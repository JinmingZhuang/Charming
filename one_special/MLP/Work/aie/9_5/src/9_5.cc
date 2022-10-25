// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_5/src/9_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_4_2_4096 2
#define LOCK_9_4_3_4096 3
#define LOCK_10_5_6_0 54
#define LOCK_10_5_7_4096 55
#define LOCK_9_5_2_4096 18
#define LOCK_9_5_3_4096 19
#define LOCK_9_5_4_0 20
#define LOCK_9_5_5_4096 21

// Declare shared memory buffers
v4float buf1058[256];
v4float buf1058d[256];
v4float buf1059[256];
v4float buf1059d[256];
v4float buf1060[256];
v4float buf1060d[256];
v4float buf1061[256];
v4float buf1061d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1059_buf1059d[1];
  window_datatype * buf1059_ptr = (window_datatype * )buf1059;
  window_datatype * buf1059d_ptr = (window_datatype * )buf1059d;
  window_init(window_buf1059_buf1059d, 1, buf1059, LOCK_9_4_2_4096, buf1059d, LOCK_9_4_3_4096, 256, 256);
  window_internal window_buf1060_buf1060d[1];
  window_datatype * buf1060_ptr = (window_datatype * )buf1060;
  window_datatype * buf1060d_ptr = (window_datatype * )buf1060d;
  window_init(window_buf1060_buf1060d, 1, buf1060, LOCK_10_5_6_0, buf1060d, LOCK_10_5_7_4096, 256, 256);
  window_internal window_buf1058_buf1058d[1];
  window_datatype * buf1058_ptr = (window_datatype * )buf1058;
  window_datatype * buf1058d_ptr = (window_datatype * )buf1058d;
  window_init(window_buf1058_buf1058d, 1, buf1058, LOCK_9_5_2_4096, buf1058d, LOCK_9_5_3_4096, 256, 256);
  window_internal window_buf1061_buf1061d[1];
  window_datatype * buf1061_ptr = (window_datatype * )buf1061;
  window_datatype * buf1061d_ptr = (window_datatype * )buf1061d;
  window_init(window_buf1061_buf1061d, 1, buf1061, LOCK_9_5_4_0, buf1061d, LOCK_9_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_5_bounds = sync_buffer[1];

  while (proc_9_5_bounds)
  {

    // Kernel call : i611:mm_kernel1
    window_acquire(window_buf1059_buf1059d,LOCK_9_4_2_4096,LOCK_9_4_3_4096,buf1059_ptr,buf1059d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1060_buf1060d,LOCK_10_5_6_0,LOCK_10_5_7_4096,buf1060_ptr,buf1060d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1058_buf1058d,LOCK_9_5_2_4096,LOCK_9_5_3_4096,buf1058_ptr,buf1058d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1061_buf1061d,LOCK_9_5_4_0,LOCK_9_5_5_4096,buf1061_ptr,buf1061d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1059_buf1059d),get_input_window_float(window_buf1060_buf1060d),get_input_window_float(window_buf1058_buf1058d),get_output_window_float(window_buf1061_buf1061d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1059_buf1059d,LOCK_9_4_2_4096,LOCK_9_4_3_4096,buf1059_ptr,buf1059d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1060_buf1060d,LOCK_10_5_6_0,LOCK_10_5_7_4096,buf1060_ptr,buf1060d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1058_buf1058d,LOCK_9_5_2_4096,LOCK_9_5_3_4096,buf1058_ptr,buf1058d_ptr,0,index, REL_WRITE);
    window_release(window_buf1061_buf1061d,LOCK_9_5_4_0,LOCK_9_5_5_4096,buf1061_ptr,buf1061d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_5_bounds > 0)
      --proc_9_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}