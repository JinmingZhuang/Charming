// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_4/src/2_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_1_4_0_4096 16
#define LOCK_1_4_1_0 17
#define LOCK_1_4_2_0 18
#define LOCK_1_4_3_4096 19
#define LOCK_2_5_0_0 32
#define LOCK_2_5_1_0 33

// Declare shared memory buffers
v4float buf1140[256];
v4float buf1140d[256];
v4float buf1141[256];
v4float buf1141d[256];
v4float buf1142[256];
v4float buf1142d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1140_buf1140d[1];
  window_datatype * buf1140_ptr = (window_datatype * )buf1140;
  window_datatype * buf1140d_ptr = (window_datatype * )buf1140d;
  window_init(window_buf1140_buf1140d, 1, buf1140, LOCK_1_4_0_4096, buf1140d, LOCK_1_4_1_0, 256, 256);
  window_internal window_buf1141_buf1141d[1];
  window_datatype * buf1141_ptr = (window_datatype * )buf1141;
  window_datatype * buf1141d_ptr = (window_datatype * )buf1141d;
  window_init(window_buf1141_buf1141d, 1, buf1141, LOCK_1_4_2_0, buf1141d, LOCK_1_4_3_4096, 256, 256);
  window_internal window_buf1142_buf1142d[1];
  window_datatype * buf1142_ptr = (window_datatype * )buf1142;
  window_datatype * buf1142d_ptr = (window_datatype * )buf1142d;
  window_init(window_buf1142_buf1142d, 1, buf1142, LOCK_2_5_0_0, buf1142d, LOCK_2_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_4_bounds = sync_buffer[1];

  while (proc_2_4_bounds)
  {

    // Kernel call : i652:mm_kernel0
    window_acquire(window_buf1140_buf1140d,LOCK_1_4_0_4096,LOCK_1_4_1_0,buf1140_ptr,buf1140d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1141_buf1141d,LOCK_1_4_2_0,LOCK_1_4_3_4096,buf1141_ptr,buf1141d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1142_buf1142d,LOCK_2_5_0_0,LOCK_2_5_1_0,buf1142_ptr,buf1142d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1140_buf1140d),get_input_window_float(window_buf1141_buf1141d),get_output_window_float(window_buf1142_buf1142d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1140_buf1140d,LOCK_1_4_0_4096,LOCK_1_4_1_0,buf1140_ptr,buf1140d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1141_buf1141d,LOCK_1_4_2_0,LOCK_1_4_3_4096,buf1141_ptr,buf1141d_ptr,0,index, REL_WRITE);
    window_release(window_buf1142_buf1142d,LOCK_2_5_0_0,LOCK_2_5_1_0,buf1142_ptr,buf1142d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_4_bounds > 0)
      --proc_2_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}