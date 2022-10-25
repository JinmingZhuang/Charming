// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_0/src/5_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_0_0_0 48
#define LOCK_5_0_1_0 49
#define LOCK_5_1_0_0 32
#define LOCK_5_1_1_4096 33
#define LOCK_5_1_2_4096 34
#define LOCK_5_1_3_0 35

// Declare shared memory buffers
v4float buf36[256];
v4float buf36d[256];
v4float buf37[256];
v4float buf37d[256];
v4float buf38[256];
v4float buf38d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf36_buf36d[1];
  window_datatype * buf36_ptr = (window_datatype * )buf36;
  window_datatype * buf36d_ptr = (window_datatype * )buf36d;
  window_init(window_buf36_buf36d, 1, buf36, LOCK_5_0_0_0, buf36d, LOCK_5_0_1_0, 256, 256);
  window_internal window_buf37_buf37d[1];
  window_datatype * buf37_ptr = (window_datatype * )buf37;
  window_datatype * buf37d_ptr = (window_datatype * )buf37d;
  window_init(window_buf37_buf37d, 1, buf37, LOCK_5_1_0_0, buf37d, LOCK_5_1_1_4096, 256, 256);
  window_internal window_buf38_buf38d[1];
  window_datatype * buf38_ptr = (window_datatype * )buf38;
  window_datatype * buf38d_ptr = (window_datatype * )buf38d;
  window_init(window_buf38_buf38d, 1, buf38, LOCK_5_1_2_4096, buf38d, LOCK_5_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_0_bounds = sync_buffer[1];

  while (proc_5_0_bounds)
  {

    // Kernel call : i100:mm_kernel0
    window_acquire(window_buf36_buf36d,LOCK_5_0_0_0,LOCK_5_0_1_0,buf36_ptr,buf36d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf37_buf37d,LOCK_5_1_0_0,LOCK_5_1_1_4096,buf37_ptr,buf37d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf38_buf38d,LOCK_5_1_2_4096,LOCK_5_1_3_0,buf38_ptr,buf38d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf36_buf36d),get_input_window_float(window_buf37_buf37d),get_output_window_float(window_buf38_buf38d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf36_buf36d,LOCK_5_0_0_0,LOCK_5_0_1_0,buf36_ptr,buf36d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf37_buf37d,LOCK_5_1_0_0,LOCK_5_1_1_4096,buf37_ptr,buf37d_ptr,0,index, REL_WRITE);
    window_release(window_buf38_buf38d,LOCK_5_1_2_4096,LOCK_5_1_3_0,buf38_ptr,buf38d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_0_bounds > 0)
      --proc_5_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}