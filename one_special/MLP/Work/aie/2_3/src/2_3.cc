// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_3/src/2_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_2_3_2_4096 18
#define LOCK_2_3_3_4096 19
#define LOCK_2_3_4_0 20
#define LOCK_2_3_5_0 21
#define LOCK_2_3_0_0 16
#define LOCK_2_3_1_0 17
#define LOCK_2_3_6_4096 22
#define LOCK_2_3_7_4096 23

// Declare shared memory buffers
v4float buf10[256];
v4float buf10d[256];
v4float buf11[256];
v4float buf11d[256];
v4float buf8[256];
v4float buf8d[256];
v4float buf9[256];
v4float buf9d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf9_buf9d[1];
  window_datatype * buf9_ptr = (window_datatype * )buf9;
  window_datatype * buf9d_ptr = (window_datatype * )buf9d;
  window_init(window_buf9_buf9d, 1, buf9, LOCK_2_3_2_4096, buf9d, LOCK_2_3_3_4096, 256, 256);
  window_internal window_buf10_buf10d[1];
  window_datatype * buf10_ptr = (window_datatype * )buf10;
  window_datatype * buf10d_ptr = (window_datatype * )buf10d;
  window_init(window_buf10_buf10d, 1, buf10, LOCK_2_3_4_0, buf10d, LOCK_2_3_5_0, 256, 256);
  window_internal window_buf8_buf8d[1];
  window_datatype * buf8_ptr = (window_datatype * )buf8;
  window_datatype * buf8d_ptr = (window_datatype * )buf8d;
  window_init(window_buf8_buf8d, 1, buf8, LOCK_2_3_0_0, buf8d, LOCK_2_3_1_0, 256, 256);
  window_internal window_buf11_buf11d[1];
  window_datatype * buf11_ptr = (window_datatype * )buf11;
  window_datatype * buf11d_ptr = (window_datatype * )buf11d;
  window_init(window_buf11_buf11d, 1, buf11, LOCK_2_3_6_4096, buf11d, LOCK_2_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_3_bounds = sync_buffer[1];

  while (proc_2_3_bounds)
  {

    // Kernel call : i85:mm_kernel1
    window_acquire(window_buf9_buf9d,LOCK_2_3_2_4096,LOCK_2_3_3_4096,buf9_ptr,buf9d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf10_buf10d,LOCK_2_3_4_0,LOCK_2_3_5_0,buf10_ptr,buf10d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf8_buf8d,LOCK_2_3_0_0,LOCK_2_3_1_0,buf8_ptr,buf8d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf11_buf11d,LOCK_2_3_6_4096,LOCK_2_3_7_4096,buf11_ptr,buf11d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf9_buf9d),get_input_window_float(window_buf10_buf10d),get_input_window_float(window_buf8_buf8d),get_output_window_float(window_buf11_buf11d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf9_buf9d,LOCK_2_3_2_4096,LOCK_2_3_3_4096,buf9_ptr,buf9d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf10_buf10d,LOCK_2_3_4_0,LOCK_2_3_5_0,buf10_ptr,buf10d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf8_buf8d,LOCK_2_3_0_0,LOCK_2_3_1_0,buf8_ptr,buf8d_ptr,0,index, REL_WRITE);
    window_release(window_buf11_buf11d,LOCK_2_3_6_4096,LOCK_2_3_7_4096,buf11_ptr,buf11d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_3_bounds > 0)
      --proc_2_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}