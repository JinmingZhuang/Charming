// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_1/src/46_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_0_0_0 0
#define LOCK_46_0_1_0 1
#define LOCK_46_2_0_0 32
#define LOCK_46_2_1_0 33
#define LOCK_46_1_4_0 20
#define LOCK_46_1_5_4096 21
#define LOCK_46_1_6_0 22
#define LOCK_46_1_7_4096 23

// Declare shared memory buffers
v4float buf530[256];
v4float buf530d[256];
v4float buf531[256];
v4float buf531d[256];
v4float buf532[256];
v4float buf532d[256];
v4float buf533[256];
v4float buf533d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf531_buf531d[1];
  window_datatype * buf531_ptr = (window_datatype * )buf531;
  window_datatype * buf531d_ptr = (window_datatype * )buf531d;
  window_init(window_buf531_buf531d, 1, buf531, LOCK_46_0_0_0, buf531d, LOCK_46_0_1_0, 256, 256);
  window_internal window_buf532_buf532d[1];
  window_datatype * buf532_ptr = (window_datatype * )buf532;
  window_datatype * buf532d_ptr = (window_datatype * )buf532d;
  window_init(window_buf532_buf532d, 1, buf532, LOCK_46_2_0_0, buf532d, LOCK_46_2_1_0, 256, 256);
  window_internal window_buf530_buf530d[1];
  window_datatype * buf530_ptr = (window_datatype * )buf530;
  window_datatype * buf530d_ptr = (window_datatype * )buf530d;
  window_init(window_buf530_buf530d, 1, buf530, LOCK_46_1_4_0, buf530d, LOCK_46_1_5_4096, 256, 256);
  window_internal window_buf533_buf533d[1];
  window_datatype * buf533_ptr = (window_datatype * )buf533;
  window_datatype * buf533d_ptr = (window_datatype * )buf533d;
  window_init(window_buf533_buf533d, 1, buf533, LOCK_46_1_6_0, buf533d, LOCK_46_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_1_bounds = sync_buffer[1];

  while (proc_46_1_bounds)
  {

    // Kernel call : i347:mm_kernel1
    window_acquire(window_buf531_buf531d,LOCK_46_0_0_0,LOCK_46_0_1_0,buf531_ptr,buf531d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf532_buf532d,LOCK_46_2_0_0,LOCK_46_2_1_0,buf532_ptr,buf532d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf530_buf530d,LOCK_46_1_4_0,LOCK_46_1_5_4096,buf530_ptr,buf530d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf533_buf533d,LOCK_46_1_6_0,LOCK_46_1_7_4096,buf533_ptr,buf533d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf531_buf531d),get_input_window_float(window_buf532_buf532d),get_input_window_float(window_buf530_buf530d),get_output_window_float(window_buf533_buf533d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf531_buf531d,LOCK_46_0_0_0,LOCK_46_0_1_0,buf531_ptr,buf531d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf532_buf532d,LOCK_46_2_0_0,LOCK_46_2_1_0,buf532_ptr,buf532d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf530_buf530d,LOCK_46_1_4_0,LOCK_46_1_5_4096,buf530_ptr,buf530d_ptr,0,index, REL_WRITE);
    window_release(window_buf533_buf533d,LOCK_46_1_6_0,LOCK_46_1_7_4096,buf533_ptr,buf533d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_1_bounds > 0)
      --proc_46_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}