// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_6/src/44_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_5_4_4096 4
#define LOCK_44_5_5_0 5
#define LOCK_44_7_0_0 32
#define LOCK_44_7_1_0 33
#define LOCK_44_5_2_4096 2
#define LOCK_44_5_3_0 3
#define LOCK_44_6_4_4096 52
#define LOCK_44_6_5_4096 53

// Declare shared memory buffers
v4float buf641[256];
v4float buf641d[256];
v4float buf642[256];
v4float buf642d[256];
v4float buf643[256];
v4float buf643d[256];
v4float buf644[256];
v4float buf644d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf642_buf642d[1];
  window_datatype * buf642_ptr = (window_datatype * )buf642;
  window_datatype * buf642d_ptr = (window_datatype * )buf642d;
  window_init(window_buf642_buf642d, 1, buf642, LOCK_44_5_4_4096, buf642d, LOCK_44_5_5_0, 256, 256);
  window_internal window_buf643_buf643d[1];
  window_datatype * buf643_ptr = (window_datatype * )buf643;
  window_datatype * buf643d_ptr = (window_datatype * )buf643d;
  window_init(window_buf643_buf643d, 1, buf643, LOCK_44_7_0_0, buf643d, LOCK_44_7_1_0, 256, 256);
  window_internal window_buf641_buf641d[1];
  window_datatype * buf641_ptr = (window_datatype * )buf641;
  window_datatype * buf641d_ptr = (window_datatype * )buf641d;
  window_init(window_buf641_buf641d, 1, buf641, LOCK_44_5_2_4096, buf641d, LOCK_44_5_3_0, 256, 256);
  window_internal window_buf644_buf644d[1];
  window_datatype * buf644_ptr = (window_datatype * )buf644;
  window_datatype * buf644d_ptr = (window_datatype * )buf644d;
  window_init(window_buf644_buf644d, 1, buf644, LOCK_44_6_4_4096, buf644d, LOCK_44_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_6_bounds = sync_buffer[1];

  while (proc_44_6_bounds)
  {

    // Kernel call : i402:mm_kernel1
    window_acquire(window_buf642_buf642d,LOCK_44_5_4_4096,LOCK_44_5_5_0,buf642_ptr,buf642d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf643_buf643d,LOCK_44_7_0_0,LOCK_44_7_1_0,buf643_ptr,buf643d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf641_buf641d,LOCK_44_5_2_4096,LOCK_44_5_3_0,buf641_ptr,buf641d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf644_buf644d,LOCK_44_6_4_4096,LOCK_44_6_5_4096,buf644_ptr,buf644d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf642_buf642d),get_input_window_float(window_buf643_buf643d),get_input_window_float(window_buf641_buf641d),get_output_window_float(window_buf644_buf644d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf642_buf642d,LOCK_44_5_4_4096,LOCK_44_5_5_0,buf642_ptr,buf642d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf643_buf643d,LOCK_44_7_0_0,LOCK_44_7_1_0,buf643_ptr,buf643d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf641_buf641d,LOCK_44_5_2_4096,LOCK_44_5_3_0,buf641_ptr,buf641d_ptr,0,index, REL_WRITE);
    window_release(window_buf644_buf644d,LOCK_44_6_4_4096,LOCK_44_6_5_4096,buf644_ptr,buf644d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_6_bounds > 0)
      --proc_44_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}