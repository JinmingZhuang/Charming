// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_7/src/30_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_30_7_2_4096 18
#define LOCK_30_7_3_4096 19
#define LOCK_30_7_4_0 20
#define LOCK_30_7_5_0 21
#define LOCK_30_7_0_0 16
#define LOCK_30_7_1_0 17
#define LOCK_30_7_6_4096 22
#define LOCK_30_7_7_4096 23

// Declare shared memory buffers
v4float buf812[256];
v4float buf812d[256];
v4float buf813[256];
v4float buf813d[256];
v4float buf814[256];
v4float buf814d[256];
v4float buf815[256];
v4float buf815d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf813_buf813d[1];
  window_datatype * buf813_ptr = (window_datatype * )buf813;
  window_datatype * buf813d_ptr = (window_datatype * )buf813d;
  window_init(window_buf813_buf813d, 1, buf813, LOCK_30_7_2_4096, buf813d, LOCK_30_7_3_4096, 256, 256);
  window_internal window_buf814_buf814d[1];
  window_datatype * buf814_ptr = (window_datatype * )buf814;
  window_datatype * buf814d_ptr = (window_datatype * )buf814d;
  window_init(window_buf814_buf814d, 1, buf814, LOCK_30_7_4_0, buf814d, LOCK_30_7_5_0, 256, 256);
  window_internal window_buf812_buf812d[1];
  window_datatype * buf812_ptr = (window_datatype * )buf812;
  window_datatype * buf812d_ptr = (window_datatype * )buf812d;
  window_init(window_buf812_buf812d, 1, buf812, LOCK_30_7_0_0, buf812d, LOCK_30_7_1_0, 256, 256);
  window_internal window_buf815_buf815d[1];
  window_datatype * buf815_ptr = (window_datatype * )buf815;
  window_datatype * buf815d_ptr = (window_datatype * )buf815d;
  window_init(window_buf815_buf815d, 1, buf815, LOCK_30_7_6_4096, buf815d, LOCK_30_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_7_bounds = sync_buffer[1];

  while (proc_30_7_bounds)
  {

    // Kernel call : i487:mm_kernel1
    window_acquire(window_buf813_buf813d,LOCK_30_7_2_4096,LOCK_30_7_3_4096,buf813_ptr,buf813d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf814_buf814d,LOCK_30_7_4_0,LOCK_30_7_5_0,buf814_ptr,buf814d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf812_buf812d,LOCK_30_7_0_0,LOCK_30_7_1_0,buf812_ptr,buf812d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf815_buf815d,LOCK_30_7_6_4096,LOCK_30_7_7_4096,buf815_ptr,buf815d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf813_buf813d),get_input_window_float(window_buf814_buf814d),get_input_window_float(window_buf812_buf812d),get_output_window_float(window_buf815_buf815d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf813_buf813d,LOCK_30_7_2_4096,LOCK_30_7_3_4096,buf813_ptr,buf813d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf814_buf814d,LOCK_30_7_4_0,LOCK_30_7_5_0,buf814_ptr,buf814d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf812_buf812d,LOCK_30_7_0_0,LOCK_30_7_1_0,buf812_ptr,buf812d_ptr,0,index, REL_WRITE);
    window_release(window_buf815_buf815d,LOCK_30_7_6_4096,LOCK_30_7_7_4096,buf815_ptr,buf815d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_7_bounds > 0)
      --proc_30_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}