// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_4/src/29_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_3_2_4096 2
#define LOCK_29_3_3_4096 3
#define LOCK_29_4_2_4096 50
#define LOCK_29_4_3_4096 51
#define LOCK_29_5_0_0 32
#define LOCK_29_5_1_0 33

// Declare shared memory buffers
v4float buf816[256];
v4float buf816d[256];
v4float buf817[256];
v4float buf817d[256];
v4float buf818[256];
v4float buf818d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf816_buf816d[1];
  window_datatype * buf816_ptr = (window_datatype * )buf816;
  window_datatype * buf816d_ptr = (window_datatype * )buf816d;
  window_init(window_buf816_buf816d, 1, buf816, LOCK_29_3_2_4096, buf816d, LOCK_29_3_3_4096, 256, 256);
  window_internal window_buf817_buf817d[1];
  window_datatype * buf817_ptr = (window_datatype * )buf817;
  window_datatype * buf817d_ptr = (window_datatype * )buf817d;
  window_init(window_buf817_buf817d, 1, buf817, LOCK_29_4_2_4096, buf817d, LOCK_29_4_3_4096, 256, 256);
  window_internal window_buf818_buf818d[1];
  window_datatype * buf818_ptr = (window_datatype * )buf818;
  window_datatype * buf818d_ptr = (window_datatype * )buf818d;
  window_init(window_buf818_buf818d, 1, buf818, LOCK_29_5_0_0, buf818d, LOCK_29_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_4_bounds = sync_buffer[1];

  while (proc_29_4_bounds)
  {

    // Kernel call : i490:mm_kernel0
    window_acquire(window_buf816_buf816d,LOCK_29_3_2_4096,LOCK_29_3_3_4096,buf816_ptr,buf816d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf817_buf817d,LOCK_29_4_2_4096,LOCK_29_4_3_4096,buf817_ptr,buf817d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf818_buf818d,LOCK_29_5_0_0,LOCK_29_5_1_0,buf818_ptr,buf818d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf816_buf816d),get_input_window_float(window_buf817_buf817d),get_output_window_float(window_buf818_buf818d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf816_buf816d,LOCK_29_3_2_4096,LOCK_29_3_3_4096,buf816_ptr,buf816d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf817_buf817d,LOCK_29_4_2_4096,LOCK_29_4_3_4096,buf817_ptr,buf817d_ptr,0,index, REL_WRITE);
    window_release(window_buf818_buf818d,LOCK_29_5_0_0,LOCK_29_5_1_0,buf818_ptr,buf818d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_4_bounds > 0)
      --proc_29_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}