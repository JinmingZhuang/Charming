// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/28_3/src/28_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_28_2_2_4096 2
#define LOCK_28_2_3_4096 3
#define LOCK_28_3_4_0 20
#define LOCK_28_3_5_0 21
#define LOCK_28_3_2_0 18
#define LOCK_28_3_3_4096 19
#define LOCK_28_3_6_4096 22
#define LOCK_28_3_7_4096 23

// Declare shared memory buffers
v4float buf320[256];
v4float buf320d[256];
v4float buf321[256];
v4float buf321d[256];
v4float buf322[256];
v4float buf322d[256];
v4float buf323[256];
v4float buf323d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf321_buf321d[1];
  window_datatype * buf321_ptr = (window_datatype * )buf321;
  window_datatype * buf321d_ptr = (window_datatype * )buf321d;
  window_init(window_buf321_buf321d, 1, buf321, LOCK_28_2_2_4096, buf321d, LOCK_28_2_3_4096, 256, 256);
  window_internal window_buf322_buf322d[1];
  window_datatype * buf322_ptr = (window_datatype * )buf322;
  window_datatype * buf322d_ptr = (window_datatype * )buf322d;
  window_init(window_buf322_buf322d, 1, buf322, LOCK_28_3_4_0, buf322d, LOCK_28_3_5_0, 256, 256);
  window_internal window_buf320_buf320d[1];
  window_datatype * buf320_ptr = (window_datatype * )buf320;
  window_datatype * buf320d_ptr = (window_datatype * )buf320d;
  window_init(window_buf320_buf320d, 1, buf320, LOCK_28_3_2_0, buf320d, LOCK_28_3_3_4096, 256, 256);
  window_internal window_buf323_buf323d[1];
  window_datatype * buf323_ptr = (window_datatype * )buf323;
  window_datatype * buf323d_ptr = (window_datatype * )buf323d;
  window_init(window_buf323_buf323d, 1, buf323, LOCK_28_3_6_4096, buf323d, LOCK_28_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_28_3_bounds = sync_buffer[1];

  while (proc_28_3_bounds)
  {

    // Kernel call : i241:mm_kernel1
    window_acquire(window_buf321_buf321d,LOCK_28_2_2_4096,LOCK_28_2_3_4096,buf321_ptr,buf321d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf322_buf322d,LOCK_28_3_4_0,LOCK_28_3_5_0,buf322_ptr,buf322d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf320_buf320d,LOCK_28_3_2_0,LOCK_28_3_3_4096,buf320_ptr,buf320d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf323_buf323d,LOCK_28_3_6_4096,LOCK_28_3_7_4096,buf323_ptr,buf323d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf321_buf321d),get_input_window_float(window_buf322_buf322d),get_input_window_float(window_buf320_buf320d),get_output_window_float(window_buf323_buf323d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf321_buf321d,LOCK_28_2_2_4096,LOCK_28_2_3_4096,buf321_ptr,buf321d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf322_buf322d,LOCK_28_3_4_0,LOCK_28_3_5_0,buf322_ptr,buf322d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf320_buf320d,LOCK_28_3_2_0,LOCK_28_3_3_4096,buf320_ptr,buf320d_ptr,0,index, REL_WRITE);
    window_release(window_buf323_buf323d,LOCK_28_3_6_4096,LOCK_28_3_7_4096,buf323_ptr,buf323d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_28_3_bounds > 0)
      --proc_28_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}