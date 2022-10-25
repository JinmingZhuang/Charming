// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_2/src/4_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_3_2_4096 34
#define LOCK_4_3_3_4096 35
#define LOCK_3_2_2_4096 18
#define LOCK_3_2_3_4096 19
#define LOCK_4_1_6_4096 6
#define LOCK_4_1_7_4096 7
#define LOCK_4_2_0_0 48
#define LOCK_4_2_1_0 49

// Declare shared memory buffers
v4float buf29[256];
v4float buf29d[256];
v4float buf30[256];
v4float buf30d[256];
v4float buf31[256];
v4float buf31d[256];
v4float buf32[256];
v4float buf32d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf30_buf30d[1];
  window_datatype * buf30_ptr = (window_datatype * )buf30;
  window_datatype * buf30d_ptr = (window_datatype * )buf30d;
  window_init(window_buf30_buf30d, 1, buf30, LOCK_4_3_2_4096, buf30d, LOCK_4_3_3_4096, 256, 256);
  window_internal window_buf31_buf31d[1];
  window_datatype * buf31_ptr = (window_datatype * )buf31;
  window_datatype * buf31d_ptr = (window_datatype * )buf31d;
  window_init(window_buf31_buf31d, 1, buf31, LOCK_3_2_2_4096, buf31d, LOCK_3_2_3_4096, 256, 256);
  window_internal window_buf29_buf29d[1];
  window_datatype * buf29_ptr = (window_datatype * )buf29;
  window_datatype * buf29d_ptr = (window_datatype * )buf29d;
  window_init(window_buf29_buf29d, 1, buf29, LOCK_4_1_6_4096, buf29d, LOCK_4_1_7_4096, 256, 256);
  window_internal window_buf32_buf32d[1];
  window_datatype * buf32_ptr = (window_datatype * )buf32;
  window_datatype * buf32d_ptr = (window_datatype * )buf32d;
  window_init(window_buf32_buf32d, 1, buf32, LOCK_4_2_0_0, buf32d, LOCK_4_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_2_bounds = sync_buffer[1];

  while (proc_4_2_bounds)
  {

    // Kernel call : i96:mm_kernel1
    window_acquire(window_buf30_buf30d,LOCK_4_3_2_4096,LOCK_4_3_3_4096,buf30_ptr,buf30d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf31_buf31d,LOCK_3_2_2_4096,LOCK_3_2_3_4096,buf31_ptr,buf31d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf29_buf29d,LOCK_4_1_6_4096,LOCK_4_1_7_4096,buf29_ptr,buf29d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf32_buf32d,LOCK_4_2_0_0,LOCK_4_2_1_0,buf32_ptr,buf32d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf30_buf30d),get_input_window_float(window_buf31_buf31d),get_input_window_float(window_buf29_buf29d),get_output_window_float(window_buf32_buf32d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf30_buf30d,LOCK_4_3_2_4096,LOCK_4_3_3_4096,buf30_ptr,buf30d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf31_buf31d,LOCK_3_2_2_4096,LOCK_3_2_3_4096,buf31_ptr,buf31d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf29_buf29d,LOCK_4_1_6_4096,LOCK_4_1_7_4096,buf29_ptr,buf29d_ptr,0,index, REL_WRITE);
    window_release(window_buf32_buf32d,LOCK_4_2_0_0,LOCK_4_2_1_0,buf32_ptr,buf32d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_2_bounds > 0)
      --proc_4_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}