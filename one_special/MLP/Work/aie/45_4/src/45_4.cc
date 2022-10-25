// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_4/src/45_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_45_4_2_4096 50
#define LOCK_45_4_3_4096 51
#define LOCK_45_3_2_4096 2
#define LOCK_45_3_3_4096 3
#define LOCK_45_5_0_0 32
#define LOCK_45_5_1_0 33

// Declare shared memory buffers
v4float buf624[256];
v4float buf624d[256];
v4float buf625[256];
v4float buf625d[256];
v4float buf626[256];
v4float buf626d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf624_buf624d[1];
  window_datatype * buf624_ptr = (window_datatype * )buf624;
  window_datatype * buf624d_ptr = (window_datatype * )buf624d;
  window_init(window_buf624_buf624d, 1, buf624, LOCK_45_4_2_4096, buf624d, LOCK_45_4_3_4096, 256, 256);
  window_internal window_buf625_buf625d[1];
  window_datatype * buf625_ptr = (window_datatype * )buf625;
  window_datatype * buf625d_ptr = (window_datatype * )buf625d;
  window_init(window_buf625_buf625d, 1, buf625, LOCK_45_3_2_4096, buf625d, LOCK_45_3_3_4096, 256, 256);
  window_internal window_buf626_buf626d[1];
  window_datatype * buf626_ptr = (window_datatype * )buf626;
  window_datatype * buf626d_ptr = (window_datatype * )buf626d;
  window_init(window_buf626_buf626d, 1, buf626, LOCK_45_5_0_0, buf626d, LOCK_45_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_4_bounds = sync_buffer[1];

  while (proc_45_4_bounds)
  {

    // Kernel call : i394:mm_kernel0
    window_acquire(window_buf624_buf624d,LOCK_45_4_2_4096,LOCK_45_4_3_4096,buf624_ptr,buf624d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf625_buf625d,LOCK_45_3_2_4096,LOCK_45_3_3_4096,buf625_ptr,buf625d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf626_buf626d,LOCK_45_5_0_0,LOCK_45_5_1_0,buf626_ptr,buf626d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf624_buf624d),get_input_window_float(window_buf625_buf625d),get_output_window_float(window_buf626_buf626d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf624_buf624d,LOCK_45_4_2_4096,LOCK_45_4_3_4096,buf624_ptr,buf624d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf625_buf625d,LOCK_45_3_2_4096,LOCK_45_3_3_4096,buf625_ptr,buf625d_ptr,0,index, REL_WRITE);
    window_release(window_buf626_buf626d,LOCK_45_5_0_0,LOCK_45_5_1_0,buf626_ptr,buf626d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_4_bounds > 0)
      --proc_45_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}