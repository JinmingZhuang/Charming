// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_1/src/28_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_1_0_4096 48
#define LOCK_29_1_1_4096 49
#define LOCK_28_1_4_0 20
#define LOCK_28_1_5_0 21
#define LOCK_28_1_2_4096 18
#define LOCK_28_1_3_4096 19
#define LOCK_28_1_6_0 22
#define LOCK_28_1_7_0 23

// Declare shared memory buffers
v4float buf314[256];
v4float buf314d[256];
v4float buf315[256];
v4float buf315d[256];
v4float buf316[256];
v4float buf316d[256];
v4float buf317[256];
v4float buf317d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf315_buf315d[1];
  window_datatype * buf315_ptr = (window_datatype * )buf315;
  window_datatype * buf315d_ptr = (window_datatype * )buf315d;
  window_init(window_buf315_buf315d, 1, buf315, LOCK_29_1_0_4096, buf315d, LOCK_29_1_1_4096, 256, 256);
  window_internal window_buf316_buf316d[1];
  window_datatype * buf316_ptr = (window_datatype * )buf316;
  window_datatype * buf316d_ptr = (window_datatype * )buf316d;
  window_init(window_buf316_buf316d, 1, buf316, LOCK_28_1_4_0, buf316d, LOCK_28_1_5_0, 256, 256);
  window_internal window_buf314_buf314d[1];
  window_datatype * buf314_ptr = (window_datatype * )buf314;
  window_datatype * buf314d_ptr = (window_datatype * )buf314d;
  window_init(window_buf314_buf314d, 1, buf314, LOCK_28_1_2_4096, buf314d, LOCK_28_1_3_4096, 256, 256);
  window_internal window_buf317_buf317d[1];
  window_datatype * buf317_ptr = (window_datatype * )buf317;
  window_datatype * buf317d_ptr = (window_datatype * )buf317d;
  window_init(window_buf317_buf317d, 1, buf317, LOCK_28_1_6_0, buf317d, LOCK_28_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_1_bounds = sync_buffer[1];

  while (proc_28_1_bounds)
  {

    // Kernel call : i239:mm_kernel1
    window_acquire(window_buf315_buf315d,LOCK_29_1_0_4096,LOCK_29_1_1_4096,buf315_ptr,buf315d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf316_buf316d,LOCK_28_1_4_0,LOCK_28_1_5_0,buf316_ptr,buf316d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf314_buf314d,LOCK_28_1_2_4096,LOCK_28_1_3_4096,buf314_ptr,buf314d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf317_buf317d,LOCK_28_1_6_0,LOCK_28_1_7_0,buf317_ptr,buf317d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf315_buf315d),get_input_window_float(window_buf316_buf316d),get_input_window_float(window_buf314_buf314d),get_output_window_float(window_buf317_buf317d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf315_buf315d,LOCK_29_1_0_4096,LOCK_29_1_1_4096,buf315_ptr,buf315d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf316_buf316d,LOCK_28_1_4_0,LOCK_28_1_5_0,buf316_ptr,buf316d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf314_buf314d,LOCK_28_1_2_4096,LOCK_28_1_3_4096,buf314_ptr,buf314d_ptr,0,index, REL_WRITE);
    window_release(window_buf317_buf317d,LOCK_28_1_6_0,LOCK_28_1_7_0,buf317_ptr,buf317d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_1_bounds > 0)
      --proc_28_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}