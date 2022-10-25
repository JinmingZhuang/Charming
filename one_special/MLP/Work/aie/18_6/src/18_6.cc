// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_6/src/18_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_7_0_4096 32
#define LOCK_18_7_1_0 33
#define LOCK_18_5_6_4096 6
#define LOCK_18_5_7_4096 7
#define LOCK_18_5_4_4096 4
#define LOCK_18_5_5_4096 5
#define LOCK_18_7_2_4096 34
#define LOCK_18_7_3_4096 35

// Declare shared memory buffers
v4float buf953[256];
v4float buf953d[256];
v4float buf954[256];
v4float buf954d[256];
v4float buf955[256];
v4float buf955d[256];
v4float buf956[256];
v4float buf956d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf954_buf954d[1];
  window_datatype * buf954_ptr = (window_datatype * )buf954;
  window_datatype * buf954d_ptr = (window_datatype * )buf954d;
  window_init(window_buf954_buf954d, 1, buf954, LOCK_18_7_0_4096, buf954d, LOCK_18_7_1_0, 256, 256);
  window_internal window_buf955_buf955d[1];
  window_datatype * buf955_ptr = (window_datatype * )buf955;
  window_datatype * buf955d_ptr = (window_datatype * )buf955d;
  window_init(window_buf955_buf955d, 1, buf955, LOCK_18_5_6_4096, buf955d, LOCK_18_5_7_4096, 256, 256);
  window_internal window_buf953_buf953d[1];
  window_datatype * buf953_ptr = (window_datatype * )buf953;
  window_datatype * buf953d_ptr = (window_datatype * )buf953d;
  window_init(window_buf953_buf953d, 1, buf953, LOCK_18_5_4_4096, buf953d, LOCK_18_5_5_4096, 256, 256);
  window_internal window_buf956_buf956d[1];
  window_datatype * buf956_ptr = (window_datatype * )buf956;
  window_datatype * buf956d_ptr = (window_datatype * )buf956d;
  window_init(window_buf956_buf956d, 1, buf956, LOCK_18_7_2_4096, buf956d, LOCK_18_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_6_bounds = sync_buffer[1];

  while (proc_18_6_bounds)
  {

    // Kernel call : i558:mm_kernel1
    window_acquire(window_buf954_buf954d,LOCK_18_7_0_4096,LOCK_18_7_1_0,buf954_ptr,buf954d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf955_buf955d,LOCK_18_5_6_4096,LOCK_18_5_7_4096,buf955_ptr,buf955d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf953_buf953d,LOCK_18_5_4_4096,LOCK_18_5_5_4096,buf953_ptr,buf953d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf956_buf956d,LOCK_18_7_2_4096,LOCK_18_7_3_4096,buf956_ptr,buf956d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf954_buf954d),get_input_window_float(window_buf955_buf955d),get_input_window_float(window_buf953_buf953d),get_output_window_float(window_buf956_buf956d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf954_buf954d,LOCK_18_7_0_4096,LOCK_18_7_1_0,buf954_ptr,buf954d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf955_buf955d,LOCK_18_5_6_4096,LOCK_18_5_7_4096,buf955_ptr,buf955d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf953_buf953d,LOCK_18_5_4_4096,LOCK_18_5_5_4096,buf953_ptr,buf953d_ptr,0,index, REL_WRITE);
    window_release(window_buf956_buf956d,LOCK_18_7_2_4096,LOCK_18_7_3_4096,buf956_ptr,buf956d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_6_bounds > 0)
      --proc_18_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}