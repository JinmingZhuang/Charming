// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_7/src/29_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_7_2_4096 18
#define LOCK_29_7_3_4096 19
#define LOCK_29_6_4_0 4
#define LOCK_29_6_5_0 5
#define LOCK_29_6_2_0 2
#define LOCK_29_6_3_4096 3
#define LOCK_29_6_6_4096 6
#define LOCK_29_6_7_4096 7

// Declare shared memory buffers
v4float buf824[256];
v4float buf824d[256];
v4float buf825[256];
v4float buf825d[256];
v4float buf826[256];
v4float buf826d[256];
v4float buf827[256];
v4float buf827d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf825_buf825d[1];
  window_datatype * buf825_ptr = (window_datatype * )buf825;
  window_datatype * buf825d_ptr = (window_datatype * )buf825d;
  window_init(window_buf825_buf825d, 1, buf825, LOCK_29_7_2_4096, buf825d, LOCK_29_7_3_4096, 256, 256);
  window_internal window_buf826_buf826d[1];
  window_datatype * buf826_ptr = (window_datatype * )buf826;
  window_datatype * buf826d_ptr = (window_datatype * )buf826d;
  window_init(window_buf826_buf826d, 1, buf826, LOCK_29_6_4_0, buf826d, LOCK_29_6_5_0, 256, 256);
  window_internal window_buf824_buf824d[1];
  window_datatype * buf824_ptr = (window_datatype * )buf824;
  window_datatype * buf824d_ptr = (window_datatype * )buf824d;
  window_init(window_buf824_buf824d, 1, buf824, LOCK_29_6_2_0, buf824d, LOCK_29_6_3_4096, 256, 256);
  window_internal window_buf827_buf827d[1];
  window_datatype * buf827_ptr = (window_datatype * )buf827;
  window_datatype * buf827d_ptr = (window_datatype * )buf827d;
  window_init(window_buf827_buf827d, 1, buf827, LOCK_29_6_6_4096, buf827d, LOCK_29_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_7_bounds = sync_buffer[1];

  while (proc_29_7_bounds)
  {

    // Kernel call : i493:mm_kernel1
    window_acquire(window_buf825_buf825d,LOCK_29_7_2_4096,LOCK_29_7_3_4096,buf825_ptr,buf825d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf826_buf826d,LOCK_29_6_4_0,LOCK_29_6_5_0,buf826_ptr,buf826d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf824_buf824d,LOCK_29_6_2_0,LOCK_29_6_3_4096,buf824_ptr,buf824d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf827_buf827d,LOCK_29_6_6_4096,LOCK_29_6_7_4096,buf827_ptr,buf827d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf825_buf825d),get_input_window_float(window_buf826_buf826d),get_input_window_float(window_buf824_buf824d),get_output_window_float(window_buf827_buf827d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf825_buf825d,LOCK_29_7_2_4096,LOCK_29_7_3_4096,buf825_ptr,buf825d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf826_buf826d,LOCK_29_6_4_0,LOCK_29_6_5_0,buf826_ptr,buf826d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf824_buf824d,LOCK_29_6_2_0,LOCK_29_6_3_4096,buf824_ptr,buf824d_ptr,0,index, REL_WRITE);
    window_release(window_buf827_buf827d,LOCK_29_6_6_4096,LOCK_29_6_7_4096,buf827_ptr,buf827d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_7_bounds > 0)
      --proc_29_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}