// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_2/src/6_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_1_6_0 6
#define LOCK_6_1_7_4096 7
#define LOCK_6_3_0_0 32
#define LOCK_6_3_1_0 33
#define LOCK_6_1_4_4096 4
#define LOCK_6_1_5_4096 5
#define LOCK_6_3_2_0 34
#define LOCK_6_3_3_4096 35

// Declare shared memory buffers
v4float buf53[256];
v4float buf53d[256];
v4float buf54[256];
v4float buf54d[256];
v4float buf55[256];
v4float buf55d[256];
v4float buf56[256];
v4float buf56d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf54_buf54d[1];
  window_datatype * buf54_ptr = (window_datatype * )buf54;
  window_datatype * buf54d_ptr = (window_datatype * )buf54d;
  window_init(window_buf54_buf54d, 1, buf54, LOCK_6_1_6_0, buf54d, LOCK_6_1_7_4096, 256, 256);
  window_internal window_buf55_buf55d[1];
  window_datatype * buf55_ptr = (window_datatype * )buf55;
  window_datatype * buf55d_ptr = (window_datatype * )buf55d;
  window_init(window_buf55_buf55d, 1, buf55, LOCK_6_3_0_0, buf55d, LOCK_6_3_1_0, 256, 256);
  window_internal window_buf53_buf53d[1];
  window_datatype * buf53_ptr = (window_datatype * )buf53;
  window_datatype * buf53d_ptr = (window_datatype * )buf53d;
  window_init(window_buf53_buf53d, 1, buf53, LOCK_6_1_4_4096, buf53d, LOCK_6_1_5_4096, 256, 256);
  window_internal window_buf56_buf56d[1];
  window_datatype * buf56_ptr = (window_datatype * )buf56;
  window_datatype * buf56d_ptr = (window_datatype * )buf56d;
  window_init(window_buf56_buf56d, 1, buf56, LOCK_6_3_2_0, buf56d, LOCK_6_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_2_bounds = sync_buffer[1];

  while (proc_6_2_bounds)
  {

    // Kernel call : i108:mm_kernel1
    window_acquire(window_buf54_buf54d,LOCK_6_1_6_0,LOCK_6_1_7_4096,buf54_ptr,buf54d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf55_buf55d,LOCK_6_3_0_0,LOCK_6_3_1_0,buf55_ptr,buf55d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf53_buf53d,LOCK_6_1_4_4096,LOCK_6_1_5_4096,buf53_ptr,buf53d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf56_buf56d,LOCK_6_3_2_0,LOCK_6_3_3_4096,buf56_ptr,buf56d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf54_buf54d),get_input_window_float(window_buf55_buf55d),get_input_window_float(window_buf53_buf53d),get_output_window_float(window_buf56_buf56d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf54_buf54d,LOCK_6_1_6_0,LOCK_6_1_7_4096,buf54_ptr,buf54d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf55_buf55d,LOCK_6_3_0_0,LOCK_6_3_1_0,buf55_ptr,buf55d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf53_buf53d,LOCK_6_1_4_4096,LOCK_6_1_5_4096,buf53_ptr,buf53d_ptr,0,index, REL_WRITE);
    window_release(window_buf56_buf56d,LOCK_6_3_2_0,LOCK_6_3_3_4096,buf56_ptr,buf56d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_2_bounds > 0)
      --proc_6_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}