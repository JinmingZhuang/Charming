// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_2/src/3_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_3_0_4096 32
#define LOCK_3_3_1_0 33
#define LOCK_3_1_6_0 6
#define LOCK_3_1_7_4096 7
#define LOCK_3_1_4_4096 4
#define LOCK_3_1_5_0 5
#define LOCK_3_3_2_4096 34
#define LOCK_3_3_3_4096 35

// Declare shared memory buffers
v4float buf17[256];
v4float buf17d[256];
v4float buf18[256];
v4float buf18d[256];
v4float buf19[256];
v4float buf19d[256];
v4float buf20[256];
v4float buf20d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf18_buf18d[1];
  window_datatype * buf18_ptr = (window_datatype * )buf18;
  window_datatype * buf18d_ptr = (window_datatype * )buf18d;
  window_init(window_buf18_buf18d, 1, buf18, LOCK_3_3_0_4096, buf18d, LOCK_3_3_1_0, 256, 256);
  window_internal window_buf19_buf19d[1];
  window_datatype * buf19_ptr = (window_datatype * )buf19;
  window_datatype * buf19d_ptr = (window_datatype * )buf19d;
  window_init(window_buf19_buf19d, 1, buf19, LOCK_3_1_6_0, buf19d, LOCK_3_1_7_4096, 256, 256);
  window_internal window_buf17_buf17d[1];
  window_datatype * buf17_ptr = (window_datatype * )buf17;
  window_datatype * buf17d_ptr = (window_datatype * )buf17d;
  window_init(window_buf17_buf17d, 1, buf17, LOCK_3_1_4_4096, buf17d, LOCK_3_1_5_0, 256, 256);
  window_internal window_buf20_buf20d[1];
  window_datatype * buf20_ptr = (window_datatype * )buf20;
  window_datatype * buf20d_ptr = (window_datatype * )buf20d;
  window_init(window_buf20_buf20d, 1, buf20, LOCK_3_3_2_4096, buf20d, LOCK_3_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_2_bounds = sync_buffer[1];

  while (proc_3_2_bounds)
  {

    // Kernel call : i90:mm_kernel1
    window_acquire(window_buf18_buf18d,LOCK_3_3_0_4096,LOCK_3_3_1_0,buf18_ptr,buf18d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf19_buf19d,LOCK_3_1_6_0,LOCK_3_1_7_4096,buf19_ptr,buf19d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf17_buf17d,LOCK_3_1_4_4096,LOCK_3_1_5_0,buf17_ptr,buf17d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf20_buf20d,LOCK_3_3_2_4096,LOCK_3_3_3_4096,buf20_ptr,buf20d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf18_buf18d),get_input_window_float(window_buf19_buf19d),get_input_window_float(window_buf17_buf17d),get_output_window_float(window_buf20_buf20d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf18_buf18d,LOCK_3_3_0_4096,LOCK_3_3_1_0,buf18_ptr,buf18d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf19_buf19d,LOCK_3_1_6_0,LOCK_3_1_7_4096,buf19_ptr,buf19d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf17_buf17d,LOCK_3_1_4_4096,LOCK_3_1_5_0,buf17_ptr,buf17d_ptr,0,index, REL_WRITE);
    window_release(window_buf20_buf20d,LOCK_3_3_2_4096,LOCK_3_3_3_4096,buf20_ptr,buf20d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_2_bounds > 0)
      --proc_3_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}