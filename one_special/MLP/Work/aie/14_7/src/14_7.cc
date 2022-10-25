// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_7/src/14_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_7_0_0 16
#define LOCK_14_7_1_0 17
#define LOCK_14_7_2_4096 18
#define LOCK_14_7_3_4096 19
#define LOCK_14_6_4_0 4
#define LOCK_14_6_5_4096 5
#define LOCK_14_6_6_0 6
#define LOCK_14_6_7_4096 7

// Declare shared memory buffers
v4float buf1004[256];
v4float buf1004d[256];
v4float buf1005[256];
v4float buf1005d[256];
v4float buf1006[256];
v4float buf1006d[256];
v4float buf1007[256];
v4float buf1007d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1005_buf1005d[1];
  window_datatype * buf1005_ptr = (window_datatype * )buf1005;
  window_datatype * buf1005d_ptr = (window_datatype * )buf1005d;
  window_init(window_buf1005_buf1005d, 1, buf1005, LOCK_14_7_0_0, buf1005d, LOCK_14_7_1_0, 256, 256);
  window_internal window_buf1006_buf1006d[1];
  window_datatype * buf1006_ptr = (window_datatype * )buf1006;
  window_datatype * buf1006d_ptr = (window_datatype * )buf1006d;
  window_init(window_buf1006_buf1006d, 1, buf1006, LOCK_14_7_2_4096, buf1006d, LOCK_14_7_3_4096, 256, 256);
  window_internal window_buf1004_buf1004d[1];
  window_datatype * buf1004_ptr = (window_datatype * )buf1004;
  window_datatype * buf1004d_ptr = (window_datatype * )buf1004d;
  window_init(window_buf1004_buf1004d, 1, buf1004, LOCK_14_6_4_0, buf1004d, LOCK_14_6_5_4096, 256, 256);
  window_internal window_buf1007_buf1007d[1];
  window_datatype * buf1007_ptr = (window_datatype * )buf1007;
  window_datatype * buf1007d_ptr = (window_datatype * )buf1007d;
  window_init(window_buf1007_buf1007d, 1, buf1007, LOCK_14_6_6_0, buf1007d, LOCK_14_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_7_bounds = sync_buffer[1];

  while (proc_14_7_bounds)
  {

    // Kernel call : i583:mm_kernel1
    window_acquire(window_buf1005_buf1005d,LOCK_14_7_0_0,LOCK_14_7_1_0,buf1005_ptr,buf1005d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1006_buf1006d,LOCK_14_7_2_4096,LOCK_14_7_3_4096,buf1006_ptr,buf1006d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1004_buf1004d,LOCK_14_6_4_0,LOCK_14_6_5_4096,buf1004_ptr,buf1004d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1007_buf1007d,LOCK_14_6_6_0,LOCK_14_6_7_4096,buf1007_ptr,buf1007d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1005_buf1005d),get_input_window_float(window_buf1006_buf1006d),get_input_window_float(window_buf1004_buf1004d),get_output_window_float(window_buf1007_buf1007d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1005_buf1005d,LOCK_14_7_0_0,LOCK_14_7_1_0,buf1005_ptr,buf1005d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1006_buf1006d,LOCK_14_7_2_4096,LOCK_14_7_3_4096,buf1006_ptr,buf1006d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1004_buf1004d,LOCK_14_6_4_0,LOCK_14_6_5_4096,buf1004_ptr,buf1004d_ptr,0,index, REL_WRITE);
    window_release(window_buf1007_buf1007d,LOCK_14_6_6_0,LOCK_14_6_7_4096,buf1007_ptr,buf1007d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_7_bounds > 0)
      --proc_14_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}