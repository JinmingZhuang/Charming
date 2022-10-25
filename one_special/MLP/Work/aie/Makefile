.PHONY: all 2_0 2_1 2_2 2_3 2_4 2_5 2_6 2_7 3_0 3_1 3_2 3_3 3_4 3_5 3_6 3_7 4_0 4_1 4_2 4_3 4_4 4_5 4_6 4_7 5_0 5_1 5_2 5_3 5_4 5_5 5_6 5_7 6_0 6_1 6_2 6_3 6_4 6_5 6_6 6_7 7_0 7_1 7_2 7_3 7_4 7_5 7_6 7_7 8_0 8_1 8_2 8_3 8_4 8_5 8_6 8_7 9_0 9_1 9_2 9_3 9_4 9_5 9_6 9_7 10_0 10_1 10_2 10_3 10_4 10_5 10_6 10_7 11_0 11_1 11_2 11_3 11_4 11_5 11_6 11_7 12_0 12_1 12_2 12_3 12_4 12_5 12_6 12_7 13_0 13_1 13_2 13_3 13_4 13_5 13_6 13_7 14_0 14_1 14_2 14_3 14_4 14_5 14_6 14_7 15_0 15_1 15_2 15_3 15_4 15_5 15_6 15_7 16_0 16_1 16_2 16_3 16_4 16_5 16_6 16_7 17_0 17_1 17_2 17_3 17_4 17_5 17_6 17_7 18_0 18_1 18_2 18_3 18_4 18_5 18_6 18_7 19_0 19_1 19_2 19_3 19_4 19_5 19_6 19_7 20_0 20_1 20_2 20_3 20_4 20_5 20_6 20_7 21_0 21_1 21_2 21_3 21_4 21_5 21_6 21_7 22_0 22_1 22_2 22_3 22_4 22_5 22_6 22_7 23_0 23_1 23_2 23_3 23_4 23_5 23_6 23_7 24_0 24_1 24_2 24_3 24_4 24_5 24_6 24_7 25_0 25_1 25_2 25_3 25_4 25_5 25_6 25_7 26_0 26_1 26_2 26_3 26_4 26_5 26_6 26_7 27_0 27_1 27_2 27_3 27_4 27_5 27_6 27_7 28_0 28_1 28_2 28_3 28_4 28_5 28_6 28_7 29_0 29_1 29_2 29_3 29_4 29_5 29_6 29_7 30_0 30_1 30_2 30_3 30_4 30_5 30_6 30_7 31_0 31_1 31_2 31_3 31_4 31_5 31_6 31_7 32_0 32_1 32_2 32_3 32_4 32_5 32_6 32_7 33_0 33_1 33_2 33_3 33_4 33_5 33_6 33_7 34_0 34_1 34_2 34_3 34_4 34_5 34_6 34_7 35_0 35_1 35_2 35_3 35_4 35_5 35_6 35_7 36_0 36_1 36_2 36_3 36_4 36_5 36_6 36_7 37_0 37_1 37_2 37_3 37_4 37_5 37_6 37_7 38_0 38_1 38_2 38_3 38_4 38_5 38_6 38_7 39_0 39_1 39_2 39_3 39_4 39_5 39_6 39_7 40_0 40_1 40_2 40_3 40_4 40_5 40_6 40_7 41_0 41_1 41_2 41_3 41_4 41_5 41_6 41_7 42_0 42_1 42_2 42_3 42_4 42_5 42_6 42_7 43_0 43_1 43_2 43_3 43_4 43_5 43_6 43_7 44_0 44_1 44_2 44_3 44_4 44_5 44_6 44_7 45_0 45_1 45_2 45_3 45_4 45_5 45_6 45_7 46_0 46_1 46_2 46_3 46_4 46_5 46_6 46_7 47_0 47_1 47_2 47_3 47_4 47_5 47_6 47_7 48_0 48_1 48_2 48_3 48_4 48_5 48_6 48_7 49_0 49_1 49_2 49_3 49_4 49_5 49_6 49_7 clean

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
XCHESSMK := xchessmk
XCHESSCC := xchesscc

INCLUDE_PATH := -I ../.. -I ${XILINX_VITIS_AIETOOLS}/include -I /var/tmp/Jinming/Charming/one_special/MLP/aie -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime_cxx/libcxx-lite/include -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime_cxx/libs/libcxx-9.0.0/include-lite -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime/include

.EXPORT_ALL_VARIABLES:
export XILINX_CARDANO_XLOPT_OPTIONS=-xlopt=1 -mapped-json=mm_top_mapped.json

all: 2_0 2_1 2_2 2_3 2_4 2_5 2_6 2_7 3_0 3_1 3_2 3_3 3_4 3_5 3_6 3_7 4_0 4_1 4_2 4_3 4_4 4_5 4_6 4_7 5_0 5_1 5_2 5_3 5_4 5_5 5_6 5_7 6_0 6_1 6_2 6_3 6_4 6_5 6_6 6_7 7_0 7_1 7_2 7_3 7_4 7_5 7_6 7_7 8_0 8_1 8_2 8_3 8_4 8_5 8_6 8_7 9_0 9_1 9_2 9_3 9_4 9_5 9_6 9_7 10_0 10_1 10_2 10_3 10_4 10_5 10_6 10_7 11_0 11_1 11_2 11_3 11_4 11_5 11_6 11_7 12_0 12_1 12_2 12_3 12_4 12_5 12_6 12_7 13_0 13_1 13_2 13_3 13_4 13_5 13_6 13_7 14_0 14_1 14_2 14_3 14_4 14_5 14_6 14_7 15_0 15_1 15_2 15_3 15_4 15_5 15_6 15_7 16_0 16_1 16_2 16_3 16_4 16_5 16_6 16_7 17_0 17_1 17_2 17_3 17_4 17_5 17_6 17_7 18_0 18_1 18_2 18_3 18_4 18_5 18_6 18_7 19_0 19_1 19_2 19_3 19_4 19_5 19_6 19_7 20_0 20_1 20_2 20_3 20_4 20_5 20_6 20_7 21_0 21_1 21_2 21_3 21_4 21_5 21_6 21_7 22_0 22_1 22_2 22_3 22_4 22_5 22_6 22_7 23_0 23_1 23_2 23_3 23_4 23_5 23_6 23_7 24_0 24_1 24_2 24_3 24_4 24_5 24_6 24_7 25_0 25_1 25_2 25_3 25_4 25_5 25_6 25_7 26_0 26_1 26_2 26_3 26_4 26_5 26_6 26_7 27_0 27_1 27_2 27_3 27_4 27_5 27_6 27_7 28_0 28_1 28_2 28_3 28_4 28_5 28_6 28_7 29_0 29_1 29_2 29_3 29_4 29_5 29_6 29_7 30_0 30_1 30_2 30_3 30_4 30_5 30_6 30_7 31_0 31_1 31_2 31_3 31_4 31_5 31_6 31_7 32_0 32_1 32_2 32_3 32_4 32_5 32_6 32_7 33_0 33_1 33_2 33_3 33_4 33_5 33_6 33_7 34_0 34_1 34_2 34_3 34_4 34_5 34_6 34_7 35_0 35_1 35_2 35_3 35_4 35_5 35_6 35_7 36_0 36_1 36_2 36_3 36_4 36_5 36_6 36_7 37_0 37_1 37_2 37_3 37_4 37_5 37_6 37_7 38_0 38_1 38_2 38_3 38_4 38_5 38_6 38_7 39_0 39_1 39_2 39_3 39_4 39_5 39_6 39_7 40_0 40_1 40_2 40_3 40_4 40_5 40_6 40_7 41_0 41_1 41_2 41_3 41_4 41_5 41_6 41_7 42_0 42_1 42_2 42_3 42_4 42_5 42_6 42_7 43_0 43_1 43_2 43_3 43_4 43_5 43_6 43_7 44_0 44_1 44_2 44_3 44_4 44_5 44_6 44_7 45_0 45_1 45_2 45_3 45_4 45_5 45_6 45_7 46_0 46_1 46_2 46_3 46_4 46_5 46_6 46_7 47_0 47_1 47_2 47_3 47_4 47_5 47_6 47_7 48_0 48_1 48_2 48_3 48_4 48_5 48_6 48_7 49_0 49_1 49_2 49_3 49_4 49_5 49_6 49_7 

2_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_0/src/2_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/2_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_0_orig.ll -o ir/2_0.ll 2>2_0/xlopt.log;
2_0_llopt: 2_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_0.ll -o ir/2_0.ll 2>/dev/null;

2_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_1/src/2_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/2_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_1_orig.ll -o ir/2_1.ll 2>2_1/xlopt.log;
2_1_llopt: 2_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_1.ll -o ir/2_1.ll 2>/dev/null;

2_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_2/src/2_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/2_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_2_orig.ll -o ir/2_2.ll 2>2_2/xlopt.log;
2_2_llopt: 2_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_2.ll -o ir/2_2.ll 2>/dev/null;

2_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_3/src/2_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/2_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_3_orig.ll -o ir/2_3.ll 2>2_3/xlopt.log;
2_3_llopt: 2_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_3.ll -o ir/2_3.ll 2>/dev/null;

2_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_4/src/2_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/2_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_4_orig.ll -o ir/2_4.ll 2>2_4/xlopt.log;
2_4_llopt: 2_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_4.ll -o ir/2_4.ll 2>/dev/null;

2_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_5/src/2_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/2_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_5_orig.ll -o ir/2_5.ll 2>2_5/xlopt.log;
2_5_llopt: 2_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_5.ll -o ir/2_5.ll 2>/dev/null;

2_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_6/src/2_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/2_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_6_orig.ll -o ir/2_6.ll 2>2_6/xlopt.log;
2_6_llopt: 2_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_6.ll -o ir/2_6.ll 2>/dev/null;

2_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/2_7/src/2_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/2_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/2_7_orig.ll -o ir/2_7.ll 2>2_7/xlopt.log;
2_7_llopt: 2_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/2_7.ll -o ir/2_7.ll 2>/dev/null;

3_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_0/src/3_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/3_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_0_orig.ll -o ir/3_0.ll 2>3_0/xlopt.log;
3_0_llopt: 3_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_0.ll -o ir/3_0.ll 2>/dev/null;

3_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_1/src/3_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/3_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_1_orig.ll -o ir/3_1.ll 2>3_1/xlopt.log;
3_1_llopt: 3_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_1.ll -o ir/3_1.ll 2>/dev/null;

3_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_2/src/3_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/3_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_2_orig.ll -o ir/3_2.ll 2>3_2/xlopt.log;
3_2_llopt: 3_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_2.ll -o ir/3_2.ll 2>/dev/null;

3_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_3/src/3_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/3_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_3_orig.ll -o ir/3_3.ll 2>3_3/xlopt.log;
3_3_llopt: 3_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_3.ll -o ir/3_3.ll 2>/dev/null;

3_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_4/src/3_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/3_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_4_orig.ll -o ir/3_4.ll 2>3_4/xlopt.log;
3_4_llopt: 3_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_4.ll -o ir/3_4.ll 2>/dev/null;

3_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_5/src/3_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/3_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_5_orig.ll -o ir/3_5.ll 2>3_5/xlopt.log;
3_5_llopt: 3_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_5.ll -o ir/3_5.ll 2>/dev/null;

3_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_6/src/3_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/3_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_6_orig.ll -o ir/3_6.ll 2>3_6/xlopt.log;
3_6_llopt: 3_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_6.ll -o ir/3_6.ll 2>/dev/null;

3_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/3_7/src/3_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/3_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/3_7_orig.ll -o ir/3_7.ll 2>3_7/xlopt.log;
3_7_llopt: 3_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/3_7.ll -o ir/3_7.ll 2>/dev/null;

4_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_0/src/4_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/4_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_0_orig.ll -o ir/4_0.ll 2>4_0/xlopt.log;
4_0_llopt: 4_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_0.ll -o ir/4_0.ll 2>/dev/null;

4_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_1/src/4_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/4_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_1_orig.ll -o ir/4_1.ll 2>4_1/xlopt.log;
4_1_llopt: 4_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_1.ll -o ir/4_1.ll 2>/dev/null;

4_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_2/src/4_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/4_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_2_orig.ll -o ir/4_2.ll 2>4_2/xlopt.log;
4_2_llopt: 4_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_2.ll -o ir/4_2.ll 2>/dev/null;

4_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_3/src/4_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/4_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_3_orig.ll -o ir/4_3.ll 2>4_3/xlopt.log;
4_3_llopt: 4_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_3.ll -o ir/4_3.ll 2>/dev/null;

4_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_4/src/4_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/4_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_4_orig.ll -o ir/4_4.ll 2>4_4/xlopt.log;
4_4_llopt: 4_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_4.ll -o ir/4_4.ll 2>/dev/null;

4_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_5/src/4_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/4_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_5_orig.ll -o ir/4_5.ll 2>4_5/xlopt.log;
4_5_llopt: 4_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_5.ll -o ir/4_5.ll 2>/dev/null;

4_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_6/src/4_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/4_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_6_orig.ll -o ir/4_6.ll 2>4_6/xlopt.log;
4_6_llopt: 4_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_6.ll -o ir/4_6.ll 2>/dev/null;

4_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/4_7/src/4_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/4_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/4_7_orig.ll -o ir/4_7.ll 2>4_7/xlopt.log;
4_7_llopt: 4_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/4_7.ll -o ir/4_7.ll 2>/dev/null;

5_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_0/src/5_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/5_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_0_orig.ll -o ir/5_0.ll 2>5_0/xlopt.log;
5_0_llopt: 5_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_0.ll -o ir/5_0.ll 2>/dev/null;

5_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_1/src/5_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/5_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_1_orig.ll -o ir/5_1.ll 2>5_1/xlopt.log;
5_1_llopt: 5_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_1.ll -o ir/5_1.ll 2>/dev/null;

5_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_2/src/5_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/5_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_2_orig.ll -o ir/5_2.ll 2>5_2/xlopt.log;
5_2_llopt: 5_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_2.ll -o ir/5_2.ll 2>/dev/null;

5_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_3/src/5_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/5_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_3_orig.ll -o ir/5_3.ll 2>5_3/xlopt.log;
5_3_llopt: 5_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_3.ll -o ir/5_3.ll 2>/dev/null;

5_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_4/src/5_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/5_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_4_orig.ll -o ir/5_4.ll 2>5_4/xlopt.log;
5_4_llopt: 5_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_4.ll -o ir/5_4.ll 2>/dev/null;

5_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_5/src/5_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/5_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_5_orig.ll -o ir/5_5.ll 2>5_5/xlopt.log;
5_5_llopt: 5_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_5.ll -o ir/5_5.ll 2>/dev/null;

5_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_6/src/5_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/5_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_6_orig.ll -o ir/5_6.ll 2>5_6/xlopt.log;
5_6_llopt: 5_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_6.ll -o ir/5_6.ll 2>/dev/null;

5_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/5_7/src/5_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/5_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/5_7_orig.ll -o ir/5_7.ll 2>5_7/xlopt.log;
5_7_llopt: 5_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/5_7.ll -o ir/5_7.ll 2>/dev/null;

6_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_0/src/6_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/6_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_0_orig.ll -o ir/6_0.ll 2>6_0/xlopt.log;
6_0_llopt: 6_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_0.ll -o ir/6_0.ll 2>/dev/null;

6_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_1/src/6_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/6_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_1_orig.ll -o ir/6_1.ll 2>6_1/xlopt.log;
6_1_llopt: 6_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_1.ll -o ir/6_1.ll 2>/dev/null;

6_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_2/src/6_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/6_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_2_orig.ll -o ir/6_2.ll 2>6_2/xlopt.log;
6_2_llopt: 6_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_2.ll -o ir/6_2.ll 2>/dev/null;

6_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_3/src/6_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/6_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_3_orig.ll -o ir/6_3.ll 2>6_3/xlopt.log;
6_3_llopt: 6_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_3.ll -o ir/6_3.ll 2>/dev/null;

6_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_4/src/6_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/6_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_4_orig.ll -o ir/6_4.ll 2>6_4/xlopt.log;
6_4_llopt: 6_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_4.ll -o ir/6_4.ll 2>/dev/null;

6_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_5/src/6_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/6_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_5_orig.ll -o ir/6_5.ll 2>6_5/xlopt.log;
6_5_llopt: 6_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_5.ll -o ir/6_5.ll 2>/dev/null;

6_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_6/src/6_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/6_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_6_orig.ll -o ir/6_6.ll 2>6_6/xlopt.log;
6_6_llopt: 6_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_6.ll -o ir/6_6.ll 2>/dev/null;

6_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/6_7/src/6_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/6_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/6_7_orig.ll -o ir/6_7.ll 2>6_7/xlopt.log;
6_7_llopt: 6_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/6_7.ll -o ir/6_7.ll 2>/dev/null;

7_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_0/src/7_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/7_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_0_orig.ll -o ir/7_0.ll 2>7_0/xlopt.log;
7_0_llopt: 7_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_0.ll -o ir/7_0.ll 2>/dev/null;

7_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_1/src/7_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/7_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_1_orig.ll -o ir/7_1.ll 2>7_1/xlopt.log;
7_1_llopt: 7_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_1.ll -o ir/7_1.ll 2>/dev/null;

7_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_2/src/7_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/7_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_2_orig.ll -o ir/7_2.ll 2>7_2/xlopt.log;
7_2_llopt: 7_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_2.ll -o ir/7_2.ll 2>/dev/null;

7_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_3/src/7_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/7_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_3_orig.ll -o ir/7_3.ll 2>7_3/xlopt.log;
7_3_llopt: 7_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_3.ll -o ir/7_3.ll 2>/dev/null;

7_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_4/src/7_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/7_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_4_orig.ll -o ir/7_4.ll 2>7_4/xlopt.log;
7_4_llopt: 7_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_4.ll -o ir/7_4.ll 2>/dev/null;

7_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_5/src/7_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/7_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_5_orig.ll -o ir/7_5.ll 2>7_5/xlopt.log;
7_5_llopt: 7_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_5.ll -o ir/7_5.ll 2>/dev/null;

7_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_6/src/7_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/7_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_6_orig.ll -o ir/7_6.ll 2>7_6/xlopt.log;
7_6_llopt: 7_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_6.ll -o ir/7_6.ll 2>/dev/null;

7_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/7_7/src/7_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/7_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/7_7_orig.ll -o ir/7_7.ll 2>7_7/xlopt.log;
7_7_llopt: 7_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/7_7.ll -o ir/7_7.ll 2>/dev/null;

8_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_0/src/8_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/8_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_0_orig.ll -o ir/8_0.ll 2>8_0/xlopt.log;
8_0_llopt: 8_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_0.ll -o ir/8_0.ll 2>/dev/null;

8_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_1/src/8_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/8_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_1_orig.ll -o ir/8_1.ll 2>8_1/xlopt.log;
8_1_llopt: 8_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_1.ll -o ir/8_1.ll 2>/dev/null;

8_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_2/src/8_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/8_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_2_orig.ll -o ir/8_2.ll 2>8_2/xlopt.log;
8_2_llopt: 8_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_2.ll -o ir/8_2.ll 2>/dev/null;

8_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_3/src/8_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/8_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_3_orig.ll -o ir/8_3.ll 2>8_3/xlopt.log;
8_3_llopt: 8_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_3.ll -o ir/8_3.ll 2>/dev/null;

8_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_4/src/8_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/8_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_4_orig.ll -o ir/8_4.ll 2>8_4/xlopt.log;
8_4_llopt: 8_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_4.ll -o ir/8_4.ll 2>/dev/null;

8_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_5/src/8_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/8_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_5_orig.ll -o ir/8_5.ll 2>8_5/xlopt.log;
8_5_llopt: 8_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_5.ll -o ir/8_5.ll 2>/dev/null;

8_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_6/src/8_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/8_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_6_orig.ll -o ir/8_6.ll 2>8_6/xlopt.log;
8_6_llopt: 8_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_6.ll -o ir/8_6.ll 2>/dev/null;

8_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/8_7/src/8_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/8_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/8_7_orig.ll -o ir/8_7.ll 2>8_7/xlopt.log;
8_7_llopt: 8_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/8_7.ll -o ir/8_7.ll 2>/dev/null;

9_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_0/src/9_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/9_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_0_orig.ll -o ir/9_0.ll 2>9_0/xlopt.log;
9_0_llopt: 9_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_0.ll -o ir/9_0.ll 2>/dev/null;

9_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_1/src/9_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/9_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_1_orig.ll -o ir/9_1.ll 2>9_1/xlopt.log;
9_1_llopt: 9_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_1.ll -o ir/9_1.ll 2>/dev/null;

9_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_2/src/9_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/9_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_2_orig.ll -o ir/9_2.ll 2>9_2/xlopt.log;
9_2_llopt: 9_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_2.ll -o ir/9_2.ll 2>/dev/null;

9_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_3/src/9_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/9_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_3_orig.ll -o ir/9_3.ll 2>9_3/xlopt.log;
9_3_llopt: 9_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_3.ll -o ir/9_3.ll 2>/dev/null;

9_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_4/src/9_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/9_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_4_orig.ll -o ir/9_4.ll 2>9_4/xlopt.log;
9_4_llopt: 9_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_4.ll -o ir/9_4.ll 2>/dev/null;

9_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_5/src/9_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/9_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_5_orig.ll -o ir/9_5.ll 2>9_5/xlopt.log;
9_5_llopt: 9_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_5.ll -o ir/9_5.ll 2>/dev/null;

9_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_6/src/9_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/9_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_6_orig.ll -o ir/9_6.ll 2>9_6/xlopt.log;
9_6_llopt: 9_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_6.ll -o ir/9_6.ll 2>/dev/null;

9_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/9_7/src/9_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/9_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/9_7_orig.ll -o ir/9_7.ll 2>9_7/xlopt.log;
9_7_llopt: 9_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/9_7.ll -o ir/9_7.ll 2>/dev/null;

10_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_0/src/10_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/10_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_0_orig.ll -o ir/10_0.ll 2>10_0/xlopt.log;
10_0_llopt: 10_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_0.ll -o ir/10_0.ll 2>/dev/null;

10_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_1/src/10_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/10_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_1_orig.ll -o ir/10_1.ll 2>10_1/xlopt.log;
10_1_llopt: 10_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_1.ll -o ir/10_1.ll 2>/dev/null;

10_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_2/src/10_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/10_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_2_orig.ll -o ir/10_2.ll 2>10_2/xlopt.log;
10_2_llopt: 10_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_2.ll -o ir/10_2.ll 2>/dev/null;

