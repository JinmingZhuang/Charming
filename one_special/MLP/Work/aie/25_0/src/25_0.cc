// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_0/src/25_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_0_0_0 48
#define LOCK_25_0_1_0 49
#define LOCK_25_1_0_4096 32
#define LOCK_25_1_1_4096 33
#define LOCK_25_1_2_4096 34
#define LOCK_25_1_3_4096 35

// Declare shared memory buffers
v4float buf276[256];
v4float buf276d[256];
v4float buf277[256];
v4float buf277d[256];
v4float buf278[256];
v4float buf278d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf276_buf276d[1];
  window_datatype * buf276_ptr = (window_datatype * )buf276;
  window_datatype * buf276d_ptr = (window_datatype * )buf276d;
  window_init(window_buf276_buf276d, 1, buf276, LOCK_25_0_0_0, buf276d, LOCK_25_0_1_0, 256, 256);
  window_internal window_buf277_buf277d[1];
  window_datatype * buf277_ptr = (window_datatype * )buf277;
  window_datatype * buf277d_ptr = (window_datatype * )buf277d;
  window_init(window_buf277_buf277d, 1, buf277, LOCK_25_1_0_4096, buf277d, LOCK_25_1_1_4096, 256, 256);
  window_internal window_buf278_buf278d[1];
  window_datatype * buf278_ptr = (window_datatype * )buf278;
  window_datatype * buf278d_ptr = (window_datatype * )buf278d;
  window_init(window_buf278_buf278d, 1, buf278, LOCK_25_1_2_4096, buf278d, LOCK_25_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_0_bounds = sync_buffer[1];

  while (proc_25_0_bounds)
  {

    // Kernel call : i220:mm_kernel0
    window_acquire(window_buf276_buf276d,LOCK_25_0_0_0,LOCK_25_0_1_0,buf276_ptr,buf276d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf277_buf277d,LOCK_25_1_0_4096,LOCK_25_1_1_4096,buf277_ptr,buf277d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf278_buf278d,LOCK_25_1_2_4096,LOCK_25_1_3_4096,buf278_ptr,buf278d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf276_buf276d),get_input_window_float(window_buf277_buf277d),get_output_window_float(window_buf278_buf278d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf276_buf276d,LOCK_25_0_0_0,LOCK_25_0_1_0,buf276_ptr,buf276d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf277_buf277d,LOCK_25_1_0_4096,LOCK_25_1_1_4096,buf277_ptr,buf277d_ptr,0,index, REL_WRITE);
    window_release(window_buf278_buf278d,LOCK_25_1_2_4096,LOCK_25_1_3_4096,buf278_ptr,buf278d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_0_bounds > 0)
      --proc_25_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}