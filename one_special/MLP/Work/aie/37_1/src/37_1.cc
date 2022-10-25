// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_1/src/37_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_2_0_0 32
#define LOCK_37_2_1_0 33
#define LOCK_37_0_0_0 0
#define LOCK_37_0_1_0 1
#define LOCK_37_1_4_0 20
#define LOCK_37_1_5_0 21
#define LOCK_37_1_6_4096 22
#define LOCK_37_1_7_0 23

// Declare shared memory buffers
v4float buf422[256];
v4float buf422d[256];
v4float buf423[256];
v4float buf423d[256];
v4float buf424[256];
v4float buf424d[256];
v4float buf425[256];
v4float buf425d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf423_buf423d[1];
  window_datatype * buf423_ptr = (window_datatype * )buf423;
  window_datatype * buf423d_ptr = (window_datatype * )buf423d;
  window_init(window_buf423_buf423d, 1, buf423, LOCK_37_2_0_0, buf423d, LOCK_37_2_1_0, 256, 256);
  window_internal window_buf424_buf424d[1];
  window_datatype * buf424_ptr = (window_datatype * )buf424;
  window_datatype * buf424d_ptr = (window_datatype * )buf424d;
  window_init(window_buf424_buf424d, 1, buf424, LOCK_37_0_0_0, buf424d, LOCK_37_0_1_0, 256, 256);
  window_internal window_buf422_buf422d[1];
  window_datatype * buf422_ptr = (window_datatype * )buf422;
  window_datatype * buf422d_ptr = (window_datatype * )buf422d;
  window_init(window_buf422_buf422d, 1, buf422, LOCK_37_1_4_0, buf422d, LOCK_37_1_5_0, 256, 256);
  window_internal window_buf425_buf425d[1];
  window_datatype * buf425_ptr = (window_datatype * )buf425;
  window_datatype * buf425d_ptr = (window_datatype * )buf425d;
  window_init(window_buf425_buf425d, 1, buf425, LOCK_37_1_6_4096, buf425d, LOCK_37_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_1_bounds = sync_buffer[1];

  while (proc_37_1_bounds)
  {

    // Kernel call : i293:mm_kernel1
    window_acquire(window_buf423_buf423d,LOCK_37_2_0_0,LOCK_37_2_1_0,buf423_ptr,buf423d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf424_buf424d,LOCK_37_0_0_0,LOCK_37_0_1_0,buf424_ptr,buf424d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf422_buf422d,LOCK_37_1_4_0,LOCK_37_1_5_0,buf422_ptr,buf422d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf425_buf425d,LOCK_37_1_6_4096,LOCK_37_1_7_0,buf425_ptr,buf425d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf423_buf423d),get_input_window_float(window_buf424_buf424d),get_input_window_float(window_buf422_buf422d),get_output_window_float(window_buf425_buf425d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf423_buf423d,LOCK_37_2_0_0,LOCK_37_2_1_0,buf423_ptr,buf423d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf424_buf424d,LOCK_37_0_0_0,LOCK_37_0_1_0,buf424_ptr,buf424d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf422_buf422d,LOCK_37_1_4_0,LOCK_37_1_5_0,buf422_ptr,buf422d_ptr,0,index, REL_WRITE);
    window_release(window_buf425_buf425d,LOCK_37_1_6_4096,LOCK_37_1_7_0,buf425_ptr,buf425d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_1_bounds > 0)
      --proc_37_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}