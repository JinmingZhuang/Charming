// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_0/src/6_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_0_0_0 48
#define LOCK_6_0_1_0 49
#define LOCK_6_1_0_0 32
#define LOCK_6_1_1_0 33
#define LOCK_6_1_2_0 34
#define LOCK_6_1_3_4096 35

// Declare shared memory buffers
v4float buf48[256];
v4float buf48d[256];
v4float buf49[256];
v4float buf49d[256];
v4float buf50[256];
v4float buf50d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf48_buf48d[1];
  window_datatype * buf48_ptr = (window_datatype * )buf48;
  window_datatype * buf48d_ptr = (window_datatype * )buf48d;
  window_init(window_buf48_buf48d, 1, buf48, LOCK_6_0_0_0, buf48d, LOCK_6_0_1_0, 256, 256);
  window_internal window_buf49_buf49d[1];
  window_datatype * buf49_ptr = (window_datatype * )buf49;
  window_datatype * buf49d_ptr = (window_datatype * )buf49d;
  window_init(window_buf49_buf49d, 1, buf49, LOCK_6_1_0_0, buf49d, LOCK_6_1_1_0, 256, 256);
  window_internal window_buf50_buf50d[1];
  window_datatype * buf50_ptr = (window_datatype * )buf50;
  window_datatype * buf50d_ptr = (window_datatype * )buf50d;
  window_init(window_buf50_buf50d, 1, buf50, LOCK_6_1_2_0, buf50d, LOCK_6_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_0_bounds = sync_buffer[1];

  while (proc_6_0_bounds)
  {

    // Kernel call : i106:mm_kernel0
    window_acquire(window_buf48_buf48d,LOCK_6_0_0_0,LOCK_6_0_1_0,buf48_ptr,buf48d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf49_buf49d,LOCK_6_1_0_0,LOCK_6_1_1_0,buf49_ptr,buf49d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf50_buf50d,LOCK_6_1_2_0,LOCK_6_1_3_4096,buf50_ptr,buf50d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf48_buf48d),get_input_window_float(window_buf49_buf49d),get_output_window_float(window_buf50_buf50d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf48_buf48d,LOCK_6_0_0_0,LOCK_6_0_1_0,buf48_ptr,buf48d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf49_buf49d,LOCK_6_1_0_0,LOCK_6_1_1_0,buf49_ptr,buf49d_ptr,0,index, REL_WRITE);
    window_release(window_buf50_buf50d,LOCK_6_1_2_0,LOCK_6_1_3_4096,buf50_ptr,buf50d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_0_bounds > 0)
      --proc_6_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}