// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_4/src/41_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_4_0_0 16
#define LOCK_40_4_1_0 17
#define LOCK_41_3_2_4096 2
#define LOCK_41_3_3_4096 3
#define LOCK_41_5_0_0 32
#define LOCK_41_5_1_4096 33

// Declare shared memory buffers
v4float buf672[256];
v4float buf672d[256];
v4float buf673[256];
v4float buf673d[256];
v4float buf674[256];
v4float buf674d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf672_buf672d[1];
  window_datatype * buf672_ptr = (window_datatype * )buf672;
  window_datatype * buf672d_ptr = (window_datatype * )buf672d;
  window_init(window_buf672_buf672d, 1, buf672, LOCK_40_4_0_0, buf672d, LOCK_40_4_1_0, 256, 256);
  window_internal window_buf673_buf673d[1];
  window_datatype * buf673_ptr = (window_datatype * )buf673;
  window_datatype * buf673d_ptr = (window_datatype * )buf673d;
  window_init(window_buf673_buf673d, 1, buf673, LOCK_41_3_2_4096, buf673d, LOCK_41_3_3_4096, 256, 256);
  window_internal window_buf674_buf674d[1];
  window_datatype * buf674_ptr = (window_datatype * )buf674;
  window_datatype * buf674d_ptr = (window_datatype * )buf674d;
  window_init(window_buf674_buf674d, 1, buf674, LOCK_41_5_0_0, buf674d, LOCK_41_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_4_bounds = sync_buffer[1];

  while (proc_41_4_bounds)
  {

    // Kernel call : i418:mm_kernel0
    window_acquire(window_buf672_buf672d,LOCK_40_4_0_0,LOCK_40_4_1_0,buf672_ptr,buf672d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf673_buf673d,LOCK_41_3_2_4096,LOCK_41_3_3_4096,buf673_ptr,buf673d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf674_buf674d,LOCK_41_5_0_0,LOCK_41_5_1_4096,buf674_ptr,buf674d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf672_buf672d),get_input_window_float(window_buf673_buf673d),get_output_window_float(window_buf674_buf674d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf672_buf672d,LOCK_40_4_0_0,LOCK_40_4_1_0,buf672_ptr,buf672d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf673_buf673d,LOCK_41_3_2_4096,LOCK_41_3_3_4096,buf673_ptr,buf673d_ptr,0,index, REL_WRITE);
    window_release(window_buf674_buf674d,LOCK_41_5_0_0,LOCK_41_5_1_4096,buf674_ptr,buf674d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_4_bounds > 0)
      --proc_41_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}