// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_4/src/13_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_4_0_0 16
#define LOCK_12_4_1_0 17
#define LOCK_13_4_2_4096 50
#define LOCK_13_4_3_4096 51
#define LOCK_13_5_0_0 32
#define LOCK_13_5_1_4096 33

// Declare shared memory buffers
v4float buf1008[256];
v4float buf1008d[256];
v4float buf1009[256];
v4float buf1009d[256];
v4float buf1010[256];
v4float buf1010d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1008_buf1008d[1];
  window_datatype * buf1008_ptr = (window_datatype * )buf1008;
  window_datatype * buf1008d_ptr = (window_datatype * )buf1008d;
  window_init(window_buf1008_buf1008d, 1, buf1008, LOCK_12_4_0_0, buf1008d, LOCK_12_4_1_0, 256, 256);
  window_internal window_buf1009_buf1009d[1];
  window_datatype * buf1009_ptr = (window_datatype * )buf1009;
  window_datatype * buf1009d_ptr = (window_datatype * )buf1009d;
  window_init(window_buf1009_buf1009d, 1, buf1009, LOCK_13_4_2_4096, buf1009d, LOCK_13_4_3_4096, 256, 256);
  window_internal window_buf1010_buf1010d[1];
  window_datatype * buf1010_ptr = (window_datatype * )buf1010;
  window_datatype * buf1010d_ptr = (window_datatype * )buf1010d;
  window_init(window_buf1010_buf1010d, 1, buf1010, LOCK_13_5_0_0, buf1010d, LOCK_13_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_4_bounds = sync_buffer[1];

  while (proc_13_4_bounds)
  {

    // Kernel call : i586:mm_kernel0
    window_acquire(window_buf1008_buf1008d,LOCK_12_4_0_0,LOCK_12_4_1_0,buf1008_ptr,buf1008d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1009_buf1009d,LOCK_13_4_2_4096,LOCK_13_4_3_4096,buf1009_ptr,buf1009d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1010_buf1010d,LOCK_13_5_0_0,LOCK_13_5_1_4096,buf1010_ptr,buf1010d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1008_buf1008d),get_input_window_float(window_buf1009_buf1009d),get_output_window_float(window_buf1010_buf1010d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1008_buf1008d,LOCK_12_4_0_0,LOCK_12_4_1_0,buf1008_ptr,buf1008d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1009_buf1009d,LOCK_13_4_2_4096,LOCK_13_4_3_4096,buf1009_ptr,buf1009d_ptr,0,index, REL_WRITE);
    window_release(window_buf1010_buf1010d,LOCK_13_5_0_0,LOCK_13_5_1_4096,buf1010_ptr,buf1010d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_4_bounds > 0)
      --proc_13_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}