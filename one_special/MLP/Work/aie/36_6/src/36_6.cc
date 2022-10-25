// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_6/src/36_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_6_0_4096 48
#define LOCK_36_6_1_0 49
#define LOCK_36_7_0_0 32
#define LOCK_36_7_1_0 33
#define LOCK_36_5_6_4096 6
#define LOCK_36_5_7_4096 7
#define LOCK_36_6_2_4096 50
#define LOCK_36_6_3_4096 51

// Declare shared memory buffers
v4float buf737[256];
v4float buf737d[256];
v4float buf738[256];
v4float buf738d[256];
v4float buf739[256];
v4float buf739d[256];
v4float buf740[256];
v4float buf740d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf738_buf738d[1];
  window_datatype * buf738_ptr = (window_datatype * )buf738;
  window_datatype * buf738d_ptr = (window_datatype * )buf738d;
  window_init(window_buf738_buf738d, 1, buf738, LOCK_36_6_0_4096, buf738d, LOCK_36_6_1_0, 256, 256);
  window_internal window_buf739_buf739d[1];
  window_datatype * buf739_ptr = (window_datatype * )buf739;
  window_datatype * buf739d_ptr = (window_datatype * )buf739d;
  window_init(window_buf739_buf739d, 1, buf739, LOCK_36_7_0_0, buf739d, LOCK_36_7_1_0, 256, 256);
  window_internal window_buf737_buf737d[1];
  window_datatype * buf737_ptr = (window_datatype * )buf737;
  window_datatype * buf737d_ptr = (window_datatype * )buf737d;
  window_init(window_buf737_buf737d, 1, buf737, LOCK_36_5_6_4096, buf737d, LOCK_36_5_7_4096, 256, 256);
  window_internal window_buf740_buf740d[1];
  window_datatype * buf740_ptr = (window_datatype * )buf740;
  window_datatype * buf740d_ptr = (window_datatype * )buf740d;
  window_init(window_buf740_buf740d, 1, buf740, LOCK_36_6_2_4096, buf740d, LOCK_36_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_6_bounds = sync_buffer[1];

  while (proc_36_6_bounds)
  {

    // Kernel call : i450:mm_kernel1
    window_acquire(window_buf738_buf738d,LOCK_36_6_0_4096,LOCK_36_6_1_0,buf738_ptr,buf738d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf739_buf739d,LOCK_36_7_0_0,LOCK_36_7_1_0,buf739_ptr,buf739d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf737_buf737d,LOCK_36_5_6_4096,LOCK_36_5_7_4096,buf737_ptr,buf737d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf740_buf740d,LOCK_36_6_2_4096,LOCK_36_6_3_4096,buf740_ptr,buf740d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf738_buf738d),get_input_window_float(window_buf739_buf739d),get_input_window_float(window_buf737_buf737d),get_output_window_float(window_buf740_buf740d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf738_buf738d,LOCK_36_6_0_4096,LOCK_36_6_1_0,buf738_ptr,buf738d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf739_buf739d,LOCK_36_7_0_0,LOCK_36_7_1_0,buf739_ptr,buf739d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf737_buf737d,LOCK_36_5_6_4096,LOCK_36_5_7_4096,buf737_ptr,buf737d_ptr,0,index, REL_WRITE);
    window_release(window_buf740_buf740d,LOCK_36_6_2_4096,LOCK_36_6_3_4096,buf740_ptr,buf740d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_6_bounds > 0)
      --proc_36_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}