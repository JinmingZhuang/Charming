#include "mm_graph.h"

const int ROW=4;
const int COL=16;
const int R_BRO=4;
const int C_BRO=2;
const int NUM_PACKET_PAC=NUM_ENGINES_PER_PAC/4;    //number of packet in each graph
const int NUM_INSTANCES=ROW*COL;                   //graph number
const int NUM_OUT_PACK=NUM_INSTANCES/4;
using namespace adf;


template <int COL_OFFSET,int ROW_OFFSET>
class mm_x64_x4_graph : public adf::graph {
	
public:
	input_port in_row[ROW*NUM_PACKET_PAC*COL/R_BRO];
	input_port in_col[COL*NUM_PACKET_PAC*ROW/C_BRO];

		
	adf::pktmerge<4>  mg_out[NUM_OUT_PACK];
	output_port out[NUM_OUT_PACK];
	
	mm_x4_graph<COL_OFFSET+0, ROW_OFFSET+0>  mm_x4_0_0;
    mm_x4_graph<COL_OFFSET+1, ROW_OFFSET+0>  mm_x4_1_0;
    mm_x4_graph<COL_OFFSET+2, ROW_OFFSET+0>  mm_x4_2_0;
    mm_x4_graph<COL_OFFSET+3, ROW_OFFSET+0>  mm_x4_3_0;
    mm_x4_graph<COL_OFFSET+4, ROW_OFFSET+0>  mm_x4_4_0;
    mm_x4_graph<COL_OFFSET+5, ROW_OFFSET+0>  mm_x4_5_0;
    mm_x4_graph<COL_OFFSET+6, ROW_OFFSET+0>  mm_x4_6_0;
    mm_x4_graph<COL_OFFSET+7, ROW_OFFSET+0>  mm_x4_7_0;
    mm_x4_graph<COL_OFFSET+8, ROW_OFFSET+0>  mm_x4_8_0;
    mm_x4_graph<COL_OFFSET+9, ROW_OFFSET+0>  mm_x4_9_0;
    mm_x4_graph<COL_OFFSET+10, ROW_OFFSET+0>  mm_x4_10_0;
    mm_x4_graph<COL_OFFSET+11, ROW_OFFSET+0>  mm_x4_11_0;
    mm_x4_graph<COL_OFFSET+12, ROW_OFFSET+0>  mm_x4_12_0;
    mm_x4_graph<COL_OFFSET+13, ROW_OFFSET+0>  mm_x4_13_0;
    mm_x4_graph<COL_OFFSET+14, ROW_OFFSET+0>  mm_x4_14_0;
    mm_x4_graph<COL_OFFSET+15, ROW_OFFSET+0>  mm_x4_15_0;
    mm_x4_graph<COL_OFFSET+16, ROW_OFFSET+0>  mm_x4_0_1;
    mm_x4_graph<COL_OFFSET+17, ROW_OFFSET+0>  mm_x4_1_1;
    mm_x4_graph<COL_OFFSET+18, ROW_OFFSET+0>  mm_x4_2_1;
    mm_x4_graph<COL_OFFSET+19, ROW_OFFSET+0>  mm_x4_3_1;
    mm_x4_graph<COL_OFFSET+20, ROW_OFFSET+0>  mm_x4_4_1;
    mm_x4_graph<COL_OFFSET+21, ROW_OFFSET+0>  mm_x4_5_1;
    mm_x4_graph<COL_OFFSET+22, ROW_OFFSET+0>  mm_x4_6_1;
    mm_x4_graph<COL_OFFSET+23, ROW_OFFSET+0>  mm_x4_7_1;
    mm_x4_graph<COL_OFFSET+24, ROW_OFFSET+0>  mm_x4_8_1;
    mm_x4_graph<COL_OFFSET+25, ROW_OFFSET+0>  mm_x4_9_1;
    mm_x4_graph<COL_OFFSET+26, ROW_OFFSET+0>  mm_x4_10_1;
    mm_x4_graph<COL_OFFSET+27, ROW_OFFSET+0>  mm_x4_11_1;
    mm_x4_graph<COL_OFFSET+28, ROW_OFFSET+0>  mm_x4_12_1;
    mm_x4_graph<COL_OFFSET+29, ROW_OFFSET+0>  mm_x4_13_1;
    mm_x4_graph<COL_OFFSET+30, ROW_OFFSET+0>  mm_x4_14_1;
    mm_x4_graph<COL_OFFSET+31, ROW_OFFSET+0>  mm_x4_15_1;
    mm_x4_graph<COL_OFFSET+0, ROW_OFFSET+4>  mm_x4_0_2;
    mm_x4_graph<COL_OFFSET+1, ROW_OFFSET+4>  mm_x4_1_2;
    mm_x4_graph<COL_OFFSET+2, ROW_OFFSET+4>  mm_x4_2_2;
    mm_x4_graph<COL_OFFSET+3, ROW_OFFSET+4>  mm_x4_3_2;
    mm_x4_graph<COL_OFFSET+4, ROW_OFFSET+4>  mm_x4_4_2;
    mm_x4_graph<COL_OFFSET+5, ROW_OFFSET+4>  mm_x4_5_2;
    mm_x4_graph<COL_OFFSET+6, ROW_OFFSET+4>  mm_x4_6_2;
    mm_x4_graph<COL_OFFSET+7, ROW_OFFSET+4>  mm_x4_7_2;
    mm_x4_graph<COL_OFFSET+8, ROW_OFFSET+4>  mm_x4_8_2;
    mm_x4_graph<COL_OFFSET+9, ROW_OFFSET+4>  mm_x4_9_2;
    mm_x4_graph<COL_OFFSET+10, ROW_OFFSET+4>  mm_x4_10_2;
    mm_x4_graph<COL_OFFSET+11, ROW_OFFSET+4>  mm_x4_11_2;
    mm_x4_graph<COL_OFFSET+12, ROW_OFFSET+4>  mm_x4_12_2;
    mm_x4_graph<COL_OFFSET+13, ROW_OFFSET+4>  mm_x4_13_2;
    mm_x4_graph<COL_OFFSET+14, ROW_OFFSET+4>  mm_x4_14_2;
    mm_x4_graph<COL_OFFSET+15, ROW_OFFSET+4>  mm_x4_15_2;
    mm_x4_graph<COL_OFFSET+16, ROW_OFFSET+4>  mm_x4_0_3;
    mm_x4_graph<COL_OFFSET+17, ROW_OFFSET+4>  mm_x4_1_3;
    mm_x4_graph<COL_OFFSET+18, ROW_OFFSET+4>  mm_x4_2_3;
    mm_x4_graph<COL_OFFSET+19, ROW_OFFSET+4>  mm_x4_3_3;
    mm_x4_graph<COL_OFFSET+20, ROW_OFFSET+4>  mm_x4_4_3;
    mm_x4_graph<COL_OFFSET+21, ROW_OFFSET+4>  mm_x4_5_3;
    mm_x4_graph<COL_OFFSET+22, ROW_OFFSET+4>  mm_x4_6_3;
    mm_x4_graph<COL_OFFSET+23, ROW_OFFSET+4>  mm_x4_7_3;
    mm_x4_graph<COL_OFFSET+24, ROW_OFFSET+4>  mm_x4_8_3;
    mm_x4_graph<COL_OFFSET+25, ROW_OFFSET+4>  mm_x4_9_3;
    mm_x4_graph<COL_OFFSET+26, ROW_OFFSET+4>  mm_x4_10_3;
    mm_x4_graph<COL_OFFSET+27, ROW_OFFSET+4>  mm_x4_11_3;
    mm_x4_graph<COL_OFFSET+28, ROW_OFFSET+4>  mm_x4_12_3;
    mm_x4_graph<COL_OFFSET+29, ROW_OFFSET+4>  mm_x4_13_3;
    mm_x4_graph<COL_OFFSET+30, ROW_OFFSET+4>  mm_x4_14_3;
    mm_x4_graph<COL_OFFSET+31, ROW_OFFSET+4>  mm_x4_15_3;

