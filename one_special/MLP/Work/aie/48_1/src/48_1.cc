// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_1/src/48_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_0_0_0 0
#define LOCK_48_0_1_0 1
#define LOCK_49_1_0_0 48
#define LOCK_49_1_1_0 49
#define LOCK_48_1_4_4096 20
#define LOCK_48_1_5_0 21
#define LOCK_48_1_6_0 22
#define LOCK_48_1_7_0 23

// Declare shared memory buffers
v4float buf554[256];
v4float buf554d[256];
v4float buf555[256];
v4float buf555d[256];
v4float buf556[256];
v4float buf556d[256];
v4float buf557[256];
v4float buf557d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf555_buf555d[1];
  window_datatype * buf555_ptr = (window_datatype * )buf555;
  window_datatype * buf555d_ptr = (window_datatype * )buf555d;
  window_init(window_buf555_buf555d, 1, buf555, LOCK_48_0_0_0, buf555d, LOCK_48_0_1_0, 256, 256);
  window_internal window_buf556_buf556d[1];
  window_datatype * buf556_ptr = (window_datatype * )buf556;
  window_datatype * buf556d_ptr = (window_datatype * )buf556d;
  window_init(window_buf556_buf556d, 1, buf556, LOCK_49_1_0_0, buf556d, LOCK_49_1_1_0, 256, 256);
  window_internal window_buf554_buf554d[1];
  window_datatype * buf554_ptr = (window_datatype * )buf554;
  window_datatype * buf554d_ptr = (window_datatype * )buf554d;
  window_init(window_buf554_buf554d, 1, buf554, LOCK_48_1_4_4096, buf554d, LOCK_48_1_5_0, 256, 256);
  window_internal window_buf557_buf557d[1];
  window_datatype * buf557_ptr = (window_datatype * )buf557;
  window_datatype * buf557d_ptr = (window_datatype * )buf557d;
  window_init(window_buf557_buf557d, 1, buf557, LOCK_48_1_6_0, buf557d, LOCK_48_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_1_bounds = sync_buffer[1];

  while (proc_48_1_bounds)
  {

    // Kernel call : i359:mm_kernel1
    window_acquire(window_buf555_buf555d,LOCK_48_0_0_0,LOCK_48_0_1_0,buf555_ptr,buf555d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf556_buf556d,LOCK_49_1_0_0,LOCK_49_1_1_0,buf556_ptr,buf556d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf554_buf554d,LOCK_48_1_4_4096,LOCK_48_1_5_0,buf554_ptr,buf554d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf557_buf557d,LOCK_48_1_6_0,LOCK_48_1_7_0,buf557_ptr,buf557d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf555_buf555d),get_input_window_float(window_buf556_buf556d),get_input_window_float(window_buf554_buf554d),get_output_window_float(window_buf557_buf557d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf555_buf555d,LOCK_48_0_0_0,LOCK_48_0_1_0,buf555_ptr,buf555d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf556_buf556d,LOCK_49_1_0_0,LOCK_49_1_1_0,buf556_ptr,buf556d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf554_buf554d,LOCK_48_1_4_4096,LOCK_48_1_5_0,buf554_ptr,buf554d_ptr,0,index, REL_WRITE);
    window_release(window_buf557_buf557d,LOCK_48_1_6_0,LOCK_48_1_7_0,buf557_ptr,buf557d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_1_bounds > 0)
      --proc_48_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}