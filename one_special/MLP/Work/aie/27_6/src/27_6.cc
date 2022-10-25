// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_6/src/27_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_5_6_0 6
#define LOCK_27_5_7_0 7
#define LOCK_26_6_0_0 16
#define LOCK_26_6_1_0 17
#define LOCK_27_5_4_4096 4
#define LOCK_27_5_5_4096 5
#define LOCK_27_6_0_0 48
#define LOCK_27_6_1_0 49

// Declare shared memory buffers
v4float buf845[256];
v4float buf845d[256];
v4float buf846[256];
v4float buf846d[256];
v4float buf847[256];
v4float buf847d[256];
v4float buf848[256];
v4float buf848d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf846_buf846d[1];
  window_datatype * buf846_ptr = (window_datatype * )buf846;
  window_datatype * buf846d_ptr = (window_datatype * )buf846d;
  window_init(window_buf846_buf846d, 1, buf846, LOCK_27_5_6_0, buf846d, LOCK_27_5_7_0, 256, 256);
  window_internal window_buf847_buf847d[1];
  window_datatype * buf847_ptr = (window_datatype * )buf847;
  window_datatype * buf847d_ptr = (window_datatype * )buf847d;
  window_init(window_buf847_buf847d, 1, buf847, LOCK_26_6_0_0, buf847d, LOCK_26_6_1_0, 256, 256);
  window_internal window_buf845_buf845d[1];
  window_datatype * buf845_ptr = (window_datatype * )buf845;
  window_datatype * buf845d_ptr = (window_datatype * )buf845d;
  window_init(window_buf845_buf845d, 1, buf845, LOCK_27_5_4_4096, buf845d, LOCK_27_5_5_4096, 256, 256);
  window_internal window_buf848_buf848d[1];
  window_datatype * buf848_ptr = (window_datatype * )buf848;
  window_datatype * buf848d_ptr = (window_datatype * )buf848d;
  window_init(window_buf848_buf848d, 1, buf848, LOCK_27_6_0_0, buf848d, LOCK_27_6_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_6_bounds = sync_buffer[1];

  while (proc_27_6_bounds)
  {

    // Kernel call : i504:mm_kernel1
    window_acquire(window_buf846_buf846d,LOCK_27_5_6_0,LOCK_27_5_7_0,buf846_ptr,buf846d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf847_buf847d,LOCK_26_6_0_0,LOCK_26_6_1_0,buf847_ptr,buf847d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf845_buf845d,LOCK_27_5_4_4096,LOCK_27_5_5_4096,buf845_ptr,buf845d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf848_buf848d,LOCK_27_6_0_0,LOCK_27_6_1_0,buf848_ptr,buf848d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf846_buf846d),get_input_window_float(window_buf847_buf847d),get_input_window_float(window_buf845_buf845d),get_output_window_float(window_buf848_buf848d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf846_buf846d,LOCK_27_5_6_0,LOCK_27_5_7_0,buf846_ptr,buf846d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf847_buf847d,LOCK_26_6_0_0,LOCK_26_6_1_0,buf847_ptr,buf847d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf845_buf845d,LOCK_27_5_4_4096,LOCK_27_5_5_4096,buf845_ptr,buf845d_ptr,0,index, REL_WRITE);
    window_release(window_buf848_buf848d,LOCK_27_6_0_0,LOCK_27_6_1_0,buf848_ptr,buf848d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_6_bounds > 0)
      --proc_27_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}