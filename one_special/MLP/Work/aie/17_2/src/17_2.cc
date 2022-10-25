// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_2/src/17_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_3_2_4096 34
#define LOCK_17_3_3_4096 35
#define LOCK_17_2_0_4096 48
#define LOCK_17_2_1_0 49
#define LOCK_17_1_6_4096 6
#define LOCK_17_1_7_4096 7
#define LOCK_17_2_2_0 50
#define LOCK_17_2_3_4096 51

// Declare shared memory buffers
v4float buf185[256];
v4float buf185d[256];
v4float buf186[256];
v4float buf186d[256];
v4float buf187[256];
v4float buf187d[256];
v4float buf188[256];
v4float buf188d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf186_buf186d[1];
  window_datatype * buf186_ptr = (window_datatype * )buf186;
  window_datatype * buf186d_ptr = (window_datatype * )buf186d;
  window_init(window_buf186_buf186d, 1, buf186, LOCK_17_3_2_4096, buf186d, LOCK_17_3_3_4096, 256, 256);
  window_internal window_buf187_buf187d[1];
  window_datatype * buf187_ptr = (window_datatype * )buf187;
  window_datatype * buf187d_ptr = (window_datatype * )buf187d;
  window_init(window_buf187_buf187d, 1, buf187, LOCK_17_2_0_4096, buf187d, LOCK_17_2_1_0, 256, 256);
  window_internal window_buf185_buf185d[1];
  window_datatype * buf185_ptr = (window_datatype * )buf185;
  window_datatype * buf185d_ptr = (window_datatype * )buf185d;
  window_init(window_buf185_buf185d, 1, buf185, LOCK_17_1_6_4096, buf185d, LOCK_17_1_7_4096, 256, 256);
  window_internal window_buf188_buf188d[1];
  window_datatype * buf188_ptr = (window_datatype * )buf188;
  window_datatype * buf188d_ptr = (window_datatype * )buf188d;
  window_init(window_buf188_buf188d, 1, buf188, LOCK_17_2_2_0, buf188d, LOCK_17_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_2_bounds = sync_buffer[1];

  while (proc_17_2_bounds)
  {

    // Kernel call : i174:mm_kernel1
    window_acquire(window_buf186_buf186d,LOCK_17_3_2_4096,LOCK_17_3_3_4096,buf186_ptr,buf186d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf187_buf187d,LOCK_17_2_0_4096,LOCK_17_2_1_0,buf187_ptr,buf187d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf185_buf185d,LOCK_17_1_6_4096,LOCK_17_1_7_4096,buf185_ptr,buf185d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf188_buf188d,LOCK_17_2_2_0,LOCK_17_2_3_4096,buf188_ptr,buf188d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf186_buf186d),get_input_window_float(window_buf187_buf187d),get_input_window_float(window_buf185_buf185d),get_output_window_float(window_buf188_buf188d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf186_buf186d,LOCK_17_3_2_4096,LOCK_17_3_3_4096,buf186_ptr,buf186d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf187_buf187d,LOCK_17_2_0_4096,LOCK_17_2_1_0,buf187_ptr,buf187d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf185_buf185d,LOCK_17_1_6_4096,LOCK_17_1_7_4096,buf185_ptr,buf185d_ptr,0,index, REL_WRITE);
    window_release(window_buf188_buf188d,LOCK_17_2_2_0,LOCK_17_2_3_4096,buf188_ptr,buf188d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_2_bounds > 0)
      --proc_17_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}