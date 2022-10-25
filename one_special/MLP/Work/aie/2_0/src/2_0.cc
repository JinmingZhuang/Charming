// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_0/src/2_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_1_0_0_4096 16
#define LOCK_1_0_1_0 17
#define LOCK_1_0_2_0 18
#define LOCK_1_0_3_4096 19
#define LOCK_2_1_0_0 32
#define LOCK_2_1_1_1376 33

// Declare shared memory buffers
v4float buf0[256];
v4float buf0d[256];
v4float buf1[256];
v4float buf1d[256];
v4float buf2[256];
v4float buf2d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf0_buf0d[1];
  window_datatype * buf0_ptr = (window_datatype * )buf0;
  window_datatype * buf0d_ptr = (window_datatype * )buf0d;
  window_init(window_buf0_buf0d, 1, buf0, LOCK_1_0_0_4096, buf0d, LOCK_1_0_1_0, 256, 256);
  window_internal window_buf1_buf1d[1];
  window_datatype * buf1_ptr = (window_datatype * )buf1;
  window_datatype * buf1d_ptr = (window_datatype * )buf1d;
  window_init(window_buf1_buf1d, 1, buf1, LOCK_1_0_2_0, buf1d, LOCK_1_0_3_4096, 256, 256);
  window_internal window_buf2_buf2d[1];
  window_datatype * buf2_ptr = (window_datatype * )buf2;
  window_datatype * buf2d_ptr = (window_datatype * )buf2d;
  window_init(window_buf2_buf2d, 1, buf2, LOCK_2_1_0_0, buf2d, LOCK_2_1_1_1376, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_0_bounds = sync_buffer[1];

  while (proc_2_0_bounds)
  {

    // Kernel call : i82:mm_kernel0
    window_acquire(window_buf0_buf0d,LOCK_1_0_0_4096,LOCK_1_0_1_0,buf0_ptr,buf0d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1_buf1d,LOCK_1_0_2_0,LOCK_1_0_3_4096,buf1_ptr,buf1d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf2_buf2d,LOCK_2_1_0_0,LOCK_2_1_1_1376,buf2_ptr,buf2d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf0_buf0d),get_input_window_float(window_buf1_buf1d),get_output_window_float(window_buf2_buf2d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf0_buf0d,LOCK_1_0_0_4096,LOCK_1_0_1_0,buf0_ptr,buf0d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1_buf1d,LOCK_1_0_2_0,LOCK_1_0_3_4096,buf1_ptr,buf1d_ptr,0,index, REL_WRITE);
    window_release(window_buf2_buf2d,LOCK_2_1_0_0,LOCK_2_1_1_1376,buf2_ptr,buf2d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_0_bounds > 0)
      --proc_2_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}