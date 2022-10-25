// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_2/src/24_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_1_6_0 6
#define LOCK_24_1_7_4096 7
#define LOCK_24_3_2_4096 34
#define LOCK_24_3_3_4096 35
#define LOCK_24_1_4_0 4
#define LOCK_24_1_5_4096 5
#define LOCK_24_2_2_0 50
#define LOCK_24_2_3_4096 51

// Declare shared memory buffers
v4float buf269[256];
v4float buf269d[256];
v4float buf270[256];
v4float buf270d[256];
v4float buf271[256];
v4float buf271d[256];
v4float buf272[256];
v4float buf272d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf270_buf270d[1];
  window_datatype * buf270_ptr = (window_datatype * )buf270;
  window_datatype * buf270d_ptr = (window_datatype * )buf270d;
  window_init(window_buf270_buf270d, 1, buf270, LOCK_24_1_6_0, buf270d, LOCK_24_1_7_4096, 256, 256);
  window_internal window_buf271_buf271d[1];
  window_datatype * buf271_ptr = (window_datatype * )buf271;
  window_datatype * buf271d_ptr = (window_datatype * )buf271d;
  window_init(window_buf271_buf271d, 1, buf271, LOCK_24_3_2_4096, buf271d, LOCK_24_3_3_4096, 256, 256);
  window_internal window_buf269_buf269d[1];
  window_datatype * buf269_ptr = (window_datatype * )buf269;
  window_datatype * buf269d_ptr = (window_datatype * )buf269d;
  window_init(window_buf269_buf269d, 1, buf269, LOCK_24_1_4_0, buf269d, LOCK_24_1_5_4096, 256, 256);
  window_internal window_buf272_buf272d[1];
  window_datatype * buf272_ptr = (window_datatype * )buf272;
  window_datatype * buf272d_ptr = (window_datatype * )buf272d;
  window_init(window_buf272_buf272d, 1, buf272, LOCK_24_2_2_0, buf272d, LOCK_24_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_2_bounds = sync_buffer[1];

  while (proc_24_2_bounds)
  {

    // Kernel call : i216:mm_kernel1
    window_acquire(window_buf270_buf270d,LOCK_24_1_6_0,LOCK_24_1_7_4096,buf270_ptr,buf270d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf271_buf271d,LOCK_24_3_2_4096,LOCK_24_3_3_4096,buf271_ptr,buf271d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf269_buf269d,LOCK_24_1_4_0,LOCK_24_1_5_4096,buf269_ptr,buf269d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf272_buf272d,LOCK_24_2_2_0,LOCK_24_2_3_4096,buf272_ptr,buf272d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf270_buf270d),get_input_window_float(window_buf271_buf271d),get_input_window_float(window_buf269_buf269d),get_output_window_float(window_buf272_buf272d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf270_buf270d,LOCK_24_1_6_0,LOCK_24_1_7_4096,buf270_ptr,buf270d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf271_buf271d,LOCK_24_3_2_4096,LOCK_24_3_3_4096,buf271_ptr,buf271d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf269_buf269d,LOCK_24_1_4_0,LOCK_24_1_5_4096,buf269_ptr,buf269d_ptr,0,index, REL_WRITE);
    window_release(window_buf272_buf272d,LOCK_24_2_2_0,LOCK_24_2_3_4096,buf272_ptr,buf272d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_2_bounds > 0)
      --proc_24_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}