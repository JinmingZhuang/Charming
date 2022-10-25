// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_6/src/21_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_7_0_0 32
#define LOCK_21_7_1_4096 33
#define LOCK_21_7_2_4096 34
#define LOCK_21_7_3_4096 35
#define LOCK_21_5_6_4096 6
#define LOCK_21_5_7_4096 7
#define LOCK_21_7_4_0 36
#define LOCK_21_7_5_4096 37

// Declare shared memory buffers
v4float buf917[256];
v4float buf917d[256];
v4float buf918[256];
v4float buf918d[256];
v4float buf919[256];
v4float buf919d[256];
v4float buf920[256];
v4float buf920d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf918_buf918d[1];
  window_datatype * buf918_ptr = (window_datatype * )buf918;
  window_datatype * buf918d_ptr = (window_datatype * )buf918d;
  window_init(window_buf918_buf918d, 1, buf918, LOCK_21_7_0_0, buf918d, LOCK_21_7_1_4096, 256, 256);
  window_internal window_buf919_buf919d[1];
  window_datatype * buf919_ptr = (window_datatype * )buf919;
  window_datatype * buf919d_ptr = (window_datatype * )buf919d;
  window_init(window_buf919_buf919d, 1, buf919, LOCK_21_7_2_4096, buf919d, LOCK_21_7_3_4096, 256, 256);
  window_internal window_buf917_buf917d[1];
  window_datatype * buf917_ptr = (window_datatype * )buf917;
  window_datatype * buf917d_ptr = (window_datatype * )buf917d;
  window_init(window_buf917_buf917d, 1, buf917, LOCK_21_5_6_4096, buf917d, LOCK_21_5_7_4096, 256, 256);
  window_internal window_buf920_buf920d[1];
  window_datatype * buf920_ptr = (window_datatype * )buf920;
  window_datatype * buf920d_ptr = (window_datatype * )buf920d;
  window_init(window_buf920_buf920d, 1, buf920, LOCK_21_7_4_0, buf920d, LOCK_21_7_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_6_bounds = sync_buffer[1];

  while (proc_21_6_bounds)
  {

    // Kernel call : i540:mm_kernel1
    window_acquire(window_buf918_buf918d,LOCK_21_7_0_0,LOCK_21_7_1_4096,buf918_ptr,buf918d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf919_buf919d,LOCK_21_7_2_4096,LOCK_21_7_3_4096,buf919_ptr,buf919d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf917_buf917d,LOCK_21_5_6_4096,LOCK_21_5_7_4096,buf917_ptr,buf917d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf920_buf920d,LOCK_21_7_4_0,LOCK_21_7_5_4096,buf920_ptr,buf920d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf918_buf918d),get_input_window_float(window_buf919_buf919d),get_input_window_float(window_buf917_buf917d),get_output_window_float(window_buf920_buf920d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf918_buf918d,LOCK_21_7_0_0,LOCK_21_7_1_4096,buf918_ptr,buf918d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf919_buf919d,LOCK_21_7_2_4096,LOCK_21_7_3_4096,buf919_ptr,buf919d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf917_buf917d,LOCK_21_5_6_4096,LOCK_21_5_7_4096,buf917_ptr,buf917d_ptr,0,index, REL_WRITE);
    window_release(window_buf920_buf920d,LOCK_21_7_4_0,LOCK_21_7_5_4096,buf920_ptr,buf920d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_6_bounds > 0)
      --proc_21_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}