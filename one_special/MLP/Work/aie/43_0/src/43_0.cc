// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_0/src/43_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_0_0_0 48
#define LOCK_43_0_1_0 49
#define LOCK_43_1_0_4096 32
#define LOCK_43_1_1_0 33
#define LOCK_43_1_2_4096 34
#define LOCK_43_1_3_0 35

// Declare shared memory buffers
v4float buf492[256];
v4float buf492d[256];
v4float buf493[256];
v4float buf493d[256];
v4float buf494[256];
v4float buf494d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf492_buf492d[1];
  window_datatype * buf492_ptr = (window_datatype * )buf492;
  window_datatype * buf492d_ptr = (window_datatype * )buf492d;
  window_init(window_buf492_buf492d, 1, buf492, LOCK_43_0_0_0, buf492d, LOCK_43_0_1_0, 256, 256);
  window_internal window_buf493_buf493d[1];
  window_datatype * buf493_ptr = (window_datatype * )buf493;
  window_datatype * buf493d_ptr = (window_datatype * )buf493d;
  window_init(window_buf493_buf493d, 1, buf493, LOCK_43_1_0_4096, buf493d, LOCK_43_1_1_0, 256, 256);
  window_internal window_buf494_buf494d[1];
  window_datatype * buf494_ptr = (window_datatype * )buf494;
  window_datatype * buf494d_ptr = (window_datatype * )buf494d;
  window_init(window_buf494_buf494d, 1, buf494, LOCK_43_1_2_4096, buf494d, LOCK_43_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_0_bounds = sync_buffer[1];

  while (proc_43_0_bounds)
  {

    // Kernel call : i328:mm_kernel0
    window_acquire(window_buf492_buf492d,LOCK_43_0_0_0,LOCK_43_0_1_0,buf492_ptr,buf492d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf493_buf493d,LOCK_43_1_0_4096,LOCK_43_1_1_0,buf493_ptr,buf493d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf494_buf494d,LOCK_43_1_2_4096,LOCK_43_1_3_0,buf494_ptr,buf494d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf492_buf492d),get_input_window_float(window_buf493_buf493d),get_output_window_float(window_buf494_buf494d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf492_buf492d,LOCK_43_0_0_0,LOCK_43_0_1_0,buf492_ptr,buf492d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf493_buf493d,LOCK_43_1_0_4096,LOCK_43_1_1_0,buf493_ptr,buf493d_ptr,0,index, REL_WRITE);
    window_release(window_buf494_buf494d,LOCK_43_1_2_4096,LOCK_43_1_3_0,buf494_ptr,buf494d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_0_bounds > 0)
      --proc_43_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}