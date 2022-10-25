// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_3/src/33_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_4_0_0 32
#define LOCK_33_4_1_0 33
#define LOCK_33_2_4_0 4
#define LOCK_33_2_5_0 5
#define LOCK_33_2_2_0 2
#define LOCK_33_2_3_4096 3
#define LOCK_33_2_6_4096 6
#define LOCK_33_2_7_4096 7

// Declare shared memory buffers
v4float buf380[256];
v4float buf380d[256];
v4float buf381[256];
v4float buf381d[256];
v4float buf382[256];
v4float buf382d[256];
v4float buf383[256];
v4float buf383d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf381_buf381d[1];
  window_datatype * buf381_ptr = (window_datatype * )buf381;
  window_datatype * buf381d_ptr = (window_datatype * )buf381d;
  window_init(window_buf381_buf381d, 1, buf381, LOCK_33_4_0_0, buf381d, LOCK_33_4_1_0, 256, 256);
  window_internal window_buf382_buf382d[1];
  window_datatype * buf382_ptr = (window_datatype * )buf382;
  window_datatype * buf382d_ptr = (window_datatype * )buf382d;
  window_init(window_buf382_buf382d, 1, buf382, LOCK_33_2_4_0, buf382d, LOCK_33_2_5_0, 256, 256);
  window_internal window_buf380_buf380d[1];
  window_datatype * buf380_ptr = (window_datatype * )buf380;
  window_datatype * buf380d_ptr = (window_datatype * )buf380d;
  window_init(window_buf380_buf380d, 1, buf380, LOCK_33_2_2_0, buf380d, LOCK_33_2_3_4096, 256, 256);
  window_internal window_buf383_buf383d[1];
  window_datatype * buf383_ptr = (window_datatype * )buf383;
  window_datatype * buf383d_ptr = (window_datatype * )buf383d;
  window_init(window_buf383_buf383d, 1, buf383, LOCK_33_2_6_4096, buf383d, LOCK_33_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_3_bounds = sync_buffer[1];

  while (proc_33_3_bounds)
  {

    // Kernel call : i271:mm_kernel1
    window_acquire(window_buf381_buf381d,LOCK_33_4_0_0,LOCK_33_4_1_0,buf381_ptr,buf381d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf382_buf382d,LOCK_33_2_4_0,LOCK_33_2_5_0,buf382_ptr,buf382d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf380_buf380d,LOCK_33_2_2_0,LOCK_33_2_3_4096,buf380_ptr,buf380d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf383_buf383d,LOCK_33_2_6_4096,LOCK_33_2_7_4096,buf383_ptr,buf383d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf381_buf381d),get_input_window_float(window_buf382_buf382d),get_input_window_float(window_buf380_buf380d),get_output_window_float(window_buf383_buf383d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf381_buf381d,LOCK_33_4_0_0,LOCK_33_4_1_0,buf381_ptr,buf381d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf382_buf382d,LOCK_33_2_4_0,LOCK_33_2_5_0,buf382_ptr,buf382d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf380_buf380d,LOCK_33_2_2_0,LOCK_33_2_3_4096,buf380_ptr,buf380d_ptr,0,index, REL_WRITE);
    window_release(window_buf383_buf383d,LOCK_33_2_6_4096,LOCK_33_2_7_4096,buf383_ptr,buf383d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_3_bounds > 0)
      --proc_33_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}