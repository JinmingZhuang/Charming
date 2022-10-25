// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_3/src/34_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_2_2_4096 2
#define LOCK_34_2_3_4096 3
#define LOCK_34_4_0_0 32
#define LOCK_34_4_1_0 33
#define LOCK_34_3_2_0 18
#define LOCK_34_3_3_4096 19
#define LOCK_34_3_4_0 20
#define LOCK_34_3_5_0 21

// Declare shared memory buffers
v4float buf392[256];
v4float buf392d[256];
v4float buf393[256];
v4float buf393d[256];
v4float buf394[256];
v4float buf394d[256];
v4float buf395[256];
v4float buf395d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf393_buf393d[1];
  window_datatype * buf393_ptr = (window_datatype * )buf393;
  window_datatype * buf393d_ptr = (window_datatype * )buf393d;
  window_init(window_buf393_buf393d, 1, buf393, LOCK_34_2_2_4096, buf393d, LOCK_34_2_3_4096, 256, 256);
  window_internal window_buf394_buf394d[1];
  window_datatype * buf394_ptr = (window_datatype * )buf394;
  window_datatype * buf394d_ptr = (window_datatype * )buf394d;
  window_init(window_buf394_buf394d, 1, buf394, LOCK_34_4_0_0, buf394d, LOCK_34_4_1_0, 256, 256);
  window_internal window_buf392_buf392d[1];
  window_datatype * buf392_ptr = (window_datatype * )buf392;
  window_datatype * buf392d_ptr = (window_datatype * )buf392d;
  window_init(window_buf392_buf392d, 1, buf392, LOCK_34_3_2_0, buf392d, LOCK_34_3_3_4096, 256, 256);
  window_internal window_buf395_buf395d[1];
  window_datatype * buf395_ptr = (window_datatype * )buf395;
  window_datatype * buf395d_ptr = (window_datatype * )buf395d;
  window_init(window_buf395_buf395d, 1, buf395, LOCK_34_3_4_0, buf395d, LOCK_34_3_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_3_bounds = sync_buffer[1];

  while (proc_34_3_bounds)
  {

    // Kernel call : i277:mm_kernel1
    window_acquire(window_buf393_buf393d,LOCK_34_2_2_4096,LOCK_34_2_3_4096,buf393_ptr,buf393d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf394_buf394d,LOCK_34_4_0_0,LOCK_34_4_1_0,buf394_ptr,buf394d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf392_buf392d,LOCK_34_3_2_0,LOCK_34_3_3_4096,buf392_ptr,buf392d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf395_buf395d,LOCK_34_3_4_0,LOCK_34_3_5_0,buf395_ptr,buf395d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf393_buf393d),get_input_window_float(window_buf394_buf394d),get_input_window_float(window_buf392_buf392d),get_output_window_float(window_buf395_buf395d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf393_buf393d,LOCK_34_2_2_4096,LOCK_34_2_3_4096,buf393_ptr,buf393d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf394_buf394d,LOCK_34_4_0_0,LOCK_34_4_1_0,buf394_ptr,buf394d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf392_buf392d,LOCK_34_3_2_0,LOCK_34_3_3_4096,buf392_ptr,buf392d_ptr,0,index, REL_WRITE);
    window_release(window_buf395_buf395d,LOCK_34_3_4_0,LOCK_34_3_5_0,buf395_ptr,buf395d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_3_bounds > 0)
      --proc_34_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}