// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_0/src/30_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_0_2_4096 18
#define LOCK_29_0_3_4096 19
#define LOCK_30_0_0_0 48
#define LOCK_30_0_1_0 49
#define LOCK_30_1_2_4096 34
#define LOCK_30_1_3_4096 35

// Declare shared memory buffers
v4float buf336[256];
v4float buf336d[256];
v4float buf337[256];
v4float buf337d[256];
v4float buf338[256];
v4float buf338d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf336_buf336d[1];
  window_datatype * buf336_ptr = (window_datatype * )buf336;
  window_datatype * buf336d_ptr = (window_datatype * )buf336d;
  window_init(window_buf336_buf336d, 1, buf336, LOCK_29_0_2_4096, buf336d, LOCK_29_0_3_4096, 256, 256);
  window_internal window_buf337_buf337d[1];
  window_datatype * buf337_ptr = (window_datatype * )buf337;
  window_datatype * buf337d_ptr = (window_datatype * )buf337d;
  window_init(window_buf337_buf337d, 1, buf337, LOCK_30_0_0_0, buf337d, LOCK_30_0_1_0, 256, 256);
  window_internal window_buf338_buf338d[1];
  window_datatype * buf338_ptr = (window_datatype * )buf338;
  window_datatype * buf338d_ptr = (window_datatype * )buf338d;
  window_init(window_buf338_buf338d, 1, buf338, LOCK_30_1_2_4096, buf338d, LOCK_30_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_0_bounds = sync_buffer[1];

  while (proc_30_0_bounds)
  {

    // Kernel call : i250:mm_kernel0
    window_acquire(window_buf336_buf336d,LOCK_29_0_2_4096,LOCK_29_0_3_4096,buf336_ptr,buf336d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf337_buf337d,LOCK_30_0_0_0,LOCK_30_0_1_0,buf337_ptr,buf337d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf338_buf338d,LOCK_30_1_2_4096,LOCK_30_1_3_4096,buf338_ptr,buf338d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf336_buf336d),get_input_window_float(window_buf337_buf337d),get_output_window_float(window_buf338_buf338d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf336_buf336d,LOCK_29_0_2_4096,LOCK_29_0_3_4096,buf336_ptr,buf336d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf337_buf337d,LOCK_30_0_0_0,LOCK_30_0_1_0,buf337_ptr,buf337d_ptr,0,index, REL_WRITE);
    window_release(window_buf338_buf338d,LOCK_30_1_2_4096,LOCK_30_1_3_4096,buf338_ptr,buf338d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_0_bounds > 0)
      --proc_30_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}