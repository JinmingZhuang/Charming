// (c) Copyright 1995-2018 Xilinx, Inc. All rights reserved.

#include "xnwOut/xnwOut__LNoc.h"
static xsc::common_cpp::properties PS_AIE_Config_Master_Params = []()
-> xsc::common_cpp::properties {
	auto props = xsc::common_cpp::properties();
	props.addString   ( "PHYS_NAME", "NOC_NMU128_X0Y5" );
	props.addBitString( "REG_DWIDTH", "10000" );
	return props;
}();

static xsc::common_cpp::properties PS_AIE_Config_Slave_Params = []()
-> xsc::common_cpp::properties {
	auto props = xsc::common_cpp::properties();
	props.addString   ( "PHYS_NAME", "NOC_NSU128_X5Y6" );
	props.addBitString( "REG_DWIDTH", "10000" );
	return props;
}();

static xsc::common_cpp::properties PS_PL_RTP_Slave_Params = []()
-> xsc::common_cpp::properties {
	auto props = xsc::common_cpp::properties();
	props.addString   ( "PHYS_NAME", "NOC_NSU512_X0Y0" );
	props.addBitString( "REG_DWIDTH", "10000" );
	return props;
}();

static xsc::common_cpp::properties MC_Params = []()
-> xsc::common_cpp::properties {
	auto props = xsc::common_cpp::properties();
	props.addString   ( "PHYS_NAME", "DDRMC_X0Y0" );
	props.addBool     ( "EXT_DC_CLOCK", "true" );
	return props;
}();

static xsc::common_cpp::properties SNoc_Params = []()
-> xsc::common_cpp::properties {
	auto props = xsc::common_cpp::properties();
	props.addString   ( "PARAM_FILE", "/var/tmp/Jinming/Charming/one_special/MLP/Work/noc/xnwOut/xnwOut__snoc__registers__out.txt" );
	props.addString   ( "DEVICE_FILE"  , "/opt/tools/xilinx/Vitis/2021.1/aietools/data/parts/xilinx/devint/vault/versal/data/device_misc/xcvc1902/xcvc1902.nocme.v10.model" );
	props.addString   ( "ADDRMAP_FILE" , "/opt/tools/xilinx/Vitis/2021.1/aietools/data/rsb/iprepos/axi_noc_v1_0/xit/Versal_Address_Map.xml" );
	return props;
}();

LNoc::LNoc( sc_core::sc_module_name nm, const xsc::common_cpp::properties& props)
	: sc_core::sc_module (nm) 
	, noc_clk ("noc_clk") 
	, reset_n ("reset_n") 
	, PS_AIE_Config_Master_axi_clk ("PS_AIE_Config_Master_axi_clk")
	, PS_AIE_Config_Slave_axi_clk ("PS_AIE_Config_Slave_axi_clk")
	, PS_PL_RTP_Slave_axi_clk ("PS_PL_RTP_Slave_axi_clk")
	, MC_mc_clk ("MC_mc_clk")
	, PS_AIE_Config_Master_axi_rd ("PS_AIE_Config_Master_axi_rd", 512 )
	, PS_AIE_Config_Master_axi_wr ("PS_AIE_Config_Master_axi_wr", 512 )
	, PS_AIE_Config_Slave_axi_rd ("PS_AIE_Config_Slave_axi_rd", 512 )
	, PS_PL_RTP_Slave_axi_rd ("PS_PL_RTP_Slave_axi_rd", 512 )
	, PS_AIE_Config_Slave_axi_wr ("PS_AIE_Config_Slave_axi_wr", 512 )
	, PS_PL_RTP_Slave_axi_wr ("PS_PL_RTP_Slave_axi_wr", 512 )
	, PS_AIE_Config_Master ("PS_AIE_Config_Master", PS_AIE_Config_Master_Params) 
	, MC ("MC", MC_Params) 
	, PS_AIE_Config_Slave ("PS_AIE_Config_Slave", PS_AIE_Config_Slave_Params) 
	, PS_PL_RTP_Slave ("PS_PL_RTP_Slave", PS_PL_RTP_Slave_Params) 
	, sNoc( "sNoc", SNoc_Params )
{
	PS_AIE_Config_Master.aclk ( PS_AIE_Config_Master_axi_clk);
	PS_AIE_Config_Master.tbclk (reset_n);
	PS_AIE_Config_Master.aresetn (reset_n);
	PS_AIE_Config_Slave.aclk ( PS_AIE_Config_Slave_axi_clk);
	PS_PL_RTP_Slave.aclk ( PS_PL_RTP_Slave_axi_clk);
	PS_AIE_Config_Slave.aresetn (reset_n);
	PS_PL_RTP_Slave.aresetn (reset_n);
	MC.mc_clk( MC_mc_clk);
	MC.mc_rst_n(reset_n);
	PS_AIE_Config_Master_axi_rd.bind(PS_AIE_Config_Master.arr_socket);
	PS_AIE_Config_Master_axi_wr.bind(PS_AIE_Config_Master.awb_socket);
	PS_AIE_Config_Slave.arr_socket.bind(PS_AIE_Config_Slave_axi_rd);
	PS_PL_RTP_Slave.arr_socket.bind(PS_PL_RTP_Slave_axi_rd);
	PS_AIE_Config_Slave.awb_socket.bind(PS_AIE_Config_Slave_axi_wr);
	PS_PL_RTP_Slave.awb_socket.bind(PS_PL_RTP_Slave_axi_wr);
	sNoc.noc_clk  ( noc_clk );
	sNoc.noc_rst_n( reset_n );
}

std::unique_ptr<LNoc> createLNoc(sc_core::sc_module_name nm)
	{return std::unique_ptr<LNoc>(new LNoc(nm, xsc::common_cpp::properties()));}
