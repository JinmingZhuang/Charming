// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_7/src/47_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_6_2_4096 2
#define LOCK_47_6_3_4096 3
#define LOCK_47_7_2_4096 18
#define LOCK_47_7_3_4096 19
#define LOCK_47_7_0_0 16
#define LOCK_47_7_1_0 17
#define LOCK_47_7_4_0 20
#define LOCK_47_7_5_0 21

// Declare shared memory buffers
v4float buf608[256];
v4float buf608d[256];
v4float buf609[256];
v4float buf609d[256];
v4float buf610[256];
v4float buf610d[256];
v4float buf611[256];
v4float buf611d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf609_buf609d[1];
  window_datatype * buf609_ptr = (window_datatype * )buf609;
  window_datatype * buf609d_ptr = (window_datatype * )buf609d;
  window_init(window_buf609_buf609d, 1, buf609, LOCK_47_6_2_4096, buf609d, LOCK_47_6_3_4096, 256, 256);
  window_internal window_buf610_buf610d[1];
  window_datatype * buf610_ptr = (window_datatype * )buf610;
  window_datatype * buf610d_ptr = (window_datatype * )buf610d;
  window_init(window_buf610_buf610d, 1, buf610, LOCK_47_7_2_4096, buf610d, LOCK_47_7_3_4096, 256, 256);
  window_internal window_buf608_buf608d[1];
  window_datatype * buf608_ptr = (window_datatype * )buf608;
  window_datatype * buf608d_ptr = (window_datatype * )buf608d;
  window_init(window_buf608_buf608d, 1, buf608, LOCK_47_7_0_0, buf608d, LOCK_47_7_1_0, 256, 256);
  window_internal window_buf611_buf611d[1];
  window_datatype * buf611_ptr = (window_datatype * )buf611;
  window_datatype * buf611d_ptr = (window_datatype * )buf611d;
  window_init(window_buf611_buf611d, 1, buf611, LOCK_47_7_4_0, buf611d, LOCK_47_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_7_bounds = sync_buffer[1];

  while (proc_47_7_bounds)
  {

    // Kernel call : i385:mm_kernel1
    window_acquire(window_buf609_buf609d,LOCK_47_6_2_4096,LOCK_47_6_3_4096,buf609_ptr,buf609d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf610_buf610d,LOCK_47_7_2_4096,LOCK_47_7_3_4096,buf610_ptr,buf610d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf608_buf608d,LOCK_47_7_0_0,LOCK_47_7_1_0,buf608_ptr,buf608d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf611_buf611d,LOCK_47_7_4_0,LOCK_47_7_5_0,buf611_ptr,buf611d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf609_buf609d),get_input_window_float(window_buf610_buf610d),get_input_window_float(window_buf608_buf608d),get_output_window_float(window_buf611_buf611d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf609_buf609d,LOCK_47_6_2_4096,LOCK_47_6_3_4096,buf609_ptr,buf609d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf610_buf610d,LOCK_47_7_2_4096,LOCK_47_7_3_4096,buf610_ptr,buf610d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf608_buf608d,LOCK_47_7_0_0,LOCK_47_7_1_0,buf608_ptr,buf608d_ptr,0,index, REL_WRITE);
    window_release(window_buf611_buf611d,LOCK_47_7_4_0,LOCK_47_7_5_0,buf611_ptr,buf611d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_7_bounds > 0)
      --proc_47_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}