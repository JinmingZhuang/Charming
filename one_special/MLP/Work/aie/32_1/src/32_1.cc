// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_1/src/32_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_32_2_0_0 32
#define LOCK_32_2_1_0 33
#define LOCK_32_2_2_4096 34
#define LOCK_32_2_3_0 35
#define LOCK_32_1_4_4096 20
#define LOCK_32_1_5_4096 21
#define LOCK_32_1_6_0 22
#define LOCK_32_1_7_4096 23

// Declare shared memory buffers
v4float buf362[256];
v4float buf362d[256];
v4float buf363[256];
v4float buf363d[256];
v4float buf364[256];
v4float buf364d[256];
v4float buf365[256];
v4float buf365d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf363_buf363d[1];
  window_datatype * buf363_ptr = (window_datatype * )buf363;
  window_datatype * buf363d_ptr = (window_datatype * )buf363d;
  window_init(window_buf363_buf363d, 1, buf363, LOCK_32_2_0_0, buf363d, LOCK_32_2_1_0, 256, 256);
  window_internal window_buf364_buf364d[1];
  window_datatype * buf364_ptr = (window_datatype * )buf364;
  window_datatype * buf364d_ptr = (window_datatype * )buf364d;
  window_init(window_buf364_buf364d, 1, buf364, LOCK_32_2_2_4096, buf364d, LOCK_32_2_3_0, 256, 256);
  window_internal window_buf362_buf362d[1];
  window_datatype * buf362_ptr = (window_datatype * )buf362;
  window_datatype * buf362d_ptr = (window_datatype * )buf362d;
  window_init(window_buf362_buf362d, 1, buf362, LOCK_32_1_4_4096, buf362d, LOCK_32_1_5_4096, 256, 256);
  window_internal window_buf365_buf365d[1];
  window_datatype * buf365_ptr = (window_datatype * )buf365;
  window_datatype * buf365d_ptr = (window_datatype * )buf365d;
  window_init(window_buf365_buf365d, 1, buf365, LOCK_32_1_6_0, buf365d, LOCK_32_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_1_bounds = sync_buffer[1];

  while (proc_32_1_bounds)
  {

    // Kernel call : i263:mm_kernel1
    window_acquire(window_buf363_buf363d,LOCK_32_2_0_0,LOCK_32_2_1_0,buf363_ptr,buf363d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf364_buf364d,LOCK_32_2_2_4096,LOCK_32_2_3_0,buf364_ptr,buf364d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf362_buf362d,LOCK_32_1_4_4096,LOCK_32_1_5_4096,buf362_ptr,buf362d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf365_buf365d,LOCK_32_1_6_0,LOCK_32_1_7_4096,buf365_ptr,buf365d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf363_buf363d),get_input_window_float(window_buf364_buf364d),get_input_window_float(window_buf362_buf362d),get_output_window_float(window_buf365_buf365d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf363_buf363d,LOCK_32_2_0_0,LOCK_32_2_1_0,buf363_ptr,buf363d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf364_buf364d,LOCK_32_2_2_4096,LOCK_32_2_3_0,buf364_ptr,buf364d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf362_buf362d,LOCK_32_1_4_4096,LOCK_32_1_5_4096,buf362_ptr,buf362d_ptr,0,index, REL_WRITE);
    window_release(window_buf365_buf365d,LOCK_32_1_6_0,LOCK_32_1_7_4096,buf365_ptr,buf365d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_1_bounds > 0)
      --proc_32_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}