#include "mm_top.h"
using namespace adf;


PLIO *in_r0_Acc0  = new PLIO("in_r0_Acc0",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc0  = new PLIO("in_r1_Acc0",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc1  = new PLIO("in_r0_Acc1",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc1  = new PLIO("in_r1_Acc1",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc2  = new PLIO("in_r0_Acc2",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc2  = new PLIO("in_r1_Acc2",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc3  = new PLIO("in_r0_Acc3",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc3  = new PLIO("in_r1_Acc3",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc4  = new PLIO("in_r0_Acc4",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc4  = new PLIO("in_r1_Acc4",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc5  = new PLIO("in_r0_Acc5",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc5  = new PLIO("in_r1_Acc5",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc6  = new PLIO("in_r0_Acc6",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc6  = new PLIO("in_r1_Acc6",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r0_Acc7  = new PLIO("in_r0_Acc7",  adf::plio_128_bits, "data/input0.txt", 250);
PLIO *in_r1_Acc7  = new PLIO("in_r1_Acc7",  adf::plio_128_bits, "data/input0.txt", 250);

PLIO *in_c0_Acc0  = new PLIO("in_c0_Acc0",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc0  = new PLIO("in_c1_Acc0",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc0  = new PLIO("in_c2_Acc0",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc0  = new PLIO("in_c3_Acc0",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc1  = new PLIO("in_c0_Acc1",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc1  = new PLIO("in_c1_Acc1",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc1  = new PLIO("in_c2_Acc1",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc1  = new PLIO("in_c3_Acc1",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc2  = new PLIO("in_c0_Acc2",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc2  = new PLIO("in_c1_Acc2",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc2  = new PLIO("in_c2_Acc2",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc2  = new PLIO("in_c3_Acc2",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc3  = new PLIO("in_c0_Acc3",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc3  = new PLIO("in_c1_Acc3",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc3  = new PLIO("in_c2_Acc3",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc3  = new PLIO("in_c3_Acc3",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc4  = new PLIO("in_c0_Acc4",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc4  = new PLIO("in_c1_Acc4",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc4  = new PLIO("in_c2_Acc4",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc4  = new PLIO("in_c3_Acc4",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc5  = new PLIO("in_c0_Acc5",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc5  = new PLIO("in_c1_Acc5",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc5  = new PLIO("in_c2_Acc5",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc5  = new PLIO("in_c3_Acc5",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc6  = new PLIO("in_c0_Acc6",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc6  = new PLIO("in_c1_Acc6",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc6  = new PLIO("in_c2_Acc6",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc6  = new PLIO("in_c3_Acc6",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c0_Acc7  = new PLIO("in_c0_Acc7",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c1_Acc7  = new PLIO("in_c1_Acc7",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c2_Acc7  = new PLIO("in_c2_Acc7",  adf::plio_128_bits, "data/input1.txt", 250);
PLIO *in_c3_Acc7  = new PLIO("in_c3_Acc7",  adf::plio_128_bits, "data/input1.txt", 250);


PLIO *out_0_Acc0 = new PLIO("out_0_Acc0", adf::plio_128_bits, "./data/output_0.txt", 250);
PLIO *out_1_Acc0 = new PLIO("out_1_Acc0", adf::plio_128_bits, "./data/output_1.txt", 250);
PLIO *out_0_Acc1 = new PLIO("out_0_Acc1", adf::plio_128_bits, "./data/output_2.txt", 250);
PLIO *out_1_Acc1 = new PLIO("out_1_Acc1", adf::plio_128_bits, "./data/output_3.txt", 250);
PLIO *out_0_Acc2 = new PLIO("out_0_Acc2", adf::plio_128_bits, "./data/output_4.txt", 250);
PLIO *out_1_Acc2 = new PLIO("out_1_Acc2", adf::plio_128_bits, "./data/output_5.txt", 250);
PLIO *out_0_Acc3 = new PLIO("out_0_Acc3", adf::plio_128_bits, "./data/output_6.txt", 250);
PLIO *out_1_Acc3 = new PLIO("out_1_Acc3", adf::plio_128_bits, "./data/output_7.txt", 250);
PLIO *out_0_Acc4 = new PLIO("out_0_Acc4", adf::plio_128_bits, "./data/output_8.txt", 250);
PLIO *out_1_Acc4 = new PLIO("out_1_Acc4", adf::plio_128_bits, "./data/output_9.txt", 250);
PLIO *out_0_Acc5 = new PLIO("out_0_Acc5", adf::plio_128_bits, "./data/output_10.txt", 250);
PLIO *out_1_Acc5 = new PLIO("out_1_Acc5", adf::plio_128_bits, "./data/output_11.txt", 250);
PLIO *out_0_Acc6 = new PLIO("out_0_Acc6", adf::plio_128_bits, "./data/output_12.txt", 250);
PLIO *out_1_Acc6 = new PLIO("out_1_Acc6", adf::plio_128_bits, "./data/output_13.txt", 250);
PLIO *out_0_Acc7 = new PLIO("out_0_Acc7", adf::plio_128_bits, "./data/output_14.txt", 250);
PLIO *out_1_Acc7 = new PLIO("out_1_Acc7", adf::plio_128_bits, "./data/output_15.txt", 250);

mm_x8_x4_graph<6,0> myGraph0;
mm_x8_x4_graph<10,0> myGraph1;
mm_x8_x4_graph<14,0> myGraph2;
mm_x8_x4_graph<18,0> myGraph3;
mm_x8_x4_graph<22,0> myGraph4;
mm_x8_x4_graph<26,0> myGraph5;
mm_x8_x4_graph<30,0> myGraph6;
mm_x8_x4_graph<34,0> myGraph7;
	
simulation::platform<48,16> platform(
                                in_r0_Acc0,
                                in_r1_Acc0,
                                in_r0_Acc1,
                                in_r1_Acc1,
                                in_r0_Acc2,
                                in_r1_Acc2,
                                in_r0_Acc3,
                                in_r1_Acc3,
                                in_r0_Acc4,
                                in_r1_Acc4,
                                in_r0_Acc5,
                                in_r1_Acc5,
                                in_r0_Acc6,
                                in_r1_Acc6,
                                in_r0_Acc7,
                                in_r1_Acc7,
                                in_c0_Acc0,
                                in_c1_Acc0,
                                in_c2_Acc0,
                                in_c3_Acc0,
                                in_c0_Acc1,
                                in_c1_Acc1,
                                in_c2_Acc1,
                                in_c3_Acc1,
                                in_c0_Acc2,
                                in_c1_Acc2,
                                in_c2_Acc2,
                                in_c3_Acc2,
                                in_c0_Acc3,
                                in_c1_Acc3,
                                in_c2_Acc3,
                                in_c3_Acc3,
                                in_c0_Acc4,
                                in_c1_Acc4,
                                in_c2_Acc4,
                                in_c3_Acc4,
                                in_c0_Acc5,
                                in_c1_Acc5,
                                in_c2_Acc5,
                                in_c3_Acc5,
                                in_c0_Acc6,
                                in_c1_Acc6,
                                in_c2_Acc6,
                                in_c3_Acc6,
                                in_c0_Acc7,
                                in_c1_Acc7,
                                in_c2_Acc7,
                                in_c3_Acc7,
                                out_0_Acc0,
                                out_1_Acc0,
                                out_0_Acc1,
                                out_1_Acc1,
                                out_0_Acc2,
                                out_1_Acc2,
                                out_0_Acc3,
                                out_1_Acc3,
                                out_0_Acc4,
                                out_1_Acc4,
                                out_0_Acc5,
                                out_1_Acc5,
                                out_0_Acc6,
                                out_1_Acc6,
                                out_0_Acc7,
                                out_1_Acc7
													);
connect<> netir0_Acc0(platform.src[0], myGraph0.in_row[0]);
connect<> netir1_Acc0(platform.src[1], myGraph0.in_row[1]);
connect<> netir0_Acc1(platform.src[2], myGraph1.in_row[0]);
connect<> netir1_Acc1(platform.src[3], myGraph1.in_row[1]);
connect<> netir0_Acc2(platform.src[4], myGraph2.in_row[0]);
connect<> netir1_Acc2(platform.src[5], myGraph2.in_row[1]);
connect<> netir0_Acc3(platform.src[6], myGraph3.in_row[0]);
connect<> netir1_Acc3(platform.src[7], myGraph3.in_row[1]);
connect<> netir0_Acc4(platform.src[8], myGraph4.in_row[0]);
connect<> netir1_Acc4(platform.src[9], myGraph4.in_row[1]);
connect<> netir0_Acc5(platform.src[10], myGraph5.in_row[0]);
connect<> netir1_Acc5(platform.src[11], myGraph5.in_row[1]);
connect<> netir0_Acc6(platform.src[12], myGraph6.in_row[0]);
connect<> netir1_Acc6(platform.src[13], myGraph6.in_row[1]);
connect<> netir0_Acc7(platform.src[14], myGraph7.in_row[0]);
connect<> netir1_Acc7(platform.src[15], myGraph7.in_row[1]);

connect<> netic0_ACC0(platform.src[16], myGraph0.in_col[0]);
connect<> netic1_ACC0(platform.src[17], myGraph0.in_col[1]);
connect<> netic2_ACC0(platform.src[18], myGraph0.in_col[2]);
connect<> netic3_ACC0(platform.src[19], myGraph0.in_col[3]);
connect<> netic0_ACC1(platform.src[20], myGraph1.in_col[0]);
connect<> netic1_ACC1(platform.src[21], myGraph1.in_col[1]);
connect<> netic2_ACC1(platform.src[22], myGraph1.in_col[2]);
connect<> netic3_ACC1(platform.src[23], myGraph1.in_col[3]);
connect<> netic0_ACC2(platform.src[24], myGraph2.in_col[0]);
connect<> netic1_ACC2(platform.src[25], myGraph2.in_col[1]);
connect<> netic2_ACC2(platform.src[26], myGraph2.in_col[2]);
connect<> netic3_ACC2(platform.src[27], myGraph2.in_col[3]);
connect<> netic0_ACC3(platform.src[28], myGraph3.in_col[0]);
connect<> netic1_ACC3(platform.src[29], myGraph3.in_col[1]);
connect<> netic2_ACC3(platform.src[30], myGraph3.in_col[2]);
connect<> netic3_ACC3(platform.src[31], myGraph3.in_col[3]);
connect<> netic0_ACC4(platform.src[32], myGraph4.in_col[0]);
connect<> netic1_ACC4(platform.src[33], myGraph4.in_col[1]);
connect<> netic2_ACC4(platform.src[34], myGraph4.in_col[2]);
connect<> netic3_ACC4(platform.src[35], myGraph4.in_col[3]);
connect<> netic0_ACC5(platform.src[36], myGraph5.in_col[0]);
connect<> netic1_ACC5(platform.src[37], myGraph5.in_col[1]);
connect<> netic2_ACC5(platform.src[38], myGraph5.in_col[2]);
connect<> netic3_ACC5(platform.src[39], myGraph5.in_col[3]);
connect<> netic0_ACC6(platform.src[40], myGraph6.in_col[0]);
connect<> netic1_ACC6(platform.src[41], myGraph6.in_col[1]);
connect<> netic2_ACC6(platform.src[42], myGraph6.in_col[2]);
connect<> netic3_ACC6(platform.src[43], myGraph6.in_col[3]);
connect<> netic0_ACC7(platform.src[44], myGraph7.in_col[0]);
connect<> netic1_ACC7(platform.src[45], myGraph7.in_col[1]);
connect<> netic2_ACC7(platform.src[46], myGraph7.in_col[2]);
connect<> netic3_ACC7(platform.src[47], myGraph7.in_col[3]);

connect<> neto0_Acc0(myGraph0.out[0],  platform.sink[0]);
connect<> neto1_Acc0(myGraph0.out[1],  platform.sink[1]);
connect<> neto0_Acc1(myGraph1.out[0],  platform.sink[2]);
connect<> neto1_Acc1(myGraph1.out[1],  platform.sink[3]);
connect<> neto0_Acc2(myGraph2.out[0],  platform.sink[4]);
connect<> neto1_Acc2(myGraph2.out[1],  platform.sink[5]);
connect<> neto0_Acc3(myGraph3.out[0],  platform.sink[6]);
connect<> neto1_Acc3(myGraph3.out[1],  platform.sink[7]);
connect<> neto0_Acc4(myGraph4.out[0],  platform.sink[8]);
connect<> neto1_Acc4(myGraph4.out[1],  platform.sink[9]);
connect<> neto0_Acc5(myGraph5.out[0],  platform.sink[10]);
connect<> neto1_Acc5(myGraph5.out[1],  platform.sink[11]);
connect<> neto0_Acc6(myGraph6.out[0],  platform.sink[12]);
connect<> neto1_Acc6(myGraph6.out[1],  platform.sink[13]);
connect<> neto0_Acc7(myGraph7.out[0],  platform.sink[14]);
connect<> neto1_Acc7(myGraph7.out[1],  platform.sink[15]);


#ifdef __AIESIM__

int main(void) {
  myGraph0.init();
  myGraph1.init();
  myGraph2.init();
  myGraph3.init();
  myGraph4.init();
  myGraph5.init();
  myGraph6.init();
  myGraph7.init();
  myGraph0.run(4);
  myGraph1.run(4);
  myGraph2.run(4);
  myGraph3.run(4);
  myGraph4.run(4);
  myGraph5.run(4);
  myGraph6.run(4);
  myGraph7.run(4);
  myGraph0.end();
  myGraph1.end();
  myGraph2.end();
  myGraph3.end();
  myGraph4.end();
  myGraph5.end();
  myGraph6.end();
  myGraph7.end();
  return 0;
}

#endif
