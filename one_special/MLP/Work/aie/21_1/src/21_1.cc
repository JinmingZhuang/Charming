// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_1/src/21_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_0_0_0 0
#define LOCK_21_0_1_0 1
#define LOCK_22_1_0_0 48
#define LOCK_22_1_1_0 49
#define LOCK_21_1_4_4096 20
#define LOCK_21_1_5_0 21
#define LOCK_21_1_6_4096 22
#define LOCK_21_1_7_0 23

// Declare shared memory buffers
v4float buf230[256];
v4float buf230d[256];
v4float buf231[256];
v4float buf231d[256];
v4float buf232[256];
v4float buf232d[256];
v4float buf233[256];
v4float buf233d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf231_buf231d[1];
  window_datatype * buf231_ptr = (window_datatype * )buf231;
  window_datatype * buf231d_ptr = (window_datatype * )buf231d;
  window_init(window_buf231_buf231d, 1, buf231, LOCK_21_0_0_0, buf231d, LOCK_21_0_1_0, 256, 256);
  window_internal window_buf232_buf232d[1];
  window_datatype * buf232_ptr = (window_datatype * )buf232;
  window_datatype * buf232d_ptr = (window_datatype * )buf232d;
  window_init(window_buf232_buf232d, 1, buf232, LOCK_22_1_0_0, buf232d, LOCK_22_1_1_0, 256, 256);
  window_internal window_buf230_buf230d[1];
  window_datatype * buf230_ptr = (window_datatype * )buf230;
  window_datatype * buf230d_ptr = (window_datatype * )buf230d;
  window_init(window_buf230_buf230d, 1, buf230, LOCK_21_1_4_4096, buf230d, LOCK_21_1_5_0, 256, 256);
  window_internal window_buf233_buf233d[1];
  window_datatype * buf233_ptr = (window_datatype * )buf233;
  window_datatype * buf233d_ptr = (window_datatype * )buf233d;
  window_init(window_buf233_buf233d, 1, buf233, LOCK_21_1_6_4096, buf233d, LOCK_21_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_1_bounds = sync_buffer[1];

  while (proc_21_1_bounds)
  {

    // Kernel call : i197:mm_kernel1
    window_acquire(window_buf231_buf231d,LOCK_21_0_0_0,LOCK_21_0_1_0,buf231_ptr,buf231d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf232_buf232d,LOCK_22_1_0_0,LOCK_22_1_1_0,buf232_ptr,buf232d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf230_buf230d,LOCK_21_1_4_4096,LOCK_21_1_5_0,buf230_ptr,buf230d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf233_buf233d,LOCK_21_1_6_4096,LOCK_21_1_7_0,buf233_ptr,buf233d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf231_buf231d),get_input_window_float(window_buf232_buf232d),get_input_window_float(window_buf230_buf230d),get_output_window_float(window_buf233_buf233d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf231_buf231d,LOCK_21_0_0_0,LOCK_21_0_1_0,buf231_ptr,buf231d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf232_buf232d,LOCK_22_1_0_0,LOCK_22_1_1_0,buf232_ptr,buf232d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf230_buf230d,LOCK_21_1_4_4096,LOCK_21_1_5_0,buf230_ptr,buf230d_ptr,0,index, REL_WRITE);
    window_release(window_buf233_buf233d,LOCK_21_1_6_4096,LOCK_21_1_7_0,buf233_ptr,buf233d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_1_bounds > 0)
      --proc_21_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}