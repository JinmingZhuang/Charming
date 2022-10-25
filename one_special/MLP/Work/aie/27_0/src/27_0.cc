// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_0/src/27_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_0_0_0 48
#define LOCK_27_0_1_0 49
#define LOCK_27_1_2_0 34
#define LOCK_27_1_3_4096 35
#define LOCK_27_1_4_0 36
#define LOCK_27_1_5_4096 37

// Declare shared memory buffers
v4float buf300[256];
v4float buf300d[256];
v4float buf301[256];
v4float buf301d[256];
v4float buf302[256];
v4float buf302d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf300_buf300d[1];
  window_datatype * buf300_ptr = (window_datatype * )buf300;
  window_datatype * buf300d_ptr = (window_datatype * )buf300d;
  window_init(window_buf300_buf300d, 1, buf300, LOCK_27_0_0_0, buf300d, LOCK_27_0_1_0, 256, 256);
  window_internal window_buf301_buf301d[1];
  window_datatype * buf301_ptr = (window_datatype * )buf301;
  window_datatype * buf301d_ptr = (window_datatype * )buf301d;
  window_init(window_buf301_buf301d, 1, buf301, LOCK_27_1_2_0, buf301d, LOCK_27_1_3_4096, 256, 256);
  window_internal window_buf302_buf302d[1];
  window_datatype * buf302_ptr = (window_datatype * )buf302;
  window_datatype * buf302d_ptr = (window_datatype * )buf302d;
  window_init(window_buf302_buf302d, 1, buf302, LOCK_27_1_4_0, buf302d, LOCK_27_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_0_bounds = sync_buffer[1];

  while (proc_27_0_bounds)
  {

    // Kernel call : i232:mm_kernel0
    window_acquire(window_buf300_buf300d,LOCK_27_0_0_0,LOCK_27_0_1_0,buf300_ptr,buf300d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf301_buf301d,LOCK_27_1_2_0,LOCK_27_1_3_4096,buf301_ptr,buf301d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf302_buf302d,LOCK_27_1_4_0,LOCK_27_1_5_4096,buf302_ptr,buf302d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf300_buf300d),get_input_window_float(window_buf301_buf301d),get_output_window_float(window_buf302_buf302d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf300_buf300d,LOCK_27_0_0_0,LOCK_27_0_1_0,buf300_ptr,buf300d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf301_buf301d,LOCK_27_1_2_0,LOCK_27_1_3_4096,buf301_ptr,buf301d_ptr,0,index, REL_WRITE);
    window_release(window_buf302_buf302d,LOCK_27_1_4_0,LOCK_27_1_5_4096,buf302_ptr,buf302d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_0_bounds > 0)
      --proc_27_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}