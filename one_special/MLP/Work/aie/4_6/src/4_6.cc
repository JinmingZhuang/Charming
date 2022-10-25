// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_6/src/4_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_7_0_0 32
#define LOCK_4_7_1_4096 33
#define LOCK_4_5_6_0 6
#define LOCK_4_5_7_4096 7
#define LOCK_4_5_4_0 4
#define LOCK_4_5_5_4096 5
#define LOCK_4_7_2_0 34
#define LOCK_4_7_3_4096 35

// Declare shared memory buffers
v4float buf1121[256];
v4float buf1121d[256];
v4float buf1122[256];
v4float buf1122d[256];
v4float buf1123[256];
v4float buf1123d[256];
v4float buf1124[256];
v4float buf1124d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1122_buf1122d[1];
  window_datatype * buf1122_ptr = (window_datatype * )buf1122;
  window_datatype * buf1122d_ptr = (window_datatype * )buf1122d;
  window_init(window_buf1122_buf1122d, 1, buf1122, LOCK_4_7_0_0, buf1122d, LOCK_4_7_1_4096, 256, 256);
  window_internal window_buf1123_buf1123d[1];
  window_datatype * buf1123_ptr = (window_datatype * )buf1123;
  window_datatype * buf1123d_ptr = (window_datatype * )buf1123d;
  window_init(window_buf1123_buf1123d, 1, buf1123, LOCK_4_5_6_0, buf1123d, LOCK_4_5_7_4096, 256, 256);
  window_internal window_buf1121_buf1121d[1];
  window_datatype * buf1121_ptr = (window_datatype * )buf1121;
  window_datatype * buf1121d_ptr = (window_datatype * )buf1121d;
  window_init(window_buf1121_buf1121d, 1, buf1121, LOCK_4_5_4_0, buf1121d, LOCK_4_5_5_4096, 256, 256);
  window_internal window_buf1124_buf1124d[1];
  window_datatype * buf1124_ptr = (window_datatype * )buf1124;
  window_datatype * buf1124d_ptr = (window_datatype * )buf1124d;
  window_init(window_buf1124_buf1124d, 1, buf1124, LOCK_4_7_2_0, buf1124d, LOCK_4_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_6_bounds = sync_buffer[1];

  while (proc_4_6_bounds)
  {

    // Kernel call : i642:mm_kernel1
    window_acquire(window_buf1122_buf1122d,LOCK_4_7_0_0,LOCK_4_7_1_4096,buf1122_ptr,buf1122d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1123_buf1123d,LOCK_4_5_6_0,LOCK_4_5_7_4096,buf1123_ptr,buf1123d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1121_buf1121d,LOCK_4_5_4_0,LOCK_4_5_5_4096,buf1121_ptr,buf1121d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1124_buf1124d,LOCK_4_7_2_0,LOCK_4_7_3_4096,buf1124_ptr,buf1124d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1122_buf1122d),get_input_window_float(window_buf1123_buf1123d),get_input_window_float(window_buf1121_buf1121d),get_output_window_float(window_buf1124_buf1124d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1122_buf1122d,LOCK_4_7_0_0,LOCK_4_7_1_4096,buf1122_ptr,buf1122d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1123_buf1123d,LOCK_4_5_6_0,LOCK_4_5_7_4096,buf1123_ptr,buf1123d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1121_buf1121d,LOCK_4_5_4_0,LOCK_4_5_5_4096,buf1121_ptr,buf1121d_ptr,0,index, REL_WRITE);
    window_release(window_buf1124_buf1124d,LOCK_4_7_2_0,LOCK_4_7_3_4096,buf1124_ptr,buf1124d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_6_bounds > 0)
      --proc_4_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}