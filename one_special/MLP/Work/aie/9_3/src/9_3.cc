// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_3/src/9_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_3_2_4096 18
#define LOCK_9_3_3_0 19
#define LOCK_9_4_0_0 32
#define LOCK_9_4_1_0 33
#define LOCK_9_3_0_0 16
#define LOCK_9_3_1_4096 17
#define LOCK_9_3_4_0 20
#define LOCK_9_3_5_4096 21

// Declare shared memory buffers
v4float buf92[256];
v4float buf92d[256];
v4float buf93[256];
v4float buf93d[256];
v4float buf94[256];
v4float buf94d[256];
v4float buf95[256];
v4float buf95d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf93_buf93d[1];
  window_datatype * buf93_ptr = (window_datatype * )buf93;
  window_datatype * buf93d_ptr = (window_datatype * )buf93d;
  window_init(window_buf93_buf93d, 1, buf93, LOCK_9_3_2_4096, buf93d, LOCK_9_3_3_0, 256, 256);
  window_internal window_buf94_buf94d[1];
  window_datatype * buf94_ptr = (window_datatype * )buf94;
  window_datatype * buf94d_ptr = (window_datatype * )buf94d;
  window_init(window_buf94_buf94d, 1, buf94, LOCK_9_4_0_0, buf94d, LOCK_9_4_1_0, 256, 256);
  window_internal window_buf92_buf92d[1];
  window_datatype * buf92_ptr = (window_datatype * )buf92;
  window_datatype * buf92d_ptr = (window_datatype * )buf92d;
  window_init(window_buf92_buf92d, 1, buf92, LOCK_9_3_0_0, buf92d, LOCK_9_3_1_4096, 256, 256);
  window_internal window_buf95_buf95d[1];
  window_datatype * buf95_ptr = (window_datatype * )buf95;
  window_datatype * buf95d_ptr = (window_datatype * )buf95d;
  window_init(window_buf95_buf95d, 1, buf95, LOCK_9_3_4_0, buf95d, LOCK_9_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_3_bounds = sync_buffer[1];

  while (proc_9_3_bounds)
  {

    // Kernel call : i127:mm_kernel1
    window_acquire(window_buf93_buf93d,LOCK_9_3_2_4096,LOCK_9_3_3_0,buf93_ptr,buf93d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf94_buf94d,LOCK_9_4_0_0,LOCK_9_4_1_0,buf94_ptr,buf94d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf92_buf92d,LOCK_9_3_0_0,LOCK_9_3_1_4096,buf92_ptr,buf92d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf95_buf95d,LOCK_9_3_4_0,LOCK_9_3_5_4096,buf95_ptr,buf95d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf93_buf93d),get_input_window_float(window_buf94_buf94d),get_input_window_float(window_buf92_buf92d),get_output_window_float(window_buf95_buf95d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf93_buf93d,LOCK_9_3_2_4096,LOCK_9_3_3_0,buf93_ptr,buf93d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf94_buf94d,LOCK_9_4_0_0,LOCK_9_4_1_0,buf94_ptr,buf94d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf92_buf92d,LOCK_9_3_0_0,LOCK_9_3_1_4096,buf92_ptr,buf92d_ptr,0,index, REL_WRITE);
    window_release(window_buf95_buf95d,LOCK_9_3_4_0,LOCK_9_3_5_4096,buf95_ptr,buf95d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_3_bounds > 0)
      --proc_9_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}