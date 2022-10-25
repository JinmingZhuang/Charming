// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_7/src/33_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_6_0_0 0
#define LOCK_33_6_1_0 1
#define LOCK_33_6_2_4096 2
#define LOCK_33_6_3_4096 3
#define LOCK_33_7_2_4096 18
#define LOCK_33_7_3_4096 19
#define LOCK_33_7_4_4096 20
#define LOCK_33_7_5_0 21

// Declare shared memory buffers
v4float buf776[256];
v4float buf776d[256];
v4float buf777[256];
v4float buf777d[256];
v4float buf778[256];
v4float buf778d[256];
v4float buf779[256];
v4float buf779d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf777_buf777d[1];
  window_datatype * buf777_ptr = (window_datatype * )buf777;
  window_datatype * buf777d_ptr = (window_datatype * )buf777d;
  window_init(window_buf777_buf777d, 1, buf777, LOCK_33_6_0_0, buf777d, LOCK_33_6_1_0, 256, 256);
  window_internal window_buf778_buf778d[1];
  window_datatype * buf778_ptr = (window_datatype * )buf778;
  window_datatype * buf778d_ptr = (window_datatype * )buf778d;
  window_init(window_buf778_buf778d, 1, buf778, LOCK_33_6_2_4096, buf778d, LOCK_33_6_3_4096, 256, 256);
  window_internal window_buf776_buf776d[1];
  window_datatype * buf776_ptr = (window_datatype * )buf776;
  window_datatype * buf776d_ptr = (window_datatype * )buf776d;
  window_init(window_buf776_buf776d, 1, buf776, LOCK_33_7_2_4096, buf776d, LOCK_33_7_3_4096, 256, 256);
  window_internal window_buf779_buf779d[1];
  window_datatype * buf779_ptr = (window_datatype * )buf779;
  window_datatype * buf779d_ptr = (window_datatype * )buf779d;
  window_init(window_buf779_buf779d, 1, buf779, LOCK_33_7_4_4096, buf779d, LOCK_33_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_7_bounds = sync_buffer[1];

  while (proc_33_7_bounds)
  {

    // Kernel call : i469:mm_kernel1
    window_acquire(window_buf777_buf777d,LOCK_33_6_0_0,LOCK_33_6_1_0,buf777_ptr,buf777d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf778_buf778d,LOCK_33_6_2_4096,LOCK_33_6_3_4096,buf778_ptr,buf778d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf776_buf776d,LOCK_33_7_2_4096,LOCK_33_7_3_4096,buf776_ptr,buf776d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf779_buf779d,LOCK_33_7_4_4096,LOCK_33_7_5_0,buf779_ptr,buf779d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf777_buf777d),get_input_window_float(window_buf778_buf778d),get_input_window_float(window_buf776_buf776d),get_output_window_float(window_buf779_buf779d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf777_buf777d,LOCK_33_6_0_0,LOCK_33_6_1_0,buf777_ptr,buf777d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf778_buf778d,LOCK_33_6_2_4096,LOCK_33_6_3_4096,buf778_ptr,buf778d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf776_buf776d,LOCK_33_7_2_4096,LOCK_33_7_3_4096,buf776_ptr,buf776d_ptr,0,index, REL_WRITE);
    window_release(window_buf779_buf779d,LOCK_33_7_4_4096,LOCK_33_7_5_0,buf779_ptr,buf779d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_7_bounds > 0)
      --proc_33_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}