// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_4/src/9_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_5_0_0 32
#define LOCK_9_5_1_4096 33
#define LOCK_9_3_6_4096 6
#define LOCK_9_3_7_0 7
#define LOCK_9_5_2_4096 34
#define LOCK_9_5_3_4096 35

// Declare shared memory buffers
v4float buf1056[256];
v4float buf1056d[256];
v4float buf1057[256];
v4float buf1057d[256];
v4float buf1058[256];
v4float buf1058d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1056_buf1056d[1];
  window_datatype * buf1056_ptr = (window_datatype * )buf1056;
  window_datatype * buf1056d_ptr = (window_datatype * )buf1056d;
  window_init(window_buf1056_buf1056d, 1, buf1056, LOCK_9_5_0_0, buf1056d, LOCK_9_5_1_4096, 256, 256);
  window_internal window_buf1057_buf1057d[1];
  window_datatype * buf1057_ptr = (window_datatype * )buf1057;
  window_datatype * buf1057d_ptr = (window_datatype * )buf1057d;
  window_init(window_buf1057_buf1057d, 1, buf1057, LOCK_9_3_6_4096, buf1057d, LOCK_9_3_7_0, 256, 256);
  window_internal window_buf1058_buf1058d[1];
  window_datatype * buf1058_ptr = (window_datatype * )buf1058;
  window_datatype * buf1058d_ptr = (window_datatype * )buf1058d;
  window_init(window_buf1058_buf1058d, 1, buf1058, LOCK_9_5_2_4096, buf1058d, LOCK_9_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_4_bounds = sync_buffer[1];

  while (proc_9_4_bounds)
  {

    // Kernel call : i610:mm_kernel0
    window_acquire(window_buf1056_buf1056d,LOCK_9_5_0_0,LOCK_9_5_1_4096,buf1056_ptr,buf1056d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1057_buf1057d,LOCK_9_3_6_4096,LOCK_9_3_7_0,buf1057_ptr,buf1057d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1058_buf1058d,LOCK_9_5_2_4096,LOCK_9_5_3_4096,buf1058_ptr,buf1058d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1056_buf1056d),get_input_window_float(window_buf1057_buf1057d),get_output_window_float(window_buf1058_buf1058d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1056_buf1056d,LOCK_9_5_0_0,LOCK_9_5_1_4096,buf1056_ptr,buf1056d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1057_buf1057d,LOCK_9_3_6_4096,LOCK_9_3_7_0,buf1057_ptr,buf1057d_ptr,0,index, REL_WRITE);
    window_release(window_buf1058_buf1058d,LOCK_9_5_2_4096,LOCK_9_5_3_4096,buf1058_ptr,buf1058d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_4_bounds > 0)
      --proc_9_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}