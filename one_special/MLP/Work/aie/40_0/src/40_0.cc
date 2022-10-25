// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_0/src/40_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_1_0_4096 32
#define LOCK_40_1_1_4096 33
#define LOCK_40_0_0_0 48
#define LOCK_40_0_1_0 49
#define LOCK_40_1_2_4096 34
#define LOCK_40_1_3_4096 35

// Declare shared memory buffers
v4float buf456[256];
v4float buf456d[256];
v4float buf457[256];
v4float buf457d[256];
v4float buf458[256];
v4float buf458d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf456_buf456d[1];
  window_datatype * buf456_ptr = (window_datatype * )buf456;
  window_datatype * buf456d_ptr = (window_datatype * )buf456d;
  window_init(window_buf456_buf456d, 1, buf456, LOCK_40_1_0_4096, buf456d, LOCK_40_1_1_4096, 256, 256);
  window_internal window_buf457_buf457d[1];
  window_datatype * buf457_ptr = (window_datatype * )buf457;
  window_datatype * buf457d_ptr = (window_datatype * )buf457d;
  window_init(window_buf457_buf457d, 1, buf457, LOCK_40_0_0_0, buf457d, LOCK_40_0_1_0, 256, 256);
  window_internal window_buf458_buf458d[1];
  window_datatype * buf458_ptr = (window_datatype * )buf458;
  window_datatype * buf458d_ptr = (window_datatype * )buf458d;
  window_init(window_buf458_buf458d, 1, buf458, LOCK_40_1_2_4096, buf458d, LOCK_40_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_0_bounds = sync_buffer[1];

  while (proc_40_0_bounds)
  {

    // Kernel call : i310:mm_kernel0
    window_acquire(window_buf456_buf456d,LOCK_40_1_0_4096,LOCK_40_1_1_4096,buf456_ptr,buf456d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf457_buf457d,LOCK_40_0_0_0,LOCK_40_0_1_0,buf457_ptr,buf457d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf458_buf458d,LOCK_40_1_2_4096,LOCK_40_1_3_4096,buf458_ptr,buf458d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf456_buf456d),get_input_window_float(window_buf457_buf457d),get_output_window_float(window_buf458_buf458d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf456_buf456d,LOCK_40_1_0_4096,LOCK_40_1_1_4096,buf456_ptr,buf456d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf457_buf457d,LOCK_40_0_0_0,LOCK_40_0_1_0,buf457_ptr,buf457d_ptr,0,index, REL_WRITE);
    window_release(window_buf458_buf458d,LOCK_40_1_2_4096,LOCK_40_1_3_4096,buf458_ptr,buf458d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_0_bounds > 0)
      --proc_40_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}