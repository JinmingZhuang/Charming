// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_1/src/8_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_0_0_0 0
#define LOCK_8_0_1_0 1
#define LOCK_8_0_2_4096 2
#define LOCK_8_0_3_4096 3
#define LOCK_8_1_4_4096 20
#define LOCK_8_1_5_4096 21
#define LOCK_8_1_6_0 22
#define LOCK_8_1_7_4096 23

// Declare shared memory buffers
v4float buf74[256];
v4float buf74d[256];
v4float buf75[256];
v4float buf75d[256];
v4float buf76[256];
v4float buf76d[256];
v4float buf77[256];
v4float buf77d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf75_buf75d[1];
  window_datatype * buf75_ptr = (window_datatype * )buf75;
  window_datatype * buf75d_ptr = (window_datatype * )buf75d;
  window_init(window_buf75_buf75d, 1, buf75, LOCK_8_0_0_0, buf75d, LOCK_8_0_1_0, 256, 256);
  window_internal window_buf76_buf76d[1];
  window_datatype * buf76_ptr = (window_datatype * )buf76;
  window_datatype * buf76d_ptr = (window_datatype * )buf76d;
  window_init(window_buf76_buf76d, 1, buf76, LOCK_8_0_2_4096, buf76d, LOCK_8_0_3_4096, 256, 256);
  window_internal window_buf74_buf74d[1];
  window_datatype * buf74_ptr = (window_datatype * )buf74;
  window_datatype * buf74d_ptr = (window_datatype * )buf74d;
  window_init(window_buf74_buf74d, 1, buf74, LOCK_8_1_4_4096, buf74d, LOCK_8_1_5_4096, 256, 256);
  window_internal window_buf77_buf77d[1];
  window_datatype * buf77_ptr = (window_datatype * )buf77;
  window_datatype * buf77d_ptr = (window_datatype * )buf77d;
  window_init(window_buf77_buf77d, 1, buf77, LOCK_8_1_6_0, buf77d, LOCK_8_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_1_bounds = sync_buffer[1];

  while (proc_8_1_bounds)
  {

    // Kernel call : i119:mm_kernel1
    window_acquire(window_buf75_buf75d,LOCK_8_0_0_0,LOCK_8_0_1_0,buf75_ptr,buf75d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf76_buf76d,LOCK_8_0_2_4096,LOCK_8_0_3_4096,buf76_ptr,buf76d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf74_buf74d,LOCK_8_1_4_4096,LOCK_8_1_5_4096,buf74_ptr,buf74d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf77_buf77d,LOCK_8_1_6_0,LOCK_8_1_7_4096,buf77_ptr,buf77d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf75_buf75d),get_input_window_float(window_buf76_buf76d),get_input_window_float(window_buf74_buf74d),get_output_window_float(window_buf77_buf77d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf75_buf75d,LOCK_8_0_0_0,LOCK_8_0_1_0,buf75_ptr,buf75d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf76_buf76d,LOCK_8_0_2_4096,LOCK_8_0_3_4096,buf76_ptr,buf76d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf74_buf74d,LOCK_8_1_4_4096,LOCK_8_1_5_4096,buf74_ptr,buf74d_ptr,0,index, REL_WRITE);
    window_release(window_buf77_buf77d,LOCK_8_1_6_0,LOCK_8_1_7_4096,buf77_ptr,buf77d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_1_bounds > 0)
      --proc_8_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}