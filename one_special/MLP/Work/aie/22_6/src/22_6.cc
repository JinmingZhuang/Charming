// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/22_6/src/22_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_6_2_4096 50
#define LOCK_22_6_3_4096 51
#define LOCK_22_5_6_4096 6
#define LOCK_22_5_7_4096 7
#define LOCK_22_5_4_4096 4
#define LOCK_22_5_5_4096 5
#define LOCK_22_7_0_0 32
#define LOCK_22_7_1_0 33

// Declare shared memory buffers
v4float buf905[256];
v4float buf905d[256];
v4float buf906[256];
v4float buf906d[256];
v4float buf907[256];
v4float buf907d[256];
v4float buf908[256];
v4float buf908d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf906_buf906d[1];
  window_datatype * buf906_ptr = (window_datatype * )buf906;
  window_datatype * buf906d_ptr = (window_datatype * )buf906d;
  window_init(window_buf906_buf906d, 1, buf906, LOCK_22_6_2_4096, buf906d, LOCK_22_6_3_4096, 256, 256);
  window_internal window_buf907_buf907d[1];
  window_datatype * buf907_ptr = (window_datatype * )buf907;
  window_datatype * buf907d_ptr = (window_datatype * )buf907d;
  window_init(window_buf907_buf907d, 1, buf907, LOCK_22_5_6_4096, buf907d, LOCK_22_5_7_4096, 256, 256);
  window_internal window_buf905_buf905d[1];
  window_datatype * buf905_ptr = (window_datatype * )buf905;
  window_datatype * buf905d_ptr = (window_datatype * )buf905d;
  window_init(window_buf905_buf905d, 1, buf905, LOCK_22_5_4_4096, buf905d, LOCK_22_5_5_4096, 256, 256);
  window_internal window_buf908_buf908d[1];
  window_datatype * buf908_ptr = (window_datatype * )buf908;
  window_datatype * buf908d_ptr = (window_datatype * )buf908d;
  window_init(window_buf908_buf908d, 1, buf908, LOCK_22_7_0_0, buf908d, LOCK_22_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_22_6_bounds = sync_buffer[1];

  while (proc_22_6_bounds)
  {

    // Kernel call : i534:mm_kernel1
    window_acquire(window_buf906_buf906d,LOCK_22_6_2_4096,LOCK_22_6_3_4096,buf906_ptr,buf906d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf907_buf907d,LOCK_22_5_6_4096,LOCK_22_5_7_4096,buf907_ptr,buf907d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf905_buf905d,LOCK_22_5_4_4096,LOCK_22_5_5_4096,buf905_ptr,buf905d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf908_buf908d,LOCK_22_7_0_0,LOCK_22_7_1_0,buf908_ptr,buf908d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf906_buf906d),get_input_window_float(window_buf907_buf907d),get_input_window_float(window_buf905_buf905d),get_output_window_float(window_buf908_buf908d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf906_buf906d,LOCK_22_6_2_4096,LOCK_22_6_3_4096,buf906_ptr,buf906d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf907_buf907d,LOCK_22_5_6_4096,LOCK_22_5_7_4096,buf907_ptr,buf907d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf905_buf905d,LOCK_22_5_4_4096,LOCK_22_5_5_4096,buf905_ptr,buf905d_ptr,0,index, REL_WRITE);
    window_release(window_buf908_buf908d,LOCK_22_7_0_0,LOCK_22_7_1_0,buf908_ptr,buf908d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_22_6_bounds > 0)
      --proc_22_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}