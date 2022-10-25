// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_7/src/34_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_7_2_4096 18
#define LOCK_34_7_3_4096 19
#define LOCK_34_6_4_4096 4
#define LOCK_34_6_5_0 5
#define LOCK_34_6_2_4096 2
#define LOCK_34_6_3_4096 3
#define LOCK_34_6_6_0 6
#define LOCK_34_6_7_0 7

// Declare shared memory buffers
v4float buf764[256];
v4float buf764d[256];
v4float buf765[256];
v4float buf765d[256];
v4float buf766[256];
v4float buf766d[256];
v4float buf767[256];
v4float buf767d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf765_buf765d[1];
  window_datatype * buf765_ptr = (window_datatype * )buf765;
  window_datatype * buf765d_ptr = (window_datatype * )buf765d;
  window_init(window_buf765_buf765d, 1, buf765, LOCK_34_7_2_4096, buf765d, LOCK_34_7_3_4096, 256, 256);
  window_internal window_buf766_buf766d[1];
  window_datatype * buf766_ptr = (window_datatype * )buf766;
  window_datatype * buf766d_ptr = (window_datatype * )buf766d;
  window_init(window_buf766_buf766d, 1, buf766, LOCK_34_6_4_4096, buf766d, LOCK_34_6_5_0, 256, 256);
  window_internal window_buf764_buf764d[1];
  window_datatype * buf764_ptr = (window_datatype * )buf764;
  window_datatype * buf764d_ptr = (window_datatype * )buf764d;
  window_init(window_buf764_buf764d, 1, buf764, LOCK_34_6_2_4096, buf764d, LOCK_34_6_3_4096, 256, 256);
  window_internal window_buf767_buf767d[1];
  window_datatype * buf767_ptr = (window_datatype * )buf767;
  window_datatype * buf767d_ptr = (window_datatype * )buf767d;
  window_init(window_buf767_buf767d, 1, buf767, LOCK_34_6_6_0, buf767d, LOCK_34_6_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_7_bounds = sync_buffer[1];

  while (proc_34_7_bounds)
  {

    // Kernel call : i463:mm_kernel1
    window_acquire(window_buf765_buf765d,LOCK_34_7_2_4096,LOCK_34_7_3_4096,buf765_ptr,buf765d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf766_buf766d,LOCK_34_6_4_4096,LOCK_34_6_5_0,buf766_ptr,buf766d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf764_buf764d,LOCK_34_6_2_4096,LOCK_34_6_3_4096,buf764_ptr,buf764d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf767_buf767d,LOCK_34_6_6_0,LOCK_34_6_7_0,buf767_ptr,buf767d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf765_buf765d),get_input_window_float(window_buf766_buf766d),get_input_window_float(window_buf764_buf764d),get_output_window_float(window_buf767_buf767d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf765_buf765d,LOCK_34_7_2_4096,LOCK_34_7_3_4096,buf765_ptr,buf765d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf766_buf766d,LOCK_34_6_4_4096,LOCK_34_6_5_0,buf766_ptr,buf766d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf764_buf764d,LOCK_34_6_2_4096,LOCK_34_6_3_4096,buf764_ptr,buf764d_ptr,0,index, REL_WRITE);
    window_release(window_buf767_buf767d,LOCK_34_6_6_0,LOCK_34_6_7_0,buf767_ptr,buf767d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_7_bounds > 0)
      --proc_34_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}