.PHONY: all 3_6

ifeq ($(XILINX_VITIS_AIETOOLS),)
XILINX_VITIS_AIETOOLS:=${XILINX_VITIS}/aietools
endif
ifeq ($(CARDANO_AIE_ARCH_MODEL_DIR),)
CARDANO_AIE_ARCH_MODEL_DIR := ${XILINX_VITIS_AIETOOLS}/data/versal_prod/lib
endif
CHESSMK := chessmk
all: 3_6

3_6:
	(${CHESSMK} -C Release_LLVM -P ${CARDANO_AIE_ARCH_MODEL_DIR} +P 4  -DDEPLOYMENT_ELF=1  +o ../Release 3_6/scripts/3_6.prx) 2>&1 | tee 3_6/3_6.log
	(coreverify -obj 3_6 -s 4096 -pm 16384)