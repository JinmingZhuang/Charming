// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_4/src/31_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_4_2_4096 50
#define LOCK_31_4_3_4096 51
#define LOCK_31_3_2_4096 2
#define LOCK_31_3_3_4096 3
#define LOCK_31_5_0_4096 32
#define LOCK_31_5_1_0 33

// Declare shared memory buffers
v4float buf792[256];
v4float buf792d[256];
v4float buf793[256];
v4float buf793d[256];
v4float buf794[256];
v4float buf794d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf792_buf792d[1];
  window_datatype * buf792_ptr = (window_datatype * )buf792;
  window_datatype * buf792d_ptr = (window_datatype * )buf792d;
  window_init(window_buf792_buf792d, 1, buf792, LOCK_31_4_2_4096, buf792d, LOCK_31_4_3_4096, 256, 256);
  window_internal window_buf793_buf793d[1];
  window_datatype * buf793_ptr = (window_datatype * )buf793;
  window_datatype * buf793d_ptr = (window_datatype * )buf793d;
  window_init(window_buf793_buf793d, 1, buf793, LOCK_31_3_2_4096, buf793d, LOCK_31_3_3_4096, 256, 256);
  window_internal window_buf794_buf794d[1];
  window_datatype * buf794_ptr = (window_datatype * )buf794;
  window_datatype * buf794d_ptr = (window_datatype * )buf794d;
  window_init(window_buf794_buf794d, 1, buf794, LOCK_31_5_0_4096, buf794d, LOCK_31_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_4_bounds = sync_buffer[1];

  while (proc_31_4_bounds)
  {

    // Kernel call : i478:mm_kernel0
    window_acquire(window_buf792_buf792d,LOCK_31_4_2_4096,LOCK_31_4_3_4096,buf792_ptr,buf792d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf793_buf793d,LOCK_31_3_2_4096,LOCK_31_3_3_4096,buf793_ptr,buf793d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf794_buf794d,LOCK_31_5_0_4096,LOCK_31_5_1_0,buf794_ptr,buf794d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf792_buf792d),get_input_window_float(window_buf793_buf793d),get_output_window_float(window_buf794_buf794d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf792_buf792d,LOCK_31_4_2_4096,LOCK_31_4_3_4096,buf792_ptr,buf792d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf793_buf793d,LOCK_31_3_2_4096,LOCK_31_3_3_4096,buf793_ptr,buf793d_ptr,0,index, REL_WRITE);
    window_release(window_buf794_buf794d,LOCK_31_5_0_4096,LOCK_31_5_1_0,buf794_ptr,buf794d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_4_bounds > 0)
      --proc_31_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}