// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_3/src/11_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_2_2_4096 2
#define LOCK_11_2_3_4096 3
#define LOCK_11_2_4_0 4
#define LOCK_11_2_5_0 5
#define LOCK_11_2_0_0 0
#define LOCK_11_2_1_0 1
#define LOCK_11_2_6_4096 6
#define LOCK_11_2_7_4096 7

// Declare shared memory buffers
v4float buf116[256];
v4float buf116d[256];
v4float buf117[256];
v4float buf117d[256];
v4float buf118[256];
v4float buf118d[256];
v4float buf119[256];
v4float buf119d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf117_buf117d[1];
  window_datatype * buf117_ptr = (window_datatype * )buf117;
  window_datatype * buf117d_ptr = (window_datatype * )buf117d;
  window_init(window_buf117_buf117d, 1, buf117, LOCK_11_2_2_4096, buf117d, LOCK_11_2_3_4096, 256, 256);
  window_internal window_buf118_buf118d[1];
  window_datatype * buf118_ptr = (window_datatype * )buf118;
  window_datatype * buf118d_ptr = (window_datatype * )buf118d;
  window_init(window_buf118_buf118d, 1, buf118, LOCK_11_2_4_0, buf118d, LOCK_11_2_5_0, 256, 256);
  window_internal window_buf116_buf116d[1];
  window_datatype * buf116_ptr = (window_datatype * )buf116;
  window_datatype * buf116d_ptr = (window_datatype * )buf116d;
  window_init(window_buf116_buf116d, 1, buf116, LOCK_11_2_0_0, buf116d, LOCK_11_2_1_0, 256, 256);
  window_internal window_buf119_buf119d[1];
  window_datatype * buf119_ptr = (window_datatype * )buf119;
  window_datatype * buf119d_ptr = (window_datatype * )buf119d;
  window_init(window_buf119_buf119d, 1, buf119, LOCK_11_2_6_4096, buf119d, LOCK_11_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_3_bounds = sync_buffer[1];

  while (proc_11_3_bounds)
  {

    // Kernel call : i139:mm_kernel1
    window_acquire(window_buf117_buf117d,LOCK_11_2_2_4096,LOCK_11_2_3_4096,buf117_ptr,buf117d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf118_buf118d,LOCK_11_2_4_0,LOCK_11_2_5_0,buf118_ptr,buf118d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf116_buf116d,LOCK_11_2_0_0,LOCK_11_2_1_0,buf116_ptr,buf116d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf119_buf119d,LOCK_11_2_6_4096,LOCK_11_2_7_4096,buf119_ptr,buf119d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf117_buf117d),get_input_window_float(window_buf118_buf118d),get_input_window_float(window_buf116_buf116d),get_output_window_float(window_buf119_buf119d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf117_buf117d,LOCK_11_2_2_4096,LOCK_11_2_3_4096,buf117_ptr,buf117d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf118_buf118d,LOCK_11_2_4_0,LOCK_11_2_5_0,buf118_ptr,buf118d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf116_buf116d,LOCK_11_2_0_0,LOCK_11_2_1_0,buf116_ptr,buf116d_ptr,0,index, REL_WRITE);
    window_release(window_buf119_buf119d,LOCK_11_2_6_4096,LOCK_11_2_7_4096,buf119_ptr,buf119d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_3_bounds > 0)
      --proc_11_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}