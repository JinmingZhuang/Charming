// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_1/src/16_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_16_0_0_0 0
#define LOCK_16_0_1_0 1
#define LOCK_16_0_2_4096 2
#define LOCK_16_0_3_4096 3
#define LOCK_16_1_4_4096 20
#define LOCK_16_1_5_4096 21
#define LOCK_16_1_6_0 22
#define LOCK_16_1_7_4096 23

// Declare shared memory buffers
v4float buf170[256];
v4float buf170d[256];
v4float buf171[256];
v4float buf171d[256];
v4float buf172[256];
v4float buf172d[256];
v4float buf173[256];
v4float buf173d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf171_buf171d[1];
  window_datatype * buf171_ptr = (window_datatype * )buf171;
  window_datatype * buf171d_ptr = (window_datatype * )buf171d;
  window_init(window_buf171_buf171d, 1, buf171, LOCK_16_0_0_0, buf171d, LOCK_16_0_1_0, 256, 256);
  window_internal window_buf172_buf172d[1];
  window_datatype * buf172_ptr = (window_datatype * )buf172;
  window_datatype * buf172d_ptr = (window_datatype * )buf172d;
  window_init(window_buf172_buf172d, 1, buf172, LOCK_16_0_2_4096, buf172d, LOCK_16_0_3_4096, 256, 256);
  window_internal window_buf170_buf170d[1];
  window_datatype * buf170_ptr = (window_datatype * )buf170;
  window_datatype * buf170d_ptr = (window_datatype * )buf170d;
  window_init(window_buf170_buf170d, 1, buf170, LOCK_16_1_4_4096, buf170d, LOCK_16_1_5_4096, 256, 256);
  window_internal window_buf173_buf173d[1];
  window_datatype * buf173_ptr = (window_datatype * )buf173;
  window_datatype * buf173d_ptr = (window_datatype * )buf173d;
  window_init(window_buf173_buf173d, 1, buf173, LOCK_16_1_6_0, buf173d, LOCK_16_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_1_bounds = sync_buffer[1];

  while (proc_16_1_bounds)
  {

    // Kernel call : i167:mm_kernel1
    window_acquire(window_buf171_buf171d,LOCK_16_0_0_0,LOCK_16_0_1_0,buf171_ptr,buf171d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf172_buf172d,LOCK_16_0_2_4096,LOCK_16_0_3_4096,buf172_ptr,buf172d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf170_buf170d,LOCK_16_1_4_4096,LOCK_16_1_5_4096,buf170_ptr,buf170d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf173_buf173d,LOCK_16_1_6_0,LOCK_16_1_7_4096,buf173_ptr,buf173d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf171_buf171d),get_input_window_float(window_buf172_buf172d),get_input_window_float(window_buf170_buf170d),get_output_window_float(window_buf173_buf173d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf171_buf171d,LOCK_16_0_0_0,LOCK_16_0_1_0,buf171_ptr,buf171d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf172_buf172d,LOCK_16_0_2_4096,LOCK_16_0_3_4096,buf172_ptr,buf172d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf170_buf170d,LOCK_16_1_4_4096,LOCK_16_1_5_4096,buf170_ptr,buf170d_ptr,0,index, REL_WRITE);
    window_release(window_buf173_buf173d,LOCK_16_1_6_0,LOCK_16_1_7_4096,buf173_ptr,buf173d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_1_bounds > 0)
      --proc_16_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}