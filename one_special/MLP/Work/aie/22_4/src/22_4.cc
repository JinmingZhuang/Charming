// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_4/src/22_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_5_0_0 32
#define LOCK_22_5_1_0 33
#define LOCK_22_4_0_0 48
#define LOCK_22_4_1_0 49
#define LOCK_22_5_2_0 34
#define LOCK_22_5_3_0 35

// Declare shared memory buffers
v4float buf900[256];
v4float buf900d[256];
v4float buf901[256];
v4float buf901d[256];
v4float buf902[256];
v4float buf902d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf900_buf900d[1];
  window_datatype * buf900_ptr = (window_datatype * )buf900;
  window_datatype * buf900d_ptr = (window_datatype * )buf900d;
  window_init(window_buf900_buf900d, 1, buf900, LOCK_22_5_0_0, buf900d, LOCK_22_5_1_0, 256, 256);
  window_internal window_buf901_buf901d[1];
  window_datatype * buf901_ptr = (window_datatype * )buf901;
  window_datatype * buf901d_ptr = (window_datatype * )buf901d;
  window_init(window_buf901_buf901d, 1, buf901, LOCK_22_4_0_0, buf901d, LOCK_22_4_1_0, 256, 256);
  window_internal window_buf902_buf902d[1];
  window_datatype * buf902_ptr = (window_datatype * )buf902;
  window_datatype * buf902d_ptr = (window_datatype * )buf902d;
  window_init(window_buf902_buf902d, 1, buf902, LOCK_22_5_2_0, buf902d, LOCK_22_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_4_bounds = sync_buffer[1];

  while (proc_22_4_bounds)
  {

    // Kernel call : i532:mm_kernel0
    window_acquire(window_buf900_buf900d,LOCK_22_5_0_0,LOCK_22_5_1_0,buf900_ptr,buf900d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf901_buf901d,LOCK_22_4_0_0,LOCK_22_4_1_0,buf901_ptr,buf901d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf902_buf902d,LOCK_22_5_2_0,LOCK_22_5_3_0,buf902_ptr,buf902d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf900_buf900d),get_input_window_float(window_buf901_buf901d),get_output_window_float(window_buf902_buf902d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf900_buf900d,LOCK_22_5_0_0,LOCK_22_5_1_0,buf900_ptr,buf900d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf901_buf901d,LOCK_22_4_0_0,LOCK_22_4_1_0,buf901_ptr,buf901d_ptr,0,index, REL_WRITE);
    window_release(window_buf902_buf902d,LOCK_22_5_2_0,LOCK_22_5_3_0,buf902_ptr,buf902d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_4_bounds > 0)
      --proc_22_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}