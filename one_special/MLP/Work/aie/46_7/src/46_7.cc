// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_7/src/46_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_7_4_0 20
#define LOCK_46_7_5_0 21
#define LOCK_47_7_6_4096 54
#define LOCK_47_7_7_4096 55
#define LOCK_46_7_2_0 18
#define LOCK_46_7_3_4096 19
#define LOCK_46_7_6_4096 22
#define LOCK_46_7_7_4096 23

// Declare shared memory buffers
v4float buf620[256];
v4float buf620d[256];
v4float buf621[256];
v4float buf621d[256];
v4float buf622[256];
v4float buf622d[256];
v4float buf623[256];
v4float buf623d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf621_buf621d[1];
  window_datatype * buf621_ptr = (window_datatype * )buf621;
  window_datatype * buf621d_ptr = (window_datatype * )buf621d;
  window_init(window_buf621_buf621d, 1, buf621, LOCK_46_7_4_0, buf621d, LOCK_46_7_5_0, 256, 256);
  window_internal window_buf622_buf622d[1];
  window_datatype * buf622_ptr = (window_datatype * )buf622;
  window_datatype * buf622d_ptr = (window_datatype * )buf622d;
  window_init(window_buf622_buf622d, 1, buf622, LOCK_47_7_6_4096, buf622d, LOCK_47_7_7_4096, 256, 256);
  window_internal window_buf620_buf620d[1];
  window_datatype * buf620_ptr = (window_datatype * )buf620;
  window_datatype * buf620d_ptr = (window_datatype * )buf620d;
  window_init(window_buf620_buf620d, 1, buf620, LOCK_46_7_2_0, buf620d, LOCK_46_7_3_4096, 256, 256);
  window_internal window_buf623_buf623d[1];
  window_datatype * buf623_ptr = (window_datatype * )buf623;
  window_datatype * buf623d_ptr = (window_datatype * )buf623d;
  window_init(window_buf623_buf623d, 1, buf623, LOCK_46_7_6_4096, buf623d, LOCK_46_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_7_bounds = sync_buffer[1];

  while (proc_46_7_bounds)
  {

    // Kernel call : i391:mm_kernel1
    window_acquire(window_buf621_buf621d,LOCK_46_7_4_0,LOCK_46_7_5_0,buf621_ptr,buf621d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf622_buf622d,LOCK_47_7_6_4096,LOCK_47_7_7_4096,buf622_ptr,buf622d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf620_buf620d,LOCK_46_7_2_0,LOCK_46_7_3_4096,buf620_ptr,buf620d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf623_buf623d,LOCK_46_7_6_4096,LOCK_46_7_7_4096,buf623_ptr,buf623d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf621_buf621d),get_input_window_float(window_buf622_buf622d),get_input_window_float(window_buf620_buf620d),get_output_window_float(window_buf623_buf623d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf621_buf621d,LOCK_46_7_4_0,LOCK_46_7_5_0,buf621_ptr,buf621d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf622_buf622d,LOCK_47_7_6_4096,LOCK_47_7_7_4096,buf622_ptr,buf622d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf620_buf620d,LOCK_46_7_2_0,LOCK_46_7_3_4096,buf620_ptr,buf620d_ptr,0,index, REL_WRITE);
    window_release(window_buf623_buf623d,LOCK_46_7_6_4096,LOCK_46_7_7_4096,buf623_ptr,buf623d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_7_bounds > 0)
      --proc_46_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}