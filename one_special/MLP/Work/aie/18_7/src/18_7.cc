// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_7/src/18_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_7_4_4096 20
#define LOCK_18_7_5_0 21
#define LOCK_19_7_6_4096 54
#define LOCK_19_7_7_4096 55
#define LOCK_18_7_2_4096 18
#define LOCK_18_7_3_4096 19
#define LOCK_18_7_6_0 22
#define LOCK_18_7_7_0 23

// Declare shared memory buffers
v4float buf956[256];
v4float buf956d[256];
v4float buf957[256];
v4float buf957d[256];
v4float buf958[256];
v4float buf958d[256];
v4float buf959[256];
v4float buf959d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf957_buf957d[1];
  window_datatype * buf957_ptr = (window_datatype * )buf957;
  window_datatype * buf957d_ptr = (window_datatype * )buf957d;
  window_init(window_buf957_buf957d, 1, buf957, LOCK_18_7_4_4096, buf957d, LOCK_18_7_5_0, 256, 256);
  window_internal window_buf958_buf958d[1];
  window_datatype * buf958_ptr = (window_datatype * )buf958;
  window_datatype * buf958d_ptr = (window_datatype * )buf958d;
  window_init(window_buf958_buf958d, 1, buf958, LOCK_19_7_6_4096, buf958d, LOCK_19_7_7_4096, 256, 256);
  window_internal window_buf956_buf956d[1];
  window_datatype * buf956_ptr = (window_datatype * )buf956;
  window_datatype * buf956d_ptr = (window_datatype * )buf956d;
  window_init(window_buf956_buf956d, 1, buf956, LOCK_18_7_2_4096, buf956d, LOCK_18_7_3_4096, 256, 256);
  window_internal window_buf959_buf959d[1];
  window_datatype * buf959_ptr = (window_datatype * )buf959;
  window_datatype * buf959d_ptr = (window_datatype * )buf959d;
  window_init(window_buf959_buf959d, 1, buf959, LOCK_18_7_6_0, buf959d, LOCK_18_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_7_bounds = sync_buffer[1];

  while (proc_18_7_bounds)
  {

    // Kernel call : i559:mm_kernel1
    window_acquire(window_buf957_buf957d,LOCK_18_7_4_4096,LOCK_18_7_5_0,buf957_ptr,buf957d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf958_buf958d,LOCK_19_7_6_4096,LOCK_19_7_7_4096,buf958_ptr,buf958d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf956_buf956d,LOCK_18_7_2_4096,LOCK_18_7_3_4096,buf956_ptr,buf956d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf959_buf959d,LOCK_18_7_6_0,LOCK_18_7_7_0,buf959_ptr,buf959d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf957_buf957d),get_input_window_float(window_buf958_buf958d),get_input_window_float(window_buf956_buf956d),get_output_window_float(window_buf959_buf959d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf957_buf957d,LOCK_18_7_4_4096,LOCK_18_7_5_0,buf957_ptr,buf957d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf958_buf958d,LOCK_19_7_6_4096,LOCK_19_7_7_4096,buf958_ptr,buf958d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf956_buf956d,LOCK_18_7_2_4096,LOCK_18_7_3_4096,buf956_ptr,buf956d_ptr,0,index, REL_WRITE);
    window_release(window_buf959_buf959d,LOCK_18_7_6_0,LOCK_18_7_7_0,buf959_ptr,buf959d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_7_bounds > 0)
      --proc_18_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}