// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_5/src/21_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_5_2_4096 18
#define LOCK_21_5_3_4096 19
#define LOCK_21_5_4_0 20
#define LOCK_21_5_5_0 21
#define LOCK_21_5_0_0 16
#define LOCK_21_5_1_0 17
#define LOCK_21_5_6_4096 22
#define LOCK_21_5_7_4096 23

// Declare shared memory buffers
v4float buf914[256];
v4float buf914d[256];
v4float buf915[256];
v4float buf915d[256];
v4float buf916[256];
v4float buf916d[256];
v4float buf917[256];
v4float buf917d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf915_buf915d[1];
  window_datatype * buf915_ptr = (window_datatype * )buf915;
  window_datatype * buf915d_ptr = (window_datatype * )buf915d;
  window_init(window_buf915_buf915d, 1, buf915, LOCK_21_5_2_4096, buf915d, LOCK_21_5_3_4096, 256, 256);
  window_internal window_buf916_buf916d[1];
  window_datatype * buf916_ptr = (window_datatype * )buf916;
  window_datatype * buf916d_ptr = (window_datatype * )buf916d;
  window_init(window_buf916_buf916d, 1, buf916, LOCK_21_5_4_0, buf916d, LOCK_21_5_5_0, 256, 256);
  window_internal window_buf914_buf914d[1];
  window_datatype * buf914_ptr = (window_datatype * )buf914;
  window_datatype * buf914d_ptr = (window_datatype * )buf914d;
  window_init(window_buf914_buf914d, 1, buf914, LOCK_21_5_0_0, buf914d, LOCK_21_5_1_0, 256, 256);
  window_internal window_buf917_buf917d[1];
  window_datatype * buf917_ptr = (window_datatype * )buf917;
  window_datatype * buf917d_ptr = (window_datatype * )buf917d;
  window_init(window_buf917_buf917d, 1, buf917, LOCK_21_5_6_4096, buf917d, LOCK_21_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_5_bounds = sync_buffer[1];

  while (proc_21_5_bounds)
  {

    // Kernel call : i539:mm_kernel1
    window_acquire(window_buf915_buf915d,LOCK_21_5_2_4096,LOCK_21_5_3_4096,buf915_ptr,buf915d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf916_buf916d,LOCK_21_5_4_0,LOCK_21_5_5_0,buf916_ptr,buf916d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf914_buf914d,LOCK_21_5_0_0,LOCK_21_5_1_0,buf914_ptr,buf914d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf917_buf917d,LOCK_21_5_6_4096,LOCK_21_5_7_4096,buf917_ptr,buf917d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf915_buf915d),get_input_window_float(window_buf916_buf916d),get_input_window_float(window_buf914_buf914d),get_output_window_float(window_buf917_buf917d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf915_buf915d,LOCK_21_5_2_4096,LOCK_21_5_3_4096,buf915_ptr,buf915d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf916_buf916d,LOCK_21_5_4_0,LOCK_21_5_5_0,buf916_ptr,buf916d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf914_buf914d,LOCK_21_5_0_0,LOCK_21_5_1_0,buf914_ptr,buf914d_ptr,0,index, REL_WRITE);
    window_release(window_buf917_buf917d,LOCK_21_5_6_4096,LOCK_21_5_7_4096,buf917_ptr,buf917d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_5_bounds > 0)
      --proc_21_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}