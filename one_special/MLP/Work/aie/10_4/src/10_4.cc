// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_4/src/10_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_4_0_4096 48
#define LOCK_10_4_1_4096 49
#define LOCK_10_4_2_0 50
#define LOCK_10_4_3_0 51
#define LOCK_10_5_0_0 32
#define LOCK_10_5_1_4096 33

// Declare shared memory buffers
v4float buf1044[256];
v4float buf1044d[256];
v4float buf1045[256];
v4float buf1045d[256];
v4float buf1046[256];
v4float buf1046d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1044_buf1044d[1];
  window_datatype * buf1044_ptr = (window_datatype * )buf1044;
  window_datatype * buf1044d_ptr = (window_datatype * )buf1044d;
  window_init(window_buf1044_buf1044d, 1, buf1044, LOCK_10_4_0_4096, buf1044d, LOCK_10_4_1_4096, 256, 256);
  window_internal window_buf1045_buf1045d[1];
  window_datatype * buf1045_ptr = (window_datatype * )buf1045;
  window_datatype * buf1045d_ptr = (window_datatype * )buf1045d;
  window_init(window_buf1045_buf1045d, 1, buf1045, LOCK_10_4_2_0, buf1045d, LOCK_10_4_3_0, 256, 256);
  window_internal window_buf1046_buf1046d[1];
  window_datatype * buf1046_ptr = (window_datatype * )buf1046;
  window_datatype * buf1046d_ptr = (window_datatype * )buf1046d;
  window_init(window_buf1046_buf1046d, 1, buf1046, LOCK_10_5_0_0, buf1046d, LOCK_10_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_4_bounds = sync_buffer[1];

  while (proc_10_4_bounds)
  {

    // Kernel call : i604:mm_kernel0
    window_acquire(window_buf1044_buf1044d,LOCK_10_4_0_4096,LOCK_10_4_1_4096,buf1044_ptr,buf1044d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1045_buf1045d,LOCK_10_4_2_0,LOCK_10_4_3_0,buf1045_ptr,buf1045d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1046_buf1046d,LOCK_10_5_0_0,LOCK_10_5_1_4096,buf1046_ptr,buf1046d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1044_buf1044d),get_input_window_float(window_buf1045_buf1045d),get_output_window_float(window_buf1046_buf1046d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1044_buf1044d,LOCK_10_4_0_4096,LOCK_10_4_1_4096,buf1044_ptr,buf1044d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1045_buf1045d,LOCK_10_4_2_0,LOCK_10_4_3_0,buf1045_ptr,buf1045d_ptr,0,index, REL_WRITE);
    window_release(window_buf1046_buf1046d,LOCK_10_5_0_0,LOCK_10_5_1_4096,buf1046_ptr,buf1046d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_4_bounds > 0)
      --proc_10_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}