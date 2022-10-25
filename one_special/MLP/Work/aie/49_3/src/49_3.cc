// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_3/src/49_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_3_2_4096 18
#define LOCK_49_3_3_4096 19
#define LOCK_49_3_4_0 20
#define LOCK_49_3_5_0 21
#define LOCK_49_3_0_0 16
#define LOCK_49_3_1_0 17
#define LOCK_49_3_6_4096 22
#define LOCK_49_3_7_4096 23

// Declare shared memory buffers
v4float buf572[256];
v4float buf572d[256];
v4float buf573[256];
v4float buf573d[256];
v4float buf574[256];
v4float buf574d[256];
v4float buf575[256];
v4float buf575d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf573_buf573d[1];
  window_datatype * buf573_ptr = (window_datatype * )buf573;
  window_datatype * buf573d_ptr = (window_datatype * )buf573d;
  window_init(window_buf573_buf573d, 1, buf573, LOCK_49_3_2_4096, buf573d, LOCK_49_3_3_4096, 256, 256);
  window_internal window_buf574_buf574d[1];
  window_datatype * buf574_ptr = (window_datatype * )buf574;
  window_datatype * buf574d_ptr = (window_datatype * )buf574d;
  window_init(window_buf574_buf574d, 1, buf574, LOCK_49_3_4_0, buf574d, LOCK_49_3_5_0, 256, 256);
  window_internal window_buf572_buf572d[1];
  window_datatype * buf572_ptr = (window_datatype * )buf572;
  window_datatype * buf572d_ptr = (window_datatype * )buf572d;
  window_init(window_buf572_buf572d, 1, buf572, LOCK_49_3_0_0, buf572d, LOCK_49_3_1_0, 256, 256);
  window_internal window_buf575_buf575d[1];
  window_datatype * buf575_ptr = (window_datatype * )buf575;
  window_datatype * buf575d_ptr = (window_datatype * )buf575d;
  window_init(window_buf575_buf575d, 1, buf575, LOCK_49_3_6_4096, buf575d, LOCK_49_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_3_bounds = sync_buffer[1];

  while (proc_49_3_bounds)
  {

    // Kernel call : i367:mm_kernel1
    window_acquire(window_buf573_buf573d,LOCK_49_3_2_4096,LOCK_49_3_3_4096,buf573_ptr,buf573d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf574_buf574d,LOCK_49_3_4_0,LOCK_49_3_5_0,buf574_ptr,buf574d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf572_buf572d,LOCK_49_3_0_0,LOCK_49_3_1_0,buf572_ptr,buf572d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf575_buf575d,LOCK_49_3_6_4096,LOCK_49_3_7_4096,buf575_ptr,buf575d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf573_buf573d),get_input_window_float(window_buf574_buf574d),get_input_window_float(window_buf572_buf572d),get_output_window_float(window_buf575_buf575d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf573_buf573d,LOCK_49_3_2_4096,LOCK_49_3_3_4096,buf573_ptr,buf573d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf574_buf574d,LOCK_49_3_4_0,LOCK_49_3_5_0,buf574_ptr,buf574d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf572_buf572d,LOCK_49_3_0_0,LOCK_49_3_1_0,buf572_ptr,buf572d_ptr,0,index, REL_WRITE);
    window_release(window_buf575_buf575d,LOCK_49_3_6_4096,LOCK_49_3_7_4096,buf575_ptr,buf575d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_3_bounds > 0)
      --proc_49_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}