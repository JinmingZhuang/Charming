// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_0/src/19_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_0_2_4096 18
#define LOCK_18_0_3_4096 19
#define LOCK_19_1_0_4096 32
#define LOCK_19_1_1_4096 33
#define LOCK_19_1_2_0 34
#define LOCK_19_1_3_0 35

// Declare shared memory buffers
v4float buf204[256];
v4float buf204d[256];
v4float buf205[256];
v4float buf205d[256];
v4float buf206[256];
v4float buf206d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf204_buf204d[1];
  window_datatype * buf204_ptr = (window_datatype * )buf204;
  window_datatype * buf204d_ptr = (window_datatype * )buf204d;
  window_init(window_buf204_buf204d, 1, buf204, LOCK_18_0_2_4096, buf204d, LOCK_18_0_3_4096, 256, 256);
  window_internal window_buf205_buf205d[1];
  window_datatype * buf205_ptr = (window_datatype * )buf205;
  window_datatype * buf205d_ptr = (window_datatype * )buf205d;
  window_init(window_buf205_buf205d, 1, buf205, LOCK_19_1_0_4096, buf205d, LOCK_19_1_1_4096, 256, 256);
  window_internal window_buf206_buf206d[1];
  window_datatype * buf206_ptr = (window_datatype * )buf206;
  window_datatype * buf206d_ptr = (window_datatype * )buf206d;
  window_init(window_buf206_buf206d, 1, buf206, LOCK_19_1_2_0, buf206d, LOCK_19_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_0_bounds = sync_buffer[1];

  while (proc_19_0_bounds)
  {

    // Kernel call : i184:mm_kernel0
    window_acquire(window_buf204_buf204d,LOCK_18_0_2_4096,LOCK_18_0_3_4096,buf204_ptr,buf204d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf205_buf205d,LOCK_19_1_0_4096,LOCK_19_1_1_4096,buf205_ptr,buf205d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf206_buf206d,LOCK_19_1_2_0,LOCK_19_1_3_0,buf206_ptr,buf206d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf204_buf204d),get_input_window_float(window_buf205_buf205d),get_output_window_float(window_buf206_buf206d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf204_buf204d,LOCK_18_0_2_4096,LOCK_18_0_3_4096,buf204_ptr,buf204d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf205_buf205d,LOCK_19_1_0_4096,LOCK_19_1_1_4096,buf205_ptr,buf205d_ptr,0,index, REL_WRITE);
    window_release(window_buf206_buf206d,LOCK_19_1_2_0,LOCK_19_1_3_0,buf206_ptr,buf206d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_0_bounds > 0)
      --proc_19_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}