// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_5/src/41_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_41_4_2_4096 2
#define LOCK_41_4_3_4096 3
#define LOCK_41_5_2_0 18
#define LOCK_41_5_3_4096 19
#define LOCK_41_5_0_0 16
#define LOCK_41_5_1_4096 17
#define LOCK_41_5_4_0 20
#define LOCK_41_5_5_4096 21

// Declare shared memory buffers
v4float buf674[256];
v4float buf674d[256];
v4float buf675[256];
v4float buf675d[256];
v4float buf676[256];
v4float buf676d[256];
v4float buf677[256];
v4float buf677d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf675_buf675d[1];
  window_datatype * buf675_ptr = (window_datatype * )buf675;
  window_datatype * buf675d_ptr = (window_datatype * )buf675d;
  window_init(window_buf675_buf675d, 1, buf675, LOCK_41_4_2_4096, buf675d, LOCK_41_4_3_4096, 256, 256);
  window_internal window_buf676_buf676d[1];
  window_datatype * buf676_ptr = (window_datatype * )buf676;
  window_datatype * buf676d_ptr = (window_datatype * )buf676d;
  window_init(window_buf676_buf676d, 1, buf676, LOCK_41_5_2_0, buf676d, LOCK_41_5_3_4096, 256, 256);
  window_internal window_buf674_buf674d[1];
  window_datatype * buf674_ptr = (window_datatype * )buf674;
  window_datatype * buf674d_ptr = (window_datatype * )buf674d;
  window_init(window_buf674_buf674d, 1, buf674, LOCK_41_5_0_0, buf674d, LOCK_41_5_1_4096, 256, 256);
  window_internal window_buf677_buf677d[1];
  window_datatype * buf677_ptr = (window_datatype * )buf677;
  window_datatype * buf677d_ptr = (window_datatype * )buf677d;
  window_init(window_buf677_buf677d, 1, buf677, LOCK_41_5_4_0, buf677d, LOCK_41_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_5_bounds = sync_buffer[1];

  while (proc_41_5_bounds)
  {

    // Kernel call : i419:mm_kernel1
    window_acquire(window_buf675_buf675d,LOCK_41_4_2_4096,LOCK_41_4_3_4096,buf675_ptr,buf675d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf676_buf676d,LOCK_41_5_2_0,LOCK_41_5_3_4096,buf676_ptr,buf676d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf674_buf674d,LOCK_41_5_0_0,LOCK_41_5_1_4096,buf674_ptr,buf674d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf677_buf677d,LOCK_41_5_4_0,LOCK_41_5_5_4096,buf677_ptr,buf677d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf675_buf675d),get_input_window_float(window_buf676_buf676d),get_input_window_float(window_buf674_buf674d),get_output_window_float(window_buf677_buf677d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf675_buf675d,LOCK_41_4_2_4096,LOCK_41_4_3_4096,buf675_ptr,buf675d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf676_buf676d,LOCK_41_5_2_0,LOCK_41_5_3_4096,buf676_ptr,buf676d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf674_buf674d,LOCK_41_5_0_0,LOCK_41_5_1_4096,buf674_ptr,buf674d_ptr,0,index, REL_WRITE);
    window_release(window_buf677_buf677d,LOCK_41_5_4_0,LOCK_41_5_5_4096,buf677_ptr,buf677d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_5_bounds > 0)
      --proc_41_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}