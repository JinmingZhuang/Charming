/**
* Copyright (C_large) 2019-2021 Xilinx, Inc
*
* Licensed under the Apache License, Version 2.0 (the "License"). You may
* not use this file except in compliance with the License. A_large copy of the
* License is located at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations
* under the License.
*/

#include <iostream>
#include "../aie/mm_top_small.h"
#include "../aie/mm_top_large.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fstream>
#include <time.h>

#include <vector>
#include <math.h>
#include <string>

// This is used for the PL Kernels
#include "xrt/xrt.h"
#include "xrt/experimental/xrt_kernel.h"

// Using the ADF API that call XRT API
#include "adf/adf_api/XRTConfig.h"
mm_x64_x4_graph<0,0> myGraph_large;
mm_x16_x2_graph<33,0> myGraph_small;
static std::vector<char> load_xclbin(xrtDeviceHandle device, const std::string& fnm) {
    if (fnm.empty()) throw std::runtime_error("No xclbin specified");

    // load bit stream
    std::ifstream stream(fnm);
    stream.seekg(0, stream.end);
    size_t size = stream.tellg();
    stream.seekg(0, stream.beg);

    std::vector<char> header(size);
    stream.read(header.data(), size);

    auto top = reinterpret_cast<const axlf*>(header.data());
    if (xrtDeviceLoadXclbin(device, top)) throw std::runtime_error("Xclbin loading failed");

    return header;
}

const int H1=32;
const int W1=32;
const int W2=32;
const int A_large=4;
const int B_large=4;
const int C_large=16;
const int X_large=8;
const int Y_large=1;
const int Z_large=2;
const int A_small=8;
const int B_small=2;
const int C_small=2;
const int X_small=2;
const int Y_small=1;
const int Z_small=1;

const int M_acc1=H1*A_large*X_large;
const int K_acc1=W1*B_large*Y_large;
const int N_acc1=W2*C_large*Z_large;
const int M_acc0=H1*A_small*X_small;
const int K_acc0=W1*B_small*Y_small;
const int N_acc0=W2*C_small*Z_small;


const int DATA_SIZE1=H1*W1;
const int DATA_SIZE2=W1*W2;
const int OUT_SIZE=H1*W2;



