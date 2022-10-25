// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_2/src/5_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_1_6_0 6
#define LOCK_5_1_7_4096 7
#define LOCK_5_3_0_4096 32
#define LOCK_5_3_1_4096 33
#define LOCK_5_1_4_4096 4
#define LOCK_5_1_5_0 5
#define LOCK_5_3_2_4096 34
#define LOCK_5_3_3_4096 35

// Declare shared memory buffers
v4float buf41[256];
v4float buf41d[256];
v4float buf42[256];
v4float buf42d[256];
v4float buf43[256];
v4float buf43d[256];
v4float buf44[256];
v4float buf44d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf42_buf42d[1];
  window_datatype * buf42_ptr = (window_datatype * )buf42;
  window_datatype * buf42d_ptr = (window_datatype * )buf42d;
  window_init(window_buf42_buf42d, 1, buf42, LOCK_5_1_6_0, buf42d, LOCK_5_1_7_4096, 256, 256);
  window_internal window_buf43_buf43d[1];
  window_datatype * buf43_ptr = (window_datatype * )buf43;
  window_datatype * buf43d_ptr = (window_datatype * )buf43d;
  window_init(window_buf43_buf43d, 1, buf43, LOCK_5_3_0_4096, buf43d, LOCK_5_3_1_4096, 256, 256);
  window_internal window_buf41_buf41d[1];
  window_datatype * buf41_ptr = (window_datatype * )buf41;
  window_datatype * buf41d_ptr = (window_datatype * )buf41d;
  window_init(window_buf41_buf41d, 1, buf41, LOCK_5_1_4_4096, buf41d, LOCK_5_1_5_0, 256, 256);
  window_internal window_buf44_buf44d[1];
  window_datatype * buf44_ptr = (window_datatype * )buf44;
  window_datatype * buf44d_ptr = (window_datatype * )buf44d;
  window_init(window_buf44_buf44d, 1, buf44, LOCK_5_3_2_4096, buf44d, LOCK_5_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_2_bounds = sync_buffer[1];

  while (proc_5_2_bounds)
  {

    // Kernel call : i102:mm_kernel1
    window_acquire(window_buf42_buf42d,LOCK_5_1_6_0,LOCK_5_1_7_4096,buf42_ptr,buf42d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf43_buf43d,LOCK_5_3_0_4096,LOCK_5_3_1_4096,buf43_ptr,buf43d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf41_buf41d,LOCK_5_1_4_4096,LOCK_5_1_5_0,buf41_ptr,buf41d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf44_buf44d,LOCK_5_3_2_4096,LOCK_5_3_3_4096,buf44_ptr,buf44d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf42_buf42d),get_input_window_float(window_buf43_buf43d),get_input_window_float(window_buf41_buf41d),get_output_window_float(window_buf44_buf44d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf42_buf42d,LOCK_5_1_6_0,LOCK_5_1_7_4096,buf42_ptr,buf42d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf43_buf43d,LOCK_5_3_0_4096,LOCK_5_3_1_4096,buf43_ptr,buf43d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf41_buf41d,LOCK_5_1_4_4096,LOCK_5_1_5_0,buf41_ptr,buf41d_ptr,0,index, REL_WRITE);
    window_release(window_buf44_buf44d,LOCK_5_3_2_4096,LOCK_5_3_3_4096,buf44_ptr,buf44d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_2_bounds > 0)
      --proc_5_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}