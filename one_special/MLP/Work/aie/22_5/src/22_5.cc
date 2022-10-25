// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_5/src/22_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_6_0_0 32
#define LOCK_22_6_1_0 33
#define LOCK_22_4_2_4096 2
#define LOCK_22_4_3_4096 3
#define LOCK_22_5_2_0 18
#define LOCK_22_5_3_0 19
#define LOCK_22_5_4_4096 20
#define LOCK_22_5_5_4096 21

// Declare shared memory buffers
v4float buf902[256];
v4float buf902d[256];
v4float buf903[256];
v4float buf903d[256];
v4float buf904[256];
v4float buf904d[256];
v4float buf905[256];
v4float buf905d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf903_buf903d[1];
  window_datatype * buf903_ptr = (window_datatype * )buf903;
  window_datatype * buf903d_ptr = (window_datatype * )buf903d;
  window_init(window_buf903_buf903d, 1, buf903, LOCK_22_6_0_0, buf903d, LOCK_22_6_1_0, 256, 256);
  window_internal window_buf904_buf904d[1];
  window_datatype * buf904_ptr = (window_datatype * )buf904;
  window_datatype * buf904d_ptr = (window_datatype * )buf904d;
  window_init(window_buf904_buf904d, 1, buf904, LOCK_22_4_2_4096, buf904d, LOCK_22_4_3_4096, 256, 256);
  window_internal window_buf902_buf902d[1];
  window_datatype * buf902_ptr = (window_datatype * )buf902;
  window_datatype * buf902d_ptr = (window_datatype * )buf902d;
  window_init(window_buf902_buf902d, 1, buf902, LOCK_22_5_2_0, buf902d, LOCK_22_5_3_0, 256, 256);
  window_internal window_buf905_buf905d[1];
  window_datatype * buf905_ptr = (window_datatype * )buf905;
  window_datatype * buf905d_ptr = (window_datatype * )buf905d;
  window_init(window_buf905_buf905d, 1, buf905, LOCK_22_5_4_4096, buf905d, LOCK_22_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_5_bounds = sync_buffer[1];

  while (proc_22_5_bounds)
  {

    // Kernel call : i533:mm_kernel1
    window_acquire(window_buf903_buf903d,LOCK_22_6_0_0,LOCK_22_6_1_0,buf903_ptr,buf903d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf904_buf904d,LOCK_22_4_2_4096,LOCK_22_4_3_4096,buf904_ptr,buf904d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf902_buf902d,LOCK_22_5_2_0,LOCK_22_5_3_0,buf902_ptr,buf902d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf905_buf905d,LOCK_22_5_4_4096,LOCK_22_5_5_4096,buf905_ptr,buf905d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf903_buf903d),get_input_window_float(window_buf904_buf904d),get_input_window_float(window_buf902_buf902d),get_output_window_float(window_buf905_buf905d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf903_buf903d,LOCK_22_6_0_0,LOCK_22_6_1_0,buf903_ptr,buf903d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf904_buf904d,LOCK_22_4_2_4096,LOCK_22_4_3_4096,buf904_ptr,buf904d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf902_buf902d,LOCK_22_5_2_0,LOCK_22_5_3_0,buf902_ptr,buf902d_ptr,0,index, REL_WRITE);
    window_release(window_buf905_buf905d,LOCK_22_5_4_4096,LOCK_22_5_5_4096,buf905_ptr,buf905d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_5_bounds > 0)
      --proc_22_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}