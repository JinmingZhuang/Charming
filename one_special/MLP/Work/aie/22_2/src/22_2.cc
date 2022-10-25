// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_2/src/22_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_2_2_4096 18
#define LOCK_21_2_3_4096 19
#define LOCK_22_2_0_0 48
#define LOCK_22_2_1_0 49
#define LOCK_22_1_6_4096 6
#define LOCK_22_1_7_4096 7
#define LOCK_22_3_2_4096 34
#define LOCK_22_3_3_4096 35

// Declare shared memory buffers
v4float buf245[256];
v4float buf245d[256];
v4float buf246[256];
v4float buf246d[256];
v4float buf247[256];
v4float buf247d[256];
v4float buf248[256];
v4float buf248d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf246_buf246d[1];
  window_datatype * buf246_ptr = (window_datatype * )buf246;
  window_datatype * buf246d_ptr = (window_datatype * )buf246d;
  window_init(window_buf246_buf246d, 1, buf246, LOCK_21_2_2_4096, buf246d, LOCK_21_2_3_4096, 256, 256);
  window_internal window_buf247_buf247d[1];
  window_datatype * buf247_ptr = (window_datatype * )buf247;
  window_datatype * buf247d_ptr = (window_datatype * )buf247d;
  window_init(window_buf247_buf247d, 1, buf247, LOCK_22_2_0_0, buf247d, LOCK_22_2_1_0, 256, 256);
  window_internal window_buf245_buf245d[1];
  window_datatype * buf245_ptr = (window_datatype * )buf245;
  window_datatype * buf245d_ptr = (window_datatype * )buf245d;
  window_init(window_buf245_buf245d, 1, buf245, LOCK_22_1_6_4096, buf245d, LOCK_22_1_7_4096, 256, 256);
  window_internal window_buf248_buf248d[1];
  window_datatype * buf248_ptr = (window_datatype * )buf248;
  window_datatype * buf248d_ptr = (window_datatype * )buf248d;
  window_init(window_buf248_buf248d, 1, buf248, LOCK_22_3_2_4096, buf248d, LOCK_22_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_2_bounds = sync_buffer[1];

  while (proc_22_2_bounds)
  {

    // Kernel call : i204:mm_kernel1
    window_acquire(window_buf246_buf246d,LOCK_21_2_2_4096,LOCK_21_2_3_4096,buf246_ptr,buf246d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf247_buf247d,LOCK_22_2_0_0,LOCK_22_2_1_0,buf247_ptr,buf247d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf245_buf245d,LOCK_22_1_6_4096,LOCK_22_1_7_4096,buf245_ptr,buf245d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf248_buf248d,LOCK_22_3_2_4096,LOCK_22_3_3_4096,buf248_ptr,buf248d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf246_buf246d),get_input_window_float(window_buf247_buf247d),get_input_window_float(window_buf245_buf245d),get_output_window_float(window_buf248_buf248d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf246_buf246d,LOCK_21_2_2_4096,LOCK_21_2_3_4096,buf246_ptr,buf246d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf247_buf247d,LOCK_22_2_0_0,LOCK_22_2_1_0,buf247_ptr,buf247d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf245_buf245d,LOCK_22_1_6_4096,LOCK_22_1_7_4096,buf245_ptr,buf245d_ptr,0,index, REL_WRITE);
    window_release(window_buf248_buf248d,LOCK_22_3_2_4096,LOCK_22_3_3_4096,buf248_ptr,buf248d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_2_bounds > 0)
      --proc_22_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}