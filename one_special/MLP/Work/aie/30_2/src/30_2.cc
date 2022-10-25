// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_2/src/30_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_2_6_4096 22
#define LOCK_29_2_7_4096 23
#define LOCK_30_3_2_4096 34
#define LOCK_30_3_3_4096 35
#define LOCK_30_1_6_4096 6
#define LOCK_30_1_7_4096 7
#define LOCK_30_2_0_0 48
#define LOCK_30_2_1_0 49

// Declare shared memory buffers
v4float buf341[256];
v4float buf341d[256];
v4float buf342[256];
v4float buf342d[256];
v4float buf343[256];
v4float buf343d[256];
v4float buf344[256];
v4float buf344d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf342_buf342d[1];
  window_datatype * buf342_ptr = (window_datatype * )buf342;
  window_datatype * buf342d_ptr = (window_datatype * )buf342d;
  window_init(window_buf342_buf342d, 1, buf342, LOCK_29_2_6_4096, buf342d, LOCK_29_2_7_4096, 256, 256);
  window_internal window_buf343_buf343d[1];
  window_datatype * buf343_ptr = (window_datatype * )buf343;
  window_datatype * buf343d_ptr = (window_datatype * )buf343d;
  window_init(window_buf343_buf343d, 1, buf343, LOCK_30_3_2_4096, buf343d, LOCK_30_3_3_4096, 256, 256);
  window_internal window_buf341_buf341d[1];
  window_datatype * buf341_ptr = (window_datatype * )buf341;
  window_datatype * buf341d_ptr = (window_datatype * )buf341d;
  window_init(window_buf341_buf341d, 1, buf341, LOCK_30_1_6_4096, buf341d, LOCK_30_1_7_4096, 256, 256);
  window_internal window_buf344_buf344d[1];
  window_datatype * buf344_ptr = (window_datatype * )buf344;
  window_datatype * buf344d_ptr = (window_datatype * )buf344d;
  window_init(window_buf344_buf344d, 1, buf344, LOCK_30_2_0_0, buf344d, LOCK_30_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_2_bounds = sync_buffer[1];

  while (proc_30_2_bounds)
  {

    // Kernel call : i252:mm_kernel1
    window_acquire(window_buf342_buf342d,LOCK_29_2_6_4096,LOCK_29_2_7_4096,buf342_ptr,buf342d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf343_buf343d,LOCK_30_3_2_4096,LOCK_30_3_3_4096,buf343_ptr,buf343d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf341_buf341d,LOCK_30_1_6_4096,LOCK_30_1_7_4096,buf341_ptr,buf341d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf344_buf344d,LOCK_30_2_0_0,LOCK_30_2_1_0,buf344_ptr,buf344d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf342_buf342d),get_input_window_float(window_buf343_buf343d),get_input_window_float(window_buf341_buf341d),get_output_window_float(window_buf344_buf344d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf342_buf342d,LOCK_29_2_6_4096,LOCK_29_2_7_4096,buf342_ptr,buf342d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf343_buf343d,LOCK_30_3_2_4096,LOCK_30_3_3_4096,buf343_ptr,buf343d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf341_buf341d,LOCK_30_1_6_4096,LOCK_30_1_7_4096,buf341_ptr,buf341d_ptr,0,index, REL_WRITE);
    window_release(window_buf344_buf344d,LOCK_30_2_0_0,LOCK_30_2_1_0,buf344_ptr,buf344d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_2_bounds > 0)
      --proc_30_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}