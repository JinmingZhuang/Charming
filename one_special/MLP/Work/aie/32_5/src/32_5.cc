// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_5/src/32_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_32_4_2_4096 2
#define LOCK_32_4_3_4096 3
#define LOCK_32_6_2_4096 34
#define LOCK_32_6_3_4096 35
#define LOCK_32_5_2_0 18
#define LOCK_32_5_3_4096 19
#define LOCK_32_5_4_0 20
#define LOCK_32_5_5_4096 21

// Declare shared memory buffers
v4float buf782[256];
v4float buf782d[256];
v4float buf783[256];
v4float buf783d[256];
v4float buf784[256];
v4float buf784d[256];
v4float buf785[256];
v4float buf785d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf783_buf783d[1];
  window_datatype * buf783_ptr = (window_datatype * )buf783;
  window_datatype * buf783d_ptr = (window_datatype * )buf783d;
  window_init(window_buf783_buf783d, 1, buf783, LOCK_32_4_2_4096, buf783d, LOCK_32_4_3_4096, 256, 256);
  window_internal window_buf784_buf784d[1];
  window_datatype * buf784_ptr = (window_datatype * )buf784;
  window_datatype * buf784d_ptr = (window_datatype * )buf784d;
  window_init(window_buf784_buf784d, 1, buf784, LOCK_32_6_2_4096, buf784d, LOCK_32_6_3_4096, 256, 256);
  window_internal window_buf782_buf782d[1];
  window_datatype * buf782_ptr = (window_datatype * )buf782;
  window_datatype * buf782d_ptr = (window_datatype * )buf782d;
  window_init(window_buf782_buf782d, 1, buf782, LOCK_32_5_2_0, buf782d, LOCK_32_5_3_4096, 256, 256);
  window_internal window_buf785_buf785d[1];
  window_datatype * buf785_ptr = (window_datatype * )buf785;
  window_datatype * buf785d_ptr = (window_datatype * )buf785d;
  window_init(window_buf785_buf785d, 1, buf785, LOCK_32_5_4_0, buf785d, LOCK_32_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_5_bounds = sync_buffer[1];

  while (proc_32_5_bounds)
  {

    // Kernel call : i473:mm_kernel1
    window_acquire(window_buf783_buf783d,LOCK_32_4_2_4096,LOCK_32_4_3_4096,buf783_ptr,buf783d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf784_buf784d,LOCK_32_6_2_4096,LOCK_32_6_3_4096,buf784_ptr,buf784d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf782_buf782d,LOCK_32_5_2_0,LOCK_32_5_3_4096,buf782_ptr,buf782d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf785_buf785d,LOCK_32_5_4_0,LOCK_32_5_5_4096,buf785_ptr,buf785d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf783_buf783d),get_input_window_float(window_buf784_buf784d),get_input_window_float(window_buf782_buf782d),get_output_window_float(window_buf785_buf785d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf783_buf783d,LOCK_32_4_2_4096,LOCK_32_4_3_4096,buf783_ptr,buf783d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf784_buf784d,LOCK_32_6_2_4096,LOCK_32_6_3_4096,buf784_ptr,buf784d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf782_buf782d,LOCK_32_5_2_0,LOCK_32_5_3_4096,buf782_ptr,buf782d_ptr,0,index, REL_WRITE);
    window_release(window_buf785_buf785d,LOCK_32_5_4_0,LOCK_32_5_5_4096,buf785_ptr,buf785d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_5_bounds > 0)
      --proc_32_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}