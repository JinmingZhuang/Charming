// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_0/src/7_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_7_1_2_0 34
#define LOCK_7_1_3_4096 35
#define LOCK_7_0_0_0 48
#define LOCK_7_0_1_0 49
#define LOCK_7_1_4_0 36
#define LOCK_7_1_5_0 37

// Declare shared memory buffers
v4float buf60[256];
v4float buf60d[256];
v4float buf61[256];
v4float buf61d[256];
v4float buf62[256];
v4float buf62d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf60_buf60d[1];
  window_datatype * buf60_ptr = (window_datatype * )buf60;
  window_datatype * buf60d_ptr = (window_datatype * )buf60d;
  window_init(window_buf60_buf60d, 1, buf60, LOCK_7_1_2_0, buf60d, LOCK_7_1_3_4096, 256, 256);
  window_internal window_buf61_buf61d[1];
  window_datatype * buf61_ptr = (window_datatype * )buf61;
  window_datatype * buf61d_ptr = (window_datatype * )buf61d;
  window_init(window_buf61_buf61d, 1, buf61, LOCK_7_0_0_0, buf61d, LOCK_7_0_1_0, 256, 256);
  window_internal window_buf62_buf62d[1];
  window_datatype * buf62_ptr = (window_datatype * )buf62;
  window_datatype * buf62d_ptr = (window_datatype * )buf62d;
  window_init(window_buf62_buf62d, 1, buf62, LOCK_7_1_4_0, buf62d, LOCK_7_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_0_bounds = sync_buffer[1];

  while (proc_7_0_bounds)
  {

    // Kernel call : i112:mm_kernel0
    window_acquire(window_buf60_buf60d,LOCK_7_1_2_0,LOCK_7_1_3_4096,buf60_ptr,buf60d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf61_buf61d,LOCK_7_0_0_0,LOCK_7_0_1_0,buf61_ptr,buf61d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf62_buf62d,LOCK_7_1_4_0,LOCK_7_1_5_0,buf62_ptr,buf62d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf60_buf60d),get_input_window_float(window_buf61_buf61d),get_output_window_float(window_buf62_buf62d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf60_buf60d,LOCK_7_1_2_0,LOCK_7_1_3_4096,buf60_ptr,buf60d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf61_buf61d,LOCK_7_0_0_0,LOCK_7_0_1_0,buf61_ptr,buf61d_ptr,0,index, REL_WRITE);
    window_release(window_buf62_buf62d,LOCK_7_1_4_0,LOCK_7_1_5_0,buf62_ptr,buf62d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_0_bounds > 0)
      --proc_7_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}