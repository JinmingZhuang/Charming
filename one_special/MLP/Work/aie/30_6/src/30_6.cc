// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_6/src/30_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_30_6_0_0 48
#define LOCK_30_6_1_4096 49
#define LOCK_30_6_2_4096 50
#define LOCK_30_6_3_0 51
#define LOCK_30_5_6_4096 6
#define LOCK_30_5_7_4096 7
#define LOCK_30_7_0_0 32
#define LOCK_30_7_1_0 33

// Declare shared memory buffers
v4float buf809[256];
v4float buf809d[256];
v4float buf810[256];
v4float buf810d[256];
v4float buf811[256];
v4float buf811d[256];
v4float buf812[256];
v4float buf812d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf810_buf810d[1];
  window_datatype * buf810_ptr = (window_datatype * )buf810;
  window_datatype * buf810d_ptr = (window_datatype * )buf810d;
  window_init(window_buf810_buf810d, 1, buf810, LOCK_30_6_0_0, buf810d, LOCK_30_6_1_4096, 256, 256);
  window_internal window_buf811_buf811d[1];
  window_datatype * buf811_ptr = (window_datatype * )buf811;
  window_datatype * buf811d_ptr = (window_datatype * )buf811d;
  window_init(window_buf811_buf811d, 1, buf811, LOCK_30_6_2_4096, buf811d, LOCK_30_6_3_0, 256, 256);
  window_internal window_buf809_buf809d[1];
  window_datatype * buf809_ptr = (window_datatype * )buf809;
  window_datatype * buf809d_ptr = (window_datatype * )buf809d;
  window_init(window_buf809_buf809d, 1, buf809, LOCK_30_5_6_4096, buf809d, LOCK_30_5_7_4096, 256, 256);
  window_internal window_buf812_buf812d[1];
  window_datatype * buf812_ptr = (window_datatype * )buf812;
  window_datatype * buf812d_ptr = (window_datatype * )buf812d;
  window_init(window_buf812_buf812d, 1, buf812, LOCK_30_7_0_0, buf812d, LOCK_30_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_6_bounds = sync_buffer[1];

  while (proc_30_6_bounds)
  {

    // Kernel call : i486:mm_kernel1
    window_acquire(window_buf810_buf810d,LOCK_30_6_0_0,LOCK_30_6_1_4096,buf810_ptr,buf810d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf811_buf811d,LOCK_30_6_2_4096,LOCK_30_6_3_0,buf811_ptr,buf811d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf809_buf809d,LOCK_30_5_6_4096,LOCK_30_5_7_4096,buf809_ptr,buf809d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf812_buf812d,LOCK_30_7_0_0,LOCK_30_7_1_0,buf812_ptr,buf812d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf810_buf810d),get_input_window_float(window_buf811_buf811d),get_input_window_float(window_buf809_buf809d),get_output_window_float(window_buf812_buf812d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf810_buf810d,LOCK_30_6_0_0,LOCK_30_6_1_4096,buf810_ptr,buf810d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf811_buf811d,LOCK_30_6_2_4096,LOCK_30_6_3_0,buf811_ptr,buf811d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf809_buf809d,LOCK_30_5_6_4096,LOCK_30_5_7_4096,buf809_ptr,buf809d_ptr,0,index, REL_WRITE);
    window_release(window_buf812_buf812d,LOCK_30_7_0_0,LOCK_30_7_1_0,buf812_ptr,buf812d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_6_bounds > 0)
      --proc_30_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}