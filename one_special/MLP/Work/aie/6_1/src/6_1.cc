// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_1/src/6_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_0_2_4096 2
#define LOCK_6_0_3_4096 3
#define LOCK_7_1_0_4096 48
#define LOCK_7_1_1_4096 49
#define LOCK_6_1_2_0 18
#define LOCK_6_1_3_4096 19
#define LOCK_6_1_4_4096 20
#define LOCK_6_1_5_4096 21

// Declare shared memory buffers
v4float buf50[256];
v4float buf50d[256];
v4float buf51[256];
v4float buf51d[256];
v4float buf52[256];
v4float buf52d[256];
v4float buf53[256];
v4float buf53d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf51_buf51d[1];
  window_datatype * buf51_ptr = (window_datatype * )buf51;
  window_datatype * buf51d_ptr = (window_datatype * )buf51d;
  window_init(window_buf51_buf51d, 1, buf51, LOCK_6_0_2_4096, buf51d, LOCK_6_0_3_4096, 256, 256);
  window_internal window_buf52_buf52d[1];
  window_datatype * buf52_ptr = (window_datatype * )buf52;
  window_datatype * buf52d_ptr = (window_datatype * )buf52d;
  window_init(window_buf52_buf52d, 1, buf52, LOCK_7_1_0_4096, buf52d, LOCK_7_1_1_4096, 256, 256);
  window_internal window_buf50_buf50d[1];
  window_datatype * buf50_ptr = (window_datatype * )buf50;
  window_datatype * buf50d_ptr = (window_datatype * )buf50d;
  window_init(window_buf50_buf50d, 1, buf50, LOCK_6_1_2_0, buf50d, LOCK_6_1_3_4096, 256, 256);
  window_internal window_buf53_buf53d[1];
  window_datatype * buf53_ptr = (window_datatype * )buf53;
  window_datatype * buf53d_ptr = (window_datatype * )buf53d;
  window_init(window_buf53_buf53d, 1, buf53, LOCK_6_1_4_4096, buf53d, LOCK_6_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_1_bounds = sync_buffer[1];

  while (proc_6_1_bounds)
  {

    // Kernel call : i107:mm_kernel1
    window_acquire(window_buf51_buf51d,LOCK_6_0_2_4096,LOCK_6_0_3_4096,buf51_ptr,buf51d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf52_buf52d,LOCK_7_1_0_4096,LOCK_7_1_1_4096,buf52_ptr,buf52d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf50_buf50d,LOCK_6_1_2_0,LOCK_6_1_3_4096,buf50_ptr,buf50d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf53_buf53d,LOCK_6_1_4_4096,LOCK_6_1_5_4096,buf53_ptr,buf53d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf51_buf51d),get_input_window_float(window_buf52_buf52d),get_input_window_float(window_buf50_buf50d),get_output_window_float(window_buf53_buf53d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf51_buf51d,LOCK_6_0_2_4096,LOCK_6_0_3_4096,buf51_ptr,buf51d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf52_buf52d,LOCK_7_1_0_4096,LOCK_7_1_1_4096,buf52_ptr,buf52d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf50_buf50d,LOCK_6_1_2_0,LOCK_6_1_3_4096,buf50_ptr,buf50d_ptr,0,index, REL_WRITE);
    window_release(window_buf53_buf53d,LOCK_6_1_4_4096,LOCK_6_1_5_4096,buf53_ptr,buf53d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_1_bounds > 0)
      --proc_6_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}