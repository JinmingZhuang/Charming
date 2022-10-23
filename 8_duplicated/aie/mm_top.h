#include "mm_graph.h"

const int ROW=2;
const int COL=4;
const int R_BRO=4;
const int C_BRO=2;
const int NUM_PACKET_PAC=NUM_ENGINES_PER_PAC/4;    //number of packet in each graph
const int NUM_INSTANCES=ROW*COL;                   //graph number
const int NUM_OUT_PACK=NUM_INSTANCES/4;
using namespace adf;


template <int COL_OFFSET,int ROW_OFFSET>
class mm_x8_x4_graph : public adf::graph {
	
public:
	input_port in_row[ROW*NUM_PACKET_PAC*COL/R_BRO];
	input_port in_col[COL*NUM_PACKET_PAC*ROW/C_BRO];

		
	adf::pktmerge<4>  mg_out[NUM_OUT_PACK];
	output_port out[NUM_OUT_PACK];
	
	mm_x4_graph<COL_OFFSET+0, ROW_OFFSET+0>  mm_x4_0_0;
    mm_x4_graph<COL_OFFSET+1, ROW_OFFSET+0>  mm_x4_1_0;
    mm_x4_graph<COL_OFFSET+2, ROW_OFFSET+0>  mm_x4_2_0;
    mm_x4_graph<COL_OFFSET+3, ROW_OFFSET+0>  mm_x4_3_0;
    mm_x4_graph<COL_OFFSET+0, ROW_OFFSET+4>  mm_x4_0_1;
    mm_x4_graph<COL_OFFSET+1, ROW_OFFSET+4>  mm_x4_1_1;
    mm_x4_graph<COL_OFFSET+2, ROW_OFFSET+4>  mm_x4_2_1;
    mm_x4_graph<COL_OFFSET+3, ROW_OFFSET+4>  mm_x4_3_1;

	mm_x8_x4_graph() {
		for (int i =0; i<NUM_OUT_PACK; i++)  {
			mg_out[i] = adf::pktmerge<4>::create();
		}
		//Connect all input ports
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_0_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_1_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_2_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[0], mm_x4_3_0.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_0_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_1_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_2_1.in[0]);
		connect< pktstream, window< h1*w1*4 > >(in_row[1], mm_x4_3_1.in[0]);

	    connect< pktstream, window< w1*w2*4 > >(in_col[0], mm_x4_0_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[0], mm_x4_0_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[1], mm_x4_1_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[1], mm_x4_1_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[2], mm_x4_2_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[2], mm_x4_2_1.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[3], mm_x4_3_0.in[1]);
		connect< pktstream, window< w1*w2*4 > >(in_col[3], mm_x4_3_1.in[1]);

		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_0_0.out, mg_out[0].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_1_0.out, mg_out[0].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_2_0.out, mg_out[0].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_3_0.out, mg_out[0].in[3]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_0_1.out, mg_out[1].in[0]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_1_1.out, mg_out[1].in[1]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_2_1.out, mg_out[1].in[2]);
		connect<adf::window<h1*w2*4>, adf::pktstream > (mm_x4_3_1.out, mg_out[1].in[3]);


	    for (int i=0; i<NUM_OUT_PACK; i++)  {
	    	adf::connect<adf::pktstream> (mg_out[i].out[0], out[i]);
	    }
   }
};
