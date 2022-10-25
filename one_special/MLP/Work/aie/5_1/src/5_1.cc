// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_1/src/5_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_0_2_4096 2
#define LOCK_5_0_3_4096 3
#define LOCK_5_2_0_0 32
#define LOCK_5_2_1_0 33
#define LOCK_5_1_2_4096 18
#define LOCK_5_1_3_0 19
#define LOCK_5_1_4_4096 20
#define LOCK_5_1_5_0 21

// Declare shared memory buffers
v4float buf38[256];
v4float buf38d[256];
v4float buf39[256];
v4float buf39d[256];
v4float buf40[256];
v4float buf40d[256];
v4float buf41[256];
v4float buf41d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf39_buf39d[1];
  window_datatype * buf39_ptr = (window_datatype * )buf39;
  window_datatype * buf39d_ptr = (window_datatype * )buf39d;
  window_init(window_buf39_buf39d, 1, buf39, LOCK_5_0_2_4096, buf39d, LOCK_5_0_3_4096, 256, 256);
  window_internal window_buf40_buf40d[1];
  window_datatype * buf40_ptr = (window_datatype * )buf40;
  window_datatype * buf40d_ptr = (window_datatype * )buf40d;
  window_init(window_buf40_buf40d, 1, buf40, LOCK_5_2_0_0, buf40d, LOCK_5_2_1_0, 256, 256);
  window_internal window_buf38_buf38d[1];
  window_datatype * buf38_ptr = (window_datatype * )buf38;
  window_datatype * buf38d_ptr = (window_datatype * )buf38d;
  window_init(window_buf38_buf38d, 1, buf38, LOCK_5_1_2_4096, buf38d, LOCK_5_1_3_0, 256, 256);
  window_internal window_buf41_buf41d[1];
  window_datatype * buf41_ptr = (window_datatype * )buf41;
  window_datatype * buf41d_ptr = (window_datatype * )buf41d;
  window_init(window_buf41_buf41d, 1, buf41, LOCK_5_1_4_4096, buf41d, LOCK_5_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_1_bounds = sync_buffer[1];

  while (proc_5_1_bounds)
  {

    // Kernel call : i101:mm_kernel1
    window_acquire(window_buf39_buf39d,LOCK_5_0_2_4096,LOCK_5_0_3_4096,buf39_ptr,buf39d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf40_buf40d,LOCK_5_2_0_0,LOCK_5_2_1_0,buf40_ptr,buf40d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf38_buf38d,LOCK_5_1_2_4096,LOCK_5_1_3_0,buf38_ptr,buf38d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf41_buf41d,LOCK_5_1_4_4096,LOCK_5_1_5_0,buf41_ptr,buf41d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf39_buf39d),get_input_window_float(window_buf40_buf40d),get_input_window_float(window_buf38_buf38d),get_output_window_float(window_buf41_buf41d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf39_buf39d,LOCK_5_0_2_4096,LOCK_5_0_3_4096,buf39_ptr,buf39d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf40_buf40d,LOCK_5_2_0_0,LOCK_5_2_1_0,buf40_ptr,buf40d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf38_buf38d,LOCK_5_1_2_4096,LOCK_5_1_3_0,buf38_ptr,buf38d_ptr,0,index, REL_WRITE);
    window_release(window_buf41_buf41d,LOCK_5_1_4_4096,LOCK_5_1_5_0,buf41_ptr,buf41d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_1_bounds > 0)
      --proc_5_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}