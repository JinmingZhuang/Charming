// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_4/src/18_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_4_0_0 48
#define LOCK_18_4_1_0 49
#define LOCK_18_5_0_0 32
#define LOCK_18_5_1_0 33
#define LOCK_18_5_2_0 34
#define LOCK_18_5_3_0 35

// Declare shared memory buffers
v4float buf948[256];
v4float buf948d[256];
v4float buf949[256];
v4float buf949d[256];
v4float buf950[256];
v4float buf950d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf948_buf948d[1];
  window_datatype * buf948_ptr = (window_datatype * )buf948;
  window_datatype * buf948d_ptr = (window_datatype * )buf948d;
  window_init(window_buf948_buf948d, 1, buf948, LOCK_18_4_0_0, buf948d, LOCK_18_4_1_0, 256, 256);
  window_internal window_buf949_buf949d[1];
  window_datatype * buf949_ptr = (window_datatype * )buf949;
  window_datatype * buf949d_ptr = (window_datatype * )buf949d;
  window_init(window_buf949_buf949d, 1, buf949, LOCK_18_5_0_0, buf949d, LOCK_18_5_1_0, 256, 256);
  window_internal window_buf950_buf950d[1];
  window_datatype * buf950_ptr = (window_datatype * )buf950;
  window_datatype * buf950d_ptr = (window_datatype * )buf950d;
  window_init(window_buf950_buf950d, 1, buf950, LOCK_18_5_2_0, buf950d, LOCK_18_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_4_bounds = sync_buffer[1];

  while (proc_18_4_bounds)
  {

    // Kernel call : i556:mm_kernel0
    window_acquire(window_buf948_buf948d,LOCK_18_4_0_0,LOCK_18_4_1_0,buf948_ptr,buf948d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf949_buf949d,LOCK_18_5_0_0,LOCK_18_5_1_0,buf949_ptr,buf949d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf950_buf950d,LOCK_18_5_2_0,LOCK_18_5_3_0,buf950_ptr,buf950d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf948_buf948d),get_input_window_float(window_buf949_buf949d),get_output_window_float(window_buf950_buf950d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf948_buf948d,LOCK_18_4_0_0,LOCK_18_4_1_0,buf948_ptr,buf948d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf949_buf949d,LOCK_18_5_0_0,LOCK_18_5_1_0,buf949_ptr,buf949d_ptr,0,index, REL_WRITE);
    window_release(window_buf950_buf950d,LOCK_18_5_2_0,LOCK_18_5_3_0,buf950_ptr,buf950d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_4_bounds > 0)
      --proc_18_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}