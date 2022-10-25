// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_1/src/12_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_1_4_0 20
#define LOCK_12_1_5_0 21
#define LOCK_12_2_0_0 32
#define LOCK_12_2_1_0 33
#define LOCK_12_1_2_4096 18
#define LOCK_12_1_3_4096 19
#define LOCK_12_1_6_0 22
#define LOCK_12_1_7_0 23

// Declare shared memory buffers
v4float buf122[256];
v4float buf122d[256];
v4float buf123[256];
v4float buf123d[256];
v4float buf124[256];
v4float buf124d[256];
v4float buf125[256];
v4float buf125d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf123_buf123d[1];
  window_datatype * buf123_ptr = (window_datatype * )buf123;
  window_datatype * buf123d_ptr = (window_datatype * )buf123d;
  window_init(window_buf123_buf123d, 1, buf123, LOCK_12_1_4_0, buf123d, LOCK_12_1_5_0, 256, 256);
  window_internal window_buf124_buf124d[1];
  window_datatype * buf124_ptr = (window_datatype * )buf124;
  window_datatype * buf124d_ptr = (window_datatype * )buf124d;
  window_init(window_buf124_buf124d, 1, buf124, LOCK_12_2_0_0, buf124d, LOCK_12_2_1_0, 256, 256);
  window_internal window_buf122_buf122d[1];
  window_datatype * buf122_ptr = (window_datatype * )buf122;
  window_datatype * buf122d_ptr = (window_datatype * )buf122d;
  window_init(window_buf122_buf122d, 1, buf122, LOCK_12_1_2_4096, buf122d, LOCK_12_1_3_4096, 256, 256);
  window_internal window_buf125_buf125d[1];
  window_datatype * buf125_ptr = (window_datatype * )buf125;
  window_datatype * buf125d_ptr = (window_datatype * )buf125d;
  window_init(window_buf125_buf125d, 1, buf125, LOCK_12_1_6_0, buf125d, LOCK_12_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_1_bounds = sync_buffer[1];

  while (proc_12_1_bounds)
  {

    // Kernel call : i143:mm_kernel1
    window_acquire(window_buf123_buf123d,LOCK_12_1_4_0,LOCK_12_1_5_0,buf123_ptr,buf123d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf124_buf124d,LOCK_12_2_0_0,LOCK_12_2_1_0,buf124_ptr,buf124d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf122_buf122d,LOCK_12_1_2_4096,LOCK_12_1_3_4096,buf122_ptr,buf122d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf125_buf125d,LOCK_12_1_6_0,LOCK_12_1_7_0,buf125_ptr,buf125d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf123_buf123d),get_input_window_float(window_buf124_buf124d),get_input_window_float(window_buf122_buf122d),get_output_window_float(window_buf125_buf125d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf123_buf123d,LOCK_12_1_4_0,LOCK_12_1_5_0,buf123_ptr,buf123d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf124_buf124d,LOCK_12_2_0_0,LOCK_12_2_1_0,buf124_ptr,buf124d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf122_buf122d,LOCK_12_1_2_4096,LOCK_12_1_3_4096,buf122_ptr,buf122d_ptr,0,index, REL_WRITE);
    window_release(window_buf125_buf125d,LOCK_12_1_6_0,LOCK_12_1_7_0,buf125_ptr,buf125d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_1_bounds > 0)
      --proc_12_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}