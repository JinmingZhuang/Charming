// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_5/src/47_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_5_4_0 20
#define LOCK_47_5_5_0 21
#define LOCK_47_4_2_4096 2
#define LOCK_47_4_3_4096 3
#define LOCK_47_5_2_0 18
#define LOCK_47_5_3_4096 19
#define LOCK_47_5_6_4096 22
#define LOCK_47_5_7_4096 23

// Declare shared memory buffers
v4float buf602[256];
v4float buf602d[256];
v4float buf603[256];
v4float buf603d[256];
v4float buf604[256];
v4float buf604d[256];
v4float buf605[256];
v4float buf605d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf603_buf603d[1];
  window_datatype * buf603_ptr = (window_datatype * )buf603;
  window_datatype * buf603d_ptr = (window_datatype * )buf603d;
  window_init(window_buf603_buf603d, 1, buf603, LOCK_47_5_4_0, buf603d, LOCK_47_5_5_0, 256, 256);
  window_internal window_buf604_buf604d[1];
  window_datatype * buf604_ptr = (window_datatype * )buf604;
  window_datatype * buf604d_ptr = (window_datatype * )buf604d;
  window_init(window_buf604_buf604d, 1, buf604, LOCK_47_4_2_4096, buf604d, LOCK_47_4_3_4096, 256, 256);
  window_internal window_buf602_buf602d[1];
  window_datatype * buf602_ptr = (window_datatype * )buf602;
  window_datatype * buf602d_ptr = (window_datatype * )buf602d;
  window_init(window_buf602_buf602d, 1, buf602, LOCK_47_5_2_0, buf602d, LOCK_47_5_3_4096, 256, 256);
  window_internal window_buf605_buf605d[1];
  window_datatype * buf605_ptr = (window_datatype * )buf605;
  window_datatype * buf605d_ptr = (window_datatype * )buf605d;
  window_init(window_buf605_buf605d, 1, buf605, LOCK_47_5_6_4096, buf605d, LOCK_47_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_5_bounds = sync_buffer[1];

  while (proc_47_5_bounds)
  {

    // Kernel call : i383:mm_kernel1
    window_acquire(window_buf603_buf603d,LOCK_47_5_4_0,LOCK_47_5_5_0,buf603_ptr,buf603d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf604_buf604d,LOCK_47_4_2_4096,LOCK_47_4_3_4096,buf604_ptr,buf604d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf602_buf602d,LOCK_47_5_2_0,LOCK_47_5_3_4096,buf602_ptr,buf602d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf605_buf605d,LOCK_47_5_6_4096,LOCK_47_5_7_4096,buf605_ptr,buf605d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf603_buf603d),get_input_window_float(window_buf604_buf604d),get_input_window_float(window_buf602_buf602d),get_output_window_float(window_buf605_buf605d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf603_buf603d,LOCK_47_5_4_0,LOCK_47_5_5_0,buf603_ptr,buf603d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf604_buf604d,LOCK_47_4_2_4096,LOCK_47_4_3_4096,buf604_ptr,buf604d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf602_buf602d,LOCK_47_5_2_0,LOCK_47_5_3_4096,buf602_ptr,buf602d_ptr,0,index, REL_WRITE);
    window_release(window_buf605_buf605d,LOCK_47_5_6_4096,LOCK_47_5_7_4096,buf605_ptr,buf605d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_5_bounds > 0)
      --proc_47_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}