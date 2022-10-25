// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_7/src/21_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_6_0_0 0
#define LOCK_21_6_1_0 1
#define LOCK_21_6_2_4096 2
#define LOCK_21_6_3_4096 3
#define LOCK_21_7_4_0 20
#define LOCK_21_7_5_4096 21
#define LOCK_21_7_6_0 22
#define LOCK_21_7_7_0 23

// Declare shared memory buffers
v4float buf920[256];
v4float buf920d[256];
v4float buf921[256];
v4float buf921d[256];
v4float buf922[256];
v4float buf922d[256];
v4float buf923[256];
v4float buf923d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf921_buf921d[1];
  window_datatype * buf921_ptr = (window_datatype * )buf921;
  window_datatype * buf921d_ptr = (window_datatype * )buf921d;
  window_init(window_buf921_buf921d, 1, buf921, LOCK_21_6_0_0, buf921d, LOCK_21_6_1_0, 256, 256);
  window_internal window_buf922_buf922d[1];
  window_datatype * buf922_ptr = (window_datatype * )buf922;
  window_datatype * buf922d_ptr = (window_datatype * )buf922d;
  window_init(window_buf922_buf922d, 1, buf922, LOCK_21_6_2_4096, buf922d, LOCK_21_6_3_4096, 256, 256);
  window_internal window_buf920_buf920d[1];
  window_datatype * buf920_ptr = (window_datatype * )buf920;
  window_datatype * buf920d_ptr = (window_datatype * )buf920d;
  window_init(window_buf920_buf920d, 1, buf920, LOCK_21_7_4_0, buf920d, LOCK_21_7_5_4096, 256, 256);
  window_internal window_buf923_buf923d[1];
  window_datatype * buf923_ptr = (window_datatype * )buf923;
  window_datatype * buf923d_ptr = (window_datatype * )buf923d;
  window_init(window_buf923_buf923d, 1, buf923, LOCK_21_7_6_0, buf923d, LOCK_21_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_7_bounds = sync_buffer[1];

  while (proc_21_7_bounds)
  {

    // Kernel call : i541:mm_kernel1
    window_acquire(window_buf921_buf921d,LOCK_21_6_0_0,LOCK_21_6_1_0,buf921_ptr,buf921d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf922_buf922d,LOCK_21_6_2_4096,LOCK_21_6_3_4096,buf922_ptr,buf922d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf920_buf920d,LOCK_21_7_4_0,LOCK_21_7_5_4096,buf920_ptr,buf920d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf923_buf923d,LOCK_21_7_6_0,LOCK_21_7_7_0,buf923_ptr,buf923d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf921_buf921d),get_input_window_float(window_buf922_buf922d),get_input_window_float(window_buf920_buf920d),get_output_window_float(window_buf923_buf923d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf921_buf921d,LOCK_21_6_0_0,LOCK_21_6_1_0,buf921_ptr,buf921d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf922_buf922d,LOCK_21_6_2_4096,LOCK_21_6_3_4096,buf922_ptr,buf922d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf920_buf920d,LOCK_21_7_4_0,LOCK_21_7_5_4096,buf920_ptr,buf920d_ptr,0,index, REL_WRITE);
    window_release(window_buf923_buf923d,LOCK_21_7_6_0,LOCK_21_7_7_0,buf923_ptr,buf923d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_7_bounds > 0)
      --proc_21_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}