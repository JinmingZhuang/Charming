// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_5/src/28_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_4_0_0 0
#define LOCK_28_4_1_0 1
#define LOCK_28_4_2_4096 2
#define LOCK_28_4_3_4096 3
#define LOCK_28_5_4_0 20
#define LOCK_28_5_5_4096 21
#define LOCK_28_5_6_0 22
#define LOCK_28_5_7_4096 23

// Declare shared memory buffers
v4float buf830[256];
v4float buf830d[256];
v4float buf831[256];
v4float buf831d[256];
v4float buf832[256];
v4float buf832d[256];
v4float buf833[256];
v4float buf833d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf831_buf831d[1];
  window_datatype * buf831_ptr = (window_datatype * )buf831;
  window_datatype * buf831d_ptr = (window_datatype * )buf831d;
  window_init(window_buf831_buf831d, 1, buf831, LOCK_28_4_0_0, buf831d, LOCK_28_4_1_0, 256, 256);
  window_internal window_buf832_buf832d[1];
  window_datatype * buf832_ptr = (window_datatype * )buf832;
  window_datatype * buf832d_ptr = (window_datatype * )buf832d;
  window_init(window_buf832_buf832d, 1, buf832, LOCK_28_4_2_4096, buf832d, LOCK_28_4_3_4096, 256, 256);
  window_internal window_buf830_buf830d[1];
  window_datatype * buf830_ptr = (window_datatype * )buf830;
  window_datatype * buf830d_ptr = (window_datatype * )buf830d;
  window_init(window_buf830_buf830d, 1, buf830, LOCK_28_5_4_0, buf830d, LOCK_28_5_5_4096, 256, 256);
  window_internal window_buf833_buf833d[1];
  window_datatype * buf833_ptr = (window_datatype * )buf833;
  window_datatype * buf833d_ptr = (window_datatype * )buf833d;
  window_init(window_buf833_buf833d, 1, buf833, LOCK_28_5_6_0, buf833d, LOCK_28_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_5_bounds = sync_buffer[1];

  while (proc_28_5_bounds)
  {

    // Kernel call : i497:mm_kernel1
    window_acquire(window_buf831_buf831d,LOCK_28_4_0_0,LOCK_28_4_1_0,buf831_ptr,buf831d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf832_buf832d,LOCK_28_4_2_4096,LOCK_28_4_3_4096,buf832_ptr,buf832d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf830_buf830d,LOCK_28_5_4_0,LOCK_28_5_5_4096,buf830_ptr,buf830d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf833_buf833d,LOCK_28_5_6_0,LOCK_28_5_7_4096,buf833_ptr,buf833d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf831_buf831d),get_input_window_float(window_buf832_buf832d),get_input_window_float(window_buf830_buf830d),get_output_window_float(window_buf833_buf833d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf831_buf831d,LOCK_28_4_0_0,LOCK_28_4_1_0,buf831_ptr,buf831d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf832_buf832d,LOCK_28_4_2_4096,LOCK_28_4_3_4096,buf832_ptr,buf832d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf830_buf830d,LOCK_28_5_4_0,LOCK_28_5_5_4096,buf830_ptr,buf830d_ptr,0,index, REL_WRITE);
    window_release(window_buf833_buf833d,LOCK_28_5_6_0,LOCK_28_5_7_4096,buf833_ptr,buf833d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_5_bounds > 0)
      --proc_28_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}