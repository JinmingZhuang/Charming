// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_6/src/42_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_41_6_0_0 16
#define LOCK_41_6_1_0 17
#define LOCK_42_5_6_0 6
#define LOCK_42_5_7_0 7
#define LOCK_42_5_4_0 4
#define LOCK_42_5_5_4096 5
#define LOCK_42_6_2_4096 50
#define LOCK_42_6_3_4096 51

// Declare shared memory buffers
v4float buf665[256];
v4float buf665d[256];
v4float buf666[256];
v4float buf666d[256];
v4float buf667[256];
v4float buf667d[256];
v4float buf668[256];
v4float buf668d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf666_buf666d[1];
  window_datatype * buf666_ptr = (window_datatype * )buf666;
  window_datatype * buf666d_ptr = (window_datatype * )buf666d;
  window_init(window_buf666_buf666d, 1, buf666, LOCK_41_6_0_0, buf666d, LOCK_41_6_1_0, 256, 256);
  window_internal window_buf667_buf667d[1];
  window_datatype * buf667_ptr = (window_datatype * )buf667;
  window_datatype * buf667d_ptr = (window_datatype * )buf667d;
  window_init(window_buf667_buf667d, 1, buf667, LOCK_42_5_6_0, buf667d, LOCK_42_5_7_0, 256, 256);
  window_internal window_buf665_buf665d[1];
  window_datatype * buf665_ptr = (window_datatype * )buf665;
  window_datatype * buf665d_ptr = (window_datatype * )buf665d;
  window_init(window_buf665_buf665d, 1, buf665, LOCK_42_5_4_0, buf665d, LOCK_42_5_5_4096, 256, 256);
  window_internal window_buf668_buf668d[1];
  window_datatype * buf668_ptr = (window_datatype * )buf668;
  window_datatype * buf668d_ptr = (window_datatype * )buf668d;
  window_init(window_buf668_buf668d, 1, buf668, LOCK_42_6_2_4096, buf668d, LOCK_42_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_6_bounds = sync_buffer[1];

  while (proc_42_6_bounds)
  {

    // Kernel call : i414:mm_kernel1
    window_acquire(window_buf666_buf666d,LOCK_41_6_0_0,LOCK_41_6_1_0,buf666_ptr,buf666d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf667_buf667d,LOCK_42_5_6_0,LOCK_42_5_7_0,buf667_ptr,buf667d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf665_buf665d,LOCK_42_5_4_0,LOCK_42_5_5_4096,buf665_ptr,buf665d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf668_buf668d,LOCK_42_6_2_4096,LOCK_42_6_3_4096,buf668_ptr,buf668d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf666_buf666d),get_input_window_float(window_buf667_buf667d),get_input_window_float(window_buf665_buf665d),get_output_window_float(window_buf668_buf668d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf666_buf666d,LOCK_41_6_0_0,LOCK_41_6_1_0,buf666_ptr,buf666d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf667_buf667d,LOCK_42_5_6_0,LOCK_42_5_7_0,buf667_ptr,buf667d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf665_buf665d,LOCK_42_5_4_0,LOCK_42_5_5_4096,buf665_ptr,buf665d_ptr,0,index, REL_WRITE);
    window_release(window_buf668_buf668d,LOCK_42_6_2_4096,LOCK_42_6_3_4096,buf668_ptr,buf668d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_6_bounds > 0)
      --proc_42_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}