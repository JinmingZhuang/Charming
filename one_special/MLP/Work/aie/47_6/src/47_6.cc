// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_6/src/47_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_6_0_0 48
#define LOCK_47_6_1_0 49
#define LOCK_46_6_0_0 16
#define LOCK_46_6_1_0 17
#define LOCK_47_5_6_4096 6
#define LOCK_47_5_7_4096 7
#define LOCK_47_7_0_0 32
#define LOCK_47_7_1_0 33

// Declare shared memory buffers
v4float buf605[256];
v4float buf605d[256];
v4float buf606[256];
v4float buf606d[256];
v4float buf607[256];
v4float buf607d[256];
v4float buf608[256];
v4float buf608d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf606_buf606d[1];
  window_datatype * buf606_ptr = (window_datatype * )buf606;
  window_datatype * buf606d_ptr = (window_datatype * )buf606d;
  window_init(window_buf606_buf606d, 1, buf606, LOCK_47_6_0_0, buf606d, LOCK_47_6_1_0, 256, 256);
  window_internal window_buf607_buf607d[1];
  window_datatype * buf607_ptr = (window_datatype * )buf607;
  window_datatype * buf607d_ptr = (window_datatype * )buf607d;
  window_init(window_buf607_buf607d, 1, buf607, LOCK_46_6_0_0, buf607d, LOCK_46_6_1_0, 256, 256);
  window_internal window_buf605_buf605d[1];
  window_datatype * buf605_ptr = (window_datatype * )buf605;
  window_datatype * buf605d_ptr = (window_datatype * )buf605d;
  window_init(window_buf605_buf605d, 1, buf605, LOCK_47_5_6_4096, buf605d, LOCK_47_5_7_4096, 256, 256);
  window_internal window_buf608_buf608d[1];
  window_datatype * buf608_ptr = (window_datatype * )buf608;
  window_datatype * buf608d_ptr = (window_datatype * )buf608d;
  window_init(window_buf608_buf608d, 1, buf608, LOCK_47_7_0_0, buf608d, LOCK_47_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_6_bounds = sync_buffer[1];

  while (proc_47_6_bounds)
  {

    // Kernel call : i384:mm_kernel1
    window_acquire(window_buf606_buf606d,LOCK_47_6_0_0,LOCK_47_6_1_0,buf606_ptr,buf606d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf607_buf607d,LOCK_46_6_0_0,LOCK_46_6_1_0,buf607_ptr,buf607d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf605_buf605d,LOCK_47_5_6_4096,LOCK_47_5_7_4096,buf605_ptr,buf605d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf608_buf608d,LOCK_47_7_0_0,LOCK_47_7_1_0,buf608_ptr,buf608d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf606_buf606d),get_input_window_float(window_buf607_buf607d),get_input_window_float(window_buf605_buf605d),get_output_window_float(window_buf608_buf608d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf606_buf606d,LOCK_47_6_0_0,LOCK_47_6_1_0,buf606_ptr,buf606d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf607_buf607d,LOCK_46_6_0_0,LOCK_46_6_1_0,buf607_ptr,buf607d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf605_buf605d,LOCK_47_5_6_4096,LOCK_47_5_7_4096,buf605_ptr,buf605d_ptr,0,index, REL_WRITE);
    window_release(window_buf608_buf608d,LOCK_47_7_0_0,LOCK_47_7_1_0,buf608_ptr,buf608d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_6_bounds > 0)
      --proc_47_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}