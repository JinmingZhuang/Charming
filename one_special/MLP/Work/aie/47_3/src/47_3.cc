// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_3/src/47_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_3_2_4096 18
#define LOCK_47_3_3_4096 19
#define LOCK_47_2_4_0 4
#define LOCK_47_2_5_0 5
#define LOCK_47_2_2_4096 2
#define LOCK_47_2_3_4096 3
#define LOCK_47_2_6_4096 6
#define LOCK_47_2_7_4096 7

// Declare shared memory buffers
v4float buf548[256];
v4float buf548d[256];
v4float buf549[256];
v4float buf549d[256];
v4float buf550[256];
v4float buf550d[256];
v4float buf551[256];
v4float buf551d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf549_buf549d[1];
  window_datatype * buf549_ptr = (window_datatype * )buf549;
  window_datatype * buf549d_ptr = (window_datatype * )buf549d;
  window_init(window_buf549_buf549d, 1, buf549, LOCK_47_3_2_4096, buf549d, LOCK_47_3_3_4096, 256, 256);
  window_internal window_buf550_buf550d[1];
  window_datatype * buf550_ptr = (window_datatype * )buf550;
  window_datatype * buf550d_ptr = (window_datatype * )buf550d;
  window_init(window_buf550_buf550d, 1, buf550, LOCK_47_2_4_0, buf550d, LOCK_47_2_5_0, 256, 256);
  window_internal window_buf548_buf548d[1];
  window_datatype * buf548_ptr = (window_datatype * )buf548;
  window_datatype * buf548d_ptr = (window_datatype * )buf548d;
  window_init(window_buf548_buf548d, 1, buf548, LOCK_47_2_2_4096, buf548d, LOCK_47_2_3_4096, 256, 256);
  window_internal window_buf551_buf551d[1];
  window_datatype * buf551_ptr = (window_datatype * )buf551;
  window_datatype * buf551d_ptr = (window_datatype * )buf551d;
  window_init(window_buf551_buf551d, 1, buf551, LOCK_47_2_6_4096, buf551d, LOCK_47_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_3_bounds = sync_buffer[1];

  while (proc_47_3_bounds)
  {

    // Kernel call : i355:mm_kernel1
    window_acquire(window_buf549_buf549d,LOCK_47_3_2_4096,LOCK_47_3_3_4096,buf549_ptr,buf549d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf550_buf550d,LOCK_47_2_4_0,LOCK_47_2_5_0,buf550_ptr,buf550d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf548_buf548d,LOCK_47_2_2_4096,LOCK_47_2_3_4096,buf548_ptr,buf548d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf551_buf551d,LOCK_47_2_6_4096,LOCK_47_2_7_4096,buf551_ptr,buf551d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf549_buf549d),get_input_window_float(window_buf550_buf550d),get_input_window_float(window_buf548_buf548d),get_output_window_float(window_buf551_buf551d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf549_buf549d,LOCK_47_3_2_4096,LOCK_47_3_3_4096,buf549_ptr,buf549d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf550_buf550d,LOCK_47_2_4_0,LOCK_47_2_5_0,buf550_ptr,buf550d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf548_buf548d,LOCK_47_2_2_4096,LOCK_47_2_3_4096,buf548_ptr,buf548d_ptr,0,index, REL_WRITE);
    window_release(window_buf551_buf551d,LOCK_47_2_6_4096,LOCK_47_2_7_4096,buf551_ptr,buf551d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_3_bounds > 0)
      --proc_47_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}