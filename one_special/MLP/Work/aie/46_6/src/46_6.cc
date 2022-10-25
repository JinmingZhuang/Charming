// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_6/src/46_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_6_2_4096 50
#define LOCK_46_6_3_4096 51
#define LOCK_46_7_0_4096 32
#define LOCK_46_7_1_0 33
#define LOCK_46_5_6_4096 6
#define LOCK_46_5_7_4096 7
#define LOCK_46_7_2_0 34
#define LOCK_46_7_3_4096 35

// Declare shared memory buffers
v4float buf617[256];
v4float buf617d[256];
v4float buf618[256];
v4float buf618d[256];
v4float buf619[256];
v4float buf619d[256];
v4float buf620[256];
v4float buf620d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf618_buf618d[1];
  window_datatype * buf618_ptr = (window_datatype * )buf618;
  window_datatype * buf618d_ptr = (window_datatype * )buf618d;
  window_init(window_buf618_buf618d, 1, buf618, LOCK_46_6_2_4096, buf618d, LOCK_46_6_3_4096, 256, 256);
  window_internal window_buf619_buf619d[1];
  window_datatype * buf619_ptr = (window_datatype * )buf619;
  window_datatype * buf619d_ptr = (window_datatype * )buf619d;
  window_init(window_buf619_buf619d, 1, buf619, LOCK_46_7_0_4096, buf619d, LOCK_46_7_1_0, 256, 256);
  window_internal window_buf617_buf617d[1];
  window_datatype * buf617_ptr = (window_datatype * )buf617;
  window_datatype * buf617d_ptr = (window_datatype * )buf617d;
  window_init(window_buf617_buf617d, 1, buf617, LOCK_46_5_6_4096, buf617d, LOCK_46_5_7_4096, 256, 256);
  window_internal window_buf620_buf620d[1];
  window_datatype * buf620_ptr = (window_datatype * )buf620;
  window_datatype * buf620d_ptr = (window_datatype * )buf620d;
  window_init(window_buf620_buf620d, 1, buf620, LOCK_46_7_2_0, buf620d, LOCK_46_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_6_bounds = sync_buffer[1];

  while (proc_46_6_bounds)
  {

    // Kernel call : i390:mm_kernel1
    window_acquire(window_buf618_buf618d,LOCK_46_6_2_4096,LOCK_46_6_3_4096,buf618_ptr,buf618d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf619_buf619d,LOCK_46_7_0_4096,LOCK_46_7_1_0,buf619_ptr,buf619d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf617_buf617d,LOCK_46_5_6_4096,LOCK_46_5_7_4096,buf617_ptr,buf617d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf620_buf620d,LOCK_46_7_2_0,LOCK_46_7_3_4096,buf620_ptr,buf620d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf618_buf618d),get_input_window_float(window_buf619_buf619d),get_input_window_float(window_buf617_buf617d),get_output_window_float(window_buf620_buf620d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf618_buf618d,LOCK_46_6_2_4096,LOCK_46_6_3_4096,buf618_ptr,buf618d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf619_buf619d,LOCK_46_7_0_4096,LOCK_46_7_1_0,buf619_ptr,buf619d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf617_buf617d,LOCK_46_5_6_4096,LOCK_46_5_7_4096,buf617_ptr,buf617d_ptr,0,index, REL_WRITE);
    window_release(window_buf620_buf620d,LOCK_46_7_2_0,LOCK_46_7_3_4096,buf620_ptr,buf620d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_6_bounds > 0)
      --proc_46_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}