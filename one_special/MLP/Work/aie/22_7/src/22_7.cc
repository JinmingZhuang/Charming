// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_7/src/22_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_7_2_4096 18
#define LOCK_22_7_3_4096 19
#define LOCK_22_7_4_0 20
#define LOCK_22_7_5_0 21
#define LOCK_22_7_0_0 16
#define LOCK_22_7_1_0 17
#define LOCK_22_7_6_4096 22
#define LOCK_22_7_7_4096 23

// Declare shared memory buffers
v4float buf908[256];
v4float buf908d[256];
v4float buf909[256];
v4float buf909d[256];
v4float buf910[256];
v4float buf910d[256];
v4float buf911[256];
v4float buf911d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf909_buf909d[1];
  window_datatype * buf909_ptr = (window_datatype * )buf909;
  window_datatype * buf909d_ptr = (window_datatype * )buf909d;
  window_init(window_buf909_buf909d, 1, buf909, LOCK_22_7_2_4096, buf909d, LOCK_22_7_3_4096, 256, 256);
  window_internal window_buf910_buf910d[1];
  window_datatype * buf910_ptr = (window_datatype * )buf910;
  window_datatype * buf910d_ptr = (window_datatype * )buf910d;
  window_init(window_buf910_buf910d, 1, buf910, LOCK_22_7_4_0, buf910d, LOCK_22_7_5_0, 256, 256);
  window_internal window_buf908_buf908d[1];
  window_datatype * buf908_ptr = (window_datatype * )buf908;
  window_datatype * buf908d_ptr = (window_datatype * )buf908d;
  window_init(window_buf908_buf908d, 1, buf908, LOCK_22_7_0_0, buf908d, LOCK_22_7_1_0, 256, 256);
  window_internal window_buf911_buf911d[1];
  window_datatype * buf911_ptr = (window_datatype * )buf911;
  window_datatype * buf911d_ptr = (window_datatype * )buf911d;
  window_init(window_buf911_buf911d, 1, buf911, LOCK_22_7_6_4096, buf911d, LOCK_22_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_7_bounds = sync_buffer[1];

  while (proc_22_7_bounds)
  {

    // Kernel call : i535:mm_kernel1
    window_acquire(window_buf909_buf909d,LOCK_22_7_2_4096,LOCK_22_7_3_4096,buf909_ptr,buf909d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf910_buf910d,LOCK_22_7_4_0,LOCK_22_7_5_0,buf910_ptr,buf910d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf908_buf908d,LOCK_22_7_0_0,LOCK_22_7_1_0,buf908_ptr,buf908d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf911_buf911d,LOCK_22_7_6_4096,LOCK_22_7_7_4096,buf911_ptr,buf911d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf909_buf909d),get_input_window_float(window_buf910_buf910d),get_input_window_float(window_buf908_buf908d),get_output_window_float(window_buf911_buf911d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf909_buf909d,LOCK_22_7_2_4096,LOCK_22_7_3_4096,buf909_ptr,buf909d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf910_buf910d,LOCK_22_7_4_0,LOCK_22_7_5_0,buf910_ptr,buf910d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf908_buf908d,LOCK_22_7_0_0,LOCK_22_7_1_0,buf908_ptr,buf908d_ptr,0,index, REL_WRITE);
    window_release(window_buf911_buf911d,LOCK_22_7_6_4096,LOCK_22_7_7_4096,buf911_ptr,buf911d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_7_bounds > 0)
      --proc_22_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}