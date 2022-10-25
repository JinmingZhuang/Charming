// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_2/src/35_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_3_0_0 32
#define LOCK_35_3_1_0 33
#define LOCK_35_2_0_4096 48
#define LOCK_35_2_1_0 49
#define LOCK_35_1_6_4096 6
#define LOCK_35_1_7_4096 7
#define LOCK_35_2_2_4096 50
#define LOCK_35_2_3_4096 51

// Declare shared memory buffers
v4float buf401[256];
v4float buf401d[256];
v4float buf402[256];
v4float buf402d[256];
v4float buf403[256];
v4float buf403d[256];
v4float buf404[256];
v4float buf404d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf402_buf402d[1];
  window_datatype * buf402_ptr = (window_datatype * )buf402;
  window_datatype * buf402d_ptr = (window_datatype * )buf402d;
  window_init(window_buf402_buf402d, 1, buf402, LOCK_35_3_0_0, buf402d, LOCK_35_3_1_0, 256, 256);
  window_internal window_buf403_buf403d[1];
  window_datatype * buf403_ptr = (window_datatype * )buf403;
  window_datatype * buf403d_ptr = (window_datatype * )buf403d;
  window_init(window_buf403_buf403d, 1, buf403, LOCK_35_2_0_4096, buf403d, LOCK_35_2_1_0, 256, 256);
  window_internal window_buf401_buf401d[1];
  window_datatype * buf401_ptr = (window_datatype * )buf401;
  window_datatype * buf401d_ptr = (window_datatype * )buf401d;
  window_init(window_buf401_buf401d, 1, buf401, LOCK_35_1_6_4096, buf401d, LOCK_35_1_7_4096, 256, 256);
  window_internal window_buf404_buf404d[1];
  window_datatype * buf404_ptr = (window_datatype * )buf404;
  window_datatype * buf404d_ptr = (window_datatype * )buf404d;
  window_init(window_buf404_buf404d, 1, buf404, LOCK_35_2_2_4096, buf404d, LOCK_35_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_2_bounds = sync_buffer[1];

  while (proc_35_2_bounds)
  {

    // Kernel call : i282:mm_kernel1
    window_acquire(window_buf402_buf402d,LOCK_35_3_0_0,LOCK_35_3_1_0,buf402_ptr,buf402d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf403_buf403d,LOCK_35_2_0_4096,LOCK_35_2_1_0,buf403_ptr,buf403d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf401_buf401d,LOCK_35_1_6_4096,LOCK_35_1_7_4096,buf401_ptr,buf401d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf404_buf404d,LOCK_35_2_2_4096,LOCK_35_2_3_4096,buf404_ptr,buf404d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf402_buf402d),get_input_window_float(window_buf403_buf403d),get_input_window_float(window_buf401_buf401d),get_output_window_float(window_buf404_buf404d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf402_buf402d,LOCK_35_3_0_0,LOCK_35_3_1_0,buf402_ptr,buf402d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf403_buf403d,LOCK_35_2_0_4096,LOCK_35_2_1_0,buf403_ptr,buf403d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf401_buf401d,LOCK_35_1_6_4096,LOCK_35_1_7_4096,buf401_ptr,buf401d_ptr,0,index, REL_WRITE);
    window_release(window_buf404_buf404d,LOCK_35_2_2_4096,LOCK_35_2_3_4096,buf404_ptr,buf404d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_2_bounds > 0)
      --proc_35_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}