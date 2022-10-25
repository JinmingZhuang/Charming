// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_4/src/8_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_3_2_4096 2
#define LOCK_8_3_3_4096 3
#define LOCK_7_4_0_0 16
#define LOCK_7_4_1_0 17
#define LOCK_8_5_0_0 32
#define LOCK_8_5_1_0 33

// Declare shared memory buffers
v4float buf1068[256];
v4float buf1068d[256];
v4float buf1069[256];
v4float buf1069d[256];
v4float buf1070[256];
v4float buf1070d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1068_buf1068d[1];
  window_datatype * buf1068_ptr = (window_datatype * )buf1068;
  window_datatype * buf1068d_ptr = (window_datatype * )buf1068d;
  window_init(window_buf1068_buf1068d, 1, buf1068, LOCK_8_3_2_4096, buf1068d, LOCK_8_3_3_4096, 256, 256);
  window_internal window_buf1069_buf1069d[1];
  window_datatype * buf1069_ptr = (window_datatype * )buf1069;
  window_datatype * buf1069d_ptr = (window_datatype * )buf1069d;
  window_init(window_buf1069_buf1069d, 1, buf1069, LOCK_7_4_0_0, buf1069d, LOCK_7_4_1_0, 256, 256);
  window_internal window_buf1070_buf1070d[1];
  window_datatype * buf1070_ptr = (window_datatype * )buf1070;
  window_datatype * buf1070d_ptr = (window_datatype * )buf1070d;
  window_init(window_buf1070_buf1070d, 1, buf1070, LOCK_8_5_0_0, buf1070d, LOCK_8_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_4_bounds = sync_buffer[1];

  while (proc_8_4_bounds)
  {

    // Kernel call : i616:mm_kernel0
    window_acquire(window_buf1068_buf1068d,LOCK_8_3_2_4096,LOCK_8_3_3_4096,buf1068_ptr,buf1068d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1069_buf1069d,LOCK_7_4_0_0,LOCK_7_4_1_0,buf1069_ptr,buf1069d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1070_buf1070d,LOCK_8_5_0_0,LOCK_8_5_1_0,buf1070_ptr,buf1070d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1068_buf1068d),get_input_window_float(window_buf1069_buf1069d),get_output_window_float(window_buf1070_buf1070d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1068_buf1068d,LOCK_8_3_2_4096,LOCK_8_3_3_4096,buf1068_ptr,buf1068d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1069_buf1069d,LOCK_7_4_0_0,LOCK_7_4_1_0,buf1069_ptr,buf1069d_ptr,0,index, REL_WRITE);
    window_release(window_buf1070_buf1070d,LOCK_8_5_0_0,LOCK_8_5_1_0,buf1070_ptr,buf1070d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_4_bounds > 0)
      --proc_8_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}