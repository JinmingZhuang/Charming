// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_7/src/12_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_6_2_4096 2
#define LOCK_12_6_3_4096 3
#define LOCK_12_7_4_0 20
#define LOCK_12_7_5_0 21
#define LOCK_12_7_2_4096 18
#define LOCK_12_7_3_4096 19
#define LOCK_12_7_6_0 22
#define LOCK_12_7_7_0 23

// Declare shared memory buffers
v4float buf1028[256];
v4float buf1028d[256];
v4float buf1029[256];
v4float buf1029d[256];
v4float buf1030[256];
v4float buf1030d[256];
v4float buf1031[256];
v4float buf1031d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1029_buf1029d[1];
  window_datatype * buf1029_ptr = (window_datatype * )buf1029;
  window_datatype * buf1029d_ptr = (window_datatype * )buf1029d;
  window_init(window_buf1029_buf1029d, 1, buf1029, LOCK_12_6_2_4096, buf1029d, LOCK_12_6_3_4096, 256, 256);
  window_internal window_buf1030_buf1030d[1];
  window_datatype * buf1030_ptr = (window_datatype * )buf1030;
  window_datatype * buf1030d_ptr = (window_datatype * )buf1030d;
  window_init(window_buf1030_buf1030d, 1, buf1030, LOCK_12_7_4_0, buf1030d, LOCK_12_7_5_0, 256, 256);
  window_internal window_buf1028_buf1028d[1];
  window_datatype * buf1028_ptr = (window_datatype * )buf1028;
  window_datatype * buf1028d_ptr = (window_datatype * )buf1028d;
  window_init(window_buf1028_buf1028d, 1, buf1028, LOCK_12_7_2_4096, buf1028d, LOCK_12_7_3_4096, 256, 256);
  window_internal window_buf1031_buf1031d[1];
  window_datatype * buf1031_ptr = (window_datatype * )buf1031;
  window_datatype * buf1031d_ptr = (window_datatype * )buf1031d;
  window_init(window_buf1031_buf1031d, 1, buf1031, LOCK_12_7_6_0, buf1031d, LOCK_12_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_7_bounds = sync_buffer[1];

  while (proc_12_7_bounds)
  {

    // Kernel call : i595:mm_kernel1
    window_acquire(window_buf1029_buf1029d,LOCK_12_6_2_4096,LOCK_12_6_3_4096,buf1029_ptr,buf1029d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1030_buf1030d,LOCK_12_7_4_0,LOCK_12_7_5_0,buf1030_ptr,buf1030d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1028_buf1028d,LOCK_12_7_2_4096,LOCK_12_7_3_4096,buf1028_ptr,buf1028d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1031_buf1031d,LOCK_12_7_6_0,LOCK_12_7_7_0,buf1031_ptr,buf1031d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1029_buf1029d),get_input_window_float(window_buf1030_buf1030d),get_input_window_float(window_buf1028_buf1028d),get_output_window_float(window_buf1031_buf1031d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1029_buf1029d,LOCK_12_6_2_4096,LOCK_12_6_3_4096,buf1029_ptr,buf1029d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1030_buf1030d,LOCK_12_7_4_0,LOCK_12_7_5_0,buf1030_ptr,buf1030d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1028_buf1028d,LOCK_12_7_2_4096,LOCK_12_7_3_4096,buf1028_ptr,buf1028d_ptr,0,index, REL_WRITE);
    window_release(window_buf1031_buf1031d,LOCK_12_7_6_0,LOCK_12_7_7_0,buf1031_ptr,buf1031d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_7_bounds > 0)
      --proc_12_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}