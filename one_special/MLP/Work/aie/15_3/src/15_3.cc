// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_3/src/15_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_16_3_0_0 48
#define LOCK_16_3_1_4096 49
#define LOCK_15_3_2_4096 18
#define LOCK_15_3_3_4096 19
#define LOCK_15_3_0_0 16
#define LOCK_15_3_1_0 17
#define LOCK_15_3_4_0 20
#define LOCK_15_3_5_0 21

// Declare shared memory buffers
v4float buf164[256];
v4float buf164d[256];
v4float buf165[256];
v4float buf165d[256];
v4float buf166[256];
v4float buf166d[256];
v4float buf167[256];
v4float buf167d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf165_buf165d[1];
  window_datatype * buf165_ptr = (window_datatype * )buf165;
  window_datatype * buf165d_ptr = (window_datatype * )buf165d;
  window_init(window_buf165_buf165d, 1, buf165, LOCK_16_3_0_0, buf165d, LOCK_16_3_1_4096, 256, 256);
  window_internal window_buf166_buf166d[1];
  window_datatype * buf166_ptr = (window_datatype * )buf166;
  window_datatype * buf166d_ptr = (window_datatype * )buf166d;
  window_init(window_buf166_buf166d, 1, buf166, LOCK_15_3_2_4096, buf166d, LOCK_15_3_3_4096, 256, 256);
  window_internal window_buf164_buf164d[1];
  window_datatype * buf164_ptr = (window_datatype * )buf164;
  window_datatype * buf164d_ptr = (window_datatype * )buf164d;
  window_init(window_buf164_buf164d, 1, buf164, LOCK_15_3_0_0, buf164d, LOCK_15_3_1_0, 256, 256);
  window_internal window_buf167_buf167d[1];
  window_datatype * buf167_ptr = (window_datatype * )buf167;
  window_datatype * buf167d_ptr = (window_datatype * )buf167d;
  window_init(window_buf167_buf167d, 1, buf167, LOCK_15_3_4_0, buf167d, LOCK_15_3_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_3_bounds = sync_buffer[1];

  while (proc_15_3_bounds)
  {

    // Kernel call : i163:mm_kernel1
    window_acquire(window_buf165_buf165d,LOCK_16_3_0_0,LOCK_16_3_1_4096,buf165_ptr,buf165d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf166_buf166d,LOCK_15_3_2_4096,LOCK_15_3_3_4096,buf166_ptr,buf166d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf164_buf164d,LOCK_15_3_0_0,LOCK_15_3_1_0,buf164_ptr,buf164d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf167_buf167d,LOCK_15_3_4_0,LOCK_15_3_5_0,buf167_ptr,buf167d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf165_buf165d),get_input_window_float(window_buf166_buf166d),get_input_window_float(window_buf164_buf164d),get_output_window_float(window_buf167_buf167d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf165_buf165d,LOCK_16_3_0_0,LOCK_16_3_1_4096,buf165_ptr,buf165d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf166_buf166d,LOCK_15_3_2_4096,LOCK_15_3_3_4096,buf166_ptr,buf166d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf164_buf164d,LOCK_15_3_0_0,LOCK_15_3_1_0,buf164_ptr,buf164d_ptr,0,index, REL_WRITE);
    window_release(window_buf167_buf167d,LOCK_15_3_4_0,LOCK_15_3_5_0,buf167_ptr,buf167d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_3_bounds > 0)
      --proc_15_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}