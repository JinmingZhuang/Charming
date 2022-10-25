// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_4/src/21_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_4_2_4096 50
#define LOCK_21_4_3_4096 51
#define LOCK_21_3_6_0 6
#define LOCK_21_3_7_4096 7
#define LOCK_21_5_0_0 32
#define LOCK_21_5_1_0 33

// Declare shared memory buffers
v4float buf912[256];
v4float buf912d[256];
v4float buf913[256];
v4float buf913d[256];
v4float buf914[256];
v4float buf914d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf912_buf912d[1];
  window_datatype * buf912_ptr = (window_datatype * )buf912;
  window_datatype * buf912d_ptr = (window_datatype * )buf912d;
  window_init(window_buf912_buf912d, 1, buf912, LOCK_21_4_2_4096, buf912d, LOCK_21_4_3_4096, 256, 256);
  window_internal window_buf913_buf913d[1];
  window_datatype * buf913_ptr = (window_datatype * )buf913;
  window_datatype * buf913d_ptr = (window_datatype * )buf913d;
  window_init(window_buf913_buf913d, 1, buf913, LOCK_21_3_6_0, buf913d, LOCK_21_3_7_4096, 256, 256);
  window_internal window_buf914_buf914d[1];
  window_datatype * buf914_ptr = (window_datatype * )buf914;
  window_datatype * buf914d_ptr = (window_datatype * )buf914d;
  window_init(window_buf914_buf914d, 1, buf914, LOCK_21_5_0_0, buf914d, LOCK_21_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_4_bounds = sync_buffer[1];

  while (proc_21_4_bounds)
  {

    // Kernel call : i538:mm_kernel0
    window_acquire(window_buf912_buf912d,LOCK_21_4_2_4096,LOCK_21_4_3_4096,buf912_ptr,buf912d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf913_buf913d,LOCK_21_3_6_0,LOCK_21_3_7_4096,buf913_ptr,buf913d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf914_buf914d,LOCK_21_5_0_0,LOCK_21_5_1_0,buf914_ptr,buf914d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf912_buf912d),get_input_window_float(window_buf913_buf913d),get_output_window_float(window_buf914_buf914d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf912_buf912d,LOCK_21_4_2_4096,LOCK_21_4_3_4096,buf912_ptr,buf912d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf913_buf913d,LOCK_21_3_6_0,LOCK_21_3_7_4096,buf913_ptr,buf913d_ptr,0,index, REL_WRITE);
    window_release(window_buf914_buf914d,LOCK_21_5_0_0,LOCK_21_5_1_0,buf914_ptr,buf914d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_4_bounds > 0)
      --proc_21_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}