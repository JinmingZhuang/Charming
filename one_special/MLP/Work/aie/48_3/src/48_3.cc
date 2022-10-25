// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_3/src/48_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_2_2_4096 2
#define LOCK_48_2_3_4096 3
#define LOCK_48_2_4_0 4
#define LOCK_48_2_5_0 5
#define LOCK_48_2_0_0 0
#define LOCK_48_2_1_0 1
#define LOCK_48_2_6_4096 6
#define LOCK_48_2_7_4096 7

// Declare shared memory buffers
v4float buf560[256];
v4float buf560d[256];
v4float buf561[256];
v4float buf561d[256];
v4float buf562[256];
v4float buf562d[256];
v4float buf563[256];
v4float buf563d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf561_buf561d[1];
  window_datatype * buf561_ptr = (window_datatype * )buf561;
  window_datatype * buf561d_ptr = (window_datatype * )buf561d;
  window_init(window_buf561_buf561d, 1, buf561, LOCK_48_2_2_4096, buf561d, LOCK_48_2_3_4096, 256, 256);
  window_internal window_buf562_buf562d[1];
  window_datatype * buf562_ptr = (window_datatype * )buf562;
  window_datatype * buf562d_ptr = (window_datatype * )buf562d;
  window_init(window_buf562_buf562d, 1, buf562, LOCK_48_2_4_0, buf562d, LOCK_48_2_5_0, 256, 256);
  window_internal window_buf560_buf560d[1];
  window_datatype * buf560_ptr = (window_datatype * )buf560;
  window_datatype * buf560d_ptr = (window_datatype * )buf560d;
  window_init(window_buf560_buf560d, 1, buf560, LOCK_48_2_0_0, buf560d, LOCK_48_2_1_0, 256, 256);
  window_internal window_buf563_buf563d[1];
  window_datatype * buf563_ptr = (window_datatype * )buf563;
  window_datatype * buf563d_ptr = (window_datatype * )buf563d;
  window_init(window_buf563_buf563d, 1, buf563, LOCK_48_2_6_4096, buf563d, LOCK_48_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_3_bounds = sync_buffer[1];

  while (proc_48_3_bounds)
  {

    // Kernel call : i361:mm_kernel1
    window_acquire(window_buf561_buf561d,LOCK_48_2_2_4096,LOCK_48_2_3_4096,buf561_ptr,buf561d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf562_buf562d,LOCK_48_2_4_0,LOCK_48_2_5_0,buf562_ptr,buf562d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf560_buf560d,LOCK_48_2_0_0,LOCK_48_2_1_0,buf560_ptr,buf560d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf563_buf563d,LOCK_48_2_6_4096,LOCK_48_2_7_4096,buf563_ptr,buf563d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf561_buf561d),get_input_window_float(window_buf562_buf562d),get_input_window_float(window_buf560_buf560d),get_output_window_float(window_buf563_buf563d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf561_buf561d,LOCK_48_2_2_4096,LOCK_48_2_3_4096,buf561_ptr,buf561d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf562_buf562d,LOCK_48_2_4_0,LOCK_48_2_5_0,buf562_ptr,buf562d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf560_buf560d,LOCK_48_2_0_0,LOCK_48_2_1_0,buf560_ptr,buf560d_ptr,0,index, REL_WRITE);
    window_release(window_buf563_buf563d,LOCK_48_2_6_4096,LOCK_48_2_7_4096,buf563_ptr,buf563d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_3_bounds > 0)
      --proc_48_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}