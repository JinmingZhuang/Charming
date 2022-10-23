#
#Copyright 2020 Xilinx, Inc.
#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.
#You may obtain a copy of the License at
#    http://www.apache.org/licenses/LICENSE-2.0
#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions and
#limitations under the License.
#
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
TARGET   = hw
MODE	 = linux
HOST_ARCH = aarch64
PLATFORM_REPO_PATHS=/opt/xilinx/platforms
PLATFORM = ${PLATFORM_REPO_PATHS}/xilinx_vck190_base_202110_1/xilinx_vck190_base_202110_1.xpfm
XCLBIN   = vck190_aie_base_graph_${TARGET}.xclbin
XSA	 = vck190_aie_base_graph_${TARGET}.xsa
XPFM	 = vck190_xpfm
HOST_EXE = hostexe
HOST_SRCS := ./host/host.cpp
SDKTARGETSYSROOT = ${SYSROOT}
ROOTFS=${EDGE_COMMON_SW}/rootfs.ext4
IMAGE=${EDGE_COMMON_SW}/Image

FINAL_XCLBIN=mm_${TARGET}.xclbin
TEMP_DIR := ./_x.$(TARGET).xilinx_vck190_base_202110_1
BUILD_DIR := ./build_dir.$(TARGET).xilinx_vck190_base_202110_1

KERNEL_XO := $(TEMP_DIR)/dma.xo
GRAPH    = aie/mm_top.cpp
LIBADF  = libadf.a
AIE_CMPL_CMD = aiecompiler -platform=${PLATFORM} --target=hw --stacksize=4096 -include="./aie" -workdir=./Work ${GRAPH} #-v
AIE_SIM_CMD = aiesimulator --pkg-dir=./Work --dump-vcd foo --profile
EMU_CMD = ./launch_hw_emu.sh
PACKAGE_OUT = ./package.$(TARGET)
RM = rm -f
RMDIR = rm -rf
##########################################################################################################################################################
### DO NOT MODIFY BELOW THIS LINE UNLESS NECESSARY
################################################################################################################################################

CUR_DIR := $(patsubst %/,%,$(dir $(MK_PATH)))
XFLIB_DIR_REL_PATH :=/share/Jinming/research/vitis_template/Vitis_Libraries/utils
XFLIB_DIR := $(shell readlink -f $(XFLIB_DIR_REL_PATH))

BINARY_CONTAINERS += $(BUILD_DIR)/${XCLBIN}
VCC      = v++
VPP_XO_FLAGS += -c --platform $(PLATFORM) --save-temps --optimize 2 -g
VPP_XO_FLAGS += --hls.jobs 8
VPP_XO_FLAGS += -I$(XFLIB_DIR)/L1/include
VPP_XO_FLAGS += -I$(XFLIB_DIR)/L1/include/hw
VPP_XO_FLAGS += -I$(CUR_DIR)/kernel


GCC_FLAGS := -Wall -c \
			 -std=c++14 \
			 -Wno-int-to-pointer-cast \
			 --sysroot=$(SYSROOT) \

GCC_INCLUDES := -I$(SYSROOT)/usr/include/xrt \
				-I./  \
				-I${XILINX_VITIS}/aietools/include \
				-I${XILINX_VITIS}/include \
				-I./aie
				#-I$(SYSROOT)/usr/include \


GCC_LIB := -lxaiengine -ladf_api_xrt -lxrt_core -lxrt_coreutil \
		   -L$(SYSROOT)/usr/lib \
		   --sysroot=$(SYSROOT) \
		   -L${XILINX_VITIS}/aietools/lib/aarch64.o


CXX := $(XILINX_VITIS)/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-g++


CLFLAGS += -t $(TARGET) --platform $(PLATFORM) --save-temps --optimize 2
ifneq ($(TARGET), hw)
	CLFLAGS += -g
endif
CLFLAGS += --hls.jobs 8
CLFLAGS += --config ./conn.cfg
CLFLAGS += --clock.defaultFreqHz 230000000

LDCLFLAGS := --vivado.synth.jobs 8 --vivado.impl.jobs 8

.PHONY: clean

###
# Guarding Checks. Do not modify.
###
check_defined = \
	$(strip $(foreach 1,$1, \
		$(call __check_defined,$1,$(strip $(value 2)))))

__check_defined = \
	$(if $(value $1),, \
		$(error Undefined $1$(if $2, ($2))))

guard-PLATFORM_REPO_PATHS:
	$(call check_defined, PLATFORM_REPO_PATHS, Set your where you downloaded xilinx_vck190_es1_base_202110_1)

guard-ROOTFS:
	$(call check_defined, ROOTFS, Set to: xilinx-versal-common-v2021.1/rootfs.ext4)

guard-IMAGE:
	$(call check_defined, IMAGE, Set to: xilinx-versal-common-v2021.1/Image)

guard-CXX:
	$(call check_defined, CXX, Run: xilinx-versal-common-v2021.1/environment-setup-cortexa72-cortexa53-xilinx-linux)

guard-SDKTARGETSYSROOT:
	$(call check_defined, SDKTARGETSYSROOT, Run: xilinx-versal-common-v2021.1/environment-setup-cortexa72-cortexa53-xilinx-linux)

