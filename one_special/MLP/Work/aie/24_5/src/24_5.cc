// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_5/src/24_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_6_0_0 32
#define LOCK_24_6_1_0 33
#define LOCK_24_4_2_4096 2
#define LOCK_24_4_3_4096 3
#define LOCK_24_5_0_0 16
#define LOCK_24_5_1_0 17
#define LOCK_24_5_2_4096 18
#define LOCK_24_5_3_0 19

// Declare shared memory buffers
v4float buf878[256];
v4float buf878d[256];
v4float buf879[256];
v4float buf879d[256];
v4float buf880[256];
v4float buf880d[256];
v4float buf881[256];
v4float buf881d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf879_buf879d[1];
  window_datatype * buf879_ptr = (window_datatype * )buf879;
  window_datatype * buf879d_ptr = (window_datatype * )buf879d;
  window_init(window_buf879_buf879d, 1, buf879, LOCK_24_6_0_0, buf879d, LOCK_24_6_1_0, 256, 256);
  window_internal window_buf880_buf880d[1];
  window_datatype * buf880_ptr = (window_datatype * )buf880;
  window_datatype * buf880d_ptr = (window_datatype * )buf880d;
  window_init(window_buf880_buf880d, 1, buf880, LOCK_24_4_2_4096, buf880d, LOCK_24_4_3_4096, 256, 256);
  window_internal window_buf878_buf878d[1];
  window_datatype * buf878_ptr = (window_datatype * )buf878;
  window_datatype * buf878d_ptr = (window_datatype * )buf878d;
  window_init(window_buf878_buf878d, 1, buf878, LOCK_24_5_0_0, buf878d, LOCK_24_5_1_0, 256, 256);
  window_internal window_buf881_buf881d[1];
  window_datatype * buf881_ptr = (window_datatype * )buf881;
  window_datatype * buf881d_ptr = (window_datatype * )buf881d;
  window_init(window_buf881_buf881d, 1, buf881, LOCK_24_5_2_4096, buf881d, LOCK_24_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_5_bounds = sync_buffer[1];

  while (proc_24_5_bounds)
  {

    // Kernel call : i521:mm_kernel1
    window_acquire(window_buf879_buf879d,LOCK_24_6_0_0,LOCK_24_6_1_0,buf879_ptr,buf879d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf880_buf880d,LOCK_24_4_2_4096,LOCK_24_4_3_4096,buf880_ptr,buf880d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf878_buf878d,LOCK_24_5_0_0,LOCK_24_5_1_0,buf878_ptr,buf878d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf881_buf881d,LOCK_24_5_2_4096,LOCK_24_5_3_0,buf881_ptr,buf881d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf879_buf879d),get_input_window_float(window_buf880_buf880d),get_input_window_float(window_buf878_buf878d),get_output_window_float(window_buf881_buf881d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf879_buf879d,LOCK_24_6_0_0,LOCK_24_6_1_0,buf879_ptr,buf879d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf880_buf880d,LOCK_24_4_2_4096,LOCK_24_4_3_4096,buf880_ptr,buf880d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf878_buf878d,LOCK_24_5_0_0,LOCK_24_5_1_0,buf878_ptr,buf878d_ptr,0,index, REL_WRITE);
    window_release(window_buf881_buf881d,LOCK_24_5_2_4096,LOCK_24_5_3_0,buf881_ptr,buf881d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_5_bounds > 0)
      --proc_24_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}