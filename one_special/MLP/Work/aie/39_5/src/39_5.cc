// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_5/src/39_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_6_0_0 32
#define LOCK_39_6_1_0 33
#define LOCK_39_5_2_4096 18
#define LOCK_39_5_3_4096 19
#define LOCK_39_5_0_0 16
#define LOCK_39_5_1_0 17
#define LOCK_39_5_4_0 20
#define LOCK_39_5_5_0 21

// Declare shared memory buffers
v4float buf698[256];
v4float buf698d[256];
v4float buf699[256];
v4float buf699d[256];
v4float buf700[256];
v4float buf700d[256];
v4float buf701[256];
v4float buf701d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf699_buf699d[1];
  window_datatype * buf699_ptr = (window_datatype * )buf699;
  window_datatype * buf699d_ptr = (window_datatype * )buf699d;
  window_init(window_buf699_buf699d, 1, buf699, LOCK_39_6_0_0, buf699d, LOCK_39_6_1_0, 256, 256);
  window_internal window_buf700_buf700d[1];
  window_datatype * buf700_ptr = (window_datatype * )buf700;
  window_datatype * buf700d_ptr = (window_datatype * )buf700d;
  window_init(window_buf700_buf700d, 1, buf700, LOCK_39_5_2_4096, buf700d, LOCK_39_5_3_4096, 256, 256);
  window_internal window_buf698_buf698d[1];
  window_datatype * buf698_ptr = (window_datatype * )buf698;
  window_datatype * buf698d_ptr = (window_datatype * )buf698d;
  window_init(window_buf698_buf698d, 1, buf698, LOCK_39_5_0_0, buf698d, LOCK_39_5_1_0, 256, 256);
  window_internal window_buf701_buf701d[1];
  window_datatype * buf701_ptr = (window_datatype * )buf701;
  window_datatype * buf701d_ptr = (window_datatype * )buf701d;
  window_init(window_buf701_buf701d, 1, buf701, LOCK_39_5_4_0, buf701d, LOCK_39_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_5_bounds = sync_buffer[1];

  while (proc_39_5_bounds)
  {

    // Kernel call : i431:mm_kernel1
    window_acquire(window_buf699_buf699d,LOCK_39_6_0_0,LOCK_39_6_1_0,buf699_ptr,buf699d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf700_buf700d,LOCK_39_5_2_4096,LOCK_39_5_3_4096,buf700_ptr,buf700d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf698_buf698d,LOCK_39_5_0_0,LOCK_39_5_1_0,buf698_ptr,buf698d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf701_buf701d,LOCK_39_5_4_0,LOCK_39_5_5_0,buf701_ptr,buf701d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf699_buf699d),get_input_window_float(window_buf700_buf700d),get_input_window_float(window_buf698_buf698d),get_output_window_float(window_buf701_buf701d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf699_buf699d,LOCK_39_6_0_0,LOCK_39_6_1_0,buf699_ptr,buf699d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf700_buf700d,LOCK_39_5_2_4096,LOCK_39_5_3_4096,buf700_ptr,buf700d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf698_buf698d,LOCK_39_5_0_0,LOCK_39_5_1_0,buf698_ptr,buf698d_ptr,0,index, REL_WRITE);
    window_release(window_buf701_buf701d,LOCK_39_5_4_0,LOCK_39_5_5_0,buf701_ptr,buf701d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_5_bounds > 0)
      --proc_39_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}