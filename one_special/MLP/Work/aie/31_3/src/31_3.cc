// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_3/src/31_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_4_0_0 32
#define LOCK_31_4_1_0 33
#define LOCK_32_3_0_0 48
#define LOCK_32_3_1_0 49
#define LOCK_31_2_0_0 0
#define LOCK_31_2_1_0 1
#define LOCK_31_2_2_0 2
#define LOCK_31_2_3_4096 3

// Declare shared memory buffers
v4float buf356[256];
v4float buf356d[256];
v4float buf357[256];
v4float buf357d[256];
v4float buf358[256];
v4float buf358d[256];
v4float buf359[256];
v4float buf359d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf357_buf357d[1];
  window_datatype * buf357_ptr = (window_datatype * )buf357;
  window_datatype * buf357d_ptr = (window_datatype * )buf357d;
  window_init(window_buf357_buf357d, 1, buf357, LOCK_31_4_0_0, buf357d, LOCK_31_4_1_0, 256, 256);
  window_internal window_buf358_buf358d[1];
  window_datatype * buf358_ptr = (window_datatype * )buf358;
  window_datatype * buf358d_ptr = (window_datatype * )buf358d;
  window_init(window_buf358_buf358d, 1, buf358, LOCK_32_3_0_0, buf358d, LOCK_32_3_1_0, 256, 256);
  window_internal window_buf356_buf356d[1];
  window_datatype * buf356_ptr = (window_datatype * )buf356;
  window_datatype * buf356d_ptr = (window_datatype * )buf356d;
  window_init(window_buf356_buf356d, 1, buf356, LOCK_31_2_0_0, buf356d, LOCK_31_2_1_0, 256, 256);
  window_internal window_buf359_buf359d[1];
  window_datatype * buf359_ptr = (window_datatype * )buf359;
  window_datatype * buf359d_ptr = (window_datatype * )buf359d;
  window_init(window_buf359_buf359d, 1, buf359, LOCK_31_2_2_0, buf359d, LOCK_31_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_3_bounds = sync_buffer[1];

  while (proc_31_3_bounds)
  {

    // Kernel call : i259:mm_kernel1
    window_acquire(window_buf357_buf357d,LOCK_31_4_0_0,LOCK_31_4_1_0,buf357_ptr,buf357d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf358_buf358d,LOCK_32_3_0_0,LOCK_32_3_1_0,buf358_ptr,buf358d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf356_buf356d,LOCK_31_2_0_0,LOCK_31_2_1_0,buf356_ptr,buf356d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf359_buf359d,LOCK_31_2_2_0,LOCK_31_2_3_4096,buf359_ptr,buf359d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf357_buf357d),get_input_window_float(window_buf358_buf358d),get_input_window_float(window_buf356_buf356d),get_output_window_float(window_buf359_buf359d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf357_buf357d,LOCK_31_4_0_0,LOCK_31_4_1_0,buf357_ptr,buf357d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf358_buf358d,LOCK_32_3_0_0,LOCK_32_3_1_0,buf358_ptr,buf358d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf356_buf356d,LOCK_31_2_0_0,LOCK_31_2_1_0,buf356_ptr,buf356d_ptr,0,index, REL_WRITE);
    window_release(window_buf359_buf359d,LOCK_31_2_2_0,LOCK_31_2_3_4096,buf359_ptr,buf359d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_3_bounds > 0)
      --proc_31_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}