// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_4/src/6_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_5_0_4096 32
#define LOCK_6_5_1_4096 33
#define LOCK_6_3_6_4096 6
#define LOCK_6_3_7_0 7
#define LOCK_6_5_2_4096 34
#define LOCK_6_5_3_4096 35

// Declare shared memory buffers
v4float buf1092[256];
v4float buf1092d[256];
v4float buf1093[256];
v4float buf1093d[256];
v4float buf1094[256];
v4float buf1094d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1092_buf1092d[1];
  window_datatype * buf1092_ptr = (window_datatype * )buf1092;
  window_datatype * buf1092d_ptr = (window_datatype * )buf1092d;
  window_init(window_buf1092_buf1092d, 1, buf1092, LOCK_6_5_0_4096, buf1092d, LOCK_6_5_1_4096, 256, 256);
  window_internal window_buf1093_buf1093d[1];
  window_datatype * buf1093_ptr = (window_datatype * )buf1093;
  window_datatype * buf1093d_ptr = (window_datatype * )buf1093d;
  window_init(window_buf1093_buf1093d, 1, buf1093, LOCK_6_3_6_4096, buf1093d, LOCK_6_3_7_0, 256, 256);
  window_internal window_buf1094_buf1094d[1];
  window_datatype * buf1094_ptr = (window_datatype * )buf1094;
  window_datatype * buf1094d_ptr = (window_datatype * )buf1094d;
  window_init(window_buf1094_buf1094d, 1, buf1094, LOCK_6_5_2_4096, buf1094d, LOCK_6_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_4_bounds = sync_buffer[1];

  while (proc_6_4_bounds)
  {

    // Kernel call : i628:mm_kernel0
    window_acquire(window_buf1092_buf1092d,LOCK_6_5_0_4096,LOCK_6_5_1_4096,buf1092_ptr,buf1092d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1093_buf1093d,LOCK_6_3_6_4096,LOCK_6_3_7_0,buf1093_ptr,buf1093d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1094_buf1094d,LOCK_6_5_2_4096,LOCK_6_5_3_4096,buf1094_ptr,buf1094d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1092_buf1092d),get_input_window_float(window_buf1093_buf1093d),get_output_window_float(window_buf1094_buf1094d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1092_buf1092d,LOCK_6_5_0_4096,LOCK_6_5_1_4096,buf1092_ptr,buf1092d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1093_buf1093d,LOCK_6_3_6_4096,LOCK_6_3_7_0,buf1093_ptr,buf1093d_ptr,0,index, REL_WRITE);
    window_release(window_buf1094_buf1094d,LOCK_6_5_2_4096,LOCK_6_5_3_4096,buf1094_ptr,buf1094d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_4_bounds > 0)
      --proc_6_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}