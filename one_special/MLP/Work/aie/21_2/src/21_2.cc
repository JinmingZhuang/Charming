// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_2/src/21_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_2_0_0 48
#define LOCK_21_2_1_0 49
#define LOCK_21_3_0_0 32
#define LOCK_21_3_1_0 33
#define LOCK_21_1_6_4096 6
#define LOCK_21_1_7_0 7
#define LOCK_21_3_2_0 34
#define LOCK_21_3_3_4096 35

// Declare shared memory buffers
v4float buf233[256];
v4float buf233d[256];
v4float buf234[256];
v4float buf234d[256];
v4float buf235[256];
v4float buf235d[256];
v4float buf236[256];
v4float buf236d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf234_buf234d[1];
  window_datatype * buf234_ptr = (window_datatype * )buf234;
  window_datatype * buf234d_ptr = (window_datatype * )buf234d;
  window_init(window_buf234_buf234d, 1, buf234, LOCK_21_2_0_0, buf234d, LOCK_21_2_1_0, 256, 256);
  window_internal window_buf235_buf235d[1];
  window_datatype * buf235_ptr = (window_datatype * )buf235;
  window_datatype * buf235d_ptr = (window_datatype * )buf235d;
  window_init(window_buf235_buf235d, 1, buf235, LOCK_21_3_0_0, buf235d, LOCK_21_3_1_0, 256, 256);
  window_internal window_buf233_buf233d[1];
  window_datatype * buf233_ptr = (window_datatype * )buf233;
  window_datatype * buf233d_ptr = (window_datatype * )buf233d;
  window_init(window_buf233_buf233d, 1, buf233, LOCK_21_1_6_4096, buf233d, LOCK_21_1_7_0, 256, 256);
  window_internal window_buf236_buf236d[1];
  window_datatype * buf236_ptr = (window_datatype * )buf236;
  window_datatype * buf236d_ptr = (window_datatype * )buf236d;
  window_init(window_buf236_buf236d, 1, buf236, LOCK_21_3_2_0, buf236d, LOCK_21_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_2_bounds = sync_buffer[1];

  while (proc_21_2_bounds)
  {

    // Kernel call : i198:mm_kernel1
    window_acquire(window_buf234_buf234d,LOCK_21_2_0_0,LOCK_21_2_1_0,buf234_ptr,buf234d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf235_buf235d,LOCK_21_3_0_0,LOCK_21_3_1_0,buf235_ptr,buf235d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf233_buf233d,LOCK_21_1_6_4096,LOCK_21_1_7_0,buf233_ptr,buf233d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf236_buf236d,LOCK_21_3_2_0,LOCK_21_3_3_4096,buf236_ptr,buf236d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf234_buf234d),get_input_window_float(window_buf235_buf235d),get_input_window_float(window_buf233_buf233d),get_output_window_float(window_buf236_buf236d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf234_buf234d,LOCK_21_2_0_0,LOCK_21_2_1_0,buf234_ptr,buf234d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf235_buf235d,LOCK_21_3_0_0,LOCK_21_3_1_0,buf235_ptr,buf235d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf233_buf233d,LOCK_21_1_6_4096,LOCK_21_1_7_0,buf233_ptr,buf233d_ptr,0,index, REL_WRITE);
    window_release(window_buf236_buf236d,LOCK_21_3_2_0,LOCK_21_3_3_4096,buf236_ptr,buf236d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_2_bounds > 0)
      --proc_21_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}