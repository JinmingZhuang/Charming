// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_0/src/11_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_1_0_4096 32
#define LOCK_11_1_1_0 33
#define LOCK_11_0_0_0 48
#define LOCK_11_0_1_0 49
#define LOCK_11_1_2_4096 34
#define LOCK_11_1_3_4096 35

// Declare shared memory buffers
v4float buf108[256];
v4float buf108d[256];
v4float buf109[256];
v4float buf109d[256];
v4float buf110[256];
v4float buf110d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf108_buf108d[1];
  window_datatype * buf108_ptr = (window_datatype * )buf108;
  window_datatype * buf108d_ptr = (window_datatype * )buf108d;
  window_init(window_buf108_buf108d, 1, buf108, LOCK_11_1_0_4096, buf108d, LOCK_11_1_1_0, 256, 256);
  window_internal window_buf109_buf109d[1];
  window_datatype * buf109_ptr = (window_datatype * )buf109;
  window_datatype * buf109d_ptr = (window_datatype * )buf109d;
  window_init(window_buf109_buf109d, 1, buf109, LOCK_11_0_0_0, buf109d, LOCK_11_0_1_0, 256, 256);
  window_internal window_buf110_buf110d[1];
  window_datatype * buf110_ptr = (window_datatype * )buf110;
  window_datatype * buf110d_ptr = (window_datatype * )buf110d;
  window_init(window_buf110_buf110d, 1, buf110, LOCK_11_1_2_4096, buf110d, LOCK_11_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_0_bounds = sync_buffer[1];

  while (proc_11_0_bounds)
  {

    // Kernel call : i136:mm_kernel0
    window_acquire(window_buf108_buf108d,LOCK_11_1_0_4096,LOCK_11_1_1_0,buf108_ptr,buf108d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf109_buf109d,LOCK_11_0_0_0,LOCK_11_0_1_0,buf109_ptr,buf109d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf110_buf110d,LOCK_11_1_2_4096,LOCK_11_1_3_4096,buf110_ptr,buf110d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf108_buf108d),get_input_window_float(window_buf109_buf109d),get_output_window_float(window_buf110_buf110d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf108_buf108d,LOCK_11_1_0_4096,LOCK_11_1_1_0,buf108_ptr,buf108d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf109_buf109d,LOCK_11_0_0_0,LOCK_11_0_1_0,buf109_ptr,buf109d_ptr,0,index, REL_WRITE);
    window_release(window_buf110_buf110d,LOCK_11_1_2_4096,LOCK_11_1_3_4096,buf110_ptr,buf110d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_0_bounds > 0)
      --proc_11_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}