#ifndef CONFIG_TRANS0_HPP
#define CONFIG_TRANS0_HPP

#include <cstring>
#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#define AXI_WIDTH_512 512
#define PER_TRA 16
typedef hls::stream<ap_uint<32>> axis_stream_32;
typedef hls::stream<ap_uint<512>> axis_stream_512;

#endif