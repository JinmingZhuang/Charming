// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_0/src/3_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_1_0_0 32
#define LOCK_3_1_1_4096 33
#define LOCK_3_0_0_0 48
#define LOCK_3_0_1_0 49
#define LOCK_3_1_2_0 34
#define LOCK_3_1_3_4096 35

// Declare shared memory buffers
v4float buf12[256];
v4float buf12d[256];
v4float buf13[256];
v4float buf13d[256];
v4float buf14[256];
v4float buf14d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf12_buf12d[1];
  window_datatype * buf12_ptr = (window_datatype * )buf12;
  window_datatype * buf12d_ptr = (window_datatype * )buf12d;
  window_init(window_buf12_buf12d, 1, buf12, LOCK_3_1_0_0, buf12d, LOCK_3_1_1_4096, 256, 256);
  window_internal window_buf13_buf13d[1];
  window_datatype * buf13_ptr = (window_datatype * )buf13;
  window_datatype * buf13d_ptr = (window_datatype * )buf13d;
  window_init(window_buf13_buf13d, 1, buf13, LOCK_3_0_0_0, buf13d, LOCK_3_0_1_0, 256, 256);
  window_internal window_buf14_buf14d[1];
  window_datatype * buf14_ptr = (window_datatype * )buf14;
  window_datatype * buf14d_ptr = (window_datatype * )buf14d;
  window_init(window_buf14_buf14d, 1, buf14, LOCK_3_1_2_0, buf14d, LOCK_3_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_0_bounds = sync_buffer[1];

  while (proc_3_0_bounds)
  {

    // Kernel call : i88:mm_kernel0
    window_acquire(window_buf12_buf12d,LOCK_3_1_0_0,LOCK_3_1_1_4096,buf12_ptr,buf12d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf13_buf13d,LOCK_3_0_0_0,LOCK_3_0_1_0,buf13_ptr,buf13d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf14_buf14d,LOCK_3_1_2_0,LOCK_3_1_3_4096,buf14_ptr,buf14d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf12_buf12d),get_input_window_float(window_buf13_buf13d),get_output_window_float(window_buf14_buf14d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf12_buf12d,LOCK_3_1_0_0,LOCK_3_1_1_4096,buf12_ptr,buf12d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf13_buf13d,LOCK_3_0_0_0,LOCK_3_0_1_0,buf13_ptr,buf13d_ptr,0,index, REL_WRITE);
    window_release(window_buf14_buf14d,LOCK_3_1_2_0,LOCK_3_1_3_4096,buf14_ptr,buf14d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_0_bounds > 0)
      --proc_3_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}