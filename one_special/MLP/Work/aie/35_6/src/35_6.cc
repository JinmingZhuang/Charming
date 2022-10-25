// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_6/src/35_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_6_0_0 48
#define LOCK_35_6_1_0 49
#define LOCK_35_6_2_0 50
#define LOCK_35_6_3_4096 51
#define LOCK_35_5_4_0 4
#define LOCK_35_5_5_0 5
#define LOCK_35_6_4_4096 52
#define LOCK_35_6_5_4096 53

// Declare shared memory buffers
v4float buf749[256];
v4float buf749d[256];
v4float buf750[256];
v4float buf750d[256];
v4float buf751[256];
v4float buf751d[256];
v4float buf752[256];
v4float buf752d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf750_buf750d[1];
  window_datatype * buf750_ptr = (window_datatype * )buf750;
  window_datatype * buf750d_ptr = (window_datatype * )buf750d;
  window_init(window_buf750_buf750d, 1, buf750, LOCK_35_6_0_0, buf750d, LOCK_35_6_1_0, 256, 256);
  window_internal window_buf751_buf751d[1];
  window_datatype * buf751_ptr = (window_datatype * )buf751;
  window_datatype * buf751d_ptr = (window_datatype * )buf751d;
  window_init(window_buf751_buf751d, 1, buf751, LOCK_35_6_2_0, buf751d, LOCK_35_6_3_4096, 256, 256);
  window_internal window_buf749_buf749d[1];
  window_datatype * buf749_ptr = (window_datatype * )buf749;
  window_datatype * buf749d_ptr = (window_datatype * )buf749d;
  window_init(window_buf749_buf749d, 1, buf749, LOCK_35_5_4_0, buf749d, LOCK_35_5_5_0, 256, 256);
  window_internal window_buf752_buf752d[1];
  window_datatype * buf752_ptr = (window_datatype * )buf752;
  window_datatype * buf752d_ptr = (window_datatype * )buf752d;
  window_init(window_buf752_buf752d, 1, buf752, LOCK_35_6_4_4096, buf752d, LOCK_35_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_6_bounds = sync_buffer[1];

  while (proc_35_6_bounds)
  {

    // Kernel call : i456:mm_kernel1
    window_acquire(window_buf750_buf750d,LOCK_35_6_0_0,LOCK_35_6_1_0,buf750_ptr,buf750d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf751_buf751d,LOCK_35_6_2_0,LOCK_35_6_3_4096,buf751_ptr,buf751d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf749_buf749d,LOCK_35_5_4_0,LOCK_35_5_5_0,buf749_ptr,buf749d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf752_buf752d,LOCK_35_6_4_4096,LOCK_35_6_5_4096,buf752_ptr,buf752d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf750_buf750d),get_input_window_float(window_buf751_buf751d),get_input_window_float(window_buf749_buf749d),get_output_window_float(window_buf752_buf752d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf750_buf750d,LOCK_35_6_0_0,LOCK_35_6_1_0,buf750_ptr,buf750d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf751_buf751d,LOCK_35_6_2_0,LOCK_35_6_3_4096,buf751_ptr,buf751d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf749_buf749d,LOCK_35_5_4_0,LOCK_35_5_5_0,buf749_ptr,buf749d_ptr,0,index, REL_WRITE);
    window_release(window_buf752_buf752d,LOCK_35_6_4_4096,LOCK_35_6_5_4096,buf752_ptr,buf752d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_6_bounds > 0)
      --proc_35_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}