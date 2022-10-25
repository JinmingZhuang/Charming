.PHONY: all 6_6

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
CHESSMK := chessmk
all: 6_6

6_6:
	(${CHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 6_6/scripts/6_6.prx) 2>&1 | tee 6_6/6_6.log
	(coreverify -obj 6_6 -s 4096 -pm 16384)
