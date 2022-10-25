// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_5/src/44_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_6_2_0 34
#define LOCK_44_6_3_0 35
#define LOCK_44_4_2_4096 2
#define LOCK_44_4_3_4096 3
#define LOCK_44_5_0_4096 16
#define LOCK_44_5_1_0 17
#define LOCK_44_5_2_4096 18
#define LOCK_44_5_3_0 19

// Declare shared memory buffers
v4float buf638[256];
v4float buf638d[256];
v4float buf639[256];
v4float buf639d[256];
v4float buf640[256];
v4float buf640d[256];
v4float buf641[256];
v4float buf641d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf639_buf639d[1];
  window_datatype * buf639_ptr = (window_datatype * )buf639;
  window_datatype * buf639d_ptr = (window_datatype * )buf639d;
  window_init(window_buf639_buf639d, 1, buf639, LOCK_44_6_2_0, buf639d, LOCK_44_6_3_0, 256, 256);
  window_internal window_buf640_buf640d[1];
  window_datatype * buf640_ptr = (window_datatype * )buf640;
  window_datatype * buf640d_ptr = (window_datatype * )buf640d;
  window_init(window_buf640_buf640d, 1, buf640, LOCK_44_4_2_4096, buf640d, LOCK_44_4_3_4096, 256, 256);
  window_internal window_buf638_buf638d[1];
  window_datatype * buf638_ptr = (window_datatype * )buf638;
  window_datatype * buf638d_ptr = (window_datatype * )buf638d;
  window_init(window_buf638_buf638d, 1, buf638, LOCK_44_5_0_4096, buf638d, LOCK_44_5_1_0, 256, 256);
  window_internal window_buf641_buf641d[1];
  window_datatype * buf641_ptr = (window_datatype * )buf641;
  window_datatype * buf641d_ptr = (window_datatype * )buf641d;
  window_init(window_buf641_buf641d, 1, buf641, LOCK_44_5_2_4096, buf641d, LOCK_44_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_5_bounds = sync_buffer[1];

  while (proc_44_5_bounds)
  {

    // Kernel call : i401:mm_kernel1
    window_acquire(window_buf639_buf639d,LOCK_44_6_2_0,LOCK_44_6_3_0,buf639_ptr,buf639d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf640_buf640d,LOCK_44_4_2_4096,LOCK_44_4_3_4096,buf640_ptr,buf640d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf638_buf638d,LOCK_44_5_0_4096,LOCK_44_5_1_0,buf638_ptr,buf638d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf641_buf641d,LOCK_44_5_2_4096,LOCK_44_5_3_0,buf641_ptr,buf641d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf639_buf639d),get_input_window_float(window_buf640_buf640d),get_input_window_float(window_buf638_buf638d),get_output_window_float(window_buf641_buf641d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf639_buf639d,LOCK_44_6_2_0,LOCK_44_6_3_0,buf639_ptr,buf639d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf640_buf640d,LOCK_44_4_2_4096,LOCK_44_4_3_4096,buf640_ptr,buf640d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf638_buf638d,LOCK_44_5_0_4096,LOCK_44_5_1_0,buf638_ptr,buf638d_ptr,0,index, REL_WRITE);
    window_release(window_buf641_buf641d,LOCK_44_5_2_4096,LOCK_44_5_3_0,buf641_ptr,buf641d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_5_bounds > 0)
      --proc_44_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}