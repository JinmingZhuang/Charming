// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_5/src/30_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_30_4_0_0 0
#define LOCK_30_4_1_0 1
#define LOCK_30_4_2_4096 2
#define LOCK_30_4_3_4096 3
#define LOCK_30_5_4_0 20
#define LOCK_30_5_5_0 21
#define LOCK_30_5_6_4096 22
#define LOCK_30_5_7_4096 23

// Declare shared memory buffers
v4float buf806[256];
v4float buf806d[256];
v4float buf807[256];
v4float buf807d[256];
v4float buf808[256];
v4float buf808d[256];
v4float buf809[256];
v4float buf809d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf807_buf807d[1];
  window_datatype * buf807_ptr = (window_datatype * )buf807;
  window_datatype * buf807d_ptr = (window_datatype * )buf807d;
  window_init(window_buf807_buf807d, 1, buf807, LOCK_30_4_0_0, buf807d, LOCK_30_4_1_0, 256, 256);
  window_internal window_buf808_buf808d[1];
  window_datatype * buf808_ptr = (window_datatype * )buf808;
  window_datatype * buf808d_ptr = (window_datatype * )buf808d;
  window_init(window_buf808_buf808d, 1, buf808, LOCK_30_4_2_4096, buf808d, LOCK_30_4_3_4096, 256, 256);
  window_internal window_buf806_buf806d[1];
  window_datatype * buf806_ptr = (window_datatype * )buf806;
  window_datatype * buf806d_ptr = (window_datatype * )buf806d;
  window_init(window_buf806_buf806d, 1, buf806, LOCK_30_5_4_0, buf806d, LOCK_30_5_5_0, 256, 256);
  window_internal window_buf809_buf809d[1];
  window_datatype * buf809_ptr = (window_datatype * )buf809;
  window_datatype * buf809d_ptr = (window_datatype * )buf809d;
  window_init(window_buf809_buf809d, 1, buf809, LOCK_30_5_6_4096, buf809d, LOCK_30_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_5_bounds = sync_buffer[1];

  while (proc_30_5_bounds)
  {

    // Kernel call : i485:mm_kernel1
    window_acquire(window_buf807_buf807d,LOCK_30_4_0_0,LOCK_30_4_1_0,buf807_ptr,buf807d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf808_buf808d,LOCK_30_4_2_4096,LOCK_30_4_3_4096,buf808_ptr,buf808d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf806_buf806d,LOCK_30_5_4_0,LOCK_30_5_5_0,buf806_ptr,buf806d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf809_buf809d,LOCK_30_5_6_4096,LOCK_30_5_7_4096,buf809_ptr,buf809d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf807_buf807d),get_input_window_float(window_buf808_buf808d),get_input_window_float(window_buf806_buf806d),get_output_window_float(window_buf809_buf809d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf807_buf807d,LOCK_30_4_0_0,LOCK_30_4_1_0,buf807_ptr,buf807d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf808_buf808d,LOCK_30_4_2_4096,LOCK_30_4_3_4096,buf808_ptr,buf808d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf806_buf806d,LOCK_30_5_4_0,LOCK_30_5_5_0,buf806_ptr,buf806d_ptr,0,index, REL_WRITE);
    window_release(window_buf809_buf809d,LOCK_30_5_6_4096,LOCK_30_5_7_4096,buf809_ptr,buf809d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_5_bounds > 0)
      --proc_30_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}