	mm_x64_x4_graph() {
		for (int i =0; i<NUM_OUT_PACK; i++)  {
			mg_out[i] = adf::pktmerge<4>::create();
		}
		//Connect all input ports
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_0_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_1_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_2_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_3_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_4_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_5_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_6_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_7_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[2], mm_x4_8_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[2], mm_x4_9_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[2], mm_x4_10_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[2], mm_x4_11_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[3], mm_x4_12_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[3], mm_x4_13_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[3], mm_x4_14_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[3], mm_x4_15_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[4], mm_x4_0_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[4], mm_x4_1_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[4], mm_x4_2_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[4], mm_x4_3_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[5], mm_x4_4_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[5], mm_x4_5_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[5], mm_x4_6_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[5], mm_x4_7_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[6], mm_x4_8_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[6], mm_x4_9_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[6], mm_x4_10_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[6], mm_x4_11_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[7], mm_x4_12_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[7], mm_x4_13_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[7], mm_x4_14_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[7], mm_x4_15_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[8], mm_x4_0_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[8], mm_x4_1_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[8], mm_x4_2_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[8], mm_x4_3_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[9], mm_x4_4_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[9], mm_x4_5_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[9], mm_x4_6_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[9], mm_x4_7_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[10], mm_x4_8_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[10], mm_x4_9_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[10], mm_x4_10_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[10], mm_x4_11_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[11], mm_x4_12_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[11], mm_x4_13_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[11], mm_x4_14_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[11], mm_x4_15_2.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[12], mm_x4_0_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[12], mm_x4_1_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[12], mm_x4_2_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[12], mm_x4_3_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[13], mm_x4_4_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[13], mm_x4_5_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[13], mm_x4_6_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[13], mm_x4_7_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[14], mm_x4_8_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[14], mm_x4_9_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[14], mm_x4_10_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[14], mm_x4_11_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[15], mm_x4_12_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[15], mm_x4_13_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[15], mm_x4_14_3.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[15], mm_x4_15_3.in[0]);

