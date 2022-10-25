// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_1/src/17_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_1_2_4096 18
#define LOCK_17_1_3_4096 19
#define LOCK_17_1_4_0 20
#define LOCK_17_1_5_0 21
#define LOCK_17_1_0_0 16
#define LOCK_17_1_1_0 17
#define LOCK_17_1_6_4096 22
#define LOCK_17_1_7_4096 23

// Declare shared memory buffers
v4float buf182[256];
v4float buf182d[256];
v4float buf183[256];
v4float buf183d[256];
v4float buf184[256];
v4float buf184d[256];
v4float buf185[256];
v4float buf185d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf183_buf183d[1];
  window_datatype * buf183_ptr = (window_datatype * )buf183;
  window_datatype * buf183d_ptr = (window_datatype * )buf183d;
  window_init(window_buf183_buf183d, 1, buf183, LOCK_17_1_2_4096, buf183d, LOCK_17_1_3_4096, 256, 256);
  window_internal window_buf184_buf184d[1];
  window_datatype * buf184_ptr = (window_datatype * )buf184;
  window_datatype * buf184d_ptr = (window_datatype * )buf184d;
  window_init(window_buf184_buf184d, 1, buf184, LOCK_17_1_4_0, buf184d, LOCK_17_1_5_0, 256, 256);
  window_internal window_buf182_buf182d[1];
  window_datatype * buf182_ptr = (window_datatype * )buf182;
  window_datatype * buf182d_ptr = (window_datatype * )buf182d;
  window_init(window_buf182_buf182d, 1, buf182, LOCK_17_1_0_0, buf182d, LOCK_17_1_1_0, 256, 256);
  window_internal window_buf185_buf185d[1];
  window_datatype * buf185_ptr = (window_datatype * )buf185;
  window_datatype * buf185d_ptr = (window_datatype * )buf185d;
  window_init(window_buf185_buf185d, 1, buf185, LOCK_17_1_6_4096, buf185d, LOCK_17_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_1_bounds = sync_buffer[1];

  while (proc_17_1_bounds)
  {

    // Kernel call : i173:mm_kernel1
    window_acquire(window_buf183_buf183d,LOCK_17_1_2_4096,LOCK_17_1_3_4096,buf183_ptr,buf183d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf184_buf184d,LOCK_17_1_4_0,LOCK_17_1_5_0,buf184_ptr,buf184d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf182_buf182d,LOCK_17_1_0_0,LOCK_17_1_1_0,buf182_ptr,buf182d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf185_buf185d,LOCK_17_1_6_4096,LOCK_17_1_7_4096,buf185_ptr,buf185d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf183_buf183d),get_input_window_float(window_buf184_buf184d),get_input_window_float(window_buf182_buf182d),get_output_window_float(window_buf185_buf185d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf183_buf183d,LOCK_17_1_2_4096,LOCK_17_1_3_4096,buf183_ptr,buf183d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf184_buf184d,LOCK_17_1_4_0,LOCK_17_1_5_0,buf184_ptr,buf184d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf182_buf182d,LOCK_17_1_0_0,LOCK_17_1_1_0,buf182_ptr,buf182d_ptr,0,index, REL_WRITE);
    window_release(window_buf185_buf185d,LOCK_17_1_6_4096,LOCK_17_1_7_4096,buf185_ptr,buf185d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_1_bounds > 0)
      --proc_17_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}