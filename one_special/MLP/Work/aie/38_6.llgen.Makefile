.PHONY: all 38_6

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

all: 38_6_xlopt 38_6_llopt

38_6_xlopt:
	${CHESSCC} +f +s -p me -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  +Wllvm,-O2,-fno-jump-tables,-fno-discard-value-names,-mllvm,-chess-collapse-struct-types-during-linking=0,-Xclang,-disable-llvm-passes,-g -D__AIENGINE__ -D__AIEARCH__=1 ${INCLUDE_PATH} /var/tmp/Jinming/Charming/one_special/MLP/Work/aie/38_6/src/38_6.cc +Wllvm,-Xclang,-mlink-bitcode-file,-Xclang,ir/K1_mm_kernel1.ll -o ir/38_6_orig.ll;
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S -load-pass-plugin=${XILINX_VITIS_AIETOOLS}/lib/lnx64.o/libLLVMXLOpt.so -passes=xlopt ir/38_6_orig.ll -o ir/38_6.ll 2>38_6/xlopt.log;

38_6_llopt: 38_6_xlopt
	${XILINX_VITIS_AIETOOLS}/lnx64.o/tools/clang/bin/opt -S ir/38_6.ll -o ir/38_6.ll 2>/dev/null;