// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_0/src/9_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_0_0_4096 48
#define LOCK_9_0_1_4096 49
#define LOCK_9_0_2_0 50
#define LOCK_9_0_3_0 51
#define LOCK_9_1_0_0 32
#define LOCK_9_1_1_4096 33

// Declare shared memory buffers
v4float buf84[256];
v4float buf84d[256];
v4float buf85[256];
v4float buf85d[256];
v4float buf86[256];
v4float buf86d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf84_buf84d[1];
  window_datatype * buf84_ptr = (window_datatype * )buf84;
  window_datatype * buf84d_ptr = (window_datatype * )buf84d;
  window_init(window_buf84_buf84d, 1, buf84, LOCK_9_0_0_4096, buf84d, LOCK_9_0_1_4096, 256, 256);
  window_internal window_buf85_buf85d[1];
  window_datatype * buf85_ptr = (window_datatype * )buf85;
  window_datatype * buf85d_ptr = (window_datatype * )buf85d;
  window_init(window_buf85_buf85d, 1, buf85, LOCK_9_0_2_0, buf85d, LOCK_9_0_3_0, 256, 256);
  window_internal window_buf86_buf86d[1];
  window_datatype * buf86_ptr = (window_datatype * )buf86;
  window_datatype * buf86d_ptr = (window_datatype * )buf86d;
  window_init(window_buf86_buf86d, 1, buf86, LOCK_9_1_0_0, buf86d, LOCK_9_1_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_0_bounds = sync_buffer[1];

  while (proc_9_0_bounds)
  {

    // Kernel call : i124:mm_kernel0
    window_acquire(window_buf84_buf84d,LOCK_9_0_0_4096,LOCK_9_0_1_4096,buf84_ptr,buf84d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf85_buf85d,LOCK_9_0_2_0,LOCK_9_0_3_0,buf85_ptr,buf85d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf86_buf86d,LOCK_9_1_0_0,LOCK_9_1_1_4096,buf86_ptr,buf86d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf84_buf84d),get_input_window_float(window_buf85_buf85d),get_output_window_float(window_buf86_buf86d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf84_buf84d,LOCK_9_0_0_4096,LOCK_9_0_1_4096,buf84_ptr,buf84d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf85_buf85d,LOCK_9_0_2_0,LOCK_9_0_3_0,buf85_ptr,buf85d_ptr,0,index, REL_WRITE);
    window_release(window_buf86_buf86d,LOCK_9_1_0_0,LOCK_9_1_1_4096,buf86_ptr,buf86d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_0_bounds > 0)
      --proc_9_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}