10_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_3/src/10_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/10_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_3_orig.ll -o ir/10_3.ll 2>10_3/xlopt.log;
10_3_llopt: 10_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_3.ll -o ir/10_3.ll 2>/dev/null;

10_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_4/src/10_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/10_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_4_orig.ll -o ir/10_4.ll 2>10_4/xlopt.log;
10_4_llopt: 10_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_4.ll -o ir/10_4.ll 2>/dev/null;

10_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_5/src/10_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/10_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_5_orig.ll -o ir/10_5.ll 2>10_5/xlopt.log;
10_5_llopt: 10_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_5.ll -o ir/10_5.ll 2>/dev/null;

10_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_6/src/10_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/10_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_6_orig.ll -o ir/10_6.ll 2>10_6/xlopt.log;
10_6_llopt: 10_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_6.ll -o ir/10_6.ll 2>/dev/null;

10_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/10_7/src/10_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/10_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/10_7_orig.ll -o ir/10_7.ll 2>10_7/xlopt.log;
10_7_llopt: 10_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/10_7.ll -o ir/10_7.ll 2>/dev/null;

11_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_0/src/11_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/11_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_0_orig.ll -o ir/11_0.ll 2>11_0/xlopt.log;
11_0_llopt: 11_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_0.ll -o ir/11_0.ll 2>/dev/null;

11_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_1/src/11_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/11_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_1_orig.ll -o ir/11_1.ll 2>11_1/xlopt.log;
11_1_llopt: 11_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_1.ll -o ir/11_1.ll 2>/dev/null;

11_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_2/src/11_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/11_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_2_orig.ll -o ir/11_2.ll 2>11_2/xlopt.log;
11_2_llopt: 11_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_2.ll -o ir/11_2.ll 2>/dev/null;

11_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_3/src/11_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/11_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_3_orig.ll -o ir/11_3.ll 2>11_3/xlopt.log;
11_3_llopt: 11_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_3.ll -o ir/11_3.ll 2>/dev/null;

11_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_4/src/11_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/11_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_4_orig.ll -o ir/11_4.ll 2>11_4/xlopt.log;
11_4_llopt: 11_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_4.ll -o ir/11_4.ll 2>/dev/null;

11_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_5/src/11_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/11_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_5_orig.ll -o ir/11_5.ll 2>11_5/xlopt.log;
11_5_llopt: 11_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_5.ll -o ir/11_5.ll 2>/dev/null;

11_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_6/src/11_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/11_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_6_orig.ll -o ir/11_6.ll 2>11_6/xlopt.log;
11_6_llopt: 11_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_6.ll -o ir/11_6.ll 2>/dev/null;

11_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/11_7/src/11_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/11_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/11_7_orig.ll -o ir/11_7.ll 2>11_7/xlopt.log;
11_7_llopt: 11_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/11_7.ll -o ir/11_7.ll 2>/dev/null;

12_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_0/src/12_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/12_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_0_orig.ll -o ir/12_0.ll 2>12_0/xlopt.log;
12_0_llopt: 12_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_0.ll -o ir/12_0.ll 2>/dev/null;

12_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_1/src/12_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/12_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_1_orig.ll -o ir/12_1.ll 2>12_1/xlopt.log;
12_1_llopt: 12_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_1.ll -o ir/12_1.ll 2>/dev/null;

12_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_2/src/12_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/12_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_2_orig.ll -o ir/12_2.ll 2>12_2/xlopt.log;
12_2_llopt: 12_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_2.ll -o ir/12_2.ll 2>/dev/null;

12_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_3/src/12_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/12_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_3_orig.ll -o ir/12_3.ll 2>12_3/xlopt.log;
12_3_llopt: 12_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_3.ll -o ir/12_3.ll 2>/dev/null;

12_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_4/src/12_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/12_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_4_orig.ll -o ir/12_4.ll 2>12_4/xlopt.log;
12_4_llopt: 12_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_4.ll -o ir/12_4.ll 2>/dev/null;

12_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_5/src/12_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/12_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_5_orig.ll -o ir/12_5.ll 2>12_5/xlopt.log;
12_5_llopt: 12_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_5.ll -o ir/12_5.ll 2>/dev/null;

12_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_6/src/12_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/12_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_6_orig.ll -o ir/12_6.ll 2>12_6/xlopt.log;
12_6_llopt: 12_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_6.ll -o ir/12_6.ll 2>/dev/null;

12_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/12_7/src/12_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/12_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/12_7_orig.ll -o ir/12_7.ll 2>12_7/xlopt.log;
12_7_llopt: 12_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/12_7.ll -o ir/12_7.ll 2>/dev/null;

13_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_0/src/13_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/13_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_0_orig.ll -o ir/13_0.ll 2>13_0/xlopt.log;
13_0_llopt: 13_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_0.ll -o ir/13_0.ll 2>/dev/null;

13_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_1/src/13_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/13_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_1_orig.ll -o ir/13_1.ll 2>13_1/xlopt.log;
13_1_llopt: 13_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_1.ll -o ir/13_1.ll 2>/dev/null;

13_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_2/src/13_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/13_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_2_orig.ll -o ir/13_2.ll 2>13_2/xlopt.log;
13_2_llopt: 13_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_2.ll -o ir/13_2.ll 2>/dev/null;

13_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_3/src/13_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/13_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_3_orig.ll -o ir/13_3.ll 2>13_3/xlopt.log;
13_3_llopt: 13_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_3.ll -o ir/13_3.ll 2>/dev/null;

13_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_4/src/13_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/13_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_4_orig.ll -o ir/13_4.ll 2>13_4/xlopt.log;
13_4_llopt: 13_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_4.ll -o ir/13_4.ll 2>/dev/null;

13_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_5/src/13_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/13_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_5_orig.ll -o ir/13_5.ll 2>13_5/xlopt.log;
13_5_llopt: 13_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_5.ll -o ir/13_5.ll 2>/dev/null;

13_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_6/src/13_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/13_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_6_orig.ll -o ir/13_6.ll 2>13_6/xlopt.log;
13_6_llopt: 13_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_6.ll -o ir/13_6.ll 2>/dev/null;

13_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/13_7/src/13_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/13_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/13_7_orig.ll -o ir/13_7.ll 2>13_7/xlopt.log;
13_7_llopt: 13_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/13_7.ll -o ir/13_7.ll 2>/dev/null;

14_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_0/src/14_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/14_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_0_orig.ll -o ir/14_0.ll 2>14_0/xlopt.log;
14_0_llopt: 14_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_0.ll -o ir/14_0.ll 2>/dev/null;

14_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_1/src/14_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/14_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_1_orig.ll -o ir/14_1.ll 2>14_1/xlopt.log;
14_1_llopt: 14_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_1.ll -o ir/14_1.ll 2>/dev/null;

14_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_2/src/14_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/14_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_2_orig.ll -o ir/14_2.ll 2>14_2/xlopt.log;
14_2_llopt: 14_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_2.ll -o ir/14_2.ll 2>/dev/null;

14_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_3/src/14_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/14_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_3_orig.ll -o ir/14_3.ll 2>14_3/xlopt.log;
14_3_llopt: 14_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_3.ll -o ir/14_3.ll 2>/dev/null;

14_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_4/src/14_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/14_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_4_orig.ll -o ir/14_4.ll 2>14_4/xlopt.log;
14_4_llopt: 14_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_4.ll -o ir/14_4.ll 2>/dev/null;

14_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_5/src/14_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/14_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_5_orig.ll -o ir/14_5.ll 2>14_5/xlopt.log;
14_5_llopt: 14_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_5.ll -o ir/14_5.ll 2>/dev/null;

14_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_6/src/14_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/14_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_6_orig.ll -o ir/14_6.ll 2>14_6/xlopt.log;
14_6_llopt: 14_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_6.ll -o ir/14_6.ll 2>/dev/null;

14_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/14_7/src/14_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/14_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/14_7_orig.ll -o ir/14_7.ll 2>14_7/xlopt.log;
14_7_llopt: 14_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/14_7.ll -o ir/14_7.ll 2>/dev/null;

15_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_0/src/15_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/15_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_0_orig.ll -o ir/15_0.ll 2>15_0/xlopt.log;
15_0_llopt: 15_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_0.ll -o ir/15_0.ll 2>/dev/null;

15_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_1/src/15_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/15_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_1_orig.ll -o ir/15_1.ll 2>15_1/xlopt.log;
15_1_llopt: 15_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_1.ll -o ir/15_1.ll 2>/dev/null;

15_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_2/src/15_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/15_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_2_orig.ll -o ir/15_2.ll 2>15_2/xlopt.log;
15_2_llopt: 15_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_2.ll -o ir/15_2.ll 2>/dev/null;

15_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_3/src/15_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/15_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_3_orig.ll -o ir/15_3.ll 2>15_3/xlopt.log;
15_3_llopt: 15_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_3.ll -o ir/15_3.ll 2>/dev/null;

15_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_4/src/15_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/15_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_4_orig.ll -o ir/15_4.ll 2>15_4/xlopt.log;
15_4_llopt: 15_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_4.ll -o ir/15_4.ll 2>/dev/null;

15_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_5/src/15_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/15_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_5_orig.ll -o ir/15_5.ll 2>15_5/xlopt.log;
15_5_llopt: 15_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_5.ll -o ir/15_5.ll 2>/dev/null;

15_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_6/src/15_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/15_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_6_orig.ll -o ir/15_6.ll 2>15_6/xlopt.log;
15_6_llopt: 15_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_6.ll -o ir/15_6.ll 2>/dev/null;

15_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/15_7/src/15_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/15_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/15_7_orig.ll -o ir/15_7.ll 2>15_7/xlopt.log;
15_7_llopt: 15_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/15_7.ll -o ir/15_7.ll 2>/dev/null;

16_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_0/src/16_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/16_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_0_orig.ll -o ir/16_0.ll 2>16_0/xlopt.log;
16_0_llopt: 16_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_0.ll -o ir/16_0.ll 2>/dev/null;

16_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_1/src/16_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/16_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_1_orig.ll -o ir/16_1.ll 2>16_1/xlopt.log;
16_1_llopt: 16_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_1.ll -o ir/16_1.ll 2>/dev/null;

16_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_2/src/16_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/16_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_2_orig.ll -o ir/16_2.ll 2>16_2/xlopt.log;
16_2_llopt: 16_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_2.ll -o ir/16_2.ll 2>/dev/null;

16_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_3/src/16_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/16_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_3_orig.ll -o ir/16_3.ll 2>16_3/xlopt.log;
16_3_llopt: 16_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_3.ll -o ir/16_3.ll 2>/dev/null;

16_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_4/src/16_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/16_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_4_orig.ll -o ir/16_4.ll 2>16_4/xlopt.log;
16_4_llopt: 16_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_4.ll -o ir/16_4.ll 2>/dev/null;

16_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_5/src/16_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/16_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_5_orig.ll -o ir/16_5.ll 2>16_5/xlopt.log;
16_5_llopt: 16_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_5.ll -o ir/16_5.ll 2>/dev/null;

16_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_6/src/16_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/16_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_6_orig.ll -o ir/16_6.ll 2>16_6/xlopt.log;
16_6_llopt: 16_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_6.ll -o ir/16_6.ll 2>/dev/null;

16_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/16_7/src/16_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/16_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/16_7_orig.ll -o ir/16_7.ll 2>16_7/xlopt.log;
16_7_llopt: 16_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/16_7.ll -o ir/16_7.ll 2>/dev/null;

17_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_0/src/17_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/17_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_0_orig.ll -o ir/17_0.ll 2>17_0/xlopt.log;
17_0_llopt: 17_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_0.ll -o ir/17_0.ll 2>/dev/null;

17_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_1/src/17_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/17_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_1_orig.ll -o ir/17_1.ll 2>17_1/xlopt.log;
17_1_llopt: 17_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_1.ll -o ir/17_1.ll 2>/dev/null;

17_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_2/src/17_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/17_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_2_orig.ll -o ir/17_2.ll 2>17_2/xlopt.log;
17_2_llopt: 17_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_2.ll -o ir/17_2.ll 2>/dev/null;

17_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_3/src/17_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/17_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_3_orig.ll -o ir/17_3.ll 2>17_3/xlopt.log;
17_3_llopt: 17_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_3.ll -o ir/17_3.ll 2>/dev/null;

17_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_4/src/17_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/17_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_4_orig.ll -o ir/17_4.ll 2>17_4/xlopt.log;
17_4_llopt: 17_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_4.ll -o ir/17_4.ll 2>/dev/null;

17_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_5/src/17_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/17_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_5_orig.ll -o ir/17_5.ll 2>17_5/xlopt.log;
17_5_llopt: 17_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_5.ll -o ir/17_5.ll 2>/dev/null;

17_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_6/src/17_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/17_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_6_orig.ll -o ir/17_6.ll 2>17_6/xlopt.log;
17_6_llopt: 17_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_6.ll -o ir/17_6.ll 2>/dev/null;

17_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/17_7/src/17_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/17_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/17_7_orig.ll -o ir/17_7.ll 2>17_7/xlopt.log;
17_7_llopt: 17_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/17_7.ll -o ir/17_7.ll 2>/dev/null;

18_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_0/src/18_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/18_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_0_orig.ll -o ir/18_0.ll 2>18_0/xlopt.log;
18_0_llopt: 18_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_0.ll -o ir/18_0.ll 2>/dev/null;

18_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_1/src/18_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/18_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_1_orig.ll -o ir/18_1.ll 2>18_1/xlopt.log;
18_1_llopt: 18_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_1.ll -o ir/18_1.ll 2>/dev/null;

18_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_2/src/18_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/18_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_2_orig.ll -o ir/18_2.ll 2>18_2/xlopt.log;
18_2_llopt: 18_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_2.ll -o ir/18_2.ll 2>/dev/null;

18_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_3/src/18_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/18_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_3_orig.ll -o ir/18_3.ll 2>18_3/xlopt.log;
18_3_llopt: 18_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_3.ll -o ir/18_3.ll 2>/dev/null;

18_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_4/src/18_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/18_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_4_orig.ll -o ir/18_4.ll 2>18_4/xlopt.log;
18_4_llopt: 18_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_4.ll -o ir/18_4.ll 2>/dev/null;

18_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_5/src/18_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/18_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_5_orig.ll -o ir/18_5.ll 2>18_5/xlopt.log;
18_5_llopt: 18_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_5.ll -o ir/18_5.ll 2>/dev/null;

18_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_6/src/18_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/18_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_6_orig.ll -o ir/18_6.ll 2>18_6/xlopt.log;
18_6_llopt: 18_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_6.ll -o ir/18_6.ll 2>/dev/null;

18_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/18_7/src/18_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/18_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/18_7_orig.ll -o ir/18_7.ll 2>18_7/xlopt.log;
18_7_llopt: 18_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/18_7.ll -o ir/18_7.ll 2>/dev/null;

19_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_0/src/19_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/19_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_0_orig.ll -o ir/19_0.ll 2>19_0/xlopt.log;
19_0_llopt: 19_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_0.ll -o ir/19_0.ll 2>/dev/null;

19_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_1/src/19_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/19_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_1_orig.ll -o ir/19_1.ll 2>19_1/xlopt.log;
19_1_llopt: 19_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_1.ll -o ir/19_1.ll 2>/dev/null;

19_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_2/src/19_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/19_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_2_orig.ll -o ir/19_2.ll 2>19_2/xlopt.log;
19_2_llopt: 19_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_2.ll -o ir/19_2.ll 2>/dev/null;

19_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_3/src/19_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/19_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_3_orig.ll -o ir/19_3.ll 2>19_3/xlopt.log;
19_3_llopt: 19_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_3.ll -o ir/19_3.ll 2>/dev/null;

19_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_4/src/19_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/19_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_4_orig.ll -o ir/19_4.ll 2>19_4/xlopt.log;
19_4_llopt: 19_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_4.ll -o ir/19_4.ll 2>/dev/null;

19_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_5/src/19_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/19_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_5_orig.ll -o ir/19_5.ll 2>19_5/xlopt.log;
19_5_llopt: 19_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_5.ll -o ir/19_5.ll 2>/dev/null;

19_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_6/src/19_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/19_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_6_orig.ll -o ir/19_6.ll 2>19_6/xlopt.log;
19_6_llopt: 19_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_6.ll -o ir/19_6.ll 2>/dev/null;

19_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/19_7/src/19_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/19_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/19_7_orig.ll -o ir/19_7.ll 2>19_7/xlopt.log;
19_7_llopt: 19_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/19_7.ll -o ir/19_7.ll 2>/dev/null;

20_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_0/src/20_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/20_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_0_orig.ll -o ir/20_0.ll 2>20_0/xlopt.log;
20_0_llopt: 20_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_0.ll -o ir/20_0.ll 2>/dev/null;

20_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_1/src/20_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/20_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_1_orig.ll -o ir/20_1.ll 2>20_1/xlopt.log;
20_1_llopt: 20_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_1.ll -o ir/20_1.ll 2>/dev/null;

20_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_2/src/20_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/20_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_2_orig.ll -o ir/20_2.ll 2>20_2/xlopt.log;
20_2_llopt: 20_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_2.ll -o ir/20_2.ll 2>/dev/null;

20_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_3/src/20_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/20_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_3_orig.ll -o ir/20_3.ll 2>20_3/xlopt.log;
20_3_llopt: 20_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_3.ll -o ir/20_3.ll 2>/dev/null;

20_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_4/src/20_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/20_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_4_orig.ll -o ir/20_4.ll 2>20_4/xlopt.log;
20_4_llopt: 20_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_4.ll -o ir/20_4.ll 2>/dev/null;

20_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_5/src/20_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/20_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_5_orig.ll -o ir/20_5.ll 2>20_5/xlopt.log;
20_5_llopt: 20_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_5.ll -o ir/20_5.ll 2>/dev/null;

20_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_6/src/20_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/20_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_6_orig.ll -o ir/20_6.ll 2>20_6/xlopt.log;
20_6_llopt: 20_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_6.ll -o ir/20_6.ll 2>/dev/null;

20_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/20_7/src/20_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/20_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/20_7_orig.ll -o ir/20_7.ll 2>20_7/xlopt.log;
20_7_llopt: 20_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/20_7.ll -o ir/20_7.ll 2>/dev/null;

21_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_0/src/21_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/21_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_0_orig.ll -o ir/21_0.ll 2>21_0/xlopt.log;
21_0_llopt: 21_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_0.ll -o ir/21_0.ll 2>/dev/null;

21_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_1/src/21_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/21_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_1_orig.ll -o ir/21_1.ll 2>21_1/xlopt.log;
21_1_llopt: 21_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_1.ll -o ir/21_1.ll 2>/dev/null;

21_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_2/src/21_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/21_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_2_orig.ll -o ir/21_2.ll 2>21_2/xlopt.log;
21_2_llopt: 21_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_2.ll -o ir/21_2.ll 2>/dev/null;

21_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_3/src/21_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/21_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_3_orig.ll -o ir/21_3.ll 2>21_3/xlopt.log;
21_3_llopt: 21_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_3.ll -o ir/21_3.ll 2>/dev/null;

21_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_4/src/21_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/21_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_4_orig.ll -o ir/21_4.ll 2>21_4/xlopt.log;
21_4_llopt: 21_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_4.ll -o ir/21_4.ll 2>/dev/null;

21_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_5/src/21_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/21_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_5_orig.ll -o ir/21_5.ll 2>21_5/xlopt.log;
21_5_llopt: 21_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_5.ll -o ir/21_5.ll 2>/dev/null;

21_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_6/src/21_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/21_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_6_orig.ll -o ir/21_6.ll 2>21_6/xlopt.log;
21_6_llopt: 21_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_6.ll -o ir/21_6.ll 2>/dev/null;

21_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/21_7/src/21_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/21_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/21_7_orig.ll -o ir/21_7.ll 2>21_7/xlopt.log;
21_7_llopt: 21_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/21_7.ll -o ir/21_7.ll 2>/dev/null;

22_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_0/src/22_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/22_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_0_orig.ll -o ir/22_0.ll 2>22_0/xlopt.log;
22_0_llopt: 22_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_0.ll -o ir/22_0.ll 2>/dev/null;

22_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_1/src/22_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/22_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_1_orig.ll -o ir/22_1.ll 2>22_1/xlopt.log;
22_1_llopt: 22_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_1.ll -o ir/22_1.ll 2>/dev/null;

22_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_2/src/22_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/22_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_2_orig.ll -o ir/22_2.ll 2>22_2/xlopt.log;
22_2_llopt: 22_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_2.ll -o ir/22_2.ll 2>/dev/null;

22_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_3/src/22_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/22_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_3_orig.ll -o ir/22_3.ll 2>22_3/xlopt.log;
22_3_llopt: 22_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_3.ll -o ir/22_3.ll 2>/dev/null;

22_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_4/src/22_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/22_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_4_orig.ll -o ir/22_4.ll 2>22_4/xlopt.log;
22_4_llopt: 22_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_4.ll -o ir/22_4.ll 2>/dev/null;

22_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_5/src/22_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/22_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_5_orig.ll -o ir/22_5.ll 2>22_5/xlopt.log;
22_5_llopt: 22_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_5.ll -o ir/22_5.ll 2>/dev/null;

22_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_6/src/22_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/22_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_6_orig.ll -o ir/22_6.ll 2>22_6/xlopt.log;
22_6_llopt: 22_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_6.ll -o ir/22_6.ll 2>/dev/null;

22_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/22_7/src/22_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/22_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/22_7_orig.ll -o ir/22_7.ll 2>22_7/xlopt.log;
22_7_llopt: 22_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/22_7.ll -o ir/22_7.ll 2>/dev/null;

23_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_0/src/23_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/23_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_0_orig.ll -o ir/23_0.ll 2>23_0/xlopt.log;
23_0_llopt: 23_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_0.ll -o ir/23_0.ll 2>/dev/null;

23_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_1/src/23_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/23_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_1_orig.ll -o ir/23_1.ll 2>23_1/xlopt.log;
23_1_llopt: 23_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_1.ll -o ir/23_1.ll 2>/dev/null;

23_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_2/src/23_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/23_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_2_orig.ll -o ir/23_2.ll 2>23_2/xlopt.log;
23_2_llopt: 23_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_2.ll -o ir/23_2.ll 2>/dev/null;

23_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_3/src/23_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/23_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_3_orig.ll -o ir/23_3.ll 2>23_3/xlopt.log;
23_3_llopt: 23_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_3.ll -o ir/23_3.ll 2>/dev/null;

