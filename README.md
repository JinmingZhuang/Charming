# Charming 

In this repo, we provide multiple heterogeneous Charming accelerators on AMD Versal VCK190 platform for general-purpose Matrix-Matrix Multiplication(GEMM) applications including BERT for natural language processing, NCF for recommendations, ViT for vision classification, MLP for multi-layer perceptron classification or regression.

To resolve the inconsistency of massive computation resources on Versal within one monolithic accelerator and various small sizes MM layers in the aforementioned applications, we propose multiple diverse MM accelerator architectures, namely, one monolithic acc, one specilized acc, eight duplicated accs and two diverse accs.

To play with the Charming Accelerators, following software and hardware dependencies are required:
+ AMD/Xilinx Vitis 2021.1
+ AMD/Xilinx XRT Library
+ AMD/Xilinx VCK190 Evaluation Kit

To quickly boost and run experiment on the board, users can download the platform package (VCK190 Base 2021.1) and petalinux common image(Versal common image) from the following link:
https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-platforms/2021-1.html

Following instructions are helpful for setting up the broad:
https://xilinx.github.io/vck190-base-trd/2021.1/html/run/run-setup.html
