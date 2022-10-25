// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_5/src/4_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_4_2_4096 2
#define LOCK_4_4_3_4096 3
#define LOCK_4_6_2_4096 34
#define LOCK_4_6_3_4096 35
#define LOCK_4_5_2_4096 18
#define LOCK_4_5_3_0 19
#define LOCK_4_5_4_0 20
#define LOCK_4_5_5_4096 21

// Declare shared memory buffers
v4float buf1118[256];
v4float buf1118d[256];
v4float buf1119[256];
v4float buf1119d[256];
v4float buf1120[256];
v4float buf1120d[256];
v4float buf1121[256];
v4float buf1121d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1119_buf1119d[1];
  window_datatype * buf1119_ptr = (window_datatype * )buf1119;
  window_datatype * buf1119d_ptr = (window_datatype * )buf1119d;
  window_init(window_buf1119_buf1119d, 1, buf1119, LOCK_4_4_2_4096, buf1119d, LOCK_4_4_3_4096, 256, 256);
  window_internal window_buf1120_buf1120d[1];
  window_datatype * buf1120_ptr = (window_datatype * )buf1120;
  window_datatype * buf1120d_ptr = (window_datatype * )buf1120d;
  window_init(window_buf1120_buf1120d, 1, buf1120, LOCK_4_6_2_4096, buf1120d, LOCK_4_6_3_4096, 256, 256);
  window_internal window_buf1118_buf1118d[1];
  window_datatype * buf1118_ptr = (window_datatype * )buf1118;
  window_datatype * buf1118d_ptr = (window_datatype * )buf1118d;
  window_init(window_buf1118_buf1118d, 1, buf1118, LOCK_4_5_2_4096, buf1118d, LOCK_4_5_3_0, 256, 256);
  window_internal window_buf1121_buf1121d[1];
  window_datatype * buf1121_ptr = (window_datatype * )buf1121;
  window_datatype * buf1121d_ptr = (window_datatype * )buf1121d;
  window_init(window_buf1121_buf1121d, 1, buf1121, LOCK_4_5_4_0, buf1121d, LOCK_4_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_5_bounds = sync_buffer[1];

  while (proc_4_5_bounds)
  {

    // Kernel call : i641:mm_kernel1
    window_acquire(window_buf1119_buf1119d,LOCK_4_4_2_4096,LOCK_4_4_3_4096,buf1119_ptr,buf1119d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1120_buf1120d,LOCK_4_6_2_4096,LOCK_4_6_3_4096,buf1120_ptr,buf1120d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1118_buf1118d,LOCK_4_5_2_4096,LOCK_4_5_3_0,buf1118_ptr,buf1118d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1121_buf1121d,LOCK_4_5_4_0,LOCK_4_5_5_4096,buf1121_ptr,buf1121d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1119_buf1119d),get_input_window_float(window_buf1120_buf1120d),get_input_window_float(window_buf1118_buf1118d),get_output_window_float(window_buf1121_buf1121d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1119_buf1119d,LOCK_4_4_2_4096,LOCK_4_4_3_4096,buf1119_ptr,buf1119d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1120_buf1120d,LOCK_4_6_2_4096,LOCK_4_6_3_4096,buf1120_ptr,buf1120d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1118_buf1118d,LOCK_4_5_2_4096,LOCK_4_5_3_0,buf1118_ptr,buf1118d_ptr,0,index, REL_WRITE);
    window_release(window_buf1121_buf1121d,LOCK_4_5_4_0,LOCK_4_5_5_4096,buf1121_ptr,buf1121d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_5_bounds > 0)
      --proc_4_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}