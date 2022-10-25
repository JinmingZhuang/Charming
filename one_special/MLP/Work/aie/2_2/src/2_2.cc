// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_2/src/2_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_1_2_0_4096 16
#define LOCK_1_2_1_0 17
#define LOCK_1_2_2_0 18
#define LOCK_1_2_3_4096 19
#define LOCK_2_2_0_0 48
#define LOCK_2_2_1_0 49
#define LOCK_2_3_0_0 32
#define LOCK_2_3_1_0 33

// Declare shared memory buffers
v4float buf5[256];
v4float buf5d[256];
v4float buf6[256];
v4float buf6d[256];
v4float buf7[256];
v4float buf7d[256];
v4float buf8[256];
v4float buf8d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf6_buf6d[1];
  window_datatype * buf6_ptr = (window_datatype * )buf6;
  window_datatype * buf6d_ptr = (window_datatype * )buf6d;
  window_init(window_buf6_buf6d, 1, buf6, LOCK_1_2_0_4096, buf6d, LOCK_1_2_1_0, 256, 256);
  window_internal window_buf7_buf7d[1];
  window_datatype * buf7_ptr = (window_datatype * )buf7;
  window_datatype * buf7d_ptr = (window_datatype * )buf7d;
  window_init(window_buf7_buf7d, 1, buf7, LOCK_1_2_2_0, buf7d, LOCK_1_2_3_4096, 256, 256);
  window_internal window_buf5_buf5d[1];
  window_datatype * buf5_ptr = (window_datatype * )buf5;
  window_datatype * buf5d_ptr = (window_datatype * )buf5d;
  window_init(window_buf5_buf5d, 1, buf5, LOCK_2_2_0_0, buf5d, LOCK_2_2_1_0, 256, 256);
  window_internal window_buf8_buf8d[1];
  window_datatype * buf8_ptr = (window_datatype * )buf8;
  window_datatype * buf8d_ptr = (window_datatype * )buf8d;
  window_init(window_buf8_buf8d, 1, buf8, LOCK_2_3_0_0, buf8d, LOCK_2_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_2_bounds = sync_buffer[1];

  while (proc_2_2_bounds)
  {

    // Kernel call : i84:mm_kernel1
    window_acquire(window_buf6_buf6d,LOCK_1_2_0_4096,LOCK_1_2_1_0,buf6_ptr,buf6d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf7_buf7d,LOCK_1_2_2_0,LOCK_1_2_3_4096,buf7_ptr,buf7d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf5_buf5d,LOCK_2_2_0_0,LOCK_2_2_1_0,buf5_ptr,buf5d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf8_buf8d,LOCK_2_3_0_0,LOCK_2_3_1_0,buf8_ptr,buf8d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf6_buf6d),get_input_window_float(window_buf7_buf7d),get_input_window_float(window_buf5_buf5d),get_output_window_float(window_buf8_buf8d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf6_buf6d,LOCK_1_2_0_4096,LOCK_1_2_1_0,buf6_ptr,buf6d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf7_buf7d,LOCK_1_2_2_0,LOCK_1_2_3_4096,buf7_ptr,buf7d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf5_buf5d,LOCK_2_2_0_0,LOCK_2_2_1_0,buf5_ptr,buf5d_ptr,0,index, REL_WRITE);
    window_release(window_buf8_buf8d,LOCK_2_3_0_0,LOCK_2_3_1_0,buf8_ptr,buf8d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_2_bounds > 0)
      --proc_2_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}