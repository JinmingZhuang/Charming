// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_0/src/4_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_0_0_0 48
#define LOCK_4_0_1_0 49
#define LOCK_3_0_2_4096 18
#define LOCK_3_0_3_4096 19
#define LOCK_4_1_2_4096 34
#define LOCK_4_1_3_4096 35

// Declare shared memory buffers
v4float buf24[256];
v4float buf24d[256];
v4float buf25[256];
v4float buf25d[256];
v4float buf26[256];
v4float buf26d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf24_buf24d[1];
  window_datatype * buf24_ptr = (window_datatype * )buf24;
  window_datatype * buf24d_ptr = (window_datatype * )buf24d;
  window_init(window_buf24_buf24d, 1, buf24, LOCK_4_0_0_0, buf24d, LOCK_4_0_1_0, 256, 256);
  window_internal window_buf25_buf25d[1];
  window_datatype * buf25_ptr = (window_datatype * )buf25;
  window_datatype * buf25d_ptr = (window_datatype * )buf25d;
  window_init(window_buf25_buf25d, 1, buf25, LOCK_3_0_2_4096, buf25d, LOCK_3_0_3_4096, 256, 256);
  window_internal window_buf26_buf26d[1];
  window_datatype * buf26_ptr = (window_datatype * )buf26;
  window_datatype * buf26d_ptr = (window_datatype * )buf26d;
  window_init(window_buf26_buf26d, 1, buf26, LOCK_4_1_2_4096, buf26d, LOCK_4_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_0_bounds = sync_buffer[1];

  while (proc_4_0_bounds)
  {

    // Kernel call : i94:mm_kernel0
    window_acquire(window_buf24_buf24d,LOCK_4_0_0_0,LOCK_4_0_1_0,buf24_ptr,buf24d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf25_buf25d,LOCK_3_0_2_4096,LOCK_3_0_3_4096,buf25_ptr,buf25d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf26_buf26d,LOCK_4_1_2_4096,LOCK_4_1_3_4096,buf26_ptr,buf26d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf24_buf24d),get_input_window_float(window_buf25_buf25d),get_output_window_float(window_buf26_buf26d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf24_buf24d,LOCK_4_0_0_0,LOCK_4_0_1_0,buf24_ptr,buf24d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf25_buf25d,LOCK_3_0_2_4096,LOCK_3_0_3_4096,buf25_ptr,buf25d_ptr,0,index, REL_WRITE);
    window_release(window_buf26_buf26d,LOCK_4_1_2_4096,LOCK_4_1_3_4096,buf26_ptr,buf26d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_0_bounds > 0)
      --proc_4_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}