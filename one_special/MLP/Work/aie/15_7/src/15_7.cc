// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_7/src/15_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_7_2_4096 18
#define LOCK_15_7_3_4096 19
#define LOCK_15_7_4_0 20
#define LOCK_15_7_5_0 21
#define LOCK_15_7_0_0 16
#define LOCK_15_7_1_0 17
#define LOCK_15_7_6_4096 22
#define LOCK_15_7_7_4096 23

// Declare shared memory buffers
v4float buf992[256];
v4float buf992d[256];
v4float buf993[256];
v4float buf993d[256];
v4float buf994[256];
v4float buf994d[256];
v4float buf995[256];
v4float buf995d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf993_buf993d[1];
  window_datatype * buf993_ptr = (window_datatype * )buf993;
  window_datatype * buf993d_ptr = (window_datatype * )buf993d;
  window_init(window_buf993_buf993d, 1, buf993, LOCK_15_7_2_4096, buf993d, LOCK_15_7_3_4096, 256, 256);
  window_internal window_buf994_buf994d[1];
  window_datatype * buf994_ptr = (window_datatype * )buf994;
  window_datatype * buf994d_ptr = (window_datatype * )buf994d;
  window_init(window_buf994_buf994d, 1, buf994, LOCK_15_7_4_0, buf994d, LOCK_15_7_5_0, 256, 256);
  window_internal window_buf992_buf992d[1];
  window_datatype * buf992_ptr = (window_datatype * )buf992;
  window_datatype * buf992d_ptr = (window_datatype * )buf992d;
  window_init(window_buf992_buf992d, 1, buf992, LOCK_15_7_0_0, buf992d, LOCK_15_7_1_0, 256, 256);
  window_internal window_buf995_buf995d[1];
  window_datatype * buf995_ptr = (window_datatype * )buf995;
  window_datatype * buf995d_ptr = (window_datatype * )buf995d;
  window_init(window_buf995_buf995d, 1, buf995, LOCK_15_7_6_4096, buf995d, LOCK_15_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_7_bounds = sync_buffer[1];

  while (proc_15_7_bounds)
  {

    // Kernel call : i577:mm_kernel1
    window_acquire(window_buf993_buf993d,LOCK_15_7_2_4096,LOCK_15_7_3_4096,buf993_ptr,buf993d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf994_buf994d,LOCK_15_7_4_0,LOCK_15_7_5_0,buf994_ptr,buf994d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf992_buf992d,LOCK_15_7_0_0,LOCK_15_7_1_0,buf992_ptr,buf992d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf995_buf995d,LOCK_15_7_6_4096,LOCK_15_7_7_4096,buf995_ptr,buf995d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf993_buf993d),get_input_window_float(window_buf994_buf994d),get_input_window_float(window_buf992_buf992d),get_output_window_float(window_buf995_buf995d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf993_buf993d,LOCK_15_7_2_4096,LOCK_15_7_3_4096,buf993_ptr,buf993d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf994_buf994d,LOCK_15_7_4_0,LOCK_15_7_5_0,buf994_ptr,buf994d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf992_buf992d,LOCK_15_7_0_0,LOCK_15_7_1_0,buf992_ptr,buf992d_ptr,0,index, REL_WRITE);
    window_release(window_buf995_buf995d,LOCK_15_7_6_4096,LOCK_15_7_7_4096,buf995_ptr,buf995d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_7_bounds > 0)
      --proc_15_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}