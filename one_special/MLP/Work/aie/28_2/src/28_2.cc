// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_2/src/28_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_2_0_0 48
#define LOCK_28_2_1_0 49
#define LOCK_28_3_0_4096 32
#define LOCK_28_3_1_0 33
#define LOCK_28_1_6_0 6
#define LOCK_28_1_7_0 7
#define LOCK_28_3_2_0 34
#define LOCK_28_3_3_4096 35

// Declare shared memory buffers
v4float buf317[256];
v4float buf317d[256];
v4float buf318[256];
v4float buf318d[256];
v4float buf319[256];
v4float buf319d[256];
v4float buf320[256];
v4float buf320d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf318_buf318d[1];
  window_datatype * buf318_ptr = (window_datatype * )buf318;
  window_datatype * buf318d_ptr = (window_datatype * )buf318d;
  window_init(window_buf318_buf318d, 1, buf318, LOCK_28_2_0_0, buf318d, LOCK_28_2_1_0, 256, 256);
  window_internal window_buf319_buf319d[1];
  window_datatype * buf319_ptr = (window_datatype * )buf319;
  window_datatype * buf319d_ptr = (window_datatype * )buf319d;
  window_init(window_buf319_buf319d, 1, buf319, LOCK_28_3_0_4096, buf319d, LOCK_28_3_1_0, 256, 256);
  window_internal window_buf317_buf317d[1];
  window_datatype * buf317_ptr = (window_datatype * )buf317;
  window_datatype * buf317d_ptr = (window_datatype * )buf317d;
  window_init(window_buf317_buf317d, 1, buf317, LOCK_28_1_6_0, buf317d, LOCK_28_1_7_0, 256, 256);
  window_internal window_buf320_buf320d[1];
  window_datatype * buf320_ptr = (window_datatype * )buf320;
  window_datatype * buf320d_ptr = (window_datatype * )buf320d;
  window_init(window_buf320_buf320d, 1, buf320, LOCK_28_3_2_0, buf320d, LOCK_28_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_2_bounds = sync_buffer[1];

  while (proc_28_2_bounds)
  {

    // Kernel call : i240:mm_kernel1
    window_acquire(window_buf318_buf318d,LOCK_28_2_0_0,LOCK_28_2_1_0,buf318_ptr,buf318d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf319_buf319d,LOCK_28_3_0_4096,LOCK_28_3_1_0,buf319_ptr,buf319d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf317_buf317d,LOCK_28_1_6_0,LOCK_28_1_7_0,buf317_ptr,buf317d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf320_buf320d,LOCK_28_3_2_0,LOCK_28_3_3_4096,buf320_ptr,buf320d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf318_buf318d),get_input_window_float(window_buf319_buf319d),get_input_window_float(window_buf317_buf317d),get_output_window_float(window_buf320_buf320d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf318_buf318d,LOCK_28_2_0_0,LOCK_28_2_1_0,buf318_ptr,buf318d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf319_buf319d,LOCK_28_3_0_4096,LOCK_28_3_1_0,buf319_ptr,buf319d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf317_buf317d,LOCK_28_1_6_0,LOCK_28_1_7_0,buf317_ptr,buf317d_ptr,0,index, REL_WRITE);
    window_release(window_buf320_buf320d,LOCK_28_3_2_0,LOCK_28_3_3_4096,buf320_ptr,buf320d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_2_bounds > 0)
      --proc_28_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}