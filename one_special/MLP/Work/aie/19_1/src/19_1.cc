// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_1/src/19_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_1_0_0 48
#define LOCK_20_1_1_0 49
#define LOCK_19_0_0_0 0
#define LOCK_19_0_1_0 1
#define LOCK_19_1_2_0 18
#define LOCK_19_1_3_0 19
#define LOCK_19_1_4_0 20
#define LOCK_19_1_5_0 21

// Declare shared memory buffers
v4float buf206[256];
v4float buf206d[256];
v4float buf207[256];
v4float buf207d[256];
v4float buf208[256];
v4float buf208d[256];
v4float buf209[256];
v4float buf209d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf207_buf207d[1];
  window_datatype * buf207_ptr = (window_datatype * )buf207;
  window_datatype * buf207d_ptr = (window_datatype * )buf207d;
  window_init(window_buf207_buf207d, 1, buf207, LOCK_20_1_0_0, buf207d, LOCK_20_1_1_0, 256, 256);
  window_internal window_buf208_buf208d[1];
  window_datatype * buf208_ptr = (window_datatype * )buf208;
  window_datatype * buf208d_ptr = (window_datatype * )buf208d;
  window_init(window_buf208_buf208d, 1, buf208, LOCK_19_0_0_0, buf208d, LOCK_19_0_1_0, 256, 256);
  window_internal window_buf206_buf206d[1];
  window_datatype * buf206_ptr = (window_datatype * )buf206;
  window_datatype * buf206d_ptr = (window_datatype * )buf206d;
  window_init(window_buf206_buf206d, 1, buf206, LOCK_19_1_2_0, buf206d, LOCK_19_1_3_0, 256, 256);
  window_internal window_buf209_buf209d[1];
  window_datatype * buf209_ptr = (window_datatype * )buf209;
  window_datatype * buf209d_ptr = (window_datatype * )buf209d;
  window_init(window_buf209_buf209d, 1, buf209, LOCK_19_1_4_0, buf209d, LOCK_19_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_1_bounds = sync_buffer[1];

  while (proc_19_1_bounds)
  {

    // Kernel call : i185:mm_kernel1
    window_acquire(window_buf207_buf207d,LOCK_20_1_0_0,LOCK_20_1_1_0,buf207_ptr,buf207d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf208_buf208d,LOCK_19_0_0_0,LOCK_19_0_1_0,buf208_ptr,buf208d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf206_buf206d,LOCK_19_1_2_0,LOCK_19_1_3_0,buf206_ptr,buf206d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf209_buf209d,LOCK_19_1_4_0,LOCK_19_1_5_0,buf209_ptr,buf209d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf207_buf207d),get_input_window_float(window_buf208_buf208d),get_input_window_float(window_buf206_buf206d),get_output_window_float(window_buf209_buf209d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf207_buf207d,LOCK_20_1_0_0,LOCK_20_1_1_0,buf207_ptr,buf207d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf208_buf208d,LOCK_19_0_0_0,LOCK_19_0_1_0,buf208_ptr,buf208d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf206_buf206d,LOCK_19_1_2_0,LOCK_19_1_3_0,buf206_ptr,buf206d_ptr,0,index, REL_WRITE);
    window_release(window_buf209_buf209d,LOCK_19_1_4_0,LOCK_19_1_5_0,buf209_ptr,buf209d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_1_bounds > 0)
      --proc_19_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}