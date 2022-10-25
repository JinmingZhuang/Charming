// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_6/src/28_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_7_0_4096 32
#define LOCK_28_7_1_0 33
#define LOCK_28_6_0_0 48
#define LOCK_28_6_1_0 49
#define LOCK_28_5_6_0 6
#define LOCK_28_5_7_4096 7
#define LOCK_28_7_2_0 34
#define LOCK_28_7_3_4096 35

// Declare shared memory buffers
v4float buf833[256];
v4float buf833d[256];
v4float buf834[256];
v4float buf834d[256];
v4float buf835[256];
v4float buf835d[256];
v4float buf836[256];
v4float buf836d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf834_buf834d[1];
  window_datatype * buf834_ptr = (window_datatype * )buf834;
  window_datatype * buf834d_ptr = (window_datatype * )buf834d;
  window_init(window_buf834_buf834d, 1, buf834, LOCK_28_7_0_4096, buf834d, LOCK_28_7_1_0, 256, 256);
  window_internal window_buf835_buf835d[1];
  window_datatype * buf835_ptr = (window_datatype * )buf835;
  window_datatype * buf835d_ptr = (window_datatype * )buf835d;
  window_init(window_buf835_buf835d, 1, buf835, LOCK_28_6_0_0, buf835d, LOCK_28_6_1_0, 256, 256);
  window_internal window_buf833_buf833d[1];
  window_datatype * buf833_ptr = (window_datatype * )buf833;
  window_datatype * buf833d_ptr = (window_datatype * )buf833d;
  window_init(window_buf833_buf833d, 1, buf833, LOCK_28_5_6_0, buf833d, LOCK_28_5_7_4096, 256, 256);
  window_internal window_buf836_buf836d[1];
  window_datatype * buf836_ptr = (window_datatype * )buf836;
  window_datatype * buf836d_ptr = (window_datatype * )buf836d;
  window_init(window_buf836_buf836d, 1, buf836, LOCK_28_7_2_0, buf836d, LOCK_28_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_6_bounds = sync_buffer[1];

  while (proc_28_6_bounds)
  {

    // Kernel call : i498:mm_kernel1
    window_acquire(window_buf834_buf834d,LOCK_28_7_0_4096,LOCK_28_7_1_0,buf834_ptr,buf834d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf835_buf835d,LOCK_28_6_0_0,LOCK_28_6_1_0,buf835_ptr,buf835d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf833_buf833d,LOCK_28_5_6_0,LOCK_28_5_7_4096,buf833_ptr,buf833d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf836_buf836d,LOCK_28_7_2_0,LOCK_28_7_3_4096,buf836_ptr,buf836d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf834_buf834d),get_input_window_float(window_buf835_buf835d),get_input_window_float(window_buf833_buf833d),get_output_window_float(window_buf836_buf836d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf834_buf834d,LOCK_28_7_0_4096,LOCK_28_7_1_0,buf834_ptr,buf834d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf835_buf835d,LOCK_28_6_0_0,LOCK_28_6_1_0,buf835_ptr,buf835d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf833_buf833d,LOCK_28_5_6_0,LOCK_28_5_7_4096,buf833_ptr,buf833d_ptr,0,index, REL_WRITE);
    window_release(window_buf836_buf836d,LOCK_28_7_2_0,LOCK_28_7_3_4096,buf836_ptr,buf836d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_6_bounds > 0)
      --proc_28_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}