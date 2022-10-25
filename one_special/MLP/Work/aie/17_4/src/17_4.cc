// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_4/src/17_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_5_0_4096 32
#define LOCK_17_5_1_0 33
#define LOCK_16_4_2_4096 18
#define LOCK_16_4_3_4096 19
#define LOCK_17_5_2_0 34
#define LOCK_17_5_3_4096 35

// Declare shared memory buffers
v4float buf960[256];
v4float buf960d[256];
v4float buf961[256];
v4float buf961d[256];
v4float buf962[256];
v4float buf962d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf960_buf960d[1];
  window_datatype * buf960_ptr = (window_datatype * )buf960;
  window_datatype * buf960d_ptr = (window_datatype * )buf960d;
  window_init(window_buf960_buf960d, 1, buf960, LOCK_17_5_0_4096, buf960d, LOCK_17_5_1_0, 256, 256);
  window_internal window_buf961_buf961d[1];
  window_datatype * buf961_ptr = (window_datatype * )buf961;
  window_datatype * buf961d_ptr = (window_datatype * )buf961d;
  window_init(window_buf961_buf961d, 1, buf961, LOCK_16_4_2_4096, buf961d, LOCK_16_4_3_4096, 256, 256);
  window_internal window_buf962_buf962d[1];
  window_datatype * buf962_ptr = (window_datatype * )buf962;
  window_datatype * buf962d_ptr = (window_datatype * )buf962d;
  window_init(window_buf962_buf962d, 1, buf962, LOCK_17_5_2_0, buf962d, LOCK_17_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_4_bounds = sync_buffer[1];

  while (proc_17_4_bounds)
  {

    // Kernel call : i562:mm_kernel0
    window_acquire(window_buf960_buf960d,LOCK_17_5_0_4096,LOCK_17_5_1_0,buf960_ptr,buf960d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf961_buf961d,LOCK_16_4_2_4096,LOCK_16_4_3_4096,buf961_ptr,buf961d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf962_buf962d,LOCK_17_5_2_0,LOCK_17_5_3_4096,buf962_ptr,buf962d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf960_buf960d),get_input_window_float(window_buf961_buf961d),get_output_window_float(window_buf962_buf962d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf960_buf960d,LOCK_17_5_0_4096,LOCK_17_5_1_0,buf960_ptr,buf960d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf961_buf961d,LOCK_16_4_2_4096,LOCK_16_4_3_4096,buf961_ptr,buf961d_ptr,0,index, REL_WRITE);
    window_release(window_buf962_buf962d,LOCK_17_5_2_0,LOCK_17_5_3_4096,buf962_ptr,buf962d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_4_bounds > 0)
      --proc_17_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}