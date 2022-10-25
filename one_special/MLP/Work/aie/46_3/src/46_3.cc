// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_3/src/46_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_2_4_0 4
#define LOCK_46_2_5_0 5
#define LOCK_47_3_0_0 48
#define LOCK_47_3_1_0 49
#define LOCK_46_2_2_4096 2
#define LOCK_46_2_3_4096 3
#define LOCK_46_2_6_4096 6
#define LOCK_46_2_7_4096 7

// Declare shared memory buffers
v4float buf536[256];
v4float buf536d[256];
v4float buf537[256];
v4float buf537d[256];
v4float buf538[256];
v4float buf538d[256];
v4float buf539[256];
v4float buf539d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf537_buf537d[1];
  window_datatype * buf537_ptr = (window_datatype * )buf537;
  window_datatype * buf537d_ptr = (window_datatype * )buf537d;
  window_init(window_buf537_buf537d, 1, buf537, LOCK_46_2_4_0, buf537d, LOCK_46_2_5_0, 256, 256);
  window_internal window_buf538_buf538d[1];
  window_datatype * buf538_ptr = (window_datatype * )buf538;
  window_datatype * buf538d_ptr = (window_datatype * )buf538d;
  window_init(window_buf538_buf538d, 1, buf538, LOCK_47_3_0_0, buf538d, LOCK_47_3_1_0, 256, 256);
  window_internal window_buf536_buf536d[1];
  window_datatype * buf536_ptr = (window_datatype * )buf536;
  window_datatype * buf536d_ptr = (window_datatype * )buf536d;
  window_init(window_buf536_buf536d, 1, buf536, LOCK_46_2_2_4096, buf536d, LOCK_46_2_3_4096, 256, 256);
  window_internal window_buf539_buf539d[1];
  window_datatype * buf539_ptr = (window_datatype * )buf539;
  window_datatype * buf539d_ptr = (window_datatype * )buf539d;
  window_init(window_buf539_buf539d, 1, buf539, LOCK_46_2_6_4096, buf539d, LOCK_46_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_3_bounds = sync_buffer[1];

  while (proc_46_3_bounds)
  {

    // Kernel call : i349:mm_kernel1
    window_acquire(window_buf537_buf537d,LOCK_46_2_4_0,LOCK_46_2_5_0,buf537_ptr,buf537d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf538_buf538d,LOCK_47_3_0_0,LOCK_47_3_1_0,buf538_ptr,buf538d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf536_buf536d,LOCK_46_2_2_4096,LOCK_46_2_3_4096,buf536_ptr,buf536d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf539_buf539d,LOCK_46_2_6_4096,LOCK_46_2_7_4096,buf539_ptr,buf539d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf537_buf537d),get_input_window_float(window_buf538_buf538d),get_input_window_float(window_buf536_buf536d),get_output_window_float(window_buf539_buf539d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf537_buf537d,LOCK_46_2_4_0,LOCK_46_2_5_0,buf537_ptr,buf537d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf538_buf538d,LOCK_47_3_0_0,LOCK_47_3_1_0,buf538_ptr,buf538d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf536_buf536d,LOCK_46_2_2_4096,LOCK_46_2_3_4096,buf536_ptr,buf536d_ptr,0,index, REL_WRITE);
    window_release(window_buf539_buf539d,LOCK_46_2_6_4096,LOCK_46_2_7_4096,buf539_ptr,buf539d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_3_bounds > 0)
      --proc_46_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}