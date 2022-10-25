// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_3/src/37_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_4_0_0 32
#define LOCK_37_4_1_0 33
#define LOCK_37_2_2_4096 2
#define LOCK_37_2_3_4096 3
#define LOCK_37_3_4_0 20
#define LOCK_37_3_5_4096 21
#define LOCK_37_3_6_0 22
#define LOCK_37_3_7_4096 23

// Declare shared memory buffers
v4float buf428[256];
v4float buf428d[256];
v4float buf429[256];
v4float buf429d[256];
v4float buf430[256];
v4float buf430d[256];
v4float buf431[256];
v4float buf431d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf429_buf429d[1];
  window_datatype * buf429_ptr = (window_datatype * )buf429;
  window_datatype * buf429d_ptr = (window_datatype * )buf429d;
  window_init(window_buf429_buf429d, 1, buf429, LOCK_37_4_0_0, buf429d, LOCK_37_4_1_0, 256, 256);
  window_internal window_buf430_buf430d[1];
  window_datatype * buf430_ptr = (window_datatype * )buf430;
  window_datatype * buf430d_ptr = (window_datatype * )buf430d;
  window_init(window_buf430_buf430d, 1, buf430, LOCK_37_2_2_4096, buf430d, LOCK_37_2_3_4096, 256, 256);
  window_internal window_buf428_buf428d[1];
  window_datatype * buf428_ptr = (window_datatype * )buf428;
  window_datatype * buf428d_ptr = (window_datatype * )buf428d;
  window_init(window_buf428_buf428d, 1, buf428, LOCK_37_3_4_0, buf428d, LOCK_37_3_5_4096, 256, 256);
  window_internal window_buf431_buf431d[1];
  window_datatype * buf431_ptr = (window_datatype * )buf431;
  window_datatype * buf431d_ptr = (window_datatype * )buf431d;
  window_init(window_buf431_buf431d, 1, buf431, LOCK_37_3_6_0, buf431d, LOCK_37_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_3_bounds = sync_buffer[1];

  while (proc_37_3_bounds)
  {

    // Kernel call : i295:mm_kernel1
    window_acquire(window_buf429_buf429d,LOCK_37_4_0_0,LOCK_37_4_1_0,buf429_ptr,buf429d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf430_buf430d,LOCK_37_2_2_4096,LOCK_37_2_3_4096,buf430_ptr,buf430d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf428_buf428d,LOCK_37_3_4_0,LOCK_37_3_5_4096,buf428_ptr,buf428d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf431_buf431d,LOCK_37_3_6_0,LOCK_37_3_7_4096,buf431_ptr,buf431d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf429_buf429d),get_input_window_float(window_buf430_buf430d),get_input_window_float(window_buf428_buf428d),get_output_window_float(window_buf431_buf431d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf429_buf429d,LOCK_37_4_0_0,LOCK_37_4_1_0,buf429_ptr,buf429d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf430_buf430d,LOCK_37_2_2_4096,LOCK_37_2_3_4096,buf430_ptr,buf430d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf428_buf428d,LOCK_37_3_4_0,LOCK_37_3_5_4096,buf428_ptr,buf428d_ptr,0,index, REL_WRITE);
    window_release(window_buf431_buf431d,LOCK_37_3_6_0,LOCK_37_3_7_4096,buf431_ptr,buf431d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_3_bounds > 0)
      --proc_37_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}