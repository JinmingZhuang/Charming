// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_1/src/13_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_1_0_0 48
#define LOCK_14_1_1_0 49
#define LOCK_13_0_0_0 0
#define LOCK_13_0_1_0 1
#define LOCK_13_1_2_0 18
#define LOCK_13_1_3_4096 19
#define LOCK_13_1_4_4096 20
#define LOCK_13_1_5_4096 21

// Declare shared memory buffers
v4float buf134[256];
v4float buf134d[256];
v4float buf135[256];
v4float buf135d[256];
v4float buf136[256];
v4float buf136d[256];
v4float buf137[256];
v4float buf137d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf135_buf135d[1];
  window_datatype * buf135_ptr = (window_datatype * )buf135;
  window_datatype * buf135d_ptr = (window_datatype * )buf135d;
  window_init(window_buf135_buf135d, 1, buf135, LOCK_14_1_0_0, buf135d, LOCK_14_1_1_0, 256, 256);
  window_internal window_buf136_buf136d[1];
  window_datatype * buf136_ptr = (window_datatype * )buf136;
  window_datatype * buf136d_ptr = (window_datatype * )buf136d;
  window_init(window_buf136_buf136d, 1, buf136, LOCK_13_0_0_0, buf136d, LOCK_13_0_1_0, 256, 256);
  window_internal window_buf134_buf134d[1];
  window_datatype * buf134_ptr = (window_datatype * )buf134;
  window_datatype * buf134d_ptr = (window_datatype * )buf134d;
  window_init(window_buf134_buf134d, 1, buf134, LOCK_13_1_2_0, buf134d, LOCK_13_1_3_4096, 256, 256);
  window_internal window_buf137_buf137d[1];
  window_datatype * buf137_ptr = (window_datatype * )buf137;
  window_datatype * buf137d_ptr = (window_datatype * )buf137d;
  window_init(window_buf137_buf137d, 1, buf137, LOCK_13_1_4_4096, buf137d, LOCK_13_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_1_bounds = sync_buffer[1];

  while (proc_13_1_bounds)
  {

    // Kernel call : i149:mm_kernel1
    window_acquire(window_buf135_buf135d,LOCK_14_1_0_0,LOCK_14_1_1_0,buf135_ptr,buf135d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf136_buf136d,LOCK_13_0_0_0,LOCK_13_0_1_0,buf136_ptr,buf136d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf134_buf134d,LOCK_13_1_2_0,LOCK_13_1_3_4096,buf134_ptr,buf134d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf137_buf137d,LOCK_13_1_4_4096,LOCK_13_1_5_4096,buf137_ptr,buf137d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf135_buf135d),get_input_window_float(window_buf136_buf136d),get_input_window_float(window_buf134_buf134d),get_output_window_float(window_buf137_buf137d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf135_buf135d,LOCK_14_1_0_0,LOCK_14_1_1_0,buf135_ptr,buf135d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf136_buf136d,LOCK_13_0_0_0,LOCK_13_0_1_0,buf136_ptr,buf136d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf134_buf134d,LOCK_13_1_2_0,LOCK_13_1_3_4096,buf134_ptr,buf134d_ptr,0,index, REL_WRITE);
    window_release(window_buf137_buf137d,LOCK_13_1_4_4096,LOCK_13_1_5_4096,buf137_ptr,buf137d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_1_bounds > 0)
      --proc_13_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}