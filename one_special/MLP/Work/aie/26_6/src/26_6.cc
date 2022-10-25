// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_6/src/26_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_26_7_0_0 32
#define LOCK_26_7_1_0 33
#define LOCK_26_5_6_0 6
#define LOCK_26_5_7_0 7
#define LOCK_26_5_4_4096 4
#define LOCK_26_5_5_4096 5
#define LOCK_26_6_4_4096 52
#define LOCK_26_6_5_4096 53

// Declare shared memory buffers
v4float buf857[256];
v4float buf857d[256];
v4float buf858[256];
v4float buf858d[256];
v4float buf859[256];
v4float buf859d[256];
v4float buf860[256];
v4float buf860d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf858_buf858d[1];
  window_datatype * buf858_ptr = (window_datatype * )buf858;
  window_datatype * buf858d_ptr = (window_datatype * )buf858d;
  window_init(window_buf858_buf858d, 1, buf858, LOCK_26_7_0_0, buf858d, LOCK_26_7_1_0, 256, 256);
  window_internal window_buf859_buf859d[1];
  window_datatype * buf859_ptr = (window_datatype * )buf859;
  window_datatype * buf859d_ptr = (window_datatype * )buf859d;
  window_init(window_buf859_buf859d, 1, buf859, LOCK_26_5_6_0, buf859d, LOCK_26_5_7_0, 256, 256);
  window_internal window_buf857_buf857d[1];
  window_datatype * buf857_ptr = (window_datatype * )buf857;
  window_datatype * buf857d_ptr = (window_datatype * )buf857d;
  window_init(window_buf857_buf857d, 1, buf857, LOCK_26_5_4_4096, buf857d, LOCK_26_5_5_4096, 256, 256);
  window_internal window_buf860_buf860d[1];
  window_datatype * buf860_ptr = (window_datatype * )buf860;
  window_datatype * buf860d_ptr = (window_datatype * )buf860d;
  window_init(window_buf860_buf860d, 1, buf860, LOCK_26_6_4_4096, buf860d, LOCK_26_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_6_bounds = sync_buffer[1];

  while (proc_26_6_bounds)
  {

    // Kernel call : i510:mm_kernel1
    window_acquire(window_buf858_buf858d,LOCK_26_7_0_0,LOCK_26_7_1_0,buf858_ptr,buf858d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf859_buf859d,LOCK_26_5_6_0,LOCK_26_5_7_0,buf859_ptr,buf859d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf857_buf857d,LOCK_26_5_4_4096,LOCK_26_5_5_4096,buf857_ptr,buf857d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf860_buf860d,LOCK_26_6_4_4096,LOCK_26_6_5_4096,buf860_ptr,buf860d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf858_buf858d),get_input_window_float(window_buf859_buf859d),get_input_window_float(window_buf857_buf857d),get_output_window_float(window_buf860_buf860d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf858_buf858d,LOCK_26_7_0_0,LOCK_26_7_1_0,buf858_ptr,buf858d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf859_buf859d,LOCK_26_5_6_0,LOCK_26_5_7_0,buf859_ptr,buf859d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf857_buf857d,LOCK_26_5_4_4096,LOCK_26_5_5_4096,buf857_ptr,buf857d_ptr,0,index, REL_WRITE);
    window_release(window_buf860_buf860d,LOCK_26_6_4_4096,LOCK_26_6_5_4096,buf860_ptr,buf860d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_6_bounds > 0)
      --proc_26_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}