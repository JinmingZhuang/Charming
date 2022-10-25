// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_7/src/36_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_6_4_4096 4
#define LOCK_36_6_5_0 5
#define LOCK_36_7_2_4096 18
#define LOCK_36_7_3_4096 19
#define LOCK_36_6_2_4096 2
#define LOCK_36_6_3_4096 3
#define LOCK_36_6_6_0 6
#define LOCK_36_6_7_0 7

// Declare shared memory buffers
v4float buf740[256];
v4float buf740d[256];
v4float buf741[256];
v4float buf741d[256];
v4float buf742[256];
v4float buf742d[256];
v4float buf743[256];
v4float buf743d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf741_buf741d[1];
  window_datatype * buf741_ptr = (window_datatype * )buf741;
  window_datatype * buf741d_ptr = (window_datatype * )buf741d;
  window_init(window_buf741_buf741d, 1, buf741, LOCK_36_6_4_4096, buf741d, LOCK_36_6_5_0, 256, 256);
  window_internal window_buf742_buf742d[1];
  window_datatype * buf742_ptr = (window_datatype * )buf742;
  window_datatype * buf742d_ptr = (window_datatype * )buf742d;
  window_init(window_buf742_buf742d, 1, buf742, LOCK_36_7_2_4096, buf742d, LOCK_36_7_3_4096, 256, 256);
  window_internal window_buf740_buf740d[1];
  window_datatype * buf740_ptr = (window_datatype * )buf740;
  window_datatype * buf740d_ptr = (window_datatype * )buf740d;
  window_init(window_buf740_buf740d, 1, buf740, LOCK_36_6_2_4096, buf740d, LOCK_36_6_3_4096, 256, 256);
  window_internal window_buf743_buf743d[1];
  window_datatype * buf743_ptr = (window_datatype * )buf743;
  window_datatype * buf743d_ptr = (window_datatype * )buf743d;
  window_init(window_buf743_buf743d, 1, buf743, LOCK_36_6_6_0, buf743d, LOCK_36_6_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_7_bounds = sync_buffer[1];

  while (proc_36_7_bounds)
  {

    // Kernel call : i451:mm_kernel1
    window_acquire(window_buf741_buf741d,LOCK_36_6_4_4096,LOCK_36_6_5_0,buf741_ptr,buf741d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf742_buf742d,LOCK_36_7_2_4096,LOCK_36_7_3_4096,buf742_ptr,buf742d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf740_buf740d,LOCK_36_6_2_4096,LOCK_36_6_3_4096,buf740_ptr,buf740d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf743_buf743d,LOCK_36_6_6_0,LOCK_36_6_7_0,buf743_ptr,buf743d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf741_buf741d),get_input_window_float(window_buf742_buf742d),get_input_window_float(window_buf740_buf740d),get_output_window_float(window_buf743_buf743d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf741_buf741d,LOCK_36_6_4_4096,LOCK_36_6_5_0,buf741_ptr,buf741d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf742_buf742d,LOCK_36_7_2_4096,LOCK_36_7_3_4096,buf742_ptr,buf742d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf740_buf740d,LOCK_36_6_2_4096,LOCK_36_6_3_4096,buf740_ptr,buf740d_ptr,0,index, REL_WRITE);
    window_release(window_buf743_buf743d,LOCK_36_6_6_0,LOCK_36_6_7_0,buf743_ptr,buf743d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_7_bounds > 0)
      --proc_36_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}