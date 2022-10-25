// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_6/src/6_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_7_0_0 32
#define LOCK_6_7_1_4096 33
#define LOCK_6_7_2_4096 34
#define LOCK_6_7_3_0 35
#define LOCK_6_5_6_0 6
#define LOCK_6_5_7_0 7
#define LOCK_6_7_4_4096 36
#define LOCK_6_7_5_0 37

// Declare shared memory buffers
v4float buf1097[256];
v4float buf1097d[256];
v4float buf1098[256];
v4float buf1098d[256];
v4float buf1099[256];
v4float buf1099d[256];
v4float buf1100[256];
v4float buf1100d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1098_buf1098d[1];
  window_datatype * buf1098_ptr = (window_datatype * )buf1098;
  window_datatype * buf1098d_ptr = (window_datatype * )buf1098d;
  window_init(window_buf1098_buf1098d, 1, buf1098, LOCK_6_7_0_0, buf1098d, LOCK_6_7_1_4096, 256, 256);
  window_internal window_buf1099_buf1099d[1];
  window_datatype * buf1099_ptr = (window_datatype * )buf1099;
  window_datatype * buf1099d_ptr = (window_datatype * )buf1099d;
  window_init(window_buf1099_buf1099d, 1, buf1099, LOCK_6_7_2_4096, buf1099d, LOCK_6_7_3_0, 256, 256);
  window_internal window_buf1097_buf1097d[1];
  window_datatype * buf1097_ptr = (window_datatype * )buf1097;
  window_datatype * buf1097d_ptr = (window_datatype * )buf1097d;
  window_init(window_buf1097_buf1097d, 1, buf1097, LOCK_6_5_6_0, buf1097d, LOCK_6_5_7_0, 256, 256);
  window_internal window_buf1100_buf1100d[1];
  window_datatype * buf1100_ptr = (window_datatype * )buf1100;
  window_datatype * buf1100d_ptr = (window_datatype * )buf1100d;
  window_init(window_buf1100_buf1100d, 1, buf1100, LOCK_6_7_4_4096, buf1100d, LOCK_6_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_6_bounds = sync_buffer[1];

  while (proc_6_6_bounds)
  {

    // Kernel call : i630:mm_kernel1
    window_acquire(window_buf1098_buf1098d,LOCK_6_7_0_0,LOCK_6_7_1_4096,buf1098_ptr,buf1098d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1099_buf1099d,LOCK_6_7_2_4096,LOCK_6_7_3_0,buf1099_ptr,buf1099d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1097_buf1097d,LOCK_6_5_6_0,LOCK_6_5_7_0,buf1097_ptr,buf1097d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1100_buf1100d,LOCK_6_7_4_4096,LOCK_6_7_5_0,buf1100_ptr,buf1100d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1098_buf1098d),get_input_window_float(window_buf1099_buf1099d),get_input_window_float(window_buf1097_buf1097d),get_output_window_float(window_buf1100_buf1100d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1098_buf1098d,LOCK_6_7_0_0,LOCK_6_7_1_4096,buf1098_ptr,buf1098d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1099_buf1099d,LOCK_6_7_2_4096,LOCK_6_7_3_0,buf1099_ptr,buf1099d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1097_buf1097d,LOCK_6_5_6_0,LOCK_6_5_7_0,buf1097_ptr,buf1097d_ptr,0,index, REL_WRITE);
    window_release(window_buf1100_buf1100d,LOCK_6_7_4_4096,LOCK_6_7_5_0,buf1100_ptr,buf1100d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_6_bounds > 0)
      --proc_6_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}