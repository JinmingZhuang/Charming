[![DOI](https://zenodo.org/badge/556002569.svg)](https://zenodo.org/badge/latestdoi/556002569)<br/>
# CHARM
## Overview
In this repo, we provide multiple heterogeneous CHARM accelerators on AMD Versal VCK190 platform for general-purpose Matrix-Matrix Multiplication(GEMM) applications including BERT for natural language processing, NCF for recommendations, ViT for vision classification, MLP for multi-layer perceptron classification or regression.

To resolve the inconsistency of massive computation resources on Versal within one monolithic accelerator and various small sizes MM layers in the aforementioned applications, we propose multiple diverse MM accelerator architectures, namely, one monolithic acc, one specilized acc, eight duplicated accs and two diverse accs.

## Dependencies 
To play with the Charming Accelerators, following software and hardware dependencies are required:
+ Linux System with "tar" installed
+ AMD/Xilinx Vitis 2021.1
+ AMD/Xilinx XRT Library
+ AMD/Xilinx VCK190 Evaluation Kit

## Environment Setup <br/>

### 1. To quickly boost and run experiments on the board instead of building the platform and Linux from scratch, users can download the platform package (VCK190 Base 2021.1) and petalinux common image(Versal common image) from the following link:<br/>
https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-platforms/2021-1.html

### 2. Install platform and petalinux
```
unzip xilinx_vck190_base_202110_1.zip
```
```
tar -xf xilinx-versal-common-v2021.1.tar.gz
cd xilinx-versal-common-v2021.1
sh sdk.sh
```

### 3. VCK190 Base 2021.1: It contains the pre-built Versal extensible embedded platform. During compilation users need to specify the platofrm path in the following format.<br/> 
```
PLATFORM = ${PATH}/xilinx_vck190_base_202110_1/xilinx_vck190_base_202110_1.xpfm
```

### 4. Versal common image: It includes the petalinux system boot files and the cross compilation environment needed for ARM CPU. During compilation, users need to point the path to SYSROOT and EDGE_COMMON_SW.<br/>
```
SYSROOT = ${PATH}/sysroots/cortexa72-cortexa53-xilinx-linux
EDGE_COMMON_SW=${PATH}/xilinx-versal-common-v2021.1
```

### 5. Vitis and Cross-compilation Environment Setup<br/>
```
source /opt/tools/xilinx/Vitis/2021.1/settings64.sh
source /opt/xilinx/xrt/setup.sh
unset LD_LIBRARY_PATH (If needed)
source ${PATH}/environment-setup-cortexa72-cortexa53-xilinx-linux
```

## Using Pre-built Design (3-5 Minutes)<br/>

#### As the time for compilation more take several hours, we provide our pre-built hardware configuration and executable files in the design.
### 1. Generate sd_card directly
```
make package PLATFORM=${PATH} SYSROOT=${PATH} EDGE_COMMON_SW=${PATH} PRE_BUILT=1
```

## Compile Charming Accelerators(4-12 Hours)<br/>
#### The compilation processes are the same for all the designs. In the following part we take one monolithic design as an example.<br/>
```
cd one_monolithic
```
### 1. AIE Compilation<br/>
#### The source files of AIE design is in one_monolithic/aie folder, we leverage aiecompiler to generate the libadf.a file. <br/>
```
make aie PLATFORM=${PLATFORM} SYSROOT=${SYSROOT} EDGE_COMMON_SW=${EDGE_COMMON_SW}
```


### 2. Programmable Logic (PL) Compilation<br/>
#### The source files of PL design is in one_monolithic/kernel folder, we leverage Vitis HLS to generate the RTL code and Vitis to generate the bitstream. <br/>
```
make build PLATFORM=${PLATFORM} SYSROOT=${SYSROOT} EDGE_COMMON_SW=${EDGE_COMMON_SW} 
```


### 3. Host Compilation<br/>
#### The source files of PL design is in one_monolithic/host folder, we leverage the cross-compilation tool to generate the executable file that can be run on ARM CPU.<br/>
```
make host PLATFORM=${PLATFORM} SYSROOT=${SYSROOT} EDGE_COMMON_SW=${EDGE_COMMON_SW}
```
### 4. File Package<br/>
#### In this step, we package all the file together to package.hw/sd_card.img including the host executable, xclbin and petalinux boost files.<br/>
``` 
make package PLATFORM=${PLATFORM} SYSROOT=${SYSROOT} EDGE_COMMON_SW=${EDGE_COMMON_SW}
```


## Run Experiments on Board<br/>
### 1. Copy sd_card.img to an micro sd card<br/>
https://docs.xilinx.com/r/en-US/ug1393-vitis-application-acceleration/Writing-Images-to-the-SD-Card

### 2. Execution<br/>
#### When running the program, there are 5 input arguments. The first three are the Matrix size M, K, N standing for MM with size ( M * K ) * ( K * N ). Next arguments stands for the test iteration. Last one is verfigy flag, 0 stands for don't calculate the software(sw) reference result, 1 stands for verifying the sw and hw results. For large MM, it may take more than 30 minutes for the ARM core to compute.
```
cd /mnt/sd-mmcblk0p1
./hostexe mm_hw.xclbin 6144 6144 6144 1 0
```

## Reproduce Experiment Results of the Paper<br/>

### 1. Throughput (GFLOPs) Vs Square Matrix Size (Table.2) <br/>
<img src="https://user-images.githubusercontent.com/77606152/205368353-5ead6274-40c7-479f-93e9-55598dd41805.png" width="450" height="300"> <br/>

#### 1) Prepare sd_card image file using pre-built design (5-10 Minutes) <br/>
```
cd one_monolithic
make package PLATFORM=${PATH} SYSROOT=${PATH} EDGE_COMMON_SW=${PATH} PRE_BUILT=1
```


#### 2) Run script on board and view the results (5-10 Minutes)<br/>
#### a. Copy package.hw/sd_card.img to an micro sd card and boot the board.
#### b. The results shown in the red box of Table 2 should be within ±5% of the on board results.<br/>
```
cd /mnt/sd-mmcblk0p1
sh run_mm.sh
vi Table2.log
```

### 2. End-to-end application caomparison of BERT, ViT NCF and MLP (Figure 7) <br/>
<img src="https://user-images.githubusercontent.com/77606152/205414725-52e8f217-54db-4dcd-8383-9515bbf9f21d.png" width="500" height="300"> <br/>

#### 1. One monolithic design result(Figure 7 Grey Bars)<br/>

#### For one monolithic design since all the application are running on the same hardware configuration, we can simply use one image as above MM test and call different host runtime, for convenience, user can run the following command directly.<br/>
```
sh run_application.sh
vi Figure7_One_Mono.log
```

#### 2. One speacialized design result (Figure 7 Orange Bars)<br/>
#### Here we run each application for 20 times in order to amortize the measurement uncertainty. Following is the example for BERT application, same instruction can be used on other applications. Note that for NCF and MLP applications the hardware design and results are the same as their one monolithic design as shown in Figure 7.

<!-- #### Note that in order to avoid of rebooting the system after running each task, we set myGragh.run(-1) in the host code which makes AIE run forever. Thus, the AIE will not stop automatically, after running each task we should enter "Ctrl + C" to stop the program and run next Application.<br/> -->

```
cd one_special/BERT
make package PLATFORM=${PATH} SYSROOT=${PATH} EDGE_COMMON_SW=${PATH} PRE_BUILT=1
```
#### Copy package.hw/sd_card.img to an micro sd card and boot the board.<br/>
```
sh run_application.sh
vi Figure7_One_Spe.log
```

#### 3. Two diverse design result (Figure 7 Blue Bars)<br/>
#### The test processes of two diverse design are the same as one specialized design<br/>
```
cd two_diverse/BERT
make package PLATFORM=${PATH} SYSROOT=${PATH} EDGE_COMMON_SW=${PATH} PRE_BUILT=1
```
#### Copy package.hw/sd_card.img to an micro sd card and boot the board.<br/>
```
sh run_application.sh
vi Figure7_Two_Div.log
```

#### 4. 8 duplicate design result (Figure 7 Yellow Bars)<br/>
#### All the tasks share the same sd_card.img<br/>
```
cd 8_duplicated
make package PLATFORM=${PATH} SYSROOT=${PATH} EDGE_COMMON_SW=${PATH} PRE_BUILT=1
```

#### Copy package.hw/sd_card.img to an micro sd card and boot the board.<br/>
#### Users can change tasks to vit, ncf, mlp as well
```
sh run_mm.sh bert
vi Figure7_8_duplicate_bert.log
```
**References:**<br>
[1] **[AIE Architecture(AM009 2021.1)](https://docs.xilinx.com/r/en-US/am009-versal-ai-engine)**<br>
[2] **[AIE Instructions and APIs(UG1078 UG1529)](https://www.xilinx.com/htmldocs/aiengine_intrinsics_start.html)**<br>
[3] **[AIE Coding Example(UG1079 2021.1)](https://docs.xilinx.com/r/2021.1-English/ug1079-ai-engine-kernel-coding/Revision-History)**<br>
[4] **[Versal Programming Environment(UG1076 2021.1)](https://docs.xilinx.com/r/2021.1-English/ug1076-ai-engine-environment/Revision-History)**<br>
[5] **[Introduction to FP32 programming of AIE](https://github.com/Xilinx/Vitis-Tutorials/blob/2022.1/AI_Engine_Development/Feature_Tutorials/07-AI-Engine-Floating-Point/README.md)**<br>
