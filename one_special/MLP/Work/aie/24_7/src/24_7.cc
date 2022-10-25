// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_7/src/24_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_7_2_4096 18
#define LOCK_24_7_3_4096 19
#define LOCK_24_6_2_4096 2
#define LOCK_24_6_3_4096 3
#define LOCK_24_7_0_0 16
#define LOCK_24_7_1_0 17
#define LOCK_24_7_4_0 20
#define LOCK_24_7_5_0 21

// Declare shared memory buffers
v4float buf884[256];
v4float buf884d[256];
v4float buf885[256];
v4float buf885d[256];
v4float buf886[256];
v4float buf886d[256];
v4float buf887[256];
v4float buf887d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf885_buf885d[1];
  window_datatype * buf885_ptr = (window_datatype * )buf885;
  window_datatype * buf885d_ptr = (window_datatype * )buf885d;
  window_init(window_buf885_buf885d, 1, buf885, LOCK_24_7_2_4096, buf885d, LOCK_24_7_3_4096, 256, 256);
  window_internal window_buf886_buf886d[1];
  window_datatype * buf886_ptr = (window_datatype * )buf886;
  window_datatype * buf886d_ptr = (window_datatype * )buf886d;
  window_init(window_buf886_buf886d, 1, buf886, LOCK_24_6_2_4096, buf886d, LOCK_24_6_3_4096, 256, 256);
  window_internal window_buf884_buf884d[1];
  window_datatype * buf884_ptr = (window_datatype * )buf884;
  window_datatype * buf884d_ptr = (window_datatype * )buf884d;
  window_init(window_buf884_buf884d, 1, buf884, LOCK_24_7_0_0, buf884d, LOCK_24_7_1_0, 256, 256);
  window_internal window_buf887_buf887d[1];
  window_datatype * buf887_ptr = (window_datatype * )buf887;
  window_datatype * buf887d_ptr = (window_datatype * )buf887d;
  window_init(window_buf887_buf887d, 1, buf887, LOCK_24_7_4_0, buf887d, LOCK_24_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_7_bounds = sync_buffer[1];

  while (proc_24_7_bounds)
  {

    // Kernel call : i523:mm_kernel1
    window_acquire(window_buf885_buf885d,LOCK_24_7_2_4096,LOCK_24_7_3_4096,buf885_ptr,buf885d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf886_buf886d,LOCK_24_6_2_4096,LOCK_24_6_3_4096,buf886_ptr,buf886d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf884_buf884d,LOCK_24_7_0_0,LOCK_24_7_1_0,buf884_ptr,buf884d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf887_buf887d,LOCK_24_7_4_0,LOCK_24_7_5_0,buf887_ptr,buf887d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf885_buf885d),get_input_window_float(window_buf886_buf886d),get_input_window_float(window_buf884_buf884d),get_output_window_float(window_buf887_buf887d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf885_buf885d,LOCK_24_7_2_4096,LOCK_24_7_3_4096,buf885_ptr,buf885d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf886_buf886d,LOCK_24_6_2_4096,LOCK_24_6_3_4096,buf886_ptr,buf886d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf884_buf884d,LOCK_24_7_0_0,LOCK_24_7_1_0,buf884_ptr,buf884d_ptr,0,index, REL_WRITE);
    window_release(window_buf887_buf887d,LOCK_24_7_4_0,LOCK_24_7_5_0,buf887_ptr,buf887d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_7_bounds > 0)
      --proc_24_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}