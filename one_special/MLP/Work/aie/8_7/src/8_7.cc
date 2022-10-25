// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_7/src/8_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_7_2_0 18
#define LOCK_8_7_3_4096 19
#define LOCK_8_6_2_4096 2
#define LOCK_8_6_3_4096 3
#define LOCK_8_7_0_4096 16
#define LOCK_8_7_1_0 17
#define LOCK_8_7_4_0 20
#define LOCK_8_7_5_0 21

// Declare shared memory buffers
v4float buf1076[256];
v4float buf1076d[256];
v4float buf1077[256];
v4float buf1077d[256];
v4float buf1078[256];
v4float buf1078d[256];
v4float buf1079[256];
v4float buf1079d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1077_buf1077d[1];
  window_datatype * buf1077_ptr = (window_datatype * )buf1077;
  window_datatype * buf1077d_ptr = (window_datatype * )buf1077d;
  window_init(window_buf1077_buf1077d, 1, buf1077, LOCK_8_7_2_0, buf1077d, LOCK_8_7_3_4096, 256, 256);
  window_internal window_buf1078_buf1078d[1];
  window_datatype * buf1078_ptr = (window_datatype * )buf1078;
  window_datatype * buf1078d_ptr = (window_datatype * )buf1078d;
  window_init(window_buf1078_buf1078d, 1, buf1078, LOCK_8_6_2_4096, buf1078d, LOCK_8_6_3_4096, 256, 256);
  window_internal window_buf1076_buf1076d[1];
  window_datatype * buf1076_ptr = (window_datatype * )buf1076;
  window_datatype * buf1076d_ptr = (window_datatype * )buf1076d;
  window_init(window_buf1076_buf1076d, 1, buf1076, LOCK_8_7_0_4096, buf1076d, LOCK_8_7_1_0, 256, 256);
  window_internal window_buf1079_buf1079d[1];
  window_datatype * buf1079_ptr = (window_datatype * )buf1079;
  window_datatype * buf1079d_ptr = (window_datatype * )buf1079d;
  window_init(window_buf1079_buf1079d, 1, buf1079, LOCK_8_7_4_0, buf1079d, LOCK_8_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_7_bounds = sync_buffer[1];

  while (proc_8_7_bounds)
  {

    // Kernel call : i619:mm_kernel1
    window_acquire(window_buf1077_buf1077d,LOCK_8_7_2_0,LOCK_8_7_3_4096,buf1077_ptr,buf1077d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1078_buf1078d,LOCK_8_6_2_4096,LOCK_8_6_3_4096,buf1078_ptr,buf1078d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1076_buf1076d,LOCK_8_7_0_4096,LOCK_8_7_1_0,buf1076_ptr,buf1076d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1079_buf1079d,LOCK_8_7_4_0,LOCK_8_7_5_0,buf1079_ptr,buf1079d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1077_buf1077d),get_input_window_float(window_buf1078_buf1078d),get_input_window_float(window_buf1076_buf1076d),get_output_window_float(window_buf1079_buf1079d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1077_buf1077d,LOCK_8_7_2_0,LOCK_8_7_3_4096,buf1077_ptr,buf1077d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1078_buf1078d,LOCK_8_6_2_4096,LOCK_8_6_3_4096,buf1078_ptr,buf1078d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1076_buf1076d,LOCK_8_7_0_4096,LOCK_8_7_1_0,buf1076_ptr,buf1076d_ptr,0,index, REL_WRITE);
    window_release(window_buf1079_buf1079d,LOCK_8_7_4_0,LOCK_8_7_5_0,buf1079_ptr,buf1079d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_7_bounds > 0)
      --proc_8_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}