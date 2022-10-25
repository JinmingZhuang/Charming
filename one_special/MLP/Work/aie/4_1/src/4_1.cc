// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_1/src/4_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_0_2_4096 2
#define LOCK_4_0_3_4096 3
#define LOCK_4_1_4_0 20
#define LOCK_4_1_5_0 21
#define LOCK_4_1_2_4096 18
#define LOCK_4_1_3_4096 19
#define LOCK_4_1_6_4096 22
#define LOCK_4_1_7_4096 23

// Declare shared memory buffers
v4float buf26[256];
v4float buf26d[256];
v4float buf27[256];
v4float buf27d[256];
v4float buf28[256];
v4float buf28d[256];
v4float buf29[256];
v4float buf29d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf27_buf27d[1];
  window_datatype * buf27_ptr = (window_datatype * )buf27;
  window_datatype * buf27d_ptr = (window_datatype * )buf27d;
  window_init(window_buf27_buf27d, 1, buf27, LOCK_4_0_2_4096, buf27d, LOCK_4_0_3_4096, 256, 256);
  window_internal window_buf28_buf28d[1];
  window_datatype * buf28_ptr = (window_datatype * )buf28;
  window_datatype * buf28d_ptr = (window_datatype * )buf28d;
  window_init(window_buf28_buf28d, 1, buf28, LOCK_4_1_4_0, buf28d, LOCK_4_1_5_0, 256, 256);
  window_internal window_buf26_buf26d[1];
  window_datatype * buf26_ptr = (window_datatype * )buf26;
  window_datatype * buf26d_ptr = (window_datatype * )buf26d;
  window_init(window_buf26_buf26d, 1, buf26, LOCK_4_1_2_4096, buf26d, LOCK_4_1_3_4096, 256, 256);
  window_internal window_buf29_buf29d[1];
  window_datatype * buf29_ptr = (window_datatype * )buf29;
  window_datatype * buf29d_ptr = (window_datatype * )buf29d;
  window_init(window_buf29_buf29d, 1, buf29, LOCK_4_1_6_4096, buf29d, LOCK_4_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_1_bounds = sync_buffer[1];

  while (proc_4_1_bounds)
  {

    // Kernel call : i95:mm_kernel1
    window_acquire(window_buf27_buf27d,LOCK_4_0_2_4096,LOCK_4_0_3_4096,buf27_ptr,buf27d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf28_buf28d,LOCK_4_1_4_0,LOCK_4_1_5_0,buf28_ptr,buf28d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf26_buf26d,LOCK_4_1_2_4096,LOCK_4_1_3_4096,buf26_ptr,buf26d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf29_buf29d,LOCK_4_1_6_4096,LOCK_4_1_7_4096,buf29_ptr,buf29d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf27_buf27d),get_input_window_float(window_buf28_buf28d),get_input_window_float(window_buf26_buf26d),get_output_window_float(window_buf29_buf29d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf27_buf27d,LOCK_4_0_2_4096,LOCK_4_0_3_4096,buf27_ptr,buf27d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf28_buf28d,LOCK_4_1_4_0,LOCK_4_1_5_0,buf28_ptr,buf28d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf26_buf26d,LOCK_4_1_2_4096,LOCK_4_1_3_4096,buf26_ptr,buf26d_ptr,0,index, REL_WRITE);
    window_release(window_buf29_buf29d,LOCK_4_1_6_4096,LOCK_4_1_7_4096,buf29_ptr,buf29d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_1_bounds > 0)
      --proc_4_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}