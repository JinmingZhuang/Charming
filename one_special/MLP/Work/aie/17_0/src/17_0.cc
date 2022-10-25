// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_0/src/17_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_0_0_0 48
#define LOCK_17_0_1_0 49
#define LOCK_17_0_2_4096 50
#define LOCK_17_0_3_4096 51
#define LOCK_17_1_0_0 32
#define LOCK_17_1_1_0 33

// Declare shared memory buffers
v4float buf180[256];
v4float buf180d[256];
v4float buf181[256];
v4float buf181d[256];
v4float buf182[256];
v4float buf182d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf180_buf180d[1];
  window_datatype * buf180_ptr = (window_datatype * )buf180;
  window_datatype * buf180d_ptr = (window_datatype * )buf180d;
  window_init(window_buf180_buf180d, 1, buf180, LOCK_17_0_0_0, buf180d, LOCK_17_0_1_0, 256, 256);
  window_internal window_buf181_buf181d[1];
  window_datatype * buf181_ptr = (window_datatype * )buf181;
  window_datatype * buf181d_ptr = (window_datatype * )buf181d;
  window_init(window_buf181_buf181d, 1, buf181, LOCK_17_0_2_4096, buf181d, LOCK_17_0_3_4096, 256, 256);
  window_internal window_buf182_buf182d[1];
  window_datatype * buf182_ptr = (window_datatype * )buf182;
  window_datatype * buf182d_ptr = (window_datatype * )buf182d;
  window_init(window_buf182_buf182d, 1, buf182, LOCK_17_1_0_0, buf182d, LOCK_17_1_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_0_bounds = sync_buffer[1];

  while (proc_17_0_bounds)
  {

    // Kernel call : i172:mm_kernel0
    window_acquire(window_buf180_buf180d,LOCK_17_0_0_0,LOCK_17_0_1_0,buf180_ptr,buf180d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf181_buf181d,LOCK_17_0_2_4096,LOCK_17_0_3_4096,buf181_ptr,buf181d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf182_buf182d,LOCK_17_1_0_0,LOCK_17_1_1_0,buf182_ptr,buf182d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf180_buf180d),get_input_window_float(window_buf181_buf181d),get_output_window_float(window_buf182_buf182d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf180_buf180d,LOCK_17_0_0_0,LOCK_17_0_1_0,buf180_ptr,buf180d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf181_buf181d,LOCK_17_0_2_4096,LOCK_17_0_3_4096,buf181_ptr,buf181d_ptr,0,index, REL_WRITE);
    window_release(window_buf182_buf182d,LOCK_17_1_0_0,LOCK_17_1_1_0,buf182_ptr,buf182d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_0_bounds > 0)
      --proc_17_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}