// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_1/src/9_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_2_0_0 32
#define LOCK_9_2_1_0 33
#define LOCK_9_1_2_0 18
#define LOCK_9_1_3_0 19
#define LOCK_9_1_0_0 16
#define LOCK_9_1_1_4096 17
#define LOCK_9_1_4_4096 20
#define LOCK_9_1_5_4096 21

// Declare shared memory buffers
v4float buf86[256];
v4float buf86d[256];
v4float buf87[256];
v4float buf87d[256];
v4float buf88[256];
v4float buf88d[256];
v4float buf89[256];
v4float buf89d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf87_buf87d[1];
  window_datatype * buf87_ptr = (window_datatype * )buf87;
  window_datatype * buf87d_ptr = (window_datatype * )buf87d;
  window_init(window_buf87_buf87d, 1, buf87, LOCK_9_2_0_0, buf87d, LOCK_9_2_1_0, 256, 256);
  window_internal window_buf88_buf88d[1];
  window_datatype * buf88_ptr = (window_datatype * )buf88;
  window_datatype * buf88d_ptr = (window_datatype * )buf88d;
  window_init(window_buf88_buf88d, 1, buf88, LOCK_9_1_2_0, buf88d, LOCK_9_1_3_0, 256, 256);
  window_internal window_buf86_buf86d[1];
  window_datatype * buf86_ptr = (window_datatype * )buf86;
  window_datatype * buf86d_ptr = (window_datatype * )buf86d;
  window_init(window_buf86_buf86d, 1, buf86, LOCK_9_1_0_0, buf86d, LOCK_9_1_1_4096, 256, 256);
  window_internal window_buf89_buf89d[1];
  window_datatype * buf89_ptr = (window_datatype * )buf89;
  window_datatype * buf89d_ptr = (window_datatype * )buf89d;
  window_init(window_buf89_buf89d, 1, buf89, LOCK_9_1_4_4096, buf89d, LOCK_9_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_1_bounds = sync_buffer[1];

  while (proc_9_1_bounds)
  {

    // Kernel call : i125:mm_kernel1
    window_acquire(window_buf87_buf87d,LOCK_9_2_0_0,LOCK_9_2_1_0,buf87_ptr,buf87d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf88_buf88d,LOCK_9_1_2_0,LOCK_9_1_3_0,buf88_ptr,buf88d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf86_buf86d,LOCK_9_1_0_0,LOCK_9_1_1_4096,buf86_ptr,buf86d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf89_buf89d,LOCK_9_1_4_4096,LOCK_9_1_5_4096,buf89_ptr,buf89d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf87_buf87d),get_input_window_float(window_buf88_buf88d),get_input_window_float(window_buf86_buf86d),get_output_window_float(window_buf89_buf89d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf87_buf87d,LOCK_9_2_0_0,LOCK_9_2_1_0,buf87_ptr,buf87d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf88_buf88d,LOCK_9_1_2_0,LOCK_9_1_3_0,buf88_ptr,buf88d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf86_buf86d,LOCK_9_1_0_0,LOCK_9_1_1_4096,buf86_ptr,buf86d_ptr,0,index, REL_WRITE);
    window_release(window_buf89_buf89d,LOCK_9_1_4_4096,LOCK_9_1_5_4096,buf89_ptr,buf89d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_1_bounds > 0)
      --proc_9_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}