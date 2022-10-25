// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_2/src/7_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_2_2_4096 18
#define LOCK_6_2_3_4096 19
#define LOCK_7_3_0_4096 32
#define LOCK_7_3_1_0 33
#define LOCK_7_1_6_0 6
#define LOCK_7_1_7_4096 7
#define LOCK_7_3_2_4096 34
#define LOCK_7_3_3_4096 35

// Declare shared memory buffers
v4float buf65[256];
v4float buf65d[256];
v4float buf66[256];
v4float buf66d[256];
v4float buf67[256];
v4float buf67d[256];
v4float buf68[256];
v4float buf68d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf66_buf66d[1];
  window_datatype * buf66_ptr = (window_datatype * )buf66;
  window_datatype * buf66d_ptr = (window_datatype * )buf66d;
  window_init(window_buf66_buf66d, 1, buf66, LOCK_6_2_2_4096, buf66d, LOCK_6_2_3_4096, 256, 256);
  window_internal window_buf67_buf67d[1];
  window_datatype * buf67_ptr = (window_datatype * )buf67;
  window_datatype * buf67d_ptr = (window_datatype * )buf67d;
  window_init(window_buf67_buf67d, 1, buf67, LOCK_7_3_0_4096, buf67d, LOCK_7_3_1_0, 256, 256);
  window_internal window_buf65_buf65d[1];
  window_datatype * buf65_ptr = (window_datatype * )buf65;
  window_datatype * buf65d_ptr = (window_datatype * )buf65d;
  window_init(window_buf65_buf65d, 1, buf65, LOCK_7_1_6_0, buf65d, LOCK_7_1_7_4096, 256, 256);
  window_internal window_buf68_buf68d[1];
  window_datatype * buf68_ptr = (window_datatype * )buf68;
  window_datatype * buf68d_ptr = (window_datatype * )buf68d;
  window_init(window_buf68_buf68d, 1, buf68, LOCK_7_3_2_4096, buf68d, LOCK_7_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_2_bounds = sync_buffer[1];

  while (proc_7_2_bounds)
  {

    // Kernel call : i114:mm_kernel1
    window_acquire(window_buf66_buf66d,LOCK_6_2_2_4096,LOCK_6_2_3_4096,buf66_ptr,buf66d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf67_buf67d,LOCK_7_3_0_4096,LOCK_7_3_1_0,buf67_ptr,buf67d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf65_buf65d,LOCK_7_1_6_0,LOCK_7_1_7_4096,buf65_ptr,buf65d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf68_buf68d,LOCK_7_3_2_4096,LOCK_7_3_3_4096,buf68_ptr,buf68d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf66_buf66d),get_input_window_float(window_buf67_buf67d),get_input_window_float(window_buf65_buf65d),get_output_window_float(window_buf68_buf68d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf66_buf66d,LOCK_6_2_2_4096,LOCK_6_2_3_4096,buf66_ptr,buf66d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf67_buf67d,LOCK_7_3_0_4096,LOCK_7_3_1_0,buf67_ptr,buf67d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf65_buf65d,LOCK_7_1_6_0,LOCK_7_1_7_4096,buf65_ptr,buf65d_ptr,0,index, REL_WRITE);
    window_release(window_buf68_buf68d,LOCK_7_3_2_4096,LOCK_7_3_3_4096,buf68_ptr,buf68d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_2_bounds > 0)
      --proc_7_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}