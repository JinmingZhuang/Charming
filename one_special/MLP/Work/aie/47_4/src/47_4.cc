// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_4/src/47_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_5_0_4096 32
#define LOCK_47_5_1_0 33
#define LOCK_47_4_0_0 48
#define LOCK_47_4_1_0 49
#define LOCK_47_5_2_0 34
#define LOCK_47_5_3_4096 35

// Declare shared memory buffers
v4float buf600[256];
v4float buf600d[256];
v4float buf601[256];
v4float buf601d[256];
v4float buf602[256];
v4float buf602d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf600_buf600d[1];
  window_datatype * buf600_ptr = (window_datatype * )buf600;
  window_datatype * buf600d_ptr = (window_datatype * )buf600d;
  window_init(window_buf600_buf600d, 1, buf600, LOCK_47_5_0_4096, buf600d, LOCK_47_5_1_0, 256, 256);
  window_internal window_buf601_buf601d[1];
  window_datatype * buf601_ptr = (window_datatype * )buf601;
  window_datatype * buf601d_ptr = (window_datatype * )buf601d;
  window_init(window_buf601_buf601d, 1, buf601, LOCK_47_4_0_0, buf601d, LOCK_47_4_1_0, 256, 256);
  window_internal window_buf602_buf602d[1];
  window_datatype * buf602_ptr = (window_datatype * )buf602;
  window_datatype * buf602d_ptr = (window_datatype * )buf602d;
  window_init(window_buf602_buf602d, 1, buf602, LOCK_47_5_2_0, buf602d, LOCK_47_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_4_bounds = sync_buffer[1];

  while (proc_47_4_bounds)
  {

    // Kernel call : i382:mm_kernel0
    window_acquire(window_buf600_buf600d,LOCK_47_5_0_4096,LOCK_47_5_1_0,buf600_ptr,buf600d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf601_buf601d,LOCK_47_4_0_0,LOCK_47_4_1_0,buf601_ptr,buf601d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf602_buf602d,LOCK_47_5_2_0,LOCK_47_5_3_4096,buf602_ptr,buf602d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf600_buf600d),get_input_window_float(window_buf601_buf601d),get_output_window_float(window_buf602_buf602d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf600_buf600d,LOCK_47_5_0_4096,LOCK_47_5_1_0,buf600_ptr,buf600d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf601_buf601d,LOCK_47_4_0_0,LOCK_47_4_1_0,buf601_ptr,buf601d_ptr,0,index, REL_WRITE);
    window_release(window_buf602_buf602d,LOCK_47_5_2_0,LOCK_47_5_3_4096,buf602_ptr,buf602d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_4_bounds > 0)
      --proc_47_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}