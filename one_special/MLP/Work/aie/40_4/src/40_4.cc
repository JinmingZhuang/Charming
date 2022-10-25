// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_4/src/40_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_5_0_4096 32
#define LOCK_40_5_1_0 33
#define LOCK_40_4_2_4096 50
#define LOCK_40_4_3_4096 51
#define LOCK_40_5_2_0 34
#define LOCK_40_5_3_4096 35

// Declare shared memory buffers
v4float buf684[256];
v4float buf684d[256];
v4float buf685[256];
v4float buf685d[256];
v4float buf686[256];
v4float buf686d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf684_buf684d[1];
  window_datatype * buf684_ptr = (window_datatype * )buf684;
  window_datatype * buf684d_ptr = (window_datatype * )buf684d;
  window_init(window_buf684_buf684d, 1, buf684, LOCK_40_5_0_4096, buf684d, LOCK_40_5_1_0, 256, 256);
  window_internal window_buf685_buf685d[1];
  window_datatype * buf685_ptr = (window_datatype * )buf685;
  window_datatype * buf685d_ptr = (window_datatype * )buf685d;
  window_init(window_buf685_buf685d, 1, buf685, LOCK_40_4_2_4096, buf685d, LOCK_40_4_3_4096, 256, 256);
  window_internal window_buf686_buf686d[1];
  window_datatype * buf686_ptr = (window_datatype * )buf686;
  window_datatype * buf686d_ptr = (window_datatype * )buf686d;
  window_init(window_buf686_buf686d, 1, buf686, LOCK_40_5_2_0, buf686d, LOCK_40_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_4_bounds = sync_buffer[1];

  while (proc_40_4_bounds)
  {

    // Kernel call : i424:mm_kernel0
    window_acquire(window_buf684_buf684d,LOCK_40_5_0_4096,LOCK_40_5_1_0,buf684_ptr,buf684d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf685_buf685d,LOCK_40_4_2_4096,LOCK_40_4_3_4096,buf685_ptr,buf685d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf686_buf686d,LOCK_40_5_2_0,LOCK_40_5_3_4096,buf686_ptr,buf686d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf684_buf684d),get_input_window_float(window_buf685_buf685d),get_output_window_float(window_buf686_buf686d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf684_buf684d,LOCK_40_5_0_4096,LOCK_40_5_1_0,buf684_ptr,buf684d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf685_buf685d,LOCK_40_4_2_4096,LOCK_40_4_3_4096,buf685_ptr,buf685d_ptr,0,index, REL_WRITE);
    window_release(window_buf686_buf686d,LOCK_40_5_2_0,LOCK_40_5_3_4096,buf686_ptr,buf686d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_4_bounds > 0)
      --proc_40_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}