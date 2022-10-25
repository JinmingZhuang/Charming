// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_3/src/26_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_26_4_0_0 32
#define LOCK_26_4_1_0 33
#define LOCK_26_3_0_0 16
#define LOCK_26_3_1_0 17
#define LOCK_26_2_2_4096 2
#define LOCK_26_2_3_4096 3
#define LOCK_26_2_4_0 4
#define LOCK_26_2_5_4096 5

// Declare shared memory buffers
v4float buf296[256];
v4float buf296d[256];
v4float buf297[256];
v4float buf297d[256];
v4float buf298[256];
v4float buf298d[256];
v4float buf299[256];
v4float buf299d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf297_buf297d[1];
  window_datatype * buf297_ptr = (window_datatype * )buf297;
  window_datatype * buf297d_ptr = (window_datatype * )buf297d;
  window_init(window_buf297_buf297d, 1, buf297, LOCK_26_4_0_0, buf297d, LOCK_26_4_1_0, 256, 256);
  window_internal window_buf298_buf298d[1];
  window_datatype * buf298_ptr = (window_datatype * )buf298;
  window_datatype * buf298d_ptr = (window_datatype * )buf298d;
  window_init(window_buf298_buf298d, 1, buf298, LOCK_26_3_0_0, buf298d, LOCK_26_3_1_0, 256, 256);
  window_internal window_buf296_buf296d[1];
  window_datatype * buf296_ptr = (window_datatype * )buf296;
  window_datatype * buf296d_ptr = (window_datatype * )buf296d;
  window_init(window_buf296_buf296d, 1, buf296, LOCK_26_2_2_4096, buf296d, LOCK_26_2_3_4096, 256, 256);
  window_internal window_buf299_buf299d[1];
  window_datatype * buf299_ptr = (window_datatype * )buf299;
  window_datatype * buf299d_ptr = (window_datatype * )buf299d;
  window_init(window_buf299_buf299d, 1, buf299, LOCK_26_2_4_0, buf299d, LOCK_26_2_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_3_bounds = sync_buffer[1];

  while (proc_26_3_bounds)
  {

    // Kernel call : i229:mm_kernel1
    window_acquire(window_buf297_buf297d,LOCK_26_4_0_0,LOCK_26_4_1_0,buf297_ptr,buf297d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf298_buf298d,LOCK_26_3_0_0,LOCK_26_3_1_0,buf298_ptr,buf298d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf296_buf296d,LOCK_26_2_2_4096,LOCK_26_2_3_4096,buf296_ptr,buf296d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf299_buf299d,LOCK_26_2_4_0,LOCK_26_2_5_4096,buf299_ptr,buf299d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf297_buf297d),get_input_window_float(window_buf298_buf298d),get_input_window_float(window_buf296_buf296d),get_output_window_float(window_buf299_buf299d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf297_buf297d,LOCK_26_4_0_0,LOCK_26_4_1_0,buf297_ptr,buf297d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf298_buf298d,LOCK_26_3_0_0,LOCK_26_3_1_0,buf298_ptr,buf298d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf296_buf296d,LOCK_26_2_2_4096,LOCK_26_2_3_4096,buf296_ptr,buf296d_ptr,0,index, REL_WRITE);
    window_release(window_buf299_buf299d,LOCK_26_2_4_0,LOCK_26_2_5_4096,buf299_ptr,buf299d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_3_bounds > 0)
      --proc_26_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}