23_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_4/src/23_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/23_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_4_orig.ll -o ir/23_4.ll 2>23_4/xlopt.log;
23_4_llopt: 23_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_4.ll -o ir/23_4.ll 2>/dev/null;

23_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_5/src/23_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/23_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_5_orig.ll -o ir/23_5.ll 2>23_5/xlopt.log;
23_5_llopt: 23_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_5.ll -o ir/23_5.ll 2>/dev/null;

23_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_6/src/23_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/23_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_6_orig.ll -o ir/23_6.ll 2>23_6/xlopt.log;
23_6_llopt: 23_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_6.ll -o ir/23_6.ll 2>/dev/null;

23_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/23_7/src/23_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/23_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/23_7_orig.ll -o ir/23_7.ll 2>23_7/xlopt.log;
23_7_llopt: 23_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/23_7.ll -o ir/23_7.ll 2>/dev/null;

24_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_0/src/24_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/24_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_0_orig.ll -o ir/24_0.ll 2>24_0/xlopt.log;
24_0_llopt: 24_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_0.ll -o ir/24_0.ll 2>/dev/null;

24_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_1/src/24_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/24_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_1_orig.ll -o ir/24_1.ll 2>24_1/xlopt.log;
24_1_llopt: 24_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_1.ll -o ir/24_1.ll 2>/dev/null;

24_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_2/src/24_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/24_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_2_orig.ll -o ir/24_2.ll 2>24_2/xlopt.log;
24_2_llopt: 24_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_2.ll -o ir/24_2.ll 2>/dev/null;

24_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_3/src/24_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/24_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_3_orig.ll -o ir/24_3.ll 2>24_3/xlopt.log;
24_3_llopt: 24_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_3.ll -o ir/24_3.ll 2>/dev/null;

24_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_4/src/24_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/24_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_4_orig.ll -o ir/24_4.ll 2>24_4/xlopt.log;
24_4_llopt: 24_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_4.ll -o ir/24_4.ll 2>/dev/null;

24_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_5/src/24_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/24_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_5_orig.ll -o ir/24_5.ll 2>24_5/xlopt.log;
24_5_llopt: 24_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_5.ll -o ir/24_5.ll 2>/dev/null;

24_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_6/src/24_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/24_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_6_orig.ll -o ir/24_6.ll 2>24_6/xlopt.log;
24_6_llopt: 24_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_6.ll -o ir/24_6.ll 2>/dev/null;

24_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/24_7/src/24_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/24_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/24_7_orig.ll -o ir/24_7.ll 2>24_7/xlopt.log;
24_7_llopt: 24_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/24_7.ll -o ir/24_7.ll 2>/dev/null;

25_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_0/src/25_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/25_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_0_orig.ll -o ir/25_0.ll 2>25_0/xlopt.log;
25_0_llopt: 25_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_0.ll -o ir/25_0.ll 2>/dev/null;

25_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_1/src/25_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/25_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_1_orig.ll -o ir/25_1.ll 2>25_1/xlopt.log;
25_1_llopt: 25_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_1.ll -o ir/25_1.ll 2>/dev/null;

25_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_2/src/25_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/25_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_2_orig.ll -o ir/25_2.ll 2>25_2/xlopt.log;
25_2_llopt: 25_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_2.ll -o ir/25_2.ll 2>/dev/null;

25_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_3/src/25_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/25_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_3_orig.ll -o ir/25_3.ll 2>25_3/xlopt.log;
25_3_llopt: 25_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_3.ll -o ir/25_3.ll 2>/dev/null;

25_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_4/src/25_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/25_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_4_orig.ll -o ir/25_4.ll 2>25_4/xlopt.log;
25_4_llopt: 25_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_4.ll -o ir/25_4.ll 2>/dev/null;

25_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_5/src/25_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/25_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_5_orig.ll -o ir/25_5.ll 2>25_5/xlopt.log;
25_5_llopt: 25_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_5.ll -o ir/25_5.ll 2>/dev/null;

25_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_6/src/25_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/25_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_6_orig.ll -o ir/25_6.ll 2>25_6/xlopt.log;
25_6_llopt: 25_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_6.ll -o ir/25_6.ll 2>/dev/null;

25_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/25_7/src/25_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/25_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/25_7_orig.ll -o ir/25_7.ll 2>25_7/xlopt.log;
25_7_llopt: 25_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/25_7.ll -o ir/25_7.ll 2>/dev/null;

26_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_0/src/26_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/26_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_0_orig.ll -o ir/26_0.ll 2>26_0/xlopt.log;
26_0_llopt: 26_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_0.ll -o ir/26_0.ll 2>/dev/null;

26_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_1/src/26_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/26_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_1_orig.ll -o ir/26_1.ll 2>26_1/xlopt.log;
26_1_llopt: 26_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_1.ll -o ir/26_1.ll 2>/dev/null;

26_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_2/src/26_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/26_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_2_orig.ll -o ir/26_2.ll 2>26_2/xlopt.log;
26_2_llopt: 26_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_2.ll -o ir/26_2.ll 2>/dev/null;

26_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_3/src/26_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/26_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_3_orig.ll -o ir/26_3.ll 2>26_3/xlopt.log;
26_3_llopt: 26_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_3.ll -o ir/26_3.ll 2>/dev/null;

26_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_4/src/26_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/26_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_4_orig.ll -o ir/26_4.ll 2>26_4/xlopt.log;
26_4_llopt: 26_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_4.ll -o ir/26_4.ll 2>/dev/null;

26_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_5/src/26_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/26_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_5_orig.ll -o ir/26_5.ll 2>26_5/xlopt.log;
26_5_llopt: 26_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_5.ll -o ir/26_5.ll 2>/dev/null;

26_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_6/src/26_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/26_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_6_orig.ll -o ir/26_6.ll 2>26_6/xlopt.log;
26_6_llopt: 26_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_6.ll -o ir/26_6.ll 2>/dev/null;

26_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/26_7/src/26_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/26_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/26_7_orig.ll -o ir/26_7.ll 2>26_7/xlopt.log;
26_7_llopt: 26_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/26_7.ll -o ir/26_7.ll 2>/dev/null;

27_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_0/src/27_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/27_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_0_orig.ll -o ir/27_0.ll 2>27_0/xlopt.log;
27_0_llopt: 27_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_0.ll -o ir/27_0.ll 2>/dev/null;

27_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_1/src/27_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/27_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_1_orig.ll -o ir/27_1.ll 2>27_1/xlopt.log;
27_1_llopt: 27_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_1.ll -o ir/27_1.ll 2>/dev/null;

27_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_2/src/27_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/27_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_2_orig.ll -o ir/27_2.ll 2>27_2/xlopt.log;
27_2_llopt: 27_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_2.ll -o ir/27_2.ll 2>/dev/null;

27_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_3/src/27_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/27_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_3_orig.ll -o ir/27_3.ll 2>27_3/xlopt.log;
27_3_llopt: 27_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_3.ll -o ir/27_3.ll 2>/dev/null;

27_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_4/src/27_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/27_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_4_orig.ll -o ir/27_4.ll 2>27_4/xlopt.log;
27_4_llopt: 27_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_4.ll -o ir/27_4.ll 2>/dev/null;

27_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_5/src/27_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/27_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_5_orig.ll -o ir/27_5.ll 2>27_5/xlopt.log;
27_5_llopt: 27_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_5.ll -o ir/27_5.ll 2>/dev/null;

27_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_6/src/27_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/27_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_6_orig.ll -o ir/27_6.ll 2>27_6/xlopt.log;
27_6_llopt: 27_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_6.ll -o ir/27_6.ll 2>/dev/null;

27_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/27_7/src/27_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/27_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/27_7_orig.ll -o ir/27_7.ll 2>27_7/xlopt.log;
27_7_llopt: 27_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/27_7.ll -o ir/27_7.ll 2>/dev/null;

28_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_0/src/28_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/28_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_0_orig.ll -o ir/28_0.ll 2>28_0/xlopt.log;
28_0_llopt: 28_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_0.ll -o ir/28_0.ll 2>/dev/null;

28_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_1/src/28_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/28_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_1_orig.ll -o ir/28_1.ll 2>28_1/xlopt.log;
28_1_llopt: 28_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_1.ll -o ir/28_1.ll 2>/dev/null;

28_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_2/src/28_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/28_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_2_orig.ll -o ir/28_2.ll 2>28_2/xlopt.log;
28_2_llopt: 28_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_2.ll -o ir/28_2.ll 2>/dev/null;

28_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_3/src/28_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/28_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_3_orig.ll -o ir/28_3.ll 2>28_3/xlopt.log;
28_3_llopt: 28_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_3.ll -o ir/28_3.ll 2>/dev/null;

28_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_4/src/28_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/28_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_4_orig.ll -o ir/28_4.ll 2>28_4/xlopt.log;
28_4_llopt: 28_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_4.ll -o ir/28_4.ll 2>/dev/null;

28_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_5/src/28_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/28_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_5_orig.ll -o ir/28_5.ll 2>28_5/xlopt.log;
28_5_llopt: 28_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_5.ll -o ir/28_5.ll 2>/dev/null;

28_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_6/src/28_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/28_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_6_orig.ll -o ir/28_6.ll 2>28_6/xlopt.log;
28_6_llopt: 28_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_6.ll -o ir/28_6.ll 2>/dev/null;

28_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/28_7/src/28_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/28_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/28_7_orig.ll -o ir/28_7.ll 2>28_7/xlopt.log;
28_7_llopt: 28_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/28_7.ll -o ir/28_7.ll 2>/dev/null;

29_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_0/src/29_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/29_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_0_orig.ll -o ir/29_0.ll 2>29_0/xlopt.log;
29_0_llopt: 29_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_0.ll -o ir/29_0.ll 2>/dev/null;

29_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_1/src/29_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/29_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_1_orig.ll -o ir/29_1.ll 2>29_1/xlopt.log;
29_1_llopt: 29_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_1.ll -o ir/29_1.ll 2>/dev/null;

29_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_2/src/29_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/29_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_2_orig.ll -o ir/29_2.ll 2>29_2/xlopt.log;
29_2_llopt: 29_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_2.ll -o ir/29_2.ll 2>/dev/null;

29_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_3/src/29_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/29_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_3_orig.ll -o ir/29_3.ll 2>29_3/xlopt.log;
29_3_llopt: 29_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_3.ll -o ir/29_3.ll 2>/dev/null;

29_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_4/src/29_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/29_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_4_orig.ll -o ir/29_4.ll 2>29_4/xlopt.log;
29_4_llopt: 29_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_4.ll -o ir/29_4.ll 2>/dev/null;

29_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_5/src/29_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/29_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_5_orig.ll -o ir/29_5.ll 2>29_5/xlopt.log;
29_5_llopt: 29_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_5.ll -o ir/29_5.ll 2>/dev/null;

29_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_6/src/29_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/29_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_6_orig.ll -o ir/29_6.ll 2>29_6/xlopt.log;
29_6_llopt: 29_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_6.ll -o ir/29_6.ll 2>/dev/null;

29_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/29_7/src/29_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/29_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/29_7_orig.ll -o ir/29_7.ll 2>29_7/xlopt.log;
29_7_llopt: 29_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/29_7.ll -o ir/29_7.ll 2>/dev/null;

30_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_0/src/30_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/30_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_0_orig.ll -o ir/30_0.ll 2>30_0/xlopt.log;
30_0_llopt: 30_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_0.ll -o ir/30_0.ll 2>/dev/null;

30_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_1/src/30_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/30_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_1_orig.ll -o ir/30_1.ll 2>30_1/xlopt.log;
30_1_llopt: 30_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_1.ll -o ir/30_1.ll 2>/dev/null;

30_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_2/src/30_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/30_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_2_orig.ll -o ir/30_2.ll 2>30_2/xlopt.log;
30_2_llopt: 30_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_2.ll -o ir/30_2.ll 2>/dev/null;

30_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_3/src/30_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/30_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_3_orig.ll -o ir/30_3.ll 2>30_3/xlopt.log;
30_3_llopt: 30_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_3.ll -o ir/30_3.ll 2>/dev/null;

30_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_4/src/30_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/30_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_4_orig.ll -o ir/30_4.ll 2>30_4/xlopt.log;
30_4_llopt: 30_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_4.ll -o ir/30_4.ll 2>/dev/null;

30_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_5/src/30_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/30_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_5_orig.ll -o ir/30_5.ll 2>30_5/xlopt.log;
30_5_llopt: 30_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_5.ll -o ir/30_5.ll 2>/dev/null;

30_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_6/src/30_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/30_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_6_orig.ll -o ir/30_6.ll 2>30_6/xlopt.log;
30_6_llopt: 30_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_6.ll -o ir/30_6.ll 2>/dev/null;

30_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/30_7/src/30_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/30_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/30_7_orig.ll -o ir/30_7.ll 2>30_7/xlopt.log;
30_7_llopt: 30_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/30_7.ll -o ir/30_7.ll 2>/dev/null;

31_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_0/src/31_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/31_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_0_orig.ll -o ir/31_0.ll 2>31_0/xlopt.log;
31_0_llopt: 31_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_0.ll -o ir/31_0.ll 2>/dev/null;

31_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_1/src/31_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/31_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_1_orig.ll -o ir/31_1.ll 2>31_1/xlopt.log;
31_1_llopt: 31_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_1.ll -o ir/31_1.ll 2>/dev/null;

31_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_2/src/31_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/31_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_2_orig.ll -o ir/31_2.ll 2>31_2/xlopt.log;
31_2_llopt: 31_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_2.ll -o ir/31_2.ll 2>/dev/null;

31_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_3/src/31_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/31_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_3_orig.ll -o ir/31_3.ll 2>31_3/xlopt.log;
31_3_llopt: 31_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_3.ll -o ir/31_3.ll 2>/dev/null;

31_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_4/src/31_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/31_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_4_orig.ll -o ir/31_4.ll 2>31_4/xlopt.log;
31_4_llopt: 31_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_4.ll -o ir/31_4.ll 2>/dev/null;

31_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_5/src/31_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/31_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_5_orig.ll -o ir/31_5.ll 2>31_5/xlopt.log;
31_5_llopt: 31_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_5.ll -o ir/31_5.ll 2>/dev/null;

31_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_6/src/31_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/31_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_6_orig.ll -o ir/31_6.ll 2>31_6/xlopt.log;
31_6_llopt: 31_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_6.ll -o ir/31_6.ll 2>/dev/null;

31_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/31_7/src/31_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/31_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/31_7_orig.ll -o ir/31_7.ll 2>31_7/xlopt.log;
31_7_llopt: 31_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/31_7.ll -o ir/31_7.ll 2>/dev/null;

32_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_0/src/32_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/32_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_0_orig.ll -o ir/32_0.ll 2>32_0/xlopt.log;
32_0_llopt: 32_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_0.ll -o ir/32_0.ll 2>/dev/null;

32_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_1/src/32_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/32_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_1_orig.ll -o ir/32_1.ll 2>32_1/xlopt.log;
32_1_llopt: 32_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_1.ll -o ir/32_1.ll 2>/dev/null;

32_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_2/src/32_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/32_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_2_orig.ll -o ir/32_2.ll 2>32_2/xlopt.log;
32_2_llopt: 32_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_2.ll -o ir/32_2.ll 2>/dev/null;

32_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_3/src/32_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/32_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_3_orig.ll -o ir/32_3.ll 2>32_3/xlopt.log;
32_3_llopt: 32_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_3.ll -o ir/32_3.ll 2>/dev/null;

32_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_4/src/32_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/32_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_4_orig.ll -o ir/32_4.ll 2>32_4/xlopt.log;
32_4_llopt: 32_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_4.ll -o ir/32_4.ll 2>/dev/null;

32_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_5/src/32_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/32_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_5_orig.ll -o ir/32_5.ll 2>32_5/xlopt.log;
32_5_llopt: 32_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_5.ll -o ir/32_5.ll 2>/dev/null;

32_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_6/src/32_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/32_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_6_orig.ll -o ir/32_6.ll 2>32_6/xlopt.log;
32_6_llopt: 32_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_6.ll -o ir/32_6.ll 2>/dev/null;

32_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/32_7/src/32_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/32_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/32_7_orig.ll -o ir/32_7.ll 2>32_7/xlopt.log;
32_7_llopt: 32_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/32_7.ll -o ir/32_7.ll 2>/dev/null;

33_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_0/src/33_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/33_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_0_orig.ll -o ir/33_0.ll 2>33_0/xlopt.log;
33_0_llopt: 33_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_0.ll -o ir/33_0.ll 2>/dev/null;

33_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_1/src/33_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/33_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_1_orig.ll -o ir/33_1.ll 2>33_1/xlopt.log;
33_1_llopt: 33_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_1.ll -o ir/33_1.ll 2>/dev/null;

33_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_2/src/33_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/33_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_2_orig.ll -o ir/33_2.ll 2>33_2/xlopt.log;
33_2_llopt: 33_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_2.ll -o ir/33_2.ll 2>/dev/null;

33_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_3/src/33_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/33_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_3_orig.ll -o ir/33_3.ll 2>33_3/xlopt.log;
33_3_llopt: 33_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_3.ll -o ir/33_3.ll 2>/dev/null;

33_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_4/src/33_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/33_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_4_orig.ll -o ir/33_4.ll 2>33_4/xlopt.log;
33_4_llopt: 33_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_4.ll -o ir/33_4.ll 2>/dev/null;

33_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_5/src/33_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/33_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_5_orig.ll -o ir/33_5.ll 2>33_5/xlopt.log;
33_5_llopt: 33_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_5.ll -o ir/33_5.ll 2>/dev/null;

33_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_6/src/33_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/33_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_6_orig.ll -o ir/33_6.ll 2>33_6/xlopt.log;
33_6_llopt: 33_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_6.ll -o ir/33_6.ll 2>/dev/null;

33_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/33_7/src/33_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/33_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/33_7_orig.ll -o ir/33_7.ll 2>33_7/xlopt.log;
33_7_llopt: 33_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/33_7.ll -o ir/33_7.ll 2>/dev/null;

34_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_0/src/34_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/34_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_0_orig.ll -o ir/34_0.ll 2>34_0/xlopt.log;
34_0_llopt: 34_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_0.ll -o ir/34_0.ll 2>/dev/null;

34_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_1/src/34_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/34_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_1_orig.ll -o ir/34_1.ll 2>34_1/xlopt.log;
34_1_llopt: 34_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_1.ll -o ir/34_1.ll 2>/dev/null;

34_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_2/src/34_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/34_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_2_orig.ll -o ir/34_2.ll 2>34_2/xlopt.log;
34_2_llopt: 34_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_2.ll -o ir/34_2.ll 2>/dev/null;

34_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_3/src/34_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/34_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_3_orig.ll -o ir/34_3.ll 2>34_3/xlopt.log;
34_3_llopt: 34_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_3.ll -o ir/34_3.ll 2>/dev/null;

34_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_4/src/34_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/34_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_4_orig.ll -o ir/34_4.ll 2>34_4/xlopt.log;
34_4_llopt: 34_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_4.ll -o ir/34_4.ll 2>/dev/null;

34_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_5/src/34_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/34_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_5_orig.ll -o ir/34_5.ll 2>34_5/xlopt.log;
34_5_llopt: 34_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_5.ll -o ir/34_5.ll 2>/dev/null;

34_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_6/src/34_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/34_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_6_orig.ll -o ir/34_6.ll 2>34_6/xlopt.log;
34_6_llopt: 34_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_6.ll -o ir/34_6.ll 2>/dev/null;

34_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/34_7/src/34_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/34_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/34_7_orig.ll -o ir/34_7.ll 2>34_7/xlopt.log;
34_7_llopt: 34_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/34_7.ll -o ir/34_7.ll 2>/dev/null;

35_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_0/src/35_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/35_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_0_orig.ll -o ir/35_0.ll 2>35_0/xlopt.log;
35_0_llopt: 35_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_0.ll -o ir/35_0.ll 2>/dev/null;

35_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_1/src/35_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/35_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_1_orig.ll -o ir/35_1.ll 2>35_1/xlopt.log;
35_1_llopt: 35_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_1.ll -o ir/35_1.ll 2>/dev/null;

35_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_2/src/35_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/35_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_2_orig.ll -o ir/35_2.ll 2>35_2/xlopt.log;
35_2_llopt: 35_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_2.ll -o ir/35_2.ll 2>/dev/null;

35_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_3/src/35_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/35_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_3_orig.ll -o ir/35_3.ll 2>35_3/xlopt.log;
35_3_llopt: 35_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_3.ll -o ir/35_3.ll 2>/dev/null;

35_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_4/src/35_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/35_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_4_orig.ll -o ir/35_4.ll 2>35_4/xlopt.log;
35_4_llopt: 35_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_4.ll -o ir/35_4.ll 2>/dev/null;

35_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_5/src/35_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/35_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_5_orig.ll -o ir/35_5.ll 2>35_5/xlopt.log;
35_5_llopt: 35_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_5.ll -o ir/35_5.ll 2>/dev/null;

35_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_6/src/35_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/35_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_6_orig.ll -o ir/35_6.ll 2>35_6/xlopt.log;
35_6_llopt: 35_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_6.ll -o ir/35_6.ll 2>/dev/null;

35_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/35_7/src/35_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/35_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/35_7_orig.ll -o ir/35_7.ll 2>35_7/xlopt.log;
35_7_llopt: 35_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/35_7.ll -o ir/35_7.ll 2>/dev/null;

36_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_0/src/36_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/36_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_0_orig.ll -o ir/36_0.ll 2>36_0/xlopt.log;
36_0_llopt: 36_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_0.ll -o ir/36_0.ll 2>/dev/null;

36_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_1/src/36_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/36_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_1_orig.ll -o ir/36_1.ll 2>36_1/xlopt.log;
36_1_llopt: 36_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_1.ll -o ir/36_1.ll 2>/dev/null;

36_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_2/src/36_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/36_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_2_orig.ll -o ir/36_2.ll 2>36_2/xlopt.log;
36_2_llopt: 36_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_2.ll -o ir/36_2.ll 2>/dev/null;

36_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_3/src/36_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/36_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_3_orig.ll -o ir/36_3.ll 2>36_3/xlopt.log;
36_3_llopt: 36_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_3.ll -o ir/36_3.ll 2>/dev/null;

36_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_4/src/36_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/36_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_4_orig.ll -o ir/36_4.ll 2>36_4/xlopt.log;
36_4_llopt: 36_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_4.ll -o ir/36_4.ll 2>/dev/null;

