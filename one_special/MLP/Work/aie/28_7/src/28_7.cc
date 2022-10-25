// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_7/src/28_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_7_4_0 20
#define LOCK_28_7_5_0 21
#define LOCK_28_6_2_4096 2
#define LOCK_28_6_3_4096 3
#define LOCK_28_7_2_0 18
#define LOCK_28_7_3_4096 19
#define LOCK_28_7_6_4096 22
#define LOCK_28_7_7_4096 23

// Declare shared memory buffers
v4float buf836[256];
v4float buf836d[256];
v4float buf837[256];
v4float buf837d[256];
v4float buf838[256];
v4float buf838d[256];
v4float buf839[256];
v4float buf839d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf837_buf837d[1];
  window_datatype * buf837_ptr = (window_datatype * )buf837;
  window_datatype * buf837d_ptr = (window_datatype * )buf837d;
  window_init(window_buf837_buf837d, 1, buf837, LOCK_28_7_4_0, buf837d, LOCK_28_7_5_0, 256, 256);
  window_internal window_buf838_buf838d[1];
  window_datatype * buf838_ptr = (window_datatype * )buf838;
  window_datatype * buf838d_ptr = (window_datatype * )buf838d;
  window_init(window_buf838_buf838d, 1, buf838, LOCK_28_6_2_4096, buf838d, LOCK_28_6_3_4096, 256, 256);
  window_internal window_buf836_buf836d[1];
  window_datatype * buf836_ptr = (window_datatype * )buf836;
  window_datatype * buf836d_ptr = (window_datatype * )buf836d;
  window_init(window_buf836_buf836d, 1, buf836, LOCK_28_7_2_0, buf836d, LOCK_28_7_3_4096, 256, 256);
  window_internal window_buf839_buf839d[1];
  window_datatype * buf839_ptr = (window_datatype * )buf839;
  window_datatype * buf839d_ptr = (window_datatype * )buf839d;
  window_init(window_buf839_buf839d, 1, buf839, LOCK_28_7_6_4096, buf839d, LOCK_28_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_7_bounds = sync_buffer[1];

  while (proc_28_7_bounds)
  {

    // Kernel call : i499:mm_kernel1
    window_acquire(window_buf837_buf837d,LOCK_28_7_4_0,LOCK_28_7_5_0,buf837_ptr,buf837d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf838_buf838d,LOCK_28_6_2_4096,LOCK_28_6_3_4096,buf838_ptr,buf838d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf836_buf836d,LOCK_28_7_2_0,LOCK_28_7_3_4096,buf836_ptr,buf836d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf839_buf839d,LOCK_28_7_6_4096,LOCK_28_7_7_4096,buf839_ptr,buf839d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf837_buf837d),get_input_window_float(window_buf838_buf838d),get_input_window_float(window_buf836_buf836d),get_output_window_float(window_buf839_buf839d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf837_buf837d,LOCK_28_7_4_0,LOCK_28_7_5_0,buf837_ptr,buf837d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf838_buf838d,LOCK_28_6_2_4096,LOCK_28_6_3_4096,buf838_ptr,buf838d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf836_buf836d,LOCK_28_7_2_0,LOCK_28_7_3_4096,buf836_ptr,buf836d_ptr,0,index, REL_WRITE);
    window_release(window_buf839_buf839d,LOCK_28_7_6_4096,LOCK_28_7_7_4096,buf839_ptr,buf839d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_7_bounds > 0)
      --proc_28_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}