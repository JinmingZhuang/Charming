// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_0/src/28_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_1_0_4096 32
#define LOCK_28_1_1_4096 33
#define LOCK_28_0_0_0 48
#define LOCK_28_0_1_0 49
#define LOCK_28_1_2_4096 34
#define LOCK_28_1_3_4096 35

// Declare shared memory buffers
v4float buf312[256];
v4float buf312d[256];
v4float buf313[256];
v4float buf313d[256];
v4float buf314[256];
v4float buf314d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf312_buf312d[1];
  window_datatype * buf312_ptr = (window_datatype * )buf312;
  window_datatype * buf312d_ptr = (window_datatype * )buf312d;
  window_init(window_buf312_buf312d, 1, buf312, LOCK_28_1_0_4096, buf312d, LOCK_28_1_1_4096, 256, 256);
  window_internal window_buf313_buf313d[1];
  window_datatype * buf313_ptr = (window_datatype * )buf313;
  window_datatype * buf313d_ptr = (window_datatype * )buf313d;
  window_init(window_buf313_buf313d, 1, buf313, LOCK_28_0_0_0, buf313d, LOCK_28_0_1_0, 256, 256);
  window_internal window_buf314_buf314d[1];
  window_datatype * buf314_ptr = (window_datatype * )buf314;
  window_datatype * buf314d_ptr = (window_datatype * )buf314d;
  window_init(window_buf314_buf314d, 1, buf314, LOCK_28_1_2_4096, buf314d, LOCK_28_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_0_bounds = sync_buffer[1];

  while (proc_28_0_bounds)
  {

    // Kernel call : i238:mm_kernel0
    window_acquire(window_buf312_buf312d,LOCK_28_1_0_4096,LOCK_28_1_1_4096,buf312_ptr,buf312d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf313_buf313d,LOCK_28_0_0_0,LOCK_28_0_1_0,buf313_ptr,buf313d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf314_buf314d,LOCK_28_1_2_4096,LOCK_28_1_3_4096,buf314_ptr,buf314d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf312_buf312d),get_input_window_float(window_buf313_buf313d),get_output_window_float(window_buf314_buf314d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf312_buf312d,LOCK_28_1_0_4096,LOCK_28_1_1_4096,buf312_ptr,buf312d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf313_buf313d,LOCK_28_0_0_0,LOCK_28_0_1_0,buf313_ptr,buf313d_ptr,0,index, REL_WRITE);
    window_release(window_buf314_buf314d,LOCK_28_1_2_4096,LOCK_28_1_3_4096,buf314_ptr,buf314d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_0_bounds > 0)
      --proc_28_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}