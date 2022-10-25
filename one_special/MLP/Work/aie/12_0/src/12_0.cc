// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_0/src/12_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_1_0_4096 32
#define LOCK_12_1_1_4096 33
#define LOCK_12_0_0_0 48
#define LOCK_12_0_1_0 49
#define LOCK_12_1_2_4096 34
#define LOCK_12_1_3_4096 35

// Declare shared memory buffers
v4float buf120[256];
v4float buf120d[256];
v4float buf121[256];
v4float buf121d[256];
v4float buf122[256];
v4float buf122d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf120_buf120d[1];
  window_datatype * buf120_ptr = (window_datatype * )buf120;
  window_datatype * buf120d_ptr = (window_datatype * )buf120d;
  window_init(window_buf120_buf120d, 1, buf120, LOCK_12_1_0_4096, buf120d, LOCK_12_1_1_4096, 256, 256);
  window_internal window_buf121_buf121d[1];
  window_datatype * buf121_ptr = (window_datatype * )buf121;
  window_datatype * buf121d_ptr = (window_datatype * )buf121d;
  window_init(window_buf121_buf121d, 1, buf121, LOCK_12_0_0_0, buf121d, LOCK_12_0_1_0, 256, 256);
  window_internal window_buf122_buf122d[1];
  window_datatype * buf122_ptr = (window_datatype * )buf122;
  window_datatype * buf122d_ptr = (window_datatype * )buf122d;
  window_init(window_buf122_buf122d, 1, buf122, LOCK_12_1_2_4096, buf122d, LOCK_12_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_0_bounds = sync_buffer[1];

  while (proc_12_0_bounds)
  {

    // Kernel call : i142:mm_kernel0
    window_acquire(window_buf120_buf120d,LOCK_12_1_0_4096,LOCK_12_1_1_4096,buf120_ptr,buf120d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf121_buf121d,LOCK_12_0_0_0,LOCK_12_0_1_0,buf121_ptr,buf121d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf122_buf122d,LOCK_12_1_2_4096,LOCK_12_1_3_4096,buf122_ptr,buf122d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf120_buf120d),get_input_window_float(window_buf121_buf121d),get_output_window_float(window_buf122_buf122d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf120_buf120d,LOCK_12_1_0_4096,LOCK_12_1_1_4096,buf120_ptr,buf120d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf121_buf121d,LOCK_12_0_0_0,LOCK_12_0_1_0,buf121_ptr,buf121d_ptr,0,index, REL_WRITE);
    window_release(window_buf122_buf122d,LOCK_12_1_2_4096,LOCK_12_1_3_4096,buf122_ptr,buf122d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_0_bounds > 0)
      --proc_12_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}