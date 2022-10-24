[![DOI](https://zenodo.org/badge/556002569.svg)](https://zenodo.org/badge/latestdoi/556002569)<br/>
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
## Compile Charming Accelerators<br/>
The compilation processes are the same for all the designs. In the following part we take one unified/monolithic design as an example.<br/>
1. AIE Compilation<br/>
```
make aie PLATFORM=${PATH} 
```
The source files of AIE design is in one_unified/aie folder, we leverage aiecompiler to generate the libadf.a file. <br/>

2. Programmable Logic (PL) Compilation<br/>
```
make build PLATFORM=${PATH} 
```
The source files of PL design is in one_unified/kernel folder, we leverage Vitis HLS to generate the RTL code and Vitis to generate the bitstream. <br/>

3. Host Compilation<br/>
```
make host SYSROOT=${PATH} EDGE_COMMON_SW=${PATH}
```
The source files of PL design is in one_unified/host folder, we leverage the cross-compilation tool to generate the executable file that can be run on ARM CPU.<br/>

4. File Package<br/>
```
make package
```
In this step, we package all the file together to package.hw/sd_card.img including the host executable, xclbin and petalinux boost files.<br/>

## Run Experiments on Board<br/>
1. Copy sd_card.img to an micro sd card<br/>
https://docs.xilinx.com/r/en-US/ug1393-vitis-application-acceleration/Writing-Images-to-the-SD-Card

2. Execution<br/>
```
cd /mnt/sd-mmcblk0p1
./hostexe mm_hw.xclbin 6144 6144 6144 1 0
```
## Reproduce Experiment Results of the Paper<br/>
![image](https://user-images.githubusercontent.com/77606152/197424370-bc03e3f3-cc04-4876-85ec-a59a006b7319.png)<br/>
After copying the corresponding sd_card.img and booting the board, please run the following commands to reproduce the experiment result presented in the paper. <br/>

#### 1. One unified/monolithic design result<br/>
A) Single GEMM Throughput of One Monolithic Design (Table 2)<br/>
```
./run_mm.sh
vim Table2.log
```

B) Throughput of MMs in BERT,ViT, NCF and MLP (Figure 7 Grey Bars)<br/>
```
./host{bert,vit,ncf,mlp} mm_hw.xclbin 100 0
```

#### 2. 8 duplicate design result (Figure 7 Yellow Bars)<br/>
```
./host{bert,vit,ncf,mlp} mm_hw.xclbin 100 0
```

#### 3. One speacialized design result (Figure 7 Orange Bars)<br/>
Copy the image of each design in "one_special" folder into sd_card and boot the system<br/>
```
./host{bert,vit,ncf,mlp} mm_hw.xclbin 100 0
```

#### 4. Two diverse design result (Figure 7 Blue Bars)<br/>
Copy the image of each design in "two_diverse" folder into sd_card and boot the system<br/>
```
./host{bert,vit,ncf,mlp} mm_hw.xclbin 100 0
```

#### 5. Time breakdown result(Table 4 Bert column)<br/>
Copy the image of each design in "overall system" folder into sd_card and boot the system<br/>
```
./host{bert,vit,ncf,mlp} mm_hw.xclbin 100 0
```
