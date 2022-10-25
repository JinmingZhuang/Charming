// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_3/src/21_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_22_3_0_0 48
#define LOCK_22_3_1_0 49
#define LOCK_21_4_0_0 32
#define LOCK_21_4_1_0 33
#define LOCK_21_3_2_0 18
#define LOCK_21_3_3_4096 19
#define LOCK_21_3_4_4096 20
#define LOCK_21_3_5_4096 21

// Declare shared memory buffers
v4float buf236[256];
v4float buf236d[256];
v4float buf237[256];
v4float buf237d[256];
v4float buf238[256];
v4float buf238d[256];
v4float buf239[256];
v4float buf239d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf237_buf237d[1];
  window_datatype * buf237_ptr = (window_datatype * )buf237;
  window_datatype * buf237d_ptr = (window_datatype * )buf237d;
  window_init(window_buf237_buf237d, 1, buf237, LOCK_22_3_0_0, buf237d, LOCK_22_3_1_0, 256, 256);
  window_internal window_buf238_buf238d[1];
  window_datatype * buf238_ptr = (window_datatype * )buf238;
  window_datatype * buf238d_ptr = (window_datatype * )buf238d;
  window_init(window_buf238_buf238d, 1, buf238, LOCK_21_4_0_0, buf238d, LOCK_21_4_1_0, 256, 256);
  window_internal window_buf236_buf236d[1];
  window_datatype * buf236_ptr = (window_datatype * )buf236;
  window_datatype * buf236d_ptr = (window_datatype * )buf236d;
  window_init(window_buf236_buf236d, 1, buf236, LOCK_21_3_2_0, buf236d, LOCK_21_3_3_4096, 256, 256);
  window_internal window_buf239_buf239d[1];
  window_datatype * buf239_ptr = (window_datatype * )buf239;
  window_datatype * buf239d_ptr = (window_datatype * )buf239d;
  window_init(window_buf239_buf239d, 1, buf239, LOCK_21_3_4_4096, buf239d, LOCK_21_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_3_bounds = sync_buffer[1];

  while (proc_21_3_bounds)
  {

    // Kernel call : i199:mm_kernel1
    window_acquire(window_buf237_buf237d,LOCK_22_3_0_0,LOCK_22_3_1_0,buf237_ptr,buf237d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf238_buf238d,LOCK_21_4_0_0,LOCK_21_4_1_0,buf238_ptr,buf238d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf236_buf236d,LOCK_21_3_2_0,LOCK_21_3_3_4096,buf236_ptr,buf236d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf239_buf239d,LOCK_21_3_4_4096,LOCK_21_3_5_4096,buf239_ptr,buf239d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf237_buf237d),get_input_window_float(window_buf238_buf238d),get_input_window_float(window_buf236_buf236d),get_output_window_float(window_buf239_buf239d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf237_buf237d,LOCK_22_3_0_0,LOCK_22_3_1_0,buf237_ptr,buf237d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf238_buf238d,LOCK_21_4_0_0,LOCK_21_4_1_0,buf238_ptr,buf238d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf236_buf236d,LOCK_21_3_2_0,LOCK_21_3_3_4096,buf236_ptr,buf236d_ptr,0,index, REL_WRITE);
    window_release(window_buf239_buf239d,LOCK_21_3_4_4096,LOCK_21_3_5_4096,buf239_ptr,buf239d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_3_bounds > 0)
      --proc_21_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}