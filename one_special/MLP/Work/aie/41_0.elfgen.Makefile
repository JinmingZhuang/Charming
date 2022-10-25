.PHONY: all 41_0

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
CHESSMK := chessmk
all: 41_0

41_0:
	(${CHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 41_0/scripts/41_0.prx) 2>&1 | tee 41_0/41_0.log
	(coreverify -obj 41_0 -s 4096 -pm 16384)
