// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_6/src/17_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_6_2_4096 50
#define LOCK_17_6_3_4096 51
#define LOCK_16_6_0_0 16
#define LOCK_16_6_1_0 17
#define LOCK_17_5_4_4096 4
#define LOCK_17_5_5_0 5
#define LOCK_17_7_0_0 32
#define LOCK_17_7_1_0 33

// Declare shared memory buffers
v4float buf965[256];
v4float buf965d[256];
v4float buf966[256];
v4float buf966d[256];
v4float buf967[256];
v4float buf967d[256];
v4float buf968[256];
v4float buf968d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf966_buf966d[1];
  window_datatype * buf966_ptr = (window_datatype * )buf966;
  window_datatype * buf966d_ptr = (window_datatype * )buf966d;
  window_init(window_buf966_buf966d, 1, buf966, LOCK_17_6_2_4096, buf966d, LOCK_17_6_3_4096, 256, 256);
  window_internal window_buf967_buf967d[1];
  window_datatype * buf967_ptr = (window_datatype * )buf967;
  window_datatype * buf967d_ptr = (window_datatype * )buf967d;
  window_init(window_buf967_buf967d, 1, buf967, LOCK_16_6_0_0, buf967d, LOCK_16_6_1_0, 256, 256);
  window_internal window_buf965_buf965d[1];
  window_datatype * buf965_ptr = (window_datatype * )buf965;
  window_datatype * buf965d_ptr = (window_datatype * )buf965d;
  window_init(window_buf965_buf965d, 1, buf965, LOCK_17_5_4_4096, buf965d, LOCK_17_5_5_0, 256, 256);
  window_internal window_buf968_buf968d[1];
  window_datatype * buf968_ptr = (window_datatype * )buf968;
  window_datatype * buf968d_ptr = (window_datatype * )buf968d;
  window_init(window_buf968_buf968d, 1, buf968, LOCK_17_7_0_0, buf968d, LOCK_17_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_6_bounds = sync_buffer[1];

  while (proc_17_6_bounds)
  {

    // Kernel call : i564:mm_kernel1
    window_acquire(window_buf966_buf966d,LOCK_17_6_2_4096,LOCK_17_6_3_4096,buf966_ptr,buf966d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf967_buf967d,LOCK_16_6_0_0,LOCK_16_6_1_0,buf967_ptr,buf967d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf965_buf965d,LOCK_17_5_4_4096,LOCK_17_5_5_0,buf965_ptr,buf965d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf968_buf968d,LOCK_17_7_0_0,LOCK_17_7_1_0,buf968_ptr,buf968d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf966_buf966d),get_input_window_float(window_buf967_buf967d),get_input_window_float(window_buf965_buf965d),get_output_window_float(window_buf968_buf968d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf966_buf966d,LOCK_17_6_2_4096,LOCK_17_6_3_4096,buf966_ptr,buf966d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf967_buf967d,LOCK_16_6_0_0,LOCK_16_6_1_0,buf967_ptr,buf967d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf965_buf965d,LOCK_17_5_4_4096,LOCK_17_5_5_0,buf965_ptr,buf965d_ptr,0,index, REL_WRITE);
    window_release(window_buf968_buf968d,LOCK_17_7_0_0,LOCK_17_7_1_0,buf968_ptr,buf968d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_6_bounds > 0)
      --proc_17_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}