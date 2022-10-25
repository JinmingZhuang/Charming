// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_7/src/23_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_7_2_4096 18
#define LOCK_23_7_3_4096 19
#define LOCK_24_7_6_4096 54
#define LOCK_24_7_7_4096 55
#define LOCK_23_6_4_4096 4
#define LOCK_23_6_5_4096 5
#define LOCK_23_6_6_0 6
#define LOCK_23_6_7_4096 7

// Declare shared memory buffers
v4float buf896[256];
v4float buf896d[256];
v4float buf897[256];
v4float buf897d[256];
v4float buf898[256];
v4float buf898d[256];
v4float buf899[256];
v4float buf899d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf897_buf897d[1];
  window_datatype * buf897_ptr = (window_datatype * )buf897;
  window_datatype * buf897d_ptr = (window_datatype * )buf897d;
  window_init(window_buf897_buf897d, 1, buf897, LOCK_23_7_2_4096, buf897d, LOCK_23_7_3_4096, 256, 256);
  window_internal window_buf898_buf898d[1];
  window_datatype * buf898_ptr = (window_datatype * )buf898;
  window_datatype * buf898d_ptr = (window_datatype * )buf898d;
  window_init(window_buf898_buf898d, 1, buf898, LOCK_24_7_6_4096, buf898d, LOCK_24_7_7_4096, 256, 256);
  window_internal window_buf896_buf896d[1];
  window_datatype * buf896_ptr = (window_datatype * )buf896;
  window_datatype * buf896d_ptr = (window_datatype * )buf896d;
  window_init(window_buf896_buf896d, 1, buf896, LOCK_23_6_4_4096, buf896d, LOCK_23_6_5_4096, 256, 256);
  window_internal window_buf899_buf899d[1];
  window_datatype * buf899_ptr = (window_datatype * )buf899;
  window_datatype * buf899d_ptr = (window_datatype * )buf899d;
  window_init(window_buf899_buf899d, 1, buf899, LOCK_23_6_6_0, buf899d, LOCK_23_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_7_bounds = sync_buffer[1];

  while (proc_23_7_bounds)
  {

    // Kernel call : i529:mm_kernel1
    window_acquire(window_buf897_buf897d,LOCK_23_7_2_4096,LOCK_23_7_3_4096,buf897_ptr,buf897d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf898_buf898d,LOCK_24_7_6_4096,LOCK_24_7_7_4096,buf898_ptr,buf898d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf896_buf896d,LOCK_23_6_4_4096,LOCK_23_6_5_4096,buf896_ptr,buf896d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf899_buf899d,LOCK_23_6_6_0,LOCK_23_6_7_4096,buf899_ptr,buf899d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf897_buf897d),get_input_window_float(window_buf898_buf898d),get_input_window_float(window_buf896_buf896d),get_output_window_float(window_buf899_buf899d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf897_buf897d,LOCK_23_7_2_4096,LOCK_23_7_3_4096,buf897_ptr,buf897d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf898_buf898d,LOCK_24_7_6_4096,LOCK_24_7_7_4096,buf898_ptr,buf898d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf896_buf896d,LOCK_23_6_4_4096,LOCK_23_6_5_4096,buf896_ptr,buf896d_ptr,0,index, REL_WRITE);
    window_release(window_buf899_buf899d,LOCK_23_6_6_0,LOCK_23_6_7_4096,buf899_ptr,buf899d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_7_bounds > 0)
      --proc_23_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}