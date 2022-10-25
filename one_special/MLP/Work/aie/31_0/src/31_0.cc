// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_0/src/31_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_1_0_0 32
#define LOCK_31_1_1_0 33
#define LOCK_31_0_0_0 48
#define LOCK_31_0_1_0 49
#define LOCK_31_1_2_4096 34
#define LOCK_31_1_3_4096 35

// Declare shared memory buffers
v4float buf348[256];
v4float buf348d[256];
v4float buf349[256];
v4float buf349d[256];
v4float buf350[256];
v4float buf350d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf348_buf348d[1];
  window_datatype * buf348_ptr = (window_datatype * )buf348;
  window_datatype * buf348d_ptr = (window_datatype * )buf348d;
  window_init(window_buf348_buf348d, 1, buf348, LOCK_31_1_0_0, buf348d, LOCK_31_1_1_0, 256, 256);
  window_internal window_buf349_buf349d[1];
  window_datatype * buf349_ptr = (window_datatype * )buf349;
  window_datatype * buf349d_ptr = (window_datatype * )buf349d;
  window_init(window_buf349_buf349d, 1, buf349, LOCK_31_0_0_0, buf349d, LOCK_31_0_1_0, 256, 256);
  window_internal window_buf350_buf350d[1];
  window_datatype * buf350_ptr = (window_datatype * )buf350;
  window_datatype * buf350d_ptr = (window_datatype * )buf350d;
  window_init(window_buf350_buf350d, 1, buf350, LOCK_31_1_2_4096, buf350d, LOCK_31_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_0_bounds = sync_buffer[1];

  while (proc_31_0_bounds)
  {

    // Kernel call : i256:mm_kernel0
    window_acquire(window_buf348_buf348d,LOCK_31_1_0_0,LOCK_31_1_1_0,buf348_ptr,buf348d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf349_buf349d,LOCK_31_0_0_0,LOCK_31_0_1_0,buf349_ptr,buf349d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf350_buf350d,LOCK_31_1_2_4096,LOCK_31_1_3_4096,buf350_ptr,buf350d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf348_buf348d),get_input_window_float(window_buf349_buf349d),get_output_window_float(window_buf350_buf350d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf348_buf348d,LOCK_31_1_0_0,LOCK_31_1_1_0,buf348_ptr,buf348d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf349_buf349d,LOCK_31_0_0_0,LOCK_31_0_1_0,buf349_ptr,buf349d_ptr,0,index, REL_WRITE);
    window_release(window_buf350_buf350d,LOCK_31_1_2_4096,LOCK_31_1_3_4096,buf350_ptr,buf350d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_0_bounds > 0)
      --proc_31_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}