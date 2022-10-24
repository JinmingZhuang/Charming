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
mm_x4_x2_graph<33,0> myGraph;
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
const int A=2;
const int B=2;
const int C=2;
const int X=1;
const int Y=1;
const int Z=1;



const int DATA_SIZE1=H1*W1;
const int DATA_SIZE2=W1*W2;
const int OUT_SIZE=H1*W2;

using namespace std;


int main(int argc, char** argv) {

    int TX,TY,TZ;
    int M1=512,K1=64,N1=64;
    int iter=1;
    int D0=1,D1=1;
    char* xclbinFilename;
    //xclbinFilename = argv[1];
    if(argc == 8) {
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
        if (sscanf (argv[5], "%i", &D0) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[6], "%i", &D1) != 1) {
            fprintf(stderr, "error - not an integer");
        }
        if (sscanf (argv[7], "%i", &iter) != 1) {
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
    std::cout << "TX:" << TX << " TY:" << TY << " TZ:" << TZ << std::endl;
    
    int M =TX * X * A * H1;
    int K =TY * Y * B * W1;
    int N =TZ * Z * C * W2;
    int sizeIn1 = M * K * D0 * D1;
    int sizeIn2 = K * N * D0 * D1;
    int sizeOut = M * N * D0 * D1;

    std::vector<std::vector<std::vector<std::vector<float>>>> DataInput0(D0, std::vector<std::vector<std::vector<float>>>(D1,std::vector<std::vector<float>>(M,std::vector<float>(K, 1.0))));
    std::vector<std::vector<std::vector<std::vector<float>>>> DataInput1(D0, std::vector<std::vector<std::vector<float>>>(D1,std::vector<std::vector<float>>(K,std::vector<float>(N, 1.0))));
    std::vector<std::vector<std::vector<std::vector<float>>>> golden(D0, std::vector<std::vector<std::vector<float>>>(D1,std::vector<std::vector<float>>(M,std::vector<float>(N, 1.0))));



    srand (time(0));
    for(int dot_x=0;dot_x<D0;dot_x++){
        for(int dot_y=0;dot_y<D1;dot_y++){
            for (int m = 0; m < M; m++) {
                for (int k = 0; k < K; k++) {
                    DataInput0[dot_x][dot_y][m][k]= k*(float)1.0;
                } 
            }
        }
    }

    srand (time(0));
    for(int dot_x=0;dot_x<D0;dot_x++){
        for(int dot_y=0;dot_y<D1;dot_y++){
            for (int k = 0; k < K; k++) {
                for (int n = 0; n < N; n++) {
                    DataInput1[dot_x][dot_y][k][n]= k*(float)1.0;
                } 
            }
        }
    }
    
    //Allocate input mem
    xrtBufferHandle in_bohdl0 = xrtBOAlloc(dhdl, sizeIn1 * sizeof(float), 0, 0);
    auto in_bomapped0 = reinterpret_cast<float*>(xrtBOMap(in_bohdl0));


    xrtBufferHandle in_bohdl1 = xrtBOAlloc(dhdl, sizeIn2 * sizeof(float), 0, 0);
    auto in_bomapped1 = reinterpret_cast<float*>(xrtBOMap(in_bohdl1));
    
    for(int dot_y=0;dot_y<D1;dot_y++){
        for (int k = 0; k < K; k++) {
            for(int dot_x=0;dot_x<D0;dot_x++){
                for (int m = 0; m < M; m++) {
                    in_bomapped0[m+k*M*D0+dot_y*K*M*D0+dot_x*M]=DataInput0[dot_x][dot_y][m][k];
                } 
            }
        }
    }
    
    
    for(int dot_y=0;dot_y<D1;dot_y++){
        for (int n = 0; n < N; n++) {
            for(int dot_x=0;dot_x<D0;dot_x++){
                for (int k = 0; k < K; k++) {
                    in_bomapped1[k+n*K*D0+dot_y*N*K*D0+dot_x*K]=DataInput1[dot_x][dot_y][k][n];
                } 
            }
        }
    }
    

    // sync input memory
    xrtBOSync(in_bohdl0, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn1* sizeof(float),0);
    xrtBOSync(in_bohdl1, XCL_BO_SYNC_BO_TO_DEVICE , sizeIn2* sizeof(float),0);
    
    //Allocate output buffer
    float *out_bomapped; 
    xrtBufferHandle out_bohdl; 

    out_bohdl = xrtBOAlloc(dhdl, sizeOut* sizeof(float), 0, 0);
    out_bomapped = reinterpret_cast<float*>(xrtBOMap(out_bohdl));
    
    myGraph.init();
                              
    printf("graph run\n");
    myGraph.run(-1);

    std::cout << "Kernel run\n";
    xrtKernelHandle dma_khdl = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma_small");
    xrtRunHandle dma_rhdl;

        

    //profile aie mm 
    double kernel_time_in_sec = 0;
    std::chrono::duration<double> kernel_time(0);
    auto kernel_start = std::chrono::high_resolution_clock::now();
    for (int i=0;i<iter;i++){
    // start input kernels run handles
    dma_rhdl = xrtKernelRun(dma_khdl, in_bohdl0, in_bohdl1,out_bohdl,TX,TY,TZ,D0,D1,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,//A 8
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,//B 8
                        nullptr, nullptr, nullptr, nullptr);// C 4



    
    //////////////////////////////////////////
    // wait for mm2s done
    //////////////////////////////////////////
    //Wait for kernel finish
    xrtRunWait(dma_rhdl);
    }
 
    auto kernel_end = std::chrono::high_resolution_clock::now();
    kernel_time = std::chrono::duration<double>(kernel_end - kernel_start);
    kernel_time_in_sec = kernel_time.count();
    double TOPS = (double)(M1 * K1 * D0 * D1) * (double) (N1 * 2 *iter* 1e-9) / kernel_time_in_sec;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "MM Size:"<< M1 << "*" << K1 << "*" << N1 << std::endl;
    std::cout << "Total time is: "<< kernel_time_in_sec <<"s, TOPS = " << TOPS << " GOPS/s" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    // sync output memory

    xrtRunClose(dma_rhdl);
    xrtKernelClose(dma_khdl);
    xrtBOSync(out_bohdl, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
        
    
    

    
    //////////////////////////////////////////
    // Comparing the execution data to the golden data
    //////////////////////////////////////////

    {
        float sum = 0;
        for(int dot_x=0;dot_x<D0;dot_x++){
            for(int dot_y=0;dot_y<D1;dot_y++){
                for (int m = 0; m < M; m++) {
                    for (int n = 0; n < N; n++) {
                        sum =0;
                        for (int k = 0; k < K; k++) {
                            sum=sum+DataInput0[dot_x][dot_y][m][k]*DataInput1[dot_x][dot_y][k][n];
                        }
                        golden[dot_x][dot_y][m][n]=sum;
                    } 
                }
            }
        }
    }

    int errorCount = 0;
    {   
        
        for(int dot_y=0;dot_y<D1;dot_y++){
            for (int n = 0; n < N; n++) {
                for(int dot_x=0;dot_x<D0;dot_x++){
                    for (int m = 0; m < M; m++) {
                        if(abs((float)(out_bomapped[m+n*M*D0+dot_y*N*M*D0+dot_x*M])-golden[dot_x][dot_y][m][n])>=1e-3){
                            printf("Error found out_bomapped[%d]!=golden[%d][%d][%d][%d], %f!=%f \n", m+n*M*D0+dot_y*N*M*D0+dot_x*M,dot_x,dot_y,m,n,out_bomapped[m+n*M*D0+dot_y*N*M*D0+dot_x*M],golden[dot_x][dot_y][m][n]);
                            errorCount++;
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
    
    xrtBOFree(out_bohdl);
    xrtBOFree(in_bohdl0);
    xrtBOFree(in_bohdl1);
    xrtDeviceClose(dhdl);
    return 0;
}
