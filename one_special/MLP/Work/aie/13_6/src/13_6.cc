// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_6/src/13_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_13_7_0_0 32
#define LOCK_13_7_1_0 33
#define LOCK_13_5_4_0 4
#define LOCK_13_5_5_4096 5
#define LOCK_13_5_2_0 2
#define LOCK_13_5_3_0 3
#define LOCK_13_6_2_4096 50
#define LOCK_13_6_3_0 51

// Declare shared memory buffers
v4float buf1013[256];
v4float buf1013d[256];
v4float buf1014[256];
v4float buf1014d[256];
v4float buf1015[256];
v4float buf1015d[256];
v4float buf1016[256];
v4float buf1016d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1014_buf1014d[1];
  window_datatype * buf1014_ptr = (window_datatype * )buf1014;
  window_datatype * buf1014d_ptr = (window_datatype * )buf1014d;
  window_init(window_buf1014_buf1014d, 1, buf1014, LOCK_13_7_0_0, buf1014d, LOCK_13_7_1_0, 256, 256);
  window_internal window_buf1015_buf1015d[1];
  window_datatype * buf1015_ptr = (window_datatype * )buf1015;
  window_datatype * buf1015d_ptr = (window_datatype * )buf1015d;
  window_init(window_buf1015_buf1015d, 1, buf1015, LOCK_13_5_4_0, buf1015d, LOCK_13_5_5_4096, 256, 256);
  window_internal window_buf1013_buf1013d[1];
  window_datatype * buf1013_ptr = (window_datatype * )buf1013;
  window_datatype * buf1013d_ptr = (window_datatype * )buf1013d;
  window_init(window_buf1013_buf1013d, 1, buf1013, LOCK_13_5_2_0, buf1013d, LOCK_13_5_3_0, 256, 256);
  window_internal window_buf1016_buf1016d[1];
  window_datatype * buf1016_ptr = (window_datatype * )buf1016;
  window_datatype * buf1016d_ptr = (window_datatype * )buf1016d;
  window_init(window_buf1016_buf1016d, 1, buf1016, LOCK_13_6_2_4096, buf1016d, LOCK_13_6_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_6_bounds = sync_buffer[1];

  while (proc_13_6_bounds)
  {

    // Kernel call : i588:mm_kernel1
    window_acquire(window_buf1014_buf1014d,LOCK_13_7_0_0,LOCK_13_7_1_0,buf1014_ptr,buf1014d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1015_buf1015d,LOCK_13_5_4_0,LOCK_13_5_5_4096,buf1015_ptr,buf1015d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1013_buf1013d,LOCK_13_5_2_0,LOCK_13_5_3_0,buf1013_ptr,buf1013d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1016_buf1016d,LOCK_13_6_2_4096,LOCK_13_6_3_0,buf1016_ptr,buf1016d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1014_buf1014d),get_input_window_float(window_buf1015_buf1015d),get_input_window_float(window_buf1013_buf1013d),get_output_window_float(window_buf1016_buf1016d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1014_buf1014d,LOCK_13_7_0_0,LOCK_13_7_1_0,buf1014_ptr,buf1014d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1015_buf1015d,LOCK_13_5_4_0,LOCK_13_5_5_4096,buf1015_ptr,buf1015d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1013_buf1013d,LOCK_13_5_2_0,LOCK_13_5_3_0,buf1013_ptr,buf1013d_ptr,0,index, REL_WRITE);
    window_release(window_buf1016_buf1016d,LOCK_13_6_2_4096,LOCK_13_6_3_0,buf1016_ptr,buf1016d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_6_bounds > 0)
      --proc_13_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}