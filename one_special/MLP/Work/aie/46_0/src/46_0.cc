// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_0/src/46_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_1_0_4096 32
#define LOCK_46_1_1_4096 33
#define LOCK_46_1_2_0 34
#define LOCK_46_1_3_0 35
#define LOCK_46_1_4_0 36
#define LOCK_46_1_5_4096 37

// Declare shared memory buffers
v4float buf528[256];
v4float buf528d[256];
v4float buf529[256];
v4float buf529d[256];
v4float buf530[256];
v4float buf530d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf528_buf528d[1];
  window_datatype * buf528_ptr = (window_datatype * )buf528;
  window_datatype * buf528d_ptr = (window_datatype * )buf528d;
  window_init(window_buf528_buf528d, 1, buf528, LOCK_46_1_0_4096, buf528d, LOCK_46_1_1_4096, 256, 256);
  window_internal window_buf529_buf529d[1];
  window_datatype * buf529_ptr = (window_datatype * )buf529;
  window_datatype * buf529d_ptr = (window_datatype * )buf529d;
  window_init(window_buf529_buf529d, 1, buf529, LOCK_46_1_2_0, buf529d, LOCK_46_1_3_0, 256, 256);
  window_internal window_buf530_buf530d[1];
  window_datatype * buf530_ptr = (window_datatype * )buf530;
  window_datatype * buf530d_ptr = (window_datatype * )buf530d;
  window_init(window_buf530_buf530d, 1, buf530, LOCK_46_1_4_0, buf530d, LOCK_46_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_0_bounds = sync_buffer[1];

  while (proc_46_0_bounds)
  {

    // Kernel call : i346:mm_kernel0
    window_acquire(window_buf528_buf528d,LOCK_46_1_0_4096,LOCK_46_1_1_4096,buf528_ptr,buf528d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf529_buf529d,LOCK_46_1_2_0,LOCK_46_1_3_0,buf529_ptr,buf529d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf530_buf530d,LOCK_46_1_4_0,LOCK_46_1_5_4096,buf530_ptr,buf530d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf528_buf528d),get_input_window_float(window_buf529_buf529d),get_output_window_float(window_buf530_buf530d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf528_buf528d,LOCK_46_1_0_4096,LOCK_46_1_1_4096,buf528_ptr,buf528d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf529_buf529d,LOCK_46_1_2_0,LOCK_46_1_3_0,buf529_ptr,buf529d_ptr,0,index, REL_WRITE);
    window_release(window_buf530_buf530d,LOCK_46_1_4_0,LOCK_46_1_5_4096,buf530_ptr,buf530d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_0_bounds > 0)
      --proc_46_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}