// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_5/src/16_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_5_6_4096 54
#define LOCK_17_5_7_0 55
#define LOCK_16_5_4_4096 20
#define LOCK_16_5_5_0 21
#define LOCK_16_5_2_4096 18
#define LOCK_16_5_3_4096 19
#define LOCK_16_5_6_0 22
#define LOCK_16_5_7_0 23

// Declare shared memory buffers
v4float buf974[256];
v4float buf974d[256];
v4float buf975[256];
v4float buf975d[256];
v4float buf976[256];
v4float buf976d[256];
v4float buf977[256];
v4float buf977d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf975_buf975d[1];
  window_datatype * buf975_ptr = (window_datatype * )buf975;
  window_datatype * buf975d_ptr = (window_datatype * )buf975d;
  window_init(window_buf975_buf975d, 1, buf975, LOCK_17_5_6_4096, buf975d, LOCK_17_5_7_0, 256, 256);
  window_internal window_buf976_buf976d[1];
  window_datatype * buf976_ptr = (window_datatype * )buf976;
  window_datatype * buf976d_ptr = (window_datatype * )buf976d;
  window_init(window_buf976_buf976d, 1, buf976, LOCK_16_5_4_4096, buf976d, LOCK_16_5_5_0, 256, 256);
  window_internal window_buf974_buf974d[1];
  window_datatype * buf974_ptr = (window_datatype * )buf974;
  window_datatype * buf974d_ptr = (window_datatype * )buf974d;
  window_init(window_buf974_buf974d, 1, buf974, LOCK_16_5_2_4096, buf974d, LOCK_16_5_3_4096, 256, 256);
  window_internal window_buf977_buf977d[1];
  window_datatype * buf977_ptr = (window_datatype * )buf977;
  window_datatype * buf977d_ptr = (window_datatype * )buf977d;
  window_init(window_buf977_buf977d, 1, buf977, LOCK_16_5_6_0, buf977d, LOCK_16_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_5_bounds = sync_buffer[1];

  while (proc_16_5_bounds)
  {

    // Kernel call : i569:mm_kernel1
    window_acquire(window_buf975_buf975d,LOCK_17_5_6_4096,LOCK_17_5_7_0,buf975_ptr,buf975d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf976_buf976d,LOCK_16_5_4_4096,LOCK_16_5_5_0,buf976_ptr,buf976d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf974_buf974d,LOCK_16_5_2_4096,LOCK_16_5_3_4096,buf974_ptr,buf974d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf977_buf977d,LOCK_16_5_6_0,LOCK_16_5_7_0,buf977_ptr,buf977d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf975_buf975d),get_input_window_float(window_buf976_buf976d),get_input_window_float(window_buf974_buf974d),get_output_window_float(window_buf977_buf977d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf975_buf975d,LOCK_17_5_6_4096,LOCK_17_5_7_0,buf975_ptr,buf975d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf976_buf976d,LOCK_16_5_4_4096,LOCK_16_5_5_0,buf976_ptr,buf976d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf974_buf974d,LOCK_16_5_2_4096,LOCK_16_5_3_4096,buf974_ptr,buf974d_ptr,0,index, REL_WRITE);
    window_release(window_buf977_buf977d,LOCK_16_5_6_0,LOCK_16_5_7_0,buf977_ptr,buf977d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_5_bounds > 0)
      --proc_16_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}