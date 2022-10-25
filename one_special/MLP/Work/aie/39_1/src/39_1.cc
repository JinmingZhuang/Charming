// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_1/src/39_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_0_2_4096 2
#define LOCK_39_0_3_4096 3
#define LOCK_39_2_0_0 32
#define LOCK_39_2_1_0 33
#define LOCK_39_1_2_4096 18
#define LOCK_39_1_3_0 19
#define LOCK_39_1_4_4096 20
#define LOCK_39_1_5_4096 21

// Declare shared memory buffers
v4float buf446[256];
v4float buf446d[256];
v4float buf447[256];
v4float buf447d[256];
v4float buf448[256];
v4float buf448d[256];
v4float buf449[256];
v4float buf449d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf447_buf447d[1];
  window_datatype * buf447_ptr = (window_datatype * )buf447;
  window_datatype * buf447d_ptr = (window_datatype * )buf447d;
  window_init(window_buf447_buf447d, 1, buf447, LOCK_39_0_2_4096, buf447d, LOCK_39_0_3_4096, 256, 256);
  window_internal window_buf448_buf448d[1];
  window_datatype * buf448_ptr = (window_datatype * )buf448;
  window_datatype * buf448d_ptr = (window_datatype * )buf448d;
  window_init(window_buf448_buf448d, 1, buf448, LOCK_39_2_0_0, buf448d, LOCK_39_2_1_0, 256, 256);
  window_internal window_buf446_buf446d[1];
  window_datatype * buf446_ptr = (window_datatype * )buf446;
  window_datatype * buf446d_ptr = (window_datatype * )buf446d;
  window_init(window_buf446_buf446d, 1, buf446, LOCK_39_1_2_4096, buf446d, LOCK_39_1_3_0, 256, 256);
  window_internal window_buf449_buf449d[1];
  window_datatype * buf449_ptr = (window_datatype * )buf449;
  window_datatype * buf449d_ptr = (window_datatype * )buf449d;
  window_init(window_buf449_buf449d, 1, buf449, LOCK_39_1_4_4096, buf449d, LOCK_39_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_1_bounds = sync_buffer[1];

  while (proc_39_1_bounds)
  {

    // Kernel call : i305:mm_kernel1
    window_acquire(window_buf447_buf447d,LOCK_39_0_2_4096,LOCK_39_0_3_4096,buf447_ptr,buf447d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf448_buf448d,LOCK_39_2_0_0,LOCK_39_2_1_0,buf448_ptr,buf448d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf446_buf446d,LOCK_39_1_2_4096,LOCK_39_1_3_0,buf446_ptr,buf446d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf449_buf449d,LOCK_39_1_4_4096,LOCK_39_1_5_4096,buf449_ptr,buf449d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf447_buf447d),get_input_window_float(window_buf448_buf448d),get_input_window_float(window_buf446_buf446d),get_output_window_float(window_buf449_buf449d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf447_buf447d,LOCK_39_0_2_4096,LOCK_39_0_3_4096,buf447_ptr,buf447d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf448_buf448d,LOCK_39_2_0_0,LOCK_39_2_1_0,buf448_ptr,buf448d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf446_buf446d,LOCK_39_1_2_4096,LOCK_39_1_3_0,buf446_ptr,buf446d_ptr,0,index, REL_WRITE);
    window_release(window_buf449_buf449d,LOCK_39_1_4_4096,LOCK_39_1_5_4096,buf449_ptr,buf449d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_1_bounds > 0)
      --proc_39_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}