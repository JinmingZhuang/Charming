// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_1/src/15_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_1_2_4096 18
#define LOCK_15_1_3_4096 19
#define LOCK_15_1_4_0 20
#define LOCK_15_1_5_0 21
#define LOCK_15_1_0_0 16
#define LOCK_15_1_1_0 17
#define LOCK_15_1_6_4096 22
#define LOCK_15_1_7_4096 23

// Declare shared memory buffers
v4float buf158[256];
v4float buf158d[256];
v4float buf159[256];
v4float buf159d[256];
v4float buf160[256];
v4float buf160d[256];
v4float buf161[256];
v4float buf161d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf159_buf159d[1];
  window_datatype * buf159_ptr = (window_datatype * )buf159;
  window_datatype * buf159d_ptr = (window_datatype * )buf159d;
  window_init(window_buf159_buf159d, 1, buf159, LOCK_15_1_2_4096, buf159d, LOCK_15_1_3_4096, 256, 256);
  window_internal window_buf160_buf160d[1];
  window_datatype * buf160_ptr = (window_datatype * )buf160;
  window_datatype * buf160d_ptr = (window_datatype * )buf160d;
  window_init(window_buf160_buf160d, 1, buf160, LOCK_15_1_4_0, buf160d, LOCK_15_1_5_0, 256, 256);
  window_internal window_buf158_buf158d[1];
  window_datatype * buf158_ptr = (window_datatype * )buf158;
  window_datatype * buf158d_ptr = (window_datatype * )buf158d;
  window_init(window_buf158_buf158d, 1, buf158, LOCK_15_1_0_0, buf158d, LOCK_15_1_1_0, 256, 256);
  window_internal window_buf161_buf161d[1];
  window_datatype * buf161_ptr = (window_datatype * )buf161;
  window_datatype * buf161d_ptr = (window_datatype * )buf161d;
  window_init(window_buf161_buf161d, 1, buf161, LOCK_15_1_6_4096, buf161d, LOCK_15_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_1_bounds = sync_buffer[1];

  while (proc_15_1_bounds)
  {

    // Kernel call : i161:mm_kernel1
    window_acquire(window_buf159_buf159d,LOCK_15_1_2_4096,LOCK_15_1_3_4096,buf159_ptr,buf159d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf160_buf160d,LOCK_15_1_4_0,LOCK_15_1_5_0,buf160_ptr,buf160d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf158_buf158d,LOCK_15_1_0_0,LOCK_15_1_1_0,buf158_ptr,buf158d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf161_buf161d,LOCK_15_1_6_4096,LOCK_15_1_7_4096,buf161_ptr,buf161d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf159_buf159d),get_input_window_float(window_buf160_buf160d),get_input_window_float(window_buf158_buf158d),get_output_window_float(window_buf161_buf161d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf159_buf159d,LOCK_15_1_2_4096,LOCK_15_1_3_4096,buf159_ptr,buf159d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf160_buf160d,LOCK_15_1_4_0,LOCK_15_1_5_0,buf160_ptr,buf160d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf158_buf158d,LOCK_15_1_0_0,LOCK_15_1_1_0,buf158_ptr,buf158d_ptr,0,index, REL_WRITE);
    window_release(window_buf161_buf161d,LOCK_15_1_6_4096,LOCK_15_1_7_4096,buf161_ptr,buf161d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_1_bounds > 0)
      --proc_15_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}