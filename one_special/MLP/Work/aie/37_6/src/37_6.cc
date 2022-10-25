// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_6/src/37_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_7_0_4096 32
#define LOCK_37_7_1_0 33
#define LOCK_37_7_2_0 34
#define LOCK_37_7_3_0 35
#define LOCK_37_5_6_0 6
#define LOCK_37_5_7_0 7
#define LOCK_37_7_4_4096 36
#define LOCK_37_7_5_0 37

// Declare shared memory buffers
v4float buf725[256];
v4float buf725d[256];
v4float buf726[256];
v4float buf726d[256];
v4float buf727[256];
v4float buf727d[256];
v4float buf728[256];
v4float buf728d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf726_buf726d[1];
  window_datatype * buf726_ptr = (window_datatype * )buf726;
  window_datatype * buf726d_ptr = (window_datatype * )buf726d;
  window_init(window_buf726_buf726d, 1, buf726, LOCK_37_7_0_4096, buf726d, LOCK_37_7_1_0, 256, 256);
  window_internal window_buf727_buf727d[1];
  window_datatype * buf727_ptr = (window_datatype * )buf727;
  window_datatype * buf727d_ptr = (window_datatype * )buf727d;
  window_init(window_buf727_buf727d, 1, buf727, LOCK_37_7_2_0, buf727d, LOCK_37_7_3_0, 256, 256);
  window_internal window_buf725_buf725d[1];
  window_datatype * buf725_ptr = (window_datatype * )buf725;
  window_datatype * buf725d_ptr = (window_datatype * )buf725d;
  window_init(window_buf725_buf725d, 1, buf725, LOCK_37_5_6_0, buf725d, LOCK_37_5_7_0, 256, 256);
  window_internal window_buf728_buf728d[1];
  window_datatype * buf728_ptr = (window_datatype * )buf728;
  window_datatype * buf728d_ptr = (window_datatype * )buf728d;
  window_init(window_buf728_buf728d, 1, buf728, LOCK_37_7_4_4096, buf728d, LOCK_37_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_6_bounds = sync_buffer[1];

  while (proc_37_6_bounds)
  {

    // Kernel call : i444:mm_kernel1
    window_acquire(window_buf726_buf726d,LOCK_37_7_0_4096,LOCK_37_7_1_0,buf726_ptr,buf726d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf727_buf727d,LOCK_37_7_2_0,LOCK_37_7_3_0,buf727_ptr,buf727d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf725_buf725d,LOCK_37_5_6_0,LOCK_37_5_7_0,buf725_ptr,buf725d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf728_buf728d,LOCK_37_7_4_4096,LOCK_37_7_5_0,buf728_ptr,buf728d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf726_buf726d),get_input_window_float(window_buf727_buf727d),get_input_window_float(window_buf725_buf725d),get_output_window_float(window_buf728_buf728d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf726_buf726d,LOCK_37_7_0_4096,LOCK_37_7_1_0,buf726_ptr,buf726d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf727_buf727d,LOCK_37_7_2_0,LOCK_37_7_3_0,buf727_ptr,buf727d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf725_buf725d,LOCK_37_5_6_0,LOCK_37_5_7_0,buf725_ptr,buf725d_ptr,0,index, REL_WRITE);
    window_release(window_buf728_buf728d,LOCK_37_7_4_4096,LOCK_37_7_5_0,buf728_ptr,buf728d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_6_bounds > 0)
      --proc_37_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}