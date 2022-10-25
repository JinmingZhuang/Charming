// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_3/src/27_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_3_0_0 16
#define LOCK_27_3_1_0 17
#define LOCK_27_4_0_0 32
#define LOCK_27_4_1_0 33
#define LOCK_27_2_4_4096 4
#define LOCK_27_2_5_4096 5
#define LOCK_27_2_6_4096 6
#define LOCK_27_2_7_4096 7

// Declare shared memory buffers
v4float buf308[256];
v4float buf308d[256];
v4float buf309[256];
v4float buf309d[256];
v4float buf310[256];
v4float buf310d[256];
v4float buf311[256];
v4float buf311d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf309_buf309d[1];
  window_datatype * buf309_ptr = (window_datatype * )buf309;
  window_datatype * buf309d_ptr = (window_datatype * )buf309d;
  window_init(window_buf309_buf309d, 1, buf309, LOCK_27_3_0_0, buf309d, LOCK_27_3_1_0, 256, 256);
  window_internal window_buf310_buf310d[1];
  window_datatype * buf310_ptr = (window_datatype * )buf310;
  window_datatype * buf310d_ptr = (window_datatype * )buf310d;
  window_init(window_buf310_buf310d, 1, buf310, LOCK_27_4_0_0, buf310d, LOCK_27_4_1_0, 256, 256);
  window_internal window_buf308_buf308d[1];
  window_datatype * buf308_ptr = (window_datatype * )buf308;
  window_datatype * buf308d_ptr = (window_datatype * )buf308d;
  window_init(window_buf308_buf308d, 1, buf308, LOCK_27_2_4_4096, buf308d, LOCK_27_2_5_4096, 256, 256);
  window_internal window_buf311_buf311d[1];
  window_datatype * buf311_ptr = (window_datatype * )buf311;
  window_datatype * buf311d_ptr = (window_datatype * )buf311d;
  window_init(window_buf311_buf311d, 1, buf311, LOCK_27_2_6_4096, buf311d, LOCK_27_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_3_bounds = sync_buffer[1];

  while (proc_27_3_bounds)
  {

    // Kernel call : i235:mm_kernel1
    window_acquire(window_buf309_buf309d,LOCK_27_3_0_0,LOCK_27_3_1_0,buf309_ptr,buf309d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf310_buf310d,LOCK_27_4_0_0,LOCK_27_4_1_0,buf310_ptr,buf310d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf308_buf308d,LOCK_27_2_4_4096,LOCK_27_2_5_4096,buf308_ptr,buf308d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf311_buf311d,LOCK_27_2_6_4096,LOCK_27_2_7_4096,buf311_ptr,buf311d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf309_buf309d),get_input_window_float(window_buf310_buf310d),get_input_window_float(window_buf308_buf308d),get_output_window_float(window_buf311_buf311d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf309_buf309d,LOCK_27_3_0_0,LOCK_27_3_1_0,buf309_ptr,buf309d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf310_buf310d,LOCK_27_4_0_0,LOCK_27_4_1_0,buf310_ptr,buf310d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf308_buf308d,LOCK_27_2_4_4096,LOCK_27_2_5_4096,buf308_ptr,buf308d_ptr,0,index, REL_WRITE);
    window_release(window_buf311_buf311d,LOCK_27_2_6_4096,LOCK_27_2_7_4096,buf311_ptr,buf311d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_3_bounds > 0)
      --proc_27_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}