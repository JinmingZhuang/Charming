// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_5/src/7_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_7_5_4_4096 20
#define LOCK_7_5_5_0 21
#define LOCK_7_4_2_4096 2
#define LOCK_7_4_3_4096 3
#define LOCK_7_5_2_0 18
#define LOCK_7_5_3_4096 19
#define LOCK_7_5_6_0 22
#define LOCK_7_5_7_4096 23

// Declare shared memory buffers
v4float buf1082[256];
v4float buf1082d[256];
v4float buf1083[256];
v4float buf1083d[256];
v4float buf1084[256];
v4float buf1084d[256];
v4float buf1085[256];
v4float buf1085d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1083_buf1083d[1];
  window_datatype * buf1083_ptr = (window_datatype * )buf1083;
  window_datatype * buf1083d_ptr = (window_datatype * )buf1083d;
  window_init(window_buf1083_buf1083d, 1, buf1083, LOCK_7_5_4_4096, buf1083d, LOCK_7_5_5_0, 256, 256);
  window_internal window_buf1084_buf1084d[1];
  window_datatype * buf1084_ptr = (window_datatype * )buf1084;
  window_datatype * buf1084d_ptr = (window_datatype * )buf1084d;
  window_init(window_buf1084_buf1084d, 1, buf1084, LOCK_7_4_2_4096, buf1084d, LOCK_7_4_3_4096, 256, 256);
  window_internal window_buf1082_buf1082d[1];
  window_datatype * buf1082_ptr = (window_datatype * )buf1082;
  window_datatype * buf1082d_ptr = (window_datatype * )buf1082d;
  window_init(window_buf1082_buf1082d, 1, buf1082, LOCK_7_5_2_0, buf1082d, LOCK_7_5_3_4096, 256, 256);
  window_internal window_buf1085_buf1085d[1];
  window_datatype * buf1085_ptr = (window_datatype * )buf1085;
  window_datatype * buf1085d_ptr = (window_datatype * )buf1085d;
  window_init(window_buf1085_buf1085d, 1, buf1085, LOCK_7_5_6_0, buf1085d, LOCK_7_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_5_bounds = sync_buffer[1];

  while (proc_7_5_bounds)
  {

    // Kernel call : i623:mm_kernel1
    window_acquire(window_buf1083_buf1083d,LOCK_7_5_4_4096,LOCK_7_5_5_0,buf1083_ptr,buf1083d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1084_buf1084d,LOCK_7_4_2_4096,LOCK_7_4_3_4096,buf1084_ptr,buf1084d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1082_buf1082d,LOCK_7_5_2_0,LOCK_7_5_3_4096,buf1082_ptr,buf1082d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1085_buf1085d,LOCK_7_5_6_0,LOCK_7_5_7_4096,buf1085_ptr,buf1085d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1083_buf1083d),get_input_window_float(window_buf1084_buf1084d),get_input_window_float(window_buf1082_buf1082d),get_output_window_float(window_buf1085_buf1085d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1083_buf1083d,LOCK_7_5_4_4096,LOCK_7_5_5_0,buf1083_ptr,buf1083d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1084_buf1084d,LOCK_7_4_2_4096,LOCK_7_4_3_4096,buf1084_ptr,buf1084d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1082_buf1082d,LOCK_7_5_2_0,LOCK_7_5_3_4096,buf1082_ptr,buf1082d_ptr,0,index, REL_WRITE);
    window_release(window_buf1085_buf1085d,LOCK_7_5_6_0,LOCK_7_5_7_4096,buf1085_ptr,buf1085d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_5_bounds > 0)
      --proc_7_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}