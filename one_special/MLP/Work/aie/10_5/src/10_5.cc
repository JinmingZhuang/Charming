// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_5/src/10_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_5_2_4096 18
#define LOCK_10_5_3_0 19
#define LOCK_11_5_6_4096 54
#define LOCK_11_5_7_4096 55
#define LOCK_10_5_0_0 16
#define LOCK_10_5_1_4096 17
#define LOCK_10_5_4_0 20
#define LOCK_10_5_5_4096 21

// Declare shared memory buffers
v4float buf1046[256];
v4float buf1046d[256];
v4float buf1047[256];
v4float buf1047d[256];
v4float buf1048[256];
v4float buf1048d[256];
v4float buf1049[256];
v4float buf1049d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1047_buf1047d[1];
  window_datatype * buf1047_ptr = (window_datatype * )buf1047;
  window_datatype * buf1047d_ptr = (window_datatype * )buf1047d;
  window_init(window_buf1047_buf1047d, 1, buf1047, LOCK_10_5_2_4096, buf1047d, LOCK_10_5_3_0, 256, 256);
  window_internal window_buf1048_buf1048d[1];
  window_datatype * buf1048_ptr = (window_datatype * )buf1048;
  window_datatype * buf1048d_ptr = (window_datatype * )buf1048d;
  window_init(window_buf1048_buf1048d, 1, buf1048, LOCK_11_5_6_4096, buf1048d, LOCK_11_5_7_4096, 256, 256);
  window_internal window_buf1046_buf1046d[1];
  window_datatype * buf1046_ptr = (window_datatype * )buf1046;
  window_datatype * buf1046d_ptr = (window_datatype * )buf1046d;
  window_init(window_buf1046_buf1046d, 1, buf1046, LOCK_10_5_0_0, buf1046d, LOCK_10_5_1_4096, 256, 256);
  window_internal window_buf1049_buf1049d[1];
  window_datatype * buf1049_ptr = (window_datatype * )buf1049;
  window_datatype * buf1049d_ptr = (window_datatype * )buf1049d;
  window_init(window_buf1049_buf1049d, 1, buf1049, LOCK_10_5_4_0, buf1049d, LOCK_10_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_5_bounds = sync_buffer[1];

  while (proc_10_5_bounds)
  {

    // Kernel call : i605:mm_kernel1
    window_acquire(window_buf1047_buf1047d,LOCK_10_5_2_4096,LOCK_10_5_3_0,buf1047_ptr,buf1047d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1048_buf1048d,LOCK_11_5_6_4096,LOCK_11_5_7_4096,buf1048_ptr,buf1048d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1046_buf1046d,LOCK_10_5_0_0,LOCK_10_5_1_4096,buf1046_ptr,buf1046d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1049_buf1049d,LOCK_10_5_4_0,LOCK_10_5_5_4096,buf1049_ptr,buf1049d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1047_buf1047d),get_input_window_float(window_buf1048_buf1048d),get_input_window_float(window_buf1046_buf1046d),get_output_window_float(window_buf1049_buf1049d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1047_buf1047d,LOCK_10_5_2_4096,LOCK_10_5_3_0,buf1047_ptr,buf1047d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1048_buf1048d,LOCK_11_5_6_4096,LOCK_11_5_7_4096,buf1048_ptr,buf1048d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1046_buf1046d,LOCK_10_5_0_0,LOCK_10_5_1_4096,buf1046_ptr,buf1046d_ptr,0,index, REL_WRITE);
    window_release(window_buf1049_buf1049d,LOCK_10_5_4_0,LOCK_10_5_5_4096,buf1049_ptr,buf1049d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_5_bounds > 0)
      --proc_10_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}