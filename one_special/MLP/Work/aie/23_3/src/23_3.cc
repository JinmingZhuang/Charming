// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_3/src/23_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_3_0_0 16
#define LOCK_23_3_1_0 17
#define LOCK_24_3_0_0 48
#define LOCK_24_3_1_0 49
#define LOCK_23_2_4_0 4
#define LOCK_23_2_5_4096 5
#define LOCK_23_2_6_4096 6
#define LOCK_23_2_7_4096 7

// Declare shared memory buffers
v4float buf260[256];
v4float buf260d[256];
v4float buf261[256];
v4float buf261d[256];
v4float buf262[256];
v4float buf262d[256];
v4float buf263[256];
v4float buf263d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf261_buf261d[1];
  window_datatype * buf261_ptr = (window_datatype * )buf261;
  window_datatype * buf261d_ptr = (window_datatype * )buf261d;
  window_init(window_buf261_buf261d, 1, buf261, LOCK_23_3_0_0, buf261d, LOCK_23_3_1_0, 256, 256);
  window_internal window_buf262_buf262d[1];
  window_datatype * buf262_ptr = (window_datatype * )buf262;
  window_datatype * buf262d_ptr = (window_datatype * )buf262d;
  window_init(window_buf262_buf262d, 1, buf262, LOCK_24_3_0_0, buf262d, LOCK_24_3_1_0, 256, 256);
  window_internal window_buf260_buf260d[1];
  window_datatype * buf260_ptr = (window_datatype * )buf260;
  window_datatype * buf260d_ptr = (window_datatype * )buf260d;
  window_init(window_buf260_buf260d, 1, buf260, LOCK_23_2_4_0, buf260d, LOCK_23_2_5_4096, 256, 256);
  window_internal window_buf263_buf263d[1];
  window_datatype * buf263_ptr = (window_datatype * )buf263;
  window_datatype * buf263d_ptr = (window_datatype * )buf263d;
  window_init(window_buf263_buf263d, 1, buf263, LOCK_23_2_6_4096, buf263d, LOCK_23_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_3_bounds = sync_buffer[1];

  while (proc_23_3_bounds)
  {

    // Kernel call : i211:mm_kernel1
    window_acquire(window_buf261_buf261d,LOCK_23_3_0_0,LOCK_23_3_1_0,buf261_ptr,buf261d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf262_buf262d,LOCK_24_3_0_0,LOCK_24_3_1_0,buf262_ptr,buf262d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf260_buf260d,LOCK_23_2_4_0,LOCK_23_2_5_4096,buf260_ptr,buf260d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf263_buf263d,LOCK_23_2_6_4096,LOCK_23_2_7_4096,buf263_ptr,buf263d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf261_buf261d),get_input_window_float(window_buf262_buf262d),get_input_window_float(window_buf260_buf260d),get_output_window_float(window_buf263_buf263d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf261_buf261d,LOCK_23_3_0_0,LOCK_23_3_1_0,buf261_ptr,buf261d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf262_buf262d,LOCK_24_3_0_0,LOCK_24_3_1_0,buf262_ptr,buf262d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf260_buf260d,LOCK_23_2_4_0,LOCK_23_2_5_4096,buf260_ptr,buf260d_ptr,0,index, REL_WRITE);
    window_release(window_buf263_buf263d,LOCK_23_2_6_4096,LOCK_23_2_7_4096,buf263_ptr,buf263d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_3_bounds > 0)
      --proc_23_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}