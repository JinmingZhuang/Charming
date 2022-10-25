// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_4/src/42_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_4_0_0 48
#define LOCK_42_4_1_0 49
#define LOCK_42_4_2_4096 50
#define LOCK_42_4_3_4096 51
#define LOCK_42_5_0_4096 32
#define LOCK_42_5_1_4096 33

// Declare shared memory buffers
v4float buf660[256];
v4float buf660d[256];
v4float buf661[256];
v4float buf661d[256];
v4float buf662[256];
v4float buf662d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf660_buf660d[1];
  window_datatype * buf660_ptr = (window_datatype * )buf660;
  window_datatype * buf660d_ptr = (window_datatype * )buf660d;
  window_init(window_buf660_buf660d, 1, buf660, LOCK_42_4_0_0, buf660d, LOCK_42_4_1_0, 256, 256);
  window_internal window_buf661_buf661d[1];
  window_datatype * buf661_ptr = (window_datatype * )buf661;
  window_datatype * buf661d_ptr = (window_datatype * )buf661d;
  window_init(window_buf661_buf661d, 1, buf661, LOCK_42_4_2_4096, buf661d, LOCK_42_4_3_4096, 256, 256);
  window_internal window_buf662_buf662d[1];
  window_datatype * buf662_ptr = (window_datatype * )buf662;
  window_datatype * buf662d_ptr = (window_datatype * )buf662d;
  window_init(window_buf662_buf662d, 1, buf662, LOCK_42_5_0_4096, buf662d, LOCK_42_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_4_bounds = sync_buffer[1];

  while (proc_42_4_bounds)
  {

    // Kernel call : i412:mm_kernel0
    window_acquire(window_buf660_buf660d,LOCK_42_4_0_0,LOCK_42_4_1_0,buf660_ptr,buf660d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf661_buf661d,LOCK_42_4_2_4096,LOCK_42_4_3_4096,buf661_ptr,buf661d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf662_buf662d,LOCK_42_5_0_4096,LOCK_42_5_1_4096,buf662_ptr,buf662d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf660_buf660d),get_input_window_float(window_buf661_buf661d),get_output_window_float(window_buf662_buf662d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf660_buf660d,LOCK_42_4_0_0,LOCK_42_4_1_0,buf660_ptr,buf660d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf661_buf661d,LOCK_42_4_2_4096,LOCK_42_4_3_4096,buf661_ptr,buf661d_ptr,0,index, REL_WRITE);
    window_release(window_buf662_buf662d,LOCK_42_5_0_4096,LOCK_42_5_1_4096,buf662_ptr,buf662d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_4_bounds > 0)
      --proc_42_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}