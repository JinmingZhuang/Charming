// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_1/src/47_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_0_2_4096 2
#define LOCK_47_0_3_4096 3
#define LOCK_47_2_0_0 32
#define LOCK_47_2_1_0 33
#define LOCK_47_1_0_4096 16
#define LOCK_47_1_1_0 17
#define LOCK_47_1_2_4096 18
#define LOCK_47_1_3_0 19

// Declare shared memory buffers
v4float buf542[256];
v4float buf542d[256];
v4float buf543[256];
v4float buf543d[256];
v4float buf544[256];
v4float buf544d[256];
v4float buf545[256];
v4float buf545d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf543_buf543d[1];
  window_datatype * buf543_ptr = (window_datatype * )buf543;
  window_datatype * buf543d_ptr = (window_datatype * )buf543d;
  window_init(window_buf543_buf543d, 1, buf543, LOCK_47_0_2_4096, buf543d, LOCK_47_0_3_4096, 256, 256);
  window_internal window_buf544_buf544d[1];
  window_datatype * buf544_ptr = (window_datatype * )buf544;
  window_datatype * buf544d_ptr = (window_datatype * )buf544d;
  window_init(window_buf544_buf544d, 1, buf544, LOCK_47_2_0_0, buf544d, LOCK_47_2_1_0, 256, 256);
  window_internal window_buf542_buf542d[1];
  window_datatype * buf542_ptr = (window_datatype * )buf542;
  window_datatype * buf542d_ptr = (window_datatype * )buf542d;
  window_init(window_buf542_buf542d, 1, buf542, LOCK_47_1_0_4096, buf542d, LOCK_47_1_1_0, 256, 256);
  window_internal window_buf545_buf545d[1];
  window_datatype * buf545_ptr = (window_datatype * )buf545;
  window_datatype * buf545d_ptr = (window_datatype * )buf545d;
  window_init(window_buf545_buf545d, 1, buf545, LOCK_47_1_2_4096, buf545d, LOCK_47_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_1_bounds = sync_buffer[1];

  while (proc_47_1_bounds)
  {

    // Kernel call : i353:mm_kernel1
    window_acquire(window_buf543_buf543d,LOCK_47_0_2_4096,LOCK_47_0_3_4096,buf543_ptr,buf543d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf544_buf544d,LOCK_47_2_0_0,LOCK_47_2_1_0,buf544_ptr,buf544d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf542_buf542d,LOCK_47_1_0_4096,LOCK_47_1_1_0,buf542_ptr,buf542d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf545_buf545d,LOCK_47_1_2_4096,LOCK_47_1_3_0,buf545_ptr,buf545d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf543_buf543d),get_input_window_float(window_buf544_buf544d),get_input_window_float(window_buf542_buf542d),get_output_window_float(window_buf545_buf545d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf543_buf543d,LOCK_47_0_2_4096,LOCK_47_0_3_4096,buf543_ptr,buf543d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf544_buf544d,LOCK_47_2_0_0,LOCK_47_2_1_0,buf544_ptr,buf544d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf542_buf542d,LOCK_47_1_0_4096,LOCK_47_1_1_0,buf542_ptr,buf542d_ptr,0,index, REL_WRITE);
    window_release(window_buf545_buf545d,LOCK_47_1_2_4096,LOCK_47_1_3_0,buf545_ptr,buf545d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_1_bounds > 0)
      --proc_47_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}