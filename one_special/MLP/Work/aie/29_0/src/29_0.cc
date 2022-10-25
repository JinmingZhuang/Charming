// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_0/src/29_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_0_0_0 48
#define LOCK_29_0_1_0 49
#define LOCK_28_0_2_4096 18
#define LOCK_28_0_3_4096 19
#define LOCK_29_1_2_4096 34
#define LOCK_29_1_3_0 35

// Declare shared memory buffers
v4float buf324[256];
v4float buf324d[256];
v4float buf325[256];
v4float buf325d[256];
v4float buf326[256];
v4float buf326d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf324_buf324d[1];
  window_datatype * buf324_ptr = (window_datatype * )buf324;
  window_datatype * buf324d_ptr = (window_datatype * )buf324d;
  window_init(window_buf324_buf324d, 1, buf324, LOCK_29_0_0_0, buf324d, LOCK_29_0_1_0, 256, 256);
  window_internal window_buf325_buf325d[1];
  window_datatype * buf325_ptr = (window_datatype * )buf325;
  window_datatype * buf325d_ptr = (window_datatype * )buf325d;
  window_init(window_buf325_buf325d, 1, buf325, LOCK_28_0_2_4096, buf325d, LOCK_28_0_3_4096, 256, 256);
  window_internal window_buf326_buf326d[1];
  window_datatype * buf326_ptr = (window_datatype * )buf326;
  window_datatype * buf326d_ptr = (window_datatype * )buf326d;
  window_init(window_buf326_buf326d, 1, buf326, LOCK_29_1_2_4096, buf326d, LOCK_29_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_0_bounds = sync_buffer[1];

  while (proc_29_0_bounds)
  {

    // Kernel call : i244:mm_kernel0
    window_acquire(window_buf324_buf324d,LOCK_29_0_0_0,LOCK_29_0_1_0,buf324_ptr,buf324d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf325_buf325d,LOCK_28_0_2_4096,LOCK_28_0_3_4096,buf325_ptr,buf325d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf326_buf326d,LOCK_29_1_2_4096,LOCK_29_1_3_0,buf326_ptr,buf326d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf324_buf324d),get_input_window_float(window_buf325_buf325d),get_output_window_float(window_buf326_buf326d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf324_buf324d,LOCK_29_0_0_0,LOCK_29_0_1_0,buf324_ptr,buf324d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf325_buf325d,LOCK_28_0_2_4096,LOCK_28_0_3_4096,buf325_ptr,buf325d_ptr,0,index, REL_WRITE);
    window_release(window_buf326_buf326d,LOCK_29_1_2_4096,LOCK_29_1_3_0,buf326_ptr,buf326d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_0_bounds > 0)
      --proc_29_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}