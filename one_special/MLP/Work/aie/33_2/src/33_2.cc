// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_2/src/33_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_2_0_4096 48
#define LOCK_33_2_1_0 49
#define LOCK_33_1_6_4096 6
#define LOCK_33_1_7_0 7
#define LOCK_33_1_4_0 4
#define LOCK_33_1_5_4096 5
#define LOCK_33_2_2_0 50
#define LOCK_33_2_3_4096 51

// Declare shared memory buffers
v4float buf377[256];
v4float buf377d[256];
v4float buf378[256];
v4float buf378d[256];
v4float buf379[256];
v4float buf379d[256];
v4float buf380[256];
v4float buf380d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf378_buf378d[1];
  window_datatype * buf378_ptr = (window_datatype * )buf378;
  window_datatype * buf378d_ptr = (window_datatype * )buf378d;
  window_init(window_buf378_buf378d, 1, buf378, LOCK_33_2_0_4096, buf378d, LOCK_33_2_1_0, 256, 256);
  window_internal window_buf379_buf379d[1];
  window_datatype * buf379_ptr = (window_datatype * )buf379;
  window_datatype * buf379d_ptr = (window_datatype * )buf379d;
  window_init(window_buf379_buf379d, 1, buf379, LOCK_33_1_6_4096, buf379d, LOCK_33_1_7_0, 256, 256);
  window_internal window_buf377_buf377d[1];
  window_datatype * buf377_ptr = (window_datatype * )buf377;
  window_datatype * buf377d_ptr = (window_datatype * )buf377d;
  window_init(window_buf377_buf377d, 1, buf377, LOCK_33_1_4_0, buf377d, LOCK_33_1_5_4096, 256, 256);
  window_internal window_buf380_buf380d[1];
  window_datatype * buf380_ptr = (window_datatype * )buf380;
  window_datatype * buf380d_ptr = (window_datatype * )buf380d;
  window_init(window_buf380_buf380d, 1, buf380, LOCK_33_2_2_0, buf380d, LOCK_33_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_2_bounds = sync_buffer[1];

  while (proc_33_2_bounds)
  {

    // Kernel call : i270:mm_kernel1
    window_acquire(window_buf378_buf378d,LOCK_33_2_0_4096,LOCK_33_2_1_0,buf378_ptr,buf378d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf379_buf379d,LOCK_33_1_6_4096,LOCK_33_1_7_0,buf379_ptr,buf379d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf377_buf377d,LOCK_33_1_4_0,LOCK_33_1_5_4096,buf377_ptr,buf377d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf380_buf380d,LOCK_33_2_2_0,LOCK_33_2_3_4096,buf380_ptr,buf380d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf378_buf378d),get_input_window_float(window_buf379_buf379d),get_input_window_float(window_buf377_buf377d),get_output_window_float(window_buf380_buf380d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf378_buf378d,LOCK_33_2_0_4096,LOCK_33_2_1_0,buf378_ptr,buf378d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf379_buf379d,LOCK_33_1_6_4096,LOCK_33_1_7_0,buf379_ptr,buf379d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf377_buf377d,LOCK_33_1_4_0,LOCK_33_1_5_4096,buf377_ptr,buf377d_ptr,0,index, REL_WRITE);
    window_release(window_buf380_buf380d,LOCK_33_2_2_0,LOCK_33_2_3_4096,buf380_ptr,buf380d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_2_bounds > 0)
      --proc_33_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}