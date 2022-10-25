// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_6/src/19_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_6_0_0 16
#define LOCK_18_6_1_0 17
#define LOCK_19_5_6_4096 6
#define LOCK_19_5_7_4096 7
#define LOCK_19_5_4_0 4
#define LOCK_19_5_5_4096 5
#define LOCK_19_7_0_0 32
#define LOCK_19_7_1_0 33

// Declare shared memory buffers
v4float buf941[256];
v4float buf941d[256];
v4float buf942[256];
v4float buf942d[256];
v4float buf943[256];
v4float buf943d[256];
v4float buf944[256];
v4float buf944d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf942_buf942d[1];
  window_datatype * buf942_ptr = (window_datatype * )buf942;
  window_datatype * buf942d_ptr = (window_datatype * )buf942d;
  window_init(window_buf942_buf942d, 1, buf942, LOCK_18_6_0_0, buf942d, LOCK_18_6_1_0, 256, 256);
  window_internal window_buf943_buf943d[1];
  window_datatype * buf943_ptr = (window_datatype * )buf943;
  window_datatype * buf943d_ptr = (window_datatype * )buf943d;
  window_init(window_buf943_buf943d, 1, buf943, LOCK_19_5_6_4096, buf943d, LOCK_19_5_7_4096, 256, 256);
  window_internal window_buf941_buf941d[1];
  window_datatype * buf941_ptr = (window_datatype * )buf941;
  window_datatype * buf941d_ptr = (window_datatype * )buf941d;
  window_init(window_buf941_buf941d, 1, buf941, LOCK_19_5_4_0, buf941d, LOCK_19_5_5_4096, 256, 256);
  window_internal window_buf944_buf944d[1];
  window_datatype * buf944_ptr = (window_datatype * )buf944;
  window_datatype * buf944d_ptr = (window_datatype * )buf944d;
  window_init(window_buf944_buf944d, 1, buf944, LOCK_19_7_0_0, buf944d, LOCK_19_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_6_bounds = sync_buffer[1];

  while (proc_19_6_bounds)
  {

    // Kernel call : i552:mm_kernel1
    window_acquire(window_buf942_buf942d,LOCK_18_6_0_0,LOCK_18_6_1_0,buf942_ptr,buf942d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf943_buf943d,LOCK_19_5_6_4096,LOCK_19_5_7_4096,buf943_ptr,buf943d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf941_buf941d,LOCK_19_5_4_0,LOCK_19_5_5_4096,buf941_ptr,buf941d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf944_buf944d,LOCK_19_7_0_0,LOCK_19_7_1_0,buf944_ptr,buf944d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf942_buf942d),get_input_window_float(window_buf943_buf943d),get_input_window_float(window_buf941_buf941d),get_output_window_float(window_buf944_buf944d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf942_buf942d,LOCK_18_6_0_0,LOCK_18_6_1_0,buf942_ptr,buf942d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf943_buf943d,LOCK_19_5_6_4096,LOCK_19_5_7_4096,buf943_ptr,buf943d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf941_buf941d,LOCK_19_5_4_0,LOCK_19_5_5_4096,buf941_ptr,buf941d_ptr,0,index, REL_WRITE);
    window_release(window_buf944_buf944d,LOCK_19_7_0_0,LOCK_19_7_1_0,buf944_ptr,buf944d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_6_bounds > 0)
      --proc_19_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}