// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_0/src/39_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_1_0_0 32
#define LOCK_39_1_1_0 33
#define LOCK_39_0_0_0 48
#define LOCK_39_0_1_0 49
#define LOCK_39_1_2_4096 34
#define LOCK_39_1_3_0 35

// Declare shared memory buffers
v4float buf444[256];
v4float buf444d[256];
v4float buf445[256];
v4float buf445d[256];
v4float buf446[256];
v4float buf446d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf444_buf444d[1];
  window_datatype * buf444_ptr = (window_datatype * )buf444;
  window_datatype * buf444d_ptr = (window_datatype * )buf444d;
  window_init(window_buf444_buf444d, 1, buf444, LOCK_39_1_0_0, buf444d, LOCK_39_1_1_0, 256, 256);
  window_internal window_buf445_buf445d[1];
  window_datatype * buf445_ptr = (window_datatype * )buf445;
  window_datatype * buf445d_ptr = (window_datatype * )buf445d;
  window_init(window_buf445_buf445d, 1, buf445, LOCK_39_0_0_0, buf445d, LOCK_39_0_1_0, 256, 256);
  window_internal window_buf446_buf446d[1];
  window_datatype * buf446_ptr = (window_datatype * )buf446;
  window_datatype * buf446d_ptr = (window_datatype * )buf446d;
  window_init(window_buf446_buf446d, 1, buf446, LOCK_39_1_2_4096, buf446d, LOCK_39_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_0_bounds = sync_buffer[1];

  while (proc_39_0_bounds)
  {

    // Kernel call : i304:mm_kernel0
    window_acquire(window_buf444_buf444d,LOCK_39_1_0_0,LOCK_39_1_1_0,buf444_ptr,buf444d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf445_buf445d,LOCK_39_0_0_0,LOCK_39_0_1_0,buf445_ptr,buf445d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf446_buf446d,LOCK_39_1_2_4096,LOCK_39_1_3_0,buf446_ptr,buf446d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf444_buf444d),get_input_window_float(window_buf445_buf445d),get_output_window_float(window_buf446_buf446d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf444_buf444d,LOCK_39_1_0_0,LOCK_39_1_1_0,buf444_ptr,buf444d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf445_buf445d,LOCK_39_0_0_0,LOCK_39_0_1_0,buf445_ptr,buf445d_ptr,0,index, REL_WRITE);
    window_release(window_buf446_buf446d,LOCK_39_1_2_4096,LOCK_39_1_3_0,buf446_ptr,buf446d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_0_bounds > 0)
      --proc_39_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}