36_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_5/src/36_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/36_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_5_orig.ll -o ir/36_5.ll 2>36_5/xlopt.log;
36_5_llopt: 36_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_5.ll -o ir/36_5.ll 2>/dev/null;

36_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_6/src/36_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/36_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_6_orig.ll -o ir/36_6.ll 2>36_6/xlopt.log;
36_6_llopt: 36_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_6.ll -o ir/36_6.ll 2>/dev/null;

36_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/36_7/src/36_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/36_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/36_7_orig.ll -o ir/36_7.ll 2>36_7/xlopt.log;
36_7_llopt: 36_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/36_7.ll -o ir/36_7.ll 2>/dev/null;

37_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_0/src/37_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/37_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_0_orig.ll -o ir/37_0.ll 2>37_0/xlopt.log;
37_0_llopt: 37_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_0.ll -o ir/37_0.ll 2>/dev/null;

37_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_1/src/37_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/37_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_1_orig.ll -o ir/37_1.ll 2>37_1/xlopt.log;
37_1_llopt: 37_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_1.ll -o ir/37_1.ll 2>/dev/null;

37_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_2/src/37_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/37_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_2_orig.ll -o ir/37_2.ll 2>37_2/xlopt.log;
37_2_llopt: 37_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_2.ll -o ir/37_2.ll 2>/dev/null;

37_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_3/src/37_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/37_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_3_orig.ll -o ir/37_3.ll 2>37_3/xlopt.log;
37_3_llopt: 37_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_3.ll -o ir/37_3.ll 2>/dev/null;

37_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_4/src/37_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/37_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_4_orig.ll -o ir/37_4.ll 2>37_4/xlopt.log;
37_4_llopt: 37_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_4.ll -o ir/37_4.ll 2>/dev/null;

37_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_5/src/37_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/37_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_5_orig.ll -o ir/37_5.ll 2>37_5/xlopt.log;
37_5_llopt: 37_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_5.ll -o ir/37_5.ll 2>/dev/null;

37_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_6/src/37_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/37_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_6_orig.ll -o ir/37_6.ll 2>37_6/xlopt.log;
37_6_llopt: 37_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_6.ll -o ir/37_6.ll 2>/dev/null;

37_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_7/src/37_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/37_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_7_orig.ll -o ir/37_7.ll 2>37_7/xlopt.log;
37_7_llopt: 37_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_7.ll -o ir/37_7.ll 2>/dev/null;

38_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_0/src/38_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/38_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_0_orig.ll -o ir/38_0.ll 2>38_0/xlopt.log;
38_0_llopt: 38_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_0.ll -o ir/38_0.ll 2>/dev/null;

38_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_1/src/38_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_1_orig.ll -o ir/38_1.ll 2>38_1/xlopt.log;
38_1_llopt: 38_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_1.ll -o ir/38_1.ll 2>/dev/null;

38_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_2/src/38_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_2_orig.ll -o ir/38_2.ll 2>38_2/xlopt.log;
38_2_llopt: 38_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_2.ll -o ir/38_2.ll 2>/dev/null;

38_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_3/src/38_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_3_orig.ll -o ir/38_3.ll 2>38_3/xlopt.log;
38_3_llopt: 38_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_3.ll -o ir/38_3.ll 2>/dev/null;

38_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_4/src/38_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/38_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_4_orig.ll -o ir/38_4.ll 2>38_4/xlopt.log;
38_4_llopt: 38_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_4.ll -o ir/38_4.ll 2>/dev/null;

38_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_5/src/38_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_5_orig.ll -o ir/38_5.ll 2>38_5/xlopt.log;
38_5_llopt: 38_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_5.ll -o ir/38_5.ll 2>/dev/null;

38_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_6/src/38_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_6_orig.ll -o ir/38_6.ll 2>38_6/xlopt.log;
38_6_llopt: 38_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_6.ll -o ir/38_6.ll 2>/dev/null;

38_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_7/src/38_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_7_orig.ll -o ir/38_7.ll 2>38_7/xlopt.log;
38_7_llopt: 38_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_7.ll -o ir/38_7.ll 2>/dev/null;

39_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_0/src/39_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/39_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_0_orig.ll -o ir/39_0.ll 2>39_0/xlopt.log;
39_0_llopt: 39_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_0.ll -o ir/39_0.ll 2>/dev/null;

39_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_1/src/39_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/39_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_1_orig.ll -o ir/39_1.ll 2>39_1/xlopt.log;
39_1_llopt: 39_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_1.ll -o ir/39_1.ll 2>/dev/null;

39_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_2/src/39_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/39_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_2_orig.ll -o ir/39_2.ll 2>39_2/xlopt.log;
39_2_llopt: 39_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_2.ll -o ir/39_2.ll 2>/dev/null;

39_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_3/src/39_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/39_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_3_orig.ll -o ir/39_3.ll 2>39_3/xlopt.log;
39_3_llopt: 39_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_3.ll -o ir/39_3.ll 2>/dev/null;

39_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_4/src/39_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/39_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_4_orig.ll -o ir/39_4.ll 2>39_4/xlopt.log;
39_4_llopt: 39_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_4.ll -o ir/39_4.ll 2>/dev/null;

39_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_5/src/39_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/39_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_5_orig.ll -o ir/39_5.ll 2>39_5/xlopt.log;
39_5_llopt: 39_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_5.ll -o ir/39_5.ll 2>/dev/null;

39_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_6/src/39_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/39_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_6_orig.ll -o ir/39_6.ll 2>39_6/xlopt.log;
39_6_llopt: 39_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_6.ll -o ir/39_6.ll 2>/dev/null;

39_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/39_7/src/39_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/39_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/39_7_orig.ll -o ir/39_7.ll 2>39_7/xlopt.log;
39_7_llopt: 39_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/39_7.ll -o ir/39_7.ll 2>/dev/null;

40_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_0/src/40_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/40_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_0_orig.ll -o ir/40_0.ll 2>40_0/xlopt.log;
40_0_llopt: 40_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_0.ll -o ir/40_0.ll 2>/dev/null;

40_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_1/src/40_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/40_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_1_orig.ll -o ir/40_1.ll 2>40_1/xlopt.log;
40_1_llopt: 40_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_1.ll -o ir/40_1.ll 2>/dev/null;

40_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_2/src/40_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/40_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_2_orig.ll -o ir/40_2.ll 2>40_2/xlopt.log;
40_2_llopt: 40_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_2.ll -o ir/40_2.ll 2>/dev/null;

40_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_3/src/40_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/40_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_3_orig.ll -o ir/40_3.ll 2>40_3/xlopt.log;
40_3_llopt: 40_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_3.ll -o ir/40_3.ll 2>/dev/null;

40_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_4/src/40_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/40_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_4_orig.ll -o ir/40_4.ll 2>40_4/xlopt.log;
40_4_llopt: 40_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_4.ll -o ir/40_4.ll 2>/dev/null;

40_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_5/src/40_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/40_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_5_orig.ll -o ir/40_5.ll 2>40_5/xlopt.log;
40_5_llopt: 40_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_5.ll -o ir/40_5.ll 2>/dev/null;

40_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_6/src/40_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/40_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_6_orig.ll -o ir/40_6.ll 2>40_6/xlopt.log;
40_6_llopt: 40_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_6.ll -o ir/40_6.ll 2>/dev/null;

40_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/40_7/src/40_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/40_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/40_7_orig.ll -o ir/40_7.ll 2>40_7/xlopt.log;
40_7_llopt: 40_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/40_7.ll -o ir/40_7.ll 2>/dev/null;

41_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_0/src/41_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/41_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_0_orig.ll -o ir/41_0.ll 2>41_0/xlopt.log;
41_0_llopt: 41_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_0.ll -o ir/41_0.ll 2>/dev/null;

41_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_1/src/41_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/41_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_1_orig.ll -o ir/41_1.ll 2>41_1/xlopt.log;
41_1_llopt: 41_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_1.ll -o ir/41_1.ll 2>/dev/null;

41_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_2/src/41_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/41_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_2_orig.ll -o ir/41_2.ll 2>41_2/xlopt.log;
41_2_llopt: 41_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_2.ll -o ir/41_2.ll 2>/dev/null;

41_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_3/src/41_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/41_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_3_orig.ll -o ir/41_3.ll 2>41_3/xlopt.log;
41_3_llopt: 41_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_3.ll -o ir/41_3.ll 2>/dev/null;

41_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_4/src/41_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/41_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_4_orig.ll -o ir/41_4.ll 2>41_4/xlopt.log;
41_4_llopt: 41_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_4.ll -o ir/41_4.ll 2>/dev/null;

41_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_5/src/41_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/41_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_5_orig.ll -o ir/41_5.ll 2>41_5/xlopt.log;
41_5_llopt: 41_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_5.ll -o ir/41_5.ll 2>/dev/null;

41_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_6/src/41_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/41_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_6_orig.ll -o ir/41_6.ll 2>41_6/xlopt.log;
41_6_llopt: 41_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_6.ll -o ir/41_6.ll 2>/dev/null;

41_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/41_7/src/41_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/41_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/41_7_orig.ll -o ir/41_7.ll 2>41_7/xlopt.log;
41_7_llopt: 41_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/41_7.ll -o ir/41_7.ll 2>/dev/null;

42_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_0/src/42_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/42_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_0_orig.ll -o ir/42_0.ll 2>42_0/xlopt.log;
42_0_llopt: 42_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_0.ll -o ir/42_0.ll 2>/dev/null;

42_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_1/src/42_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/42_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_1_orig.ll -o ir/42_1.ll 2>42_1/xlopt.log;
42_1_llopt: 42_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_1.ll -o ir/42_1.ll 2>/dev/null;

42_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_2/src/42_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/42_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_2_orig.ll -o ir/42_2.ll 2>42_2/xlopt.log;
42_2_llopt: 42_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_2.ll -o ir/42_2.ll 2>/dev/null;

42_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_3/src/42_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/42_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_3_orig.ll -o ir/42_3.ll 2>42_3/xlopt.log;
42_3_llopt: 42_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_3.ll -o ir/42_3.ll 2>/dev/null;

42_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_4/src/42_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/42_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_4_orig.ll -o ir/42_4.ll 2>42_4/xlopt.log;
42_4_llopt: 42_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_4.ll -o ir/42_4.ll 2>/dev/null;

42_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_5/src/42_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/42_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_5_orig.ll -o ir/42_5.ll 2>42_5/xlopt.log;
42_5_llopt: 42_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_5.ll -o ir/42_5.ll 2>/dev/null;

42_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_6/src/42_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/42_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_6_orig.ll -o ir/42_6.ll 2>42_6/xlopt.log;
42_6_llopt: 42_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_6.ll -o ir/42_6.ll 2>/dev/null;

42_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/42_7/src/42_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/42_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/42_7_orig.ll -o ir/42_7.ll 2>42_7/xlopt.log;
42_7_llopt: 42_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/42_7.ll -o ir/42_7.ll 2>/dev/null;

43_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_0/src/43_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/43_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_0_orig.ll -o ir/43_0.ll 2>43_0/xlopt.log;
43_0_llopt: 43_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_0.ll -o ir/43_0.ll 2>/dev/null;

43_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_1/src/43_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/43_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_1_orig.ll -o ir/43_1.ll 2>43_1/xlopt.log;
43_1_llopt: 43_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_1.ll -o ir/43_1.ll 2>/dev/null;

43_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_2/src/43_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/43_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_2_orig.ll -o ir/43_2.ll 2>43_2/xlopt.log;
43_2_llopt: 43_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_2.ll -o ir/43_2.ll 2>/dev/null;

43_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_3/src/43_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/43_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_3_orig.ll -o ir/43_3.ll 2>43_3/xlopt.log;
43_3_llopt: 43_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_3.ll -o ir/43_3.ll 2>/dev/null;

43_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_4/src/43_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/43_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_4_orig.ll -o ir/43_4.ll 2>43_4/xlopt.log;
43_4_llopt: 43_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_4.ll -o ir/43_4.ll 2>/dev/null;

43_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_5/src/43_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/43_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_5_orig.ll -o ir/43_5.ll 2>43_5/xlopt.log;
43_5_llopt: 43_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_5.ll -o ir/43_5.ll 2>/dev/null;

43_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_6/src/43_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/43_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_6_orig.ll -o ir/43_6.ll 2>43_6/xlopt.log;
43_6_llopt: 43_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_6.ll -o ir/43_6.ll 2>/dev/null;

43_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/43_7/src/43_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/43_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/43_7_orig.ll -o ir/43_7.ll 2>43_7/xlopt.log;
43_7_llopt: 43_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/43_7.ll -o ir/43_7.ll 2>/dev/null;

44_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_0/src/44_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/44_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_0_orig.ll -o ir/44_0.ll 2>44_0/xlopt.log;
44_0_llopt: 44_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_0.ll -o ir/44_0.ll 2>/dev/null;

44_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_1/src/44_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/44_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_1_orig.ll -o ir/44_1.ll 2>44_1/xlopt.log;
44_1_llopt: 44_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_1.ll -o ir/44_1.ll 2>/dev/null;

44_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_2/src/44_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/44_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_2_orig.ll -o ir/44_2.ll 2>44_2/xlopt.log;
44_2_llopt: 44_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_2.ll -o ir/44_2.ll 2>/dev/null;

44_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_3/src/44_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/44_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_3_orig.ll -o ir/44_3.ll 2>44_3/xlopt.log;
44_3_llopt: 44_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_3.ll -o ir/44_3.ll 2>/dev/null;

44_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_4/src/44_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/44_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_4_orig.ll -o ir/44_4.ll 2>44_4/xlopt.log;
44_4_llopt: 44_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_4.ll -o ir/44_4.ll 2>/dev/null;

44_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_5/src/44_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/44_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_5_orig.ll -o ir/44_5.ll 2>44_5/xlopt.log;
44_5_llopt: 44_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_5.ll -o ir/44_5.ll 2>/dev/null;

44_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_6/src/44_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/44_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_6_orig.ll -o ir/44_6.ll 2>44_6/xlopt.log;
44_6_llopt: 44_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_6.ll -o ir/44_6.ll 2>/dev/null;

44_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/44_7/src/44_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/44_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/44_7_orig.ll -o ir/44_7.ll 2>44_7/xlopt.log;
44_7_llopt: 44_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/44_7.ll -o ir/44_7.ll 2>/dev/null;

45_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_0/src/45_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/45_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_0_orig.ll -o ir/45_0.ll 2>45_0/xlopt.log;
45_0_llopt: 45_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_0.ll -o ir/45_0.ll 2>/dev/null;

45_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_1/src/45_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/45_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_1_orig.ll -o ir/45_1.ll 2>45_1/xlopt.log;
45_1_llopt: 45_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_1.ll -o ir/45_1.ll 2>/dev/null;

45_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_2/src/45_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/45_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_2_orig.ll -o ir/45_2.ll 2>45_2/xlopt.log;
45_2_llopt: 45_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_2.ll -o ir/45_2.ll 2>/dev/null;

45_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_3/src/45_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/45_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_3_orig.ll -o ir/45_3.ll 2>45_3/xlopt.log;
45_3_llopt: 45_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_3.ll -o ir/45_3.ll 2>/dev/null;

45_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_4/src/45_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/45_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_4_orig.ll -o ir/45_4.ll 2>45_4/xlopt.log;
45_4_llopt: 45_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_4.ll -o ir/45_4.ll 2>/dev/null;

45_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_5/src/45_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/45_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_5_orig.ll -o ir/45_5.ll 2>45_5/xlopt.log;
45_5_llopt: 45_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_5.ll -o ir/45_5.ll 2>/dev/null;

45_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_6/src/45_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/45_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_6_orig.ll -o ir/45_6.ll 2>45_6/xlopt.log;
45_6_llopt: 45_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_6.ll -o ir/45_6.ll 2>/dev/null;

45_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/45_7/src/45_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/45_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/45_7_orig.ll -o ir/45_7.ll 2>45_7/xlopt.log;
45_7_llopt: 45_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/45_7.ll -o ir/45_7.ll 2>/dev/null;

46_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_0/src/46_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/46_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_0_orig.ll -o ir/46_0.ll 2>46_0/xlopt.log;
46_0_llopt: 46_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_0.ll -o ir/46_0.ll 2>/dev/null;

46_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_1/src/46_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/46_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_1_orig.ll -o ir/46_1.ll 2>46_1/xlopt.log;
46_1_llopt: 46_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_1.ll -o ir/46_1.ll 2>/dev/null;

46_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_2/src/46_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/46_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_2_orig.ll -o ir/46_2.ll 2>46_2/xlopt.log;
46_2_llopt: 46_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_2.ll -o ir/46_2.ll 2>/dev/null;

46_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_3/src/46_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/46_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_3_orig.ll -o ir/46_3.ll 2>46_3/xlopt.log;
46_3_llopt: 46_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_3.ll -o ir/46_3.ll 2>/dev/null;

46_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_4/src/46_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/46_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_4_orig.ll -o ir/46_4.ll 2>46_4/xlopt.log;
46_4_llopt: 46_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_4.ll -o ir/46_4.ll 2>/dev/null;

46_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_5/src/46_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/46_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_5_orig.ll -o ir/46_5.ll 2>46_5/xlopt.log;
46_5_llopt: 46_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_5.ll -o ir/46_5.ll 2>/dev/null;

46_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_6/src/46_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/46_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_6_orig.ll -o ir/46_6.ll 2>46_6/xlopt.log;
46_6_llopt: 46_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_6.ll -o ir/46_6.ll 2>/dev/null;

46_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/46_7/src/46_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/46_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/46_7_orig.ll -o ir/46_7.ll 2>46_7/xlopt.log;
46_7_llopt: 46_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/46_7.ll -o ir/46_7.ll 2>/dev/null;

47_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_0/src/47_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/47_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_0_orig.ll -o ir/47_0.ll 2>47_0/xlopt.log;
47_0_llopt: 47_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_0.ll -o ir/47_0.ll 2>/dev/null;

47_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_1/src/47_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/47_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_1_orig.ll -o ir/47_1.ll 2>47_1/xlopt.log;
47_1_llopt: 47_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_1.ll -o ir/47_1.ll 2>/dev/null;

47_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_2/src/47_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/47_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_2_orig.ll -o ir/47_2.ll 2>47_2/xlopt.log;
47_2_llopt: 47_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_2.ll -o ir/47_2.ll 2>/dev/null;

47_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_3/src/47_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/47_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_3_orig.ll -o ir/47_3.ll 2>47_3/xlopt.log;
47_3_llopt: 47_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_3.ll -o ir/47_3.ll 2>/dev/null;

47_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_4/src/47_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/47_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_4_orig.ll -o ir/47_4.ll 2>47_4/xlopt.log;
47_4_llopt: 47_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_4.ll -o ir/47_4.ll 2>/dev/null;

47_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_5/src/47_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/47_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_5_orig.ll -o ir/47_5.ll 2>47_5/xlopt.log;
47_5_llopt: 47_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_5.ll -o ir/47_5.ll 2>/dev/null;

47_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_6/src/47_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/47_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_6_orig.ll -o ir/47_6.ll 2>47_6/xlopt.log;
47_6_llopt: 47_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_6.ll -o ir/47_6.ll 2>/dev/null;

47_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/47_7/src/47_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/47_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/47_7_orig.ll -o ir/47_7.ll 2>47_7/xlopt.log;
47_7_llopt: 47_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/47_7.ll -o ir/47_7.ll 2>/dev/null;

48_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_0/src/48_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/48_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_0_orig.ll -o ir/48_0.ll 2>48_0/xlopt.log;
48_0_llopt: 48_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_0.ll -o ir/48_0.ll 2>/dev/null;

48_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_1/src/48_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/48_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_1_orig.ll -o ir/48_1.ll 2>48_1/xlopt.log;
48_1_llopt: 48_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_1.ll -o ir/48_1.ll 2>/dev/null;

48_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_2/src/48_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/48_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_2_orig.ll -o ir/48_2.ll 2>48_2/xlopt.log;
48_2_llopt: 48_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_2.ll -o ir/48_2.ll 2>/dev/null;

48_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_3/src/48_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/48_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_3_orig.ll -o ir/48_3.ll 2>48_3/xlopt.log;
48_3_llopt: 48_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_3.ll -o ir/48_3.ll 2>/dev/null;

48_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_4/src/48_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/48_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_4_orig.ll -o ir/48_4.ll 2>48_4/xlopt.log;
48_4_llopt: 48_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_4.ll -o ir/48_4.ll 2>/dev/null;

48_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_5/src/48_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/48_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_5_orig.ll -o ir/48_5.ll 2>48_5/xlopt.log;
48_5_llopt: 48_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_5.ll -o ir/48_5.ll 2>/dev/null;

48_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_6/src/48_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/48_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_6_orig.ll -o ir/48_6.ll 2>48_6/xlopt.log;
48_6_llopt: 48_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_6.ll -o ir/48_6.ll 2>/dev/null;

48_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/48_7/src/48_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/48_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/48_7_orig.ll -o ir/48_7.ll 2>48_7/xlopt.log;
48_7_llopt: 48_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/48_7.ll -o ir/48_7.ll 2>/dev/null;

49_0_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_0/src/49_0.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/49_0_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_0_orig.ll -o ir/49_0.ll 2>49_0/xlopt.log;
49_0_llopt: 49_0_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_0.ll -o ir/49_0.ll 2>/dev/null;

49_1_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_1/src/49_1.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/49_1_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_1_orig.ll -o ir/49_1.ll 2>49_1/xlopt.log;
49_1_llopt: 49_1_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_1.ll -o ir/49_1.ll 2>/dev/null;

49_2_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_2/src/49_2.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/49_2_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_2_orig.ll -o ir/49_2.ll 2>49_2/xlopt.log;
49_2_llopt: 49_2_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_2.ll -o ir/49_2.ll 2>/dev/null;

49_3_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_3/src/49_3.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/49_3_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_3_orig.ll -o ir/49_3.ll 2>49_3/xlopt.log;
49_3_llopt: 49_3_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_3.ll -o ir/49_3.ll 2>/dev/null;

49_4_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_4/src/49_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/49_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_4_orig.ll -o ir/49_4.ll 2>49_4/xlopt.log;
49_4_llopt: 49_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_4.ll -o ir/49_4.ll 2>/dev/null;

49_5_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_5/src/49_5.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/49_5_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_5_orig.ll -o ir/49_5.ll 2>49_5/xlopt.log;
49_5_llopt: 49_5_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_5.ll -o ir/49_5.ll 2>/dev/null;

