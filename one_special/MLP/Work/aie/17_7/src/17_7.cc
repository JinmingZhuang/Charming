// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_7/src/17_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_7_2_4096 18
#define LOCK_17_7_3_4096 19
#define LOCK_17_7_4_0 20
#define LOCK_17_7_5_0 21
#define LOCK_17_7_0_0 16
#define LOCK_17_7_1_0 17
#define LOCK_17_7_6_4096 22
#define LOCK_17_7_7_4096 23

// Declare shared memory buffers
v4float buf968[256];
v4float buf968d[256];
v4float buf969[256];
v4float buf969d[256];
v4float buf970[256];
v4float buf970d[256];
v4float buf971[256];
v4float buf971d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf969_buf969d[1];
  window_datatype * buf969_ptr = (window_datatype * )buf969;
  window_datatype * buf969d_ptr = (window_datatype * )buf969d;
  window_init(window_buf969_buf969d, 1, buf969, LOCK_17_7_2_4096, buf969d, LOCK_17_7_3_4096, 256, 256);
  window_internal window_buf970_buf970d[1];
  window_datatype * buf970_ptr = (window_datatype * )buf970;
  window_datatype * buf970d_ptr = (window_datatype * )buf970d;
  window_init(window_buf970_buf970d, 1, buf970, LOCK_17_7_4_0, buf970d, LOCK_17_7_5_0, 256, 256);
  window_internal window_buf968_buf968d[1];
  window_datatype * buf968_ptr = (window_datatype * )buf968;
  window_datatype * buf968d_ptr = (window_datatype * )buf968d;
  window_init(window_buf968_buf968d, 1, buf968, LOCK_17_7_0_0, buf968d, LOCK_17_7_1_0, 256, 256);
  window_internal window_buf971_buf971d[1];
  window_datatype * buf971_ptr = (window_datatype * )buf971;
  window_datatype * buf971d_ptr = (window_datatype * )buf971d;
  window_init(window_buf971_buf971d, 1, buf971, LOCK_17_7_6_4096, buf971d, LOCK_17_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_7_bounds = sync_buffer[1];

  while (proc_17_7_bounds)
  {

    // Kernel call : i565:mm_kernel1
    window_acquire(window_buf969_buf969d,LOCK_17_7_2_4096,LOCK_17_7_3_4096,buf969_ptr,buf969d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf970_buf970d,LOCK_17_7_4_0,LOCK_17_7_5_0,buf970_ptr,buf970d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf968_buf968d,LOCK_17_7_0_0,LOCK_17_7_1_0,buf968_ptr,buf968d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf971_buf971d,LOCK_17_7_6_4096,LOCK_17_7_7_4096,buf971_ptr,buf971d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf969_buf969d),get_input_window_float(window_buf970_buf970d),get_input_window_float(window_buf968_buf968d),get_output_window_float(window_buf971_buf971d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf969_buf969d,LOCK_17_7_2_4096,LOCK_17_7_3_4096,buf969_ptr,buf969d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf970_buf970d,LOCK_17_7_4_0,LOCK_17_7_5_0,buf970_ptr,buf970d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf968_buf968d,LOCK_17_7_0_0,LOCK_17_7_1_0,buf968_ptr,buf968d_ptr,0,index, REL_WRITE);
    window_release(window_buf971_buf971d,LOCK_17_7_6_4096,LOCK_17_7_7_4096,buf971_ptr,buf971d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_7_bounds > 0)
      --proc_17_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}