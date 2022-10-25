// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_1/src/23_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_2_0_0 32
#define LOCK_23_2_1_4096 33
#define LOCK_23_0_2_4096 2
#define LOCK_23_0_3_4096 3
#define LOCK_23_1_2_4096 18
#define LOCK_23_1_3_0 19
#define LOCK_23_1_4_4096 20
#define LOCK_23_1_5_4096 21

// Declare shared memory buffers
v4float buf254[256];
v4float buf254d[256];
v4float buf255[256];
v4float buf255d[256];
v4float buf256[256];
v4float buf256d[256];
v4float buf257[256];
v4float buf257d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf255_buf255d[1];
  window_datatype * buf255_ptr = (window_datatype * )buf255;
  window_datatype * buf255d_ptr = (window_datatype * )buf255d;
  window_init(window_buf255_buf255d, 1, buf255, LOCK_23_2_0_0, buf255d, LOCK_23_2_1_4096, 256, 256);
  window_internal window_buf256_buf256d[1];
  window_datatype * buf256_ptr = (window_datatype * )buf256;
  window_datatype * buf256d_ptr = (window_datatype * )buf256d;
  window_init(window_buf256_buf256d, 1, buf256, LOCK_23_0_2_4096, buf256d, LOCK_23_0_3_4096, 256, 256);
  window_internal window_buf254_buf254d[1];
  window_datatype * buf254_ptr = (window_datatype * )buf254;
  window_datatype * buf254d_ptr = (window_datatype * )buf254d;
  window_init(window_buf254_buf254d, 1, buf254, LOCK_23_1_2_4096, buf254d, LOCK_23_1_3_0, 256, 256);
  window_internal window_buf257_buf257d[1];
  window_datatype * buf257_ptr = (window_datatype * )buf257;
  window_datatype * buf257d_ptr = (window_datatype * )buf257d;
  window_init(window_buf257_buf257d, 1, buf257, LOCK_23_1_4_4096, buf257d, LOCK_23_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_1_bounds = sync_buffer[1];

  while (proc_23_1_bounds)
  {

    // Kernel call : i209:mm_kernel1
    window_acquire(window_buf255_buf255d,LOCK_23_2_0_0,LOCK_23_2_1_4096,buf255_ptr,buf255d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf256_buf256d,LOCK_23_0_2_4096,LOCK_23_0_3_4096,buf256_ptr,buf256d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf254_buf254d,LOCK_23_1_2_4096,LOCK_23_1_3_0,buf254_ptr,buf254d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf257_buf257d,LOCK_23_1_4_4096,LOCK_23_1_5_4096,buf257_ptr,buf257d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf255_buf255d),get_input_window_float(window_buf256_buf256d),get_input_window_float(window_buf254_buf254d),get_output_window_float(window_buf257_buf257d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf255_buf255d,LOCK_23_2_0_0,LOCK_23_2_1_4096,buf255_ptr,buf255d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf256_buf256d,LOCK_23_0_2_4096,LOCK_23_0_3_4096,buf256_ptr,buf256d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf254_buf254d,LOCK_23_1_2_4096,LOCK_23_1_3_0,buf254_ptr,buf254d_ptr,0,index, REL_WRITE);
    window_release(window_buf257_buf257d,LOCK_23_1_4_4096,LOCK_23_1_5_4096,buf257_ptr,buf257d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_1_bounds > 0)
      --proc_23_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}