###

all: aie build host package
run: all run_hw_emu
sd_card: all

aie: guard-PLATFORM_REPO_PATHS ${LIBADF}
${LIBADF}: ${GRAPH}
	${AIE_CMPL_CMD}
	@echo "COMPLETE: aie success."

aiesim: ${LIBADF}
	${AIE_SIM_CMD}
	@echo "COMPLETE: aiesim success."

kernels:$(KERNEL_XO)
$(TEMP_DIR)/dma.xo: kernel/dma.cpp kernel/packet_sender.hpp
	mkdir -p $(TEMP_DIR)
	$(VCC) $(VPP_XO_FLAGS) -k dma --hls.clock 300000000:dma $< -o $@ | tee $(TEMP_DIR)/dma.log
	@echo "### ***** dma compilation done! *****"


build: $(BINARY_CONTAINERS)
$(BUILD_DIR)/${XCLBIN}: ${KERNEL_XO} ${LIBADF}
	mkdir -p $(BUILD_DIR)
	v++ -l $(CLFLAGS) --temp_dir $(BUILD_DIR) $(LDCLFLAGS) -o'$@' $(+) | tee $(BUILD_DIR)/hpc_xclbin.log


host: guard-CXX guard-SDKTARGETSYSROOT ${HOST_EXE}
${HOST_EXE}:
	$(CXX) -g $(GCC_FLAGS) $(GCC_INCLUDES) -o aie_control_xrt.o ./Work/ps/c_rts/aie_control_xrt.cpp
	$(CXX) -g $(HOST_SRCS) $(GCC_FLAGS) $(GCC_INCLUDES) -o main.o
	$(CXX) -g *.o $(GCC_LIB) -o $(HOST_EXE)
	@echo "COMPLETE: Host application created."

ECHO:= @echo
gen_run_app:
ifneq ($(HOST_ARCH), x86)
	rm -rf run_app.sh
	$(ECHO) 'export LD_LIBRARY_PATH=/mnt:/tmp:$$LD_LIBRARY_PATH' >> run_app.sh
	$(ECHO) 'export PATH=$$PATH:/sbin' >> run_app.sh
	$(ECHO) 'export XILINX_XRT=/usr' >> run_app.sh
ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	$(ECHO) 'export XILINX_VITIS=$$PWD' >> run_app.sh
	$(ECHO) 'export XCL_EMULATION_MODE=$(TARGET)' >> run_app.sh
endif
	$(ECHO) 'dmesg -n 4 && echo "Hide DRM messages..."' >> run_app.sh
	$(ECHO) './${HOST_EXE} ${FINAL_XCLBIN}' >> run_app.sh
	$(ECHO) 'return_code=$$?' >> run_app.sh
	$(ECHO) 'if [ $$return_code -ne 0 ]; then' >> run_app.sh
	$(ECHO) 'echo "ERROR: host run failed, RC=$$return_code"' >> run_app.sh
	$(ECHO) 'fi' >> run_app.sh
	$(ECHO) 'echo "INFO: host run completed."' >> run_app.sh
endif

package: guard-ROOTFS guard-IMAGE guard-PLATFORM_REPO_PATHS package_${TARGET}
package_${TARGET}: ${LIBADF} ${BINARY_CONTAINERS} host gen_run_app
	${VCC} -p -t ${TARGET} -f ${PLATFORM} \
		--package.out_dir $(PACKAGE_OUT) \
		--package.rootfs ${ROOTFS} \
		--package.kernel_image ${IMAGE} \
		--package.boot_mode=sd \
		--package.image_format=ext4 \
		--package.defer_aie_run \
		--package.sd_file run_app.sh \
		--package.sd_file ${HOST_EXE} ${LIBADF} ${BINARY_CONTAINERS} -o ${FINAL_XCLBIN}
	@echo "COMPLETE: Package created."

run_hw_emu: launch_hw_emu.sh
launch_hw_emu.sh: package_hw_emu
	$(EMU_CMD)

clean:
	-$(RMDIR) $(HOST_EXE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) profile_* TempConfig system_estimate.xtxt *.rpt *.csv *.o *.xo *.xpe *.xsa cfg qemu_dts_files emu_qemu_scripts *.db sim  #*.a  Work aie/*.ll _x*
	-$(RMDIR)  *v++* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb *bin* *summary* *.BIN *.bif *.exe  *.log *.txt 

cleanall: clean
	-$(RMDIR) build_dir* sd_card*
	-$(RMDIR) package.hw run_app.sh 
	-$(RMDIR) *xclbin.run_summary qemu-memory-_* emulation _vimage pl* start_simulation.sh *.xclbin
	$(MAKE) -C sw clean

cleansim:
	-$(RMDIR) aiesimulator_output foo.vcd ISS_RPC_SERVER_PORT
cleantemp:
	-$(RMDIR) ${TEMP_DIR}
cleanpac:
	-$(RMDIR) hostexe aie_control_xrt.o main.o mm_${TARGET}.xclbin mm_${TARGET}.xclbin.package_summary package.${TARGET}
