// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_1/src/49_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_1_4_0 20
#define LOCK_49_1_5_0 21
#define LOCK_49_0_2_4096 2
#define LOCK_49_0_3_4096 3
#define LOCK_49_1_2_4096 18
#define LOCK_49_1_3_4096 19
#define LOCK_49_1_6_4096 22
#define LOCK_49_1_7_4096 23

// Declare shared memory buffers
v4float buf566[256];
v4float buf566d[256];
v4float buf567[256];
v4float buf567d[256];
v4float buf568[256];
v4float buf568d[256];
v4float buf569[256];
v4float buf569d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf567_buf567d[1];
  window_datatype * buf567_ptr = (window_datatype * )buf567;
  window_datatype * buf567d_ptr = (window_datatype * )buf567d;
  window_init(window_buf567_buf567d, 1, buf567, LOCK_49_1_4_0, buf567d, LOCK_49_1_5_0, 256, 256);
  window_internal window_buf568_buf568d[1];
  window_datatype * buf568_ptr = (window_datatype * )buf568;
  window_datatype * buf568d_ptr = (window_datatype * )buf568d;
  window_init(window_buf568_buf568d, 1, buf568, LOCK_49_0_2_4096, buf568d, LOCK_49_0_3_4096, 256, 256);
  window_internal window_buf566_buf566d[1];
  window_datatype * buf566_ptr = (window_datatype * )buf566;
  window_datatype * buf566d_ptr = (window_datatype * )buf566d;
  window_init(window_buf566_buf566d, 1, buf566, LOCK_49_1_2_4096, buf566d, LOCK_49_1_3_4096, 256, 256);
  window_internal window_buf569_buf569d[1];
  window_datatype * buf569_ptr = (window_datatype * )buf569;
  window_datatype * buf569d_ptr = (window_datatype * )buf569d;
  window_init(window_buf569_buf569d, 1, buf569, LOCK_49_1_6_4096, buf569d, LOCK_49_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_1_bounds = sync_buffer[1];

  while (proc_49_1_bounds)
  {

    // Kernel call : i365:mm_kernel1
    window_acquire(window_buf567_buf567d,LOCK_49_1_4_0,LOCK_49_1_5_0,buf567_ptr,buf567d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf568_buf568d,LOCK_49_0_2_4096,LOCK_49_0_3_4096,buf568_ptr,buf568d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf566_buf566d,LOCK_49_1_2_4096,LOCK_49_1_3_4096,buf566_ptr,buf566d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf569_buf569d,LOCK_49_1_6_4096,LOCK_49_1_7_4096,buf569_ptr,buf569d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf567_buf567d),get_input_window_float(window_buf568_buf568d),get_input_window_float(window_buf566_buf566d),get_output_window_float(window_buf569_buf569d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf567_buf567d,LOCK_49_1_4_0,LOCK_49_1_5_0,buf567_ptr,buf567d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf568_buf568d,LOCK_49_0_2_4096,LOCK_49_0_3_4096,buf568_ptr,buf568d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf566_buf566d,LOCK_49_1_2_4096,LOCK_49_1_3_4096,buf566_ptr,buf566d_ptr,0,index, REL_WRITE);
    window_release(window_buf569_buf569d,LOCK_49_1_6_4096,LOCK_49_1_7_4096,buf569_ptr,buf569d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_1_bounds > 0)
      --proc_49_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}