// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_0/src/41_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_0_2_4096 18
#define LOCK_40_0_3_4096 19
#define LOCK_41_0_0_0 48
#define LOCK_41_0_1_0 49
#define LOCK_41_1_2_4096 34
#define LOCK_41_1_3_4096 35

// Declare shared memory buffers
v4float buf468[256];
v4float buf468d[256];
v4float buf469[256];
v4float buf469d[256];
v4float buf470[256];
v4float buf470d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf468_buf468d[1];
  window_datatype * buf468_ptr = (window_datatype * )buf468;
  window_datatype * buf468d_ptr = (window_datatype * )buf468d;
  window_init(window_buf468_buf468d, 1, buf468, LOCK_40_0_2_4096, buf468d, LOCK_40_0_3_4096, 256, 256);
  window_internal window_buf469_buf469d[1];
  window_datatype * buf469_ptr = (window_datatype * )buf469;
  window_datatype * buf469d_ptr = (window_datatype * )buf469d;
  window_init(window_buf469_buf469d, 1, buf469, LOCK_41_0_0_0, buf469d, LOCK_41_0_1_0, 256, 256);
  window_internal window_buf470_buf470d[1];
  window_datatype * buf470_ptr = (window_datatype * )buf470;
  window_datatype * buf470d_ptr = (window_datatype * )buf470d;
  window_init(window_buf470_buf470d, 1, buf470, LOCK_41_1_2_4096, buf470d, LOCK_41_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_0_bounds = sync_buffer[1];

  while (proc_41_0_bounds)
  {

    // Kernel call : i316:mm_kernel0
    window_acquire(window_buf468_buf468d,LOCK_40_0_2_4096,LOCK_40_0_3_4096,buf468_ptr,buf468d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf469_buf469d,LOCK_41_0_0_0,LOCK_41_0_1_0,buf469_ptr,buf469d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf470_buf470d,LOCK_41_1_2_4096,LOCK_41_1_3_4096,buf470_ptr,buf470d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf468_buf468d),get_input_window_float(window_buf469_buf469d),get_output_window_float(window_buf470_buf470d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf468_buf468d,LOCK_40_0_2_4096,LOCK_40_0_3_4096,buf468_ptr,buf468d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf469_buf469d,LOCK_41_0_0_0,LOCK_41_0_1_0,buf469_ptr,buf469d_ptr,0,index, REL_WRITE);
    window_release(window_buf470_buf470d,LOCK_41_1_2_4096,LOCK_41_1_3_4096,buf470_ptr,buf470d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_0_bounds > 0)
      --proc_41_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}