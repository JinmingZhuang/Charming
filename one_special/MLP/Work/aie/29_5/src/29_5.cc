// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_5/src/29_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_5_2_4096 18
#define LOCK_29_5_3_4096 19
#define LOCK_29_5_4_0 20
#define LOCK_29_5_5_0 21
#define LOCK_29_5_0_0 16
#define LOCK_29_5_1_0 17
#define LOCK_29_5_6_4096 22
#define LOCK_29_5_7_4096 23

// Declare shared memory buffers
v4float buf818[256];
v4float buf818d[256];
v4float buf819[256];
v4float buf819d[256];
v4float buf820[256];
v4float buf820d[256];
v4float buf821[256];
v4float buf821d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf819_buf819d[1];
  window_datatype * buf819_ptr = (window_datatype * )buf819;
  window_datatype * buf819d_ptr = (window_datatype * )buf819d;
  window_init(window_buf819_buf819d, 1, buf819, LOCK_29_5_2_4096, buf819d, LOCK_29_5_3_4096, 256, 256);
  window_internal window_buf820_buf820d[1];
  window_datatype * buf820_ptr = (window_datatype * )buf820;
  window_datatype * buf820d_ptr = (window_datatype * )buf820d;
  window_init(window_buf820_buf820d, 1, buf820, LOCK_29_5_4_0, buf820d, LOCK_29_5_5_0, 256, 256);
  window_internal window_buf818_buf818d[1];
  window_datatype * buf818_ptr = (window_datatype * )buf818;
  window_datatype * buf818d_ptr = (window_datatype * )buf818d;
  window_init(window_buf818_buf818d, 1, buf818, LOCK_29_5_0_0, buf818d, LOCK_29_5_1_0, 256, 256);
  window_internal window_buf821_buf821d[1];
  window_datatype * buf821_ptr = (window_datatype * )buf821;
  window_datatype * buf821d_ptr = (window_datatype * )buf821d;
  window_init(window_buf821_buf821d, 1, buf821, LOCK_29_5_6_4096, buf821d, LOCK_29_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_5_bounds = sync_buffer[1];

  while (proc_29_5_bounds)
  {

    // Kernel call : i491:mm_kernel1
    window_acquire(window_buf819_buf819d,LOCK_29_5_2_4096,LOCK_29_5_3_4096,buf819_ptr,buf819d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf820_buf820d,LOCK_29_5_4_0,LOCK_29_5_5_0,buf820_ptr,buf820d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf818_buf818d,LOCK_29_5_0_0,LOCK_29_5_1_0,buf818_ptr,buf818d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf821_buf821d,LOCK_29_5_6_4096,LOCK_29_5_7_4096,buf821_ptr,buf821d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf819_buf819d),get_input_window_float(window_buf820_buf820d),get_input_window_float(window_buf818_buf818d),get_output_window_float(window_buf821_buf821d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf819_buf819d,LOCK_29_5_2_4096,LOCK_29_5_3_4096,buf819_ptr,buf819d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf820_buf820d,LOCK_29_5_4_0,LOCK_29_5_5_0,buf820_ptr,buf820d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf818_buf818d,LOCK_29_5_0_0,LOCK_29_5_1_0,buf818_ptr,buf818d_ptr,0,index, REL_WRITE);
    window_release(window_buf821_buf821d,LOCK_29_5_6_4096,LOCK_29_5_7_4096,buf821_ptr,buf821d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_5_bounds > 0)
      --proc_29_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}