// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_6/src/10_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_6_0_0 16
#define LOCK_9_6_1_0 17
#define LOCK_10_6_2_4096 50
#define LOCK_10_6_3_4096 51
#define LOCK_10_5_4_0 4
#define LOCK_10_5_5_4096 5
#define LOCK_10_7_0_0 32
#define LOCK_10_7_1_4096 33

// Declare shared memory buffers
v4float buf1049[256];
v4float buf1049d[256];
v4float buf1050[256];
v4float buf1050d[256];
v4float buf1051[256];
v4float buf1051d[256];
v4float buf1052[256];
v4float buf1052d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1050_buf1050d[1];
  window_datatype * buf1050_ptr = (window_datatype * )buf1050;
  window_datatype * buf1050d_ptr = (window_datatype * )buf1050d;
  window_init(window_buf1050_buf1050d, 1, buf1050, LOCK_9_6_0_0, buf1050d, LOCK_9_6_1_0, 256, 256);
  window_internal window_buf1051_buf1051d[1];
  window_datatype * buf1051_ptr = (window_datatype * )buf1051;
  window_datatype * buf1051d_ptr = (window_datatype * )buf1051d;
  window_init(window_buf1051_buf1051d, 1, buf1051, LOCK_10_6_2_4096, buf1051d, LOCK_10_6_3_4096, 256, 256);
  window_internal window_buf1049_buf1049d[1];
  window_datatype * buf1049_ptr = (window_datatype * )buf1049;
  window_datatype * buf1049d_ptr = (window_datatype * )buf1049d;
  window_init(window_buf1049_buf1049d, 1, buf1049, LOCK_10_5_4_0, buf1049d, LOCK_10_5_5_4096, 256, 256);
  window_internal window_buf1052_buf1052d[1];
  window_datatype * buf1052_ptr = (window_datatype * )buf1052;
  window_datatype * buf1052d_ptr = (window_datatype * )buf1052d;
  window_init(window_buf1052_buf1052d, 1, buf1052, LOCK_10_7_0_0, buf1052d, LOCK_10_7_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_6_bounds = sync_buffer[1];

  while (proc_10_6_bounds)
  {

    // Kernel call : i606:mm_kernel1
    window_acquire(window_buf1050_buf1050d,LOCK_9_6_0_0,LOCK_9_6_1_0,buf1050_ptr,buf1050d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1051_buf1051d,LOCK_10_6_2_4096,LOCK_10_6_3_4096,buf1051_ptr,buf1051d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1049_buf1049d,LOCK_10_5_4_0,LOCK_10_5_5_4096,buf1049_ptr,buf1049d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1052_buf1052d,LOCK_10_7_0_0,LOCK_10_7_1_4096,buf1052_ptr,buf1052d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1050_buf1050d),get_input_window_float(window_buf1051_buf1051d),get_input_window_float(window_buf1049_buf1049d),get_output_window_float(window_buf1052_buf1052d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1050_buf1050d,LOCK_9_6_0_0,LOCK_9_6_1_0,buf1050_ptr,buf1050d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1051_buf1051d,LOCK_10_6_2_4096,LOCK_10_6_3_4096,buf1051_ptr,buf1051d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1049_buf1049d,LOCK_10_5_4_0,LOCK_10_5_5_4096,buf1049_ptr,buf1049d_ptr,0,index, REL_WRITE);
    window_release(window_buf1052_buf1052d,LOCK_10_7_0_0,LOCK_10_7_1_4096,buf1052_ptr,buf1052d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_6_bounds > 0)
      --proc_10_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}