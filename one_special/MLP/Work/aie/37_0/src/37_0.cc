// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_0/src/37_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_1_0_4096 32
#define LOCK_37_1_1_4096 33
#define LOCK_37_1_2_0 34
#define LOCK_37_1_3_4096 35
#define LOCK_37_1_4_0 36
#define LOCK_37_1_5_0 37

// Declare shared memory buffers
v4float buf420[256];
v4float buf420d[256];
v4float buf421[256];
v4float buf421d[256];
v4float buf422[256];
v4float buf422d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf420_buf420d[1];
  window_datatype * buf420_ptr = (window_datatype * )buf420;
  window_datatype * buf420d_ptr = (window_datatype * )buf420d;
  window_init(window_buf420_buf420d, 1, buf420, LOCK_37_1_0_4096, buf420d, LOCK_37_1_1_4096, 256, 256);
  window_internal window_buf421_buf421d[1];
  window_datatype * buf421_ptr = (window_datatype * )buf421;
  window_datatype * buf421d_ptr = (window_datatype * )buf421d;
  window_init(window_buf421_buf421d, 1, buf421, LOCK_37_1_2_0, buf421d, LOCK_37_1_3_4096, 256, 256);
  window_internal window_buf422_buf422d[1];
  window_datatype * buf422_ptr = (window_datatype * )buf422;
  window_datatype * buf422d_ptr = (window_datatype * )buf422d;
  window_init(window_buf422_buf422d, 1, buf422, LOCK_37_1_4_0, buf422d, LOCK_37_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_0_bounds = sync_buffer[1];

  while (proc_37_0_bounds)
  {

    // Kernel call : i292:mm_kernel0
    window_acquire(window_buf420_buf420d,LOCK_37_1_0_4096,LOCK_37_1_1_4096,buf420_ptr,buf420d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf421_buf421d,LOCK_37_1_2_0,LOCK_37_1_3_4096,buf421_ptr,buf421d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf422_buf422d,LOCK_37_1_4_0,LOCK_37_1_5_0,buf422_ptr,buf422d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf420_buf420d),get_input_window_float(window_buf421_buf421d),get_output_window_float(window_buf422_buf422d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf420_buf420d,LOCK_37_1_0_4096,LOCK_37_1_1_4096,buf420_ptr,buf420d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf421_buf421d,LOCK_37_1_2_0,LOCK_37_1_3_4096,buf421_ptr,buf421d_ptr,0,index, REL_WRITE);
    window_release(window_buf422_buf422d,LOCK_37_1_4_0,LOCK_37_1_5_0,buf422_ptr,buf422d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_0_bounds > 0)
      --proc_37_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}