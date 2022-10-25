// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_3/src/17_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_2_4_0 4
#define LOCK_17_2_5_0 5
#define LOCK_17_4_0_0 32
#define LOCK_17_4_1_0 33
#define LOCK_17_2_2_0 2
#define LOCK_17_2_3_4096 3
#define LOCK_17_2_6_4096 6
#define LOCK_17_2_7_4096 7

// Declare shared memory buffers
v4float buf188[256];
v4float buf188d[256];
v4float buf189[256];
v4float buf189d[256];
v4float buf190[256];
v4float buf190d[256];
v4float buf191[256];
v4float buf191d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf189_buf189d[1];
  window_datatype * buf189_ptr = (window_datatype * )buf189;
  window_datatype * buf189d_ptr = (window_datatype * )buf189d;
  window_init(window_buf189_buf189d, 1, buf189, LOCK_17_2_4_0, buf189d, LOCK_17_2_5_0, 256, 256);
  window_internal window_buf190_buf190d[1];
  window_datatype * buf190_ptr = (window_datatype * )buf190;
  window_datatype * buf190d_ptr = (window_datatype * )buf190d;
  window_init(window_buf190_buf190d, 1, buf190, LOCK_17_4_0_0, buf190d, LOCK_17_4_1_0, 256, 256);
  window_internal window_buf188_buf188d[1];
  window_datatype * buf188_ptr = (window_datatype * )buf188;
  window_datatype * buf188d_ptr = (window_datatype * )buf188d;
  window_init(window_buf188_buf188d, 1, buf188, LOCK_17_2_2_0, buf188d, LOCK_17_2_3_4096, 256, 256);
  window_internal window_buf191_buf191d[1];
  window_datatype * buf191_ptr = (window_datatype * )buf191;
  window_datatype * buf191d_ptr = (window_datatype * )buf191d;
  window_init(window_buf191_buf191d, 1, buf191, LOCK_17_2_6_4096, buf191d, LOCK_17_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_3_bounds = sync_buffer[1];

  while (proc_17_3_bounds)
  {

    // Kernel call : i175:mm_kernel1
    window_acquire(window_buf189_buf189d,LOCK_17_2_4_0,LOCK_17_2_5_0,buf189_ptr,buf189d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf190_buf190d,LOCK_17_4_0_0,LOCK_17_4_1_0,buf190_ptr,buf190d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf188_buf188d,LOCK_17_2_2_0,LOCK_17_2_3_4096,buf188_ptr,buf188d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf191_buf191d,LOCK_17_2_6_4096,LOCK_17_2_7_4096,buf191_ptr,buf191d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf189_buf189d),get_input_window_float(window_buf190_buf190d),get_input_window_float(window_buf188_buf188d),get_output_window_float(window_buf191_buf191d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf189_buf189d,LOCK_17_2_4_0,LOCK_17_2_5_0,buf189_ptr,buf189d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf190_buf190d,LOCK_17_4_0_0,LOCK_17_4_1_0,buf190_ptr,buf190d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf188_buf188d,LOCK_17_2_2_0,LOCK_17_2_3_4096,buf188_ptr,buf188d_ptr,0,index, REL_WRITE);
    window_release(window_buf191_buf191d,LOCK_17_2_6_4096,LOCK_17_2_7_4096,buf191_ptr,buf191d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_3_bounds > 0)
      --proc_17_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}