// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_3/src/6_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_4_0_0 32
#define LOCK_6_4_1_0 33
#define LOCK_6_2_0_0 0
#define LOCK_6_2_1_0 1
#define LOCK_6_3_2_0 18
#define LOCK_6_3_3_4096 19
#define LOCK_6_3_4_4096 20
#define LOCK_6_3_5_4096 21

// Declare shared memory buffers
v4float buf56[256];
v4float buf56d[256];
v4float buf57[256];
v4float buf57d[256];
v4float buf58[256];
v4float buf58d[256];
v4float buf59[256];
v4float buf59d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf57_buf57d[1];
  window_datatype * buf57_ptr = (window_datatype * )buf57;
  window_datatype * buf57d_ptr = (window_datatype * )buf57d;
  window_init(window_buf57_buf57d, 1, buf57, LOCK_6_4_0_0, buf57d, LOCK_6_4_1_0, 256, 256);
  window_internal window_buf58_buf58d[1];
  window_datatype * buf58_ptr = (window_datatype * )buf58;
  window_datatype * buf58d_ptr = (window_datatype * )buf58d;
  window_init(window_buf58_buf58d, 1, buf58, LOCK_6_2_0_0, buf58d, LOCK_6_2_1_0, 256, 256);
  window_internal window_buf56_buf56d[1];
  window_datatype * buf56_ptr = (window_datatype * )buf56;
  window_datatype * buf56d_ptr = (window_datatype * )buf56d;
  window_init(window_buf56_buf56d, 1, buf56, LOCK_6_3_2_0, buf56d, LOCK_6_3_3_4096, 256, 256);
  window_internal window_buf59_buf59d[1];
  window_datatype * buf59_ptr = (window_datatype * )buf59;
  window_datatype * buf59d_ptr = (window_datatype * )buf59d;
  window_init(window_buf59_buf59d, 1, buf59, LOCK_6_3_4_4096, buf59d, LOCK_6_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_3_bounds = sync_buffer[1];

  while (proc_6_3_bounds)
  {

    // Kernel call : i109:mm_kernel1
    window_acquire(window_buf57_buf57d,LOCK_6_4_0_0,LOCK_6_4_1_0,buf57_ptr,buf57d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf58_buf58d,LOCK_6_2_0_0,LOCK_6_2_1_0,buf58_ptr,buf58d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf56_buf56d,LOCK_6_3_2_0,LOCK_6_3_3_4096,buf56_ptr,buf56d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf59_buf59d,LOCK_6_3_4_4096,LOCK_6_3_5_4096,buf59_ptr,buf59d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf57_buf57d),get_input_window_float(window_buf58_buf58d),get_input_window_float(window_buf56_buf56d),get_output_window_float(window_buf59_buf59d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf57_buf57d,LOCK_6_4_0_0,LOCK_6_4_1_0,buf57_ptr,buf57d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf58_buf58d,LOCK_6_2_0_0,LOCK_6_2_1_0,buf58_ptr,buf58d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf56_buf56d,LOCK_6_3_2_0,LOCK_6_3_3_4096,buf56_ptr,buf56d_ptr,0,index, REL_WRITE);
    window_release(window_buf59_buf59d,LOCK_6_3_4_4096,LOCK_6_3_5_4096,buf59_ptr,buf59d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_3_bounds > 0)
      --proc_6_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}