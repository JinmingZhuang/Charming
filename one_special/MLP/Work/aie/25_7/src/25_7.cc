// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_7/src/25_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_7_4_4096 20
#define LOCK_25_7_5_0 21
#define LOCK_26_7_2_4096 50
#define LOCK_26_7_3_4096 51
#define LOCK_25_7_2_4096 18
#define LOCK_25_7_3_4096 19
#define LOCK_25_7_6_0 22
#define LOCK_25_7_7_0 23

// Declare shared memory buffers
v4float buf872[256];
v4float buf872d[256];
v4float buf873[256];
v4float buf873d[256];
v4float buf874[256];
v4float buf874d[256];
v4float buf875[256];
v4float buf875d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf873_buf873d[1];
  window_datatype * buf873_ptr = (window_datatype * )buf873;
  window_datatype * buf873d_ptr = (window_datatype * )buf873d;
  window_init(window_buf873_buf873d, 1, buf873, LOCK_25_7_4_4096, buf873d, LOCK_25_7_5_0, 256, 256);
  window_internal window_buf874_buf874d[1];
  window_datatype * buf874_ptr = (window_datatype * )buf874;
  window_datatype * buf874d_ptr = (window_datatype * )buf874d;
  window_init(window_buf874_buf874d, 1, buf874, LOCK_26_7_2_4096, buf874d, LOCK_26_7_3_4096, 256, 256);
  window_internal window_buf872_buf872d[1];
  window_datatype * buf872_ptr = (window_datatype * )buf872;
  window_datatype * buf872d_ptr = (window_datatype * )buf872d;
  window_init(window_buf872_buf872d, 1, buf872, LOCK_25_7_2_4096, buf872d, LOCK_25_7_3_4096, 256, 256);
  window_internal window_buf875_buf875d[1];
  window_datatype * buf875_ptr = (window_datatype * )buf875;
  window_datatype * buf875d_ptr = (window_datatype * )buf875d;
  window_init(window_buf875_buf875d, 1, buf875, LOCK_25_7_6_0, buf875d, LOCK_25_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_7_bounds = sync_buffer[1];

  while (proc_25_7_bounds)
  {

    // Kernel call : i517:mm_kernel1
    window_acquire(window_buf873_buf873d,LOCK_25_7_4_4096,LOCK_25_7_5_0,buf873_ptr,buf873d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf874_buf874d,LOCK_26_7_2_4096,LOCK_26_7_3_4096,buf874_ptr,buf874d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf872_buf872d,LOCK_25_7_2_4096,LOCK_25_7_3_4096,buf872_ptr,buf872d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf875_buf875d,LOCK_25_7_6_0,LOCK_25_7_7_0,buf875_ptr,buf875d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf873_buf873d),get_input_window_float(window_buf874_buf874d),get_input_window_float(window_buf872_buf872d),get_output_window_float(window_buf875_buf875d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf873_buf873d,LOCK_25_7_4_4096,LOCK_25_7_5_0,buf873_ptr,buf873d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf874_buf874d,LOCK_26_7_2_4096,LOCK_26_7_3_4096,buf874_ptr,buf874d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf872_buf872d,LOCK_25_7_2_4096,LOCK_25_7_3_4096,buf872_ptr,buf872d_ptr,0,index, REL_WRITE);
    window_release(window_buf875_buf875d,LOCK_25_7_6_0,LOCK_25_7_7_0,buf875_ptr,buf875d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_7_bounds > 0)
      --proc_25_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}