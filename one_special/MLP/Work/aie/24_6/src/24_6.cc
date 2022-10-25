// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_6/src/24_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_5_4_0 4
#define LOCK_24_5_5_4096 5
#define LOCK_24_5_6_4096 6
#define LOCK_24_5_7_4096 7
#define LOCK_24_5_2_4096 2
#define LOCK_24_5_3_0 3
#define LOCK_24_7_0_0 32
#define LOCK_24_7_1_0 33

// Declare shared memory buffers
v4float buf881[256];
v4float buf881d[256];
v4float buf882[256];
v4float buf882d[256];
v4float buf883[256];
v4float buf883d[256];
v4float buf884[256];
v4float buf884d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf882_buf882d[1];
  window_datatype * buf882_ptr = (window_datatype * )buf882;
  window_datatype * buf882d_ptr = (window_datatype * )buf882d;
  window_init(window_buf882_buf882d, 1, buf882, LOCK_24_5_4_0, buf882d, LOCK_24_5_5_4096, 256, 256);
  window_internal window_buf883_buf883d[1];
  window_datatype * buf883_ptr = (window_datatype * )buf883;
  window_datatype * buf883d_ptr = (window_datatype * )buf883d;
  window_init(window_buf883_buf883d, 1, buf883, LOCK_24_5_6_4096, buf883d, LOCK_24_5_7_4096, 256, 256);
  window_internal window_buf881_buf881d[1];
  window_datatype * buf881_ptr = (window_datatype * )buf881;
  window_datatype * buf881d_ptr = (window_datatype * )buf881d;
  window_init(window_buf881_buf881d, 1, buf881, LOCK_24_5_2_4096, buf881d, LOCK_24_5_3_0, 256, 256);
  window_internal window_buf884_buf884d[1];
  window_datatype * buf884_ptr = (window_datatype * )buf884;
  window_datatype * buf884d_ptr = (window_datatype * )buf884d;
  window_init(window_buf884_buf884d, 1, buf884, LOCK_24_7_0_0, buf884d, LOCK_24_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_6_bounds = sync_buffer[1];

  while (proc_24_6_bounds)
  {

    // Kernel call : i522:mm_kernel1
    window_acquire(window_buf882_buf882d,LOCK_24_5_4_0,LOCK_24_5_5_4096,buf882_ptr,buf882d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf883_buf883d,LOCK_24_5_6_4096,LOCK_24_5_7_4096,buf883_ptr,buf883d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf881_buf881d,LOCK_24_5_2_4096,LOCK_24_5_3_0,buf881_ptr,buf881d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf884_buf884d,LOCK_24_7_0_0,LOCK_24_7_1_0,buf884_ptr,buf884d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf882_buf882d),get_input_window_float(window_buf883_buf883d),get_input_window_float(window_buf881_buf881d),get_output_window_float(window_buf884_buf884d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf882_buf882d,LOCK_24_5_4_0,LOCK_24_5_5_4096,buf882_ptr,buf882d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf883_buf883d,LOCK_24_5_6_4096,LOCK_24_5_7_4096,buf883_ptr,buf883d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf881_buf881d,LOCK_24_5_2_4096,LOCK_24_5_3_0,buf881_ptr,buf881d_ptr,0,index, REL_WRITE);
    window_release(window_buf884_buf884d,LOCK_24_7_0_0,LOCK_24_7_1_0,buf884_ptr,buf884d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_6_bounds > 0)
      --proc_24_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}