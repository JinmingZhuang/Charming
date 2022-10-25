// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_0/src/15_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_0_0_0 48
#define LOCK_15_0_1_0 49
#define LOCK_15_0_2_4096 50
#define LOCK_15_0_3_4096 51
#define LOCK_15_1_0_0 32
#define LOCK_15_1_1_0 33

// Declare shared memory buffers
v4float buf156[256];
v4float buf156d[256];
v4float buf157[256];
v4float buf157d[256];
v4float buf158[256];
v4float buf158d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf156_buf156d[1];
  window_datatype * buf156_ptr = (window_datatype * )buf156;
  window_datatype * buf156d_ptr = (window_datatype * )buf156d;
  window_init(window_buf156_buf156d, 1, buf156, LOCK_15_0_0_0, buf156d, LOCK_15_0_1_0, 256, 256);
  window_internal window_buf157_buf157d[1];
  window_datatype * buf157_ptr = (window_datatype * )buf157;
  window_datatype * buf157d_ptr = (window_datatype * )buf157d;
  window_init(window_buf157_buf157d, 1, buf157, LOCK_15_0_2_4096, buf157d, LOCK_15_0_3_4096, 256, 256);
  window_internal window_buf158_buf158d[1];
  window_datatype * buf158_ptr = (window_datatype * )buf158;
  window_datatype * buf158d_ptr = (window_datatype * )buf158d;
  window_init(window_buf158_buf158d, 1, buf158, LOCK_15_1_0_0, buf158d, LOCK_15_1_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_0_bounds = sync_buffer[1];

  while (proc_15_0_bounds)
  {

    // Kernel call : i160:mm_kernel0
    window_acquire(window_buf156_buf156d,LOCK_15_0_0_0,LOCK_15_0_1_0,buf156_ptr,buf156d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf157_buf157d,LOCK_15_0_2_4096,LOCK_15_0_3_4096,buf157_ptr,buf157d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf158_buf158d,LOCK_15_1_0_0,LOCK_15_1_1_0,buf158_ptr,buf158d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf156_buf156d),get_input_window_float(window_buf157_buf157d),get_output_window_float(window_buf158_buf158d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf156_buf156d,LOCK_15_0_0_0,LOCK_15_0_1_0,buf156_ptr,buf156d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf157_buf157d,LOCK_15_0_2_4096,LOCK_15_0_3_4096,buf157_ptr,buf157d_ptr,0,index, REL_WRITE);
    window_release(window_buf158_buf158d,LOCK_15_1_0_0,LOCK_15_1_1_0,buf158_ptr,buf158d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_0_bounds > 0)
      --proc_15_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}