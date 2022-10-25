// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_0/src/23_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_1_0_0 32
#define LOCK_23_1_1_0 33
#define LOCK_23_0_0_0 48
#define LOCK_23_0_1_0 49
#define LOCK_23_1_2_4096 34
#define LOCK_23_1_3_0 35

// Declare shared memory buffers
v4float buf252[256];
v4float buf252d[256];
v4float buf253[256];
v4float buf253d[256];
v4float buf254[256];
v4float buf254d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf252_buf252d[1];
  window_datatype * buf252_ptr = (window_datatype * )buf252;
  window_datatype * buf252d_ptr = (window_datatype * )buf252d;
  window_init(window_buf252_buf252d, 1, buf252, LOCK_23_1_0_0, buf252d, LOCK_23_1_1_0, 256, 256);
  window_internal window_buf253_buf253d[1];
  window_datatype * buf253_ptr = (window_datatype * )buf253;
  window_datatype * buf253d_ptr = (window_datatype * )buf253d;
  window_init(window_buf253_buf253d, 1, buf253, LOCK_23_0_0_0, buf253d, LOCK_23_0_1_0, 256, 256);
  window_internal window_buf254_buf254d[1];
  window_datatype * buf254_ptr = (window_datatype * )buf254;
  window_datatype * buf254d_ptr = (window_datatype * )buf254d;
  window_init(window_buf254_buf254d, 1, buf254, LOCK_23_1_2_4096, buf254d, LOCK_23_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_0_bounds = sync_buffer[1];

  while (proc_23_0_bounds)
  {

    // Kernel call : i208:mm_kernel0
    window_acquire(window_buf252_buf252d,LOCK_23_1_0_0,LOCK_23_1_1_0,buf252_ptr,buf252d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf253_buf253d,LOCK_23_0_0_0,LOCK_23_0_1_0,buf253_ptr,buf253d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf254_buf254d,LOCK_23_1_2_4096,LOCK_23_1_3_0,buf254_ptr,buf254d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf252_buf252d),get_input_window_float(window_buf253_buf253d),get_output_window_float(window_buf254_buf254d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf252_buf252d,LOCK_23_1_0_0,LOCK_23_1_1_0,buf252_ptr,buf252d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf253_buf253d,LOCK_23_0_0_0,LOCK_23_0_1_0,buf253_ptr,buf253d_ptr,0,index, REL_WRITE);
    window_release(window_buf254_buf254d,LOCK_23_1_2_4096,LOCK_23_1_3_0,buf254_ptr,buf254d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_0_bounds > 0)
      --proc_23_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}