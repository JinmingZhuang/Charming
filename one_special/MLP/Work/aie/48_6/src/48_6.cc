// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_6/src/48_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_6_0_0 48
#define LOCK_48_6_1_0 49
#define LOCK_48_7_0_4096 32
#define LOCK_48_7_1_0 33
#define LOCK_48_5_6_4096 6
#define LOCK_48_5_7_4096 7
#define LOCK_48_7_2_4096 34
#define LOCK_48_7_3_4096 35

// Declare shared memory buffers
v4float buf593[256];
v4float buf593d[256];
v4float buf594[256];
v4float buf594d[256];
v4float buf595[256];
v4float buf595d[256];
v4float buf596[256];
v4float buf596d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf594_buf594d[1];
  window_datatype * buf594_ptr = (window_datatype * )buf594;
  window_datatype * buf594d_ptr = (window_datatype * )buf594d;
  window_init(window_buf594_buf594d, 1, buf594, LOCK_48_6_0_0, buf594d, LOCK_48_6_1_0, 256, 256);
  window_internal window_buf595_buf595d[1];
  window_datatype * buf595_ptr = (window_datatype * )buf595;
  window_datatype * buf595d_ptr = (window_datatype * )buf595d;
  window_init(window_buf595_buf595d, 1, buf595, LOCK_48_7_0_4096, buf595d, LOCK_48_7_1_0, 256, 256);
  window_internal window_buf593_buf593d[1];
  window_datatype * buf593_ptr = (window_datatype * )buf593;
  window_datatype * buf593d_ptr = (window_datatype * )buf593d;
  window_init(window_buf593_buf593d, 1, buf593, LOCK_48_5_6_4096, buf593d, LOCK_48_5_7_4096, 256, 256);
  window_internal window_buf596_buf596d[1];
  window_datatype * buf596_ptr = (window_datatype * )buf596;
  window_datatype * buf596d_ptr = (window_datatype * )buf596d;
  window_init(window_buf596_buf596d, 1, buf596, LOCK_48_7_2_4096, buf596d, LOCK_48_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_6_bounds = sync_buffer[1];

  while (proc_48_6_bounds)
  {

    // Kernel call : i378:mm_kernel1
    window_acquire(window_buf594_buf594d,LOCK_48_6_0_0,LOCK_48_6_1_0,buf594_ptr,buf594d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf595_buf595d,LOCK_48_7_0_4096,LOCK_48_7_1_0,buf595_ptr,buf595d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf593_buf593d,LOCK_48_5_6_4096,LOCK_48_5_7_4096,buf593_ptr,buf593d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf596_buf596d,LOCK_48_7_2_4096,LOCK_48_7_3_4096,buf596_ptr,buf596d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf594_buf594d),get_input_window_float(window_buf595_buf595d),get_input_window_float(window_buf593_buf593d),get_output_window_float(window_buf596_buf596d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf594_buf594d,LOCK_48_6_0_0,LOCK_48_6_1_0,buf594_ptr,buf594d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf595_buf595d,LOCK_48_7_0_4096,LOCK_48_7_1_0,buf595_ptr,buf595d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf593_buf593d,LOCK_48_5_6_4096,LOCK_48_5_7_4096,buf593_ptr,buf593d_ptr,0,index, REL_WRITE);
    window_release(window_buf596_buf596d,LOCK_48_7_2_4096,LOCK_48_7_3_4096,buf596_ptr,buf596d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_6_bounds > 0)
      --proc_48_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}