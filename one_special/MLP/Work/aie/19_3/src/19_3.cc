// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_3/src/19_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_3_0_0 48
#define LOCK_20_3_1_4096 49
#define LOCK_19_2_2_4096 2
#define LOCK_19_2_3_4096 3
#define LOCK_19_2_0_0 0
#define LOCK_19_2_1_0 1
#define LOCK_19_2_4_0 4
#define LOCK_19_2_5_0 5

// Declare shared memory buffers
v4float buf212[256];
v4float buf212d[256];
v4float buf213[256];
v4float buf213d[256];
v4float buf214[256];
v4float buf214d[256];
v4float buf215[256];
v4float buf215d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf213_buf213d[1];
  window_datatype * buf213_ptr = (window_datatype * )buf213;
  window_datatype * buf213d_ptr = (window_datatype * )buf213d;
  window_init(window_buf213_buf213d, 1, buf213, LOCK_20_3_0_0, buf213d, LOCK_20_3_1_4096, 256, 256);
  window_internal window_buf214_buf214d[1];
  window_datatype * buf214_ptr = (window_datatype * )buf214;
  window_datatype * buf214d_ptr = (window_datatype * )buf214d;
  window_init(window_buf214_buf214d, 1, buf214, LOCK_19_2_2_4096, buf214d, LOCK_19_2_3_4096, 256, 256);
  window_internal window_buf212_buf212d[1];
  window_datatype * buf212_ptr = (window_datatype * )buf212;
  window_datatype * buf212d_ptr = (window_datatype * )buf212d;
  window_init(window_buf212_buf212d, 1, buf212, LOCK_19_2_0_0, buf212d, LOCK_19_2_1_0, 256, 256);
  window_internal window_buf215_buf215d[1];
  window_datatype * buf215_ptr = (window_datatype * )buf215;
  window_datatype * buf215d_ptr = (window_datatype * )buf215d;
  window_init(window_buf215_buf215d, 1, buf215, LOCK_19_2_4_0, buf215d, LOCK_19_2_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_3_bounds = sync_buffer[1];

  while (proc_19_3_bounds)
  {

    // Kernel call : i187:mm_kernel1
    window_acquire(window_buf213_buf213d,LOCK_20_3_0_0,LOCK_20_3_1_4096,buf213_ptr,buf213d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf214_buf214d,LOCK_19_2_2_4096,LOCK_19_2_3_4096,buf214_ptr,buf214d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf212_buf212d,LOCK_19_2_0_0,LOCK_19_2_1_0,buf212_ptr,buf212d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf215_buf215d,LOCK_19_2_4_0,LOCK_19_2_5_0,buf215_ptr,buf215d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf213_buf213d),get_input_window_float(window_buf214_buf214d),get_input_window_float(window_buf212_buf212d),get_output_window_float(window_buf215_buf215d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf213_buf213d,LOCK_20_3_0_0,LOCK_20_3_1_4096,buf213_ptr,buf213d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf214_buf214d,LOCK_19_2_2_4096,LOCK_19_2_3_4096,buf214_ptr,buf214d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf212_buf212d,LOCK_19_2_0_0,LOCK_19_2_1_0,buf212_ptr,buf212d_ptr,0,index, REL_WRITE);
    window_release(window_buf215_buf215d,LOCK_19_2_4_0,LOCK_19_2_5_0,buf215_ptr,buf215d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_3_bounds > 0)
      --proc_19_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}