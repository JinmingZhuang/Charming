// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_0/src/26_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_26_0_0_0 48
#define LOCK_26_0_1_0 49
#define LOCK_25_0_2_4096 18
#define LOCK_25_0_3_4096 19
#define LOCK_26_1_2_4096 34
#define LOCK_26_1_3_0 35

// Declare shared memory buffers
v4float buf288[256];
v4float buf288d[256];
v4float buf289[256];
v4float buf289d[256];
v4float buf290[256];
v4float buf290d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf288_buf288d[1];
  window_datatype * buf288_ptr = (window_datatype * )buf288;
  window_datatype * buf288d_ptr = (window_datatype * )buf288d;
  window_init(window_buf288_buf288d, 1, buf288, LOCK_26_0_0_0, buf288d, LOCK_26_0_1_0, 256, 256);
  window_internal window_buf289_buf289d[1];
  window_datatype * buf289_ptr = (window_datatype * )buf289;
  window_datatype * buf289d_ptr = (window_datatype * )buf289d;
  window_init(window_buf289_buf289d, 1, buf289, LOCK_25_0_2_4096, buf289d, LOCK_25_0_3_4096, 256, 256);
  window_internal window_buf290_buf290d[1];
  window_datatype * buf290_ptr = (window_datatype * )buf290;
  window_datatype * buf290d_ptr = (window_datatype * )buf290d;
  window_init(window_buf290_buf290d, 1, buf290, LOCK_26_1_2_4096, buf290d, LOCK_26_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_0_bounds = sync_buffer[1];

  while (proc_26_0_bounds)
  {

    // Kernel call : i226:mm_kernel0
    window_acquire(window_buf288_buf288d,LOCK_26_0_0_0,LOCK_26_0_1_0,buf288_ptr,buf288d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf289_buf289d,LOCK_25_0_2_4096,LOCK_25_0_3_4096,buf289_ptr,buf289d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf290_buf290d,LOCK_26_1_2_4096,LOCK_26_1_3_0,buf290_ptr,buf290d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf288_buf288d),get_input_window_float(window_buf289_buf289d),get_output_window_float(window_buf290_buf290d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf288_buf288d,LOCK_26_0_0_0,LOCK_26_0_1_0,buf288_ptr,buf288d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf289_buf289d,LOCK_25_0_2_4096,LOCK_25_0_3_4096,buf289_ptr,buf289d_ptr,0,index, REL_WRITE);
    window_release(window_buf290_buf290d,LOCK_26_1_2_4096,LOCK_26_1_3_0,buf290_ptr,buf290d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_0_bounds > 0)
      --proc_26_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}