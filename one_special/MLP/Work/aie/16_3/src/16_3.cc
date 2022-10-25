// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_3/src/16_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_3_0_0 48
#define LOCK_17_3_1_0 49
#define LOCK_16_4_0_0 32
#define LOCK_16_4_1_0 33
#define LOCK_16_3_2_0 18
#define LOCK_16_3_3_4096 19
#define LOCK_16_3_4_0 20
#define LOCK_16_3_5_0 21

// Declare shared memory buffers
v4float buf176[256];
v4float buf176d[256];
v4float buf177[256];
v4float buf177d[256];
v4float buf178[256];
v4float buf178d[256];
v4float buf179[256];
v4float buf179d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf177_buf177d[1];
  window_datatype * buf177_ptr = (window_datatype * )buf177;
  window_datatype * buf177d_ptr = (window_datatype * )buf177d;
  window_init(window_buf177_buf177d, 1, buf177, LOCK_17_3_0_0, buf177d, LOCK_17_3_1_0, 256, 256);
  window_internal window_buf178_buf178d[1];
  window_datatype * buf178_ptr = (window_datatype * )buf178;
  window_datatype * buf178d_ptr = (window_datatype * )buf178d;
  window_init(window_buf178_buf178d, 1, buf178, LOCK_16_4_0_0, buf178d, LOCK_16_4_1_0, 256, 256);
  window_internal window_buf176_buf176d[1];
  window_datatype * buf176_ptr = (window_datatype * )buf176;
  window_datatype * buf176d_ptr = (window_datatype * )buf176d;
  window_init(window_buf176_buf176d, 1, buf176, LOCK_16_3_2_0, buf176d, LOCK_16_3_3_4096, 256, 256);
  window_internal window_buf179_buf179d[1];
  window_datatype * buf179_ptr = (window_datatype * )buf179;
  window_datatype * buf179d_ptr = (window_datatype * )buf179d;
  window_init(window_buf179_buf179d, 1, buf179, LOCK_16_3_4_0, buf179d, LOCK_16_3_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_3_bounds = sync_buffer[1];

  while (proc_16_3_bounds)
  {

    // Kernel call : i169:mm_kernel1
    window_acquire(window_buf177_buf177d,LOCK_17_3_0_0,LOCK_17_3_1_0,buf177_ptr,buf177d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf178_buf178d,LOCK_16_4_0_0,LOCK_16_4_1_0,buf178_ptr,buf178d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf176_buf176d,LOCK_16_3_2_0,LOCK_16_3_3_4096,buf176_ptr,buf176d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf179_buf179d,LOCK_16_3_4_0,LOCK_16_3_5_0,buf179_ptr,buf179d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf177_buf177d),get_input_window_float(window_buf178_buf178d),get_input_window_float(window_buf176_buf176d),get_output_window_float(window_buf179_buf179d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf177_buf177d,LOCK_17_3_0_0,LOCK_17_3_1_0,buf177_ptr,buf177d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf178_buf178d,LOCK_16_4_0_0,LOCK_16_4_1_0,buf178_ptr,buf178d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf176_buf176d,LOCK_16_3_2_0,LOCK_16_3_3_4096,buf176_ptr,buf176d_ptr,0,index, REL_WRITE);
    window_release(window_buf179_buf179d,LOCK_16_3_4_0,LOCK_16_3_5_0,buf179_ptr,buf179d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_3_bounds > 0)
      --proc_16_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}