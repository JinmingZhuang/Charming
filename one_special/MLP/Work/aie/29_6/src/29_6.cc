// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_6/src/29_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_6_0_4096 48
#define LOCK_29_6_1_0 49
#define LOCK_29_7_0_0 32
#define LOCK_29_7_1_0 33
#define LOCK_29_5_6_4096 6
#define LOCK_29_5_7_4096 7
#define LOCK_29_6_2_0 50
#define LOCK_29_6_3_4096 51

// Declare shared memory buffers
v4float buf821[256];
v4float buf821d[256];
v4float buf822[256];
v4float buf822d[256];
v4float buf823[256];
v4float buf823d[256];
v4float buf824[256];
v4float buf824d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf822_buf822d[1];
  window_datatype * buf822_ptr = (window_datatype * )buf822;
  window_datatype * buf822d_ptr = (window_datatype * )buf822d;
  window_init(window_buf822_buf822d, 1, buf822, LOCK_29_6_0_4096, buf822d, LOCK_29_6_1_0, 256, 256);
  window_internal window_buf823_buf823d[1];
  window_datatype * buf823_ptr = (window_datatype * )buf823;
  window_datatype * buf823d_ptr = (window_datatype * )buf823d;
  window_init(window_buf823_buf823d, 1, buf823, LOCK_29_7_0_0, buf823d, LOCK_29_7_1_0, 256, 256);
  window_internal window_buf821_buf821d[1];
  window_datatype * buf821_ptr = (window_datatype * )buf821;
  window_datatype * buf821d_ptr = (window_datatype * )buf821d;
  window_init(window_buf821_buf821d, 1, buf821, LOCK_29_5_6_4096, buf821d, LOCK_29_5_7_4096, 256, 256);
  window_internal window_buf824_buf824d[1];
  window_datatype * buf824_ptr = (window_datatype * )buf824;
  window_datatype * buf824d_ptr = (window_datatype * )buf824d;
  window_init(window_buf824_buf824d, 1, buf824, LOCK_29_6_2_0, buf824d, LOCK_29_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_6_bounds = sync_buffer[1];

  while (proc_29_6_bounds)
  {

    // Kernel call : i492:mm_kernel1
    window_acquire(window_buf822_buf822d,LOCK_29_6_0_4096,LOCK_29_6_1_0,buf822_ptr,buf822d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf823_buf823d,LOCK_29_7_0_0,LOCK_29_7_1_0,buf823_ptr,buf823d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf821_buf821d,LOCK_29_5_6_4096,LOCK_29_5_7_4096,buf821_ptr,buf821d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf824_buf824d,LOCK_29_6_2_0,LOCK_29_6_3_4096,buf824_ptr,buf824d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf822_buf822d),get_input_window_float(window_buf823_buf823d),get_input_window_float(window_buf821_buf821d),get_output_window_float(window_buf824_buf824d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf822_buf822d,LOCK_29_6_0_4096,LOCK_29_6_1_0,buf822_ptr,buf822d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf823_buf823d,LOCK_29_7_0_0,LOCK_29_7_1_0,buf823_ptr,buf823d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf821_buf821d,LOCK_29_5_6_4096,LOCK_29_5_7_4096,buf821_ptr,buf821d_ptr,0,index, REL_WRITE);
    window_release(window_buf824_buf824d,LOCK_29_6_2_0,LOCK_29_6_3_4096,buf824_ptr,buf824d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_6_bounds > 0)
      --proc_29_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}