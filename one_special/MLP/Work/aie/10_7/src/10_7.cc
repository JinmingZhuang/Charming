// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_7/src/10_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_7_2_4096 18
#define LOCK_10_7_3_0 19
#define LOCK_10_7_4_0 20
#define LOCK_10_7_5_0 21
#define LOCK_10_7_0_0 16
#define LOCK_10_7_1_4096 17
#define LOCK_10_7_6_4096 22
#define LOCK_10_7_7_4096 23

// Declare shared memory buffers
v4float buf1052[256];
v4float buf1052d[256];
v4float buf1053[256];
v4float buf1053d[256];
v4float buf1054[256];
v4float buf1054d[256];
v4float buf1055[256];
v4float buf1055d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1053_buf1053d[1];
  window_datatype * buf1053_ptr = (window_datatype * )buf1053;
  window_datatype * buf1053d_ptr = (window_datatype * )buf1053d;
  window_init(window_buf1053_buf1053d, 1, buf1053, LOCK_10_7_2_4096, buf1053d, LOCK_10_7_3_0, 256, 256);
  window_internal window_buf1054_buf1054d[1];
  window_datatype * buf1054_ptr = (window_datatype * )buf1054;
  window_datatype * buf1054d_ptr = (window_datatype * )buf1054d;
  window_init(window_buf1054_buf1054d, 1, buf1054, LOCK_10_7_4_0, buf1054d, LOCK_10_7_5_0, 256, 256);
  window_internal window_buf1052_buf1052d[1];
  window_datatype * buf1052_ptr = (window_datatype * )buf1052;
  window_datatype * buf1052d_ptr = (window_datatype * )buf1052d;
  window_init(window_buf1052_buf1052d, 1, buf1052, LOCK_10_7_0_0, buf1052d, LOCK_10_7_1_4096, 256, 256);
  window_internal window_buf1055_buf1055d[1];
  window_datatype * buf1055_ptr = (window_datatype * )buf1055;
  window_datatype * buf1055d_ptr = (window_datatype * )buf1055d;
  window_init(window_buf1055_buf1055d, 1, buf1055, LOCK_10_7_6_4096, buf1055d, LOCK_10_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_7_bounds = sync_buffer[1];

  while (proc_10_7_bounds)
  {

    // Kernel call : i607:mm_kernel1
    window_acquire(window_buf1053_buf1053d,LOCK_10_7_2_4096,LOCK_10_7_3_0,buf1053_ptr,buf1053d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1054_buf1054d,LOCK_10_7_4_0,LOCK_10_7_5_0,buf1054_ptr,buf1054d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1052_buf1052d,LOCK_10_7_0_0,LOCK_10_7_1_4096,buf1052_ptr,buf1052d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1055_buf1055d,LOCK_10_7_6_4096,LOCK_10_7_7_4096,buf1055_ptr,buf1055d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1053_buf1053d),get_input_window_float(window_buf1054_buf1054d),get_input_window_float(window_buf1052_buf1052d),get_output_window_float(window_buf1055_buf1055d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1053_buf1053d,LOCK_10_7_2_4096,LOCK_10_7_3_0,buf1053_ptr,buf1053d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1054_buf1054d,LOCK_10_7_4_0,LOCK_10_7_5_0,buf1054_ptr,buf1054d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1052_buf1052d,LOCK_10_7_0_0,LOCK_10_7_1_4096,buf1052_ptr,buf1052d_ptr,0,index, REL_WRITE);
    window_release(window_buf1055_buf1055d,LOCK_10_7_6_4096,LOCK_10_7_7_4096,buf1055_ptr,buf1055d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_7_bounds > 0)
      --proc_10_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}