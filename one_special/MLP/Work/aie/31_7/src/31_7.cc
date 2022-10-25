// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_7/src/31_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_7_4_0 20
#define LOCK_31_7_5_0 21
#define LOCK_31_6_2_4096 2
#define LOCK_31_6_3_4096 3
#define LOCK_31_7_2_4096 18
#define LOCK_31_7_3_4096 19
#define LOCK_31_7_6_0 22
#define LOCK_31_7_7_0 23

// Declare shared memory buffers
v4float buf800[256];
v4float buf800d[256];
v4float buf801[256];
v4float buf801d[256];
v4float buf802[256];
v4float buf802d[256];
v4float buf803[256];
v4float buf803d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf801_buf801d[1];
  window_datatype * buf801_ptr = (window_datatype * )buf801;
  window_datatype * buf801d_ptr = (window_datatype * )buf801d;
  window_init(window_buf801_buf801d, 1, buf801, LOCK_31_7_4_0, buf801d, LOCK_31_7_5_0, 256, 256);
  window_internal window_buf802_buf802d[1];
  window_datatype * buf802_ptr = (window_datatype * )buf802;
  window_datatype * buf802d_ptr = (window_datatype * )buf802d;
  window_init(window_buf802_buf802d, 1, buf802, LOCK_31_6_2_4096, buf802d, LOCK_31_6_3_4096, 256, 256);
  window_internal window_buf800_buf800d[1];
  window_datatype * buf800_ptr = (window_datatype * )buf800;
  window_datatype * buf800d_ptr = (window_datatype * )buf800d;
  window_init(window_buf800_buf800d, 1, buf800, LOCK_31_7_2_4096, buf800d, LOCK_31_7_3_4096, 256, 256);
  window_internal window_buf803_buf803d[1];
  window_datatype * buf803_ptr = (window_datatype * )buf803;
  window_datatype * buf803d_ptr = (window_datatype * )buf803d;
  window_init(window_buf803_buf803d, 1, buf803, LOCK_31_7_6_0, buf803d, LOCK_31_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_7_bounds = sync_buffer[1];

  while (proc_31_7_bounds)
  {

    // Kernel call : i481:mm_kernel1
    window_acquire(window_buf801_buf801d,LOCK_31_7_4_0,LOCK_31_7_5_0,buf801_ptr,buf801d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf802_buf802d,LOCK_31_6_2_4096,LOCK_31_6_3_4096,buf802_ptr,buf802d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf800_buf800d,LOCK_31_7_2_4096,LOCK_31_7_3_4096,buf800_ptr,buf800d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf803_buf803d,LOCK_31_7_6_0,LOCK_31_7_7_0,buf803_ptr,buf803d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf801_buf801d),get_input_window_float(window_buf802_buf802d),get_input_window_float(window_buf800_buf800d),get_output_window_float(window_buf803_buf803d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf801_buf801d,LOCK_31_7_4_0,LOCK_31_7_5_0,buf801_ptr,buf801d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf802_buf802d,LOCK_31_6_2_4096,LOCK_31_6_3_4096,buf802_ptr,buf802d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf800_buf800d,LOCK_31_7_2_4096,LOCK_31_7_3_4096,buf800_ptr,buf800d_ptr,0,index, REL_WRITE);
    window_release(window_buf803_buf803d,LOCK_31_7_6_0,LOCK_31_7_7_0,buf803_ptr,buf803d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_7_bounds > 0)
      --proc_31_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}