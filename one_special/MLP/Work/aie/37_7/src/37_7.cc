// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_7/src/37_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_7_2_4096 50
#define LOCK_38_7_3_4096 51
#define LOCK_37_6_2_4096 2
#define LOCK_37_6_3_4096 3
#define LOCK_37_7_4_4096 20
#define LOCK_37_7_5_0 21
#define LOCK_37_7_6_4096 22
#define LOCK_37_7_7_4096 23

// Declare shared memory buffers
v4float buf728[256];
v4float buf728d[256];
v4float buf729[256];
v4float buf729d[256];
v4float buf730[256];
v4float buf730d[256];
v4float buf731[256];
v4float buf731d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf729_buf729d[1];
  window_datatype * buf729_ptr = (window_datatype * )buf729;
  window_datatype * buf729d_ptr = (window_datatype * )buf729d;
  window_init(window_buf729_buf729d, 1, buf729, LOCK_38_7_2_4096, buf729d, LOCK_38_7_3_4096, 256, 256);
  window_internal window_buf730_buf730d[1];
  window_datatype * buf730_ptr = (window_datatype * )buf730;
  window_datatype * buf730d_ptr = (window_datatype * )buf730d;
  window_init(window_buf730_buf730d, 1, buf730, LOCK_37_6_2_4096, buf730d, LOCK_37_6_3_4096, 256, 256);
  window_internal window_buf728_buf728d[1];
  window_datatype * buf728_ptr = (window_datatype * )buf728;
  window_datatype * buf728d_ptr = (window_datatype * )buf728d;
  window_init(window_buf728_buf728d, 1, buf728, LOCK_37_7_4_4096, buf728d, LOCK_37_7_5_0, 256, 256);
  window_internal window_buf731_buf731d[1];
  window_datatype * buf731_ptr = (window_datatype * )buf731;
  window_datatype * buf731d_ptr = (window_datatype * )buf731d;
  window_init(window_buf731_buf731d, 1, buf731, LOCK_37_7_6_4096, buf731d, LOCK_37_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_7_bounds = sync_buffer[1];

  while (proc_37_7_bounds)
  {

    // Kernel call : i445:mm_kernel1
    window_acquire(window_buf729_buf729d,LOCK_38_7_2_4096,LOCK_38_7_3_4096,buf729_ptr,buf729d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf730_buf730d,LOCK_37_6_2_4096,LOCK_37_6_3_4096,buf730_ptr,buf730d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf728_buf728d,LOCK_37_7_4_4096,LOCK_37_7_5_0,buf728_ptr,buf728d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf731_buf731d,LOCK_37_7_6_4096,LOCK_37_7_7_4096,buf731_ptr,buf731d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf729_buf729d),get_input_window_float(window_buf730_buf730d),get_input_window_float(window_buf728_buf728d),get_output_window_float(window_buf731_buf731d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf729_buf729d,LOCK_38_7_2_4096,LOCK_38_7_3_4096,buf729_ptr,buf729d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf730_buf730d,LOCK_37_6_2_4096,LOCK_37_6_3_4096,buf730_ptr,buf730d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf728_buf728d,LOCK_37_7_4_4096,LOCK_37_7_5_0,buf728_ptr,buf728d_ptr,0,index, REL_WRITE);
    window_release(window_buf731_buf731d,LOCK_37_7_6_4096,LOCK_37_7_7_4096,buf731_ptr,buf731d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_7_bounds > 0)
      --proc_37_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}