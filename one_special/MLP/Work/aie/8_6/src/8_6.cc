// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_6/src/8_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_5_4_0 4
#define LOCK_8_5_5_4096 5
#define LOCK_8_5_6_4096 6
#define LOCK_8_5_7_4096 7
#define LOCK_8_5_2_4096 2
#define LOCK_8_5_3_0 3
#define LOCK_8_7_0_4096 32
#define LOCK_8_7_1_0 33

// Declare shared memory buffers
v4float buf1073[256];
v4float buf1073d[256];
v4float buf1074[256];
v4float buf1074d[256];
v4float buf1075[256];
v4float buf1075d[256];
v4float buf1076[256];
v4float buf1076d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1074_buf1074d[1];
  window_datatype * buf1074_ptr = (window_datatype * )buf1074;
  window_datatype * buf1074d_ptr = (window_datatype * )buf1074d;
  window_init(window_buf1074_buf1074d, 1, buf1074, LOCK_8_5_4_0, buf1074d, LOCK_8_5_5_4096, 256, 256);
  window_internal window_buf1075_buf1075d[1];
  window_datatype * buf1075_ptr = (window_datatype * )buf1075;
  window_datatype * buf1075d_ptr = (window_datatype * )buf1075d;
  window_init(window_buf1075_buf1075d, 1, buf1075, LOCK_8_5_6_4096, buf1075d, LOCK_8_5_7_4096, 256, 256);
  window_internal window_buf1073_buf1073d[1];
  window_datatype * buf1073_ptr = (window_datatype * )buf1073;
  window_datatype * buf1073d_ptr = (window_datatype * )buf1073d;
  window_init(window_buf1073_buf1073d, 1, buf1073, LOCK_8_5_2_4096, buf1073d, LOCK_8_5_3_0, 256, 256);
  window_internal window_buf1076_buf1076d[1];
  window_datatype * buf1076_ptr = (window_datatype * )buf1076;
  window_datatype * buf1076d_ptr = (window_datatype * )buf1076d;
  window_init(window_buf1076_buf1076d, 1, buf1076, LOCK_8_7_0_4096, buf1076d, LOCK_8_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_6_bounds = sync_buffer[1];

  while (proc_8_6_bounds)
  {

    // Kernel call : i618:mm_kernel1
    window_acquire(window_buf1074_buf1074d,LOCK_8_5_4_0,LOCK_8_5_5_4096,buf1074_ptr,buf1074d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1075_buf1075d,LOCK_8_5_6_4096,LOCK_8_5_7_4096,buf1075_ptr,buf1075d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1073_buf1073d,LOCK_8_5_2_4096,LOCK_8_5_3_0,buf1073_ptr,buf1073d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1076_buf1076d,LOCK_8_7_0_4096,LOCK_8_7_1_0,buf1076_ptr,buf1076d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1074_buf1074d),get_input_window_float(window_buf1075_buf1075d),get_input_window_float(window_buf1073_buf1073d),get_output_window_float(window_buf1076_buf1076d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1074_buf1074d,LOCK_8_5_4_0,LOCK_8_5_5_4096,buf1074_ptr,buf1074d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1075_buf1075d,LOCK_8_5_6_4096,LOCK_8_5_7_4096,buf1075_ptr,buf1075d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1073_buf1073d,LOCK_8_5_2_4096,LOCK_8_5_3_0,buf1073_ptr,buf1073d_ptr,0,index, REL_WRITE);
    window_release(window_buf1076_buf1076d,LOCK_8_7_0_4096,LOCK_8_7_1_0,buf1076_ptr,buf1076d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_6_bounds > 0)
      --proc_8_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}