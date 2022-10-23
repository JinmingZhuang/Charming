# Charming 

## Overview
In this repo, we provide multiple heterogeneous Charming accelerators on AMD Versal VCK190 platform for general-purpose Matrix-Matrix Multiplication(GEMM) applications including BERT for natural language processing, NCF for recommendations, ViT for vision classification, MLP for multi-layer perceptron classification or regression.

To resolve the inconsistency of massive computation resources on Versal within one monolithic accelerator and various small sizes MM layers in the aforementioned applications, we propose multiple diverse MM accelerator architectures, namely, one monolithic acc, one specilized acc, eight duplicated accs and two diverse accs.

## Dependencies 
To play with the Charming Accelerators, following software and hardware dependencies are required:
+ AMD/Xilinx Vitis 2021.1
+ AMD/Xilinx XRT Library
+ AMD/Xilinx VCK190 Evaluation Kit

## Environment Setup
1. To quickly boost and run experiments on the board instead of building the platform and Linux from scratch, users can download the platform package (VCK190 Base 2021.1) and petalinux common image(Versal common image) from the following link:<br/>
https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-platforms/2021-1.html

2. VCK190 Base 2021.1: It contains the pre-built Versal extensible embedded platform. During compilation users need to specify the platofrm path in the following format.<br/> 
```
PLATFORM = ${PATH}/xilinx_vck190_base_202110_1/xilinx_vck190_base_202110_1.xpfm
```

3. Versal common image: It includes the petalinux system boot files and the cross compilation environment needed for ARM CPU. Users can install the petalinux by running ``./sdk.sh``. During compilation, users need to point the path to SYSROOT and EDGE_COMMON_SW.<br/>
```
SYSROOT = ${PATH}/sysroots/cortexa72-cortexa53-xilinx-linux
EDGE_COMMON_SW=${PATH}/xilinx-versal-common-v2021.1
```

4. Vitis and Cross-compilation Environment Setup<br/>
```
source /opt/tools/xilinx/Vitis/2021.1/settings64.sh
source /opt/xilinx/xrt/setup.sh
unset LD_LIBRARY_PATH (If needed)
source ${PATH}/environment-setup-cortexa72-cortexa53-xilinx-linux
```
## Compile Charming Accelerators
The compilation processes are the same for all the designs. In the following part we take one unified/monolithic design as an example.
1. AIE Compilation
```
make aie
```
The source files of AIE design is in one_unified/aie folder, we leverage aiecompiler to generate the libadf.a file. 

2. Programmable Logic (PL) Compilation
```
make build
```
The source files of PL design is in one_unified/kernel folder, we leverage Vitis HLS to generate the RTL code and Vitis to generate the bitstream. 

3. Host Compilation
```
make host
```
The source files of PL design is in one_unified/host folder, we leverage the cross-compilation tool to generate the executable file that can be run on ARM CPU.

4. File Package
```
make package
```
In this step, we package all the file together to package.hw/sd_card.img including the host executable, xclbin and petalinux boost files.

## Run Experiments on Board
1. Copy sd_card.img to an micro sd card
https://docs.xilinx.com/r/en-US/ug1393-vitis-application-acceleration/Writing-Images-to-the-SD-Card

2. Execution
```
cd /mnt/sd-mmcblk0p1
./hostexe mm_hw.xclbin 6144 6144 6144 1 0
```
