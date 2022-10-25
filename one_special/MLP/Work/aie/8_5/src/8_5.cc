// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_5/src/8_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_6_0_0 32
#define LOCK_8_6_1_0 33
#define LOCK_8_4_2_4096 2
#define LOCK_8_4_3_4096 3
#define LOCK_8_5_0_0 16
#define LOCK_8_5_1_0 17
#define LOCK_8_5_2_4096 18
#define LOCK_8_5_3_0 19

// Declare shared memory buffers
v4float buf1070[256];
v4float buf1070d[256];
v4float buf1071[256];
v4float buf1071d[256];
v4float buf1072[256];
v4float buf1072d[256];
v4float buf1073[256];
v4float buf1073d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1071_buf1071d[1];
  window_datatype * buf1071_ptr = (window_datatype * )buf1071;
  window_datatype * buf1071d_ptr = (window_datatype * )buf1071d;
  window_init(window_buf1071_buf1071d, 1, buf1071, LOCK_8_6_0_0, buf1071d, LOCK_8_6_1_0, 256, 256);
  window_internal window_buf1072_buf1072d[1];
  window_datatype * buf1072_ptr = (window_datatype * )buf1072;
  window_datatype * buf1072d_ptr = (window_datatype * )buf1072d;
  window_init(window_buf1072_buf1072d, 1, buf1072, LOCK_8_4_2_4096, buf1072d, LOCK_8_4_3_4096, 256, 256);
  window_internal window_buf1070_buf1070d[1];
  window_datatype * buf1070_ptr = (window_datatype * )buf1070;
  window_datatype * buf1070d_ptr = (window_datatype * )buf1070d;
  window_init(window_buf1070_buf1070d, 1, buf1070, LOCK_8_5_0_0, buf1070d, LOCK_8_5_1_0, 256, 256);
  window_internal window_buf1073_buf1073d[1];
  window_datatype * buf1073_ptr = (window_datatype * )buf1073;
  window_datatype * buf1073d_ptr = (window_datatype * )buf1073d;
  window_init(window_buf1073_buf1073d, 1, buf1073, LOCK_8_5_2_4096, buf1073d, LOCK_8_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_5_bounds = sync_buffer[1];

  while (proc_8_5_bounds)
  {

    // Kernel call : i617:mm_kernel1
    window_acquire(window_buf1071_buf1071d,LOCK_8_6_0_0,LOCK_8_6_1_0,buf1071_ptr,buf1071d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1072_buf1072d,LOCK_8_4_2_4096,LOCK_8_4_3_4096,buf1072_ptr,buf1072d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1070_buf1070d,LOCK_8_5_0_0,LOCK_8_5_1_0,buf1070_ptr,buf1070d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1073_buf1073d,LOCK_8_5_2_4096,LOCK_8_5_3_0,buf1073_ptr,buf1073d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1071_buf1071d),get_input_window_float(window_buf1072_buf1072d),get_input_window_float(window_buf1070_buf1070d),get_output_window_float(window_buf1073_buf1073d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1071_buf1071d,LOCK_8_6_0_0,LOCK_8_6_1_0,buf1071_ptr,buf1071d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1072_buf1072d,LOCK_8_4_2_4096,LOCK_8_4_3_4096,buf1072_ptr,buf1072d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1070_buf1070d,LOCK_8_5_0_0,LOCK_8_5_1_0,buf1070_ptr,buf1070d_ptr,0,index, REL_WRITE);
    window_release(window_buf1073_buf1073d,LOCK_8_5_2_4096,LOCK_8_5_3_0,buf1073_ptr,buf1073d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_5_bounds > 0)
      --proc_8_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}