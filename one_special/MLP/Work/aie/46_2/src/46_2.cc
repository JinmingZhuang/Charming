// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_2/src/46_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_3_0_0 32
#define LOCK_46_3_1_0 33
#define LOCK_46_3_2_4096 34
#define LOCK_46_3_3_4096 35
#define LOCK_46_1_6_0 6
#define LOCK_46_1_7_4096 7
#define LOCK_46_2_2_4096 50
#define LOCK_46_2_3_4096 51

// Declare shared memory buffers
v4float buf533[256];
v4float buf533d[256];
v4float buf534[256];
v4float buf534d[256];
v4float buf535[256];
v4float buf535d[256];
v4float buf536[256];
v4float buf536d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf534_buf534d[1];
  window_datatype * buf534_ptr = (window_datatype * )buf534;
  window_datatype * buf534d_ptr = (window_datatype * )buf534d;
  window_init(window_buf534_buf534d, 1, buf534, LOCK_46_3_0_0, buf534d, LOCK_46_3_1_0, 256, 256);
  window_internal window_buf535_buf535d[1];
  window_datatype * buf535_ptr = (window_datatype * )buf535;
  window_datatype * buf535d_ptr = (window_datatype * )buf535d;
  window_init(window_buf535_buf535d, 1, buf535, LOCK_46_3_2_4096, buf535d, LOCK_46_3_3_4096, 256, 256);
  window_internal window_buf533_buf533d[1];
  window_datatype * buf533_ptr = (window_datatype * )buf533;
  window_datatype * buf533d_ptr = (window_datatype * )buf533d;
  window_init(window_buf533_buf533d, 1, buf533, LOCK_46_1_6_0, buf533d, LOCK_46_1_7_4096, 256, 256);
  window_internal window_buf536_buf536d[1];
  window_datatype * buf536_ptr = (window_datatype * )buf536;
  window_datatype * buf536d_ptr = (window_datatype * )buf536d;
  window_init(window_buf536_buf536d, 1, buf536, LOCK_46_2_2_4096, buf536d, LOCK_46_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_2_bounds = sync_buffer[1];

  while (proc_46_2_bounds)
  {

    // Kernel call : i348:mm_kernel1
    window_acquire(window_buf534_buf534d,LOCK_46_3_0_0,LOCK_46_3_1_0,buf534_ptr,buf534d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf535_buf535d,LOCK_46_3_2_4096,LOCK_46_3_3_4096,buf535_ptr,buf535d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf533_buf533d,LOCK_46_1_6_0,LOCK_46_1_7_4096,buf533_ptr,buf533d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf536_buf536d,LOCK_46_2_2_4096,LOCK_46_2_3_4096,buf536_ptr,buf536d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf534_buf534d),get_input_window_float(window_buf535_buf535d),get_input_window_float(window_buf533_buf533d),get_output_window_float(window_buf536_buf536d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf534_buf534d,LOCK_46_3_0_0,LOCK_46_3_1_0,buf534_ptr,buf534d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf535_buf535d,LOCK_46_3_2_4096,LOCK_46_3_3_4096,buf535_ptr,buf535d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf533_buf533d,LOCK_46_1_6_0,LOCK_46_1_7_4096,buf533_ptr,buf533d_ptr,0,index, REL_WRITE);
    window_release(window_buf536_buf536d,LOCK_46_2_2_4096,LOCK_46_2_3_4096,buf536_ptr,buf536d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_2_bounds > 0)
      --proc_46_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}