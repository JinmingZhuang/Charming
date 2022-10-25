// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_7/src/9_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_6_4_4096 4
#define LOCK_9_6_5_4096 5
#define LOCK_9_7_2_4096 18
#define LOCK_9_7_3_4096 19
#define LOCK_9_6_2_4096 2
#define LOCK_9_6_3_4096 3
#define LOCK_9_6_6_0 6
#define LOCK_9_6_7_0 7

// Declare shared memory buffers
v4float buf1064[256];
v4float buf1064d[256];
v4float buf1065[256];
v4float buf1065d[256];
v4float buf1066[256];
v4float buf1066d[256];
v4float buf1067[256];
v4float buf1067d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1065_buf1065d[1];
  window_datatype * buf1065_ptr = (window_datatype * )buf1065;
  window_datatype * buf1065d_ptr = (window_datatype * )buf1065d;
  window_init(window_buf1065_buf1065d, 1, buf1065, LOCK_9_6_4_4096, buf1065d, LOCK_9_6_5_4096, 256, 256);
  window_internal window_buf1066_buf1066d[1];
  window_datatype * buf1066_ptr = (window_datatype * )buf1066;
  window_datatype * buf1066d_ptr = (window_datatype * )buf1066d;
  window_init(window_buf1066_buf1066d, 1, buf1066, LOCK_9_7_2_4096, buf1066d, LOCK_9_7_3_4096, 256, 256);
  window_internal window_buf1064_buf1064d[1];
  window_datatype * buf1064_ptr = (window_datatype * )buf1064;
  window_datatype * buf1064d_ptr = (window_datatype * )buf1064d;
  window_init(window_buf1064_buf1064d, 1, buf1064, LOCK_9_6_2_4096, buf1064d, LOCK_9_6_3_4096, 256, 256);
  window_internal window_buf1067_buf1067d[1];
  window_datatype * buf1067_ptr = (window_datatype * )buf1067;
  window_datatype * buf1067d_ptr = (window_datatype * )buf1067d;
  window_init(window_buf1067_buf1067d, 1, buf1067, LOCK_9_6_6_0, buf1067d, LOCK_9_6_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_7_bounds = sync_buffer[1];

  while (proc_9_7_bounds)
  {

    // Kernel call : i613:mm_kernel1
    window_acquire(window_buf1065_buf1065d,LOCK_9_6_4_4096,LOCK_9_6_5_4096,buf1065_ptr,buf1065d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1066_buf1066d,LOCK_9_7_2_4096,LOCK_9_7_3_4096,buf1066_ptr,buf1066d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1064_buf1064d,LOCK_9_6_2_4096,LOCK_9_6_3_4096,buf1064_ptr,buf1064d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1067_buf1067d,LOCK_9_6_6_0,LOCK_9_6_7_0,buf1067_ptr,buf1067d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1065_buf1065d),get_input_window_float(window_buf1066_buf1066d),get_input_window_float(window_buf1064_buf1064d),get_output_window_float(window_buf1067_buf1067d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1065_buf1065d,LOCK_9_6_4_4096,LOCK_9_6_5_4096,buf1065_ptr,buf1065d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1066_buf1066d,LOCK_9_7_2_4096,LOCK_9_7_3_4096,buf1066_ptr,buf1066d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1064_buf1064d,LOCK_9_6_2_4096,LOCK_9_6_3_4096,buf1064_ptr,buf1064d_ptr,0,index, REL_WRITE);
    window_release(window_buf1067_buf1067d,LOCK_9_6_6_0,LOCK_9_6_7_0,buf1067_ptr,buf1067d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_7_bounds > 0)
      --proc_9_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}