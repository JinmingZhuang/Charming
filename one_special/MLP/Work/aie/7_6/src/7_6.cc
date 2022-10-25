// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_6/src/7_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_7_7_0_4096 32
#define LOCK_7_7_1_0 33
#define LOCK_7_6_0_0 48
#define LOCK_7_6_1_0 49
#define LOCK_7_5_6_0 6
#define LOCK_7_5_7_4096 7
#define LOCK_7_7_2_4096 34
#define LOCK_7_7_3_0 35

// Declare shared memory buffers
v4float buf1085[256];
v4float buf1085d[256];
v4float buf1086[256];
v4float buf1086d[256];
v4float buf1087[256];
v4float buf1087d[256];
v4float buf1088[256];
v4float buf1088d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1086_buf1086d[1];
  window_datatype * buf1086_ptr = (window_datatype * )buf1086;
  window_datatype * buf1086d_ptr = (window_datatype * )buf1086d;
  window_init(window_buf1086_buf1086d, 1, buf1086, LOCK_7_7_0_4096, buf1086d, LOCK_7_7_1_0, 256, 256);
  window_internal window_buf1087_buf1087d[1];
  window_datatype * buf1087_ptr = (window_datatype * )buf1087;
  window_datatype * buf1087d_ptr = (window_datatype * )buf1087d;
  window_init(window_buf1087_buf1087d, 1, buf1087, LOCK_7_6_0_0, buf1087d, LOCK_7_6_1_0, 256, 256);
  window_internal window_buf1085_buf1085d[1];
  window_datatype * buf1085_ptr = (window_datatype * )buf1085;
  window_datatype * buf1085d_ptr = (window_datatype * )buf1085d;
  window_init(window_buf1085_buf1085d, 1, buf1085, LOCK_7_5_6_0, buf1085d, LOCK_7_5_7_4096, 256, 256);
  window_internal window_buf1088_buf1088d[1];
  window_datatype * buf1088_ptr = (window_datatype * )buf1088;
  window_datatype * buf1088d_ptr = (window_datatype * )buf1088d;
  window_init(window_buf1088_buf1088d, 1, buf1088, LOCK_7_7_2_4096, buf1088d, LOCK_7_7_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_6_bounds = sync_buffer[1];

  while (proc_7_6_bounds)
  {

    // Kernel call : i624:mm_kernel1
    window_acquire(window_buf1086_buf1086d,LOCK_7_7_0_4096,LOCK_7_7_1_0,buf1086_ptr,buf1086d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1087_buf1087d,LOCK_7_6_0_0,LOCK_7_6_1_0,buf1087_ptr,buf1087d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1085_buf1085d,LOCK_7_5_6_0,LOCK_7_5_7_4096,buf1085_ptr,buf1085d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1088_buf1088d,LOCK_7_7_2_4096,LOCK_7_7_3_0,buf1088_ptr,buf1088d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1086_buf1086d),get_input_window_float(window_buf1087_buf1087d),get_input_window_float(window_buf1085_buf1085d),get_output_window_float(window_buf1088_buf1088d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1086_buf1086d,LOCK_7_7_0_4096,LOCK_7_7_1_0,buf1086_ptr,buf1086d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1087_buf1087d,LOCK_7_6_0_0,LOCK_7_6_1_0,buf1087_ptr,buf1087d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1085_buf1085d,LOCK_7_5_6_0,LOCK_7_5_7_4096,buf1085_ptr,buf1085d_ptr,0,index, REL_WRITE);
    window_release(window_buf1088_buf1088d,LOCK_7_7_2_4096,LOCK_7_7_3_0,buf1088_ptr,buf1088d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_6_bounds > 0)
      --proc_7_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}