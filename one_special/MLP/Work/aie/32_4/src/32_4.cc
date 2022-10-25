// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_4/src/32_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_32_3_2_4096 2
#define LOCK_32_3_3_4096 3
#define LOCK_32_5_0_0 32
#define LOCK_32_5_1_4096 33
#define LOCK_32_5_2_0 34
#define LOCK_32_5_3_4096 35

// Declare shared memory buffers
v4float buf780[256];
v4float buf780d[256];
v4float buf781[256];
v4float buf781d[256];
v4float buf782[256];
v4float buf782d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf780_buf780d[1];
  window_datatype * buf780_ptr = (window_datatype * )buf780;
  window_datatype * buf780d_ptr = (window_datatype * )buf780d;
  window_init(window_buf780_buf780d, 1, buf780, LOCK_32_3_2_4096, buf780d, LOCK_32_3_3_4096, 256, 256);
  window_internal window_buf781_buf781d[1];
  window_datatype * buf781_ptr = (window_datatype * )buf781;
  window_datatype * buf781d_ptr = (window_datatype * )buf781d;
  window_init(window_buf781_buf781d, 1, buf781, LOCK_32_5_0_0, buf781d, LOCK_32_5_1_4096, 256, 256);
  window_internal window_buf782_buf782d[1];
  window_datatype * buf782_ptr = (window_datatype * )buf782;
  window_datatype * buf782d_ptr = (window_datatype * )buf782d;
  window_init(window_buf782_buf782d, 1, buf782, LOCK_32_5_2_0, buf782d, LOCK_32_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_4_bounds = sync_buffer[1];

  while (proc_32_4_bounds)
  {

    // Kernel call : i472:mm_kernel0
    window_acquire(window_buf780_buf780d,LOCK_32_3_2_4096,LOCK_32_3_3_4096,buf780_ptr,buf780d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf781_buf781d,LOCK_32_5_0_0,LOCK_32_5_1_4096,buf781_ptr,buf781d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf782_buf782d,LOCK_32_5_2_0,LOCK_32_5_3_4096,buf782_ptr,buf782d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf780_buf780d),get_input_window_float(window_buf781_buf781d),get_output_window_float(window_buf782_buf782d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf780_buf780d,LOCK_32_3_2_4096,LOCK_32_3_3_4096,buf780_ptr,buf780d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf781_buf781d,LOCK_32_5_0_0,LOCK_32_5_1_4096,buf781_ptr,buf781d_ptr,0,index, REL_WRITE);
    window_release(window_buf782_buf782d,LOCK_32_5_2_0,LOCK_32_5_3_4096,buf782_ptr,buf782d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_4_bounds > 0)
      --proc_32_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}