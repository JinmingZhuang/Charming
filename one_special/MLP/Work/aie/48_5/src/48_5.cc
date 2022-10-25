// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_5/src/48_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_5_2_4096 18
#define LOCK_48_5_3_4096 19
#define LOCK_48_5_4_0 20
#define LOCK_48_5_5_0 21
#define LOCK_48_5_0_0 16
#define LOCK_48_5_1_0 17
#define LOCK_48_5_6_4096 22
#define LOCK_48_5_7_4096 23

// Declare shared memory buffers
v4float buf590[256];
v4float buf590d[256];
v4float buf591[256];
v4float buf591d[256];
v4float buf592[256];
v4float buf592d[256];
v4float buf593[256];
v4float buf593d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf591_buf591d[1];
  window_datatype * buf591_ptr = (window_datatype * )buf591;
  window_datatype * buf591d_ptr = (window_datatype * )buf591d;
  window_init(window_buf591_buf591d, 1, buf591, LOCK_48_5_2_4096, buf591d, LOCK_48_5_3_4096, 256, 256);
  window_internal window_buf592_buf592d[1];
  window_datatype * buf592_ptr = (window_datatype * )buf592;
  window_datatype * buf592d_ptr = (window_datatype * )buf592d;
  window_init(window_buf592_buf592d, 1, buf592, LOCK_48_5_4_0, buf592d, LOCK_48_5_5_0, 256, 256);
  window_internal window_buf590_buf590d[1];
  window_datatype * buf590_ptr = (window_datatype * )buf590;
  window_datatype * buf590d_ptr = (window_datatype * )buf590d;
  window_init(window_buf590_buf590d, 1, buf590, LOCK_48_5_0_0, buf590d, LOCK_48_5_1_0, 256, 256);
  window_internal window_buf593_buf593d[1];
  window_datatype * buf593_ptr = (window_datatype * )buf593;
  window_datatype * buf593d_ptr = (window_datatype * )buf593d;
  window_init(window_buf593_buf593d, 1, buf593, LOCK_48_5_6_4096, buf593d, LOCK_48_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_5_bounds = sync_buffer[1];

  while (proc_48_5_bounds)
  {

    // Kernel call : i377:mm_kernel1
    window_acquire(window_buf591_buf591d,LOCK_48_5_2_4096,LOCK_48_5_3_4096,buf591_ptr,buf591d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf592_buf592d,LOCK_48_5_4_0,LOCK_48_5_5_0,buf592_ptr,buf592d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf590_buf590d,LOCK_48_5_0_0,LOCK_48_5_1_0,buf590_ptr,buf590d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf593_buf593d,LOCK_48_5_6_4096,LOCK_48_5_7_4096,buf593_ptr,buf593d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf591_buf591d),get_input_window_float(window_buf592_buf592d),get_input_window_float(window_buf590_buf590d),get_output_window_float(window_buf593_buf593d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf591_buf591d,LOCK_48_5_2_4096,LOCK_48_5_3_4096,buf591_ptr,buf591d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf592_buf592d,LOCK_48_5_4_0,LOCK_48_5_5_0,buf592_ptr,buf592d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf590_buf590d,LOCK_48_5_0_0,LOCK_48_5_1_0,buf590_ptr,buf590d_ptr,0,index, REL_WRITE);
    window_release(window_buf593_buf593d,LOCK_48_5_6_4096,LOCK_48_5_7_4096,buf593_ptr,buf593d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_5_bounds > 0)
      --proc_48_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}