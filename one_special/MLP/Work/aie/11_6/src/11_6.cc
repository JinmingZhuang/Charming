// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_6/src/11_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_6_0_0 16
#define LOCK_10_6_1_0 17
#define LOCK_11_6_2_4096 50
#define LOCK_11_6_3_0 51
#define LOCK_11_5_4_0 4
#define LOCK_11_5_5_0 5
#define LOCK_11_6_4_4096 52
#define LOCK_11_6_5_4096 53

// Declare shared memory buffers
v4float buf1037[256];
v4float buf1037d[256];
v4float buf1038[256];
v4float buf1038d[256];
v4float buf1039[256];
v4float buf1039d[256];
v4float buf1040[256];
v4float buf1040d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1038_buf1038d[1];
  window_datatype * buf1038_ptr = (window_datatype * )buf1038;
  window_datatype * buf1038d_ptr = (window_datatype * )buf1038d;
  window_init(window_buf1038_buf1038d, 1, buf1038, LOCK_10_6_0_0, buf1038d, LOCK_10_6_1_0, 256, 256);
  window_internal window_buf1039_buf1039d[1];
  window_datatype * buf1039_ptr = (window_datatype * )buf1039;
  window_datatype * buf1039d_ptr = (window_datatype * )buf1039d;
  window_init(window_buf1039_buf1039d, 1, buf1039, LOCK_11_6_2_4096, buf1039d, LOCK_11_6_3_0, 256, 256);
  window_internal window_buf1037_buf1037d[1];
  window_datatype * buf1037_ptr = (window_datatype * )buf1037;
  window_datatype * buf1037d_ptr = (window_datatype * )buf1037d;
  window_init(window_buf1037_buf1037d, 1, buf1037, LOCK_11_5_4_0, buf1037d, LOCK_11_5_5_0, 256, 256);
  window_internal window_buf1040_buf1040d[1];
  window_datatype * buf1040_ptr = (window_datatype * )buf1040;
  window_datatype * buf1040d_ptr = (window_datatype * )buf1040d;
  window_init(window_buf1040_buf1040d, 1, buf1040, LOCK_11_6_4_4096, buf1040d, LOCK_11_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_6_bounds = sync_buffer[1];

  while (proc_11_6_bounds)
  {

    // Kernel call : i600:mm_kernel1
    window_acquire(window_buf1038_buf1038d,LOCK_10_6_0_0,LOCK_10_6_1_0,buf1038_ptr,buf1038d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1039_buf1039d,LOCK_11_6_2_4096,LOCK_11_6_3_0,buf1039_ptr,buf1039d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1037_buf1037d,LOCK_11_5_4_0,LOCK_11_5_5_0,buf1037_ptr,buf1037d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1040_buf1040d,LOCK_11_6_4_4096,LOCK_11_6_5_4096,buf1040_ptr,buf1040d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1038_buf1038d),get_input_window_float(window_buf1039_buf1039d),get_input_window_float(window_buf1037_buf1037d),get_output_window_float(window_buf1040_buf1040d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1038_buf1038d,LOCK_10_6_0_0,LOCK_10_6_1_0,buf1038_ptr,buf1038d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1039_buf1039d,LOCK_11_6_2_4096,LOCK_11_6_3_0,buf1039_ptr,buf1039d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1037_buf1037d,LOCK_11_5_4_0,LOCK_11_5_5_0,buf1037_ptr,buf1037d_ptr,0,index, REL_WRITE);
    window_release(window_buf1040_buf1040d,LOCK_11_6_4_4096,LOCK_11_6_5_4096,buf1040_ptr,buf1040d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_6_bounds > 0)
      --proc_11_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}