// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_2/src/9_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_1_6_0 6
#define LOCK_9_1_7_4096 7
#define LOCK_9_2_2_4096 50
#define LOCK_9_2_3_4096 51
#define LOCK_9_1_4_4096 4
#define LOCK_9_1_5_4096 5
#define LOCK_9_3_0_0 32
#define LOCK_9_3_1_4096 33

// Declare shared memory buffers
v4float buf89[256];
v4float buf89d[256];
v4float buf90[256];
v4float buf90d[256];
v4float buf91[256];
v4float buf91d[256];
v4float buf92[256];
v4float buf92d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf90_buf90d[1];
  window_datatype * buf90_ptr = (window_datatype * )buf90;
  window_datatype * buf90d_ptr = (window_datatype * )buf90d;
  window_init(window_buf90_buf90d, 1, buf90, LOCK_9_1_6_0, buf90d, LOCK_9_1_7_4096, 256, 256);
  window_internal window_buf91_buf91d[1];
  window_datatype * buf91_ptr = (window_datatype * )buf91;
  window_datatype * buf91d_ptr = (window_datatype * )buf91d;
  window_init(window_buf91_buf91d, 1, buf91, LOCK_9_2_2_4096, buf91d, LOCK_9_2_3_4096, 256, 256);
  window_internal window_buf89_buf89d[1];
  window_datatype * buf89_ptr = (window_datatype * )buf89;
  window_datatype * buf89d_ptr = (window_datatype * )buf89d;
  window_init(window_buf89_buf89d, 1, buf89, LOCK_9_1_4_4096, buf89d, LOCK_9_1_5_4096, 256, 256);
  window_internal window_buf92_buf92d[1];
  window_datatype * buf92_ptr = (window_datatype * )buf92;
  window_datatype * buf92d_ptr = (window_datatype * )buf92d;
  window_init(window_buf92_buf92d, 1, buf92, LOCK_9_3_0_0, buf92d, LOCK_9_3_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_2_bounds = sync_buffer[1];

  while (proc_9_2_bounds)
  {

    // Kernel call : i126:mm_kernel1
    window_acquire(window_buf90_buf90d,LOCK_9_1_6_0,LOCK_9_1_7_4096,buf90_ptr,buf90d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf91_buf91d,LOCK_9_2_2_4096,LOCK_9_2_3_4096,buf91_ptr,buf91d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf89_buf89d,LOCK_9_1_4_4096,LOCK_9_1_5_4096,buf89_ptr,buf89d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf92_buf92d,LOCK_9_3_0_0,LOCK_9_3_1_4096,buf92_ptr,buf92d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf90_buf90d),get_input_window_float(window_buf91_buf91d),get_input_window_float(window_buf89_buf89d),get_output_window_float(window_buf92_buf92d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf90_buf90d,LOCK_9_1_6_0,LOCK_9_1_7_4096,buf90_ptr,buf90d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf91_buf91d,LOCK_9_2_2_4096,LOCK_9_2_3_4096,buf91_ptr,buf91d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf89_buf89d,LOCK_9_1_4_4096,LOCK_9_1_5_4096,buf89_ptr,buf89d_ptr,0,index, REL_WRITE);
    window_release(window_buf92_buf92d,LOCK_9_3_0_0,LOCK_9_3_1_4096,buf92_ptr,buf92d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_2_bounds > 0)
      --proc_9_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}