49_6_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_6/src/49_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/49_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_6_orig.ll -o ir/49_6.ll 2>49_6/xlopt.log;
49_6_llopt: 49_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_6.ll -o ir/49_6.ll 2>/dev/null;

49_7_xlopt:
	${XCHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/49_7/src/49_7.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/49_7_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/49_7_orig.ll -o ir/49_7.ll 2>49_7/xlopt.log;
49_7_llopt: 49_7_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/49_7.ll -o ir/49_7.ll 2>/dev/null;

2_0: 2_0_xlopt 2_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_0/scripts/2_0.prx) 2>&1 | tee 2_0/2_0.log
	(coreverify -obj 2_0 -s 4096 -pm 16384)
2_1: 2_1_xlopt 2_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_1/scripts/2_1.prx) 2>&1 | tee 2_1/2_1.log
	(coreverify -obj 2_1 -s 4096 -pm 16384)
2_2: 2_2_xlopt 2_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_2/scripts/2_2.prx) 2>&1 | tee 2_2/2_2.log
	(coreverify -obj 2_2 -s 4096 -pm 16384)
2_3: 2_3_xlopt 2_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_3/scripts/2_3.prx) 2>&1 | tee 2_3/2_3.log
	(coreverify -obj 2_3 -s 4096 -pm 16384)
2_4: 2_4_xlopt 2_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_4/scripts/2_4.prx) 2>&1 | tee 2_4/2_4.log
	(coreverify -obj 2_4 -s 4096 -pm 16384)
2_5: 2_5_xlopt 2_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_5/scripts/2_5.prx) 2>&1 | tee 2_5/2_5.log
	(coreverify -obj 2_5 -s 4096 -pm 16384)
2_6: 2_6_xlopt 2_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_6/scripts/2_6.prx) 2>&1 | tee 2_6/2_6.log
	(coreverify -obj 2_6 -s 4096 -pm 16384)
2_7: 2_7_xlopt 2_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 2_7/scripts/2_7.prx) 2>&1 | tee 2_7/2_7.log
	(coreverify -obj 2_7 -s 4096 -pm 16384)
3_0: 3_0_xlopt 3_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_0/scripts/3_0.prx) 2>&1 | tee 3_0/3_0.log
	(coreverify -obj 3_0 -s 4096 -pm 16384)
3_1: 3_1_xlopt 3_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_1/scripts/3_1.prx) 2>&1 | tee 3_1/3_1.log
	(coreverify -obj 3_1 -s 4096 -pm 16384)
3_2: 3_2_xlopt 3_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_2/scripts/3_2.prx) 2>&1 | tee 3_2/3_2.log
	(coreverify -obj 3_2 -s 4096 -pm 16384)
3_3: 3_3_xlopt 3_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_3/scripts/3_3.prx) 2>&1 | tee 3_3/3_3.log
	(coreverify -obj 3_3 -s 4096 -pm 16384)
3_4: 3_4_xlopt 3_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_4/scripts/3_4.prx) 2>&1 | tee 3_4/3_4.log
	(coreverify -obj 3_4 -s 4096 -pm 16384)
3_5: 3_5_xlopt 3_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_5/scripts/3_5.prx) 2>&1 | tee 3_5/3_5.log
	(coreverify -obj 3_5 -s 4096 -pm 16384)
3_6: 3_6_xlopt 3_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_6/scripts/3_6.prx) 2>&1 | tee 3_6/3_6.log
	(coreverify -obj 3_6 -s 4096 -pm 16384)
3_7: 3_7_xlopt 3_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_7/scripts/3_7.prx) 2>&1 | tee 3_7/3_7.log
	(coreverify -obj 3_7 -s 4096 -pm 16384)
4_0: 4_0_xlopt 4_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_0/scripts/4_0.prx) 2>&1 | tee 4_0/4_0.log
	(coreverify -obj 4_0 -s 4096 -pm 16384)
4_1: 4_1_xlopt 4_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_1/scripts/4_1.prx) 2>&1 | tee 4_1/4_1.log
	(coreverify -obj 4_1 -s 4096 -pm 16384)
4_2: 4_2_xlopt 4_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_2/scripts/4_2.prx) 2>&1 | tee 4_2/4_2.log
	(coreverify -obj 4_2 -s 4096 -pm 16384)
4_3: 4_3_xlopt 4_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_3/scripts/4_3.prx) 2>&1 | tee 4_3/4_3.log
	(coreverify -obj 4_3 -s 4096 -pm 16384)
4_4: 4_4_xlopt 4_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_4/scripts/4_4.prx) 2>&1 | tee 4_4/4_4.log
	(coreverify -obj 4_4 -s 4096 -pm 16384)
4_5: 4_5_xlopt 4_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_5/scripts/4_5.prx) 2>&1 | tee 4_5/4_5.log
	(coreverify -obj 4_5 -s 4096 -pm 16384)
4_6: 4_6_xlopt 4_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_6/scripts/4_6.prx) 2>&1 | tee 4_6/4_6.log
	(coreverify -obj 4_6 -s 4096 -pm 16384)
4_7: 4_7_xlopt 4_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 4_7/scripts/4_7.prx) 2>&1 | tee 4_7/4_7.log
	(coreverify -obj 4_7 -s 4096 -pm 16384)
5_0: 5_0_xlopt 5_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_0/scripts/5_0.prx) 2>&1 | tee 5_0/5_0.log
	(coreverify -obj 5_0 -s 4096 -pm 16384)
5_1: 5_1_xlopt 5_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_1/scripts/5_1.prx) 2>&1 | tee 5_1/5_1.log
	(coreverify -obj 5_1 -s 4096 -pm 16384)
5_2: 5_2_xlopt 5_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_2/scripts/5_2.prx) 2>&1 | tee 5_2/5_2.log
	(coreverify -obj 5_2 -s 4096 -pm 16384)
5_3: 5_3_xlopt 5_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_3/scripts/5_3.prx) 2>&1 | tee 5_3/5_3.log
	(coreverify -obj 5_3 -s 4096 -pm 16384)
5_4: 5_4_xlopt 5_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_4/scripts/5_4.prx) 2>&1 | tee 5_4/5_4.log
	(coreverify -obj 5_4 -s 4096 -pm 16384)
5_5: 5_5_xlopt 5_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_5/scripts/5_5.prx) 2>&1 | tee 5_5/5_5.log
	(coreverify -obj 5_5 -s 4096 -pm 16384)
5_6: 5_6_xlopt 5_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_6/scripts/5_6.prx) 2>&1 | tee 5_6/5_6.log
	(coreverify -obj 5_6 -s 4096 -pm 16384)
5_7: 5_7_xlopt 5_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 5_7/scripts/5_7.prx) 2>&1 | tee 5_7/5_7.log
	(coreverify -obj 5_7 -s 4096 -pm 16384)
6_0: 6_0_xlopt 6_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_0/scripts/6_0.prx) 2>&1 | tee 6_0/6_0.log
	(coreverify -obj 6_0 -s 4096 -pm 16384)
6_1: 6_1_xlopt 6_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_1/scripts/6_1.prx) 2>&1 | tee 6_1/6_1.log
	(coreverify -obj 6_1 -s 4096 -pm 16384)
6_2: 6_2_xlopt 6_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_2/scripts/6_2.prx) 2>&1 | tee 6_2/6_2.log
	(coreverify -obj 6_2 -s 4096 -pm 16384)
6_3: 6_3_xlopt 6_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_3/scripts/6_3.prx) 2>&1 | tee 6_3/6_3.log
	(coreverify -obj 6_3 -s 4096 -pm 16384)
6_4: 6_4_xlopt 6_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_4/scripts/6_4.prx) 2>&1 | tee 6_4/6_4.log
	(coreverify -obj 6_4 -s 4096 -pm 16384)
6_5: 6_5_xlopt 6_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_5/scripts/6_5.prx) 2>&1 | tee 6_5/6_5.log
	(coreverify -obj 6_5 -s 4096 -pm 16384)
6_6: 6_6_xlopt 6_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_6/scripts/6_6.prx) 2>&1 | tee 6_6/6_6.log
	(coreverify -obj 6_6 -s 4096 -pm 16384)
6_7: 6_7_xlopt 6_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_7/scripts/6_7.prx) 2>&1 | tee 6_7/6_7.log
	(coreverify -obj 6_7 -s 4096 -pm 16384)
7_0: 7_0_xlopt 7_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_0/scripts/7_0.prx) 2>&1 | tee 7_0/7_0.log
	(coreverify -obj 7_0 -s 4096 -pm 16384)
7_1: 7_1_xlopt 7_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_1/scripts/7_1.prx) 2>&1 | tee 7_1/7_1.log
	(coreverify -obj 7_1 -s 4096 -pm 16384)
7_2: 7_2_xlopt 7_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_2/scripts/7_2.prx) 2>&1 | tee 7_2/7_2.log
	(coreverify -obj 7_2 -s 4096 -pm 16384)
7_3: 7_3_xlopt 7_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_3/scripts/7_3.prx) 2>&1 | tee 7_3/7_3.log
	(coreverify -obj 7_3 -s 4096 -pm 16384)
7_4: 7_4_xlopt 7_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_4/scripts/7_4.prx) 2>&1 | tee 7_4/7_4.log
	(coreverify -obj 7_4 -s 4096 -pm 16384)
7_5: 7_5_xlopt 7_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_5/scripts/7_5.prx) 2>&1 | tee 7_5/7_5.log
	(coreverify -obj 7_5 -s 4096 -pm 16384)
7_6: 7_6_xlopt 7_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_6/scripts/7_6.prx) 2>&1 | tee 7_6/7_6.log
	(coreverify -obj 7_6 -s 4096 -pm 16384)
7_7: 7_7_xlopt 7_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 7_7/scripts/7_7.prx) 2>&1 | tee 7_7/7_7.log
	(coreverify -obj 7_7 -s 4096 -pm 16384)
8_0: 8_0_xlopt 8_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_0/scripts/8_0.prx) 2>&1 | tee 8_0/8_0.log
	(coreverify -obj 8_0 -s 4096 -pm 16384)
8_1: 8_1_xlopt 8_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_1/scripts/8_1.prx) 2>&1 | tee 8_1/8_1.log
	(coreverify -obj 8_1 -s 4096 -pm 16384)
8_2: 8_2_xlopt 8_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_2/scripts/8_2.prx) 2>&1 | tee 8_2/8_2.log
	(coreverify -obj 8_2 -s 4096 -pm 16384)
8_3: 8_3_xlopt 8_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_3/scripts/8_3.prx) 2>&1 | tee 8_3/8_3.log
	(coreverify -obj 8_3 -s 4096 -pm 16384)
8_4: 8_4_xlopt 8_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_4/scripts/8_4.prx) 2>&1 | tee 8_4/8_4.log
	(coreverify -obj 8_4 -s 4096 -pm 16384)
8_5: 8_5_xlopt 8_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_5/scripts/8_5.prx) 2>&1 | tee 8_5/8_5.log
	(coreverify -obj 8_5 -s 4096 -pm 16384)
8_6: 8_6_xlopt 8_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_6/scripts/8_6.prx) 2>&1 | tee 8_6/8_6.log
	(coreverify -obj 8_6 -s 4096 -pm 16384)
8_7: 8_7_xlopt 8_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 8_7/scripts/8_7.prx) 2>&1 | tee 8_7/8_7.log
	(coreverify -obj 8_7 -s 4096 -pm 16384)
9_0: 9_0_xlopt 9_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_0/scripts/9_0.prx) 2>&1 | tee 9_0/9_0.log
	(coreverify -obj 9_0 -s 4096 -pm 16384)
9_1: 9_1_xlopt 9_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_1/scripts/9_1.prx) 2>&1 | tee 9_1/9_1.log
	(coreverify -obj 9_1 -s 4096 -pm 16384)
9_2: 9_2_xlopt 9_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_2/scripts/9_2.prx) 2>&1 | tee 9_2/9_2.log
	(coreverify -obj 9_2 -s 4096 -pm 16384)
9_3: 9_3_xlopt 9_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_3/scripts/9_3.prx) 2>&1 | tee 9_3/9_3.log
	(coreverify -obj 9_3 -s 4096 -pm 16384)
9_4: 9_4_xlopt 9_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_4/scripts/9_4.prx) 2>&1 | tee 9_4/9_4.log
	(coreverify -obj 9_4 -s 4096 -pm 16384)
9_5: 9_5_xlopt 9_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_5/scripts/9_5.prx) 2>&1 | tee 9_5/9_5.log
	(coreverify -obj 9_5 -s 4096 -pm 16384)
9_6: 9_6_xlopt 9_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_6/scripts/9_6.prx) 2>&1 | tee 9_6/9_6.log
	(coreverify -obj 9_6 -s 4096 -pm 16384)
9_7: 9_7_xlopt 9_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 9_7/scripts/9_7.prx) 2>&1 | tee 9_7/9_7.log
	(coreverify -obj 9_7 -s 4096 -pm 16384)
10_0: 10_0_xlopt 10_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_0/scripts/10_0.prx) 2>&1 | tee 10_0/10_0.log
	(coreverify -obj 10_0 -s 4096 -pm 16384)
10_1: 10_1_xlopt 10_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_1/scripts/10_1.prx) 2>&1 | tee 10_1/10_1.log
	(coreverify -obj 10_1 -s 4096 -pm 16384)
10_2: 10_2_xlopt 10_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_2/scripts/10_2.prx) 2>&1 | tee 10_2/10_2.log
	(coreverify -obj 10_2 -s 4096 -pm 16384)
10_3: 10_3_xlopt 10_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_3/scripts/10_3.prx) 2>&1 | tee 10_3/10_3.log
	(coreverify -obj 10_3 -s 4096 -pm 16384)
10_4: 10_4_xlopt 10_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_4/scripts/10_4.prx) 2>&1 | tee 10_4/10_4.log
	(coreverify -obj 10_4 -s 4096 -pm 16384)
10_5: 10_5_xlopt 10_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_5/scripts/10_5.prx) 2>&1 | tee 10_5/10_5.log
	(coreverify -obj 10_5 -s 4096 -pm 16384)
10_6: 10_6_xlopt 10_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_6/scripts/10_6.prx) 2>&1 | tee 10_6/10_6.log
	(coreverify -obj 10_6 -s 4096 -pm 16384)
10_7: 10_7_xlopt 10_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 10_7/scripts/10_7.prx) 2>&1 | tee 10_7/10_7.log
	(coreverify -obj 10_7 -s 4096 -pm 16384)
11_0: 11_0_xlopt 11_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_0/scripts/11_0.prx) 2>&1 | tee 11_0/11_0.log
	(coreverify -obj 11_0 -s 4096 -pm 16384)
11_1: 11_1_xlopt 11_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_1/scripts/11_1.prx) 2>&1 | tee 11_1/11_1.log
	(coreverify -obj 11_1 -s 4096 -pm 16384)
11_2: 11_2_xlopt 11_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_2/scripts/11_2.prx) 2>&1 | tee 11_2/11_2.log
	(coreverify -obj 11_2 -s 4096 -pm 16384)
11_3: 11_3_xlopt 11_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_3/scripts/11_3.prx) 2>&1 | tee 11_3/11_3.log
	(coreverify -obj 11_3 -s 4096 -pm 16384)
11_4: 11_4_xlopt 11_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_4/scripts/11_4.prx) 2>&1 | tee 11_4/11_4.log
	(coreverify -obj 11_4 -s 4096 -pm 16384)
11_5: 11_5_xlopt 11_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_5/scripts/11_5.prx) 2>&1 | tee 11_5/11_5.log
	(coreverify -obj 11_5 -s 4096 -pm 16384)
11_6: 11_6_xlopt 11_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_6/scripts/11_6.prx) 2>&1 | tee 11_6/11_6.log
	(coreverify -obj 11_6 -s 4096 -pm 16384)
11_7: 11_7_xlopt 11_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 11_7/scripts/11_7.prx) 2>&1 | tee 11_7/11_7.log
	(coreverify -obj 11_7 -s 4096 -pm 16384)
12_0: 12_0_xlopt 12_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_0/scripts/12_0.prx) 2>&1 | tee 12_0/12_0.log
	(coreverify -obj 12_0 -s 4096 -pm 16384)
12_1: 12_1_xlopt 12_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_1/scripts/12_1.prx) 2>&1 | tee 12_1/12_1.log
	(coreverify -obj 12_1 -s 4096 -pm 16384)
12_2: 12_2_xlopt 12_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_2/scripts/12_2.prx) 2>&1 | tee 12_2/12_2.log
	(coreverify -obj 12_2 -s 4096 -pm 16384)
12_3: 12_3_xlopt 12_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_3/scripts/12_3.prx) 2>&1 | tee 12_3/12_3.log
	(coreverify -obj 12_3 -s 4096 -pm 16384)
12_4: 12_4_xlopt 12_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_4/scripts/12_4.prx) 2>&1 | tee 12_4/12_4.log
	(coreverify -obj 12_4 -s 4096 -pm 16384)
12_5: 12_5_xlopt 12_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_5/scripts/12_5.prx) 2>&1 | tee 12_5/12_5.log
	(coreverify -obj 12_5 -s 4096 -pm 16384)
12_6: 12_6_xlopt 12_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_6/scripts/12_6.prx) 2>&1 | tee 12_6/12_6.log
	(coreverify -obj 12_6 -s 4096 -pm 16384)
12_7: 12_7_xlopt 12_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 12_7/scripts/12_7.prx) 2>&1 | tee 12_7/12_7.log
	(coreverify -obj 12_7 -s 4096 -pm 16384)
13_0: 13_0_xlopt 13_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_0/scripts/13_0.prx) 2>&1 | tee 13_0/13_0.log
	(coreverify -obj 13_0 -s 4096 -pm 16384)
13_1: 13_1_xlopt 13_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_1/scripts/13_1.prx) 2>&1 | tee 13_1/13_1.log
	(coreverify -obj 13_1 -s 4096 -pm 16384)
13_2: 13_2_xlopt 13_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_2/scripts/13_2.prx) 2>&1 | tee 13_2/13_2.log
	(coreverify -obj 13_2 -s 4096 -pm 16384)
13_3: 13_3_xlopt 13_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_3/scripts/13_3.prx) 2>&1 | tee 13_3/13_3.log
	(coreverify -obj 13_3 -s 4096 -pm 16384)
13_4: 13_4_xlopt 13_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_4/scripts/13_4.prx) 2>&1 | tee 13_4/13_4.log
	(coreverify -obj 13_4 -s 4096 -pm 16384)
13_5: 13_5_xlopt 13_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_5/scripts/13_5.prx) 2>&1 | tee 13_5/13_5.log
	(coreverify -obj 13_5 -s 4096 -pm 16384)
13_6: 13_6_xlopt 13_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_6/scripts/13_6.prx) 2>&1 | tee 13_6/13_6.log
	(coreverify -obj 13_6 -s 4096 -pm 16384)
13_7: 13_7_xlopt 13_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 13_7/scripts/13_7.prx) 2>&1 | tee 13_7/13_7.log
	(coreverify -obj 13_7 -s 4096 -pm 16384)
14_0: 14_0_xlopt 14_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_0/scripts/14_0.prx) 2>&1 | tee 14_0/14_0.log
	(coreverify -obj 14_0 -s 4096 -pm 16384)
14_1: 14_1_xlopt 14_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_1/scripts/14_1.prx) 2>&1 | tee 14_1/14_1.log
	(coreverify -obj 14_1 -s 4096 -pm 16384)
14_2: 14_2_xlopt 14_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_2/scripts/14_2.prx) 2>&1 | tee 14_2/14_2.log
	(coreverify -obj 14_2 -s 4096 -pm 16384)
14_3: 14_3_xlopt 14_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_3/scripts/14_3.prx) 2>&1 | tee 14_3/14_3.log
	(coreverify -obj 14_3 -s 4096 -pm 16384)
14_4: 14_4_xlopt 14_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_4/scripts/14_4.prx) 2>&1 | tee 14_4/14_4.log
	(coreverify -obj 14_4 -s 4096 -pm 16384)
14_5: 14_5_xlopt 14_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_5/scripts/14_5.prx) 2>&1 | tee 14_5/14_5.log
	(coreverify -obj 14_5 -s 4096 -pm 16384)
14_6: 14_6_xlopt 14_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_6/scripts/14_6.prx) 2>&1 | tee 14_6/14_6.log
	(coreverify -obj 14_6 -s 4096 -pm 16384)
14_7: 14_7_xlopt 14_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 14_7/scripts/14_7.prx) 2>&1 | tee 14_7/14_7.log
	(coreverify -obj 14_7 -s 4096 -pm 16384)
15_0: 15_0_xlopt 15_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_0/scripts/15_0.prx) 2>&1 | tee 15_0/15_0.log
	(coreverify -obj 15_0 -s 4096 -pm 16384)
15_1: 15_1_xlopt 15_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_1/scripts/15_1.prx) 2>&1 | tee 15_1/15_1.log
	(coreverify -obj 15_1 -s 4096 -pm 16384)
15_2: 15_2_xlopt 15_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_2/scripts/15_2.prx) 2>&1 | tee 15_2/15_2.log
	(coreverify -obj 15_2 -s 4096 -pm 16384)
15_3: 15_3_xlopt 15_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_3/scripts/15_3.prx) 2>&1 | tee 15_3/15_3.log
	(coreverify -obj 15_3 -s 4096 -pm 16384)
15_4: 15_4_xlopt 15_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_4/scripts/15_4.prx) 2>&1 | tee 15_4/15_4.log
	(coreverify -obj 15_4 -s 4096 -pm 16384)
15_5: 15_5_xlopt 15_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_5/scripts/15_5.prx) 2>&1 | tee 15_5/15_5.log
	(coreverify -obj 15_5 -s 4096 -pm 16384)
15_6: 15_6_xlopt 15_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_6/scripts/15_6.prx) 2>&1 | tee 15_6/15_6.log
	(coreverify -obj 15_6 -s 4096 -pm 16384)
15_7: 15_7_xlopt 15_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 15_7/scripts/15_7.prx) 2>&1 | tee 15_7/15_7.log
	(coreverify -obj 15_7 -s 4096 -pm 16384)
16_0: 16_0_xlopt 16_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_0/scripts/16_0.prx) 2>&1 | tee 16_0/16_0.log
	(coreverify -obj 16_0 -s 4096 -pm 16384)
