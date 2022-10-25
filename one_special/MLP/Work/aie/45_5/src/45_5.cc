// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_5/src/45_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_45_5_2_4096 18
#define LOCK_45_5_3_4096 19
#define LOCK_45_5_4_0 20
#define LOCK_45_5_5_0 21
#define LOCK_45_5_0_0 16
#define LOCK_45_5_1_0 17
#define LOCK_45_5_6_4096 22
#define LOCK_45_5_7_4096 23

// Declare shared memory buffers
v4float buf626[256];
v4float buf626d[256];
v4float buf627[256];
v4float buf627d[256];
v4float buf628[256];
v4float buf628d[256];
v4float buf629[256];
v4float buf629d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf627_buf627d[1];
  window_datatype * buf627_ptr = (window_datatype * )buf627;
  window_datatype * buf627d_ptr = (window_datatype * )buf627d;
  window_init(window_buf627_buf627d, 1, buf627, LOCK_45_5_2_4096, buf627d, LOCK_45_5_3_4096, 256, 256);
  window_internal window_buf628_buf628d[1];
  window_datatype * buf628_ptr = (window_datatype * )buf628;
  window_datatype * buf628d_ptr = (window_datatype * )buf628d;
  window_init(window_buf628_buf628d, 1, buf628, LOCK_45_5_4_0, buf628d, LOCK_45_5_5_0, 256, 256);
  window_internal window_buf626_buf626d[1];
  window_datatype * buf626_ptr = (window_datatype * )buf626;
  window_datatype * buf626d_ptr = (window_datatype * )buf626d;
  window_init(window_buf626_buf626d, 1, buf626, LOCK_45_5_0_0, buf626d, LOCK_45_5_1_0, 256, 256);
  window_internal window_buf629_buf629d[1];
  window_datatype * buf629_ptr = (window_datatype * )buf629;
  window_datatype * buf629d_ptr = (window_datatype * )buf629d;
  window_init(window_buf629_buf629d, 1, buf629, LOCK_45_5_6_4096, buf629d, LOCK_45_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_5_bounds = sync_buffer[1];

  while (proc_45_5_bounds)
  {

    // Kernel call : i395:mm_kernel1
    window_acquire(window_buf627_buf627d,LOCK_45_5_2_4096,LOCK_45_5_3_4096,buf627_ptr,buf627d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf628_buf628d,LOCK_45_5_4_0,LOCK_45_5_5_0,buf628_ptr,buf628d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf626_buf626d,LOCK_45_5_0_0,LOCK_45_5_1_0,buf626_ptr,buf626d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf629_buf629d,LOCK_45_5_6_4096,LOCK_45_5_7_4096,buf629_ptr,buf629d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf627_buf627d),get_input_window_float(window_buf628_buf628d),get_input_window_float(window_buf626_buf626d),get_output_window_float(window_buf629_buf629d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf627_buf627d,LOCK_45_5_2_4096,LOCK_45_5_3_4096,buf627_ptr,buf627d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf628_buf628d,LOCK_45_5_4_0,LOCK_45_5_5_0,buf628_ptr,buf628d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf626_buf626d,LOCK_45_5_0_0,LOCK_45_5_1_0,buf626_ptr,buf626d_ptr,0,index, REL_WRITE);
    window_release(window_buf629_buf629d,LOCK_45_5_6_4096,LOCK_45_5_7_4096,buf629_ptr,buf629d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_5_bounds > 0)
      --proc_45_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}