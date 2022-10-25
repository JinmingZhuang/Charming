// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_0/src/22_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_0_0_0 48
#define LOCK_22_0_1_0 49
#define LOCK_21_0_2_4096 18
#define LOCK_21_0_3_4096 19
#define LOCK_22_1_2_4096 34
#define LOCK_22_1_3_4096 35

// Declare shared memory buffers
v4float buf240[256];
v4float buf240d[256];
v4float buf241[256];
v4float buf241d[256];
v4float buf242[256];
v4float buf242d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf240_buf240d[1];
  window_datatype * buf240_ptr = (window_datatype * )buf240;
  window_datatype * buf240d_ptr = (window_datatype * )buf240d;
  window_init(window_buf240_buf240d, 1, buf240, LOCK_22_0_0_0, buf240d, LOCK_22_0_1_0, 256, 256);
  window_internal window_buf241_buf241d[1];
  window_datatype * buf241_ptr = (window_datatype * )buf241;
  window_datatype * buf241d_ptr = (window_datatype * )buf241d;
  window_init(window_buf241_buf241d, 1, buf241, LOCK_21_0_2_4096, buf241d, LOCK_21_0_3_4096, 256, 256);
  window_internal window_buf242_buf242d[1];
  window_datatype * buf242_ptr = (window_datatype * )buf242;
  window_datatype * buf242d_ptr = (window_datatype * )buf242d;
  window_init(window_buf242_buf242d, 1, buf242, LOCK_22_1_2_4096, buf242d, LOCK_22_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_0_bounds = sync_buffer[1];

  while (proc_22_0_bounds)
  {

    // Kernel call : i202:mm_kernel0
    window_acquire(window_buf240_buf240d,LOCK_22_0_0_0,LOCK_22_0_1_0,buf240_ptr,buf240d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf241_buf241d,LOCK_21_0_2_4096,LOCK_21_0_3_4096,buf241_ptr,buf241d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf242_buf242d,LOCK_22_1_2_4096,LOCK_22_1_3_4096,buf242_ptr,buf242d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf240_buf240d),get_input_window_float(window_buf241_buf241d),get_output_window_float(window_buf242_buf242d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf240_buf240d,LOCK_22_0_0_0,LOCK_22_0_1_0,buf240_ptr,buf240d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf241_buf241d,LOCK_21_0_2_4096,LOCK_21_0_3_4096,buf241_ptr,buf241d_ptr,0,index, REL_WRITE);
    window_release(window_buf242_buf242d,LOCK_22_1_2_4096,LOCK_22_1_3_4096,buf242_ptr,buf242d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_0_bounds > 0)
      --proc_22_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}