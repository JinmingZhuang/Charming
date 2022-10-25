// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_1/src/29_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_2_0_0 32
#define LOCK_29_2_1_0 33
#define LOCK_30_1_0_0 48
#define LOCK_30_1_1_0 49
#define LOCK_29_1_2_4096 18
#define LOCK_29_1_3_0 19
#define LOCK_29_1_4_0 20
#define LOCK_29_1_5_0 21

// Declare shared memory buffers
v4float buf326[256];
v4float buf326d[256];
v4float buf327[256];
v4float buf327d[256];
v4float buf328[256];
v4float buf328d[256];
v4float buf329[256];
v4float buf329d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf327_buf327d[1];
  window_datatype * buf327_ptr = (window_datatype * )buf327;
  window_datatype * buf327d_ptr = (window_datatype * )buf327d;
  window_init(window_buf327_buf327d, 1, buf327, LOCK_29_2_0_0, buf327d, LOCK_29_2_1_0, 256, 256);
  window_internal window_buf328_buf328d[1];
  window_datatype * buf328_ptr = (window_datatype * )buf328;
  window_datatype * buf328d_ptr = (window_datatype * )buf328d;
  window_init(window_buf328_buf328d, 1, buf328, LOCK_30_1_0_0, buf328d, LOCK_30_1_1_0, 256, 256);
  window_internal window_buf326_buf326d[1];
  window_datatype * buf326_ptr = (window_datatype * )buf326;
  window_datatype * buf326d_ptr = (window_datatype * )buf326d;
  window_init(window_buf326_buf326d, 1, buf326, LOCK_29_1_2_4096, buf326d, LOCK_29_1_3_0, 256, 256);
  window_internal window_buf329_buf329d[1];
  window_datatype * buf329_ptr = (window_datatype * )buf329;
  window_datatype * buf329d_ptr = (window_datatype * )buf329d;
  window_init(window_buf329_buf329d, 1, buf329, LOCK_29_1_4_0, buf329d, LOCK_29_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_1_bounds = sync_buffer[1];

  while (proc_29_1_bounds)
  {

    // Kernel call : i245:mm_kernel1
    window_acquire(window_buf327_buf327d,LOCK_29_2_0_0,LOCK_29_2_1_0,buf327_ptr,buf327d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf328_buf328d,LOCK_30_1_0_0,LOCK_30_1_1_0,buf328_ptr,buf328d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf326_buf326d,LOCK_29_1_2_4096,LOCK_29_1_3_0,buf326_ptr,buf326d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf329_buf329d,LOCK_29_1_4_0,LOCK_29_1_5_0,buf329_ptr,buf329d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf327_buf327d),get_input_window_float(window_buf328_buf328d),get_input_window_float(window_buf326_buf326d),get_output_window_float(window_buf329_buf329d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf327_buf327d,LOCK_29_2_0_0,LOCK_29_2_1_0,buf327_ptr,buf327d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf328_buf328d,LOCK_30_1_0_0,LOCK_30_1_1_0,buf328_ptr,buf328d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf326_buf326d,LOCK_29_1_2_4096,LOCK_29_1_3_0,buf326_ptr,buf326d_ptr,0,index, REL_WRITE);
    window_release(window_buf329_buf329d,LOCK_29_1_4_0,LOCK_29_1_5_0,buf329_ptr,buf329d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_1_bounds > 0)
      --proc_29_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}