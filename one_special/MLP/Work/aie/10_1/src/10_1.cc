// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_1/src/10_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_0_2_4096 2
#define LOCK_10_0_3_4096 3
#define LOCK_10_1_4_0 20
#define LOCK_10_1_5_0 21
#define LOCK_10_1_2_0 18
#define LOCK_10_1_3_4096 19
#define LOCK_10_1_6_4096 22
#define LOCK_10_1_7_4096 23

// Declare shared memory buffers
v4float buf100[256];
v4float buf100d[256];
v4float buf101[256];
v4float buf101d[256];
v4float buf98[256];
v4float buf98d[256];
v4float buf99[256];
v4float buf99d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf99_buf99d[1];
  window_datatype * buf99_ptr = (window_datatype * )buf99;
  window_datatype * buf99d_ptr = (window_datatype * )buf99d;
  window_init(window_buf99_buf99d, 1, buf99, LOCK_10_0_2_4096, buf99d, LOCK_10_0_3_4096, 256, 256);
  window_internal window_buf100_buf100d[1];
  window_datatype * buf100_ptr = (window_datatype * )buf100;
  window_datatype * buf100d_ptr = (window_datatype * )buf100d;
  window_init(window_buf100_buf100d, 1, buf100, LOCK_10_1_4_0, buf100d, LOCK_10_1_5_0, 256, 256);
  window_internal window_buf98_buf98d[1];
  window_datatype * buf98_ptr = (window_datatype * )buf98;
  window_datatype * buf98d_ptr = (window_datatype * )buf98d;
  window_init(window_buf98_buf98d, 1, buf98, LOCK_10_1_2_0, buf98d, LOCK_10_1_3_4096, 256, 256);
  window_internal window_buf101_buf101d[1];
  window_datatype * buf101_ptr = (window_datatype * )buf101;
  window_datatype * buf101d_ptr = (window_datatype * )buf101d;
  window_init(window_buf101_buf101d, 1, buf101, LOCK_10_1_6_4096, buf101d, LOCK_10_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_1_bounds = sync_buffer[1];

  while (proc_10_1_bounds)
  {

    // Kernel call : i131:mm_kernel1
    window_acquire(window_buf99_buf99d,LOCK_10_0_2_4096,LOCK_10_0_3_4096,buf99_ptr,buf99d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf100_buf100d,LOCK_10_1_4_0,LOCK_10_1_5_0,buf100_ptr,buf100d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf98_buf98d,LOCK_10_1_2_0,LOCK_10_1_3_4096,buf98_ptr,buf98d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf101_buf101d,LOCK_10_1_6_4096,LOCK_10_1_7_4096,buf101_ptr,buf101d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf99_buf99d),get_input_window_float(window_buf100_buf100d),get_input_window_float(window_buf98_buf98d),get_output_window_float(window_buf101_buf101d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf99_buf99d,LOCK_10_0_2_4096,LOCK_10_0_3_4096,buf99_ptr,buf99d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf100_buf100d,LOCK_10_1_4_0,LOCK_10_1_5_0,buf100_ptr,buf100d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf98_buf98d,LOCK_10_1_2_0,LOCK_10_1_3_4096,buf98_ptr,buf98d_ptr,0,index, REL_WRITE);
    window_release(window_buf101_buf101d,LOCK_10_1_6_4096,LOCK_10_1_7_4096,buf101_ptr,buf101d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_1_bounds > 0)
      --proc_10_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}