// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_7/src/35_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_7_0_4096 16
#define LOCK_35_7_1_4096 17
#define LOCK_35_7_2_0 18
#define LOCK_35_7_3_0 19
#define LOCK_35_6_4_4096 4
#define LOCK_35_6_5_4096 5
#define LOCK_35_6_6_0 6
#define LOCK_35_6_7_4096 7

// Declare shared memory buffers
v4float buf752[256];
v4float buf752d[256];
v4float buf753[256];
v4float buf753d[256];
v4float buf754[256];
v4float buf754d[256];
v4float buf755[256];
v4float buf755d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf753_buf753d[1];
  window_datatype * buf753_ptr = (window_datatype * )buf753;
  window_datatype * buf753d_ptr = (window_datatype * )buf753d;
  window_init(window_buf753_buf753d, 1, buf753, LOCK_35_7_0_4096, buf753d, LOCK_35_7_1_4096, 256, 256);
  window_internal window_buf754_buf754d[1];
  window_datatype * buf754_ptr = (window_datatype * )buf754;
  window_datatype * buf754d_ptr = (window_datatype * )buf754d;
  window_init(window_buf754_buf754d, 1, buf754, LOCK_35_7_2_0, buf754d, LOCK_35_7_3_0, 256, 256);
  window_internal window_buf752_buf752d[1];
  window_datatype * buf752_ptr = (window_datatype * )buf752;
  window_datatype * buf752d_ptr = (window_datatype * )buf752d;
  window_init(window_buf752_buf752d, 1, buf752, LOCK_35_6_4_4096, buf752d, LOCK_35_6_5_4096, 256, 256);
  window_internal window_buf755_buf755d[1];
  window_datatype * buf755_ptr = (window_datatype * )buf755;
  window_datatype * buf755d_ptr = (window_datatype * )buf755d;
  window_init(window_buf755_buf755d, 1, buf755, LOCK_35_6_6_0, buf755d, LOCK_35_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_7_bounds = sync_buffer[1];

  while (proc_35_7_bounds)
  {

    // Kernel call : i457:mm_kernel1
    window_acquire(window_buf753_buf753d,LOCK_35_7_0_4096,LOCK_35_7_1_4096,buf753_ptr,buf753d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf754_buf754d,LOCK_35_7_2_0,LOCK_35_7_3_0,buf754_ptr,buf754d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf752_buf752d,LOCK_35_6_4_4096,LOCK_35_6_5_4096,buf752_ptr,buf752d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf755_buf755d,LOCK_35_6_6_0,LOCK_35_6_7_4096,buf755_ptr,buf755d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf753_buf753d),get_input_window_float(window_buf754_buf754d),get_input_window_float(window_buf752_buf752d),get_output_window_float(window_buf755_buf755d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf753_buf753d,LOCK_35_7_0_4096,LOCK_35_7_1_4096,buf753_ptr,buf753d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf754_buf754d,LOCK_35_7_2_0,LOCK_35_7_3_0,buf754_ptr,buf754d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf752_buf752d,LOCK_35_6_4_4096,LOCK_35_6_5_4096,buf752_ptr,buf752d_ptr,0,index, REL_WRITE);
    window_release(window_buf755_buf755d,LOCK_35_6_6_0,LOCK_35_6_7_4096,buf755_ptr,buf755d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_7_bounds > 0)
      --proc_35_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}