// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_0/src/49_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_0_2_4096 18
#define LOCK_48_0_3_4096 19
#define LOCK_49_0_0_0 48
#define LOCK_49_0_1_0 49
#define LOCK_49_1_2_4096 34
#define LOCK_49_1_3_4096 35

// Declare shared memory buffers
v4float buf564[256];
v4float buf564d[256];
v4float buf565[256];
v4float buf565d[256];
v4float buf566[256];
v4float buf566d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf564_buf564d[1];
  window_datatype * buf564_ptr = (window_datatype * )buf564;
  window_datatype * buf564d_ptr = (window_datatype * )buf564d;
  window_init(window_buf564_buf564d, 1, buf564, LOCK_48_0_2_4096, buf564d, LOCK_48_0_3_4096, 256, 256);
  window_internal window_buf565_buf565d[1];
  window_datatype * buf565_ptr = (window_datatype * )buf565;
  window_datatype * buf565d_ptr = (window_datatype * )buf565d;
  window_init(window_buf565_buf565d, 1, buf565, LOCK_49_0_0_0, buf565d, LOCK_49_0_1_0, 256, 256);
  window_internal window_buf566_buf566d[1];
  window_datatype * buf566_ptr = (window_datatype * )buf566;
  window_datatype * buf566d_ptr = (window_datatype * )buf566d;
  window_init(window_buf566_buf566d, 1, buf566, LOCK_49_1_2_4096, buf566d, LOCK_49_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_0_bounds = sync_buffer[1];

  while (proc_49_0_bounds)
  {

    // Kernel call : i364:mm_kernel0
    window_acquire(window_buf564_buf564d,LOCK_48_0_2_4096,LOCK_48_0_3_4096,buf564_ptr,buf564d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf565_buf565d,LOCK_49_0_0_0,LOCK_49_0_1_0,buf565_ptr,buf565d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf566_buf566d,LOCK_49_1_2_4096,LOCK_49_1_3_4096,buf566_ptr,buf566d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf564_buf564d),get_input_window_float(window_buf565_buf565d),get_output_window_float(window_buf566_buf566d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf564_buf564d,LOCK_48_0_2_4096,LOCK_48_0_3_4096,buf564_ptr,buf564d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf565_buf565d,LOCK_49_0_0_0,LOCK_49_0_1_0,buf565_ptr,buf565d_ptr,0,index, REL_WRITE);
    window_release(window_buf566_buf566d,LOCK_49_1_2_4096,LOCK_49_1_3_4096,buf566_ptr,buf566d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_0_bounds > 0)
      --proc_49_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}