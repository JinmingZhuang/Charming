// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_0/src/32_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_32_0_0_0 48
#define LOCK_32_0_1_0 49
#define LOCK_31_0_2_4096 18
#define LOCK_31_0_3_4096 19
#define LOCK_32_1_4_4096 36
#define LOCK_32_1_5_4096 37

// Declare shared memory buffers
v4float buf360[256];
v4float buf360d[256];
v4float buf361[256];
v4float buf361d[256];
v4float buf362[256];
v4float buf362d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf360_buf360d[1];
  window_datatype * buf360_ptr = (window_datatype * )buf360;
  window_datatype * buf360d_ptr = (window_datatype * )buf360d;
  window_init(window_buf360_buf360d, 1, buf360, LOCK_32_0_0_0, buf360d, LOCK_32_0_1_0, 256, 256);
  window_internal window_buf361_buf361d[1];
  window_datatype * buf361_ptr = (window_datatype * )buf361;
  window_datatype * buf361d_ptr = (window_datatype * )buf361d;
  window_init(window_buf361_buf361d, 1, buf361, LOCK_31_0_2_4096, buf361d, LOCK_31_0_3_4096, 256, 256);
  window_internal window_buf362_buf362d[1];
  window_datatype * buf362_ptr = (window_datatype * )buf362;
  window_datatype * buf362d_ptr = (window_datatype * )buf362d;
  window_init(window_buf362_buf362d, 1, buf362, LOCK_32_1_4_4096, buf362d, LOCK_32_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_0_bounds = sync_buffer[1];

  while (proc_32_0_bounds)
  {

    // Kernel call : i262:mm_kernel0
    window_acquire(window_buf360_buf360d,LOCK_32_0_0_0,LOCK_32_0_1_0,buf360_ptr,buf360d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf361_buf361d,LOCK_31_0_2_4096,LOCK_31_0_3_4096,buf361_ptr,buf361d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf362_buf362d,LOCK_32_1_4_4096,LOCK_32_1_5_4096,buf362_ptr,buf362d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf360_buf360d),get_input_window_float(window_buf361_buf361d),get_output_window_float(window_buf362_buf362d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf360_buf360d,LOCK_32_0_0_0,LOCK_32_0_1_0,buf360_ptr,buf360d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf361_buf361d,LOCK_31_0_2_4096,LOCK_31_0_3_4096,buf361_ptr,buf361d_ptr,0,index, REL_WRITE);
    window_release(window_buf362_buf362d,LOCK_32_1_4_4096,LOCK_32_1_5_4096,buf362_ptr,buf362d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_0_bounds > 0)
      --proc_32_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}