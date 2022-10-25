// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_5/src/23_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_6_0_0 32
#define LOCK_23_6_1_0 33
#define LOCK_23_5_4_4096 20
#define LOCK_23_5_5_0 21
#define LOCK_23_5_2_4096 18
#define LOCK_23_5_3_4096 19
#define LOCK_23_5_6_0 22
#define LOCK_23_5_7_0 23

// Declare shared memory buffers
v4float buf890[256];
v4float buf890d[256];
v4float buf891[256];
v4float buf891d[256];
v4float buf892[256];
v4float buf892d[256];
v4float buf893[256];
v4float buf893d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf891_buf891d[1];
  window_datatype * buf891_ptr = (window_datatype * )buf891;
  window_datatype * buf891d_ptr = (window_datatype * )buf891d;
  window_init(window_buf891_buf891d, 1, buf891, LOCK_23_6_0_0, buf891d, LOCK_23_6_1_0, 256, 256);
  window_internal window_buf892_buf892d[1];
  window_datatype * buf892_ptr = (window_datatype * )buf892;
  window_datatype * buf892d_ptr = (window_datatype * )buf892d;
  window_init(window_buf892_buf892d, 1, buf892, LOCK_23_5_4_4096, buf892d, LOCK_23_5_5_0, 256, 256);
  window_internal window_buf890_buf890d[1];
  window_datatype * buf890_ptr = (window_datatype * )buf890;
  window_datatype * buf890d_ptr = (window_datatype * )buf890d;
  window_init(window_buf890_buf890d, 1, buf890, LOCK_23_5_2_4096, buf890d, LOCK_23_5_3_4096, 256, 256);
  window_internal window_buf893_buf893d[1];
  window_datatype * buf893_ptr = (window_datatype * )buf893;
  window_datatype * buf893d_ptr = (window_datatype * )buf893d;
  window_init(window_buf893_buf893d, 1, buf893, LOCK_23_5_6_0, buf893d, LOCK_23_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_5_bounds = sync_buffer[1];

  while (proc_23_5_bounds)
  {

    // Kernel call : i527:mm_kernel1
    window_acquire(window_buf891_buf891d,LOCK_23_6_0_0,LOCK_23_6_1_0,buf891_ptr,buf891d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf892_buf892d,LOCK_23_5_4_4096,LOCK_23_5_5_0,buf892_ptr,buf892d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf890_buf890d,LOCK_23_5_2_4096,LOCK_23_5_3_4096,buf890_ptr,buf890d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf893_buf893d,LOCK_23_5_6_0,LOCK_23_5_7_0,buf893_ptr,buf893d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf891_buf891d),get_input_window_float(window_buf892_buf892d),get_input_window_float(window_buf890_buf890d),get_output_window_float(window_buf893_buf893d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf891_buf891d,LOCK_23_6_0_0,LOCK_23_6_1_0,buf891_ptr,buf891d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf892_buf892d,LOCK_23_5_4_4096,LOCK_23_5_5_0,buf892_ptr,buf892d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf890_buf890d,LOCK_23_5_2_4096,LOCK_23_5_3_4096,buf890_ptr,buf890d_ptr,0,index, REL_WRITE);
    window_release(window_buf893_buf893d,LOCK_23_5_6_0,LOCK_23_5_7_0,buf893_ptr,buf893d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_5_bounds > 0)
      --proc_23_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}