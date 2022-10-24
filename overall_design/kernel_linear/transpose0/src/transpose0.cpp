#include "config_trans0.hpp"

extern "C" {
    void load_address(axis_stream_32& load_addr_out,
                   const int H_SMALL, const int W_SMALL, 
                   const int H_BEF, const int W_BEF)
    {
        for(ap_uint<32> h_bef=0;h_bef<H_BEF;h_bef++){
            for(ap_uint<32> w_bef=0;w_bef<W_BEF;w_bef++){
                for(ap_uint<32> w=0;w<W_SMALL;w++){
                    for(ap_uint<32> h=0;h<(H_SMALL/PER_TRA);h++){
                    #pragma HLS PIPELINE II = 1
                        ap_uint<32> pos;
                        pos=h+w*(H_SMALL/PER_TRA)*H_BEF+w_bef*(H_SMALL/PER_TRA)*H_BEF*W_SMALL+h_bef*(H_SMALL/PER_TRA);
                        load_addr_out.write(pos);
                    }
                }
            }
        }
    }

    void load_ddr(ap_uint<AXI_WIDTH_512>* mem_in, axis_stream_32& load_addr_in, axis_stream_512& data_out, 
                const int H_SMALL, const int W_SMALL, const int H_BEF, const int W_BEF) {
        ap_uint<AXI_WIDTH_512> temp_data;
        int bound=(H_SMALL/PER_TRA)*W_SMALL*H_BEF*W_BEF;
        for(int i=0;i<bound;i++){
        #pragma HLS PIPELINE II = 1
            ap_uint<32> addr = load_addr_in.read();
            temp_data=mem_in[addr];
            data_out.write(temp_data);  
        }
    }

    void store_address(axis_stream_32& store_addr_out,
                   const int H_SMALL, const int W_SMALL, 
                   const int H_AFT, const int W_AFT)
    {
        for(ap_uint<32> h_aft=0;h_aft<H_AFT;h_aft++){
            for(ap_uint<32> w_aft=0;w_aft<W_AFT;w_aft++){
                for(ap_uint<32> w=0;w<W_SMALL;w++){
                    for(ap_uint<32> h=0;h<(H_SMALL/PER_TRA);h++){
                    #pragma HLS PIPELINE II = 1
                        ap_uint<32> pos;
                        pos=h+w*(H_SMALL/PER_TRA)*H_AFT+w_aft*(H_SMALL/PER_TRA)*H_AFT*W_SMALL+h_aft*(H_SMALL/PER_TRA);
                        store_addr_out.write(pos);
                    }
                }
            }
        }
    }

    void store_ddr(ap_uint<AXI_WIDTH_512>* mem_out, axis_stream_32& store_addr_in ,axis_stream_512& data_in,
               const int H_SMALL, const int W_SMALL, 
               const int H_AFT, const int W_AFT){
        int bound=(H_SMALL/PER_TRA)*W_SMALL*H_AFT*W_AFT;
        ap_uint<AXI_WIDTH_512> temp_data;
        for(int i=0;i<bound;i++){
        #pragma HLS PIPELINE II = 1
            ap_uint<AXI_WIDTH_512> temp_data=data_in.read();
            ap_uint<32> addr = store_addr_in.read();
            mem_out[addr]=temp_data;

        }
    }


    void transpose0(ap_uint<AXI_WIDTH_512>* mem_in, ap_uint<AXI_WIDTH_512>* mem_out,
         const int H_SMALL, const int W_SMALL, 
         const int H_BEF, const int W_BEF, 
         const int H_AFT, const int W_AFT) {
    #pragma HLS INTERFACE m_axi port=mem_in offset=slave bundle=gmem0  max_read_burst_length=32 num_read_outstanding=16
    #pragma HLS INTERFACE s_axilite port=mem_in bundle=control
    #pragma HLS interface m_axi offset=slave bundle=gmem1 port=mem_out max_write_burst_length=32 num_write_outstanding=16
    #pragma HLS interface s_axilite bundle=control port=mem_out
    
    #pragma HLS interface s_axilite port=H_SMALL bundle=control
    #pragma HLS interface s_axilite port=W_SMALL bundle=control
    #pragma HLS interface s_axilite port=H_BEF bundle=control
    #pragma HLS interface s_axilite port=W_BEF bundle=control
    #pragma HLS interface s_axilite port=H_AFT bundle=control
    #pragma HLS interface s_axilite port=W_AFT bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control

    
    #pragma HLS DATAFLOW
    axis_stream_512 data_out;
    axis_stream_32 load_addr;
    axis_stream_32 store_addr;
        load_address(load_addr,H_SMALL, W_SMALL,H_BEF,W_BEF);
        load_ddr(mem_in,load_addr, data_out,H_SMALL, W_SMALL, H_BEF, W_BEF);
        store_address(store_addr,H_SMALL, W_SMALL, H_AFT, W_AFT);
        store_ddr(mem_out, store_addr,data_out,H_SMALL, W_SMALL, H_AFT, W_AFT);
        return;
    };
};
