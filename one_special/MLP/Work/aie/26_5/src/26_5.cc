// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_5/src/26_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_26_6_2_0 34
#define LOCK_26_6_3_4096 35
#define LOCK_26_5_2_4096 18
#define LOCK_26_5_3_0 19
#define LOCK_26_5_0_0 16
#define LOCK_26_5_1_4096 17
#define LOCK_26_5_4_4096 20
#define LOCK_26_5_5_4096 21

// Declare shared memory buffers
v4float buf854[256];
v4float buf854d[256];
v4float buf855[256];
v4float buf855d[256];
v4float buf856[256];
v4float buf856d[256];
v4float buf857[256];
v4float buf857d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf855_buf855d[1];
  window_datatype * buf855_ptr = (window_datatype * )buf855;
  window_datatype * buf855d_ptr = (window_datatype * )buf855d;
  window_init(window_buf855_buf855d, 1, buf855, LOCK_26_6_2_0, buf855d, LOCK_26_6_3_4096, 256, 256);
  window_internal window_buf856_buf856d[1];
  window_datatype * buf856_ptr = (window_datatype * )buf856;
  window_datatype * buf856d_ptr = (window_datatype * )buf856d;
  window_init(window_buf856_buf856d, 1, buf856, LOCK_26_5_2_4096, buf856d, LOCK_26_5_3_0, 256, 256);
  window_internal window_buf854_buf854d[1];
  window_datatype * buf854_ptr = (window_datatype * )buf854;
  window_datatype * buf854d_ptr = (window_datatype * )buf854d;
  window_init(window_buf854_buf854d, 1, buf854, LOCK_26_5_0_0, buf854d, LOCK_26_5_1_4096, 256, 256);
  window_internal window_buf857_buf857d[1];
  window_datatype * buf857_ptr = (window_datatype * )buf857;
  window_datatype * buf857d_ptr = (window_datatype * )buf857d;
  window_init(window_buf857_buf857d, 1, buf857, LOCK_26_5_4_4096, buf857d, LOCK_26_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_5_bounds = sync_buffer[1];

  while (proc_26_5_bounds)
  {

    // Kernel call : i509:mm_kernel1
    window_acquire(window_buf855_buf855d,LOCK_26_6_2_0,LOCK_26_6_3_4096,buf855_ptr,buf855d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf856_buf856d,LOCK_26_5_2_4096,LOCK_26_5_3_0,buf856_ptr,buf856d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf854_buf854d,LOCK_26_5_0_0,LOCK_26_5_1_4096,buf854_ptr,buf854d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf857_buf857d,LOCK_26_5_4_4096,LOCK_26_5_5_4096,buf857_ptr,buf857d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf855_buf855d),get_input_window_float(window_buf856_buf856d),get_input_window_float(window_buf854_buf854d),get_output_window_float(window_buf857_buf857d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf855_buf855d,LOCK_26_6_2_0,LOCK_26_6_3_4096,buf855_ptr,buf855d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf856_buf856d,LOCK_26_5_2_4096,LOCK_26_5_3_0,buf856_ptr,buf856d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf854_buf854d,LOCK_26_5_0_0,LOCK_26_5_1_4096,buf854_ptr,buf854d_ptr,0,index, REL_WRITE);
    window_release(window_buf857_buf857d,LOCK_26_5_4_4096,LOCK_26_5_5_4096,buf857_ptr,buf857d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_5_bounds > 0)
      --proc_26_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}