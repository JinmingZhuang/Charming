// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_2/src/48_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_3_0_0 32
#define LOCK_48_3_1_0 33
#define LOCK_48_3_2_4096 34
#define LOCK_48_3_3_4096 35
#define LOCK_48_1_6_0 6
#define LOCK_48_1_7_0 7
#define LOCK_48_2_0_0 48
#define LOCK_48_2_1_0 49

// Declare shared memory buffers
v4float buf557[256];
v4float buf557d[256];
v4float buf558[256];
v4float buf558d[256];
v4float buf559[256];
v4float buf559d[256];
v4float buf560[256];
v4float buf560d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf558_buf558d[1];
  window_datatype * buf558_ptr = (window_datatype * )buf558;
  window_datatype * buf558d_ptr = (window_datatype * )buf558d;
  window_init(window_buf558_buf558d, 1, buf558, LOCK_48_3_0_0, buf558d, LOCK_48_3_1_0, 256, 256);
  window_internal window_buf559_buf559d[1];
  window_datatype * buf559_ptr = (window_datatype * )buf559;
  window_datatype * buf559d_ptr = (window_datatype * )buf559d;
  window_init(window_buf559_buf559d, 1, buf559, LOCK_48_3_2_4096, buf559d, LOCK_48_3_3_4096, 256, 256);
  window_internal window_buf557_buf557d[1];
  window_datatype * buf557_ptr = (window_datatype * )buf557;
  window_datatype * buf557d_ptr = (window_datatype * )buf557d;
  window_init(window_buf557_buf557d, 1, buf557, LOCK_48_1_6_0, buf557d, LOCK_48_1_7_0, 256, 256);
  window_internal window_buf560_buf560d[1];
  window_datatype * buf560_ptr = (window_datatype * )buf560;
  window_datatype * buf560d_ptr = (window_datatype * )buf560d;
  window_init(window_buf560_buf560d, 1, buf560, LOCK_48_2_0_0, buf560d, LOCK_48_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_2_bounds = sync_buffer[1];

  while (proc_48_2_bounds)
  {

    // Kernel call : i360:mm_kernel1
    window_acquire(window_buf558_buf558d,LOCK_48_3_0_0,LOCK_48_3_1_0,buf558_ptr,buf558d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf559_buf559d,LOCK_48_3_2_4096,LOCK_48_3_3_4096,buf559_ptr,buf559d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf557_buf557d,LOCK_48_1_6_0,LOCK_48_1_7_0,buf557_ptr,buf557d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf560_buf560d,LOCK_48_2_0_0,LOCK_48_2_1_0,buf560_ptr,buf560d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf558_buf558d),get_input_window_float(window_buf559_buf559d),get_input_window_float(window_buf557_buf557d),get_output_window_float(window_buf560_buf560d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf558_buf558d,LOCK_48_3_0_0,LOCK_48_3_1_0,buf558_ptr,buf558d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf559_buf559d,LOCK_48_3_2_4096,LOCK_48_3_3_4096,buf559_ptr,buf559d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf557_buf557d,LOCK_48_1_6_0,LOCK_48_1_7_0,buf557_ptr,buf557d_ptr,0,index, REL_WRITE);
    window_release(window_buf560_buf560d,LOCK_48_2_0_0,LOCK_48_2_1_0,buf560_ptr,buf560d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_2_bounds > 0)
      --proc_48_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}