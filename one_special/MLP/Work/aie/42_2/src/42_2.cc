// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_2/src/42_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_3_0_4096 32
#define LOCK_42_3_1_0 33
#define LOCK_42_3_2_4096 34
#define LOCK_42_3_3_4096 35
#define LOCK_42_1_6_4096 6
#define LOCK_42_1_7_4096 7
#define LOCK_42_3_4_4096 36
#define LOCK_42_3_5_0 37

// Declare shared memory buffers
v4float buf485[256];
v4float buf485d[256];
v4float buf486[256];
v4float buf486d[256];
v4float buf487[256];
v4float buf487d[256];
v4float buf488[256];
v4float buf488d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf486_buf486d[1];
  window_datatype * buf486_ptr = (window_datatype * )buf486;
  window_datatype * buf486d_ptr = (window_datatype * )buf486d;
  window_init(window_buf486_buf486d, 1, buf486, LOCK_42_3_0_4096, buf486d, LOCK_42_3_1_0, 256, 256);
  window_internal window_buf487_buf487d[1];
  window_datatype * buf487_ptr = (window_datatype * )buf487;
  window_datatype * buf487d_ptr = (window_datatype * )buf487d;
  window_init(window_buf487_buf487d, 1, buf487, LOCK_42_3_2_4096, buf487d, LOCK_42_3_3_4096, 256, 256);
  window_internal window_buf485_buf485d[1];
  window_datatype * buf485_ptr = (window_datatype * )buf485;
  window_datatype * buf485d_ptr = (window_datatype * )buf485d;
  window_init(window_buf485_buf485d, 1, buf485, LOCK_42_1_6_4096, buf485d, LOCK_42_1_7_4096, 256, 256);
  window_internal window_buf488_buf488d[1];
  window_datatype * buf488_ptr = (window_datatype * )buf488;
  window_datatype * buf488d_ptr = (window_datatype * )buf488d;
  window_init(window_buf488_buf488d, 1, buf488, LOCK_42_3_4_4096, buf488d, LOCK_42_3_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_2_bounds = sync_buffer[1];

  while (proc_42_2_bounds)
  {

    // Kernel call : i324:mm_kernel1
    window_acquire(window_buf486_buf486d,LOCK_42_3_0_4096,LOCK_42_3_1_0,buf486_ptr,buf486d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf487_buf487d,LOCK_42_3_2_4096,LOCK_42_3_3_4096,buf487_ptr,buf487d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf485_buf485d,LOCK_42_1_6_4096,LOCK_42_1_7_4096,buf485_ptr,buf485d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf488_buf488d,LOCK_42_3_4_4096,LOCK_42_3_5_0,buf488_ptr,buf488d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf486_buf486d),get_input_window_float(window_buf487_buf487d),get_input_window_float(window_buf485_buf485d),get_output_window_float(window_buf488_buf488d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf486_buf486d,LOCK_42_3_0_4096,LOCK_42_3_1_0,buf486_ptr,buf486d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf487_buf487d,LOCK_42_3_2_4096,LOCK_42_3_3_4096,buf487_ptr,buf487d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf485_buf485d,LOCK_42_1_6_4096,LOCK_42_1_7_4096,buf485_ptr,buf485d_ptr,0,index, REL_WRITE);
    window_release(window_buf488_buf488d,LOCK_42_3_4_4096,LOCK_42_3_5_0,buf488_ptr,buf488d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_2_bounds > 0)
      --proc_42_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}