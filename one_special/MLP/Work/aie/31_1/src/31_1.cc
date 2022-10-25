// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_1/src/31_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_32_1_0_0 48
#define LOCK_32_1_1_0 49
#define LOCK_32_1_2_0 50
#define LOCK_32_1_3_4096 51
#define LOCK_31_1_2_4096 18
#define LOCK_31_1_3_4096 19
#define LOCK_31_1_4_4096 20
#define LOCK_31_1_5_4096 21

// Declare shared memory buffers
v4float buf350[256];
v4float buf350d[256];
v4float buf351[256];
v4float buf351d[256];
v4float buf352[256];
v4float buf352d[256];
v4float buf353[256];
v4float buf353d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf351_buf351d[1];
  window_datatype * buf351_ptr = (window_datatype * )buf351;
  window_datatype * buf351d_ptr = (window_datatype * )buf351d;
  window_init(window_buf351_buf351d, 1, buf351, LOCK_32_1_0_0, buf351d, LOCK_32_1_1_0, 256, 256);
  window_internal window_buf352_buf352d[1];
  window_datatype * buf352_ptr = (window_datatype * )buf352;
  window_datatype * buf352d_ptr = (window_datatype * )buf352d;
  window_init(window_buf352_buf352d, 1, buf352, LOCK_32_1_2_0, buf352d, LOCK_32_1_3_4096, 256, 256);
  window_internal window_buf350_buf350d[1];
  window_datatype * buf350_ptr = (window_datatype * )buf350;
  window_datatype * buf350d_ptr = (window_datatype * )buf350d;
  window_init(window_buf350_buf350d, 1, buf350, LOCK_31_1_2_4096, buf350d, LOCK_31_1_3_4096, 256, 256);
  window_internal window_buf353_buf353d[1];
  window_datatype * buf353_ptr = (window_datatype * )buf353;
  window_datatype * buf353d_ptr = (window_datatype * )buf353d;
  window_init(window_buf353_buf353d, 1, buf353, LOCK_31_1_4_4096, buf353d, LOCK_31_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_1_bounds = sync_buffer[1];

  while (proc_31_1_bounds)
  {

    // Kernel call : i257:mm_kernel1
    window_acquire(window_buf351_buf351d,LOCK_32_1_0_0,LOCK_32_1_1_0,buf351_ptr,buf351d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf352_buf352d,LOCK_32_1_2_0,LOCK_32_1_3_4096,buf352_ptr,buf352d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf350_buf350d,LOCK_31_1_2_4096,LOCK_31_1_3_4096,buf350_ptr,buf350d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf353_buf353d,LOCK_31_1_4_4096,LOCK_31_1_5_4096,buf353_ptr,buf353d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf351_buf351d),get_input_window_float(window_buf352_buf352d),get_input_window_float(window_buf350_buf350d),get_output_window_float(window_buf353_buf353d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf351_buf351d,LOCK_32_1_0_0,LOCK_32_1_1_0,buf351_ptr,buf351d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf352_buf352d,LOCK_32_1_2_0,LOCK_32_1_3_4096,buf352_ptr,buf352d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf350_buf350d,LOCK_31_1_2_4096,LOCK_31_1_3_4096,buf350_ptr,buf350d_ptr,0,index, REL_WRITE);
    window_release(window_buf353_buf353d,LOCK_31_1_4_4096,LOCK_31_1_5_4096,buf353_ptr,buf353d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_1_bounds > 0)
      --proc_31_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}