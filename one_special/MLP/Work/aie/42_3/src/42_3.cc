// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_3/src/42_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_2_0_4096 0
#define LOCK_42_2_1_4096 1
#define LOCK_42_2_2_0 2
#define LOCK_42_2_3_0 3
#define LOCK_42_3_4_4096 20
#define LOCK_42_3_5_0 21
#define LOCK_42_3_6_0 22
#define LOCK_42_3_7_0 23

// Declare shared memory buffers
v4float buf488[256];
v4float buf488d[256];
v4float buf489[256];
v4float buf489d[256];
v4float buf490[256];
v4float buf490d[256];
v4float buf491[256];
v4float buf491d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf489_buf489d[1];
  window_datatype * buf489_ptr = (window_datatype * )buf489;
  window_datatype * buf489d_ptr = (window_datatype * )buf489d;
  window_init(window_buf489_buf489d, 1, buf489, LOCK_42_2_0_4096, buf489d, LOCK_42_2_1_4096, 256, 256);
  window_internal window_buf490_buf490d[1];
  window_datatype * buf490_ptr = (window_datatype * )buf490;
  window_datatype * buf490d_ptr = (window_datatype * )buf490d;
  window_init(window_buf490_buf490d, 1, buf490, LOCK_42_2_2_0, buf490d, LOCK_42_2_3_0, 256, 256);
  window_internal window_buf488_buf488d[1];
  window_datatype * buf488_ptr = (window_datatype * )buf488;
  window_datatype * buf488d_ptr = (window_datatype * )buf488d;
  window_init(window_buf488_buf488d, 1, buf488, LOCK_42_3_4_4096, buf488d, LOCK_42_3_5_0, 256, 256);
  window_internal window_buf491_buf491d[1];
  window_datatype * buf491_ptr = (window_datatype * )buf491;
  window_datatype * buf491d_ptr = (window_datatype * )buf491d;
  window_init(window_buf491_buf491d, 1, buf491, LOCK_42_3_6_0, buf491d, LOCK_42_3_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_3_bounds = sync_buffer[1];

  while (proc_42_3_bounds)
  {

    // Kernel call : i325:mm_kernel1
    window_acquire(window_buf489_buf489d,LOCK_42_2_0_4096,LOCK_42_2_1_4096,buf489_ptr,buf489d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf490_buf490d,LOCK_42_2_2_0,LOCK_42_2_3_0,buf490_ptr,buf490d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf488_buf488d,LOCK_42_3_4_4096,LOCK_42_3_5_0,buf488_ptr,buf488d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf491_buf491d,LOCK_42_3_6_0,LOCK_42_3_7_0,buf491_ptr,buf491d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf489_buf489d),get_input_window_float(window_buf490_buf490d),get_input_window_float(window_buf488_buf488d),get_output_window_float(window_buf491_buf491d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf489_buf489d,LOCK_42_2_0_4096,LOCK_42_2_1_4096,buf489_ptr,buf489d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf490_buf490d,LOCK_42_2_2_0,LOCK_42_2_3_0,buf490_ptr,buf490d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf488_buf488d,LOCK_42_3_4_4096,LOCK_42_3_5_0,buf488_ptr,buf488d_ptr,0,index, REL_WRITE);
    window_release(window_buf491_buf491d,LOCK_42_3_6_0,LOCK_42_3_7_0,buf491_ptr,buf491d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_3_bounds > 0)
      --proc_42_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}