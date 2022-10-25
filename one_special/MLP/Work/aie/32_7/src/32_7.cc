// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_7/src/32_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_32_7_4_4096 20
#define LOCK_32_7_5_0 21
#define LOCK_33_7_6_0 54
#define LOCK_33_7_7_0 55
#define LOCK_32_7_2_4096 18
#define LOCK_32_7_3_4096 19
#define LOCK_32_7_6_0 22
#define LOCK_32_7_7_0 23

// Declare shared memory buffers
v4float buf788[256];
v4float buf788d[256];
v4float buf789[256];
v4float buf789d[256];
v4float buf790[256];
v4float buf790d[256];
v4float buf791[256];
v4float buf791d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf789_buf789d[1];
  window_datatype * buf789_ptr = (window_datatype * )buf789;
  window_datatype * buf789d_ptr = (window_datatype * )buf789d;
  window_init(window_buf789_buf789d, 1, buf789, LOCK_32_7_4_4096, buf789d, LOCK_32_7_5_0, 256, 256);
  window_internal window_buf790_buf790d[1];
  window_datatype * buf790_ptr = (window_datatype * )buf790;
  window_datatype * buf790d_ptr = (window_datatype * )buf790d;
  window_init(window_buf790_buf790d, 1, buf790, LOCK_33_7_6_0, buf790d, LOCK_33_7_7_0, 256, 256);
  window_internal window_buf788_buf788d[1];
  window_datatype * buf788_ptr = (window_datatype * )buf788;
  window_datatype * buf788d_ptr = (window_datatype * )buf788d;
  window_init(window_buf788_buf788d, 1, buf788, LOCK_32_7_2_4096, buf788d, LOCK_32_7_3_4096, 256, 256);
  window_internal window_buf791_buf791d[1];
  window_datatype * buf791_ptr = (window_datatype * )buf791;
  window_datatype * buf791d_ptr = (window_datatype * )buf791d;
  window_init(window_buf791_buf791d, 1, buf791, LOCK_32_7_6_0, buf791d, LOCK_32_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_7_bounds = sync_buffer[1];

  while (proc_32_7_bounds)
  {

    // Kernel call : i475:mm_kernel1
    window_acquire(window_buf789_buf789d,LOCK_32_7_4_4096,LOCK_32_7_5_0,buf789_ptr,buf789d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf790_buf790d,LOCK_33_7_6_0,LOCK_33_7_7_0,buf790_ptr,buf790d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf788_buf788d,LOCK_32_7_2_4096,LOCK_32_7_3_4096,buf788_ptr,buf788d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf791_buf791d,LOCK_32_7_6_0,LOCK_32_7_7_0,buf791_ptr,buf791d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf789_buf789d),get_input_window_float(window_buf790_buf790d),get_input_window_float(window_buf788_buf788d),get_output_window_float(window_buf791_buf791d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf789_buf789d,LOCK_32_7_4_4096,LOCK_32_7_5_0,buf789_ptr,buf789d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf790_buf790d,LOCK_33_7_6_0,LOCK_33_7_7_0,buf790_ptr,buf790d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf788_buf788d,LOCK_32_7_2_4096,LOCK_32_7_3_4096,buf788_ptr,buf788d_ptr,0,index, REL_WRITE);
    window_release(window_buf791_buf791d,LOCK_32_7_6_0,LOCK_32_7_7_0,buf791_ptr,buf791d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_7_bounds > 0)
      --proc_32_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}