// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_4/src/38_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_3_4_4096 4
#define LOCK_38_3_5_0 5
#define LOCK_38_3_6_0 6
#define LOCK_38_3_7_4096 7
#define LOCK_38_5_0_4096 32
#define LOCK_38_5_1_0 33

// Declare shared memory buffers
v4float buf708[256];
v4float buf708d[256];
v4float buf709[256];
v4float buf709d[256];
v4float buf710[256];
v4float buf710d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf708_buf708d[1];
  window_datatype * buf708_ptr = (window_datatype * )buf708;
  window_datatype * buf708d_ptr = (window_datatype * )buf708d;
  window_init(window_buf708_buf708d, 1, buf708, LOCK_38_3_4_4096, buf708d, LOCK_38_3_5_0, 256, 256);
  window_internal window_buf709_buf709d[1];
  window_datatype * buf709_ptr = (window_datatype * )buf709;
  window_datatype * buf709d_ptr = (window_datatype * )buf709d;
  window_init(window_buf709_buf709d, 1, buf709, LOCK_38_3_6_0, buf709d, LOCK_38_3_7_4096, 256, 256);
  window_internal window_buf710_buf710d[1];
  window_datatype * buf710_ptr = (window_datatype * )buf710;
  window_datatype * buf710d_ptr = (window_datatype * )buf710d;
  window_init(window_buf710_buf710d, 1, buf710, LOCK_38_5_0_4096, buf710d, LOCK_38_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_4_bounds = sync_buffer[1];

  while (proc_38_4_bounds)
  {

    // Kernel call : i436:mm_kernel0
    window_acquire(window_buf708_buf708d,LOCK_38_3_4_4096,LOCK_38_3_5_0,buf708_ptr,buf708d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf709_buf709d,LOCK_38_3_6_0,LOCK_38_3_7_4096,buf709_ptr,buf709d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf710_buf710d,LOCK_38_5_0_4096,LOCK_38_5_1_0,buf710_ptr,buf710d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf708_buf708d),get_input_window_float(window_buf709_buf709d),get_output_window_float(window_buf710_buf710d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf708_buf708d,LOCK_38_3_4_4096,LOCK_38_3_5_0,buf708_ptr,buf708d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf709_buf709d,LOCK_38_3_6_0,LOCK_38_3_7_4096,buf709_ptr,buf709d_ptr,0,index, REL_WRITE);
    window_release(window_buf710_buf710d,LOCK_38_5_0_4096,LOCK_38_5_1_0,buf710_ptr,buf710d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_4_bounds > 0)
      --proc_38_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}