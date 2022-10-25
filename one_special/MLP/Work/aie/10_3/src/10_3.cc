// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_3/src/10_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_3_0_0 48
#define LOCK_11_3_1_0 49
#define LOCK_10_3_4_4096 20
#define LOCK_10_3_5_0 21
#define LOCK_10_3_2_4096 18
#define LOCK_10_3_3_4096 19
#define LOCK_10_3_6_0 22
#define LOCK_10_3_7_0 23

// Declare shared memory buffers
v4float buf104[256];
v4float buf104d[256];
v4float buf105[256];
v4float buf105d[256];
v4float buf106[256];
v4float buf106d[256];
v4float buf107[256];
v4float buf107d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf105_buf105d[1];
  window_datatype * buf105_ptr = (window_datatype * )buf105;
  window_datatype * buf105d_ptr = (window_datatype * )buf105d;
  window_init(window_buf105_buf105d, 1, buf105, LOCK_11_3_0_0, buf105d, LOCK_11_3_1_0, 256, 256);
  window_internal window_buf106_buf106d[1];
  window_datatype * buf106_ptr = (window_datatype * )buf106;
  window_datatype * buf106d_ptr = (window_datatype * )buf106d;
  window_init(window_buf106_buf106d, 1, buf106, LOCK_10_3_4_4096, buf106d, LOCK_10_3_5_0, 256, 256);
  window_internal window_buf104_buf104d[1];
  window_datatype * buf104_ptr = (window_datatype * )buf104;
  window_datatype * buf104d_ptr = (window_datatype * )buf104d;
  window_init(window_buf104_buf104d, 1, buf104, LOCK_10_3_2_4096, buf104d, LOCK_10_3_3_4096, 256, 256);
  window_internal window_buf107_buf107d[1];
  window_datatype * buf107_ptr = (window_datatype * )buf107;
  window_datatype * buf107d_ptr = (window_datatype * )buf107d;
  window_init(window_buf107_buf107d, 1, buf107, LOCK_10_3_6_0, buf107d, LOCK_10_3_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_3_bounds = sync_buffer[1];

  while (proc_10_3_bounds)
  {

    // Kernel call : i133:mm_kernel1
    window_acquire(window_buf105_buf105d,LOCK_11_3_0_0,LOCK_11_3_1_0,buf105_ptr,buf105d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf106_buf106d,LOCK_10_3_4_4096,LOCK_10_3_5_0,buf106_ptr,buf106d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf104_buf104d,LOCK_10_3_2_4096,LOCK_10_3_3_4096,buf104_ptr,buf104d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf107_buf107d,LOCK_10_3_6_0,LOCK_10_3_7_0,buf107_ptr,buf107d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf105_buf105d),get_input_window_float(window_buf106_buf106d),get_input_window_float(window_buf104_buf104d),get_output_window_float(window_buf107_buf107d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf105_buf105d,LOCK_11_3_0_0,LOCK_11_3_1_0,buf105_ptr,buf105d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf106_buf106d,LOCK_10_3_4_4096,LOCK_10_3_5_0,buf106_ptr,buf106d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf104_buf104d,LOCK_10_3_2_4096,LOCK_10_3_3_4096,buf104_ptr,buf104d_ptr,0,index, REL_WRITE);
    window_release(window_buf107_buf107d,LOCK_10_3_6_0,LOCK_10_3_7_0,buf107_ptr,buf107d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_3_bounds > 0)
      --proc_10_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}