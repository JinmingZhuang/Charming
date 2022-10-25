// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_0/src/38_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_0_0_0 48
#define LOCK_38_0_1_0 49
#define LOCK_37_0_2_4096 18
#define LOCK_37_0_3_4096 19
#define LOCK_38_1_0_0 32
#define LOCK_38_1_1_0 33

// Declare shared memory buffers
v4float buf432[256];
v4float buf432d[256];
v4float buf433[256];
v4float buf433d[256];
v4float buf434[256];
v4float buf434d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf432_buf432d[1];
  window_datatype * buf432_ptr = (window_datatype * )buf432;
  window_datatype * buf432d_ptr = (window_datatype * )buf432d;
  window_init(window_buf432_buf432d, 1, buf432, LOCK_38_0_0_0, buf432d, LOCK_38_0_1_0, 256, 256);
  window_internal window_buf433_buf433d[1];
  window_datatype * buf433_ptr = (window_datatype * )buf433;
  window_datatype * buf433d_ptr = (window_datatype * )buf433d;
  window_init(window_buf433_buf433d, 1, buf433, LOCK_37_0_2_4096, buf433d, LOCK_37_0_3_4096, 256, 256);
  window_internal window_buf434_buf434d[1];
  window_datatype * buf434_ptr = (window_datatype * )buf434;
  window_datatype * buf434d_ptr = (window_datatype * )buf434d;
  window_init(window_buf434_buf434d, 1, buf434, LOCK_38_1_0_0, buf434d, LOCK_38_1_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_0_bounds = sync_buffer[1];

  while (proc_38_0_bounds)
  {

    // Kernel call : i298:mm_kernel0
    window_acquire(window_buf432_buf432d,LOCK_38_0_0_0,LOCK_38_0_1_0,buf432_ptr,buf432d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf433_buf433d,LOCK_37_0_2_4096,LOCK_37_0_3_4096,buf433_ptr,buf433d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf434_buf434d,LOCK_38_1_0_0,LOCK_38_1_1_0,buf434_ptr,buf434d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf432_buf432d),get_input_window_float(window_buf433_buf433d),get_output_window_float(window_buf434_buf434d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf432_buf432d,LOCK_38_0_0_0,LOCK_38_0_1_0,buf432_ptr,buf432d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf433_buf433d,LOCK_37_0_2_4096,LOCK_37_0_3_4096,buf433_ptr,buf433d_ptr,0,index, REL_WRITE);
    window_release(window_buf434_buf434d,LOCK_38_1_0_0,LOCK_38_1_1_0,buf434_ptr,buf434d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_0_bounds > 0)
      --proc_38_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}