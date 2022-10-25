// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_4/src/16_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_16_5_0_4096 32
#define LOCK_16_5_1_0 33
#define LOCK_16_3_6_4096 6
#define LOCK_16_3_7_4096 7
#define LOCK_16_5_2_4096 34
#define LOCK_16_5_3_4096 35

// Declare shared memory buffers
v4float buf972[256];
v4float buf972d[256];
v4float buf973[256];
v4float buf973d[256];
v4float buf974[256];
v4float buf974d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf972_buf972d[1];
  window_datatype * buf972_ptr = (window_datatype * )buf972;
  window_datatype * buf972d_ptr = (window_datatype * )buf972d;
  window_init(window_buf972_buf972d, 1, buf972, LOCK_16_5_0_4096, buf972d, LOCK_16_5_1_0, 256, 256);
  window_internal window_buf973_buf973d[1];
  window_datatype * buf973_ptr = (window_datatype * )buf973;
  window_datatype * buf973d_ptr = (window_datatype * )buf973d;
  window_init(window_buf973_buf973d, 1, buf973, LOCK_16_3_6_4096, buf973d, LOCK_16_3_7_4096, 256, 256);
  window_internal window_buf974_buf974d[1];
  window_datatype * buf974_ptr = (window_datatype * )buf974;
  window_datatype * buf974d_ptr = (window_datatype * )buf974d;
  window_init(window_buf974_buf974d, 1, buf974, LOCK_16_5_2_4096, buf974d, LOCK_16_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_4_bounds = sync_buffer[1];

  while (proc_16_4_bounds)
  {

    // Kernel call : i568:mm_kernel0
    window_acquire(window_buf972_buf972d,LOCK_16_5_0_4096,LOCK_16_5_1_0,buf972_ptr,buf972d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf973_buf973d,LOCK_16_3_6_4096,LOCK_16_3_7_4096,buf973_ptr,buf973d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf974_buf974d,LOCK_16_5_2_4096,LOCK_16_5_3_4096,buf974_ptr,buf974d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf972_buf972d),get_input_window_float(window_buf973_buf973d),get_output_window_float(window_buf974_buf974d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf972_buf972d,LOCK_16_5_0_4096,LOCK_16_5_1_0,buf972_ptr,buf972d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf973_buf973d,LOCK_16_3_6_4096,LOCK_16_3_7_4096,buf973_ptr,buf973d_ptr,0,index, REL_WRITE);
    window_release(window_buf974_buf974d,LOCK_16_5_2_4096,LOCK_16_5_3_4096,buf974_ptr,buf974d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_4_bounds > 0)
      --proc_16_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}