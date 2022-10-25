// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_3/src/4_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_2_2_4096 2
#define LOCK_4_2_3_4096 3
#define LOCK_4_2_4_0 4
#define LOCK_4_2_5_0 5
#define LOCK_4_2_0_0 0
#define LOCK_4_2_1_0 1
#define LOCK_4_2_6_4096 6
#define LOCK_4_2_7_4096 7

// Declare shared memory buffers
v4float buf32[256];
v4float buf32d[256];
v4float buf33[256];
v4float buf33d[256];
v4float buf34[256];
v4float buf34d[256];
v4float buf35[256];
v4float buf35d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf33_buf33d[1];
  window_datatype * buf33_ptr = (window_datatype * )buf33;
  window_datatype * buf33d_ptr = (window_datatype * )buf33d;
  window_init(window_buf33_buf33d, 1, buf33, LOCK_4_2_2_4096, buf33d, LOCK_4_2_3_4096, 256, 256);
  window_internal window_buf34_buf34d[1];
  window_datatype * buf34_ptr = (window_datatype * )buf34;
  window_datatype * buf34d_ptr = (window_datatype * )buf34d;
  window_init(window_buf34_buf34d, 1, buf34, LOCK_4_2_4_0, buf34d, LOCK_4_2_5_0, 256, 256);
  window_internal window_buf32_buf32d[1];
  window_datatype * buf32_ptr = (window_datatype * )buf32;
  window_datatype * buf32d_ptr = (window_datatype * )buf32d;
  window_init(window_buf32_buf32d, 1, buf32, LOCK_4_2_0_0, buf32d, LOCK_4_2_1_0, 256, 256);
  window_internal window_buf35_buf35d[1];
  window_datatype * buf35_ptr = (window_datatype * )buf35;
  window_datatype * buf35d_ptr = (window_datatype * )buf35d;
  window_init(window_buf35_buf35d, 1, buf35, LOCK_4_2_6_4096, buf35d, LOCK_4_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_3_bounds = sync_buffer[1];

  while (proc_4_3_bounds)
  {

    // Kernel call : i97:mm_kernel1
    window_acquire(window_buf33_buf33d,LOCK_4_2_2_4096,LOCK_4_2_3_4096,buf33_ptr,buf33d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf34_buf34d,LOCK_4_2_4_0,LOCK_4_2_5_0,buf34_ptr,buf34d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf32_buf32d,LOCK_4_2_0_0,LOCK_4_2_1_0,buf32_ptr,buf32d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf35_buf35d,LOCK_4_2_6_4096,LOCK_4_2_7_4096,buf35_ptr,buf35d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf33_buf33d),get_input_window_float(window_buf34_buf34d),get_input_window_float(window_buf32_buf32d),get_output_window_float(window_buf35_buf35d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf33_buf33d,LOCK_4_2_2_4096,LOCK_4_2_3_4096,buf33_ptr,buf33d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf34_buf34d,LOCK_4_2_4_0,LOCK_4_2_5_0,buf34_ptr,buf34d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf32_buf32d,LOCK_4_2_0_0,LOCK_4_2_1_0,buf32_ptr,buf32d_ptr,0,index, REL_WRITE);
    window_release(window_buf35_buf35d,LOCK_4_2_6_4096,LOCK_4_2_7_4096,buf35_ptr,buf35d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_3_bounds > 0)
      --proc_4_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}