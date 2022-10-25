// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_0/src/16_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_16_1_0_0 32
#define LOCK_16_1_1_4096 33
#define LOCK_16_1_2_0 34
#define LOCK_16_1_3_0 35
#define LOCK_16_1_4_4096 36
#define LOCK_16_1_5_4096 37

// Declare shared memory buffers
v4float buf168[256];
v4float buf168d[256];
v4float buf169[256];
v4float buf169d[256];
v4float buf170[256];
v4float buf170d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf168_buf168d[1];
  window_datatype * buf168_ptr = (window_datatype * )buf168;
  window_datatype * buf168d_ptr = (window_datatype * )buf168d;
  window_init(window_buf168_buf168d, 1, buf168, LOCK_16_1_0_0, buf168d, LOCK_16_1_1_4096, 256, 256);
  window_internal window_buf169_buf169d[1];
  window_datatype * buf169_ptr = (window_datatype * )buf169;
  window_datatype * buf169d_ptr = (window_datatype * )buf169d;
  window_init(window_buf169_buf169d, 1, buf169, LOCK_16_1_2_0, buf169d, LOCK_16_1_3_0, 256, 256);
  window_internal window_buf170_buf170d[1];
  window_datatype * buf170_ptr = (window_datatype * )buf170;
  window_datatype * buf170d_ptr = (window_datatype * )buf170d;
  window_init(window_buf170_buf170d, 1, buf170, LOCK_16_1_4_4096, buf170d, LOCK_16_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_0_bounds = sync_buffer[1];

  while (proc_16_0_bounds)
  {

    // Kernel call : i166:mm_kernel0
    window_acquire(window_buf168_buf168d,LOCK_16_1_0_0,LOCK_16_1_1_4096,buf168_ptr,buf168d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf169_buf169d,LOCK_16_1_2_0,LOCK_16_1_3_0,buf169_ptr,buf169d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf170_buf170d,LOCK_16_1_4_4096,LOCK_16_1_5_4096,buf170_ptr,buf170d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf168_buf168d),get_input_window_float(window_buf169_buf169d),get_output_window_float(window_buf170_buf170d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf168_buf168d,LOCK_16_1_0_0,LOCK_16_1_1_4096,buf168_ptr,buf168d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf169_buf169d,LOCK_16_1_2_0,LOCK_16_1_3_0,buf169_ptr,buf169d_ptr,0,index, REL_WRITE);
    window_release(window_buf170_buf170d,LOCK_16_1_4_4096,LOCK_16_1_5_4096,buf170_ptr,buf170d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_0_bounds > 0)
      --proc_16_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}