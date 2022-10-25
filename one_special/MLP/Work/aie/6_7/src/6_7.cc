// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_7/src/6_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_6_2_4096 2
#define LOCK_6_6_3_4096 3
#define LOCK_7_7_6_4096 54
#define LOCK_7_7_7_0 55
#define LOCK_6_7_4_4096 20
#define LOCK_6_7_5_0 21
#define LOCK_6_7_6_4096 22
#define LOCK_6_7_7_0 23

// Declare shared memory buffers
v4float buf1100[256];
v4float buf1100d[256];
v4float buf1101[256];
v4float buf1101d[256];
v4float buf1102[256];
v4float buf1102d[256];
v4float buf1103[256];
v4float buf1103d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1101_buf1101d[1];
  window_datatype * buf1101_ptr = (window_datatype * )buf1101;
  window_datatype * buf1101d_ptr = (window_datatype * )buf1101d;
  window_init(window_buf1101_buf1101d, 1, buf1101, LOCK_6_6_2_4096, buf1101d, LOCK_6_6_3_4096, 256, 256);
  window_internal window_buf1102_buf1102d[1];
  window_datatype * buf1102_ptr = (window_datatype * )buf1102;
  window_datatype * buf1102d_ptr = (window_datatype * )buf1102d;
  window_init(window_buf1102_buf1102d, 1, buf1102, LOCK_7_7_6_4096, buf1102d, LOCK_7_7_7_0, 256, 256);
  window_internal window_buf1100_buf1100d[1];
  window_datatype * buf1100_ptr = (window_datatype * )buf1100;
  window_datatype * buf1100d_ptr = (window_datatype * )buf1100d;
  window_init(window_buf1100_buf1100d, 1, buf1100, LOCK_6_7_4_4096, buf1100d, LOCK_6_7_5_0, 256, 256);
  window_internal window_buf1103_buf1103d[1];
  window_datatype * buf1103_ptr = (window_datatype * )buf1103;
  window_datatype * buf1103d_ptr = (window_datatype * )buf1103d;
  window_init(window_buf1103_buf1103d, 1, buf1103, LOCK_6_7_6_4096, buf1103d, LOCK_6_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_7_bounds = sync_buffer[1];

  while (proc_6_7_bounds)
  {

    // Kernel call : i631:mm_kernel1
    window_acquire(window_buf1101_buf1101d,LOCK_6_6_2_4096,LOCK_6_6_3_4096,buf1101_ptr,buf1101d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1102_buf1102d,LOCK_7_7_6_4096,LOCK_7_7_7_0,buf1102_ptr,buf1102d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1100_buf1100d,LOCK_6_7_4_4096,LOCK_6_7_5_0,buf1100_ptr,buf1100d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1103_buf1103d,LOCK_6_7_6_4096,LOCK_6_7_7_0,buf1103_ptr,buf1103d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1101_buf1101d),get_input_window_float(window_buf1102_buf1102d),get_input_window_float(window_buf1100_buf1100d),get_output_window_float(window_buf1103_buf1103d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1101_buf1101d,LOCK_6_6_2_4096,LOCK_6_6_3_4096,buf1101_ptr,buf1101d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1102_buf1102d,LOCK_7_7_6_4096,LOCK_7_7_7_0,buf1102_ptr,buf1102d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1100_buf1100d,LOCK_6_7_4_4096,LOCK_6_7_5_0,buf1100_ptr,buf1100d_ptr,0,index, REL_WRITE);
    window_release(window_buf1103_buf1103d,LOCK_6_7_6_4096,LOCK_6_7_7_0,buf1103_ptr,buf1103d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_7_bounds > 0)
      --proc_6_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}