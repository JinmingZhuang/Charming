// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_7/src/42_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_6_4_0 4
#define LOCK_42_6_5_0 5
#define LOCK_42_7_0_0 16
#define LOCK_42_7_1_0 17
#define LOCK_42_6_2_4096 2
#define LOCK_42_6_3_4096 3
#define LOCK_42_6_6_4096 6
#define LOCK_42_6_7_4096 7

// Declare shared memory buffers
v4float buf668[256];
v4float buf668d[256];
v4float buf669[256];
v4float buf669d[256];
v4float buf670[256];
v4float buf670d[256];
v4float buf671[256];
v4float buf671d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf669_buf669d[1];
  window_datatype * buf669_ptr = (window_datatype * )buf669;
  window_datatype * buf669d_ptr = (window_datatype * )buf669d;
  window_init(window_buf669_buf669d, 1, buf669, LOCK_42_6_4_0, buf669d, LOCK_42_6_5_0, 256, 256);
  window_internal window_buf670_buf670d[1];
  window_datatype * buf670_ptr = (window_datatype * )buf670;
  window_datatype * buf670d_ptr = (window_datatype * )buf670d;
  window_init(window_buf670_buf670d, 1, buf670, LOCK_42_7_0_0, buf670d, LOCK_42_7_1_0, 256, 256);
  window_internal window_buf668_buf668d[1];
  window_datatype * buf668_ptr = (window_datatype * )buf668;
  window_datatype * buf668d_ptr = (window_datatype * )buf668d;
  window_init(window_buf668_buf668d, 1, buf668, LOCK_42_6_2_4096, buf668d, LOCK_42_6_3_4096, 256, 256);
  window_internal window_buf671_buf671d[1];
  window_datatype * buf671_ptr = (window_datatype * )buf671;
  window_datatype * buf671d_ptr = (window_datatype * )buf671d;
  window_init(window_buf671_buf671d, 1, buf671, LOCK_42_6_6_4096, buf671d, LOCK_42_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_7_bounds = sync_buffer[1];

  while (proc_42_7_bounds)
  {

    // Kernel call : i415:mm_kernel1
    window_acquire(window_buf669_buf669d,LOCK_42_6_4_0,LOCK_42_6_5_0,buf669_ptr,buf669d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf670_buf670d,LOCK_42_7_0_0,LOCK_42_7_1_0,buf670_ptr,buf670d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf668_buf668d,LOCK_42_6_2_4096,LOCK_42_6_3_4096,buf668_ptr,buf668d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf671_buf671d,LOCK_42_6_6_4096,LOCK_42_6_7_4096,buf671_ptr,buf671d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf669_buf669d),get_input_window_float(window_buf670_buf670d),get_input_window_float(window_buf668_buf668d),get_output_window_float(window_buf671_buf671d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf669_buf669d,LOCK_42_6_4_0,LOCK_42_6_5_0,buf669_ptr,buf669d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf670_buf670d,LOCK_42_7_0_0,LOCK_42_7_1_0,buf670_ptr,buf670d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf668_buf668d,LOCK_42_6_2_4096,LOCK_42_6_3_4096,buf668_ptr,buf668d_ptr,0,index, REL_WRITE);
    window_release(window_buf671_buf671d,LOCK_42_6_6_4096,LOCK_42_6_7_4096,buf671_ptr,buf671d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_7_bounds > 0)
      --proc_42_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}