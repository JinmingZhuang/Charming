// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_5/src/5_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_4_0_4096 0
#define LOCK_5_4_1_0 1
#define LOCK_5_4_2_0 2
#define LOCK_5_4_3_4096 3
#define LOCK_5_5_2_4096 18
#define LOCK_5_5_3_0 19
#define LOCK_5_5_4_0 20
#define LOCK_5_5_5_0 21

// Declare shared memory buffers
v4float buf1106[256];
v4float buf1106d[256];
v4float buf1107[256];
v4float buf1107d[256];
v4float buf1108[256];
v4float buf1108d[256];
v4float buf1109[256];
v4float buf1109d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1107_buf1107d[1];
  window_datatype * buf1107_ptr = (window_datatype * )buf1107;
  window_datatype * buf1107d_ptr = (window_datatype * )buf1107d;
  window_init(window_buf1107_buf1107d, 1, buf1107, LOCK_5_4_0_4096, buf1107d, LOCK_5_4_1_0, 256, 256);
  window_internal window_buf1108_buf1108d[1];
  window_datatype * buf1108_ptr = (window_datatype * )buf1108;
  window_datatype * buf1108d_ptr = (window_datatype * )buf1108d;
  window_init(window_buf1108_buf1108d, 1, buf1108, LOCK_5_4_2_0, buf1108d, LOCK_5_4_3_4096, 256, 256);
  window_internal window_buf1106_buf1106d[1];
  window_datatype * buf1106_ptr = (window_datatype * )buf1106;
  window_datatype * buf1106d_ptr = (window_datatype * )buf1106d;
  window_init(window_buf1106_buf1106d, 1, buf1106, LOCK_5_5_2_4096, buf1106d, LOCK_5_5_3_0, 256, 256);
  window_internal window_buf1109_buf1109d[1];
  window_datatype * buf1109_ptr = (window_datatype * )buf1109;
  window_datatype * buf1109d_ptr = (window_datatype * )buf1109d;
  window_init(window_buf1109_buf1109d, 1, buf1109, LOCK_5_5_4_0, buf1109d, LOCK_5_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_5_bounds = sync_buffer[1];

  while (proc_5_5_bounds)
  {

    // Kernel call : i635:mm_kernel1
    window_acquire(window_buf1107_buf1107d,LOCK_5_4_0_4096,LOCK_5_4_1_0,buf1107_ptr,buf1107d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1108_buf1108d,LOCK_5_4_2_0,LOCK_5_4_3_4096,buf1108_ptr,buf1108d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1106_buf1106d,LOCK_5_5_2_4096,LOCK_5_5_3_0,buf1106_ptr,buf1106d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1109_buf1109d,LOCK_5_5_4_0,LOCK_5_5_5_0,buf1109_ptr,buf1109d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1107_buf1107d),get_input_window_float(window_buf1108_buf1108d),get_input_window_float(window_buf1106_buf1106d),get_output_window_float(window_buf1109_buf1109d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1107_buf1107d,LOCK_5_4_0_4096,LOCK_5_4_1_0,buf1107_ptr,buf1107d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1108_buf1108d,LOCK_5_4_2_0,LOCK_5_4_3_4096,buf1108_ptr,buf1108d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1106_buf1106d,LOCK_5_5_2_4096,LOCK_5_5_3_0,buf1106_ptr,buf1106d_ptr,0,index, REL_WRITE);
    window_release(window_buf1109_buf1109d,LOCK_5_5_4_0,LOCK_5_5_5_0,buf1109_ptr,buf1109d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_5_bounds > 0)
      --proc_5_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}