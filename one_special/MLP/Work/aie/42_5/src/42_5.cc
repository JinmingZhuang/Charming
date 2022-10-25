// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_5/src/42_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_5_2_4096 18
#define LOCK_42_5_3_0 19
#define LOCK_42_6_0_0 32
#define LOCK_42_6_1_0 33
#define LOCK_42_5_0_4096 16
#define LOCK_42_5_1_4096 17
#define LOCK_42_5_4_0 20
#define LOCK_42_5_5_4096 21

// Declare shared memory buffers
v4float buf662[256];
v4float buf662d[256];
v4float buf663[256];
v4float buf663d[256];
v4float buf664[256];
v4float buf664d[256];
v4float buf665[256];
v4float buf665d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf663_buf663d[1];
  window_datatype * buf663_ptr = (window_datatype * )buf663;
  window_datatype * buf663d_ptr = (window_datatype * )buf663d;
  window_init(window_buf663_buf663d, 1, buf663, LOCK_42_5_2_4096, buf663d, LOCK_42_5_3_0, 256, 256);
  window_internal window_buf664_buf664d[1];
  window_datatype * buf664_ptr = (window_datatype * )buf664;
  window_datatype * buf664d_ptr = (window_datatype * )buf664d;
  window_init(window_buf664_buf664d, 1, buf664, LOCK_42_6_0_0, buf664d, LOCK_42_6_1_0, 256, 256);
  window_internal window_buf662_buf662d[1];
  window_datatype * buf662_ptr = (window_datatype * )buf662;
  window_datatype * buf662d_ptr = (window_datatype * )buf662d;
  window_init(window_buf662_buf662d, 1, buf662, LOCK_42_5_0_4096, buf662d, LOCK_42_5_1_4096, 256, 256);
  window_internal window_buf665_buf665d[1];
  window_datatype * buf665_ptr = (window_datatype * )buf665;
  window_datatype * buf665d_ptr = (window_datatype * )buf665d;
  window_init(window_buf665_buf665d, 1, buf665, LOCK_42_5_4_0, buf665d, LOCK_42_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_5_bounds = sync_buffer[1];

  while (proc_42_5_bounds)
  {

    // Kernel call : i413:mm_kernel1
    window_acquire(window_buf663_buf663d,LOCK_42_5_2_4096,LOCK_42_5_3_0,buf663_ptr,buf663d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf664_buf664d,LOCK_42_6_0_0,LOCK_42_6_1_0,buf664_ptr,buf664d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf662_buf662d,LOCK_42_5_0_4096,LOCK_42_5_1_4096,buf662_ptr,buf662d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf665_buf665d,LOCK_42_5_4_0,LOCK_42_5_5_4096,buf665_ptr,buf665d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf663_buf663d),get_input_window_float(window_buf664_buf664d),get_input_window_float(window_buf662_buf662d),get_output_window_float(window_buf665_buf665d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf663_buf663d,LOCK_42_5_2_4096,LOCK_42_5_3_0,buf663_ptr,buf663d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf664_buf664d,LOCK_42_6_0_0,LOCK_42_6_1_0,buf664_ptr,buf664d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf662_buf662d,LOCK_42_5_0_4096,LOCK_42_5_1_4096,buf662_ptr,buf662d_ptr,0,index, REL_WRITE);
    window_release(window_buf665_buf665d,LOCK_42_5_4_0,LOCK_42_5_5_4096,buf665_ptr,buf665d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_5_bounds > 0)
      --proc_42_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}