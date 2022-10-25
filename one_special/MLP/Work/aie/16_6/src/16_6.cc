// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_6/src/16_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_6_0_0 16
#define LOCK_15_6_1_0 17
#define LOCK_16_7_0_0 32
#define LOCK_16_7_1_0 33
#define LOCK_16_5_6_0 6
#define LOCK_16_5_7_0 7
#define LOCK_16_6_2_4096 50
#define LOCK_16_6_3_4096 51

// Declare shared memory buffers
v4float buf977[256];
v4float buf977d[256];
v4float buf978[256];
v4float buf978d[256];
v4float buf979[256];
v4float buf979d[256];
v4float buf980[256];
v4float buf980d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf978_buf978d[1];
  window_datatype * buf978_ptr = (window_datatype * )buf978;
  window_datatype * buf978d_ptr = (window_datatype * )buf978d;
  window_init(window_buf978_buf978d, 1, buf978, LOCK_15_6_0_0, buf978d, LOCK_15_6_1_0, 256, 256);
  window_internal window_buf979_buf979d[1];
  window_datatype * buf979_ptr = (window_datatype * )buf979;
  window_datatype * buf979d_ptr = (window_datatype * )buf979d;
  window_init(window_buf979_buf979d, 1, buf979, LOCK_16_7_0_0, buf979d, LOCK_16_7_1_0, 256, 256);
  window_internal window_buf977_buf977d[1];
  window_datatype * buf977_ptr = (window_datatype * )buf977;
  window_datatype * buf977d_ptr = (window_datatype * )buf977d;
  window_init(window_buf977_buf977d, 1, buf977, LOCK_16_5_6_0, buf977d, LOCK_16_5_7_0, 256, 256);
  window_internal window_buf980_buf980d[1];
  window_datatype * buf980_ptr = (window_datatype * )buf980;
  window_datatype * buf980d_ptr = (window_datatype * )buf980d;
  window_init(window_buf980_buf980d, 1, buf980, LOCK_16_6_2_4096, buf980d, LOCK_16_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_6_bounds = sync_buffer[1];

  while (proc_16_6_bounds)
  {

    // Kernel call : i570:mm_kernel1
    window_acquire(window_buf978_buf978d,LOCK_15_6_0_0,LOCK_15_6_1_0,buf978_ptr,buf978d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf979_buf979d,LOCK_16_7_0_0,LOCK_16_7_1_0,buf979_ptr,buf979d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf977_buf977d,LOCK_16_5_6_0,LOCK_16_5_7_0,buf977_ptr,buf977d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf980_buf980d,LOCK_16_6_2_4096,LOCK_16_6_3_4096,buf980_ptr,buf980d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf978_buf978d),get_input_window_float(window_buf979_buf979d),get_input_window_float(window_buf977_buf977d),get_output_window_float(window_buf980_buf980d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf978_buf978d,LOCK_15_6_0_0,LOCK_15_6_1_0,buf978_ptr,buf978d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf979_buf979d,LOCK_16_7_0_0,LOCK_16_7_1_0,buf979_ptr,buf979d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf977_buf977d,LOCK_16_5_6_0,LOCK_16_5_7_0,buf977_ptr,buf977d_ptr,0,index, REL_WRITE);
    window_release(window_buf980_buf980d,LOCK_16_6_2_4096,LOCK_16_6_3_4096,buf980_ptr,buf980d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_6_bounds > 0)
      --proc_16_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}