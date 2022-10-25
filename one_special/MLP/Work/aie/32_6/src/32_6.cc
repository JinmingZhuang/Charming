// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_6/src/32_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_6_0_0 16
#define LOCK_31_6_1_0 17
#define LOCK_32_7_0_4096 32
#define LOCK_32_7_1_0 33
#define LOCK_32_5_4_0 4
#define LOCK_32_5_5_4096 5
#define LOCK_32_7_2_4096 34
#define LOCK_32_7_3_4096 35

// Declare shared memory buffers
v4float buf785[256];
v4float buf785d[256];
v4float buf786[256];
v4float buf786d[256];
v4float buf787[256];
v4float buf787d[256];
v4float buf788[256];
v4float buf788d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf786_buf786d[1];
  window_datatype * buf786_ptr = (window_datatype * )buf786;
  window_datatype * buf786d_ptr = (window_datatype * )buf786d;
  window_init(window_buf786_buf786d, 1, buf786, LOCK_31_6_0_0, buf786d, LOCK_31_6_1_0, 256, 256);
  window_internal window_buf787_buf787d[1];
  window_datatype * buf787_ptr = (window_datatype * )buf787;
  window_datatype * buf787d_ptr = (window_datatype * )buf787d;
  window_init(window_buf787_buf787d, 1, buf787, LOCK_32_7_0_4096, buf787d, LOCK_32_7_1_0, 256, 256);
  window_internal window_buf785_buf785d[1];
  window_datatype * buf785_ptr = (window_datatype * )buf785;
  window_datatype * buf785d_ptr = (window_datatype * )buf785d;
  window_init(window_buf785_buf785d, 1, buf785, LOCK_32_5_4_0, buf785d, LOCK_32_5_5_4096, 256, 256);
  window_internal window_buf788_buf788d[1];
  window_datatype * buf788_ptr = (window_datatype * )buf788;
  window_datatype * buf788d_ptr = (window_datatype * )buf788d;
  window_init(window_buf788_buf788d, 1, buf788, LOCK_32_7_2_4096, buf788d, LOCK_32_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_6_bounds = sync_buffer[1];

  while (proc_32_6_bounds)
  {

    // Kernel call : i474:mm_kernel1
    window_acquire(window_buf786_buf786d,LOCK_31_6_0_0,LOCK_31_6_1_0,buf786_ptr,buf786d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf787_buf787d,LOCK_32_7_0_4096,LOCK_32_7_1_0,buf787_ptr,buf787d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf785_buf785d,LOCK_32_5_4_0,LOCK_32_5_5_4096,buf785_ptr,buf785d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf788_buf788d,LOCK_32_7_2_4096,LOCK_32_7_3_4096,buf788_ptr,buf788d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf786_buf786d),get_input_window_float(window_buf787_buf787d),get_input_window_float(window_buf785_buf785d),get_output_window_float(window_buf788_buf788d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf786_buf786d,LOCK_31_6_0_0,LOCK_31_6_1_0,buf786_ptr,buf786d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf787_buf787d,LOCK_32_7_0_4096,LOCK_32_7_1_0,buf787_ptr,buf787d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf785_buf785d,LOCK_32_5_4_0,LOCK_32_5_5_4096,buf785_ptr,buf785d_ptr,0,index, REL_WRITE);
    window_release(window_buf788_buf788d,LOCK_32_7_2_4096,LOCK_32_7_3_4096,buf788_ptr,buf788d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_6_bounds > 0)
      --proc_32_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}