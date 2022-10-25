// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/4_7/src/4_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_7_0_0 48
#define LOCK_5_7_1_0 49
#define LOCK_5_7_2_4096 50
#define LOCK_5_7_3_4096 51
#define LOCK_4_7_2_0 18
#define LOCK_4_7_3_4096 19
#define LOCK_4_7_4_4096 20
#define LOCK_4_7_5_0 21

// Declare shared memory buffers
v4float buf1124[256];
v4float buf1124d[256];
v4float buf1125[256];
v4float buf1125d[256];
v4float buf1126[256];
v4float buf1126d[256];
v4float buf1127[256];
v4float buf1127d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1125_buf1125d[1];
  window_datatype * buf1125_ptr = (window_datatype * )buf1125;
  window_datatype * buf1125d_ptr = (window_datatype * )buf1125d;
  window_init(window_buf1125_buf1125d, 1, buf1125, LOCK_5_7_0_0, buf1125d, LOCK_5_7_1_0, 256, 256);
  window_internal window_buf1126_buf1126d[1];
  window_datatype * buf1126_ptr = (window_datatype * )buf1126;
  window_datatype * buf1126d_ptr = (window_datatype * )buf1126d;
  window_init(window_buf1126_buf1126d, 1, buf1126, LOCK_5_7_2_4096, buf1126d, LOCK_5_7_3_4096, 256, 256);
  window_internal window_buf1124_buf1124d[1];
  window_datatype * buf1124_ptr = (window_datatype * )buf1124;
  window_datatype * buf1124d_ptr = (window_datatype * )buf1124d;
  window_init(window_buf1124_buf1124d, 1, buf1124, LOCK_4_7_2_0, buf1124d, LOCK_4_7_3_4096, 256, 256);
  window_internal window_buf1127_buf1127d[1];
  window_datatype * buf1127_ptr = (window_datatype * )buf1127;
  window_datatype * buf1127d_ptr = (window_datatype * )buf1127d;
  window_init(window_buf1127_buf1127d, 1, buf1127, LOCK_4_7_4_4096, buf1127d, LOCK_4_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_4_7_bounds = sync_buffer[1];

  while (proc_4_7_bounds)
  {

    // Kernel call : i643:mm_kernel1
    window_acquire(window_buf1125_buf1125d,LOCK_5_7_0_0,LOCK_5_7_1_0,buf1125_ptr,buf1125d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1126_buf1126d,LOCK_5_7_2_4096,LOCK_5_7_3_4096,buf1126_ptr,buf1126d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1124_buf1124d,LOCK_4_7_2_0,LOCK_4_7_3_4096,buf1124_ptr,buf1124d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1127_buf1127d,LOCK_4_7_4_4096,LOCK_4_7_5_0,buf1127_ptr,buf1127d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1125_buf1125d),get_input_window_float(window_buf1126_buf1126d),get_input_window_float(window_buf1124_buf1124d),get_output_window_float(window_buf1127_buf1127d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1125_buf1125d,LOCK_5_7_0_0,LOCK_5_7_1_0,buf1125_ptr,buf1125d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1126_buf1126d,LOCK_5_7_2_4096,LOCK_5_7_3_4096,buf1126_ptr,buf1126d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1124_buf1124d,LOCK_4_7_2_0,LOCK_4_7_3_4096,buf1124_ptr,buf1124d_ptr,0,index, REL_WRITE);
    window_release(window_buf1127_buf1127d,LOCK_4_7_4_4096,LOCK_4_7_5_0,buf1127_ptr,buf1127d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_4_7_bounds > 0)
      --proc_4_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}