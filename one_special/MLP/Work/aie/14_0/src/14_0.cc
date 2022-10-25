// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_0/src/14_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_0_0_0 48
#define LOCK_14_0_1_0 49
#define LOCK_13_0_2_4096 18
#define LOCK_13_0_3_4096 19
#define LOCK_14_1_2_4096 34
#define LOCK_14_1_3_4096 35

// Declare shared memory buffers
v4float buf144[256];
v4float buf144d[256];
v4float buf145[256];
v4float buf145d[256];
v4float buf146[256];
v4float buf146d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf144_buf144d[1];
  window_datatype * buf144_ptr = (window_datatype * )buf144;
  window_datatype * buf144d_ptr = (window_datatype * )buf144d;
  window_init(window_buf144_buf144d, 1, buf144, LOCK_14_0_0_0, buf144d, LOCK_14_0_1_0, 256, 256);
  window_internal window_buf145_buf145d[1];
  window_datatype * buf145_ptr = (window_datatype * )buf145;
  window_datatype * buf145d_ptr = (window_datatype * )buf145d;
  window_init(window_buf145_buf145d, 1, buf145, LOCK_13_0_2_4096, buf145d, LOCK_13_0_3_4096, 256, 256);
  window_internal window_buf146_buf146d[1];
  window_datatype * buf146_ptr = (window_datatype * )buf146;
  window_datatype * buf146d_ptr = (window_datatype * )buf146d;
  window_init(window_buf146_buf146d, 1, buf146, LOCK_14_1_2_4096, buf146d, LOCK_14_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_0_bounds = sync_buffer[1];

  while (proc_14_0_bounds)
  {

    // Kernel call : i154:mm_kernel0
    window_acquire(window_buf144_buf144d,LOCK_14_0_0_0,LOCK_14_0_1_0,buf144_ptr,buf144d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf145_buf145d,LOCK_13_0_2_4096,LOCK_13_0_3_4096,buf145_ptr,buf145d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf146_buf146d,LOCK_14_1_2_4096,LOCK_14_1_3_4096,buf146_ptr,buf146d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf144_buf144d),get_input_window_float(window_buf145_buf145d),get_output_window_float(window_buf146_buf146d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf144_buf144d,LOCK_14_0_0_0,LOCK_14_0_1_0,buf144_ptr,buf144d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf145_buf145d,LOCK_13_0_2_4096,LOCK_13_0_3_4096,buf145_ptr,buf145d_ptr,0,index, REL_WRITE);
    window_release(window_buf146_buf146d,LOCK_14_1_2_4096,LOCK_14_1_3_4096,buf146_ptr,buf146d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_0_bounds > 0)
      --proc_14_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}