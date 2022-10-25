// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_7/src/13_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_13_6_4_0 4
#define LOCK_13_6_5_0 5
#define LOCK_13_7_2_4096 18
#define LOCK_13_7_3_4096 19
#define LOCK_13_6_2_4096 2
#define LOCK_13_6_3_0 3
#define LOCK_13_6_6_4096 6
#define LOCK_13_6_7_4096 7

// Declare shared memory buffers
v4float buf1016[256];
v4float buf1016d[256];
v4float buf1017[256];
v4float buf1017d[256];
v4float buf1018[256];
v4float buf1018d[256];
v4float buf1019[256];
v4float buf1019d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1017_buf1017d[1];
  window_datatype * buf1017_ptr = (window_datatype * )buf1017;
  window_datatype * buf1017d_ptr = (window_datatype * )buf1017d;
  window_init(window_buf1017_buf1017d, 1, buf1017, LOCK_13_6_4_0, buf1017d, LOCK_13_6_5_0, 256, 256);
  window_internal window_buf1018_buf1018d[1];
  window_datatype * buf1018_ptr = (window_datatype * )buf1018;
  window_datatype * buf1018d_ptr = (window_datatype * )buf1018d;
  window_init(window_buf1018_buf1018d, 1, buf1018, LOCK_13_7_2_4096, buf1018d, LOCK_13_7_3_4096, 256, 256);
  window_internal window_buf1016_buf1016d[1];
  window_datatype * buf1016_ptr = (window_datatype * )buf1016;
  window_datatype * buf1016d_ptr = (window_datatype * )buf1016d;
  window_init(window_buf1016_buf1016d, 1, buf1016, LOCK_13_6_2_4096, buf1016d, LOCK_13_6_3_0, 256, 256);
  window_internal window_buf1019_buf1019d[1];
  window_datatype * buf1019_ptr = (window_datatype * )buf1019;
  window_datatype * buf1019d_ptr = (window_datatype * )buf1019d;
  window_init(window_buf1019_buf1019d, 1, buf1019, LOCK_13_6_6_4096, buf1019d, LOCK_13_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_7_bounds = sync_buffer[1];

  while (proc_13_7_bounds)
  {

    // Kernel call : i589:mm_kernel1
    window_acquire(window_buf1017_buf1017d,LOCK_13_6_4_0,LOCK_13_6_5_0,buf1017_ptr,buf1017d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1018_buf1018d,LOCK_13_7_2_4096,LOCK_13_7_3_4096,buf1018_ptr,buf1018d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1016_buf1016d,LOCK_13_6_2_4096,LOCK_13_6_3_0,buf1016_ptr,buf1016d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1019_buf1019d,LOCK_13_6_6_4096,LOCK_13_6_7_4096,buf1019_ptr,buf1019d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1017_buf1017d),get_input_window_float(window_buf1018_buf1018d),get_input_window_float(window_buf1016_buf1016d),get_output_window_float(window_buf1019_buf1019d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1017_buf1017d,LOCK_13_6_4_0,LOCK_13_6_5_0,buf1017_ptr,buf1017d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1018_buf1018d,LOCK_13_7_2_4096,LOCK_13_7_3_4096,buf1018_ptr,buf1018d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1016_buf1016d,LOCK_13_6_2_4096,LOCK_13_6_3_0,buf1016_ptr,buf1016d_ptr,0,index, REL_WRITE);
    window_release(window_buf1019_buf1019d,LOCK_13_6_6_4096,LOCK_13_6_7_4096,buf1019_ptr,buf1019d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_7_bounds > 0)
      --proc_13_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}