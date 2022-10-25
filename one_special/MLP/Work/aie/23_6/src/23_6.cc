// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_6/src/23_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_7_0_0 32
#define LOCK_23_7_1_0 33
#define LOCK_23_6_2_0 50
#define LOCK_23_6_3_4096 51
#define LOCK_23_5_6_0 6
#define LOCK_23_5_7_0 7
#define LOCK_23_6_4_4096 52
#define LOCK_23_6_5_4096 53

// Declare shared memory buffers
v4float buf893[256];
v4float buf893d[256];
v4float buf894[256];
v4float buf894d[256];
v4float buf895[256];
v4float buf895d[256];
v4float buf896[256];
v4float buf896d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf894_buf894d[1];
  window_datatype * buf894_ptr = (window_datatype * )buf894;
  window_datatype * buf894d_ptr = (window_datatype * )buf894d;
  window_init(window_buf894_buf894d, 1, buf894, LOCK_23_7_0_0, buf894d, LOCK_23_7_1_0, 256, 256);
  window_internal window_buf895_buf895d[1];
  window_datatype * buf895_ptr = (window_datatype * )buf895;
  window_datatype * buf895d_ptr = (window_datatype * )buf895d;
  window_init(window_buf895_buf895d, 1, buf895, LOCK_23_6_2_0, buf895d, LOCK_23_6_3_4096, 256, 256);
  window_internal window_buf893_buf893d[1];
  window_datatype * buf893_ptr = (window_datatype * )buf893;
  window_datatype * buf893d_ptr = (window_datatype * )buf893d;
  window_init(window_buf893_buf893d, 1, buf893, LOCK_23_5_6_0, buf893d, LOCK_23_5_7_0, 256, 256);
  window_internal window_buf896_buf896d[1];
  window_datatype * buf896_ptr = (window_datatype * )buf896;
  window_datatype * buf896d_ptr = (window_datatype * )buf896d;
  window_init(window_buf896_buf896d, 1, buf896, LOCK_23_6_4_4096, buf896d, LOCK_23_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_6_bounds = sync_buffer[1];

  while (proc_23_6_bounds)
  {

    // Kernel call : i528:mm_kernel1
    window_acquire(window_buf894_buf894d,LOCK_23_7_0_0,LOCK_23_7_1_0,buf894_ptr,buf894d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf895_buf895d,LOCK_23_6_2_0,LOCK_23_6_3_4096,buf895_ptr,buf895d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf893_buf893d,LOCK_23_5_6_0,LOCK_23_5_7_0,buf893_ptr,buf893d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf896_buf896d,LOCK_23_6_4_4096,LOCK_23_6_5_4096,buf896_ptr,buf896d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf894_buf894d),get_input_window_float(window_buf895_buf895d),get_input_window_float(window_buf893_buf893d),get_output_window_float(window_buf896_buf896d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf894_buf894d,LOCK_23_7_0_0,LOCK_23_7_1_0,buf894_ptr,buf894d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf895_buf895d,LOCK_23_6_2_0,LOCK_23_6_3_4096,buf895_ptr,buf895d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf893_buf893d,LOCK_23_5_6_0,LOCK_23_5_7_0,buf893_ptr,buf893d_ptr,0,index, REL_WRITE);
    window_release(window_buf896_buf896d,LOCK_23_6_4_4096,LOCK_23_6_5_4096,buf896_ptr,buf896d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_6_bounds > 0)
      --proc_23_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}