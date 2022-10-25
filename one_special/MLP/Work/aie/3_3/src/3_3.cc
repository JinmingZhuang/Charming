// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_3/src/3_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_3_4_4096 20
#define LOCK_3_3_5_0 21
#define LOCK_4_3_0_0 48
#define LOCK_4_3_1_0 49
#define LOCK_3_3_2_4096 18
#define LOCK_3_3_3_4096 19
#define LOCK_3_3_6_0 22
#define LOCK_3_3_7_0 23

// Declare shared memory buffers
v4float buf20[256];
v4float buf20d[256];
v4float buf21[256];
v4float buf21d[256];
v4float buf22[256];
v4float buf22d[256];
v4float buf23[256];
v4float buf23d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf21_buf21d[1];
  window_datatype * buf21_ptr = (window_datatype * )buf21;
  window_datatype * buf21d_ptr = (window_datatype * )buf21d;
  window_init(window_buf21_buf21d, 1, buf21, LOCK_3_3_4_4096, buf21d, LOCK_3_3_5_0, 256, 256);
  window_internal window_buf22_buf22d[1];
  window_datatype * buf22_ptr = (window_datatype * )buf22;
  window_datatype * buf22d_ptr = (window_datatype * )buf22d;
  window_init(window_buf22_buf22d, 1, buf22, LOCK_4_3_0_0, buf22d, LOCK_4_3_1_0, 256, 256);
  window_internal window_buf20_buf20d[1];
  window_datatype * buf20_ptr = (window_datatype * )buf20;
  window_datatype * buf20d_ptr = (window_datatype * )buf20d;
  window_init(window_buf20_buf20d, 1, buf20, LOCK_3_3_2_4096, buf20d, LOCK_3_3_3_4096, 256, 256);
  window_internal window_buf23_buf23d[1];
  window_datatype * buf23_ptr = (window_datatype * )buf23;
  window_datatype * buf23d_ptr = (window_datatype * )buf23d;
  window_init(window_buf23_buf23d, 1, buf23, LOCK_3_3_6_0, buf23d, LOCK_3_3_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_3_bounds = sync_buffer[1];

  while (proc_3_3_bounds)
  {

    // Kernel call : i91:mm_kernel1
    window_acquire(window_buf21_buf21d,LOCK_3_3_4_4096,LOCK_3_3_5_0,buf21_ptr,buf21d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf22_buf22d,LOCK_4_3_0_0,LOCK_4_3_1_0,buf22_ptr,buf22d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf20_buf20d,LOCK_3_3_2_4096,LOCK_3_3_3_4096,buf20_ptr,buf20d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf23_buf23d,LOCK_3_3_6_0,LOCK_3_3_7_0,buf23_ptr,buf23d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf21_buf21d),get_input_window_float(window_buf22_buf22d),get_input_window_float(window_buf20_buf20d),get_output_window_float(window_buf23_buf23d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf21_buf21d,LOCK_3_3_4_4096,LOCK_3_3_5_0,buf21_ptr,buf21d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf22_buf22d,LOCK_4_3_0_0,LOCK_4_3_1_0,buf22_ptr,buf22d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf20_buf20d,LOCK_3_3_2_4096,LOCK_3_3_3_4096,buf20_ptr,buf20d_ptr,0,index, REL_WRITE);
    window_release(window_buf23_buf23d,LOCK_3_3_6_0,LOCK_3_3_7_0,buf23_ptr,buf23d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_3_bounds > 0)
      --proc_3_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}