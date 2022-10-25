// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_3/src/40_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_2_4_0 4
#define LOCK_40_2_5_0 5
#define LOCK_40_3_2_4096 18
#define LOCK_40_3_3_4096 19
#define LOCK_40_2_2_0 2
#define LOCK_40_2_3_4096 3
#define LOCK_40_2_6_4096 6
#define LOCK_40_2_7_4096 7

// Declare shared memory buffers
v4float buf464[256];
v4float buf464d[256];
v4float buf465[256];
v4float buf465d[256];
v4float buf466[256];
v4float buf466d[256];
v4float buf467[256];
v4float buf467d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf465_buf465d[1];
  window_datatype * buf465_ptr = (window_datatype * )buf465;
  window_datatype * buf465d_ptr = (window_datatype * )buf465d;
  window_init(window_buf465_buf465d, 1, buf465, LOCK_40_2_4_0, buf465d, LOCK_40_2_5_0, 256, 256);
  window_internal window_buf466_buf466d[1];
  window_datatype * buf466_ptr = (window_datatype * )buf466;
  window_datatype * buf466d_ptr = (window_datatype * )buf466d;
  window_init(window_buf466_buf466d, 1, buf466, LOCK_40_3_2_4096, buf466d, LOCK_40_3_3_4096, 256, 256);
  window_internal window_buf464_buf464d[1];
  window_datatype * buf464_ptr = (window_datatype * )buf464;
  window_datatype * buf464d_ptr = (window_datatype * )buf464d;
  window_init(window_buf464_buf464d, 1, buf464, LOCK_40_2_2_0, buf464d, LOCK_40_2_3_4096, 256, 256);
  window_internal window_buf467_buf467d[1];
  window_datatype * buf467_ptr = (window_datatype * )buf467;
  window_datatype * buf467d_ptr = (window_datatype * )buf467d;
  window_init(window_buf467_buf467d, 1, buf467, LOCK_40_2_6_4096, buf467d, LOCK_40_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_3_bounds = sync_buffer[1];

  while (proc_40_3_bounds)
  {

    // Kernel call : i313:mm_kernel1
    window_acquire(window_buf465_buf465d,LOCK_40_2_4_0,LOCK_40_2_5_0,buf465_ptr,buf465d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf466_buf466d,LOCK_40_3_2_4096,LOCK_40_3_3_4096,buf466_ptr,buf466d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf464_buf464d,LOCK_40_2_2_0,LOCK_40_2_3_4096,buf464_ptr,buf464d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf467_buf467d,LOCK_40_2_6_4096,LOCK_40_2_7_4096,buf467_ptr,buf467d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf465_buf465d),get_input_window_float(window_buf466_buf466d),get_input_window_float(window_buf464_buf464d),get_output_window_float(window_buf467_buf467d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf465_buf465d,LOCK_40_2_4_0,LOCK_40_2_5_0,buf465_ptr,buf465d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf466_buf466d,LOCK_40_3_2_4096,LOCK_40_3_3_4096,buf466_ptr,buf466d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf464_buf464d,LOCK_40_2_2_0,LOCK_40_2_3_4096,buf464_ptr,buf464d_ptr,0,index, REL_WRITE);
    window_release(window_buf467_buf467d,LOCK_40_2_6_4096,LOCK_40_2_7_4096,buf467_ptr,buf467d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_3_bounds > 0)
      --proc_40_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}