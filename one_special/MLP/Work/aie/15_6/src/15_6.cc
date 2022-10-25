// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_6/src/15_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_6_2_4096 50
#define LOCK_15_6_3_4096 51
#define LOCK_15_5_6_0 6
#define LOCK_15_5_7_0 7
#define LOCK_15_5_4_4096 4
#define LOCK_15_5_5_0 5
#define LOCK_15_7_0_0 32
#define LOCK_15_7_1_0 33

// Declare shared memory buffers
v4float buf989[256];
v4float buf989d[256];
v4float buf990[256];
v4float buf990d[256];
v4float buf991[256];
v4float buf991d[256];
v4float buf992[256];
v4float buf992d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf990_buf990d[1];
  window_datatype * buf990_ptr = (window_datatype * )buf990;
  window_datatype * buf990d_ptr = (window_datatype * )buf990d;
  window_init(window_buf990_buf990d, 1, buf990, LOCK_15_6_2_4096, buf990d, LOCK_15_6_3_4096, 256, 256);
  window_internal window_buf991_buf991d[1];
  window_datatype * buf991_ptr = (window_datatype * )buf991;
  window_datatype * buf991d_ptr = (window_datatype * )buf991d;
  window_init(window_buf991_buf991d, 1, buf991, LOCK_15_5_6_0, buf991d, LOCK_15_5_7_0, 256, 256);
  window_internal window_buf989_buf989d[1];
  window_datatype * buf989_ptr = (window_datatype * )buf989;
  window_datatype * buf989d_ptr = (window_datatype * )buf989d;
  window_init(window_buf989_buf989d, 1, buf989, LOCK_15_5_4_4096, buf989d, LOCK_15_5_5_0, 256, 256);
  window_internal window_buf992_buf992d[1];
  window_datatype * buf992_ptr = (window_datatype * )buf992;
  window_datatype * buf992d_ptr = (window_datatype * )buf992d;
  window_init(window_buf992_buf992d, 1, buf992, LOCK_15_7_0_0, buf992d, LOCK_15_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_6_bounds = sync_buffer[1];

  while (proc_15_6_bounds)
  {

    // Kernel call : i576:mm_kernel1
    window_acquire(window_buf990_buf990d,LOCK_15_6_2_4096,LOCK_15_6_3_4096,buf990_ptr,buf990d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf991_buf991d,LOCK_15_5_6_0,LOCK_15_5_7_0,buf991_ptr,buf991d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf989_buf989d,LOCK_15_5_4_4096,LOCK_15_5_5_0,buf989_ptr,buf989d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf992_buf992d,LOCK_15_7_0_0,LOCK_15_7_1_0,buf992_ptr,buf992d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf990_buf990d),get_input_window_float(window_buf991_buf991d),get_input_window_float(window_buf989_buf989d),get_output_window_float(window_buf992_buf992d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf990_buf990d,LOCK_15_6_2_4096,LOCK_15_6_3_4096,buf990_ptr,buf990d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf991_buf991d,LOCK_15_5_6_0,LOCK_15_5_7_0,buf991_ptr,buf991d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf989_buf989d,LOCK_15_5_4_4096,LOCK_15_5_5_0,buf989_ptr,buf989d_ptr,0,index, REL_WRITE);
    window_release(window_buf992_buf992d,LOCK_15_7_0_0,LOCK_15_7_1_0,buf992_ptr,buf992d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_6_bounds > 0)
      --proc_15_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}