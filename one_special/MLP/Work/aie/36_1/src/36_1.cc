// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_1/src/36_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_2_0_0 32
#define LOCK_36_2_1_0 33
#define LOCK_36_0_2_4096 2
#define LOCK_36_0_3_4096 3
#define LOCK_36_1_2_0 18
#define LOCK_36_1_3_4096 19
#define LOCK_36_1_4_0 20
#define LOCK_36_1_5_4096 21

// Declare shared memory buffers
v4float buf410[256];
v4float buf410d[256];
v4float buf411[256];
v4float buf411d[256];
v4float buf412[256];
v4float buf412d[256];
v4float buf413[256];
v4float buf413d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf411_buf411d[1];
  window_datatype * buf411_ptr = (window_datatype * )buf411;
  window_datatype * buf411d_ptr = (window_datatype * )buf411d;
  window_init(window_buf411_buf411d, 1, buf411, LOCK_36_2_0_0, buf411d, LOCK_36_2_1_0, 256, 256);
  window_internal window_buf412_buf412d[1];
  window_datatype * buf412_ptr = (window_datatype * )buf412;
  window_datatype * buf412d_ptr = (window_datatype * )buf412d;
  window_init(window_buf412_buf412d, 1, buf412, LOCK_36_0_2_4096, buf412d, LOCK_36_0_3_4096, 256, 256);
  window_internal window_buf410_buf410d[1];
  window_datatype * buf410_ptr = (window_datatype * )buf410;
  window_datatype * buf410d_ptr = (window_datatype * )buf410d;
  window_init(window_buf410_buf410d, 1, buf410, LOCK_36_1_2_0, buf410d, LOCK_36_1_3_4096, 256, 256);
  window_internal window_buf413_buf413d[1];
  window_datatype * buf413_ptr = (window_datatype * )buf413;
  window_datatype * buf413d_ptr = (window_datatype * )buf413d;
  window_init(window_buf413_buf413d, 1, buf413, LOCK_36_1_4_0, buf413d, LOCK_36_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_1_bounds = sync_buffer[1];

  while (proc_36_1_bounds)
  {

    // Kernel call : i287:mm_kernel1
    window_acquire(window_buf411_buf411d,LOCK_36_2_0_0,LOCK_36_2_1_0,buf411_ptr,buf411d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf412_buf412d,LOCK_36_0_2_4096,LOCK_36_0_3_4096,buf412_ptr,buf412d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf410_buf410d,LOCK_36_1_2_0,LOCK_36_1_3_4096,buf410_ptr,buf410d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf413_buf413d,LOCK_36_1_4_0,LOCK_36_1_5_4096,buf413_ptr,buf413d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf411_buf411d),get_input_window_float(window_buf412_buf412d),get_input_window_float(window_buf410_buf410d),get_output_window_float(window_buf413_buf413d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf411_buf411d,LOCK_36_2_0_0,LOCK_36_2_1_0,buf411_ptr,buf411d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf412_buf412d,LOCK_36_0_2_4096,LOCK_36_0_3_4096,buf412_ptr,buf412d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf410_buf410d,LOCK_36_1_2_0,LOCK_36_1_3_4096,buf410_ptr,buf410d_ptr,0,index, REL_WRITE);
    window_release(window_buf413_buf413d,LOCK_36_1_4_0,LOCK_36_1_5_4096,buf413_ptr,buf413d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_1_bounds > 0)
      --proc_36_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}