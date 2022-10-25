// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_0/src/48_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_1_0_4096 32
#define LOCK_48_1_1_0 33
#define LOCK_48_1_2_4096 34
#define LOCK_48_1_3_4096 35
#define LOCK_48_1_4_4096 36
#define LOCK_48_1_5_0 37

// Declare shared memory buffers
v4float buf552[256];
v4float buf552d[256];
v4float buf553[256];
v4float buf553d[256];
v4float buf554[256];
v4float buf554d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf552_buf552d[1];
  window_datatype * buf552_ptr = (window_datatype * )buf552;
  window_datatype * buf552d_ptr = (window_datatype * )buf552d;
  window_init(window_buf552_buf552d, 1, buf552, LOCK_48_1_0_4096, buf552d, LOCK_48_1_1_0, 256, 256);
  window_internal window_buf553_buf553d[1];
  window_datatype * buf553_ptr = (window_datatype * )buf553;
  window_datatype * buf553d_ptr = (window_datatype * )buf553d;
  window_init(window_buf553_buf553d, 1, buf553, LOCK_48_1_2_4096, buf553d, LOCK_48_1_3_4096, 256, 256);
  window_internal window_buf554_buf554d[1];
  window_datatype * buf554_ptr = (window_datatype * )buf554;
  window_datatype * buf554d_ptr = (window_datatype * )buf554d;
  window_init(window_buf554_buf554d, 1, buf554, LOCK_48_1_4_4096, buf554d, LOCK_48_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_0_bounds = sync_buffer[1];

  while (proc_48_0_bounds)
  {

    // Kernel call : i358:mm_kernel0
    window_acquire(window_buf552_buf552d,LOCK_48_1_0_4096,LOCK_48_1_1_0,buf552_ptr,buf552d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf553_buf553d,LOCK_48_1_2_4096,LOCK_48_1_3_4096,buf553_ptr,buf553d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf554_buf554d,LOCK_48_1_4_4096,LOCK_48_1_5_0,buf554_ptr,buf554d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf552_buf552d),get_input_window_float(window_buf553_buf553d),get_output_window_float(window_buf554_buf554d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf552_buf552d,LOCK_48_1_0_4096,LOCK_48_1_1_0,buf552_ptr,buf552d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf553_buf553d,LOCK_48_1_2_4096,LOCK_48_1_3_4096,buf553_ptr,buf553d_ptr,0,index, REL_WRITE);
    window_release(window_buf554_buf554d,LOCK_48_1_4_4096,LOCK_48_1_5_0,buf554_ptr,buf554d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_0_bounds > 0)
      --proc_48_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}