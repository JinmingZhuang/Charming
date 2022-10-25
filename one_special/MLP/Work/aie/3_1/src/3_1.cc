// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_1/src/3_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_1_0_0 48
#define LOCK_4_1_1_0 49
#define LOCK_3_2_0_0 32
#define LOCK_3_2_1_0 33
#define LOCK_3_1_2_0 18
#define LOCK_3_1_3_4096 19
#define LOCK_3_1_4_4096 20
#define LOCK_3_1_5_0 21

// Declare shared memory buffers
v4float buf14[256];
v4float buf14d[256];
v4float buf15[256];
v4float buf15d[256];
v4float buf16[256];
v4float buf16d[256];
v4float buf17[256];
v4float buf17d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf15_buf15d[1];
  window_datatype * buf15_ptr = (window_datatype * )buf15;
  window_datatype * buf15d_ptr = (window_datatype * )buf15d;
  window_init(window_buf15_buf15d, 1, buf15, LOCK_4_1_0_0, buf15d, LOCK_4_1_1_0, 256, 256);
  window_internal window_buf16_buf16d[1];
  window_datatype * buf16_ptr = (window_datatype * )buf16;
  window_datatype * buf16d_ptr = (window_datatype * )buf16d;
  window_init(window_buf16_buf16d, 1, buf16, LOCK_3_2_0_0, buf16d, LOCK_3_2_1_0, 256, 256);
  window_internal window_buf14_buf14d[1];
  window_datatype * buf14_ptr = (window_datatype * )buf14;
  window_datatype * buf14d_ptr = (window_datatype * )buf14d;
  window_init(window_buf14_buf14d, 1, buf14, LOCK_3_1_2_0, buf14d, LOCK_3_1_3_4096, 256, 256);
  window_internal window_buf17_buf17d[1];
  window_datatype * buf17_ptr = (window_datatype * )buf17;
  window_datatype * buf17d_ptr = (window_datatype * )buf17d;
  window_init(window_buf17_buf17d, 1, buf17, LOCK_3_1_4_4096, buf17d, LOCK_3_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_1_bounds = sync_buffer[1];

  while (proc_3_1_bounds)
  {

    // Kernel call : i89:mm_kernel1
    window_acquire(window_buf15_buf15d,LOCK_4_1_0_0,LOCK_4_1_1_0,buf15_ptr,buf15d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf16_buf16d,LOCK_3_2_0_0,LOCK_3_2_1_0,buf16_ptr,buf16d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf14_buf14d,LOCK_3_1_2_0,LOCK_3_1_3_4096,buf14_ptr,buf14d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf17_buf17d,LOCK_3_1_4_4096,LOCK_3_1_5_0,buf17_ptr,buf17d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf15_buf15d),get_input_window_float(window_buf16_buf16d),get_input_window_float(window_buf14_buf14d),get_output_window_float(window_buf17_buf17d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf15_buf15d,LOCK_4_1_0_0,LOCK_4_1_1_0,buf15_ptr,buf15d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf16_buf16d,LOCK_3_2_0_0,LOCK_3_2_1_0,buf16_ptr,buf16d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf14_buf14d,LOCK_3_1_2_0,LOCK_3_1_3_4096,buf14_ptr,buf14d_ptr,0,index, REL_WRITE);
    window_release(window_buf17_buf17d,LOCK_3_1_4_4096,LOCK_3_1_5_0,buf17_ptr,buf17d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_1_bounds > 0)
      --proc_3_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}