// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_2/src/37_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_3_0_4096 32
#define LOCK_37_3_1_0 33
#define LOCK_37_3_2_0 34
#define LOCK_37_3_3_4096 35
#define LOCK_37_1_6_4096 6
#define LOCK_37_1_7_0 7
#define LOCK_37_3_4_0 36
#define LOCK_37_3_5_4096 37

// Declare shared memory buffers
v4float buf425[256];
v4float buf425d[256];
v4float buf426[256];
v4float buf426d[256];
v4float buf427[256];
v4float buf427d[256];
v4float buf428[256];
v4float buf428d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf426_buf426d[1];
  window_datatype * buf426_ptr = (window_datatype * )buf426;
  window_datatype * buf426d_ptr = (window_datatype * )buf426d;
  window_init(window_buf426_buf426d, 1, buf426, LOCK_37_3_0_4096, buf426d, LOCK_37_3_1_0, 256, 256);
  window_internal window_buf427_buf427d[1];
  window_datatype * buf427_ptr = (window_datatype * )buf427;
  window_datatype * buf427d_ptr = (window_datatype * )buf427d;
  window_init(window_buf427_buf427d, 1, buf427, LOCK_37_3_2_0, buf427d, LOCK_37_3_3_4096, 256, 256);
  window_internal window_buf425_buf425d[1];
  window_datatype * buf425_ptr = (window_datatype * )buf425;
  window_datatype * buf425d_ptr = (window_datatype * )buf425d;
  window_init(window_buf425_buf425d, 1, buf425, LOCK_37_1_6_4096, buf425d, LOCK_37_1_7_0, 256, 256);
  window_internal window_buf428_buf428d[1];
  window_datatype * buf428_ptr = (window_datatype * )buf428;
  window_datatype * buf428d_ptr = (window_datatype * )buf428d;
  window_init(window_buf428_buf428d, 1, buf428, LOCK_37_3_4_0, buf428d, LOCK_37_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_2_bounds = sync_buffer[1];

  while (proc_37_2_bounds)
  {

    // Kernel call : i294:mm_kernel1
    window_acquire(window_buf426_buf426d,LOCK_37_3_0_4096,LOCK_37_3_1_0,buf426_ptr,buf426d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf427_buf427d,LOCK_37_3_2_0,LOCK_37_3_3_4096,buf427_ptr,buf427d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf425_buf425d,LOCK_37_1_6_4096,LOCK_37_1_7_0,buf425_ptr,buf425d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf428_buf428d,LOCK_37_3_4_0,LOCK_37_3_5_4096,buf428_ptr,buf428d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf426_buf426d),get_input_window_float(window_buf427_buf427d),get_input_window_float(window_buf425_buf425d),get_output_window_float(window_buf428_buf428d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf426_buf426d,LOCK_37_3_0_4096,LOCK_37_3_1_0,buf426_ptr,buf426d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf427_buf427d,LOCK_37_3_2_0,LOCK_37_3_3_4096,buf427_ptr,buf427d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf425_buf425d,LOCK_37_1_6_4096,LOCK_37_1_7_0,buf425_ptr,buf425d_ptr,0,index, REL_WRITE);
    window_release(window_buf428_buf428d,LOCK_37_3_4_0,LOCK_37_3_5_4096,buf428_ptr,buf428d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_2_bounds > 0)
      --proc_37_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}