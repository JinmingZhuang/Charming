// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_3/src/7_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_3_0_0 48
#define LOCK_8_3_1_0 49
#define LOCK_7_3_4_4096 20
#define LOCK_7_3_5_0 21
#define LOCK_7_3_2_4096 18
#define LOCK_7_3_3_4096 19
#define LOCK_7_3_6_0 22
#define LOCK_7_3_7_0 23

// Declare shared memory buffers
v4float buf68[256];
v4float buf68d[256];
v4float buf69[256];
v4float buf69d[256];
v4float buf70[256];
v4float buf70d[256];
v4float buf71[256];
v4float buf71d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf69_buf69d[1];
  window_datatype * buf69_ptr = (window_datatype * )buf69;
  window_datatype * buf69d_ptr = (window_datatype * )buf69d;
  window_init(window_buf69_buf69d, 1, buf69, LOCK_8_3_0_0, buf69d, LOCK_8_3_1_0, 256, 256);
  window_internal window_buf70_buf70d[1];
  window_datatype * buf70_ptr = (window_datatype * )buf70;
  window_datatype * buf70d_ptr = (window_datatype * )buf70d;
  window_init(window_buf70_buf70d, 1, buf70, LOCK_7_3_4_4096, buf70d, LOCK_7_3_5_0, 256, 256);
  window_internal window_buf68_buf68d[1];
  window_datatype * buf68_ptr = (window_datatype * )buf68;
  window_datatype * buf68d_ptr = (window_datatype * )buf68d;
  window_init(window_buf68_buf68d, 1, buf68, LOCK_7_3_2_4096, buf68d, LOCK_7_3_3_4096, 256, 256);
  window_internal window_buf71_buf71d[1];
  window_datatype * buf71_ptr = (window_datatype * )buf71;
  window_datatype * buf71d_ptr = (window_datatype * )buf71d;
  window_init(window_buf71_buf71d, 1, buf71, LOCK_7_3_6_0, buf71d, LOCK_7_3_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_3_bounds = sync_buffer[1];

  while (proc_7_3_bounds)
  {

    // Kernel call : i115:mm_kernel1
    window_acquire(window_buf69_buf69d,LOCK_8_3_0_0,LOCK_8_3_1_0,buf69_ptr,buf69d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf70_buf70d,LOCK_7_3_4_4096,LOCK_7_3_5_0,buf70_ptr,buf70d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf68_buf68d,LOCK_7_3_2_4096,LOCK_7_3_3_4096,buf68_ptr,buf68d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf71_buf71d,LOCK_7_3_6_0,LOCK_7_3_7_0,buf71_ptr,buf71d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf69_buf69d),get_input_window_float(window_buf70_buf70d),get_input_window_float(window_buf68_buf68d),get_output_window_float(window_buf71_buf71d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf69_buf69d,LOCK_8_3_0_0,LOCK_8_3_1_0,buf69_ptr,buf69d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf70_buf70d,LOCK_7_3_4_4096,LOCK_7_3_5_0,buf70_ptr,buf70d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf68_buf68d,LOCK_7_3_2_4096,LOCK_7_3_3_4096,buf68_ptr,buf68d_ptr,0,index, REL_WRITE);
    window_release(window_buf71_buf71d,LOCK_7_3_6_0,LOCK_7_3_7_0,buf71_ptr,buf71d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_3_bounds > 0)
      --proc_7_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}