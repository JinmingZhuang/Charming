// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_2/src/16_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_16_2_0_4096 48
#define LOCK_16_2_1_4096 49
#define LOCK_16_2_2_0 50
#define LOCK_16_2_3_0 51
#define LOCK_16_1_6_0 6
#define LOCK_16_1_7_4096 7
#define LOCK_16_3_2_0 34
#define LOCK_16_3_3_4096 35

// Declare shared memory buffers
v4float buf173[256];
v4float buf173d[256];
v4float buf174[256];
v4float buf174d[256];
v4float buf175[256];
v4float buf175d[256];
v4float buf176[256];
v4float buf176d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf174_buf174d[1];
  window_datatype * buf174_ptr = (window_datatype * )buf174;
  window_datatype * buf174d_ptr = (window_datatype * )buf174d;
  window_init(window_buf174_buf174d, 1, buf174, LOCK_16_2_0_4096, buf174d, LOCK_16_2_1_4096, 256, 256);
  window_internal window_buf175_buf175d[1];
  window_datatype * buf175_ptr = (window_datatype * )buf175;
  window_datatype * buf175d_ptr = (window_datatype * )buf175d;
  window_init(window_buf175_buf175d, 1, buf175, LOCK_16_2_2_0, buf175d, LOCK_16_2_3_0, 256, 256);
  window_internal window_buf173_buf173d[1];
  window_datatype * buf173_ptr = (window_datatype * )buf173;
  window_datatype * buf173d_ptr = (window_datatype * )buf173d;
  window_init(window_buf173_buf173d, 1, buf173, LOCK_16_1_6_0, buf173d, LOCK_16_1_7_4096, 256, 256);
  window_internal window_buf176_buf176d[1];
  window_datatype * buf176_ptr = (window_datatype * )buf176;
  window_datatype * buf176d_ptr = (window_datatype * )buf176d;
  window_init(window_buf176_buf176d, 1, buf176, LOCK_16_3_2_0, buf176d, LOCK_16_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_2_bounds = sync_buffer[1];

  while (proc_16_2_bounds)
  {

    // Kernel call : i168:mm_kernel1
    window_acquire(window_buf174_buf174d,LOCK_16_2_0_4096,LOCK_16_2_1_4096,buf174_ptr,buf174d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf175_buf175d,LOCK_16_2_2_0,LOCK_16_2_3_0,buf175_ptr,buf175d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf173_buf173d,LOCK_16_1_6_0,LOCK_16_1_7_4096,buf173_ptr,buf173d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf176_buf176d,LOCK_16_3_2_0,LOCK_16_3_3_4096,buf176_ptr,buf176d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf174_buf174d),get_input_window_float(window_buf175_buf175d),get_input_window_float(window_buf173_buf173d),get_output_window_float(window_buf176_buf176d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf174_buf174d,LOCK_16_2_0_4096,LOCK_16_2_1_4096,buf174_ptr,buf174d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf175_buf175d,LOCK_16_2_2_0,LOCK_16_2_3_0,buf175_ptr,buf175d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf173_buf173d,LOCK_16_1_6_0,LOCK_16_1_7_4096,buf173_ptr,buf173d_ptr,0,index, REL_WRITE);
    window_release(window_buf176_buf176d,LOCK_16_3_2_0,LOCK_16_3_3_4096,buf176_ptr,buf176d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_2_bounds > 0)
      --proc_16_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}