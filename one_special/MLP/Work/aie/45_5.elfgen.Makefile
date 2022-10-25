.PHONY: all 45_5

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
CHESSMK := chessmk
all: 45_5

45_5:
	(${CHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 45_5/scripts/45_5.prx) 2>&1 | tee 45_5/45_5.log
	(coreverify -obj 45_5 -s 4096 -pm 16384)