int main(int argc, char** argv) {

    int TX_large,TY_large,TZ_large,sel=0;
    int M_large_input=4096,K_large_input=4096,N_large_input=4096;
    int iter=500;
    int TX_small,TY_small,TZ_small;
    int M_small_input=4096,K_small_input=4096,N_small_input=4096;
    int TX_small_AFT=1,TY_small_AFT=1;
    char* xclbinFilename;
    if(argc == 12) {
        xclbinFilename = argv[1];
        if (sscanf (argv[2], "%i", &M_large_input) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[3], "%i", &K_large_input) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[4], "%i", &N_large_input) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[5], "%i", &M_small_input) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[6], "%i", &K_small_input) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[7], "%i", &N_small_input) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[8], "%i", &iter) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[9], "%i", &sel) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[10], "%i", &TX_small_AFT) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[11], "%i", &TY_small_AFT) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        
    }
    
    //////////////////////////////////////////
    // Open xclbin
    //////////////////////////////////////////
    
    auto dhdl = xrtDeviceOpen(0); // Open Device the local device
    if (dhdl == nullptr) throw std::runtime_error("No valid device handle found. Make sure using right xclOpen index.");
    auto xclbin = load_xclbin(dhdl, xclbinFilename);
    auto top = reinterpret_cast<const axlf*>(xclbin.data());
    adf::registerXRT(dhdl, top->m_header.uuid);

    float m_large=(float)(M_large_input)/(float)(M_acc1);
    float k_large=(float)(K_large_input)/(float)(K_acc1);
    float n_large=(float)(N_large_input)/(float)(N_acc1);
    TX_large=ceil(m_large);
    TY_large=ceil(k_large);
    TZ_large=ceil(n_large);
    std::cout << TX_large << TY_large << TZ_large << std::endl;
    

    float m_small=(float)(M_small_input)/(float)(M_acc0);
    float k_small=(float)(K_small_input)/(float)(K_acc0);
    float n_small=(float)(N_small_input)/(float)(N_acc0);
    TX_small=ceil(m_small);
    TY_small=ceil(k_small);
    TZ_small=ceil(n_small);
    std::cout << TX_small << TY_small << TZ_small << std::endl;

    int M_large =TX_large * X_large * A_large * H1;
    int K_large =TY_large * Y_large * B_large * W1;
    int N_large =TZ_large * Z_large * C_large * W2;
    int sizeIn1_large = M_large * K_large;
    int sizeIn2_large = K_large * N_large;
    int sizeOut_large = M_large * N_large;
    
    
    std::vector<std::vector<float>>DataInput0_large(M_large,std::vector<float>(K_large,1.0));
    std::vector<std::vector<float>>DataInput1_large(K_large,std::vector<float>(N_large,1.0));
    std::vector<std::vector<float>>golden_large(M_large,std::vector<float>(N_large,1.0));

    srand (time(0));
    for (int m = 0; m < M_large; m++) {
        for (int k = 0; k < K_large; k++) {
            DataInput0_large[m][k]= (rand()%5)*(float)1.0;
        } 
    }

    srand (time(0));
    for (int k = 0; k < K_large; k++) {
        for (int n = 0; n < N_large; n++) {
            DataInput1_large[k][n]= (rand()%5)*(float)1.0;
        } 
    }

    int M_small =TX_small * X_small * A_small * H1;
    int K_small =TY_small * Y_small * B_small * W1;
    int N_small =TZ_small * Z_small * C_small * W2;
    int sizeIn1_small = M_small * K_small;
    int sizeIn2_small = K_small * N_small;
    int sizeOut_small = M_small * N_small;
    
    
    std::vector<std::vector<float>>DataInput0_small(M_small,std::vector<float>(K_small,1.0));
    std::vector<std::vector<float>>DataInput1_small(K_small,std::vector<float>(N_small,1.0));
    std::vector<std::vector<float>>golden_small(M_small,std::vector<float>(N_small,1.0));

    srand (time(0));
    for (int m = 0; m < M_small; m++) {
        for (int k = 0; k < K_small; k++) {
            DataInput0_small[m][k]= (rand()%5)*(float)1.0;
        } 
    }

    srand (time(0));
    for (int k = 0; k < K_small; k++) {
        for (int n = 0; n < N_small; n++) {
            DataInput1_small[k][n]= (rand()%5)*(float)1.0;
        } 
    }
    
    //Allocate input mem
    xrtBufferHandle in_bohdl0_large = xrtBOAlloc(dhdl, sizeIn1_large * sizeof(float), 0, 0);
    auto in_bomapped0_large = reinterpret_cast<float*>(xrtBOMap(in_bohdl0_large));


    xrtBufferHandle in_bohdl1_large = xrtBOAlloc(dhdl, sizeIn2_large * sizeof(float), 0, 0);
    auto in_bomapped1_large = reinterpret_cast<float*>(xrtBOMap(in_bohdl1_large));
    
    for (int m = 0; m < M_large; m++) {
        for (int k = 0; k < K_large; k++) {
            in_bomapped0_large[m+k*M_large]=DataInput0_large[m][k];
        } 
    }

    for (int k = 0; k < K_large; k++) {
        for (int n = 0; n < N_large; n++) {
            in_bomapped1_large[k+n*K_large]=DataInput1_large[k][n];
        } 
    }
    
    //Allocate input mem
    xrtBufferHandle in_bohdl0_small = xrtBOAlloc(dhdl, sizeIn1_small * sizeof(float), 0, 0);
    auto in_bomapped0_small = reinterpret_cast<float*>(xrtBOMap(in_bohdl0_small));


    xrtBufferHandle in_bohdl1_small = xrtBOAlloc(dhdl, sizeIn2_small * sizeof(float), 0, 0);
    auto in_bomapped1_small = reinterpret_cast<float*>(xrtBOMap(in_bohdl1_small));

    
    for (int m = 0; m < M_small; m++) {
        for (int k = 0; k < K_small; k++) {
            in_bomapped0_small[m+k*M_small]=DataInput0_small[m][k];
        } 
    }

    for (int k = 0; k < K_small; k++) {
        for (int n = 0; n < N_small; n++) {
            in_bomapped1_small[k+n*K_small]=DataInput1_small[k][n];
        } 
    }
    

    // sync input memory
    xrtBOSync(in_bohdl0_large, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn1_large* sizeof(float),0);
    xrtBOSync(in_bohdl1_large, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn2_large* sizeof(float),0);
    
    // sync input memory
    xrtBOSync(in_bohdl0_small, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn1_small* sizeof(float),0);
    xrtBOSync(in_bohdl1_small, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn2_small* sizeof(float),0);

    //Allocate output buffer
    float *out_bomapped_large; 
    xrtBufferHandle out_bohdl_large; 

    out_bohdl_large = xrtBOAlloc(dhdl, sizeOut_large* sizeof(float), 0, 0);
    out_bomapped_large = reinterpret_cast<float*>(xrtBOMap(out_bohdl_large));

    //Allocate output buffer
    float *out_bomapped_small; 
    xrtBufferHandle out_bohdl_small; 

    xrtBufferHandle out_bohdl0_small_reshape = xrtBOAlloc(dhdl, sizeIn1_small * sizeof(float), 0, 0);
    auto out_bomapped0_small_reshape = reinterpret_cast<float*>(xrtBOMap(out_bohdl0_small_reshape));

    out_bohdl_small = xrtBOAlloc(dhdl, sizeOut_small* sizeof(float), 0, 0);
    out_bomapped_small = reinterpret_cast<float*>(xrtBOMap(out_bohdl_small));

    myGraph_large.init();
    myGraph_small.init();                         
    
    myGraph_large.run(-1);
    printf("graph_large run\n");
    myGraph_small.run(-1); 
    printf("graph_small run\n");


    std::cout << "Kernel run\n";
    xrtKernelHandle dma_khdl_large = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma_large");
    xrtRunHandle dma_rhdl_large;

    xrtKernelHandle dma_khdl_small = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma_small");
    xrtRunHandle dma_rhdl_small;

    xrtKernelHandle reshape_khdl = xrtPLKernelOpen(dhdl, top->m_header.uuid, "reshape:{reshape_1}");
    xrtRunHandle reshape_rhdl;

    //profile aie mm 
    double kernel_time_in_sec = 0;
    std::chrono::duration<double> kernel_time(0);
    auto kernel_start = std::chrono::high_resolution_clock::now();
    
    double kernel_time_in_sec0 = 0;
    std::chrono::duration<double> kernel_time0(0);

    double kernel_time_in_sec1 = 0;
    std::chrono::duration<double> kernel_time1(0);

    double kernel_time_in_sec_reshape = 0;
    std::chrono::duration<double> kernel_time2(0);
    if(sel==0){

        for (int i=0;i<iter;i++){
            // start input kernels run handles
            dma_rhdl_large = xrtKernelRun(dma_khdl_large, in_bohdl0_large, in_bohdl1_large,out_bohdl_large,TX_large,TY_large,TZ_large,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//A_large 16
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//B_large 32
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);// C_large 16

            dma_rhdl_small = xrtKernelRun(dma_khdl_small, in_bohdl0_small, in_bohdl1_small,out_bohdl_small,TX_small,TY_small,TZ_small,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//A_small 8
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//B_small 8
                                nullptr, nullptr, nullptr, nullptr);// C_small 4

            //////////////////////////////////////////
            //Wait for kernel finish
            xrtRunWait(dma_rhdl_large);
            xrtRunWait(dma_rhdl_small);
        }
    }
    else if(sel==1){
        for (int i=0;i<iter;i++){
            // start input kernels run handles
            
            auto kernel_start0 = std::chrono::high_resolution_clock::now();
            dma_rhdl_large = xrtKernelRun(dma_khdl_large, in_bohdl0_large, in_bohdl1_large,out_bohdl_large,TX_large,TY_large,TZ_large,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//A_large 16
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//B_large 32
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);// C_large 16
            
            
            auto kernel_start1 = std::chrono::high_resolution_clock::now();
            dma_rhdl_small = xrtKernelRun(dma_khdl_small, in_bohdl0_small, in_bohdl1_small,out_bohdl_small,TX_small,TY_small,TZ_small,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//A_small 8
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr,//B_small 8
                                nullptr, nullptr, nullptr, nullptr);// C_small 4

            


            //////////////////////////////////////////
            //Wait for kernel finish
            xrtRunWait(dma_rhdl_large);
            auto kernel_end0 = std::chrono::high_resolution_clock::now();
            kernel_time0 = std::chrono::duration<double>(kernel_end0 - kernel_start0);
            kernel_time_in_sec0 += kernel_time0.count();
            xrtRunWait(dma_rhdl_small);
            auto kernel_end1 = std::chrono::high_resolution_clock::now();
            kernel_time1 = std::chrono::duration<double>(kernel_end1 - kernel_start1);
            kernel_time_in_sec1 += kernel_time1.count();
        }
    }
    else if (sel==2){
        for (int i=0;i<iter;i++){
            // start input kernels run handles
            auto kernel_start2 = std::chrono::high_resolution_clock::now();
            reshape_rhdl = xrtKernelRun(reshape_khdl, in_bohdl0_small, out_bohdl0_small_reshape, M_acc0, K_acc0, TX_small, TY_small, TX_small_AFT, TY_small_AFT);
            xrtRunWait(reshape_rhdl);
            auto kernel_end2 = std::chrono::high_resolution_clock::now();
            kernel_time2 = std::chrono::duration<double>(kernel_end2 - kernel_start2);
            kernel_time_in_sec_reshape += kernel_time2.count();
        }
    }
 
    auto kernel_end = std::chrono::high_resolution_clock::now();
    kernel_time = std::chrono::duration<double>(kernel_end - kernel_start);
    kernel_time_in_sec = kernel_time.count();
    double OPS_large = (double)(M_large * K_large) * (double) (N_large * 2 *iter* 1e-9);
    double OPS_small = (double)(M_small * K_small) * (double) (N_small * 2 *iter* 1e-9);
    double TOPS= (OPS_large+OPS_small)/kernel_time_in_sec;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "MM_alrge Size:"<< M_large << "*" << K_large << "*" << N_large << std::endl;
    std::cout << "MM_small Size:"<< M_small << "*" << K_small << "*" << N_small << std::endl;
    std::cout << "Total time is: "<< kernel_time_in_sec <<"s, TOPS = " << TOPS << " GOPS/s" << std::endl;
    if(sel==1){
        double TOPS_Acc0= OPS_large/kernel_time_in_sec0;
        double TOPS_Acc1= OPS_small/kernel_time_in_sec1;
        std::cout << "The time of Acc0 is : "<< kernel_time_in_sec0 <<"s, TOPS_ACC0 = " << TOPS_Acc0 << " GOPS/s" << std::endl;
        std::cout << "The time of Acc1 is : "<< kernel_time_in_sec1 <<"s, TOPS_Acc1 = " << TOPS_Acc1 << " GOPS/s" << std::endl;
    }
    if(sel==2){
        double TOPS_reshape= sizeIn1_small * sizeof(float) /kernel_time_in_sec_reshape;
        std::cout << "The time of reshape is : "<< kernel_time_in_sec_reshape <<"s, TOPS_reshape = " << TOPS_reshape << " GB/s" << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // sync output memory
    xrtBOSync(out_bohdl_large, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut_large* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(out_bohdl_small, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut_small* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(out_bohdl0_small_reshape, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut_small* sizeof(float),/*OFFSET=*/ 0);

    xrtRunClose(dma_rhdl_large);
    xrtRunClose(dma_rhdl_small);
    xrtKernelClose(dma_khdl_large);
    xrtKernelClose(dma_khdl_small);
    xrtRunClose(reshape_rhdl);
    xrtRunClose(reshape_khdl);
    
    ////////////////////////////////////////////
    //// Comparing the execution data to the golden_large data
    ////////////////////////////////////////////
    
    

    for (int m = 0; m < M_small; m++) {
        for (int n = 0; n < N_small; n++) {
            golden_small[m][n]=0;
        } 
    }



    for (int m = 0; m < M_large; m++) {
        for (int n = 0; n < N_large; n++) {
            golden_large[m][n]=0;
        } 
    }

    for (int m = 0; m < M_small; m++) {
        for (int n = 0; n < N_small; n++) {
            golden_small[m][n]=0;
        } 
    }

    {
        float sum = 0;
        for (int m = 0; m < M_large; m++) {
            for (int n = 0; n < N_large; n++) {
                sum =0;
                for (int k = 0; k < K_large; k++) {
                    sum=sum+DataInput0_large[m][k]*DataInput1_large[k][n];
                }
                golden_large[m][n]=sum;
            } 
        }

        for (int m = 0; m < M_small; m++) {
            for (int n = 0; n < N_small; n++) {
                sum =0;
                for (int k = 0; k < K_small; k++) {
                    sum=sum+DataInput0_small[m][k]*DataInput1_small[k][n];
                }
                golden_small[m][n]=sum;
            } 
        }
    }

    int errorCount = 0;
    {   
        if(sel!=2){
            for (int m = 0; m < M_large; m++) {
                for (int n = 0; n < N_large; n++) {
                    if(abs((float)(out_bomapped_large[m+n*M_large])-golden_large[m][n])>=1e-3){
                        printf("Error found out_bomapped_large[%d][%d]!=golden_large[%d][%d], %f!=%f \n", m,n,m,n,out_bomapped_large[m+n*M_large],golden_large[m][n]);
                        errorCount++;
                    }
                } 
            }

            for (int m = 0; m < M_small; m++) {
                for (int n = 0; n < N_small; n++) {
                    if(abs((float)(out_bomapped_small[m+n*M_small])-golden_small[m][n])>=1e-3){
                        printf("Error found out_bomapped_small[%d][%d]!=golden_small[%d][%d], %f!=%f \n", m,n,m,n,out_bomapped_small[m+n*M_small],golden_small[m][n]);
                        errorCount++;
                    }
                } 
            }
        }
        else{
            for(int tx=0;tx<TX_small;tx++){
                for(int ty=0;ty<TY_small;ty++){
                    for(int k=0;k<K_acc0;k++){
                        for(int m=0;m<M_acc0;m++){
                            int total_tile=ty+tx*TY_small;
                            int ty_aft=total_tile%TY_small_AFT;
                            int tx_aft=total_tile/TY_small_AFT;
                            if(abs((float)(DataInput0_large[m+tx*M_acc0][k+ty*K_acc0])-out_bomapped0_small_reshape[m+k*M_acc0+ty_aft*K_acc0*M_acc0*TX_small_AFT+tx_aft*M_acc0])>=1e-3){
                                errorCount++;
                            }
                        }
                    }
                }
            }
        }
        if (errorCount)
            printf("Test failed with %d errors\n", errorCount);
        else
            printf("TEST PASSED\n");
    }

    //////////////////////////////////////////
    // clean up XRT
    //////////////////////////////////////////

    std::cout << "Releasing remaining XRT objects...\n";
    
    
    xrtBOFree(in_bohdl0_large);
    xrtBOFree(in_bohdl1_large);
    xrtBOFree(in_bohdl0_small);
    xrtBOFree(in_bohdl1_small);
    xrtBOFree(out_bohdl_small);
    xrtBOFree(out_bohdl_large);
    xrtBOFree(out_bohdl0_small_reshape);
    xrtDeviceClose(dhdl);
    return 0;
}
