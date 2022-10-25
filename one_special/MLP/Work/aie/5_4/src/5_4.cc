// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_4/src/5_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_4_0_0 16
#define LOCK_4_4_1_0 17
#define LOCK_5_5_0_4096 32
#define LOCK_5_5_1_4096 33
#define LOCK_5_5_2_4096 34
#define LOCK_5_5_3_0 35

// Declare shared memory buffers
v4float buf1104[256];
v4float buf1104d[256];
v4float buf1105[256];
v4float buf1105d[256];
v4float buf1106[256];
v4float buf1106d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1104_buf1104d[1];
  window_datatype * buf1104_ptr = (window_datatype * )buf1104;
  window_datatype * buf1104d_ptr = (window_datatype * )buf1104d;
  window_init(window_buf1104_buf1104d, 1, buf1104, LOCK_4_4_0_0, buf1104d, LOCK_4_4_1_0, 256, 256);
  window_internal window_buf1105_buf1105d[1];
  window_datatype * buf1105_ptr = (window_datatype * )buf1105;
  window_datatype * buf1105d_ptr = (window_datatype * )buf1105d;
  window_init(window_buf1105_buf1105d, 1, buf1105, LOCK_5_5_0_4096, buf1105d, LOCK_5_5_1_4096, 256, 256);
  window_internal window_buf1106_buf1106d[1];
  window_datatype * buf1106_ptr = (window_datatype * )buf1106;
  window_datatype * buf1106d_ptr = (window_datatype * )buf1106d;
  window_init(window_buf1106_buf1106d, 1, buf1106, LOCK_5_5_2_4096, buf1106d, LOCK_5_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_4_bounds = sync_buffer[1];

  while (proc_5_4_bounds)
  {

    // Kernel call : i634:mm_kernel0
    window_acquire(window_buf1104_buf1104d,LOCK_4_4_0_0,LOCK_4_4_1_0,buf1104_ptr,buf1104d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1105_buf1105d,LOCK_5_5_0_4096,LOCK_5_5_1_4096,buf1105_ptr,buf1105d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1106_buf1106d,LOCK_5_5_2_4096,LOCK_5_5_3_0,buf1106_ptr,buf1106d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1104_buf1104d),get_input_window_float(window_buf1105_buf1105d),get_output_window_float(window_buf1106_buf1106d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1104_buf1104d,LOCK_4_4_0_0,LOCK_4_4_1_0,buf1104_ptr,buf1104d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1105_buf1105d,LOCK_5_5_0_4096,LOCK_5_5_1_4096,buf1105_ptr,buf1105d_ptr,0,index, REL_WRITE);
    window_release(window_buf1106_buf1106d,LOCK_5_5_2_4096,LOCK_5_5_3_0,buf1106_ptr,buf1106d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_4_bounds > 0)
      --proc_5_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}