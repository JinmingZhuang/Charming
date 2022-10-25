// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_7/src/49_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_7_0_0 16
#define LOCK_49_7_1_0 17
#define LOCK_49_7_2_4096 18
#define LOCK_49_7_3_4096 19
#define LOCK_49_6_4_4096 4
#define LOCK_49_6_5_0 5
#define LOCK_49_6_6_4096 6
#define LOCK_49_6_7_0 7

// Declare shared memory buffers
v4float buf584[256];
v4float buf584d[256];
v4float buf585[256];
v4float buf585d[256];
v4float buf586[256];
v4float buf586d[256];
v4float buf587[256];
v4float buf587d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf585_buf585d[1];
  window_datatype * buf585_ptr = (window_datatype * )buf585;
  window_datatype * buf585d_ptr = (window_datatype * )buf585d;
  window_init(window_buf585_buf585d, 1, buf585, LOCK_49_7_0_0, buf585d, LOCK_49_7_1_0, 256, 256);
  window_internal window_buf586_buf586d[1];
  window_datatype * buf586_ptr = (window_datatype * )buf586;
  window_datatype * buf586d_ptr = (window_datatype * )buf586d;
  window_init(window_buf586_buf586d, 1, buf586, LOCK_49_7_2_4096, buf586d, LOCK_49_7_3_4096, 256, 256);
  window_internal window_buf584_buf584d[1];
  window_datatype * buf584_ptr = (window_datatype * )buf584;
  window_datatype * buf584d_ptr = (window_datatype * )buf584d;
  window_init(window_buf584_buf584d, 1, buf584, LOCK_49_6_4_4096, buf584d, LOCK_49_6_5_0, 256, 256);
  window_internal window_buf587_buf587d[1];
  window_datatype * buf587_ptr = (window_datatype * )buf587;
  window_datatype * buf587d_ptr = (window_datatype * )buf587d;
  window_init(window_buf587_buf587d, 1, buf587, LOCK_49_6_6_4096, buf587d, LOCK_49_6_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_7_bounds = sync_buffer[1];

  while (proc_49_7_bounds)
  {

    // Kernel call : i373:mm_kernel1
    window_acquire(window_buf585_buf585d,LOCK_49_7_0_0,LOCK_49_7_1_0,buf585_ptr,buf585d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf586_buf586d,LOCK_49_7_2_4096,LOCK_49_7_3_4096,buf586_ptr,buf586d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf584_buf584d,LOCK_49_6_4_4096,LOCK_49_6_5_0,buf584_ptr,buf584d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf587_buf587d,LOCK_49_6_6_4096,LOCK_49_6_7_0,buf587_ptr,buf587d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf585_buf585d),get_input_window_float(window_buf586_buf586d),get_input_window_float(window_buf584_buf584d),get_output_window_float(window_buf587_buf587d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf585_buf585d,LOCK_49_7_0_0,LOCK_49_7_1_0,buf585_ptr,buf585d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf586_buf586d,LOCK_49_7_2_4096,LOCK_49_7_3_4096,buf586_ptr,buf586d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf584_buf584d,LOCK_49_6_4_4096,LOCK_49_6_5_0,buf584_ptr,buf584d_ptr,0,index, REL_WRITE);
    window_release(window_buf587_buf587d,LOCK_49_6_6_4096,LOCK_49_6_7_0,buf587_ptr,buf587d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_7_bounds > 0)
      --proc_49_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}