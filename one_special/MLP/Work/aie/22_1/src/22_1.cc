// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_1/src/22_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_0_2_4096 2
#define LOCK_22_0_3_4096 3
#define LOCK_22_1_4_0 20
#define LOCK_22_1_5_0 21
#define LOCK_22_1_2_4096 18
#define LOCK_22_1_3_4096 19
#define LOCK_22_1_6_4096 22
#define LOCK_22_1_7_4096 23

// Declare shared memory buffers
v4float buf242[256];
v4float buf242d[256];
v4float buf243[256];
v4float buf243d[256];
v4float buf244[256];
v4float buf244d[256];
v4float buf245[256];
v4float buf245d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf243_buf243d[1];
  window_datatype * buf243_ptr = (window_datatype * )buf243;
  window_datatype * buf243d_ptr = (window_datatype * )buf243d;
  window_init(window_buf243_buf243d, 1, buf243, LOCK_22_0_2_4096, buf243d, LOCK_22_0_3_4096, 256, 256);
  window_internal window_buf244_buf244d[1];
  window_datatype * buf244_ptr = (window_datatype * )buf244;
  window_datatype * buf244d_ptr = (window_datatype * )buf244d;
  window_init(window_buf244_buf244d, 1, buf244, LOCK_22_1_4_0, buf244d, LOCK_22_1_5_0, 256, 256);
  window_internal window_buf242_buf242d[1];
  window_datatype * buf242_ptr = (window_datatype * )buf242;
  window_datatype * buf242d_ptr = (window_datatype * )buf242d;
  window_init(window_buf242_buf242d, 1, buf242, LOCK_22_1_2_4096, buf242d, LOCK_22_1_3_4096, 256, 256);
  window_internal window_buf245_buf245d[1];
  window_datatype * buf245_ptr = (window_datatype * )buf245;
  window_datatype * buf245d_ptr = (window_datatype * )buf245d;
  window_init(window_buf245_buf245d, 1, buf245, LOCK_22_1_6_4096, buf245d, LOCK_22_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_1_bounds = sync_buffer[1];

  while (proc_22_1_bounds)
  {

    // Kernel call : i203:mm_kernel1
    window_acquire(window_buf243_buf243d,LOCK_22_0_2_4096,LOCK_22_0_3_4096,buf243_ptr,buf243d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf244_buf244d,LOCK_22_1_4_0,LOCK_22_1_5_0,buf244_ptr,buf244d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf242_buf242d,LOCK_22_1_2_4096,LOCK_22_1_3_4096,buf242_ptr,buf242d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf245_buf245d,LOCK_22_1_6_4096,LOCK_22_1_7_4096,buf245_ptr,buf245d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf243_buf243d),get_input_window_float(window_buf244_buf244d),get_input_window_float(window_buf242_buf242d),get_output_window_float(window_buf245_buf245d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf243_buf243d,LOCK_22_0_2_4096,LOCK_22_0_3_4096,buf243_ptr,buf243d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf244_buf244d,LOCK_22_1_4_0,LOCK_22_1_5_0,buf244_ptr,buf244d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf242_buf242d,LOCK_22_1_2_4096,LOCK_22_1_3_4096,buf242_ptr,buf242d_ptr,0,index, REL_WRITE);
    window_release(window_buf245_buf245d,LOCK_22_1_6_4096,LOCK_22_1_7_4096,buf245_ptr,buf245d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_1_bounds > 0)
      --proc_22_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}