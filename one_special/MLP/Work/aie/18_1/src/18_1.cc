// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_1/src/18_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_0_0_0 0
#define LOCK_18_0_1_0 1
#define LOCK_18_2_0_0 32
#define LOCK_18_2_1_0 33
#define LOCK_18_1_4_0 20
#define LOCK_18_1_5_0 21
#define LOCK_18_1_6_4096 22
#define LOCK_18_1_7_0 23

// Declare shared memory buffers
v4float buf194[256];
v4float buf194d[256];
v4float buf195[256];
v4float buf195d[256];
v4float buf196[256];
v4float buf196d[256];
v4float buf197[256];
v4float buf197d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf195_buf195d[1];
  window_datatype * buf195_ptr = (window_datatype * )buf195;
  window_datatype * buf195d_ptr = (window_datatype * )buf195d;
  window_init(window_buf195_buf195d, 1, buf195, LOCK_18_0_0_0, buf195d, LOCK_18_0_1_0, 256, 256);
  window_internal window_buf196_buf196d[1];
  window_datatype * buf196_ptr = (window_datatype * )buf196;
  window_datatype * buf196d_ptr = (window_datatype * )buf196d;
  window_init(window_buf196_buf196d, 1, buf196, LOCK_18_2_0_0, buf196d, LOCK_18_2_1_0, 256, 256);
  window_internal window_buf194_buf194d[1];
  window_datatype * buf194_ptr = (window_datatype * )buf194;
  window_datatype * buf194d_ptr = (window_datatype * )buf194d;
  window_init(window_buf194_buf194d, 1, buf194, LOCK_18_1_4_0, buf194d, LOCK_18_1_5_0, 256, 256);
  window_internal window_buf197_buf197d[1];
  window_datatype * buf197_ptr = (window_datatype * )buf197;
  window_datatype * buf197d_ptr = (window_datatype * )buf197d;
  window_init(window_buf197_buf197d, 1, buf197, LOCK_18_1_6_4096, buf197d, LOCK_18_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_1_bounds = sync_buffer[1];

  while (proc_18_1_bounds)
  {

    // Kernel call : i179:mm_kernel1
    window_acquire(window_buf195_buf195d,LOCK_18_0_0_0,LOCK_18_0_1_0,buf195_ptr,buf195d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf196_buf196d,LOCK_18_2_0_0,LOCK_18_2_1_0,buf196_ptr,buf196d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf194_buf194d,LOCK_18_1_4_0,LOCK_18_1_5_0,buf194_ptr,buf194d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf197_buf197d,LOCK_18_1_6_4096,LOCK_18_1_7_0,buf197_ptr,buf197d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf195_buf195d),get_input_window_float(window_buf196_buf196d),get_input_window_float(window_buf194_buf194d),get_output_window_float(window_buf197_buf197d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf195_buf195d,LOCK_18_0_0_0,LOCK_18_0_1_0,buf195_ptr,buf195d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf196_buf196d,LOCK_18_2_0_0,LOCK_18_2_1_0,buf196_ptr,buf196d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf194_buf194d,LOCK_18_1_4_0,LOCK_18_1_5_0,buf194_ptr,buf194d_ptr,0,index, REL_WRITE);
    window_release(window_buf197_buf197d,LOCK_18_1_6_4096,LOCK_18_1_7_0,buf197_ptr,buf197d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_1_bounds > 0)
      --proc_18_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}