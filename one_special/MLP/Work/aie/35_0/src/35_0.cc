// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_0/src/35_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_0_0_0 48
#define LOCK_35_0_1_0 49
#define LOCK_34_0_2_4096 18
#define LOCK_34_0_3_4096 19
#define LOCK_35_1_2_4096 34
#define LOCK_35_1_3_4096 35

// Declare shared memory buffers
v4float buf396[256];
v4float buf396d[256];
v4float buf397[256];
v4float buf397d[256];
v4float buf398[256];
v4float buf398d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf396_buf396d[1];
  window_datatype * buf396_ptr = (window_datatype * )buf396;
  window_datatype * buf396d_ptr = (window_datatype * )buf396d;
  window_init(window_buf396_buf396d, 1, buf396, LOCK_35_0_0_0, buf396d, LOCK_35_0_1_0, 256, 256);
  window_internal window_buf397_buf397d[1];
  window_datatype * buf397_ptr = (window_datatype * )buf397;
  window_datatype * buf397d_ptr = (window_datatype * )buf397d;
  window_init(window_buf397_buf397d, 1, buf397, LOCK_34_0_2_4096, buf397d, LOCK_34_0_3_4096, 256, 256);
  window_internal window_buf398_buf398d[1];
  window_datatype * buf398_ptr = (window_datatype * )buf398;
  window_datatype * buf398d_ptr = (window_datatype * )buf398d;
  window_init(window_buf398_buf398d, 1, buf398, LOCK_35_1_2_4096, buf398d, LOCK_35_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_0_bounds = sync_buffer[1];

  while (proc_35_0_bounds)
  {

    // Kernel call : i280:mm_kernel0
    window_acquire(window_buf396_buf396d,LOCK_35_0_0_0,LOCK_35_0_1_0,buf396_ptr,buf396d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf397_buf397d,LOCK_34_0_2_4096,LOCK_34_0_3_4096,buf397_ptr,buf397d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf398_buf398d,LOCK_35_1_2_4096,LOCK_35_1_3_4096,buf398_ptr,buf398d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf396_buf396d),get_input_window_float(window_buf397_buf397d),get_output_window_float(window_buf398_buf398d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf396_buf396d,LOCK_35_0_0_0,LOCK_35_0_1_0,buf396_ptr,buf396d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf397_buf397d,LOCK_34_0_2_4096,LOCK_34_0_3_4096,buf397_ptr,buf397d_ptr,0,index, REL_WRITE);
    window_release(window_buf398_buf398d,LOCK_35_1_2_4096,LOCK_35_1_3_4096,buf398_ptr,buf398d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_0_bounds > 0)
      --proc_35_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}