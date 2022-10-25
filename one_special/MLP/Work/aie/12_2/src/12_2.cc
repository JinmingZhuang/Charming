// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_2/src/12_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_3_0_4096 32
#define LOCK_12_3_1_4096 33
#define LOCK_12_3_2_0 34
#define LOCK_12_3_3_4096 35
#define LOCK_12_1_6_0 6
#define LOCK_12_1_7_0 7
#define LOCK_12_3_4_0 36
#define LOCK_12_3_5_0 37

// Declare shared memory buffers
v4float buf125[256];
v4float buf125d[256];
v4float buf126[256];
v4float buf126d[256];
v4float buf127[256];
v4float buf127d[256];
v4float buf128[256];
v4float buf128d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf126_buf126d[1];
  window_datatype * buf126_ptr = (window_datatype * )buf126;
  window_datatype * buf126d_ptr = (window_datatype * )buf126d;
  window_init(window_buf126_buf126d, 1, buf126, LOCK_12_3_0_4096, buf126d, LOCK_12_3_1_4096, 256, 256);
  window_internal window_buf127_buf127d[1];
  window_datatype * buf127_ptr = (window_datatype * )buf127;
  window_datatype * buf127d_ptr = (window_datatype * )buf127d;
  window_init(window_buf127_buf127d, 1, buf127, LOCK_12_3_2_0, buf127d, LOCK_12_3_3_4096, 256, 256);
  window_internal window_buf125_buf125d[1];
  window_datatype * buf125_ptr = (window_datatype * )buf125;
  window_datatype * buf125d_ptr = (window_datatype * )buf125d;
  window_init(window_buf125_buf125d, 1, buf125, LOCK_12_1_6_0, buf125d, LOCK_12_1_7_0, 256, 256);
  window_internal window_buf128_buf128d[1];
  window_datatype * buf128_ptr = (window_datatype * )buf128;
  window_datatype * buf128d_ptr = (window_datatype * )buf128d;
  window_init(window_buf128_buf128d, 1, buf128, LOCK_12_3_4_0, buf128d, LOCK_12_3_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_2_bounds = sync_buffer[1];

  while (proc_12_2_bounds)
  {

    // Kernel call : i144:mm_kernel1
    window_acquire(window_buf126_buf126d,LOCK_12_3_0_4096,LOCK_12_3_1_4096,buf126_ptr,buf126d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf127_buf127d,LOCK_12_3_2_0,LOCK_12_3_3_4096,buf127_ptr,buf127d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf125_buf125d,LOCK_12_1_6_0,LOCK_12_1_7_0,buf125_ptr,buf125d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf128_buf128d,LOCK_12_3_4_0,LOCK_12_3_5_0,buf128_ptr,buf128d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf126_buf126d),get_input_window_float(window_buf127_buf127d),get_input_window_float(window_buf125_buf125d),get_output_window_float(window_buf128_buf128d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf126_buf126d,LOCK_12_3_0_4096,LOCK_12_3_1_4096,buf126_ptr,buf126d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf127_buf127d,LOCK_12_3_2_0,LOCK_12_3_3_4096,buf127_ptr,buf127d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf125_buf125d,LOCK_12_1_6_0,LOCK_12_1_7_0,buf125_ptr,buf125d_ptr,0,index, REL_WRITE);
    window_release(window_buf128_buf128d,LOCK_12_3_4_0,LOCK_12_3_5_0,buf128_ptr,buf128d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_2_bounds > 0)
      --proc_12_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}