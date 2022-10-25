// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_4/src/36_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_3_2_4096 2
#define LOCK_36_3_3_4096 3
#define LOCK_36_4_2_4096 50
#define LOCK_36_4_3_4096 51
#define LOCK_36_5_0_0 32
#define LOCK_36_5_1_0 33

// Declare shared memory buffers
v4float buf732[256];
v4float buf732d[256];
v4float buf733[256];
v4float buf733d[256];
v4float buf734[256];
v4float buf734d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf732_buf732d[1];
  window_datatype * buf732_ptr = (window_datatype * )buf732;
  window_datatype * buf732d_ptr = (window_datatype * )buf732d;
  window_init(window_buf732_buf732d, 1, buf732, LOCK_36_3_2_4096, buf732d, LOCK_36_3_3_4096, 256, 256);
  window_internal window_buf733_buf733d[1];
  window_datatype * buf733_ptr = (window_datatype * )buf733;
  window_datatype * buf733d_ptr = (window_datatype * )buf733d;
  window_init(window_buf733_buf733d, 1, buf733, LOCK_36_4_2_4096, buf733d, LOCK_36_4_3_4096, 256, 256);
  window_internal window_buf734_buf734d[1];
  window_datatype * buf734_ptr = (window_datatype * )buf734;
  window_datatype * buf734d_ptr = (window_datatype * )buf734d;
  window_init(window_buf734_buf734d, 1, buf734, LOCK_36_5_0_0, buf734d, LOCK_36_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_4_bounds = sync_buffer[1];

  while (proc_36_4_bounds)
  {

    // Kernel call : i448:mm_kernel0
    window_acquire(window_buf732_buf732d,LOCK_36_3_2_4096,LOCK_36_3_3_4096,buf732_ptr,buf732d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf733_buf733d,LOCK_36_4_2_4096,LOCK_36_4_3_4096,buf733_ptr,buf733d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf734_buf734d,LOCK_36_5_0_0,LOCK_36_5_1_0,buf734_ptr,buf734d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf732_buf732d),get_input_window_float(window_buf733_buf733d),get_output_window_float(window_buf734_buf734d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf732_buf732d,LOCK_36_3_2_4096,LOCK_36_3_3_4096,buf732_ptr,buf732d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf733_buf733d,LOCK_36_4_2_4096,LOCK_36_4_3_4096,buf733_ptr,buf733d_ptr,0,index, REL_WRITE);
    window_release(window_buf734_buf734d,LOCK_36_5_0_0,LOCK_36_5_1_0,buf734_ptr,buf734d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_4_bounds > 0)
      --proc_36_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}