16_1: 16_1_xlopt 16_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_1/scripts/16_1.prx) 2>&1 | tee 16_1/16_1.log
	(coreverify -obj 16_1 -s 4096 -pm 16384)
16_2: 16_2_xlopt 16_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_2/scripts/16_2.prx) 2>&1 | tee 16_2/16_2.log
	(coreverify -obj 16_2 -s 4096 -pm 16384)
16_3: 16_3_xlopt 16_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_3/scripts/16_3.prx) 2>&1 | tee 16_3/16_3.log
	(coreverify -obj 16_3 -s 4096 -pm 16384)
16_4: 16_4_xlopt 16_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_4/scripts/16_4.prx) 2>&1 | tee 16_4/16_4.log
	(coreverify -obj 16_4 -s 4096 -pm 16384)
16_5: 16_5_xlopt 16_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_5/scripts/16_5.prx) 2>&1 | tee 16_5/16_5.log
	(coreverify -obj 16_5 -s 4096 -pm 16384)
16_6: 16_6_xlopt 16_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_6/scripts/16_6.prx) 2>&1 | tee 16_6/16_6.log
	(coreverify -obj 16_6 -s 4096 -pm 16384)
16_7: 16_7_xlopt 16_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 16_7/scripts/16_7.prx) 2>&1 | tee 16_7/16_7.log
	(coreverify -obj 16_7 -s 4096 -pm 16384)
17_0: 17_0_xlopt 17_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_0/scripts/17_0.prx) 2>&1 | tee 17_0/17_0.log
	(coreverify -obj 17_0 -s 4096 -pm 16384)
17_1: 17_1_xlopt 17_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_1/scripts/17_1.prx) 2>&1 | tee 17_1/17_1.log
	(coreverify -obj 17_1 -s 4096 -pm 16384)
17_2: 17_2_xlopt 17_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_2/scripts/17_2.prx) 2>&1 | tee 17_2/17_2.log
	(coreverify -obj 17_2 -s 4096 -pm 16384)
17_3: 17_3_xlopt 17_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_3/scripts/17_3.prx) 2>&1 | tee 17_3/17_3.log
	(coreverify -obj 17_3 -s 4096 -pm 16384)
17_4: 17_4_xlopt 17_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_4/scripts/17_4.prx) 2>&1 | tee 17_4/17_4.log
	(coreverify -obj 17_4 -s 4096 -pm 16384)
17_5: 17_5_xlopt 17_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_5/scripts/17_5.prx) 2>&1 | tee 17_5/17_5.log
	(coreverify -obj 17_5 -s 4096 -pm 16384)
17_6: 17_6_xlopt 17_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_6/scripts/17_6.prx) 2>&1 | tee 17_6/17_6.log
	(coreverify -obj 17_6 -s 4096 -pm 16384)
17_7: 17_7_xlopt 17_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 17_7/scripts/17_7.prx) 2>&1 | tee 17_7/17_7.log
	(coreverify -obj 17_7 -s 4096 -pm 16384)
18_0: 18_0_xlopt 18_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_0/scripts/18_0.prx) 2>&1 | tee 18_0/18_0.log
	(coreverify -obj 18_0 -s 4096 -pm 16384)
18_1: 18_1_xlopt 18_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_1/scripts/18_1.prx) 2>&1 | tee 18_1/18_1.log
	(coreverify -obj 18_1 -s 4096 -pm 16384)
18_2: 18_2_xlopt 18_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_2/scripts/18_2.prx) 2>&1 | tee 18_2/18_2.log
	(coreverify -obj 18_2 -s 4096 -pm 16384)
18_3: 18_3_xlopt 18_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_3/scripts/18_3.prx) 2>&1 | tee 18_3/18_3.log
	(coreverify -obj 18_3 -s 4096 -pm 16384)
18_4: 18_4_xlopt 18_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_4/scripts/18_4.prx) 2>&1 | tee 18_4/18_4.log
	(coreverify -obj 18_4 -s 4096 -pm 16384)
18_5: 18_5_xlopt 18_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_5/scripts/18_5.prx) 2>&1 | tee 18_5/18_5.log
	(coreverify -obj 18_5 -s 4096 -pm 16384)
18_6: 18_6_xlopt 18_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_6/scripts/18_6.prx) 2>&1 | tee 18_6/18_6.log
	(coreverify -obj 18_6 -s 4096 -pm 16384)
18_7: 18_7_xlopt 18_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 18_7/scripts/18_7.prx) 2>&1 | tee 18_7/18_7.log
	(coreverify -obj 18_7 -s 4096 -pm 16384)
19_0: 19_0_xlopt 19_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_0/scripts/19_0.prx) 2>&1 | tee 19_0/19_0.log
	(coreverify -obj 19_0 -s 4096 -pm 16384)
19_1: 19_1_xlopt 19_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_1/scripts/19_1.prx) 2>&1 | tee 19_1/19_1.log
	(coreverify -obj 19_1 -s 4096 -pm 16384)
19_2: 19_2_xlopt 19_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_2/scripts/19_2.prx) 2>&1 | tee 19_2/19_2.log
	(coreverify -obj 19_2 -s 4096 -pm 16384)
19_3: 19_3_xlopt 19_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_3/scripts/19_3.prx) 2>&1 | tee 19_3/19_3.log
	(coreverify -obj 19_3 -s 4096 -pm 16384)
19_4: 19_4_xlopt 19_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_4/scripts/19_4.prx) 2>&1 | tee 19_4/19_4.log
	(coreverify -obj 19_4 -s 4096 -pm 16384)
19_5: 19_5_xlopt 19_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_5/scripts/19_5.prx) 2>&1 | tee 19_5/19_5.log
	(coreverify -obj 19_5 -s 4096 -pm 16384)
19_6: 19_6_xlopt 19_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_6/scripts/19_6.prx) 2>&1 | tee 19_6/19_6.log
	(coreverify -obj 19_6 -s 4096 -pm 16384)
19_7: 19_7_xlopt 19_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 19_7/scripts/19_7.prx) 2>&1 | tee 19_7/19_7.log
	(coreverify -obj 19_7 -s 4096 -pm 16384)
20_0: 20_0_xlopt 20_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_0/scripts/20_0.prx) 2>&1 | tee 20_0/20_0.log
	(coreverify -obj 20_0 -s 4096 -pm 16384)
20_1: 20_1_xlopt 20_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_1/scripts/20_1.prx) 2>&1 | tee 20_1/20_1.log
	(coreverify -obj 20_1 -s 4096 -pm 16384)
20_2: 20_2_xlopt 20_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_2/scripts/20_2.prx) 2>&1 | tee 20_2/20_2.log
	(coreverify -obj 20_2 -s 4096 -pm 16384)
20_3: 20_3_xlopt 20_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_3/scripts/20_3.prx) 2>&1 | tee 20_3/20_3.log
	(coreverify -obj 20_3 -s 4096 -pm 16384)
20_4: 20_4_xlopt 20_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_4/scripts/20_4.prx) 2>&1 | tee 20_4/20_4.log
	(coreverify -obj 20_4 -s 4096 -pm 16384)
20_5: 20_5_xlopt 20_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_5/scripts/20_5.prx) 2>&1 | tee 20_5/20_5.log
	(coreverify -obj 20_5 -s 4096 -pm 16384)
20_6: 20_6_xlopt 20_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_6/scripts/20_6.prx) 2>&1 | tee 20_6/20_6.log
	(coreverify -obj 20_6 -s 4096 -pm 16384)
20_7: 20_7_xlopt 20_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 20_7/scripts/20_7.prx) 2>&1 | tee 20_7/20_7.log
	(coreverify -obj 20_7 -s 4096 -pm 16384)
21_0: 21_0_xlopt 21_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_0/scripts/21_0.prx) 2>&1 | tee 21_0/21_0.log
	(coreverify -obj 21_0 -s 4096 -pm 16384)
21_1: 21_1_xlopt 21_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_1/scripts/21_1.prx) 2>&1 | tee 21_1/21_1.log
	(coreverify -obj 21_1 -s 4096 -pm 16384)
21_2: 21_2_xlopt 21_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_2/scripts/21_2.prx) 2>&1 | tee 21_2/21_2.log
	(coreverify -obj 21_2 -s 4096 -pm 16384)
21_3: 21_3_xlopt 21_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_3/scripts/21_3.prx) 2>&1 | tee 21_3/21_3.log
	(coreverify -obj 21_3 -s 4096 -pm 16384)
21_4: 21_4_xlopt 21_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_4/scripts/21_4.prx) 2>&1 | tee 21_4/21_4.log
	(coreverify -obj 21_4 -s 4096 -pm 16384)
21_5: 21_5_xlopt 21_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_5/scripts/21_5.prx) 2>&1 | tee 21_5/21_5.log
	(coreverify -obj 21_5 -s 4096 -pm 16384)
21_6: 21_6_xlopt 21_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_6/scripts/21_6.prx) 2>&1 | tee 21_6/21_6.log
	(coreverify -obj 21_6 -s 4096 -pm 16384)
21_7: 21_7_xlopt 21_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 21_7/scripts/21_7.prx) 2>&1 | tee 21_7/21_7.log
	(coreverify -obj 21_7 -s 4096 -pm 16384)
22_0: 22_0_xlopt 22_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_0/scripts/22_0.prx) 2>&1 | tee 22_0/22_0.log
	(coreverify -obj 22_0 -s 4096 -pm 16384)
22_1: 22_1_xlopt 22_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_1/scripts/22_1.prx) 2>&1 | tee 22_1/22_1.log
	(coreverify -obj 22_1 -s 4096 -pm 16384)
22_2: 22_2_xlopt 22_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_2/scripts/22_2.prx) 2>&1 | tee 22_2/22_2.log
	(coreverify -obj 22_2 -s 4096 -pm 16384)
22_3: 22_3_xlopt 22_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_3/scripts/22_3.prx) 2>&1 | tee 22_3/22_3.log
	(coreverify -obj 22_3 -s 4096 -pm 16384)
22_4: 22_4_xlopt 22_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_4/scripts/22_4.prx) 2>&1 | tee 22_4/22_4.log
	(coreverify -obj 22_4 -s 4096 -pm 16384)
22_5: 22_5_xlopt 22_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_5/scripts/22_5.prx) 2>&1 | tee 22_5/22_5.log
	(coreverify -obj 22_5 -s 4096 -pm 16384)
22_6: 22_6_xlopt 22_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_6/scripts/22_6.prx) 2>&1 | tee 22_6/22_6.log
	(coreverify -obj 22_6 -s 4096 -pm 16384)
22_7: 22_7_xlopt 22_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 22_7/scripts/22_7.prx) 2>&1 | tee 22_7/22_7.log
	(coreverify -obj 22_7 -s 4096 -pm 16384)
23_0: 23_0_xlopt 23_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_0/scripts/23_0.prx) 2>&1 | tee 23_0/23_0.log
	(coreverify -obj 23_0 -s 4096 -pm 16384)
23_1: 23_1_xlopt 23_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_1/scripts/23_1.prx) 2>&1 | tee 23_1/23_1.log
	(coreverify -obj 23_1 -s 4096 -pm 16384)
23_2: 23_2_xlopt 23_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_2/scripts/23_2.prx) 2>&1 | tee 23_2/23_2.log
	(coreverify -obj 23_2 -s 4096 -pm 16384)
23_3: 23_3_xlopt 23_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_3/scripts/23_3.prx) 2>&1 | tee 23_3/23_3.log
	(coreverify -obj 23_3 -s 4096 -pm 16384)
23_4: 23_4_xlopt 23_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_4/scripts/23_4.prx) 2>&1 | tee 23_4/23_4.log
	(coreverify -obj 23_4 -s 4096 -pm 16384)
23_5: 23_5_xlopt 23_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_5/scripts/23_5.prx) 2>&1 | tee 23_5/23_5.log
	(coreverify -obj 23_5 -s 4096 -pm 16384)
23_6: 23_6_xlopt 23_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_6/scripts/23_6.prx) 2>&1 | tee 23_6/23_6.log
	(coreverify -obj 23_6 -s 4096 -pm 16384)
23_7: 23_7_xlopt 23_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 23_7/scripts/23_7.prx) 2>&1 | tee 23_7/23_7.log
	(coreverify -obj 23_7 -s 4096 -pm 16384)
24_0: 24_0_xlopt 24_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_0/scripts/24_0.prx) 2>&1 | tee 24_0/24_0.log
	(coreverify -obj 24_0 -s 4096 -pm 16384)
24_1: 24_1_xlopt 24_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_1/scripts/24_1.prx) 2>&1 | tee 24_1/24_1.log
	(coreverify -obj 24_1 -s 4096 -pm 16384)
24_2: 24_2_xlopt 24_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_2/scripts/24_2.prx) 2>&1 | tee 24_2/24_2.log
	(coreverify -obj 24_2 -s 4096 -pm 16384)
24_3: 24_3_xlopt 24_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_3/scripts/24_3.prx) 2>&1 | tee 24_3/24_3.log
	(coreverify -obj 24_3 -s 4096 -pm 16384)
24_4: 24_4_xlopt 24_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_4/scripts/24_4.prx) 2>&1 | tee 24_4/24_4.log
	(coreverify -obj 24_4 -s 4096 -pm 16384)
24_5: 24_5_xlopt 24_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_5/scripts/24_5.prx) 2>&1 | tee 24_5/24_5.log
	(coreverify -obj 24_5 -s 4096 -pm 16384)
24_6: 24_6_xlopt 24_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_6/scripts/24_6.prx) 2>&1 | tee 24_6/24_6.log
	(coreverify -obj 24_6 -s 4096 -pm 16384)
24_7: 24_7_xlopt 24_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 24_7/scripts/24_7.prx) 2>&1 | tee 24_7/24_7.log
	(coreverify -obj 24_7 -s 4096 -pm 16384)
25_0: 25_0_xlopt 25_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_0/scripts/25_0.prx) 2>&1 | tee 25_0/25_0.log
	(coreverify -obj 25_0 -s 4096 -pm 16384)
25_1: 25_1_xlopt 25_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_1/scripts/25_1.prx) 2>&1 | tee 25_1/25_1.log
	(coreverify -obj 25_1 -s 4096 -pm 16384)
25_2: 25_2_xlopt 25_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_2/scripts/25_2.prx) 2>&1 | tee 25_2/25_2.log
	(coreverify -obj 25_2 -s 4096 -pm 16384)
25_3: 25_3_xlopt 25_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_3/scripts/25_3.prx) 2>&1 | tee 25_3/25_3.log
	(coreverify -obj 25_3 -s 4096 -pm 16384)
25_4: 25_4_xlopt 25_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_4/scripts/25_4.prx) 2>&1 | tee 25_4/25_4.log
	(coreverify -obj 25_4 -s 4096 -pm 16384)
25_5: 25_5_xlopt 25_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_5/scripts/25_5.prx) 2>&1 | tee 25_5/25_5.log
	(coreverify -obj 25_5 -s 4096 -pm 16384)
25_6: 25_6_xlopt 25_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_6/scripts/25_6.prx) 2>&1 | tee 25_6/25_6.log
	(coreverify -obj 25_6 -s 4096 -pm 16384)
25_7: 25_7_xlopt 25_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 25_7/scripts/25_7.prx) 2>&1 | tee 25_7/25_7.log
	(coreverify -obj 25_7 -s 4096 -pm 16384)
26_0: 26_0_xlopt 26_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_0/scripts/26_0.prx) 2>&1 | tee 26_0/26_0.log
	(coreverify -obj 26_0 -s 4096 -pm 16384)
26_1: 26_1_xlopt 26_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_1/scripts/26_1.prx) 2>&1 | tee 26_1/26_1.log
	(coreverify -obj 26_1 -s 4096 -pm 16384)
26_2: 26_2_xlopt 26_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_2/scripts/26_2.prx) 2>&1 | tee 26_2/26_2.log
	(coreverify -obj 26_2 -s 4096 -pm 16384)
26_3: 26_3_xlopt 26_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_3/scripts/26_3.prx) 2>&1 | tee 26_3/26_3.log
	(coreverify -obj 26_3 -s 4096 -pm 16384)
26_4: 26_4_xlopt 26_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_4/scripts/26_4.prx) 2>&1 | tee 26_4/26_4.log
	(coreverify -obj 26_4 -s 4096 -pm 16384)
26_5: 26_5_xlopt 26_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_5/scripts/26_5.prx) 2>&1 | tee 26_5/26_5.log
	(coreverify -obj 26_5 -s 4096 -pm 16384)
26_6: 26_6_xlopt 26_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_6/scripts/26_6.prx) 2>&1 | tee 26_6/26_6.log
	(coreverify -obj 26_6 -s 4096 -pm 16384)
26_7: 26_7_xlopt 26_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 26_7/scripts/26_7.prx) 2>&1 | tee 26_7/26_7.log
	(coreverify -obj 26_7 -s 4096 -pm 16384)
27_0: 27_0_xlopt 27_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_0/scripts/27_0.prx) 2>&1 | tee 27_0/27_0.log
	(coreverify -obj 27_0 -s 4096 -pm 16384)
27_1: 27_1_xlopt 27_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_1/scripts/27_1.prx) 2>&1 | tee 27_1/27_1.log
	(coreverify -obj 27_1 -s 4096 -pm 16384)
27_2: 27_2_xlopt 27_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_2/scripts/27_2.prx) 2>&1 | tee 27_2/27_2.log
	(coreverify -obj 27_2 -s 4096 -pm 16384)
27_3: 27_3_xlopt 27_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_3/scripts/27_3.prx) 2>&1 | tee 27_3/27_3.log
	(coreverify -obj 27_3 -s 4096 -pm 16384)
27_4: 27_4_xlopt 27_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_4/scripts/27_4.prx) 2>&1 | tee 27_4/27_4.log
	(coreverify -obj 27_4 -s 4096 -pm 16384)
27_5: 27_5_xlopt 27_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_5/scripts/27_5.prx) 2>&1 | tee 27_5/27_5.log
	(coreverify -obj 27_5 -s 4096 -pm 16384)
27_6: 27_6_xlopt 27_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_6/scripts/27_6.prx) 2>&1 | tee 27_6/27_6.log
	(coreverify -obj 27_6 -s 4096 -pm 16384)
27_7: 27_7_xlopt 27_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 27_7/scripts/27_7.prx) 2>&1 | tee 27_7/27_7.log
	(coreverify -obj 27_7 -s 4096 -pm 16384)
28_0: 28_0_xlopt 28_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_0/scripts/28_0.prx) 2>&1 | tee 28_0/28_0.log
	(coreverify -obj 28_0 -s 4096 -pm 16384)
28_1: 28_1_xlopt 28_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_1/scripts/28_1.prx) 2>&1 | tee 28_1/28_1.log
	(coreverify -obj 28_1 -s 4096 -pm 16384)
28_2: 28_2_xlopt 28_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_2/scripts/28_2.prx) 2>&1 | tee 28_2/28_2.log
	(coreverify -obj 28_2 -s 4096 -pm 16384)
28_3: 28_3_xlopt 28_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_3/scripts/28_3.prx) 2>&1 | tee 28_3/28_3.log
	(coreverify -obj 28_3 -s 4096 -pm 16384)
28_4: 28_4_xlopt 28_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_4/scripts/28_4.prx) 2>&1 | tee 28_4/28_4.log
	(coreverify -obj 28_4 -s 4096 -pm 16384)
28_5: 28_5_xlopt 28_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_5/scripts/28_5.prx) 2>&1 | tee 28_5/28_5.log
	(coreverify -obj 28_5 -s 4096 -pm 16384)
28_6: 28_6_xlopt 28_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_6/scripts/28_6.prx) 2>&1 | tee 28_6/28_6.log
	(coreverify -obj 28_6 -s 4096 -pm 16384)
28_7: 28_7_xlopt 28_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 28_7/scripts/28_7.prx) 2>&1 | tee 28_7/28_7.log
	(coreverify -obj 28_7 -s 4096 -pm 16384)
29_0: 29_0_xlopt 29_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_0/scripts/29_0.prx) 2>&1 | tee 29_0/29_0.log
	(coreverify -obj 29_0 -s 4096 -pm 16384)
29_1: 29_1_xlopt 29_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_1/scripts/29_1.prx) 2>&1 | tee 29_1/29_1.log
	(coreverify -obj 29_1 -s 4096 -pm 16384)
29_2: 29_2_xlopt 29_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_2/scripts/29_2.prx) 2>&1 | tee 29_2/29_2.log
	(coreverify -obj 29_2 -s 4096 -pm 16384)
29_3: 29_3_xlopt 29_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_3/scripts/29_3.prx) 2>&1 | tee 29_3/29_3.log
	(coreverify -obj 29_3 -s 4096 -pm 16384)
29_4: 29_4_xlopt 29_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_4/scripts/29_4.prx) 2>&1 | tee 29_4/29_4.log
	(coreverify -obj 29_4 -s 4096 -pm 16384)
29_5: 29_5_xlopt 29_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_5/scripts/29_5.prx) 2>&1 | tee 29_5/29_5.log
	(coreverify -obj 29_5 -s 4096 -pm 16384)
29_6: 29_6_xlopt 29_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_6/scripts/29_6.prx) 2>&1 | tee 29_6/29_6.log
	(coreverify -obj 29_6 -s 4096 -pm 16384)
29_7: 29_7_xlopt 29_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 29_7/scripts/29_7.prx) 2>&1 | tee 29_7/29_7.log
	(coreverify -obj 29_7 -s 4096 -pm 16384)
30_0: 30_0_xlopt 30_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_0/scripts/30_0.prx) 2>&1 | tee 30_0/30_0.log
	(coreverify -obj 30_0 -s 4096 -pm 16384)
30_1: 30_1_xlopt 30_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_1/scripts/30_1.prx) 2>&1 | tee 30_1/30_1.log
	(coreverify -obj 30_1 -s 4096 -pm 16384)
30_2: 30_2_xlopt 30_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_2/scripts/30_2.prx) 2>&1 | tee 30_2/30_2.log
	(coreverify -obj 30_2 -s 4096 -pm 16384)
30_3: 30_3_xlopt 30_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_3/scripts/30_3.prx) 2>&1 | tee 30_3/30_3.log
	(coreverify -obj 30_3 -s 4096 -pm 16384)
30_4: 30_4_xlopt 30_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_4/scripts/30_4.prx) 2>&1 | tee 30_4/30_4.log
	(coreverify -obj 30_4 -s 4096 -pm 16384)
30_5: 30_5_xlopt 30_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_5/scripts/30_5.prx) 2>&1 | tee 30_5/30_5.log
	(coreverify -obj 30_5 -s 4096 -pm 16384)
