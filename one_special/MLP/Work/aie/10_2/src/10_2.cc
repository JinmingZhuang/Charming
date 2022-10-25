// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_2/src/10_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_2_0_0 48
#define LOCK_10_2_1_0 49
#define LOCK_10_3_0_4096 32
#define LOCK_10_3_1_0 33
#define LOCK_10_1_6_4096 6
#define LOCK_10_1_7_4096 7
#define LOCK_10_3_2_4096 34
#define LOCK_10_3_3_4096 35

// Declare shared memory buffers
v4float buf101[256];
v4float buf101d[256];
v4float buf102[256];
v4float buf102d[256];
v4float buf103[256];
v4float buf103d[256];
v4float buf104[256];
v4float buf104d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf102_buf102d[1];
  window_datatype * buf102_ptr = (window_datatype * )buf102;
  window_datatype * buf102d_ptr = (window_datatype * )buf102d;
  window_init(window_buf102_buf102d, 1, buf102, LOCK_10_2_0_0, buf102d, LOCK_10_2_1_0, 256, 256);
  window_internal window_buf103_buf103d[1];
  window_datatype * buf103_ptr = (window_datatype * )buf103;
  window_datatype * buf103d_ptr = (window_datatype * )buf103d;
  window_init(window_buf103_buf103d, 1, buf103, LOCK_10_3_0_4096, buf103d, LOCK_10_3_1_0, 256, 256);
  window_internal window_buf101_buf101d[1];
  window_datatype * buf101_ptr = (window_datatype * )buf101;
  window_datatype * buf101d_ptr = (window_datatype * )buf101d;
  window_init(window_buf101_buf101d, 1, buf101, LOCK_10_1_6_4096, buf101d, LOCK_10_1_7_4096, 256, 256);
  window_internal window_buf104_buf104d[1];
  window_datatype * buf104_ptr = (window_datatype * )buf104;
  window_datatype * buf104d_ptr = (window_datatype * )buf104d;
  window_init(window_buf104_buf104d, 1, buf104, LOCK_10_3_2_4096, buf104d, LOCK_10_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_2_bounds = sync_buffer[1];

  while (proc_10_2_bounds)
  {

    // Kernel call : i132:mm_kernel1
    window_acquire(window_buf102_buf102d,LOCK_10_2_0_0,LOCK_10_2_1_0,buf102_ptr,buf102d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf103_buf103d,LOCK_10_3_0_4096,LOCK_10_3_1_0,buf103_ptr,buf103d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf101_buf101d,LOCK_10_1_6_4096,LOCK_10_1_7_4096,buf101_ptr,buf101d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf104_buf104d,LOCK_10_3_2_4096,LOCK_10_3_3_4096,buf104_ptr,buf104d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf102_buf102d),get_input_window_float(window_buf103_buf103d),get_input_window_float(window_buf101_buf101d),get_output_window_float(window_buf104_buf104d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf102_buf102d,LOCK_10_2_0_0,LOCK_10_2_1_0,buf102_ptr,buf102d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf103_buf103d,LOCK_10_3_0_4096,LOCK_10_3_1_0,buf103_ptr,buf103d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf101_buf101d,LOCK_10_1_6_4096,LOCK_10_1_7_4096,buf101_ptr,buf101d_ptr,0,index, REL_WRITE);
    window_release(window_buf104_buf104d,LOCK_10_3_2_4096,LOCK_10_3_3_4096,buf104_ptr,buf104d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_2_bounds > 0)
      --proc_10_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}