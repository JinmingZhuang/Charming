// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_2/src/31_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_3_0_0 32
#define LOCK_31_3_1_0 33
#define LOCK_31_1_6_0 6
#define LOCK_31_1_7_0 7
#define LOCK_31_1_4_4096 4
#define LOCK_31_1_5_4096 5
#define LOCK_31_2_0_0 48
#define LOCK_31_2_1_0 49

// Declare shared memory buffers
v4float buf353[256];
v4float buf353d[256];
v4float buf354[256];
v4float buf354d[256];
v4float buf355[256];
v4float buf355d[256];
v4float buf356[256];
v4float buf356d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf354_buf354d[1];
  window_datatype * buf354_ptr = (window_datatype * )buf354;
  window_datatype * buf354d_ptr = (window_datatype * )buf354d;
  window_init(window_buf354_buf354d, 1, buf354, LOCK_31_3_0_0, buf354d, LOCK_31_3_1_0, 256, 256);
  window_internal window_buf355_buf355d[1];
  window_datatype * buf355_ptr = (window_datatype * )buf355;
  window_datatype * buf355d_ptr = (window_datatype * )buf355d;
  window_init(window_buf355_buf355d, 1, buf355, LOCK_31_1_6_0, buf355d, LOCK_31_1_7_0, 256, 256);
  window_internal window_buf353_buf353d[1];
  window_datatype * buf353_ptr = (window_datatype * )buf353;
  window_datatype * buf353d_ptr = (window_datatype * )buf353d;
  window_init(window_buf353_buf353d, 1, buf353, LOCK_31_1_4_4096, buf353d, LOCK_31_1_5_4096, 256, 256);
  window_internal window_buf356_buf356d[1];
  window_datatype * buf356_ptr = (window_datatype * )buf356;
  window_datatype * buf356d_ptr = (window_datatype * )buf356d;
  window_init(window_buf356_buf356d, 1, buf356, LOCK_31_2_0_0, buf356d, LOCK_31_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_2_bounds = sync_buffer[1];

  while (proc_31_2_bounds)
  {

    // Kernel call : i258:mm_kernel1
    window_acquire(window_buf354_buf354d,LOCK_31_3_0_0,LOCK_31_3_1_0,buf354_ptr,buf354d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf355_buf355d,LOCK_31_1_6_0,LOCK_31_1_7_0,buf355_ptr,buf355d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf353_buf353d,LOCK_31_1_4_4096,LOCK_31_1_5_4096,buf353_ptr,buf353d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf356_buf356d,LOCK_31_2_0_0,LOCK_31_2_1_0,buf356_ptr,buf356d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf354_buf354d),get_input_window_float(window_buf355_buf355d),get_input_window_float(window_buf353_buf353d),get_output_window_float(window_buf356_buf356d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf354_buf354d,LOCK_31_3_0_0,LOCK_31_3_1_0,buf354_ptr,buf354d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf355_buf355d,LOCK_31_1_6_0,LOCK_31_1_7_0,buf355_ptr,buf355d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf353_buf353d,LOCK_31_1_4_4096,LOCK_31_1_5_4096,buf353_ptr,buf353d_ptr,0,index, REL_WRITE);
    window_release(window_buf356_buf356d,LOCK_31_2_0_0,LOCK_31_2_1_0,buf356_ptr,buf356d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_2_bounds > 0)
      --proc_31_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}