30_6: 30_6_xlopt 30_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_6/scripts/30_6.prx) 2>&1 | tee 30_6/30_6.log
	(coreverify -obj 30_6 -s 4096 -pm 16384)
30_7: 30_7_xlopt 30_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 30_7/scripts/30_7.prx) 2>&1 | tee 30_7/30_7.log
	(coreverify -obj 30_7 -s 4096 -pm 16384)
31_0: 31_0_xlopt 31_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_0/scripts/31_0.prx) 2>&1 | tee 31_0/31_0.log
	(coreverify -obj 31_0 -s 4096 -pm 16384)
31_1: 31_1_xlopt 31_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_1/scripts/31_1.prx) 2>&1 | tee 31_1/31_1.log
	(coreverify -obj 31_1 -s 4096 -pm 16384)
31_2: 31_2_xlopt 31_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_2/scripts/31_2.prx) 2>&1 | tee 31_2/31_2.log
	(coreverify -obj 31_2 -s 4096 -pm 16384)
31_3: 31_3_xlopt 31_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_3/scripts/31_3.prx) 2>&1 | tee 31_3/31_3.log
	(coreverify -obj 31_3 -s 4096 -pm 16384)
31_4: 31_4_xlopt 31_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_4/scripts/31_4.prx) 2>&1 | tee 31_4/31_4.log
	(coreverify -obj 31_4 -s 4096 -pm 16384)
31_5: 31_5_xlopt 31_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_5/scripts/31_5.prx) 2>&1 | tee 31_5/31_5.log
	(coreverify -obj 31_5 -s 4096 -pm 16384)
31_6: 31_6_xlopt 31_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_6/scripts/31_6.prx) 2>&1 | tee 31_6/31_6.log
	(coreverify -obj 31_6 -s 4096 -pm 16384)
31_7: 31_7_xlopt 31_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 31_7/scripts/31_7.prx) 2>&1 | tee 31_7/31_7.log
	(coreverify -obj 31_7 -s 4096 -pm 16384)
32_0: 32_0_xlopt 32_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_0/scripts/32_0.prx) 2>&1 | tee 32_0/32_0.log
	(coreverify -obj 32_0 -s 4096 -pm 16384)
32_1: 32_1_xlopt 32_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_1/scripts/32_1.prx) 2>&1 | tee 32_1/32_1.log
	(coreverify -obj 32_1 -s 4096 -pm 16384)
32_2: 32_2_xlopt 32_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_2/scripts/32_2.prx) 2>&1 | tee 32_2/32_2.log
	(coreverify -obj 32_2 -s 4096 -pm 16384)
32_3: 32_3_xlopt 32_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_3/scripts/32_3.prx) 2>&1 | tee 32_3/32_3.log
	(coreverify -obj 32_3 -s 4096 -pm 16384)
32_4: 32_4_xlopt 32_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_4/scripts/32_4.prx) 2>&1 | tee 32_4/32_4.log
	(coreverify -obj 32_4 -s 4096 -pm 16384)
32_5: 32_5_xlopt 32_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_5/scripts/32_5.prx) 2>&1 | tee 32_5/32_5.log
	(coreverify -obj 32_5 -s 4096 -pm 16384)
32_6: 32_6_xlopt 32_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_6/scripts/32_6.prx) 2>&1 | tee 32_6/32_6.log
	(coreverify -obj 32_6 -s 4096 -pm 16384)
32_7: 32_7_xlopt 32_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 32_7/scripts/32_7.prx) 2>&1 | tee 32_7/32_7.log
	(coreverify -obj 32_7 -s 4096 -pm 16384)
33_0: 33_0_xlopt 33_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_0/scripts/33_0.prx) 2>&1 | tee 33_0/33_0.log
	(coreverify -obj 33_0 -s 4096 -pm 16384)
33_1: 33_1_xlopt 33_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_1/scripts/33_1.prx) 2>&1 | tee 33_1/33_1.log
	(coreverify -obj 33_1 -s 4096 -pm 16384)
33_2: 33_2_xlopt 33_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_2/scripts/33_2.prx) 2>&1 | tee 33_2/33_2.log
	(coreverify -obj 33_2 -s 4096 -pm 16384)
33_3: 33_3_xlopt 33_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_3/scripts/33_3.prx) 2>&1 | tee 33_3/33_3.log
	(coreverify -obj 33_3 -s 4096 -pm 16384)
33_4: 33_4_xlopt 33_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_4/scripts/33_4.prx) 2>&1 | tee 33_4/33_4.log
	(coreverify -obj 33_4 -s 4096 -pm 16384)
33_5: 33_5_xlopt 33_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_5/scripts/33_5.prx) 2>&1 | tee 33_5/33_5.log
	(coreverify -obj 33_5 -s 4096 -pm 16384)
33_6: 33_6_xlopt 33_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_6/scripts/33_6.prx) 2>&1 | tee 33_6/33_6.log
	(coreverify -obj 33_6 -s 4096 -pm 16384)
33_7: 33_7_xlopt 33_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 33_7/scripts/33_7.prx) 2>&1 | tee 33_7/33_7.log
	(coreverify -obj 33_7 -s 4096 -pm 16384)
34_0: 34_0_xlopt 34_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_0/scripts/34_0.prx) 2>&1 | tee 34_0/34_0.log
	(coreverify -obj 34_0 -s 4096 -pm 16384)
34_1: 34_1_xlopt 34_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_1/scripts/34_1.prx) 2>&1 | tee 34_1/34_1.log
	(coreverify -obj 34_1 -s 4096 -pm 16384)
34_2: 34_2_xlopt 34_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_2/scripts/34_2.prx) 2>&1 | tee 34_2/34_2.log
	(coreverify -obj 34_2 -s 4096 -pm 16384)
34_3: 34_3_xlopt 34_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_3/scripts/34_3.prx) 2>&1 | tee 34_3/34_3.log
	(coreverify -obj 34_3 -s 4096 -pm 16384)
34_4: 34_4_xlopt 34_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_4/scripts/34_4.prx) 2>&1 | tee 34_4/34_4.log
	(coreverify -obj 34_4 -s 4096 -pm 16384)
34_5: 34_5_xlopt 34_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_5/scripts/34_5.prx) 2>&1 | tee 34_5/34_5.log
	(coreverify -obj 34_5 -s 4096 -pm 16384)
34_6: 34_6_xlopt 34_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_6/scripts/34_6.prx) 2>&1 | tee 34_6/34_6.log
	(coreverify -obj 34_6 -s 4096 -pm 16384)
34_7: 34_7_xlopt 34_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 34_7/scripts/34_7.prx) 2>&1 | tee 34_7/34_7.log
	(coreverify -obj 34_7 -s 4096 -pm 16384)
35_0: 35_0_xlopt 35_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_0/scripts/35_0.prx) 2>&1 | tee 35_0/35_0.log
	(coreverify -obj 35_0 -s 4096 -pm 16384)
35_1: 35_1_xlopt 35_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_1/scripts/35_1.prx) 2>&1 | tee 35_1/35_1.log
	(coreverify -obj 35_1 -s 4096 -pm 16384)
35_2: 35_2_xlopt 35_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_2/scripts/35_2.prx) 2>&1 | tee 35_2/35_2.log
	(coreverify -obj 35_2 -s 4096 -pm 16384)
35_3: 35_3_xlopt 35_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_3/scripts/35_3.prx) 2>&1 | tee 35_3/35_3.log
	(coreverify -obj 35_3 -s 4096 -pm 16384)
35_4: 35_4_xlopt 35_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_4/scripts/35_4.prx) 2>&1 | tee 35_4/35_4.log
	(coreverify -obj 35_4 -s 4096 -pm 16384)
35_5: 35_5_xlopt 35_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_5/scripts/35_5.prx) 2>&1 | tee 35_5/35_5.log
	(coreverify -obj 35_5 -s 4096 -pm 16384)
35_6: 35_6_xlopt 35_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_6/scripts/35_6.prx) 2>&1 | tee 35_6/35_6.log
	(coreverify -obj 35_6 -s 4096 -pm 16384)
35_7: 35_7_xlopt 35_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 35_7/scripts/35_7.prx) 2>&1 | tee 35_7/35_7.log
	(coreverify -obj 35_7 -s 4096 -pm 16384)
36_0: 36_0_xlopt 36_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_0/scripts/36_0.prx) 2>&1 | tee 36_0/36_0.log
	(coreverify -obj 36_0 -s 4096 -pm 16384)
36_1: 36_1_xlopt 36_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_1/scripts/36_1.prx) 2>&1 | tee 36_1/36_1.log
	(coreverify -obj 36_1 -s 4096 -pm 16384)
36_2: 36_2_xlopt 36_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_2/scripts/36_2.prx) 2>&1 | tee 36_2/36_2.log
	(coreverify -obj 36_2 -s 4096 -pm 16384)
36_3: 36_3_xlopt 36_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_3/scripts/36_3.prx) 2>&1 | tee 36_3/36_3.log
	(coreverify -obj 36_3 -s 4096 -pm 16384)
36_4: 36_4_xlopt 36_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_4/scripts/36_4.prx) 2>&1 | tee 36_4/36_4.log
	(coreverify -obj 36_4 -s 4096 -pm 16384)
36_5: 36_5_xlopt 36_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_5/scripts/36_5.prx) 2>&1 | tee 36_5/36_5.log
	(coreverify -obj 36_5 -s 4096 -pm 16384)
36_6: 36_6_xlopt 36_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_6/scripts/36_6.prx) 2>&1 | tee 36_6/36_6.log
	(coreverify -obj 36_6 -s 4096 -pm 16384)
36_7: 36_7_xlopt 36_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 36_7/scripts/36_7.prx) 2>&1 | tee 36_7/36_7.log
	(coreverify -obj 36_7 -s 4096 -pm 16384)
37_0: 37_0_xlopt 37_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_0/scripts/37_0.prx) 2>&1 | tee 37_0/37_0.log
	(coreverify -obj 37_0 -s 4096 -pm 16384)
37_1: 37_1_xlopt 37_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_1/scripts/37_1.prx) 2>&1 | tee 37_1/37_1.log
	(coreverify -obj 37_1 -s 4096 -pm 16384)
37_2: 37_2_xlopt 37_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_2/scripts/37_2.prx) 2>&1 | tee 37_2/37_2.log
	(coreverify -obj 37_2 -s 4096 -pm 16384)
37_3: 37_3_xlopt 37_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_3/scripts/37_3.prx) 2>&1 | tee 37_3/37_3.log
	(coreverify -obj 37_3 -s 4096 -pm 16384)
37_4: 37_4_xlopt 37_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_4/scripts/37_4.prx) 2>&1 | tee 37_4/37_4.log
	(coreverify -obj 37_4 -s 4096 -pm 16384)
37_5: 37_5_xlopt 37_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_5/scripts/37_5.prx) 2>&1 | tee 37_5/37_5.log
	(coreverify -obj 37_5 -s 4096 -pm 16384)
37_6: 37_6_xlopt 37_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_6/scripts/37_6.prx) 2>&1 | tee 37_6/37_6.log
	(coreverify -obj 37_6 -s 4096 -pm 16384)
37_7: 37_7_xlopt 37_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 37_7/scripts/37_7.prx) 2>&1 | tee 37_7/37_7.log
	(coreverify -obj 37_7 -s 4096 -pm 16384)
38_0: 38_0_xlopt 38_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_0/scripts/38_0.prx) 2>&1 | tee 38_0/38_0.log
	(coreverify -obj 38_0 -s 4096 -pm 16384)
38_1: 38_1_xlopt 38_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_1/scripts/38_1.prx) 2>&1 | tee 38_1/38_1.log
	(coreverify -obj 38_1 -s 4096 -pm 16384)
38_2: 38_2_xlopt 38_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_2/scripts/38_2.prx) 2>&1 | tee 38_2/38_2.log
	(coreverify -obj 38_2 -s 4096 -pm 16384)
38_3: 38_3_xlopt 38_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_3/scripts/38_3.prx) 2>&1 | tee 38_3/38_3.log
	(coreverify -obj 38_3 -s 4096 -pm 16384)
38_4: 38_4_xlopt 38_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_4/scripts/38_4.prx) 2>&1 | tee 38_4/38_4.log
	(coreverify -obj 38_4 -s 4096 -pm 16384)
38_5: 38_5_xlopt 38_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_5/scripts/38_5.prx) 2>&1 | tee 38_5/38_5.log
	(coreverify -obj 38_5 -s 4096 -pm 16384)
38_6: 38_6_xlopt 38_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_6/scripts/38_6.prx) 2>&1 | tee 38_6/38_6.log
	(coreverify -obj 38_6 -s 4096 -pm 16384)
38_7: 38_7_xlopt 38_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 38_7/scripts/38_7.prx) 2>&1 | tee 38_7/38_7.log
	(coreverify -obj 38_7 -s 4096 -pm 16384)
39_0: 39_0_xlopt 39_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_0/scripts/39_0.prx) 2>&1 | tee 39_0/39_0.log
	(coreverify -obj 39_0 -s 4096 -pm 16384)
39_1: 39_1_xlopt 39_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_1/scripts/39_1.prx) 2>&1 | tee 39_1/39_1.log
	(coreverify -obj 39_1 -s 4096 -pm 16384)
39_2: 39_2_xlopt 39_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_2/scripts/39_2.prx) 2>&1 | tee 39_2/39_2.log
	(coreverify -obj 39_2 -s 4096 -pm 16384)
39_3: 39_3_xlopt 39_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_3/scripts/39_3.prx) 2>&1 | tee 39_3/39_3.log
	(coreverify -obj 39_3 -s 4096 -pm 16384)
39_4: 39_4_xlopt 39_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_4/scripts/39_4.prx) 2>&1 | tee 39_4/39_4.log
	(coreverify -obj 39_4 -s 4096 -pm 16384)
39_5: 39_5_xlopt 39_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_5/scripts/39_5.prx) 2>&1 | tee 39_5/39_5.log
	(coreverify -obj 39_5 -s 4096 -pm 16384)
39_6: 39_6_xlopt 39_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_6/scripts/39_6.prx) 2>&1 | tee 39_6/39_6.log
	(coreverify -obj 39_6 -s 4096 -pm 16384)
39_7: 39_7_xlopt 39_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 39_7/scripts/39_7.prx) 2>&1 | tee 39_7/39_7.log
	(coreverify -obj 39_7 -s 4096 -pm 16384)
40_0: 40_0_xlopt 40_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_0/scripts/40_0.prx) 2>&1 | tee 40_0/40_0.log
	(coreverify -obj 40_0 -s 4096 -pm 16384)
40_1: 40_1_xlopt 40_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_1/scripts/40_1.prx) 2>&1 | tee 40_1/40_1.log
	(coreverify -obj 40_1 -s 4096 -pm 16384)
40_2: 40_2_xlopt 40_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_2/scripts/40_2.prx) 2>&1 | tee 40_2/40_2.log
	(coreverify -obj 40_2 -s 4096 -pm 16384)
40_3: 40_3_xlopt 40_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_3/scripts/40_3.prx) 2>&1 | tee 40_3/40_3.log
	(coreverify -obj 40_3 -s 4096 -pm 16384)
40_4: 40_4_xlopt 40_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_4/scripts/40_4.prx) 2>&1 | tee 40_4/40_4.log
	(coreverify -obj 40_4 -s 4096 -pm 16384)
40_5: 40_5_xlopt 40_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_5/scripts/40_5.prx) 2>&1 | tee 40_5/40_5.log
	(coreverify -obj 40_5 -s 4096 -pm 16384)
40_6: 40_6_xlopt 40_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_6/scripts/40_6.prx) 2>&1 | tee 40_6/40_6.log
	(coreverify -obj 40_6 -s 4096 -pm 16384)
40_7: 40_7_xlopt 40_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 40_7/scripts/40_7.prx) 2>&1 | tee 40_7/40_7.log
	(coreverify -obj 40_7 -s 4096 -pm 16384)
41_0: 41_0_xlopt 41_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_0/scripts/41_0.prx) 2>&1 | tee 41_0/41_0.log
	(coreverify -obj 41_0 -s 4096 -pm 16384)
41_1: 41_1_xlopt 41_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_1/scripts/41_1.prx) 2>&1 | tee 41_1/41_1.log
	(coreverify -obj 41_1 -s 4096 -pm 16384)
41_2: 41_2_xlopt 41_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_2/scripts/41_2.prx) 2>&1 | tee 41_2/41_2.log
	(coreverify -obj 41_2 -s 4096 -pm 16384)
41_3: 41_3_xlopt 41_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_3/scripts/41_3.prx) 2>&1 | tee 41_3/41_3.log
	(coreverify -obj 41_3 -s 4096 -pm 16384)
41_4: 41_4_xlopt 41_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_4/scripts/41_4.prx) 2>&1 | tee 41_4/41_4.log
	(coreverify -obj 41_4 -s 4096 -pm 16384)
41_5: 41_5_xlopt 41_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_5/scripts/41_5.prx) 2>&1 | tee 41_5/41_5.log
	(coreverify -obj 41_5 -s 4096 -pm 16384)
41_6: 41_6_xlopt 41_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_6/scripts/41_6.prx) 2>&1 | tee 41_6/41_6.log
	(coreverify -obj 41_6 -s 4096 -pm 16384)
41_7: 41_7_xlopt 41_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_7/scripts/41_7.prx) 2>&1 | tee 41_7/41_7.log
	(coreverify -obj 41_7 -s 4096 -pm 16384)
42_0: 42_0_xlopt 42_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_0/scripts/42_0.prx) 2>&1 | tee 42_0/42_0.log
	(coreverify -obj 42_0 -s 4096 -pm 16384)
42_1: 42_1_xlopt 42_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_1/scripts/42_1.prx) 2>&1 | tee 42_1/42_1.log
	(coreverify -obj 42_1 -s 4096 -pm 16384)
42_2: 42_2_xlopt 42_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_2/scripts/42_2.prx) 2>&1 | tee 42_2/42_2.log
	(coreverify -obj 42_2 -s 4096 -pm 16384)
42_3: 42_3_xlopt 42_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_3/scripts/42_3.prx) 2>&1 | tee 42_3/42_3.log
	(coreverify -obj 42_3 -s 4096 -pm 16384)
42_4: 42_4_xlopt 42_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_4/scripts/42_4.prx) 2>&1 | tee 42_4/42_4.log
	(coreverify -obj 42_4 -s 4096 -pm 16384)
42_5: 42_5_xlopt 42_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_5/scripts/42_5.prx) 2>&1 | tee 42_5/42_5.log
	(coreverify -obj 42_5 -s 4096 -pm 16384)
42_6: 42_6_xlopt 42_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_6/scripts/42_6.prx) 2>&1 | tee 42_6/42_6.log
	(coreverify -obj 42_6 -s 4096 -pm 16384)
42_7: 42_7_xlopt 42_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 42_7/scripts/42_7.prx) 2>&1 | tee 42_7/42_7.log
	(coreverify -obj 42_7 -s 4096 -pm 16384)
43_0: 43_0_xlopt 43_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_0/scripts/43_0.prx) 2>&1 | tee 43_0/43_0.log
	(coreverify -obj 43_0 -s 4096 -pm 16384)
43_1: 43_1_xlopt 43_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_1/scripts/43_1.prx) 2>&1 | tee 43_1/43_1.log
	(coreverify -obj 43_1 -s 4096 -pm 16384)
43_2: 43_2_xlopt 43_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_2/scripts/43_2.prx) 2>&1 | tee 43_2/43_2.log
	(coreverify -obj 43_2 -s 4096 -pm 16384)
43_3: 43_3_xlopt 43_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_3/scripts/43_3.prx) 2>&1 | tee 43_3/43_3.log
	(coreverify -obj 43_3 -s 4096 -pm 16384)
43_4: 43_4_xlopt 43_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_4/scripts/43_4.prx) 2>&1 | tee 43_4/43_4.log
	(coreverify -obj 43_4 -s 4096 -pm 16384)
43_5: 43_5_xlopt 43_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_5/scripts/43_5.prx) 2>&1 | tee 43_5/43_5.log
	(coreverify -obj 43_5 -s 4096 -pm 16384)
43_6: 43_6_xlopt 43_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_6/scripts/43_6.prx) 2>&1 | tee 43_6/43_6.log
	(coreverify -obj 43_6 -s 4096 -pm 16384)
43_7: 43_7_xlopt 43_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 43_7/scripts/43_7.prx) 2>&1 | tee 43_7/43_7.log
	(coreverify -obj 43_7 -s 4096 -pm 16384)
44_0: 44_0_xlopt 44_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_0/scripts/44_0.prx) 2>&1 | tee 44_0/44_0.log
	(coreverify -obj 44_0 -s 4096 -pm 16384)
44_1: 44_1_xlopt 44_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_1/scripts/44_1.prx) 2>&1 | tee 44_1/44_1.log
	(coreverify -obj 44_1 -s 4096 -pm 16384)
44_2: 44_2_xlopt 44_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_2/scripts/44_2.prx) 2>&1 | tee 44_2/44_2.log
	(coreverify -obj 44_2 -s 4096 -pm 16384)
44_3: 44_3_xlopt 44_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_3/scripts/44_3.prx) 2>&1 | tee 44_3/44_3.log
	(coreverify -obj 44_3 -s 4096 -pm 16384)
44_4: 44_4_xlopt 44_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_4/scripts/44_4.prx) 2>&1 | tee 44_4/44_4.log
	(coreverify -obj 44_4 -s 4096 -pm 16384)
44_5: 44_5_xlopt 44_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_5/scripts/44_5.prx) 2>&1 | tee 44_5/44_5.log
	(coreverify -obj 44_5 -s 4096 -pm 16384)
44_6: 44_6_xlopt 44_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_6/scripts/44_6.prx) 2>&1 | tee 44_6/44_6.log
	(coreverify -obj 44_6 -s 4096 -pm 16384)
44_7: 44_7_xlopt 44_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 44_7/scripts/44_7.prx) 2>&1 | tee 44_7/44_7.log
	(coreverify -obj 44_7 -s 4096 -pm 16384)
45_0: 45_0_xlopt 45_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_0/scripts/45_0.prx) 2>&1 | tee 45_0/45_0.log
	(coreverify -obj 45_0 -s 4096 -pm 16384)
45_1: 45_1_xlopt 45_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_1/scripts/45_1.prx) 2>&1 | tee 45_1/45_1.log
	(coreverify -obj 45_1 -s 4096 -pm 16384)
