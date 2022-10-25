// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_7/src/48_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_7_4_4096 20
#define LOCK_48_7_5_0 21
#define LOCK_48_6_2_4096 2
#define LOCK_48_6_3_4096 3
#define LOCK_48_7_2_4096 18
#define LOCK_48_7_3_4096 19
#define LOCK_48_7_6_0 22
#define LOCK_48_7_7_0 23

// Declare shared memory buffers
v4float buf596[256];
v4float buf596d[256];
v4float buf597[256];
v4float buf597d[256];
v4float buf598[256];
v4float buf598d[256];
v4float buf599[256];
v4float buf599d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf597_buf597d[1];
  window_datatype * buf597_ptr = (window_datatype * )buf597;
  window_datatype * buf597d_ptr = (window_datatype * )buf597d;
  window_init(window_buf597_buf597d, 1, buf597, LOCK_48_7_4_4096, buf597d, LOCK_48_7_5_0, 256, 256);
  window_internal window_buf598_buf598d[1];
  window_datatype * buf598_ptr = (window_datatype * )buf598;
  window_datatype * buf598d_ptr = (window_datatype * )buf598d;
  window_init(window_buf598_buf598d, 1, buf598, LOCK_48_6_2_4096, buf598d, LOCK_48_6_3_4096, 256, 256);
  window_internal window_buf596_buf596d[1];
  window_datatype * buf596_ptr = (window_datatype * )buf596;
  window_datatype * buf596d_ptr = (window_datatype * )buf596d;
  window_init(window_buf596_buf596d, 1, buf596, LOCK_48_7_2_4096, buf596d, LOCK_48_7_3_4096, 256, 256);
  window_internal window_buf599_buf599d[1];
  window_datatype * buf599_ptr = (window_datatype * )buf599;
  window_datatype * buf599d_ptr = (window_datatype * )buf599d;
  window_init(window_buf599_buf599d, 1, buf599, LOCK_48_7_6_0, buf599d, LOCK_48_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_7_bounds = sync_buffer[1];

  while (proc_48_7_bounds)
  {

    // Kernel call : i379:mm_kernel1
    window_acquire(window_buf597_buf597d,LOCK_48_7_4_4096,LOCK_48_7_5_0,buf597_ptr,buf597d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf598_buf598d,LOCK_48_6_2_4096,LOCK_48_6_3_4096,buf598_ptr,buf598d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf596_buf596d,LOCK_48_7_2_4096,LOCK_48_7_3_4096,buf596_ptr,buf596d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf599_buf599d,LOCK_48_7_6_0,LOCK_48_7_7_0,buf599_ptr,buf599d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf597_buf597d),get_input_window_float(window_buf598_buf598d),get_input_window_float(window_buf596_buf596d),get_output_window_float(window_buf599_buf599d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf597_buf597d,LOCK_48_7_4_4096,LOCK_48_7_5_0,buf597_ptr,buf597d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf598_buf598d,LOCK_48_6_2_4096,LOCK_48_6_3_4096,buf598_ptr,buf598d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf596_buf596d,LOCK_48_7_2_4096,LOCK_48_7_3_4096,buf596_ptr,buf596d_ptr,0,index, REL_WRITE);
    window_release(window_buf599_buf599d,LOCK_48_7_6_0,LOCK_48_7_7_0,buf599_ptr,buf599d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_7_bounds > 0)
      --proc_48_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}