	    connect< pktstream, window< w1*w2*4 > >(in_col[0], mm_x4_0_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[0], mm_x4_0_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[1], mm_x4_0_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[1], mm_x4_0_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[2], mm_x4_1_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[2], mm_x4_1_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[3], mm_x4_1_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[3], mm_x4_1_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[4], mm_x4_2_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[4], mm_x4_2_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[5], mm_x4_2_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[5], mm_x4_2_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[6], mm_x4_3_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[6], mm_x4_3_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[7], mm_x4_3_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[7], mm_x4_3_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[8], mm_x4_4_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[8], mm_x4_4_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[9], mm_x4_4_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[9], mm_x4_4_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[10], mm_x4_5_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[10], mm_x4_5_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[11], mm_x4_5_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[11], mm_x4_5_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[12], mm_x4_6_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[12], mm_x4_6_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[13], mm_x4_6_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[13], mm_x4_6_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[14], mm_x4_7_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[14], mm_x4_7_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[15], mm_x4_7_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[15], mm_x4_7_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[16], mm_x4_8_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[16], mm_x4_8_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[17], mm_x4_8_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[17], mm_x4_8_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[18], mm_x4_9_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[18], mm_x4_9_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[19], mm_x4_9_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[19], mm_x4_9_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[20], mm_x4_10_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[20], mm_x4_10_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[21], mm_x4_10_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[21], mm_x4_10_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[22], mm_x4_11_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[22], mm_x4_11_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[23], mm_x4_11_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[23], mm_x4_11_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[24], mm_x4_12_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[24], mm_x4_12_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[25], mm_x4_12_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[25], mm_x4_12_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[26], mm_x4_13_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[26], mm_x4_13_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[27], mm_x4_13_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[27], mm_x4_13_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[28], mm_x4_14_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[28], mm_x4_14_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[29], mm_x4_14_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[29], mm_x4_14_3.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[30], mm_x4_15_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[30], mm_x4_15_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[31], mm_x4_15_2.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[31], mm_x4_15_3.in[1]);

		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_0_0.out, mg_out[0].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_1_0.out, mg_out[0].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_2_0.out, mg_out[0].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_3_0.out, mg_out[0].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_4_0.out, mg_out[1].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_5_0.out, mg_out[1].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_6_0.out, mg_out[1].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_7_0.out, mg_out[1].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_8_0.out, mg_out[2].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_9_0.out, mg_out[2].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_10_0.out, mg_out[2].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_11_0.out, mg_out[2].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_12_0.out, mg_out[3].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_13_0.out, mg_out[3].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_14_0.out, mg_out[3].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_15_0.out, mg_out[3].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_0_1.out, mg_out[4].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_1_1.out, mg_out[4].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_2_1.out, mg_out[4].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_3_1.out, mg_out[4].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_4_1.out, mg_out[5].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_5_1.out, mg_out[5].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_6_1.out, mg_out[5].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_7_1.out, mg_out[5].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_8_1.out, mg_out[6].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_9_1.out, mg_out[6].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_10_1.out, mg_out[6].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_11_1.out, mg_out[6].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_12_1.out, mg_out[7].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_13_1.out, mg_out[7].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_14_1.out, mg_out[7].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_15_1.out, mg_out[7].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_0_2.out, mg_out[8].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_1_2.out, mg_out[8].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_2_2.out, mg_out[8].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_3_2.out, mg_out[8].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_4_2.out, mg_out[9].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_5_2.out, mg_out[9].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_6_2.out, mg_out[9].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_7_2.out, mg_out[9].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_8_2.out, mg_out[10].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_9_2.out, mg_out[10].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_10_2.out, mg_out[10].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_11_2.out, mg_out[10].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_12_2.out, mg_out[11].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_13_2.out, mg_out[11].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_14_2.out, mg_out[11].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_15_2.out, mg_out[11].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_0_3.out, mg_out[12].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_1_3.out, mg_out[12].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_2_3.out, mg_out[12].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_3_3.out, mg_out[12].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_4_3.out, mg_out[13].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_5_3.out, mg_out[13].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_6_3.out, mg_out[13].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_7_3.out, mg_out[13].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_8_3.out, mg_out[14].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_9_3.out, mg_out[14].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_10_3.out, mg_out[14].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_11_3.out, mg_out[14].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_12_3.out, mg_out[15].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_13_3.out, mg_out[15].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_14_3.out, mg_out[15].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_15_3.out, mg_out[15].in[3]);


	    for (int i=0; i<NUM_OUT_PACK; i++)  {
	    	adf::connect<adf::pktstream> (mg_out[i].out[0], out[i]);
	    }
   }
};
