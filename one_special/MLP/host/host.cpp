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
mm_x96_x4_graph<2> myGraph;
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
const int A=6;
const int B=4;
const int C=16;
const int X=8;
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
    int Lar_X=X*TX;
    int Lar_Y=Y*TY;
    int Lar_Z=Z*TZ;
    int sizeIn1 = DATA_SIZE1*A*B*Lar_X*Lar_Y;
    int sizeIn2 = DATA_SIZE2*B*C*Lar_Y*Lar_Z;
    int sizeOut = OUT_SIZE*A*C*Lar_X*Lar_Z;
    
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> DataInput0(Lar_X, std::vector<std::vector<std::vector<std::vector<float>>>>(Lar_Y, std::vector<std::vector<std::vector<float>>>(A,std::vector<std::vector<float>>(B,std::vector<float>(DATA_SIZE1, 1)))));
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> DataInput1(Lar_Z, std::vector<std::vector<std::vector<std::vector<float>>>>(Lar_Y, std::vector<std::vector<std::vector<float>>>(B,std::vector<std::vector<float>>(C,std::vector<float>(DATA_SIZE2, 1)))));
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> golden(Lar_Z, std::vector<std::vector<std::vector<std::vector<float>>>>(Lar_X, std::vector<std::vector<std::vector<float>>>(A,std::vector<std::vector<float>>(C,std::vector<float>(OUT_SIZE, 1)))));



    srand (time(0));
    for (int m = 0; m < Lar_X; m++) {
        for (int n = 0; n < Lar_Y; n++) {
            for (int k = 0; k < A; k++) {
                for (int j = 0; j < B; j++) {
                    for (int i = 0; i < DATA_SIZE1; i++) {
                        DataInput0[m][n][k][j][i] = (rand()%5)*(float)1.0;
                    }
                }
            }
        }
    }

    srand (time(0));
    for (int m = 0; m < Lar_Z; m++) {
        for (int n = 0; n < Lar_Y; n++) {
            for (int k = 0; k < B; k++) {
                for (int j = 0; j < C; j++) {
                    for (int i = 0; i < DATA_SIZE2; i++) {
                        DataInput1[m][n][k][j][i] = (rand()%5)*(float)1.0; //
                    }
                }
            }
        }
    }
    
    //Allocate input mem
    xrtBufferHandle in_bohdl0 = xrtBOAlloc(dhdl, sizeIn1 * sizeof(float), 0, 0);
    auto in_bomapped0 = reinterpret_cast<float*>(xrtBOMap(in_bohdl0));


    xrtBufferHandle in_bohdl1 = xrtBOAlloc(dhdl, sizeIn2 * sizeof(float), 0, 0);
    auto in_bomapped1 = reinterpret_cast<float*>(xrtBOMap(in_bohdl1));
    
    for(int q=0;q<TX;q++){
        for(int m=0;m<Lar_Y;m++){
            for(int k=0;k<B;k++){
                for(int p=0;p<W1;p++){
                    for(int n=0;n<X;n++){
                        for(int j=0;j<A;j++){
                            for(int i=0;i<H1;i++){
                                in_bomapped0[i+j*H1+n*A*H1+p*X*A*H1+k*X*A*DATA_SIZE1+m*B*X*A*DATA_SIZE1+q*Lar_Y*B*X*A*DATA_SIZE1]=DataInput0[n+q*X][m][j][k][i*W1+p];
                            }
                        }
                    }
                }
            }
        }
    }

    for(int q=0;q<TZ;q++){
        for(int p=0;p<TY;p++){
            for(int z=0;z<Z;z++){
                for(int k=0;k<C;k++){
                    for(int j=0;j<W2;j++){
                        for(int n=0;n<Y;n++){
                            for(int i=0;i<B;i++){
                                for (int m=0;m<W1;m++){
                                    in_bomapped1[m+i*W1+n*B*W1+j*Y*B*W1+k*DATA_SIZE2*B*Y+z*C*DATA_SIZE2*B*Y+p*Z*C*DATA_SIZE2*B*Y+q*Z*C*DATA_SIZE2*B*Y*TY]=DataInput1[z+q*Z][n+p*Y][i][k][m*W2+j];
                                }
                            }
                        }
                    }
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
    xrtKernelHandle dma_khdl = xrtPLKernelOpen(dhdl, top->m_header.uuid, "dma");
    xrtRunHandle dma_rhdl;
    //profile aie mm 
    double kernel_time_in_sec = 0;
    std::chrono::duration<double> kernel_time(0);
    auto kernel_start = std::chrono::high_resolution_clock::now();
    for (int i=0;i<iter;i++){
    // start input kernels run handles
    dma_rhdl = xrtKernelRun(dma_khdl, in_bohdl0, in_bohdl1,out_bohdl,TX,TY,TZ,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr,
                        nullptr, nullptr, nullptr, nullptr);
        xrtRunWait(dma_rhdl);
    }
 
    auto kernel_end = std::chrono::high_resolution_clock::now();
    kernel_time = std::chrono::duration<double>(kernel_end - kernel_start);
    kernel_time_in_sec = kernel_time.count();
    double TOPS = (double)(M1 * K1) * (double) (N1 * 2 *iter* 1e-9) / kernel_time_in_sec;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout  << std::endl;
    std::cout << "MM Size:"<< M1 << "*" << K1 << "*" << N1 << ", Total time is: "<< kernel_time_in_sec <<"s, TOPS = " << TOPS << " GOPS/s" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // sync output memory
    xrtBOSync(out_bohdl, XCL_BO_SYNC_BO_FROM_DEVICE , sizeOut* sizeof(float),/*OFFSET=*/ 0);
        
    xrtRunClose(dma_rhdl);
    xrtKernelClose(dma_khdl);

    
    ////////////////////////////////////////////
    //// Comparing the execution data to the golden data
    ////////////////////////////////////////////

    if (verify)
    {
        float sum = 0;
        for(int z=0;z<Lar_Z;z++){
            for (int c=0; c<C; c++){
                for (int w2_host=0; w2_host<W2; w2_host++){
                    for (int x=0; x<Lar_X; x++){
                        for (int a=0; a<A; a++){
                            for (int h1_host=0; h1_host<H1; h1_host++){
                                sum=0;
                                for (int y=0; y<Lar_Y; y++){
                                    for (int b=0; b < B; b++) {
                                        for (int w1_host=0; w1_host <W1 ; w1_host++) {
                                            sum=sum+DataInput0[x][y][a][b][w1_host+h1_host*W1]*DataInput1[z][y][b][c][w1_host*W2+w2_host];
                                        }
                                    }
                                }
                                golden[z][x][a][c][w2_host+h1_host*W2]=sum;
                            }
                        }
                    }
                }
            }
        }

        int errorCount = 0; 
        for(int p=0;p<TX;p++){
            for(int z=0;z<Lar_Z;z++){
                for (int c=0; c<C; c++){
                    for (int w2_host=0; w2_host<W2; w2_host++){
                        for (int x=0; x<X; x++){
                            for (int a=0; a<A; a++){
                                for (int h1_host=0; h1_host<H1; h1_host++){
                                    if(abs((float)(out_bomapped[h1_host+a*H1+x*H1*A+w2_host*X*A*H1+c*OUT_SIZE*A*X+z*C*OUT_SIZE*A*X+p*Lar_Z*C*OUT_SIZE*A*X])-golden[z][x+p*X][a][c][h1_host*W2+w2_host])>=1e-3){
                                        printf("Error found out_bomapped[%d]!=golden[%d][%d][%d][%d][%d], %f!=%f \n", h1_host+a*H1+x*H1*A+w2_host*X*A*H1+c*OUT_SIZE*A*X+z*C*OUT_SIZE*A*X+p*Lar_Z*C*OUT_SIZE*A*X,z,x+p*X,a,c,h1_host*W2+w2_host,(float)out_bomapped[h1_host+a*H1+x*H1*A+w2_host*X*A*H1+c*OUT_SIZE*A*X+z*C*OUT_SIZE*A*X+p*Lar_Z*C*OUT_SIZE*A*X], golden[z][x+p*X][a][c][h1_host*W2+w2_host]);
                                        errorCount++;
                                    }
                                }
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
    
    xrtBOFree(in_bohdl0);
    xrtBOFree(in_bohdl1);
    xrtBOFree(out_bohdl);
    xrtDeviceClose(dhdl);
    return 0;
}
