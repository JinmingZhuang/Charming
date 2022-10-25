// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_1/src/2_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_2_0_0_0 0
#define LOCK_2_0_1_0 1
#define LOCK_2_1_2_0 18
#define LOCK_2_1_3_0 19
#define LOCK_2_1_0_0 16
#define LOCK_2_1_1_1376 17
#define LOCK_2_2_0_0 32
#define LOCK_2_2_1_0 33

// Declare shared memory buffers
v4float buf2[256];
v4float buf2d[256];
v4float buf3[256];
v4float buf3d[256];
v4float buf4[256];
v4float buf4d[256];
v4float buf5[256];
v4float buf5d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf3_buf3d[1];
  window_datatype * buf3_ptr = (window_datatype * )buf3;
  window_datatype * buf3d_ptr = (window_datatype * )buf3d;
  window_init(window_buf3_buf3d, 1, buf3, LOCK_2_0_0_0, buf3d, LOCK_2_0_1_0, 256, 256);
  window_internal window_buf4_buf4d[1];
  window_datatype * buf4_ptr = (window_datatype * )buf4;
  window_datatype * buf4d_ptr = (window_datatype * )buf4d;
  window_init(window_buf4_buf4d, 1, buf4, LOCK_2_1_2_0, buf4d, LOCK_2_1_3_0, 256, 256);
  window_internal window_buf2_buf2d[1];
  window_datatype * buf2_ptr = (window_datatype * )buf2;
  window_datatype * buf2d_ptr = (window_datatype * )buf2d;
  window_init(window_buf2_buf2d, 1, buf2, LOCK_2_1_0_0, buf2d, LOCK_2_1_1_1376, 256, 256);
  window_internal window_buf5_buf5d[1];
  window_datatype * buf5_ptr = (window_datatype * )buf5;
  window_datatype * buf5d_ptr = (window_datatype * )buf5d;
  window_init(window_buf5_buf5d, 1, buf5, LOCK_2_2_0_0, buf5d, LOCK_2_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_1_bounds = sync_buffer[1];

  while (proc_2_1_bounds)
  {

    // Kernel call : i83:mm_kernel1
    window_acquire(window_buf3_buf3d,LOCK_2_0_0_0,LOCK_2_0_1_0,buf3_ptr,buf3d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf4_buf4d,LOCK_2_1_2_0,LOCK_2_1_3_0,buf4_ptr,buf4d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf2_buf2d,LOCK_2_1_0_0,LOCK_2_1_1_1376,buf2_ptr,buf2d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf5_buf5d,LOCK_2_2_0_0,LOCK_2_2_1_0,buf5_ptr,buf5d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf3_buf3d),get_input_window_float(window_buf4_buf4d),get_input_window_float(window_buf2_buf2d),get_output_window_float(window_buf5_buf5d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf3_buf3d,LOCK_2_0_0_0,LOCK_2_0_1_0,buf3_ptr,buf3d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf4_buf4d,LOCK_2_1_2_0,LOCK_2_1_3_0,buf4_ptr,buf4d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf2_buf2d,LOCK_2_1_0_0,LOCK_2_1_1_1376,buf2_ptr,buf2d_ptr,0,index, REL_WRITE);
    window_release(window_buf5_buf5d,LOCK_2_2_0_0,LOCK_2_2_1_0,buf5_ptr,buf5d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_1_bounds > 0)
      --proc_2_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}