45_2: 45_2_xlopt 45_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_2/scripts/45_2.prx) 2>&1 | tee 45_2/45_2.log
	(coreverify -obj 45_2 -s 4096 -pm 16384)
45_3: 45_3_xlopt 45_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_3/scripts/45_3.prx) 2>&1 | tee 45_3/45_3.log
	(coreverify -obj 45_3 -s 4096 -pm 16384)
45_4: 45_4_xlopt 45_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_4/scripts/45_4.prx) 2>&1 | tee 45_4/45_4.log
	(coreverify -obj 45_4 -s 4096 -pm 16384)
45_5: 45_5_xlopt 45_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_5/scripts/45_5.prx) 2>&1 | tee 45_5/45_5.log
	(coreverify -obj 45_5 -s 4096 -pm 16384)
45_6: 45_6_xlopt 45_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_6/scripts/45_6.prx) 2>&1 | tee 45_6/45_6.log
	(coreverify -obj 45_6 -s 4096 -pm 16384)
45_7: 45_7_xlopt 45_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_7/scripts/45_7.prx) 2>&1 | tee 45_7/45_7.log
	(coreverify -obj 45_7 -s 4096 -pm 16384)
46_0: 46_0_xlopt 46_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_0/scripts/46_0.prx) 2>&1 | tee 46_0/46_0.log
	(coreverify -obj 46_0 -s 4096 -pm 16384)
46_1: 46_1_xlopt 46_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_1/scripts/46_1.prx) 2>&1 | tee 46_1/46_1.log
	(coreverify -obj 46_1 -s 4096 -pm 16384)
46_2: 46_2_xlopt 46_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_2/scripts/46_2.prx) 2>&1 | tee 46_2/46_2.log
	(coreverify -obj 46_2 -s 4096 -pm 16384)
46_3: 46_3_xlopt 46_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_3/scripts/46_3.prx) 2>&1 | tee 46_3/46_3.log
	(coreverify -obj 46_3 -s 4096 -pm 16384)
46_4: 46_4_xlopt 46_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_4/scripts/46_4.prx) 2>&1 | tee 46_4/46_4.log
	(coreverify -obj 46_4 -s 4096 -pm 16384)
46_5: 46_5_xlopt 46_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_5/scripts/46_5.prx) 2>&1 | tee 46_5/46_5.log
	(coreverify -obj 46_5 -s 4096 -pm 16384)
46_6: 46_6_xlopt 46_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_6/scripts/46_6.prx) 2>&1 | tee 46_6/46_6.log
	(coreverify -obj 46_6 -s 4096 -pm 16384)
46_7: 46_7_xlopt 46_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 46_7/scripts/46_7.prx) 2>&1 | tee 46_7/46_7.log
	(coreverify -obj 46_7 -s 4096 -pm 16384)
47_0: 47_0_xlopt 47_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_0/scripts/47_0.prx) 2>&1 | tee 47_0/47_0.log
	(coreverify -obj 47_0 -s 4096 -pm 16384)
47_1: 47_1_xlopt 47_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_1/scripts/47_1.prx) 2>&1 | tee 47_1/47_1.log
	(coreverify -obj 47_1 -s 4096 -pm 16384)
47_2: 47_2_xlopt 47_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_2/scripts/47_2.prx) 2>&1 | tee 47_2/47_2.log
	(coreverify -obj 47_2 -s 4096 -pm 16384)
47_3: 47_3_xlopt 47_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_3/scripts/47_3.prx) 2>&1 | tee 47_3/47_3.log
	(coreverify -obj 47_3 -s 4096 -pm 16384)
47_4: 47_4_xlopt 47_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_4/scripts/47_4.prx) 2>&1 | tee 47_4/47_4.log
	(coreverify -obj 47_4 -s 4096 -pm 16384)
47_5: 47_5_xlopt 47_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_5/scripts/47_5.prx) 2>&1 | tee 47_5/47_5.log
	(coreverify -obj 47_5 -s 4096 -pm 16384)
47_6: 47_6_xlopt 47_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_6/scripts/47_6.prx) 2>&1 | tee 47_6/47_6.log
	(coreverify -obj 47_6 -s 4096 -pm 16384)
47_7: 47_7_xlopt 47_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 47_7/scripts/47_7.prx) 2>&1 | tee 47_7/47_7.log
	(coreverify -obj 47_7 -s 4096 -pm 16384)
48_0: 48_0_xlopt 48_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_0/scripts/48_0.prx) 2>&1 | tee 48_0/48_0.log
	(coreverify -obj 48_0 -s 4096 -pm 16384)
48_1: 48_1_xlopt 48_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_1/scripts/48_1.prx) 2>&1 | tee 48_1/48_1.log
	(coreverify -obj 48_1 -s 4096 -pm 16384)
48_2: 48_2_xlopt 48_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_2/scripts/48_2.prx) 2>&1 | tee 48_2/48_2.log
	(coreverify -obj 48_2 -s 4096 -pm 16384)
48_3: 48_3_xlopt 48_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_3/scripts/48_3.prx) 2>&1 | tee 48_3/48_3.log
	(coreverify -obj 48_3 -s 4096 -pm 16384)
48_4: 48_4_xlopt 48_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_4/scripts/48_4.prx) 2>&1 | tee 48_4/48_4.log
	(coreverify -obj 48_4 -s 4096 -pm 16384)
48_5: 48_5_xlopt 48_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_5/scripts/48_5.prx) 2>&1 | tee 48_5/48_5.log
	(coreverify -obj 48_5 -s 4096 -pm 16384)
48_6: 48_6_xlopt 48_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_6/scripts/48_6.prx) 2>&1 | tee 48_6/48_6.log
	(coreverify -obj 48_6 -s 4096 -pm 16384)
48_7: 48_7_xlopt 48_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 48_7/scripts/48_7.prx) 2>&1 | tee 48_7/48_7.log
	(coreverify -obj 48_7 -s 4096 -pm 16384)
49_0: 49_0_xlopt 49_0_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_0/scripts/49_0.prx) 2>&1 | tee 49_0/49_0.log
	(coreverify -obj 49_0 -s 4096 -pm 16384)
49_1: 49_1_xlopt 49_1_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_1/scripts/49_1.prx) 2>&1 | tee 49_1/49_1.log
	(coreverify -obj 49_1 -s 4096 -pm 16384)
49_2: 49_2_xlopt 49_2_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_2/scripts/49_2.prx) 2>&1 | tee 49_2/49_2.log
	(coreverify -obj 49_2 -s 4096 -pm 16384)
49_3: 49_3_xlopt 49_3_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_3/scripts/49_3.prx) 2>&1 | tee 49_3/49_3.log
	(coreverify -obj 49_3 -s 4096 -pm 16384)
49_4: 49_4_xlopt 49_4_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_4/scripts/49_4.prx) 2>&1 | tee 49_4/49_4.log
	(coreverify -obj 49_4 -s 4096 -pm 16384)
49_5: 49_5_xlopt 49_5_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_5/scripts/49_5.prx) 2>&1 | tee 49_5/49_5.log
	(coreverify -obj 49_5 -s 4096 -pm 16384)
49_6: 49_6_xlopt 49_6_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_6/scripts/49_6.prx) 2>&1 | tee 49_6/49_6.log
	(coreverify -obj 49_6 -s 4096 -pm 16384)
49_7: 49_7_xlopt 49_7_llopt
	(${XCHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR}  +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 49_7/scripts/49_7.prx) 2>&1 | tee 49_7/49_7.log
	(coreverify -obj 49_7 -s 4096 -pm 16384)

clean:
	(rm -rf 2_0/Release)
	(rm -rf 2_1/Release)
	(rm -rf 2_2/Release)
	(rm -rf 2_3/Release)
	(rm -rf 2_4/Release)
	(rm -rf 2_5/Release)
	(rm -rf 2_6/Release)
	(rm -rf 2_7/Release)
	(rm -rf 3_0/Release)
	(rm -rf 3_1/Release)
	(rm -rf 3_2/Release)
	(rm -rf 3_3/Release)
	(rm -rf 3_4/Release)
	(rm -rf 3_5/Release)
	(rm -rf 3_6/Release)
	(rm -rf 3_7/Release)
	(rm -rf 4_0/Release)
	(rm -rf 4_1/Release)
	(rm -rf 4_2/Release)
	(rm -rf 4_3/Release)
	(rm -rf 4_4/Release)
	(rm -rf 4_5/Release)
	(rm -rf 4_6/Release)
	(rm -rf 4_7/Release)
	(rm -rf 5_0/Release)
	(rm -rf 5_1/Release)
	(rm -rf 5_2/Release)
	(rm -rf 5_3/Release)
	(rm -rf 5_4/Release)
	(rm -rf 5_5/Release)
	(rm -rf 5_6/Release)
	(rm -rf 5_7/Release)
	(rm -rf 6_0/Release)
	(rm -rf 6_1/Release)
	(rm -rf 6_2/Release)
	(rm -rf 6_3/Release)
	(rm -rf 6_4/Release)
	(rm -rf 6_5/Release)
	(rm -rf 6_6/Release)
	(rm -rf 6_7/Release)
	(rm -rf 7_0/Release)
	(rm -rf 7_1/Release)
	(rm -rf 7_2/Release)
	(rm -rf 7_3/Release)
	(rm -rf 7_4/Release)
	(rm -rf 7_5/Release)
	(rm -rf 7_6/Release)
	(rm -rf 7_7/Release)
	(rm -rf 8_0/Release)
	(rm -rf 8_1/Release)
	(rm -rf 8_2/Release)
	(rm -rf 8_3/Release)
	(rm -rf 8_4/Release)
	(rm -rf 8_5/Release)
	(rm -rf 8_6/Release)
	(rm -rf 8_7/Release)
	(rm -rf 9_0/Release)
	(rm -rf 9_1/Release)
	(rm -rf 9_2/Release)
	(rm -rf 9_3/Release)
	(rm -rf 9_4/Release)
	(rm -rf 9_5/Release)
	(rm -rf 9_6/Release)
	(rm -rf 9_7/Release)
	(rm -rf 10_0/Release)
	(rm -rf 10_1/Release)
	(rm -rf 10_2/Release)
	(rm -rf 10_3/Release)
	(rm -rf 10_4/Release)
	(rm -rf 10_5/Release)
	(rm -rf 10_6/Release)
	(rm -rf 10_7/Release)
	(rm -rf 11_0/Release)
	(rm -rf 11_1/Release)
	(rm -rf 11_2/Release)
	(rm -rf 11_3/Release)
	(rm -rf 11_4/Release)
	(rm -rf 11_5/Release)
	(rm -rf 11_6/Release)
	(rm -rf 11_7/Release)
	(rm -rf 12_0/Release)
	(rm -rf 12_1/Release)
	(rm -rf 12_2/Release)
	(rm -rf 12_3/Release)
	(rm -rf 12_4/Release)
	(rm -rf 12_5/Release)
	(rm -rf 12_6/Release)
	(rm -rf 12_7/Release)
	(rm -rf 13_0/Release)
	(rm -rf 13_1/Release)
	(rm -rf 13_2/Release)
	(rm -rf 13_3/Release)
	(rm -rf 13_4/Release)
	(rm -rf 13_5/Release)
	(rm -rf 13_6/Release)
	(rm -rf 13_7/Release)
	(rm -rf 14_0/Release)
	(rm -rf 14_1/Release)
	(rm -rf 14_2/Release)
	(rm -rf 14_3/Release)
	(rm -rf 14_4/Release)
	(rm -rf 14_5/Release)
	(rm -rf 14_6/Release)
	(rm -rf 14_7/Release)
	(rm -rf 15_0/Release)
	(rm -rf 15_1/Release)
	(rm -rf 15_2/Release)
	(rm -rf 15_3/Release)
	(rm -rf 15_4/Release)
	(rm -rf 15_5/Release)
	(rm -rf 15_6/Release)
	(rm -rf 15_7/Release)
	(rm -rf 16_0/Release)
	(rm -rf 16_1/Release)
	(rm -rf 16_2/Release)
	(rm -rf 16_3/Release)
	(rm -rf 16_4/Release)
	(rm -rf 16_5/Release)
	(rm -rf 16_6/Release)
	(rm -rf 16_7/Release)
	(rm -rf 17_0/Release)
	(rm -rf 17_1/Release)
	(rm -rf 17_2/Release)
	(rm -rf 17_3/Release)
	(rm -rf 17_4/Release)
	(rm -rf 17_5/Release)
	(rm -rf 17_6/Release)
	(rm -rf 17_7/Release)
	(rm -rf 18_0/Release)
	(rm -rf 18_1/Release)
	(rm -rf 18_2/Release)
	(rm -rf 18_3/Release)
	(rm -rf 18_4/Release)
	(rm -rf 18_5/Release)
	(rm -rf 18_6/Release)
	(rm -rf 18_7/Release)
	(rm -rf 19_0/Release)
	(rm -rf 19_1/Release)
	(rm -rf 19_2/Release)
	(rm -rf 19_3/Release)
	(rm -rf 19_4/Release)
	(rm -rf 19_5/Release)
	(rm -rf 19_6/Release)
	(rm -rf 19_7/Release)
	(rm -rf 20_0/Release)
	(rm -rf 20_1/Release)
	(rm -rf 20_2/Release)
	(rm -rf 20_3/Release)
	(rm -rf 20_4/Release)
	(rm -rf 20_5/Release)
	(rm -rf 20_6/Release)
	(rm -rf 20_7/Release)
	(rm -rf 21_0/Release)
	(rm -rf 21_1/Release)
	(rm -rf 21_2/Release)
	(rm -rf 21_3/Release)
	(rm -rf 21_4/Release)
	(rm -rf 21_5/Release)
	(rm -rf 21_6/Release)
	(rm -rf 21_7/Release)
	(rm -rf 22_0/Release)
	(rm -rf 22_1/Release)
	(rm -rf 22_2/Release)
	(rm -rf 22_3/Release)
	(rm -rf 22_4/Release)
	(rm -rf 22_5/Release)
	(rm -rf 22_6/Release)
	(rm -rf 22_7/Release)
	(rm -rf 23_0/Release)
	(rm -rf 23_1/Release)
	(rm -rf 23_2/Release)
	(rm -rf 23_3/Release)
	(rm -rf 23_4/Release)
	(rm -rf 23_5/Release)
	(rm -rf 23_6/Release)
	(rm -rf 23_7/Release)
	(rm -rf 24_0/Release)
	(rm -rf 24_1/Release)
	(rm -rf 24_2/Release)
	(rm -rf 24_3/Release)
	(rm -rf 24_4/Release)
	(rm -rf 24_5/Release)
	(rm -rf 24_6/Release)
	(rm -rf 24_7/Release)
	(rm -rf 25_0/Release)
	(rm -rf 25_1/Release)
	(rm -rf 25_2/Release)
	(rm -rf 25_3/Release)
	(rm -rf 25_4/Release)
	(rm -rf 25_5/Release)
	(rm -rf 25_6/Release)
	(rm -rf 25_7/Release)
	(rm -rf 26_0/Release)
	(rm -rf 26_1/Release)
	(rm -rf 26_2/Release)
	(rm -rf 26_3/Release)
	(rm -rf 26_4/Release)
	(rm -rf 26_5/Release)
	(rm -rf 26_6/Release)
	(rm -rf 26_7/Release)
	(rm -rf 27_0/Release)
	(rm -rf 27_1/Release)
	(rm -rf 27_2/Release)
	(rm -rf 27_3/Release)
	(rm -rf 27_4/Release)
	(rm -rf 27_5/Release)
	(rm -rf 27_6/Release)
	(rm -rf 27_7/Release)
	(rm -rf 28_0/Release)
	(rm -rf 28_1/Release)
	(rm -rf 28_2/Release)
	(rm -rf 28_3/Release)
	(rm -rf 28_4/Release)
	(rm -rf 28_5/Release)
	(rm -rf 28_6/Release)
	(rm -rf 28_7/Release)
	(rm -rf 29_0/Release)
	(rm -rf 29_1/Release)
	(rm -rf 29_2/Release)
	(rm -rf 29_3/Release)
	(rm -rf 29_4/Release)
	(rm -rf 29_5/Release)
	(rm -rf 29_6/Release)
	(rm -rf 29_7/Release)
	(rm -rf 30_0/Release)
	(rm -rf 30_1/Release)
	(rm -rf 30_2/Release)
	(rm -rf 30_3/Release)
	(rm -rf 30_4/Release)
	(rm -rf 30_5/Release)
	(rm -rf 30_6/Release)
	(rm -rf 30_7/Release)
	(rm -rf 31_0/Release)
	(rm -rf 31_1/Release)
	(rm -rf 31_2/Release)
	(rm -rf 31_3/Release)
	(rm -rf 31_4/Release)
	(rm -rf 31_5/Release)
	(rm -rf 31_6/Release)
	(rm -rf 31_7/Release)
	(rm -rf 32_0/Release)
	(rm -rf 32_1/Release)
	(rm -rf 32_2/Release)
	(rm -rf 32_3/Release)
	(rm -rf 32_4/Release)
	(rm -rf 32_5/Release)
	(rm -rf 32_6/Release)
	(rm -rf 32_7/Release)
	(rm -rf 33_0/Release)
	(rm -rf 33_1/Release)
	(rm -rf 33_2/Release)
	(rm -rf 33_3/Release)
	(rm -rf 33_4/Release)
	(rm -rf 33_5/Release)
	(rm -rf 33_6/Release)
	(rm -rf 33_7/Release)
	(rm -rf 34_0/Release)
	(rm -rf 34_1/Release)
	(rm -rf 34_2/Release)
	(rm -rf 34_3/Release)
	(rm -rf 34_4/Release)
	(rm -rf 34_5/Release)
	(rm -rf 34_6/Release)
	(rm -rf 34_7/Release)
	(rm -rf 35_0/Release)
	(rm -rf 35_1/Release)
	(rm -rf 35_2/Release)
	(rm -rf 35_3/Release)
	(rm -rf 35_4/Release)
	(rm -rf 35_5/Release)
	(rm -rf 35_6/Release)
	(rm -rf 35_7/Release)
	(rm -rf 36_0/Release)
	(rm -rf 36_1/Release)
	(rm -rf 36_2/Release)
	(rm -rf 36_3/Release)
	(rm -rf 36_4/Release)
	(rm -rf 36_5/Release)
	(rm -rf 36_6/Release)
	(rm -rf 36_7/Release)
	(rm -rf 37_0/Release)
	(rm -rf 37_1/Release)
	(rm -rf 37_2/Release)
	(rm -rf 37_3/Release)
	(rm -rf 37_4/Release)
	(rm -rf 37_5/Release)
	(rm -rf 37_6/Release)
	(rm -rf 37_7/Release)
	(rm -rf 38_0/Release)
	(rm -rf 38_1/Release)
	(rm -rf 38_2/Release)
	(rm -rf 38_3/Release)
	(rm -rf 38_4/Release)
	(rm -rf 38_5/Release)
	(rm -rf 38_6/Release)
	(rm -rf 38_7/Release)
	(rm -rf 39_0/Release)
	(rm -rf 39_1/Release)
	(rm -rf 39_2/Release)
	(rm -rf 39_3/Release)
	(rm -rf 39_4/Release)
	(rm -rf 39_5/Release)
	(rm -rf 39_6/Release)
	(rm -rf 39_7/Release)
	(rm -rf 40_0/Release)
	(rm -rf 40_1/Release)
	(rm -rf 40_2/Release)
	(rm -rf 40_3/Release)
	(rm -rf 40_4/Release)
	(rm -rf 40_5/Release)
	(rm -rf 40_6/Release)
	(rm -rf 40_7/Release)
	(rm -rf 41_0/Release)
	(rm -rf 41_1/Release)
	(rm -rf 41_2/Release)
	(rm -rf 41_3/Release)
	(rm -rf 41_4/Release)
	(rm -rf 41_5/Release)
	(rm -rf 41_6/Release)
	(rm -rf 41_7/Release)
	(rm -rf 42_0/Release)
	(rm -rf 42_1/Release)
	(rm -rf 42_2/Release)
	(rm -rf 42_3/Release)
	(rm -rf 42_4/Release)
	(rm -rf 42_5/Release)
	(rm -rf 42_6/Release)
	(rm -rf 42_7/Release)
	(rm -rf 43_0/Release)
	(rm -rf 43_1/Release)
	(rm -rf 43_2/Release)
	(rm -rf 43_3/Release)
	(rm -rf 43_4/Release)
	(rm -rf 43_5/Release)
	(rm -rf 43_6/Release)
	(rm -rf 43_7/Release)
	(rm -rf 44_0/Release)
	(rm -rf 44_1/Release)
	(rm -rf 44_2/Release)
	(rm -rf 44_3/Release)
	(rm -rf 44_4/Release)
	(rm -rf 44_5/Release)
	(rm -rf 44_6/Release)
	(rm -rf 44_7/Release)
	(rm -rf 45_0/Release)
	(rm -rf 45_1/Release)
	(rm -rf 45_2/Release)
	(rm -rf 45_3/Release)
	(rm -rf 45_4/Release)
	(rm -rf 45_5/Release)
	(rm -rf 45_6/Release)
	(rm -rf 45_7/Release)
	(rm -rf 46_0/Release)
	(rm -rf 46_1/Release)
	(rm -rf 46_2/Release)
	(rm -rf 46_3/Release)
	(rm -rf 46_4/Release)
	(rm -rf 46_5/Release)
	(rm -rf 46_6/Release)
	(rm -rf 46_7/Release)
	(rm -rf 47_0/Release)
	(rm -rf 47_1/Release)
	(rm -rf 47_2/Release)
	(rm -rf 47_3/Release)
	(rm -rf 47_4/Release)
	(rm -rf 47_5/Release)
	(rm -rf 47_6/Release)
	(rm -rf 47_7/Release)
	(rm -rf 48_0/Release)
	(rm -rf 48_1/Release)
	(rm -rf 48_2/Release)
	(rm -rf 48_3/Release)
	(rm -rf 48_4/Release)
	(rm -rf 48_5/Release)
	(rm -rf 48_6/Release)
	(rm -rf 48_7/Release)
	(rm -rf 49_0/Release)
	(rm -rf 49_1/Release)
	(rm -rf 49_2/Release)
	(rm -rf 49_3/Release)
	(rm -rf 49_4/Release)
	(rm -rf 49_5/Release)
	(rm -rf 49_6/Release)
	(rm -rf 49_7/Release)
