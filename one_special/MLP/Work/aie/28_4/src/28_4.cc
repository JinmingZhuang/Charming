// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_4/src/28_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_5_0_4096 32
#define LOCK_28_5_1_0 33
#define LOCK_28_5_2_0 34
#define LOCK_28_5_3_4096 35
#define LOCK_28_5_4_0 36
#define LOCK_28_5_5_4096 37

// Declare shared memory buffers
v4float buf828[256];
v4float buf828d[256];
v4float buf829[256];
v4float buf829d[256];
v4float buf830[256];
v4float buf830d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf828_buf828d[1];
  window_datatype * buf828_ptr = (window_datatype * )buf828;
  window_datatype * buf828d_ptr = (window_datatype * )buf828d;
  window_init(window_buf828_buf828d, 1, buf828, LOCK_28_5_0_4096, buf828d, LOCK_28_5_1_0, 256, 256);
  window_internal window_buf829_buf829d[1];
  window_datatype * buf829_ptr = (window_datatype * )buf829;
  window_datatype * buf829d_ptr = (window_datatype * )buf829d;
  window_init(window_buf829_buf829d, 1, buf829, LOCK_28_5_2_0, buf829d, LOCK_28_5_3_4096, 256, 256);
  window_internal window_buf830_buf830d[1];
  window_datatype * buf830_ptr = (window_datatype * )buf830;
  window_datatype * buf830d_ptr = (window_datatype * )buf830d;
  window_init(window_buf830_buf830d, 1, buf830, LOCK_28_5_4_0, buf830d, LOCK_28_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_4_bounds = sync_buffer[1];

  while (proc_28_4_bounds)
  {

    // Kernel call : i496:mm_kernel0
    window_acquire(window_buf828_buf828d,LOCK_28_5_0_4096,LOCK_28_5_1_0,buf828_ptr,buf828d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf829_buf829d,LOCK_28_5_2_0,LOCK_28_5_3_4096,buf829_ptr,buf829d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf830_buf830d,LOCK_28_5_4_0,LOCK_28_5_5_4096,buf830_ptr,buf830d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf828_buf828d),get_input_window_float(window_buf829_buf829d),get_output_window_float(window_buf830_buf830d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf828_buf828d,LOCK_28_5_0_4096,LOCK_28_5_1_0,buf828_ptr,buf828d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf829_buf829d,LOCK_28_5_2_0,LOCK_28_5_3_4096,buf829_ptr,buf829d_ptr,0,index, REL_WRITE);
    window_release(window_buf830_buf830d,LOCK_28_5_4_0,LOCK_28_5_5_4096,buf830_ptr,buf830d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_4_bounds > 0)
      --proc_28_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}