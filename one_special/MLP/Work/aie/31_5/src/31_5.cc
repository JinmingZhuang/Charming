// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_5/src/31_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_5_2_4096 18
#define LOCK_31_5_3_0 19
#define LOCK_32_5_6_4096 54
#define LOCK_32_5_7_0 55
#define LOCK_31_5_0_4096 16
#define LOCK_31_5_1_0 17
#define LOCK_31_5_4_0 20
#define LOCK_31_5_5_0 21

// Declare shared memory buffers
v4float buf794[256];
v4float buf794d[256];
v4float buf795[256];
v4float buf795d[256];
v4float buf796[256];
v4float buf796d[256];
v4float buf797[256];
v4float buf797d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf795_buf795d[1];
  window_datatype * buf795_ptr = (window_datatype * )buf795;
  window_datatype * buf795d_ptr = (window_datatype * )buf795d;
  window_init(window_buf795_buf795d, 1, buf795, LOCK_31_5_2_4096, buf795d, LOCK_31_5_3_0, 256, 256);
  window_internal window_buf796_buf796d[1];
  window_datatype * buf796_ptr = (window_datatype * )buf796;
  window_datatype * buf796d_ptr = (window_datatype * )buf796d;
  window_init(window_buf796_buf796d, 1, buf796, LOCK_32_5_6_4096, buf796d, LOCK_32_5_7_0, 256, 256);
  window_internal window_buf794_buf794d[1];
  window_datatype * buf794_ptr = (window_datatype * )buf794;
  window_datatype * buf794d_ptr = (window_datatype * )buf794d;
  window_init(window_buf794_buf794d, 1, buf794, LOCK_31_5_0_4096, buf794d, LOCK_31_5_1_0, 256, 256);
  window_internal window_buf797_buf797d[1];
  window_datatype * buf797_ptr = (window_datatype * )buf797;
  window_datatype * buf797d_ptr = (window_datatype * )buf797d;
  window_init(window_buf797_buf797d, 1, buf797, LOCK_31_5_4_0, buf797d, LOCK_31_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_5_bounds = sync_buffer[1];

  while (proc_31_5_bounds)
  {

    // Kernel call : i479:mm_kernel1
    window_acquire(window_buf795_buf795d,LOCK_31_5_2_4096,LOCK_31_5_3_0,buf795_ptr,buf795d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf796_buf796d,LOCK_32_5_6_4096,LOCK_32_5_7_0,buf796_ptr,buf796d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf794_buf794d,LOCK_31_5_0_4096,LOCK_31_5_1_0,buf794_ptr,buf794d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf797_buf797d,LOCK_31_5_4_0,LOCK_31_5_5_0,buf797_ptr,buf797d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf795_buf795d),get_input_window_float(window_buf796_buf796d),get_input_window_float(window_buf794_buf794d),get_output_window_float(window_buf797_buf797d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf795_buf795d,LOCK_31_5_2_4096,LOCK_31_5_3_0,buf795_ptr,buf795d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf796_buf796d,LOCK_32_5_6_4096,LOCK_32_5_7_0,buf796_ptr,buf796d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf794_buf794d,LOCK_31_5_0_4096,LOCK_31_5_1_0,buf794_ptr,buf794d_ptr,0,index, REL_WRITE);
    window_release(window_buf797_buf797d,LOCK_31_5_4_0,LOCK_31_5_5_0,buf797_ptr,buf797d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_5_bounds > 0)
      --proc_31_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}