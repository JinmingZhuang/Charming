// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_7/src/7_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_7_6_2_4096 2
#define LOCK_7_6_3_4096 3
#define LOCK_8_7_6_4096 54
#define LOCK_8_7_7_4096 55
#define LOCK_7_7_2_4096 18
#define LOCK_7_7_3_0 19
#define LOCK_7_7_4_4096 20
#define LOCK_7_7_5_0 21

// Declare shared memory buffers
v4float buf1088[256];
v4float buf1088d[256];
v4float buf1089[256];
v4float buf1089d[256];
v4float buf1090[256];
v4float buf1090d[256];
v4float buf1091[256];
v4float buf1091d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1089_buf1089d[1];
  window_datatype * buf1089_ptr = (window_datatype * )buf1089;
  window_datatype * buf1089d_ptr = (window_datatype * )buf1089d;
  window_init(window_buf1089_buf1089d, 1, buf1089, LOCK_7_6_2_4096, buf1089d, LOCK_7_6_3_4096, 256, 256);
  window_internal window_buf1090_buf1090d[1];
  window_datatype * buf1090_ptr = (window_datatype * )buf1090;
  window_datatype * buf1090d_ptr = (window_datatype * )buf1090d;
  window_init(window_buf1090_buf1090d, 1, buf1090, LOCK_8_7_6_4096, buf1090d, LOCK_8_7_7_4096, 256, 256);
  window_internal window_buf1088_buf1088d[1];
  window_datatype * buf1088_ptr = (window_datatype * )buf1088;
  window_datatype * buf1088d_ptr = (window_datatype * )buf1088d;
  window_init(window_buf1088_buf1088d, 1, buf1088, LOCK_7_7_2_4096, buf1088d, LOCK_7_7_3_0, 256, 256);
  window_internal window_buf1091_buf1091d[1];
  window_datatype * buf1091_ptr = (window_datatype * )buf1091;
  window_datatype * buf1091d_ptr = (window_datatype * )buf1091d;
  window_init(window_buf1091_buf1091d, 1, buf1091, LOCK_7_7_4_4096, buf1091d, LOCK_7_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_7_bounds = sync_buffer[1];

  while (proc_7_7_bounds)
  {

    // Kernel call : i625:mm_kernel1
    window_acquire(window_buf1089_buf1089d,LOCK_7_6_2_4096,LOCK_7_6_3_4096,buf1089_ptr,buf1089d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1090_buf1090d,LOCK_8_7_6_4096,LOCK_8_7_7_4096,buf1090_ptr,buf1090d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1088_buf1088d,LOCK_7_7_2_4096,LOCK_7_7_3_0,buf1088_ptr,buf1088d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1091_buf1091d,LOCK_7_7_4_4096,LOCK_7_7_5_0,buf1091_ptr,buf1091d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1089_buf1089d),get_input_window_float(window_buf1090_buf1090d),get_input_window_float(window_buf1088_buf1088d),get_output_window_float(window_buf1091_buf1091d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1089_buf1089d,LOCK_7_6_2_4096,LOCK_7_6_3_4096,buf1089_ptr,buf1089d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1090_buf1090d,LOCK_8_7_6_4096,LOCK_8_7_7_4096,buf1090_ptr,buf1090d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1088_buf1088d,LOCK_7_7_2_4096,LOCK_7_7_3_0,buf1088_ptr,buf1088d_ptr,0,index, REL_WRITE);
    window_release(window_buf1091_buf1091d,LOCK_7_7_4_4096,LOCK_7_7_5_0,buf1091_ptr,buf1091d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_7_bounds > 0)
      --proc_7_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}