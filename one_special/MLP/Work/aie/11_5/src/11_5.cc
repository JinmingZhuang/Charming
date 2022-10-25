// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_5/src/11_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_6_0_0 32
#define LOCK_11_6_1_0 33
#define LOCK_11_5_2_4096 18
#define LOCK_11_5_3_0 19
#define LOCK_11_5_0_0 16
#define LOCK_11_5_1_4096 17
#define LOCK_11_5_4_0 20
#define LOCK_11_5_5_0 21

// Declare shared memory buffers
v4float buf1034[256];
v4float buf1034d[256];
v4float buf1035[256];
v4float buf1035d[256];
v4float buf1036[256];
v4float buf1036d[256];
v4float buf1037[256];
v4float buf1037d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1035_buf1035d[1];
  window_datatype * buf1035_ptr = (window_datatype * )buf1035;
  window_datatype * buf1035d_ptr = (window_datatype * )buf1035d;
  window_init(window_buf1035_buf1035d, 1, buf1035, LOCK_11_6_0_0, buf1035d, LOCK_11_6_1_0, 256, 256);
  window_internal window_buf1036_buf1036d[1];
  window_datatype * buf1036_ptr = (window_datatype * )buf1036;
  window_datatype * buf1036d_ptr = (window_datatype * )buf1036d;
  window_init(window_buf1036_buf1036d, 1, buf1036, LOCK_11_5_2_4096, buf1036d, LOCK_11_5_3_0, 256, 256);
  window_internal window_buf1034_buf1034d[1];
  window_datatype * buf1034_ptr = (window_datatype * )buf1034;
  window_datatype * buf1034d_ptr = (window_datatype * )buf1034d;
  window_init(window_buf1034_buf1034d, 1, buf1034, LOCK_11_5_0_0, buf1034d, LOCK_11_5_1_4096, 256, 256);
  window_internal window_buf1037_buf1037d[1];
  window_datatype * buf1037_ptr = (window_datatype * )buf1037;
  window_datatype * buf1037d_ptr = (window_datatype * )buf1037d;
  window_init(window_buf1037_buf1037d, 1, buf1037, LOCK_11_5_4_0, buf1037d, LOCK_11_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_5_bounds = sync_buffer[1];

  while (proc_11_5_bounds)
  {

    // Kernel call : i599:mm_kernel1
    window_acquire(window_buf1035_buf1035d,LOCK_11_6_0_0,LOCK_11_6_1_0,buf1035_ptr,buf1035d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1036_buf1036d,LOCK_11_5_2_4096,LOCK_11_5_3_0,buf1036_ptr,buf1036d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1034_buf1034d,LOCK_11_5_0_0,LOCK_11_5_1_4096,buf1034_ptr,buf1034d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1037_buf1037d,LOCK_11_5_4_0,LOCK_11_5_5_0,buf1037_ptr,buf1037d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1035_buf1035d),get_input_window_float(window_buf1036_buf1036d),get_input_window_float(window_buf1034_buf1034d),get_output_window_float(window_buf1037_buf1037d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1035_buf1035d,LOCK_11_6_0_0,LOCK_11_6_1_0,buf1035_ptr,buf1035d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1036_buf1036d,LOCK_11_5_2_4096,LOCK_11_5_3_0,buf1036_ptr,buf1036d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1034_buf1034d,LOCK_11_5_0_0,LOCK_11_5_1_4096,buf1034_ptr,buf1034d_ptr,0,index, REL_WRITE);
    window_release(window_buf1037_buf1037d,LOCK_11_5_4_0,LOCK_11_5_5_0,buf1037_ptr,buf1037d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_5_bounds > 0)
      --proc_11_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}