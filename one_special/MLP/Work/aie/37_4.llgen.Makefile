.PHONY: all 37_4

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
CHESSCC := chesscc

INCLUDE_PATH := -I ../.. -I ${XILINX_VITIS_AIETOOLS}/include -I /var/tmp/Jinming/Charming/one_special/MLP/aie -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime_cxx/libcxx-lite/include -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime_cxx/libs/libcxx-9.0.0/include-lite -I ${CARDANO_AIE_ARCH_MODEL_DIR}/runtime/include

.EXPORT_ALL_VARIABLES:
export XILINX_CARDANO_XLOPT_OPTIONS=-xlopt=1 -mapped-json=mm_top_mapped.json

all: 37_4_xlopt 37_4_llopt

37_4_xlopt:
	${CHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/37_4/src/37_4.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K0_mm_kernel0.ll -o ir/37_4_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/37_4_orig.ll -o ir/37_4.ll 2>37_4/xlopt.log;

37_4_llopt: 37_4_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/37_4.ll -o ir/37_4.ll 2>/dev/null;
