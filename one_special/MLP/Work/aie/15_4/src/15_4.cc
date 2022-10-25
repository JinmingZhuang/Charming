// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_4/src/15_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_3_6_4096 6
#define LOCK_15_3_7_4096 7
#define LOCK_15_4_0_0 48
#define LOCK_15_4_1_0 49
#define LOCK_15_5_0_4096 32
#define LOCK_15_5_1_4096 33

// Declare shared memory buffers
v4float buf984[256];
v4float buf984d[256];
v4float buf985[256];
v4float buf985d[256];
v4float buf986[256];
v4float buf986d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf984_buf984d[1];
  window_datatype * buf984_ptr = (window_datatype * )buf984;
  window_datatype * buf984d_ptr = (window_datatype * )buf984d;
  window_init(window_buf984_buf984d, 1, buf984, LOCK_15_3_6_4096, buf984d, LOCK_15_3_7_4096, 256, 256);
  window_internal window_buf985_buf985d[1];
  window_datatype * buf985_ptr = (window_datatype * )buf985;
  window_datatype * buf985d_ptr = (window_datatype * )buf985d;
  window_init(window_buf985_buf985d, 1, buf985, LOCK_15_4_0_0, buf985d, LOCK_15_4_1_0, 256, 256);
  window_internal window_buf986_buf986d[1];
  window_datatype * buf986_ptr = (window_datatype * )buf986;
  window_datatype * buf986d_ptr = (window_datatype * )buf986d;
  window_init(window_buf986_buf986d, 1, buf986, LOCK_15_5_0_4096, buf986d, LOCK_15_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_4_bounds = sync_buffer[1];

  while (proc_15_4_bounds)
  {

    // Kernel call : i574:mm_kernel0
    window_acquire(window_buf984_buf984d,LOCK_15_3_6_4096,LOCK_15_3_7_4096,buf984_ptr,buf984d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf985_buf985d,LOCK_15_4_0_0,LOCK_15_4_1_0,buf985_ptr,buf985d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf986_buf986d,LOCK_15_5_0_4096,LOCK_15_5_1_4096,buf986_ptr,buf986d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf984_buf984d),get_input_window_float(window_buf985_buf985d),get_output_window_float(window_buf986_buf986d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf984_buf984d,LOCK_15_3_6_4096,LOCK_15_3_7_4096,buf984_ptr,buf984d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf985_buf985d,LOCK_15_4_0_0,LOCK_15_4_1_0,buf985_ptr,buf985d_ptr,0,index, REL_WRITE);
    window_release(window_buf986_buf986d,LOCK_15_5_0_4096,LOCK_15_5_1_4096,buf986_ptr,buf986d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_4_bounds > 0)
      --proc_15_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}