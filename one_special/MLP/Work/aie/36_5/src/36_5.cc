// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_5/src/36_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_5_2_4096 18
#define LOCK_36_5_3_4096 19
#define LOCK_36_5_4_0 20
#define LOCK_36_5_5_0 21
#define LOCK_36_5_0_0 16
#define LOCK_36_5_1_0 17
#define LOCK_36_5_6_4096 22
#define LOCK_36_5_7_4096 23

// Declare shared memory buffers
v4float buf734[256];
v4float buf734d[256];
v4float buf735[256];
v4float buf735d[256];
v4float buf736[256];
v4float buf736d[256];
v4float buf737[256];
v4float buf737d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf735_buf735d[1];
  window_datatype * buf735_ptr = (window_datatype * )buf735;
  window_datatype * buf735d_ptr = (window_datatype * )buf735d;
  window_init(window_buf735_buf735d, 1, buf735, LOCK_36_5_2_4096, buf735d, LOCK_36_5_3_4096, 256, 256);
  window_internal window_buf736_buf736d[1];
  window_datatype * buf736_ptr = (window_datatype * )buf736;
  window_datatype * buf736d_ptr = (window_datatype * )buf736d;
  window_init(window_buf736_buf736d, 1, buf736, LOCK_36_5_4_0, buf736d, LOCK_36_5_5_0, 256, 256);
  window_internal window_buf734_buf734d[1];
  window_datatype * buf734_ptr = (window_datatype * )buf734;
  window_datatype * buf734d_ptr = (window_datatype * )buf734d;
  window_init(window_buf734_buf734d, 1, buf734, LOCK_36_5_0_0, buf734d, LOCK_36_5_1_0, 256, 256);
  window_internal window_buf737_buf737d[1];
  window_datatype * buf737_ptr = (window_datatype * )buf737;
  window_datatype * buf737d_ptr = (window_datatype * )buf737d;
  window_init(window_buf737_buf737d, 1, buf737, LOCK_36_5_6_4096, buf737d, LOCK_36_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_5_bounds = sync_buffer[1];

  while (proc_36_5_bounds)
  {

    // Kernel call : i449:mm_kernel1
    window_acquire(window_buf735_buf735d,LOCK_36_5_2_4096,LOCK_36_5_3_4096,buf735_ptr,buf735d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf736_buf736d,LOCK_36_5_4_0,LOCK_36_5_5_0,buf736_ptr,buf736d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf734_buf734d,LOCK_36_5_0_0,LOCK_36_5_1_0,buf734_ptr,buf734d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf737_buf737d,LOCK_36_5_6_4096,LOCK_36_5_7_4096,buf737_ptr,buf737d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf735_buf735d),get_input_window_float(window_buf736_buf736d),get_input_window_float(window_buf734_buf734d),get_output_window_float(window_buf737_buf737d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf735_buf735d,LOCK_36_5_2_4096,LOCK_36_5_3_4096,buf735_ptr,buf735d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf736_buf736d,LOCK_36_5_4_0,LOCK_36_5_5_0,buf736_ptr,buf736d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf734_buf734d,LOCK_36_5_0_0,LOCK_36_5_1_0,buf734_ptr,buf734d_ptr,0,index, REL_WRITE);
    window_release(window_buf737_buf737d,LOCK_36_5_6_4096,LOCK_36_5_7_4096,buf737_ptr,buf737d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_5_bounds > 0)
      --proc_36_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}