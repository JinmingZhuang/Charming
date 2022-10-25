// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_1/src/25_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_1_4_0 20
#define LOCK_25_1_5_0 21
#define LOCK_26_1_0_4096 48
#define LOCK_26_1_1_0 49
#define LOCK_25_1_2_4096 18
#define LOCK_25_1_3_4096 19
#define LOCK_25_1_6_0 22
#define LOCK_25_1_7_0 23

// Declare shared memory buffers
v4float buf278[256];
v4float buf278d[256];
v4float buf279[256];
v4float buf279d[256];
v4float buf280[256];
v4float buf280d[256];
v4float buf281[256];
v4float buf281d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf279_buf279d[1];
  window_datatype * buf279_ptr = (window_datatype * )buf279;
  window_datatype * buf279d_ptr = (window_datatype * )buf279d;
  window_init(window_buf279_buf279d, 1, buf279, LOCK_25_1_4_0, buf279d, LOCK_25_1_5_0, 256, 256);
  window_internal window_buf280_buf280d[1];
  window_datatype * buf280_ptr = (window_datatype * )buf280;
  window_datatype * buf280d_ptr = (window_datatype * )buf280d;
  window_init(window_buf280_buf280d, 1, buf280, LOCK_26_1_0_4096, buf280d, LOCK_26_1_1_0, 256, 256);
  window_internal window_buf278_buf278d[1];
  window_datatype * buf278_ptr = (window_datatype * )buf278;
  window_datatype * buf278d_ptr = (window_datatype * )buf278d;
  window_init(window_buf278_buf278d, 1, buf278, LOCK_25_1_2_4096, buf278d, LOCK_25_1_3_4096, 256, 256);
  window_internal window_buf281_buf281d[1];
  window_datatype * buf281_ptr = (window_datatype * )buf281;
  window_datatype * buf281d_ptr = (window_datatype * )buf281d;
  window_init(window_buf281_buf281d, 1, buf281, LOCK_25_1_6_0, buf281d, LOCK_25_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_1_bounds = sync_buffer[1];

  while (proc_25_1_bounds)
  {

    // Kernel call : i221:mm_kernel1
    window_acquire(window_buf279_buf279d,LOCK_25_1_4_0,LOCK_25_1_5_0,buf279_ptr,buf279d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf280_buf280d,LOCK_26_1_0_4096,LOCK_26_1_1_0,buf280_ptr,buf280d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf278_buf278d,LOCK_25_1_2_4096,LOCK_25_1_3_4096,buf278_ptr,buf278d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf281_buf281d,LOCK_25_1_6_0,LOCK_25_1_7_0,buf281_ptr,buf281d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf279_buf279d),get_input_window_float(window_buf280_buf280d),get_input_window_float(window_buf278_buf278d),get_output_window_float(window_buf281_buf281d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf279_buf279d,LOCK_25_1_4_0,LOCK_25_1_5_0,buf279_ptr,buf279d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf280_buf280d,LOCK_26_1_0_4096,LOCK_26_1_1_0,buf280_ptr,buf280d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf278_buf278d,LOCK_25_1_2_4096,LOCK_25_1_3_4096,buf278_ptr,buf278d_ptr,0,index, REL_WRITE);
    window_release(window_buf281_buf281d,LOCK_25_1_6_0,LOCK_25_1_7_0,buf281_ptr,buf281d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_1_bounds > 0)
      --proc_25_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}