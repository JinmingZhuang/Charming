// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_3/src/22_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_2_2_4096 2
#define LOCK_22_2_3_4096 3
#define LOCK_22_3_4_0 20
#define LOCK_22_3_5_0 21
#define LOCK_22_3_2_4096 18
#define LOCK_22_3_3_4096 19
#define LOCK_22_3_6_4096 22
#define LOCK_22_3_7_4096 23

// Declare shared memory buffers
v4float buf248[256];
v4float buf248d[256];
v4float buf249[256];
v4float buf249d[256];
v4float buf250[256];
v4float buf250d[256];
v4float buf251[256];
v4float buf251d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf249_buf249d[1];
  window_datatype * buf249_ptr = (window_datatype * )buf249;
  window_datatype * buf249d_ptr = (window_datatype * )buf249d;
  window_init(window_buf249_buf249d, 1, buf249, LOCK_22_2_2_4096, buf249d, LOCK_22_2_3_4096, 256, 256);
  window_internal window_buf250_buf250d[1];
  window_datatype * buf250_ptr = (window_datatype * )buf250;
  window_datatype * buf250d_ptr = (window_datatype * )buf250d;
  window_init(window_buf250_buf250d, 1, buf250, LOCK_22_3_4_0, buf250d, LOCK_22_3_5_0, 256, 256);
  window_internal window_buf248_buf248d[1];
  window_datatype * buf248_ptr = (window_datatype * )buf248;
  window_datatype * buf248d_ptr = (window_datatype * )buf248d;
  window_init(window_buf248_buf248d, 1, buf248, LOCK_22_3_2_4096, buf248d, LOCK_22_3_3_4096, 256, 256);
  window_internal window_buf251_buf251d[1];
  window_datatype * buf251_ptr = (window_datatype * )buf251;
  window_datatype * buf251d_ptr = (window_datatype * )buf251d;
  window_init(window_buf251_buf251d, 1, buf251, LOCK_22_3_6_4096, buf251d, LOCK_22_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_3_bounds = sync_buffer[1];

  while (proc_22_3_bounds)
  {

    // Kernel call : i205:mm_kernel1
    window_acquire(window_buf249_buf249d,LOCK_22_2_2_4096,LOCK_22_2_3_4096,buf249_ptr,buf249d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf250_buf250d,LOCK_22_3_4_0,LOCK_22_3_5_0,buf250_ptr,buf250d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf248_buf248d,LOCK_22_3_2_4096,LOCK_22_3_3_4096,buf248_ptr,buf248d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf251_buf251d,LOCK_22_3_6_4096,LOCK_22_3_7_4096,buf251_ptr,buf251d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf249_buf249d),get_input_window_float(window_buf250_buf250d),get_input_window_float(window_buf248_buf248d),get_output_window_float(window_buf251_buf251d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf249_buf249d,LOCK_22_2_2_4096,LOCK_22_2_3_4096,buf249_ptr,buf249d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf250_buf250d,LOCK_22_3_4_0,LOCK_22_3_5_0,buf250_ptr,buf250d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf248_buf248d,LOCK_22_3_2_4096,LOCK_22_3_3_4096,buf248_ptr,buf248d_ptr,0,index, REL_WRITE);
    window_release(window_buf251_buf251d,LOCK_22_3_6_4096,LOCK_22_3_7_4096,buf251_ptr,buf251d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_3_bounds > 0)
      --proc_22_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}