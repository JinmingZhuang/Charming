// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_2/src/25_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_2_0_4096 48
#define LOCK_25_2_1_4096 49
#define LOCK_25_2_2_0 50
#define LOCK_25_2_3_0 51
#define LOCK_25_1_6_0 6
#define LOCK_25_1_7_0 7
#define LOCK_25_3_0_0 32
#define LOCK_25_3_1_0 33

// Declare shared memory buffers
v4float buf281[256];
v4float buf281d[256];
v4float buf282[256];
v4float buf282d[256];
v4float buf283[256];
v4float buf283d[256];
v4float buf284[256];
v4float buf284d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf282_buf282d[1];
  window_datatype * buf282_ptr = (window_datatype * )buf282;
  window_datatype * buf282d_ptr = (window_datatype * )buf282d;
  window_init(window_buf282_buf282d, 1, buf282, LOCK_25_2_0_4096, buf282d, LOCK_25_2_1_4096, 256, 256);
  window_internal window_buf283_buf283d[1];
  window_datatype * buf283_ptr = (window_datatype * )buf283;
  window_datatype * buf283d_ptr = (window_datatype * )buf283d;
  window_init(window_buf283_buf283d, 1, buf283, LOCK_25_2_2_0, buf283d, LOCK_25_2_3_0, 256, 256);
  window_internal window_buf281_buf281d[1];
  window_datatype * buf281_ptr = (window_datatype * )buf281;
  window_datatype * buf281d_ptr = (window_datatype * )buf281d;
  window_init(window_buf281_buf281d, 1, buf281, LOCK_25_1_6_0, buf281d, LOCK_25_1_7_0, 256, 256);
  window_internal window_buf284_buf284d[1];
  window_datatype * buf284_ptr = (window_datatype * )buf284;
  window_datatype * buf284d_ptr = (window_datatype * )buf284d;
  window_init(window_buf284_buf284d, 1, buf284, LOCK_25_3_0_0, buf284d, LOCK_25_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_2_bounds = sync_buffer[1];

  while (proc_25_2_bounds)
  {

    // Kernel call : i222:mm_kernel1
    window_acquire(window_buf282_buf282d,LOCK_25_2_0_4096,LOCK_25_2_1_4096,buf282_ptr,buf282d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf283_buf283d,LOCK_25_2_2_0,LOCK_25_2_3_0,buf283_ptr,buf283d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf281_buf281d,LOCK_25_1_6_0,LOCK_25_1_7_0,buf281_ptr,buf281d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf284_buf284d,LOCK_25_3_0_0,LOCK_25_3_1_0,buf284_ptr,buf284d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf282_buf282d),get_input_window_float(window_buf283_buf283d),get_input_window_float(window_buf281_buf281d),get_output_window_float(window_buf284_buf284d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf282_buf282d,LOCK_25_2_0_4096,LOCK_25_2_1_4096,buf282_ptr,buf282d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf283_buf283d,LOCK_25_2_2_0,LOCK_25_2_3_0,buf283_ptr,buf283d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf281_buf281d,LOCK_25_1_6_0,LOCK_25_1_7_0,buf281_ptr,buf281d_ptr,0,index, REL_WRITE);
    window_release(window_buf284_buf284d,LOCK_25_3_0_0,LOCK_25_3_1_0,buf284_ptr,buf284d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_2_bounds > 0)
      --proc_25_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}