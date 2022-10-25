// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_3/src/30_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_30_2_2_4096 2
#define LOCK_30_2_3_4096 3
#define LOCK_30_2_4_0 4
#define LOCK_30_2_5_0 5
#define LOCK_30_2_0_0 0
#define LOCK_30_2_1_0 1
#define LOCK_30_2_6_4096 6
#define LOCK_30_2_7_4096 7

// Declare shared memory buffers
v4float buf344[256];
v4float buf344d[256];
v4float buf345[256];
v4float buf345d[256];
v4float buf346[256];
v4float buf346d[256];
v4float buf347[256];
v4float buf347d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf345_buf345d[1];
  window_datatype * buf345_ptr = (window_datatype * )buf345;
  window_datatype * buf345d_ptr = (window_datatype * )buf345d;
  window_init(window_buf345_buf345d, 1, buf345, LOCK_30_2_2_4096, buf345d, LOCK_30_2_3_4096, 256, 256);
  window_internal window_buf346_buf346d[1];
  window_datatype * buf346_ptr = (window_datatype * )buf346;
  window_datatype * buf346d_ptr = (window_datatype * )buf346d;
  window_init(window_buf346_buf346d, 1, buf346, LOCK_30_2_4_0, buf346d, LOCK_30_2_5_0, 256, 256);
  window_internal window_buf344_buf344d[1];
  window_datatype * buf344_ptr = (window_datatype * )buf344;
  window_datatype * buf344d_ptr = (window_datatype * )buf344d;
  window_init(window_buf344_buf344d, 1, buf344, LOCK_30_2_0_0, buf344d, LOCK_30_2_1_0, 256, 256);
  window_internal window_buf347_buf347d[1];
  window_datatype * buf347_ptr = (window_datatype * )buf347;
  window_datatype * buf347d_ptr = (window_datatype * )buf347d;
  window_init(window_buf347_buf347d, 1, buf347, LOCK_30_2_6_4096, buf347d, LOCK_30_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_3_bounds = sync_buffer[1];

  while (proc_30_3_bounds)
  {

    // Kernel call : i253:mm_kernel1
    window_acquire(window_buf345_buf345d,LOCK_30_2_2_4096,LOCK_30_2_3_4096,buf345_ptr,buf345d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf346_buf346d,LOCK_30_2_4_0,LOCK_30_2_5_0,buf346_ptr,buf346d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf344_buf344d,LOCK_30_2_0_0,LOCK_30_2_1_0,buf344_ptr,buf344d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf347_buf347d,LOCK_30_2_6_4096,LOCK_30_2_7_4096,buf347_ptr,buf347d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf345_buf345d),get_input_window_float(window_buf346_buf346d),get_input_window_float(window_buf344_buf344d),get_output_window_float(window_buf347_buf347d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf345_buf345d,LOCK_30_2_2_4096,LOCK_30_2_3_4096,buf345_ptr,buf345d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf346_buf346d,LOCK_30_2_4_0,LOCK_30_2_5_0,buf346_ptr,buf346d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf344_buf344d,LOCK_30_2_0_0,LOCK_30_2_1_0,buf344_ptr,buf344d_ptr,0,index, REL_WRITE);
    window_release(window_buf347_buf347d,LOCK_30_2_6_4096,LOCK_30_2_7_4096,buf347_ptr,buf347d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_3_bounds > 0)
      --proc_30_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}