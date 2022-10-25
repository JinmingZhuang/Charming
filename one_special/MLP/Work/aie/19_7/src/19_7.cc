// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_7/src/19_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_19_7_2_4096 18
#define LOCK_19_7_3_4096 19
#define LOCK_20_7_6_4096 54
#define LOCK_20_7_7_4096 55
#define LOCK_19_7_0_0 16
#define LOCK_19_7_1_0 17
#define LOCK_19_7_4_0 20
#define LOCK_19_7_5_0 21

// Declare shared memory buffers
v4float buf944[256];
v4float buf944d[256];
v4float buf945[256];
v4float buf945d[256];
v4float buf946[256];
v4float buf946d[256];
v4float buf947[256];
v4float buf947d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf945_buf945d[1];
  window_datatype * buf945_ptr = (window_datatype * )buf945;
  window_datatype * buf945d_ptr = (window_datatype * )buf945d;
  window_init(window_buf945_buf945d, 1, buf945, LOCK_19_7_2_4096, buf945d, LOCK_19_7_3_4096, 256, 256);
  window_internal window_buf946_buf946d[1];
  window_datatype * buf946_ptr = (window_datatype * )buf946;
  window_datatype * buf946d_ptr = (window_datatype * )buf946d;
  window_init(window_buf946_buf946d, 1, buf946, LOCK_20_7_6_4096, buf946d, LOCK_20_7_7_4096, 256, 256);
  window_internal window_buf944_buf944d[1];
  window_datatype * buf944_ptr = (window_datatype * )buf944;
  window_datatype * buf944d_ptr = (window_datatype * )buf944d;
  window_init(window_buf944_buf944d, 1, buf944, LOCK_19_7_0_0, buf944d, LOCK_19_7_1_0, 256, 256);
  window_internal window_buf947_buf947d[1];
  window_datatype * buf947_ptr = (window_datatype * )buf947;
  window_datatype * buf947d_ptr = (window_datatype * )buf947d;
  window_init(window_buf947_buf947d, 1, buf947, LOCK_19_7_4_0, buf947d, LOCK_19_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_7_bounds = sync_buffer[1];

  while (proc_19_7_bounds)
  {

    // Kernel call : i553:mm_kernel1
    window_acquire(window_buf945_buf945d,LOCK_19_7_2_4096,LOCK_19_7_3_4096,buf945_ptr,buf945d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf946_buf946d,LOCK_20_7_6_4096,LOCK_20_7_7_4096,buf946_ptr,buf946d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf944_buf944d,LOCK_19_7_0_0,LOCK_19_7_1_0,buf944_ptr,buf944d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf947_buf947d,LOCK_19_7_4_0,LOCK_19_7_5_0,buf947_ptr,buf947d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf945_buf945d),get_input_window_float(window_buf946_buf946d),get_input_window_float(window_buf944_buf944d),get_output_window_float(window_buf947_buf947d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf945_buf945d,LOCK_19_7_2_4096,LOCK_19_7_3_4096,buf945_ptr,buf945d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf946_buf946d,LOCK_20_7_6_4096,LOCK_20_7_7_4096,buf946_ptr,buf946d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf944_buf944d,LOCK_19_7_0_0,LOCK_19_7_1_0,buf944_ptr,buf944d_ptr,0,index, REL_WRITE);
    window_release(window_buf947_buf947d,LOCK_19_7_4_0,LOCK_19_7_5_0,buf947_ptr,buf947d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_7_bounds > 0)
      --proc_19_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}