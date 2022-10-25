// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_3/src/14_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_2_0_4096 0
#define LOCK_14_2_1_4096 1
#define LOCK_14_2_2_0 2
#define LOCK_14_2_3_0 3
#define LOCK_14_3_2_0 18
#define LOCK_14_3_3_0 19
#define LOCK_14_3_4_4096 20
#define LOCK_14_3_5_4096 21

// Declare shared memory buffers
v4float buf152[256];
v4float buf152d[256];
v4float buf153[256];
v4float buf153d[256];
v4float buf154[256];
v4float buf154d[256];
v4float buf155[256];
v4float buf155d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf153_buf153d[1];
  window_datatype * buf153_ptr = (window_datatype * )buf153;
  window_datatype * buf153d_ptr = (window_datatype * )buf153d;
  window_init(window_buf153_buf153d, 1, buf153, LOCK_14_2_0_4096, buf153d, LOCK_14_2_1_4096, 256, 256);
  window_internal window_buf154_buf154d[1];
  window_datatype * buf154_ptr = (window_datatype * )buf154;
  window_datatype * buf154d_ptr = (window_datatype * )buf154d;
  window_init(window_buf154_buf154d, 1, buf154, LOCK_14_2_2_0, buf154d, LOCK_14_2_3_0, 256, 256);
  window_internal window_buf152_buf152d[1];
  window_datatype * buf152_ptr = (window_datatype * )buf152;
  window_datatype * buf152d_ptr = (window_datatype * )buf152d;
  window_init(window_buf152_buf152d, 1, buf152, LOCK_14_3_2_0, buf152d, LOCK_14_3_3_0, 256, 256);
  window_internal window_buf155_buf155d[1];
  window_datatype * buf155_ptr = (window_datatype * )buf155;
  window_datatype * buf155d_ptr = (window_datatype * )buf155d;
  window_init(window_buf155_buf155d, 1, buf155, LOCK_14_3_4_4096, buf155d, LOCK_14_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_3_bounds = sync_buffer[1];

  while (proc_14_3_bounds)
  {

    // Kernel call : i157:mm_kernel1
    window_acquire(window_buf153_buf153d,LOCK_14_2_0_4096,LOCK_14_2_1_4096,buf153_ptr,buf153d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf154_buf154d,LOCK_14_2_2_0,LOCK_14_2_3_0,buf154_ptr,buf154d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf152_buf152d,LOCK_14_3_2_0,LOCK_14_3_3_0,buf152_ptr,buf152d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf155_buf155d,LOCK_14_3_4_4096,LOCK_14_3_5_4096,buf155_ptr,buf155d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf153_buf153d),get_input_window_float(window_buf154_buf154d),get_input_window_float(window_buf152_buf152d),get_output_window_float(window_buf155_buf155d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf153_buf153d,LOCK_14_2_0_4096,LOCK_14_2_1_4096,buf153_ptr,buf153d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf154_buf154d,LOCK_14_2_2_0,LOCK_14_2_3_0,buf154_ptr,buf154d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf152_buf152d,LOCK_14_3_2_0,LOCK_14_3_3_0,buf152_ptr,buf152d_ptr,0,index, REL_WRITE);
    window_release(window_buf155_buf155d,LOCK_14_3_4_4096,LOCK_14_3_5_4096,buf155_ptr,buf155d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_3_bounds > 0)
      --proc_14_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}