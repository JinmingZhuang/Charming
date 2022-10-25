// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/29_2/src/29_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_29_3_0_0 32
#define LOCK_29_3_1_0 33
#define LOCK_29_1_6_0 6
#define LOCK_29_1_7_4096 7
#define LOCK_29_1_4_0 4
#define LOCK_29_1_5_0 5
#define LOCK_29_2_2_4096 50
#define LOCK_29_2_3_4096 51

// Declare shared memory buffers
v4float buf329[256];
v4float buf329d[256];
v4float buf330[256];
v4float buf330d[256];
v4float buf331[256];
v4float buf331d[256];
v4float buf332[256];
v4float buf332d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf330_buf330d[1];
  window_datatype * buf330_ptr = (window_datatype * )buf330;
  window_datatype * buf330d_ptr = (window_datatype * )buf330d;
  window_init(window_buf330_buf330d, 1, buf330, LOCK_29_3_0_0, buf330d, LOCK_29_3_1_0, 256, 256);
  window_internal window_buf331_buf331d[1];
  window_datatype * buf331_ptr = (window_datatype * )buf331;
  window_datatype * buf331d_ptr = (window_datatype * )buf331d;
  window_init(window_buf331_buf331d, 1, buf331, LOCK_29_1_6_0, buf331d, LOCK_29_1_7_4096, 256, 256);
  window_internal window_buf329_buf329d[1];
  window_datatype * buf329_ptr = (window_datatype * )buf329;
  window_datatype * buf329d_ptr = (window_datatype * )buf329d;
  window_init(window_buf329_buf329d, 1, buf329, LOCK_29_1_4_0, buf329d, LOCK_29_1_5_0, 256, 256);
  window_internal window_buf332_buf332d[1];
  window_datatype * buf332_ptr = (window_datatype * )buf332;
  window_datatype * buf332d_ptr = (window_datatype * )buf332d;
  window_init(window_buf332_buf332d, 1, buf332, LOCK_29_2_2_4096, buf332d, LOCK_29_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_29_2_bounds = sync_buffer[1];

  while (proc_29_2_bounds)
  {

    // Kernel call : i246:mm_kernel1
    window_acquire(window_buf330_buf330d,LOCK_29_3_0_0,LOCK_29_3_1_0,buf330_ptr,buf330d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf331_buf331d,LOCK_29_1_6_0,LOCK_29_1_7_4096,buf331_ptr,buf331d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf329_buf329d,LOCK_29_1_4_0,LOCK_29_1_5_0,buf329_ptr,buf329d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf332_buf332d,LOCK_29_2_2_4096,LOCK_29_2_3_4096,buf332_ptr,buf332d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf330_buf330d),get_input_window_float(window_buf331_buf331d),get_input_window_float(window_buf329_buf329d),get_output_window_float(window_buf332_buf332d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf330_buf330d,LOCK_29_3_0_0,LOCK_29_3_1_0,buf330_ptr,buf330d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf331_buf331d,LOCK_29_1_6_0,LOCK_29_1_7_4096,buf331_ptr,buf331d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf329_buf329d,LOCK_29_1_4_0,LOCK_29_1_5_0,buf329_ptr,buf329d_ptr,0,index, REL_WRITE);
    window_release(window_buf332_buf332d,LOCK_29_2_2_4096,LOCK_29_2_3_4096,buf332_ptr,buf332d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_29_2_bounds > 0)
      --proc_29_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}