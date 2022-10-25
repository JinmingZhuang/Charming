// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_7/src/38_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_6_4_0 4
#define LOCK_38_6_5_0 5
#define LOCK_38_7_0_0 16
#define LOCK_38_7_1_0 17
#define LOCK_38_6_2_4096 2
#define LOCK_38_6_3_4096 3
#define LOCK_38_6_6_4096 6
#define LOCK_38_6_7_4096 7

// Declare shared memory buffers
v4float buf716[256];
v4float buf716d[256];
v4float buf717[256];
v4float buf717d[256];
v4float buf718[256];
v4float buf718d[256];
v4float buf719[256];
v4float buf719d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf717_buf717d[1];
  window_datatype * buf717_ptr = (window_datatype * )buf717;
  window_datatype * buf717d_ptr = (window_datatype * )buf717d;
  window_init(window_buf717_buf717d, 1, buf717, LOCK_38_6_4_0, buf717d, LOCK_38_6_5_0, 256, 256);
  window_internal window_buf718_buf718d[1];
  window_datatype * buf718_ptr = (window_datatype * )buf718;
  window_datatype * buf718d_ptr = (window_datatype * )buf718d;
  window_init(window_buf718_buf718d, 1, buf718, LOCK_38_7_0_0, buf718d, LOCK_38_7_1_0, 256, 256);
  window_internal window_buf716_buf716d[1];
  window_datatype * buf716_ptr = (window_datatype * )buf716;
  window_datatype * buf716d_ptr = (window_datatype * )buf716d;
  window_init(window_buf716_buf716d, 1, buf716, LOCK_38_6_2_4096, buf716d, LOCK_38_6_3_4096, 256, 256);
  window_internal window_buf719_buf719d[1];
  window_datatype * buf719_ptr = (window_datatype * )buf719;
  window_datatype * buf719d_ptr = (window_datatype * )buf719d;
  window_init(window_buf719_buf719d, 1, buf719, LOCK_38_6_6_4096, buf719d, LOCK_38_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_7_bounds = sync_buffer[1];

  while (proc_38_7_bounds)
  {

    // Kernel call : i439:mm_kernel1
    window_acquire(window_buf717_buf717d,LOCK_38_6_4_0,LOCK_38_6_5_0,buf717_ptr,buf717d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf718_buf718d,LOCK_38_7_0_0,LOCK_38_7_1_0,buf718_ptr,buf718d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf716_buf716d,LOCK_38_6_2_4096,LOCK_38_6_3_4096,buf716_ptr,buf716d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf719_buf719d,LOCK_38_6_6_4096,LOCK_38_6_7_4096,buf719_ptr,buf719d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf717_buf717d),get_input_window_float(window_buf718_buf718d),get_input_window_float(window_buf716_buf716d),get_output_window_float(window_buf719_buf719d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf717_buf717d,LOCK_38_6_4_0,LOCK_38_6_5_0,buf717_ptr,buf717d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf718_buf718d,LOCK_38_7_0_0,LOCK_38_7_1_0,buf718_ptr,buf718d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf716_buf716d,LOCK_38_6_2_4096,LOCK_38_6_3_4096,buf716_ptr,buf716d_ptr,0,index, REL_WRITE);
    window_release(window_buf719_buf719d,LOCK_38_6_6_4096,LOCK_38_6_7_4096,buf719_ptr,buf719d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_7_bounds > 0)
      --proc_38_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}