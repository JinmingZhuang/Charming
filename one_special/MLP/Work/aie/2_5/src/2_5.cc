// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_5/src/2_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_2_4_0_4096 0
#define LOCK_2_4_1_0 1
#define LOCK_2_4_2_0 2
#define LOCK_2_4_3_4096 3
#define LOCK_2_5_0_0 16
#define LOCK_2_5_1_0 17
#define LOCK_2_5_2_0 18
#define LOCK_2_5_3_0 19

// Declare shared memory buffers
v4float buf1142[256];
v4float buf1142d[256];
v4float buf1143[256];
v4float buf1143d[256];
v4float buf1144[256];
v4float buf1144d[256];
v4float buf1145[256];
v4float buf1145d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1143_buf1143d[1];
  window_datatype * buf1143_ptr = (window_datatype * )buf1143;
  window_datatype * buf1143d_ptr = (window_datatype * )buf1143d;
  window_init(window_buf1143_buf1143d, 1, buf1143, LOCK_2_4_0_4096, buf1143d, LOCK_2_4_1_0, 256, 256);
  window_internal window_buf1144_buf1144d[1];
  window_datatype * buf1144_ptr = (window_datatype * )buf1144;
  window_datatype * buf1144d_ptr = (window_datatype * )buf1144d;
  window_init(window_buf1144_buf1144d, 1, buf1144, LOCK_2_4_2_0, buf1144d, LOCK_2_4_3_4096, 256, 256);
  window_internal window_buf1142_buf1142d[1];
  window_datatype * buf1142_ptr = (window_datatype * )buf1142;
  window_datatype * buf1142d_ptr = (window_datatype * )buf1142d;
  window_init(window_buf1142_buf1142d, 1, buf1142, LOCK_2_5_0_0, buf1142d, LOCK_2_5_1_0, 256, 256);
  window_internal window_buf1145_buf1145d[1];
  window_datatype * buf1145_ptr = (window_datatype * )buf1145;
  window_datatype * buf1145d_ptr = (window_datatype * )buf1145d;
  window_init(window_buf1145_buf1145d, 1, buf1145, LOCK_2_5_2_0, buf1145d, LOCK_2_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_5_bounds = sync_buffer[1];

  while (proc_2_5_bounds)
  {

    // Kernel call : i653:mm_kernel1
    window_acquire(window_buf1143_buf1143d,LOCK_2_4_0_4096,LOCK_2_4_1_0,buf1143_ptr,buf1143d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1144_buf1144d,LOCK_2_4_2_0,LOCK_2_4_3_4096,buf1144_ptr,buf1144d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1142_buf1142d,LOCK_2_5_0_0,LOCK_2_5_1_0,buf1142_ptr,buf1142d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1145_buf1145d,LOCK_2_5_2_0,LOCK_2_5_3_0,buf1145_ptr,buf1145d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1143_buf1143d),get_input_window_float(window_buf1144_buf1144d),get_input_window_float(window_buf1142_buf1142d),get_output_window_float(window_buf1145_buf1145d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1143_buf1143d,LOCK_2_4_0_4096,LOCK_2_4_1_0,buf1143_ptr,buf1143d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1144_buf1144d,LOCK_2_4_2_0,LOCK_2_4_3_4096,buf1144_ptr,buf1144d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1142_buf1142d,LOCK_2_5_0_0,LOCK_2_5_1_0,buf1142_ptr,buf1142d_ptr,0,index, REL_WRITE);
    window_release(window_buf1145_buf1145d,LOCK_2_5_2_0,LOCK_2_5_3_0,buf1145_ptr,buf1145d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_5_bounds > 0)
      --proc_2_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}