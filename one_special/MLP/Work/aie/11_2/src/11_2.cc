// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_2/src/11_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_3_2_4096 34
#define LOCK_11_3_3_4096 35
#define LOCK_10_2_2_4096 18
#define LOCK_10_2_3_4096 19
#define LOCK_11_1_6_0 6
#define LOCK_11_1_7_0 7
#define LOCK_11_2_0_0 48
#define LOCK_11_2_1_0 49

// Declare shared memory buffers
v4float buf113[256];
v4float buf113d[256];
v4float buf114[256];
v4float buf114d[256];
v4float buf115[256];
v4float buf115d[256];
v4float buf116[256];
v4float buf116d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf114_buf114d[1];
  window_datatype * buf114_ptr = (window_datatype * )buf114;
  window_datatype * buf114d_ptr = (window_datatype * )buf114d;
  window_init(window_buf114_buf114d, 1, buf114, LOCK_11_3_2_4096, buf114d, LOCK_11_3_3_4096, 256, 256);
  window_internal window_buf115_buf115d[1];
  window_datatype * buf115_ptr = (window_datatype * )buf115;
  window_datatype * buf115d_ptr = (window_datatype * )buf115d;
  window_init(window_buf115_buf115d, 1, buf115, LOCK_10_2_2_4096, buf115d, LOCK_10_2_3_4096, 256, 256);
  window_internal window_buf113_buf113d[1];
  window_datatype * buf113_ptr = (window_datatype * )buf113;
  window_datatype * buf113d_ptr = (window_datatype * )buf113d;
  window_init(window_buf113_buf113d, 1, buf113, LOCK_11_1_6_0, buf113d, LOCK_11_1_7_0, 256, 256);
  window_internal window_buf116_buf116d[1];
  window_datatype * buf116_ptr = (window_datatype * )buf116;
  window_datatype * buf116d_ptr = (window_datatype * )buf116d;
  window_init(window_buf116_buf116d, 1, buf116, LOCK_11_2_0_0, buf116d, LOCK_11_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_2_bounds = sync_buffer[1];

  while (proc_11_2_bounds)
  {

    // Kernel call : i138:mm_kernel1
    window_acquire(window_buf114_buf114d,LOCK_11_3_2_4096,LOCK_11_3_3_4096,buf114_ptr,buf114d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf115_buf115d,LOCK_10_2_2_4096,LOCK_10_2_3_4096,buf115_ptr,buf115d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf113_buf113d,LOCK_11_1_6_0,LOCK_11_1_7_0,buf113_ptr,buf113d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf116_buf116d,LOCK_11_2_0_0,LOCK_11_2_1_0,buf116_ptr,buf116d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf114_buf114d),get_input_window_float(window_buf115_buf115d),get_input_window_float(window_buf113_buf113d),get_output_window_float(window_buf116_buf116d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf114_buf114d,LOCK_11_3_2_4096,LOCK_11_3_3_4096,buf114_ptr,buf114d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf115_buf115d,LOCK_10_2_2_4096,LOCK_10_2_3_4096,buf115_ptr,buf115d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf113_buf113d,LOCK_11_1_6_0,LOCK_11_1_7_0,buf113_ptr,buf113d_ptr,0,index, REL_WRITE);
    window_release(window_buf116_buf116d,LOCK_11_2_0_0,LOCK_11_2_1_0,buf116_ptr,buf116d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_2_bounds > 0)
      --proc_11_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}