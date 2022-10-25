// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_5/src/14_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_5_2_4096 18
#define LOCK_14_5_3_0 19
#define LOCK_14_4_2_4096 2
#define LOCK_14_4_3_4096 3
#define LOCK_14_5_0_0 16
#define LOCK_14_5_1_0 17
#define LOCK_14_5_4_0 20
#define LOCK_14_5_5_4096 21

// Declare shared memory buffers
v4float buf1000[256];
v4float buf1000d[256];
v4float buf1001[256];
v4float buf1001d[256];
v4float buf998[256];
v4float buf998d[256];
v4float buf999[256];
v4float buf999d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf999_buf999d[1];
  window_datatype * buf999_ptr = (window_datatype * )buf999;
  window_datatype * buf999d_ptr = (window_datatype * )buf999d;
  window_init(window_buf999_buf999d, 1, buf999, LOCK_14_5_2_4096, buf999d, LOCK_14_5_3_0, 256, 256);
  window_internal window_buf1000_buf1000d[1];
  window_datatype * buf1000_ptr = (window_datatype * )buf1000;
  window_datatype * buf1000d_ptr = (window_datatype * )buf1000d;
  window_init(window_buf1000_buf1000d, 1, buf1000, LOCK_14_4_2_4096, buf1000d, LOCK_14_4_3_4096, 256, 256);
  window_internal window_buf998_buf998d[1];
  window_datatype * buf998_ptr = (window_datatype * )buf998;
  window_datatype * buf998d_ptr = (window_datatype * )buf998d;
  window_init(window_buf998_buf998d, 1, buf998, LOCK_14_5_0_0, buf998d, LOCK_14_5_1_0, 256, 256);
  window_internal window_buf1001_buf1001d[1];
  window_datatype * buf1001_ptr = (window_datatype * )buf1001;
  window_datatype * buf1001d_ptr = (window_datatype * )buf1001d;
  window_init(window_buf1001_buf1001d, 1, buf1001, LOCK_14_5_4_0, buf1001d, LOCK_14_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_5_bounds = sync_buffer[1];

  while (proc_14_5_bounds)
  {

    // Kernel call : i581:mm_kernel1
    window_acquire(window_buf999_buf999d,LOCK_14_5_2_4096,LOCK_14_5_3_0,buf999_ptr,buf999d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1000_buf1000d,LOCK_14_4_2_4096,LOCK_14_4_3_4096,buf1000_ptr,buf1000d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf998_buf998d,LOCK_14_5_0_0,LOCK_14_5_1_0,buf998_ptr,buf998d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1001_buf1001d,LOCK_14_5_4_0,LOCK_14_5_5_4096,buf1001_ptr,buf1001d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf999_buf999d),get_input_window_float(window_buf1000_buf1000d),get_input_window_float(window_buf998_buf998d),get_output_window_float(window_buf1001_buf1001d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf999_buf999d,LOCK_14_5_2_4096,LOCK_14_5_3_0,buf999_ptr,buf999d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1000_buf1000d,LOCK_14_4_2_4096,LOCK_14_4_3_4096,buf1000_ptr,buf1000d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf998_buf998d,LOCK_14_5_0_0,LOCK_14_5_1_0,buf998_ptr,buf998d_ptr,0,index, REL_WRITE);
    window_release(window_buf1001_buf1001d,LOCK_14_5_4_0,LOCK_14_5_5_4096,buf1001_ptr,buf1001d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_5_bounds > 0)
      --proc_14_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}