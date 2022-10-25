// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_7/src/39_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_7_2_4096 18
#define LOCK_39_7_3_4096 19
#define LOCK_39_7_4_0 20
#define LOCK_39_7_5_0 21
#define LOCK_39_7_0_0 16
#define LOCK_39_7_1_0 17
#define LOCK_39_7_6_4096 22
#define LOCK_39_7_7_4096 23

// Declare shared memory buffers
v4float buf704[256];
v4float buf704d[256];
v4float buf705[256];
v4float buf705d[256];
v4float buf706[256];
v4float buf706d[256];
v4float buf707[256];
v4float buf707d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf705_buf705d[1];
  window_datatype * buf705_ptr = (window_datatype * )buf705;
  window_datatype * buf705d_ptr = (window_datatype * )buf705d;
  window_init(window_buf705_buf705d, 1, buf705, LOCK_39_7_2_4096, buf705d, LOCK_39_7_3_4096, 256, 256);
  window_internal window_buf706_buf706d[1];
  window_datatype * buf706_ptr = (window_datatype * )buf706;
  window_datatype * buf706d_ptr = (window_datatype * )buf706d;
  window_init(window_buf706_buf706d, 1, buf706, LOCK_39_7_4_0, buf706d, LOCK_39_7_5_0, 256, 256);
  window_internal window_buf704_buf704d[1];
  window_datatype * buf704_ptr = (window_datatype * )buf704;
  window_datatype * buf704d_ptr = (window_datatype * )buf704d;
  window_init(window_buf704_buf704d, 1, buf704, LOCK_39_7_0_0, buf704d, LOCK_39_7_1_0, 256, 256);
  window_internal window_buf707_buf707d[1];
  window_datatype * buf707_ptr = (window_datatype * )buf707;
  window_datatype * buf707d_ptr = (window_datatype * )buf707d;
  window_init(window_buf707_buf707d, 1, buf707, LOCK_39_7_6_4096, buf707d, LOCK_39_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_7_bounds = sync_buffer[1];

  while (proc_39_7_bounds)
  {

    // Kernel call : i433:mm_kernel1
    window_acquire(window_buf705_buf705d,LOCK_39_7_2_4096,LOCK_39_7_3_4096,buf705_ptr,buf705d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf706_buf706d,LOCK_39_7_4_0,LOCK_39_7_5_0,buf706_ptr,buf706d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf704_buf704d,LOCK_39_7_0_0,LOCK_39_7_1_0,buf704_ptr,buf704d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf707_buf707d,LOCK_39_7_6_4096,LOCK_39_7_7_4096,buf707_ptr,buf707d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf705_buf705d),get_input_window_float(window_buf706_buf706d),get_input_window_float(window_buf704_buf704d),get_output_window_float(window_buf707_buf707d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf705_buf705d,LOCK_39_7_2_4096,LOCK_39_7_3_4096,buf705_ptr,buf705d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf706_buf706d,LOCK_39_7_4_0,LOCK_39_7_5_0,buf706_ptr,buf706d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf704_buf704d,LOCK_39_7_0_0,LOCK_39_7_1_0,buf704_ptr,buf704d_ptr,0,index, REL_WRITE);
    window_release(window_buf707_buf707d,LOCK_39_7_6_4096,LOCK_39_7_7_4096,buf707_ptr,buf707d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_7_bounds > 0)
      --proc_39_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}