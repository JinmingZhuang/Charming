// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_4/src/7_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_4_2_4096 18
#define LOCK_6_4_3_4096 19
#define LOCK_7_5_0_4096 32
#define LOCK_7_5_1_0 33
#define LOCK_7_5_2_0 34
#define LOCK_7_5_3_4096 35

// Declare shared memory buffers
v4float buf1080[256];
v4float buf1080d[256];
v4float buf1081[256];
v4float buf1081d[256];
v4float buf1082[256];
v4float buf1082d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1080_buf1080d[1];
  window_datatype * buf1080_ptr = (window_datatype * )buf1080;
  window_datatype * buf1080d_ptr = (window_datatype * )buf1080d;
  window_init(window_buf1080_buf1080d, 1, buf1080, LOCK_6_4_2_4096, buf1080d, LOCK_6_4_3_4096, 256, 256);
  window_internal window_buf1081_buf1081d[1];
  window_datatype * buf1081_ptr = (window_datatype * )buf1081;
  window_datatype * buf1081d_ptr = (window_datatype * )buf1081d;
  window_init(window_buf1081_buf1081d, 1, buf1081, LOCK_7_5_0_4096, buf1081d, LOCK_7_5_1_0, 256, 256);
  window_internal window_buf1082_buf1082d[1];
  window_datatype * buf1082_ptr = (window_datatype * )buf1082;
  window_datatype * buf1082d_ptr = (window_datatype * )buf1082d;
  window_init(window_buf1082_buf1082d, 1, buf1082, LOCK_7_5_2_0, buf1082d, LOCK_7_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_4_bounds = sync_buffer[1];

  while (proc_7_4_bounds)
  {

    // Kernel call : i622:mm_kernel0
    window_acquire(window_buf1080_buf1080d,LOCK_6_4_2_4096,LOCK_6_4_3_4096,buf1080_ptr,buf1080d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1081_buf1081d,LOCK_7_5_0_4096,LOCK_7_5_1_0,buf1081_ptr,buf1081d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1082_buf1082d,LOCK_7_5_2_0,LOCK_7_5_3_4096,buf1082_ptr,buf1082d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1080_buf1080d),get_input_window_float(window_buf1081_buf1081d),get_output_window_float(window_buf1082_buf1082d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1080_buf1080d,LOCK_6_4_2_4096,LOCK_6_4_3_4096,buf1080_ptr,buf1080d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1081_buf1081d,LOCK_7_5_0_4096,LOCK_7_5_1_0,buf1081_ptr,buf1081d_ptr,0,index, REL_WRITE);
    window_release(window_buf1082_buf1082d,LOCK_7_5_2_0,LOCK_7_5_3_4096,buf1082_ptr,buf1082d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_4_bounds > 0)
      --proc_7_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}