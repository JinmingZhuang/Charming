// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_0/src/36_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_0_2_4096 18
#define LOCK_35_0_3_4096 19
#define LOCK_36_0_0_0 48
#define LOCK_36_0_1_0 49
#define LOCK_36_1_2_0 34
#define LOCK_36_1_3_4096 35

// Declare shared memory buffers
v4float buf408[256];
v4float buf408d[256];
v4float buf409[256];
v4float buf409d[256];
v4float buf410[256];
v4float buf410d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf408_buf408d[1];
  window_datatype * buf408_ptr = (window_datatype * )buf408;
  window_datatype * buf408d_ptr = (window_datatype * )buf408d;
  window_init(window_buf408_buf408d, 1, buf408, LOCK_35_0_2_4096, buf408d, LOCK_35_0_3_4096, 256, 256);
  window_internal window_buf409_buf409d[1];
  window_datatype * buf409_ptr = (window_datatype * )buf409;
  window_datatype * buf409d_ptr = (window_datatype * )buf409d;
  window_init(window_buf409_buf409d, 1, buf409, LOCK_36_0_0_0, buf409d, LOCK_36_0_1_0, 256, 256);
  window_internal window_buf410_buf410d[1];
  window_datatype * buf410_ptr = (window_datatype * )buf410;
  window_datatype * buf410d_ptr = (window_datatype * )buf410d;
  window_init(window_buf410_buf410d, 1, buf410, LOCK_36_1_2_0, buf410d, LOCK_36_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_0_bounds = sync_buffer[1];

  while (proc_36_0_bounds)
  {

    // Kernel call : i286:mm_kernel0
    window_acquire(window_buf408_buf408d,LOCK_35_0_2_4096,LOCK_35_0_3_4096,buf408_ptr,buf408d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf409_buf409d,LOCK_36_0_0_0,LOCK_36_0_1_0,buf409_ptr,buf409d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf410_buf410d,LOCK_36_1_2_0,LOCK_36_1_3_4096,buf410_ptr,buf410d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf408_buf408d),get_input_window_float(window_buf409_buf409d),get_output_window_float(window_buf410_buf410d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf408_buf408d,LOCK_35_0_2_4096,LOCK_35_0_3_4096,buf408_ptr,buf408d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf409_buf409d,LOCK_36_0_0_0,LOCK_36_0_1_0,buf409_ptr,buf409d_ptr,0,index, REL_WRITE);
    window_release(window_buf410_buf410d,LOCK_36_1_2_0,LOCK_36_1_3_4096,buf410_ptr,buf410d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_0_bounds > 0)
      --proc_36_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}