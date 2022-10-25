// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_4/src/27_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_3_2_4096 2
#define LOCK_27_3_3_4096 3
#define LOCK_26_4_2_4096 18
#define LOCK_26_4_3_4096 19
#define LOCK_27_5_0_4096 32
#define LOCK_27_5_1_4096 33

// Declare shared memory buffers
v4float buf840[256];
v4float buf840d[256];
v4float buf841[256];
v4float buf841d[256];
v4float buf842[256];
v4float buf842d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf840_buf840d[1];
  window_datatype * buf840_ptr = (window_datatype * )buf840;
  window_datatype * buf840d_ptr = (window_datatype * )buf840d;
  window_init(window_buf840_buf840d, 1, buf840, LOCK_27_3_2_4096, buf840d, LOCK_27_3_3_4096, 256, 256);
  window_internal window_buf841_buf841d[1];
  window_datatype * buf841_ptr = (window_datatype * )buf841;
  window_datatype * buf841d_ptr = (window_datatype * )buf841d;
  window_init(window_buf841_buf841d, 1, buf841, LOCK_26_4_2_4096, buf841d, LOCK_26_4_3_4096, 256, 256);
  window_internal window_buf842_buf842d[1];
  window_datatype * buf842_ptr = (window_datatype * )buf842;
  window_datatype * buf842d_ptr = (window_datatype * )buf842d;
  window_init(window_buf842_buf842d, 1, buf842, LOCK_27_5_0_4096, buf842d, LOCK_27_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_4_bounds = sync_buffer[1];

  while (proc_27_4_bounds)
  {

    // Kernel call : i502:mm_kernel0
    window_acquire(window_buf840_buf840d,LOCK_27_3_2_4096,LOCK_27_3_3_4096,buf840_ptr,buf840d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf841_buf841d,LOCK_26_4_2_4096,LOCK_26_4_3_4096,buf841_ptr,buf841d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf842_buf842d,LOCK_27_5_0_4096,LOCK_27_5_1_4096,buf842_ptr,buf842d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf840_buf840d),get_input_window_float(window_buf841_buf841d),get_output_window_float(window_buf842_buf842d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf840_buf840d,LOCK_27_3_2_4096,LOCK_27_3_3_4096,buf840_ptr,buf840d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf841_buf841d,LOCK_26_4_2_4096,LOCK_26_4_3_4096,buf841_ptr,buf841d_ptr,0,index, REL_WRITE);
    window_release(window_buf842_buf842d,LOCK_27_5_0_4096,LOCK_27_5_1_4096,buf842_ptr,buf842d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_4_bounds > 0)
      --proc_27_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}