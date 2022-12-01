/**
* Copyright (C) 2019-2021 Xilinx, Inc
*
* Licensed under the Apache License, Version 2.0 (the "License"). You may
* not use this file except in compliance with the License. A copy of the
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <math.h>
#include <string>
#include "../aie/mm_top.h"

// This is used for the PL Kernels
#include "xrt/xrt.h"
#include "xrt/experimental/xrt_kernel.h"

// Using the ADF API that call XRT API
#include "adf/adf_api/XRTConfig.h"
mm_x8_x4_graph<6,0>  myGraph0;
mm_x8_x4_graph<10,0> myGraph1;
mm_x8_x4_graph<14,0> myGraph2;
mm_x8_x4_graph<18,0> myGraph3;
mm_x8_x4_graph<22,0> myGraph4;
mm_x8_x4_graph<26,0> myGraph5;
mm_x8_x4_graph<30,0> myGraph6;
mm_x8_x4_graph<34,0> myGraph7;
using namespace std;
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

const int PACKET_NUM=4; 
const int H1=32;
const int W1=32;
const int W2=32;
const int A=2;
const int B=4;
const int C=4;
const int X=4;
const int Y=1;
const int Z=2;



const int DATA_SIZE1=H1*W1;
const int DATA_SIZE2=W1*W2;
const int OUT_SIZE=H1*W2;



int main(int argc, char** argv) {

    int TX,TY,TZ;
    int M1=4096,K1=4096,N1=4096;
    int iter=500,verify=0;
    char* xclbinFilename;
    if(argc == 7) {
        xclbinFilename = argv[1];
        if (sscanf (argv[2], "%i", &M1) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[3], "%i", &K1) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[4], "%i", &N1) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[5], "%i", &iter) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[6], "%i", &verify) != 1) {
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

    float temp_m=(float)(M1)/(float)(X*A*H1);
    float temp_k=(float)(K1)/(float)(Y*B*W1);
    float temp_n=(float)(N1)/(float)(Z*C*W2);
    TX=ceil(temp_m);
    TY=ceil(temp_k);
    TZ=ceil(temp_n);
    std::cout << TX << TY << TZ << std::endl;
    int M =TX * X * A * H1;
    int K =TY * Y * B * W1;
    int N =TZ * Z * C * W2;
    int sizeIn1 = M * K;
    int sizeIn2 = K * N;
    int sizeOut = M * N;
    
    
    std::vector<std::vector<float>>DataInput0(M,std::vector<float>(K,1.0));
    std::vector<std::vector<float>>DataInput1(K,std::vector<float>(N,1.0));
    std::vector<std::vector<float>>golden(M,std::vector<float>(N,1.0));



    srand (time(0));
    for (int m = 0; m < M; m++) {
        for (int k = 0; k < K; k++) {
            DataInput0[m][k]= (rand()%5)*(float)1.0;
        } 
    }

    srand (time(0));
    for (int k = 0; k < K; k++) {
        for (int n = 0; n < N; n++) {
            DataInput1[k][n]= (rand()%5)*(float)1.0;
        } 
    }
    
    //layer0
    xrtBufferHandle bohdl_layer0_in0 = xrtBOAlloc(dhdl, sizeIn1 * sizeof(float), 0, 0);
    auto bomapped_layer0_in0 = reinterpret_cast<float*>(xrtBOMap(bohdl_layer0_in0));
    xrtBufferHandle bohdl_layer0_in1 = xrtBOAlloc(dhdl, sizeIn2 * sizeof(float), 0, 0);
    auto bomapped_layer0_in1 = reinterpret_cast<float*>(xrtBOMap(bohdl_layer0_in1));


    
        //layer0
    for (int m = 0; m < M; m++) {
        for (int k = 0; k < K; k++) {
            bomapped_layer0_in0[m+k*M]=DataInput0[m][k];
        }
    }
    for (int k = 0; k < K; k++) {
        for (int n = 0; n < N; n++) {
            bomapped_layer0_in1[k+n*K]=DataInput1[k][n];
        }
    }

    
    
    //layer0
    xrtBOSync(bohdl_layer0_in0, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn1* sizeof(float),0);
    xrtBOSync(bohdl_layer0_in1, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn2* sizeof(float),0);

    
    //layer0
    xrtBufferHandle bohdl_layer0_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer0_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer0_out));

    //layer1
    xrtBufferHandle bohdl_layer1_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer1_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer1_out));

    //layer2
    xrtBufferHandle bohdl_layer2_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer2_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer2_out));

    //layer3
    xrtBufferHandle bohdl_layer3_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer3_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer3_out));

    //layer4
    xrtBufferHandle bohdl_layer4_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer4_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer4_out));

    //layer5
    xrtBufferHandle bohdl_layer5_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer5_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer5_out));

    //layer6
    xrtBufferHandle bohdl_layer6_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer6_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer6_out));

    //layer7
    xrtBufferHandle bohdl_layer7_out = xrtBOAlloc(dhdl, sizeOut * sizeof(float), 0, 0);
    auto bomapped_layer7_out = reinterpret_cast<float*>(xrtBOMap(bohdl_layer7_out));
    
    myGraph0.init();
    myGraph1.init();
    myGraph2.init();
    myGraph3.init();
    myGraph4.init();
    myGraph5.init();
    myGraph6.init();
    myGraph7.init();
                              
    printf("graph run\n");
    myGraph0.run(-1);
    myGraph1.run(-1);
    myGraph2.run(-1);
    myGraph3.run(-1);
    myGraph4.run(-1);
    myGraph5.run(-1);
    myGraph6.run(-1);
    myGraph7.run(-1);


    std::cout << "Kernel run\n";
    xrtKernelHandle dma_khdl0 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_0}");
    xrtKernelHandle dma_khdl1 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_1}");
    xrtKernelHandle dma_khdl2 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_2}");
    xrtKernelHandle dma_khdl3 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_3}");
    xrtKernelHandle dma_khdl4 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_4}");
    xrtKernelHandle dma_khdl5 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_5}");
    xrtKernelHandle dma_khdl6 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_6}");
    xrtKernelHandle dma_khdl7 = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma:{dma_7}");

    xrtRunHandle dma_rhdl0;
    xrtRunHandle dma_rhdl1;
    xrtRunHandle dma_rhdl2;
    xrtRunHandle dma_rhdl3;
    xrtRunHandle dma_rhdl4;
    xrtRunHandle dma_rhdl5;
    xrtRunHandle dma_rhdl6;
    xrtRunHandle dma_rhdl7;
    //profile aie mm 


    double kernel_time_in_sec = 0;
    std::chrono::duration<double> kernel_time(0);
    auto kernel_start = std::chrono::high_resolution_clock::now();
    for (int i=0;i<iter;i++){
        dma_rhdl0 = xrtKernelRun(dma_khdl0, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer0_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl1 = xrtKernelRun(dma_khdl1, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer1_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl2 = xrtKernelRun(dma_khdl2, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer2_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl3 = xrtKernelRun(dma_khdl3, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer3_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl4 = xrtKernelRun(dma_khdl4, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer4_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl5 = xrtKernelRun(dma_khdl5, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer5_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl6 = xrtKernelRun(dma_khdl6, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer6_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        dma_rhdl7 = xrtKernelRun(dma_khdl7, bohdl_layer0_in0, bohdl_layer0_in1,bohdl_layer7_out,TX,TY,TZ,
                                nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, nullptr, nullptr);
        xrtRunWait(dma_rhdl0);
        xrtRunWait(dma_rhdl1);
        xrtRunWait(dma_rhdl2);
        xrtRunWait(dma_rhdl3);
        xrtRunWait(dma_rhdl4);
        xrtRunWait(dma_rhdl5);
        xrtRunWait(dma_rhdl6);
        xrtRunWait(dma_rhdl7);
    }
 
    auto kernel_end = std::chrono::high_resolution_clock::now();
    kernel_time = std::chrono::duration<double>(kernel_end - kernel_start);
    kernel_time_in_sec = kernel_time.count();
    double TOPS = (double)(M1 * K1) * (double) (N1 * 8* 2 *iter* 1e-9) / kernel_time_in_sec;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "MM Size:"<< M1 << "*" << K1 << "*" << N1 << std::endl;
    std::cout << "Total time is: "<< kernel_time_in_sec <<"s, TOPS = " << TOPS << " GOPS/s" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    xrtRunClose(dma_rhdl0);
    xrtRunClose(dma_rhdl1);
    xrtRunClose(dma_rhdl2);
    xrtRunClose(dma_rhdl3);
    xrtRunClose(dma_rhdl4);
    xrtRunClose(dma_rhdl5);
    xrtRunClose(dma_rhdl6);
    xrtRunClose(dma_rhdl7);
    xrtKernelClose(dma_khdl0);
    xrtKernelClose(dma_khdl1);
    xrtKernelClose(dma_khdl2);
    xrtKernelClose(dma_khdl3);
    xrtKernelClose(dma_khdl4);
    xrtKernelClose(dma_khdl5);
    xrtKernelClose(dma_khdl6);
    xrtKernelClose(dma_khdl7);

    // sync output memory
    xrtBOSync(bohdl_layer0_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer1_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer2_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer3_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer4_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer5_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer6_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
    xrtBOSync(bohdl_layer7_out, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);

    
    ////////////////////////////////////////////
    //// Comparing the execution data to the golden data
    ////////////////////////////////////////////

    if(verify){
    
        float sum = 0;
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                sum =0;
                for (int k = 0; k < K; k++) {
                    sum=sum+DataInput0[m][k]*DataInput1[k][n];
                }
                golden[m][n]=sum;
            } 
        }
    

        int errorCount = 0;
      
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer0_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer1_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer2_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer3_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer4_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer5_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer6_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
                }
            }
        }

        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                if(abs((float)(bomapped_layer7_out[m+n*M])-golden[m][n])>=1e-3){
                    errorCount++;
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
    
    xrtBOFree(bohdl_layer0_in0);
    xrtBOFree(bohdl_layer0_in1);
    xrtBOFree(bohdl_layer0_out);

    xrtBOFree(bohdl_layer1_out);

    xrtBOFree(bohdl_layer2_out);

    xrtBOFree(bohdl_layer3_out);

    xrtBOFree(bohdl_layer4_out);

    xrtBOFree(bohdl_layer5_out);

    xrtBOFree(bohdl_layer6_out);

    xrtBOFree(bohdl_layer7_out);

    xrtDeviceClose(dhdl);
    return 0;
}
