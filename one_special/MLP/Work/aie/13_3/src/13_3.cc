// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_3/src/13_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_13_2_0_0 0
#define LOCK_13_2_1_0 1
#define LOCK_13_4_0_0 32
#define LOCK_13_4_1_0 33
#define LOCK_13_3_4_4096 20
#define LOCK_13_3_5_4096 21
#define LOCK_13_3_6_0 22
#define LOCK_13_3_7_4096 23

// Declare shared memory buffers
v4float buf140[256];
v4float buf140d[256];
v4float buf141[256];
v4float buf141d[256];
v4float buf142[256];
v4float buf142d[256];
v4float buf143[256];
v4float buf143d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf141_buf141d[1];
  window_datatype * buf141_ptr = (window_datatype * )buf141;
  window_datatype * buf141d_ptr = (window_datatype * )buf141d;
  window_init(window_buf141_buf141d, 1, buf141, LOCK_13_2_0_0, buf141d, LOCK_13_2_1_0, 256, 256);
  window_internal window_buf142_buf142d[1];
  window_datatype * buf142_ptr = (window_datatype * )buf142;
  window_datatype * buf142d_ptr = (window_datatype * )buf142d;
  window_init(window_buf142_buf142d, 1, buf142, LOCK_13_4_0_0, buf142d, LOCK_13_4_1_0, 256, 256);
  window_internal window_buf140_buf140d[1];
  window_datatype * buf140_ptr = (window_datatype * )buf140;
  window_datatype * buf140d_ptr = (window_datatype * )buf140d;
  window_init(window_buf140_buf140d, 1, buf140, LOCK_13_3_4_4096, buf140d, LOCK_13_3_5_4096, 256, 256);
  window_internal window_buf143_buf143d[1];
  window_datatype * buf143_ptr = (window_datatype * )buf143;
  window_datatype * buf143d_ptr = (window_datatype * )buf143d;
  window_init(window_buf143_buf143d, 1, buf143, LOCK_13_3_6_0, buf143d, LOCK_13_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_3_bounds = sync_buffer[1];

  while (proc_13_3_bounds)
  {

    // Kernel call : i151:mm_kernel1
    window_acquire(window_buf141_buf141d,LOCK_13_2_0_0,LOCK_13_2_1_0,buf141_ptr,buf141d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf142_buf142d,LOCK_13_4_0_0,LOCK_13_4_1_0,buf142_ptr,buf142d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf140_buf140d,LOCK_13_3_4_4096,LOCK_13_3_5_4096,buf140_ptr,buf140d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf143_buf143d,LOCK_13_3_6_0,LOCK_13_3_7_4096,buf143_ptr,buf143d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf141_buf141d),get_input_window_float(window_buf142_buf142d),get_input_window_float(window_buf140_buf140d),get_output_window_float(window_buf143_buf143d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf141_buf141d,LOCK_13_2_0_0,LOCK_13_2_1_0,buf141_ptr,buf141d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf142_buf142d,LOCK_13_4_0_0,LOCK_13_4_1_0,buf142_ptr,buf142d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf140_buf140d,LOCK_13_3_4_4096,LOCK_13_3_5_4096,buf140_ptr,buf140d_ptr,0,index, REL_WRITE);
    window_release(window_buf143_buf143d,LOCK_13_3_6_0,LOCK_13_3_7_4096,buf143_ptr,buf143d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_3_bounds > 0)
      --proc_13_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}