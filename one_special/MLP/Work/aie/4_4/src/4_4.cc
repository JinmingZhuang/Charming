// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_4/src/4_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_4_0_0 16
#define LOCK_3_4_1_0 17
#define LOCK_4_5_0_4096 32
#define LOCK_4_5_1_0 33
#define LOCK_4_5_2_4096 34
#define LOCK_4_5_3_0 35

// Declare shared memory buffers
v4float buf1116[256];
v4float buf1116d[256];
v4float buf1117[256];
v4float buf1117d[256];
v4float buf1118[256];
v4float buf1118d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1116_buf1116d[1];
  window_datatype * buf1116_ptr = (window_datatype * )buf1116;
  window_datatype * buf1116d_ptr = (window_datatype * )buf1116d;
  window_init(window_buf1116_buf1116d, 1, buf1116, LOCK_3_4_0_0, buf1116d, LOCK_3_4_1_0, 256, 256);
  window_internal window_buf1117_buf1117d[1];
  window_datatype * buf1117_ptr = (window_datatype * )buf1117;
  window_datatype * buf1117d_ptr = (window_datatype * )buf1117d;
  window_init(window_buf1117_buf1117d, 1, buf1117, LOCK_4_5_0_4096, buf1117d, LOCK_4_5_1_0, 256, 256);
  window_internal window_buf1118_buf1118d[1];
  window_datatype * buf1118_ptr = (window_datatype * )buf1118;
  window_datatype * buf1118d_ptr = (window_datatype * )buf1118d;
  window_init(window_buf1118_buf1118d, 1, buf1118, LOCK_4_5_2_4096, buf1118d, LOCK_4_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_4_bounds = sync_buffer[1];

  while (proc_4_4_bounds)
  {

    // Kernel call : i640:mm_kernel0
    window_acquire(window_buf1116_buf1116d,LOCK_3_4_0_0,LOCK_3_4_1_0,buf1116_ptr,buf1116d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1117_buf1117d,LOCK_4_5_0_4096,LOCK_4_5_1_0,buf1117_ptr,buf1117d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1118_buf1118d,LOCK_4_5_2_4096,LOCK_4_5_3_0,buf1118_ptr,buf1118d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1116_buf1116d),get_input_window_float(window_buf1117_buf1117d),get_output_window_float(window_buf1118_buf1118d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1116_buf1116d,LOCK_3_4_0_0,LOCK_3_4_1_0,buf1116_ptr,buf1116d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1117_buf1117d,LOCK_4_5_0_4096,LOCK_4_5_1_0,buf1117_ptr,buf1117d_ptr,0,index, REL_WRITE);
    window_release(window_buf1118_buf1118d,LOCK_4_5_2_4096,LOCK_4_5_3_0,buf1118_ptr,buf1118d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_4_bounds > 0)
      --proc_4_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}