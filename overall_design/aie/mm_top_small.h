#include "aie/mm_graph_small.h"
#include <stdio.h>
const int ROW=8;
const int COL=2;
const int R_BRO=2;
const int C_BRO=2;
const int NUM_PACKET_PAC=1;    //std::ceil(NUM_ENGINES_PER_PAC_SMALL/4) number of packet in each graph
const int NUM_INSTANCES=ROW*COL;                   //graph number
const int NUM_OUT_PACK=NUM_INSTANCES/4;
using namespace adf;


template <int COL_OFFSET,int ROW_OFFSET>
class mm_x16_x2_graph : public adf::graph {
	
public:
	input_port in_row[ROW*NUM_PACKET_PAC*COL/R_BRO];
	input_port in_col[COL*NUM_PACKET_PAC*ROW/C_BRO];

    adf::pktmerge<4>  mg_out[NUM_OUT_PACK];
    output_port out[NUM_OUT_PACK];
	
	//COL 0-32
    mm_x2_graph<COL_OFFSET+0, ROW_OFFSET+0>  mm_x2_0_0;
    mm_x2_graph<COL_OFFSET+1, ROW_OFFSET+0>  mm_x2_1_0;
    mm_x2_graph<COL_OFFSET+2, ROW_OFFSET+0>  mm_x2_0_1;
    mm_x2_graph<COL_OFFSET+3, ROW_OFFSET+0>  mm_x2_1_1;
    mm_x2_graph<COL_OFFSET+4, ROW_OFFSET+0>  mm_x2_0_2;
    mm_x2_graph<COL_OFFSET+5, ROW_OFFSET+0>  mm_x2_1_2;
    mm_x2_graph<COL_OFFSET+6, ROW_OFFSET+0>  mm_x2_0_3;
    mm_x2_graph<COL_OFFSET+7, ROW_OFFSET+0>  mm_x2_1_3;
    mm_x2_graph<COL_OFFSET+8, ROW_OFFSET+0>  mm_x2_0_4;
    mm_x2_graph<COL_OFFSET+9, ROW_OFFSET+0>  mm_x2_1_4;
    mm_x2_graph<COL_OFFSET+10, ROW_OFFSET+0>  mm_x2_0_5;
    mm_x2_graph<COL_OFFSET+11, ROW_OFFSET+0>  mm_x2_1_5;
    mm_x2_graph<COL_OFFSET+12, ROW_OFFSET+0>  mm_x2_0_6;
    mm_x2_graph<COL_OFFSET+13, ROW_OFFSET+0>  mm_x2_1_6;
    mm_x2_graph<COL_OFFSET+14, ROW_OFFSET+0>  mm_x2_0_7;
    mm_x2_graph<COL_OFFSET+15, ROW_OFFSET+0>  mm_x2_1_7;
	
	mm_x16_x2_graph() {
		for (int i =0; i<NUM_OUT_PACK; i++)  {
			mg_out[i] = adf::pktmerge<4>::create();
		}
		//Connect all input ports
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x2_0_0.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x2_1_0.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x2_0_1.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x2_1_1.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[2], mm_x2_0_2.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[2], mm_x2_1_2.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[3], mm_x2_0_3.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[3], mm_x2_1_3.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[4], mm_x2_0_4.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[4], mm_x2_1_4.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[5], mm_x2_0_5.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[5], mm_x2_1_5.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[6], mm_x2_0_6.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[6], mm_x2_1_6.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[7], mm_x2_0_7.in[0]);
	    connect< pktstream, window< h1*w1*4 > >(in_row[7], mm_x2_1_7.in[0]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[0], mm_x2_0_0.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[0], mm_x2_0_1.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[1], mm_x2_0_2.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[1], mm_x2_0_3.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[2], mm_x2_0_4.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[2], mm_x2_0_5.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[3], mm_x2_0_6.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[3], mm_x2_0_7.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[4], mm_x2_1_0.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[4], mm_x2_1_1.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[5], mm_x2_1_2.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[5], mm_x2_1_3.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[6], mm_x2_1_4.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[6], mm_x2_1_5.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[7], mm_x2_1_6.in[1]);
	    connect< pktstream, window< w1*w2*4 > >(in_col[7], mm_x2_1_7.in[1]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_0.out, mg_out[0].in[0]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_0.out, mg_out[0].in[1]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_1.out, mg_out[0].in[2]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_1.out, mg_out[0].in[3]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_2.out, mg_out[1].in[0]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_2.out, mg_out[1].in[1]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_3.out, mg_out[1].in[2]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_3.out, mg_out[1].in[3]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_4.out, mg_out[2].in[0]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_4.out, mg_out[2].in[1]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_5.out, mg_out[2].in[2]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_5.out, mg_out[2].in[3]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_6.out, mg_out[3].in[0]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_6.out, mg_out[3].in[1]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_0_7.out, mg_out[3].in[2]);
	    connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x2_1_7.out, mg_out[3].in[3]);



	   	for (int i=0; i<NUM_OUT_PACK; i++)  {
	      	adf::connect<adf::pktstream> (mg_out[i].out[0], out[i]);
	    }
    }
};
