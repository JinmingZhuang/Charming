// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_3/src/29_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_4_0_0 32
#define LOCK_29_4_1_0 33
#define LOCK_30_3_0_0 48
#define LOCK_30_3_1_0 49
#define LOCK_29_2_2_4096 2
#define LOCK_29_2_3_4096 3
#define LOCK_29_2_4_0 4
#define LOCK_29_2_5_0 5

// Declare shared memory buffers
v4float buf332[256];
v4float buf332d[256];
v4float buf333[256];
v4float buf333d[256];
v4float buf334[256];
v4float buf334d[256];
v4float buf335[256];
v4float buf335d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf333_buf333d[1];
  window_datatype * buf333_ptr = (window_datatype * )buf333;
  window_datatype * buf333d_ptr = (window_datatype * )buf333d;
  window_init(window_buf333_buf333d, 1, buf333, LOCK_29_4_0_0, buf333d, LOCK_29_4_1_0, 256, 256);
  window_internal window_buf334_buf334d[1];
  window_datatype * buf334_ptr = (window_datatype * )buf334;
  window_datatype * buf334d_ptr = (window_datatype * )buf334d;
  window_init(window_buf334_buf334d, 1, buf334, LOCK_30_3_0_0, buf334d, LOCK_30_3_1_0, 256, 256);
  window_internal window_buf332_buf332d[1];
  window_datatype * buf332_ptr = (window_datatype * )buf332;
  window_datatype * buf332d_ptr = (window_datatype * )buf332d;
  window_init(window_buf332_buf332d, 1, buf332, LOCK_29_2_2_4096, buf332d, LOCK_29_2_3_4096, 256, 256);
  window_internal window_buf335_buf335d[1];
  window_datatype * buf335_ptr = (window_datatype * )buf335;
  window_datatype * buf335d_ptr = (window_datatype * )buf335d;
  window_init(window_buf335_buf335d, 1, buf335, LOCK_29_2_4_0, buf335d, LOCK_29_2_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_3_bounds = sync_buffer[1];

  while (proc_29_3_bounds)
  {

    // Kernel call : i247:mm_kernel1
    window_acquire(window_buf333_buf333d,LOCK_29_4_0_0,LOCK_29_4_1_0,buf333_ptr,buf333d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf334_buf334d,LOCK_30_3_0_0,LOCK_30_3_1_0,buf334_ptr,buf334d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf332_buf332d,LOCK_29_2_2_4096,LOCK_29_2_3_4096,buf332_ptr,buf332d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf335_buf335d,LOCK_29_2_4_0,LOCK_29_2_5_0,buf335_ptr,buf335d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf333_buf333d),get_input_window_float(window_buf334_buf334d),get_input_window_float(window_buf332_buf332d),get_output_window_float(window_buf335_buf335d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf333_buf333d,LOCK_29_4_0_0,LOCK_29_4_1_0,buf333_ptr,buf333d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf334_buf334d,LOCK_30_3_0_0,LOCK_30_3_1_0,buf334_ptr,buf334d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf332_buf332d,LOCK_29_2_2_4096,LOCK_29_2_3_4096,buf332_ptr,buf332d_ptr,0,index, REL_WRITE);
    window_release(window_buf335_buf335d,LOCK_29_2_4_0,LOCK_29_2_5_0,buf335_ptr,buf335d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_3_bounds > 0)
      --proc_29_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}