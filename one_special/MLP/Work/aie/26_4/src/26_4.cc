// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_4/src/26_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_4_2_4096 18
#define LOCK_25_4_3_4096 19
#define LOCK_26_3_2_4096 2
#define LOCK_26_3_3_4096 3
#define LOCK_26_5_0_0 32
#define LOCK_26_5_1_4096 33

// Declare shared memory buffers
v4float buf852[256];
v4float buf852d[256];
v4float buf853[256];
v4float buf853d[256];
v4float buf854[256];
v4float buf854d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf852_buf852d[1];
  window_datatype * buf852_ptr = (window_datatype * )buf852;
  window_datatype * buf852d_ptr = (window_datatype * )buf852d;
  window_init(window_buf852_buf852d, 1, buf852, LOCK_25_4_2_4096, buf852d, LOCK_25_4_3_4096, 256, 256);
  window_internal window_buf853_buf853d[1];
  window_datatype * buf853_ptr = (window_datatype * )buf853;
  window_datatype * buf853d_ptr = (window_datatype * )buf853d;
  window_init(window_buf853_buf853d, 1, buf853, LOCK_26_3_2_4096, buf853d, LOCK_26_3_3_4096, 256, 256);
  window_internal window_buf854_buf854d[1];
  window_datatype * buf854_ptr = (window_datatype * )buf854;
  window_datatype * buf854d_ptr = (window_datatype * )buf854d;
  window_init(window_buf854_buf854d, 1, buf854, LOCK_26_5_0_0, buf854d, LOCK_26_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_4_bounds = sync_buffer[1];

  while (proc_26_4_bounds)
  {

    // Kernel call : i508:mm_kernel0
    window_acquire(window_buf852_buf852d,LOCK_25_4_2_4096,LOCK_25_4_3_4096,buf852_ptr,buf852d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf853_buf853d,LOCK_26_3_2_4096,LOCK_26_3_3_4096,buf853_ptr,buf853d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf854_buf854d,LOCK_26_5_0_0,LOCK_26_5_1_4096,buf854_ptr,buf854d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf852_buf852d),get_input_window_float(window_buf853_buf853d),get_output_window_float(window_buf854_buf854d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf852_buf852d,LOCK_25_4_2_4096,LOCK_25_4_3_4096,buf852_ptr,buf852d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf853_buf853d,LOCK_26_3_2_4096,LOCK_26_3_3_4096,buf853_ptr,buf853d_ptr,0,index, REL_WRITE);
    window_release(window_buf854_buf854d,LOCK_26_5_0_0,LOCK_26_5_1_4096,buf854_ptr,buf854d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_4_bounds > 0)
      --proc_26_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}