// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_4/src/12_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_5_0_0 32
#define LOCK_12_5_1_4096 33
#define LOCK_12_4_2_4096 50
#define LOCK_12_4_3_4096 51
#define LOCK_12_5_2_4096 34
#define LOCK_12_5_3_0 35

// Declare shared memory buffers
v4float buf1020[256];
v4float buf1020d[256];
v4float buf1021[256];
v4float buf1021d[256];
v4float buf1022[256];
v4float buf1022d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1020_buf1020d[1];
  window_datatype * buf1020_ptr = (window_datatype * )buf1020;
  window_datatype * buf1020d_ptr = (window_datatype * )buf1020d;
  window_init(window_buf1020_buf1020d, 1, buf1020, LOCK_12_5_0_0, buf1020d, LOCK_12_5_1_4096, 256, 256);
  window_internal window_buf1021_buf1021d[1];
  window_datatype * buf1021_ptr = (window_datatype * )buf1021;
  window_datatype * buf1021d_ptr = (window_datatype * )buf1021d;
  window_init(window_buf1021_buf1021d, 1, buf1021, LOCK_12_4_2_4096, buf1021d, LOCK_12_4_3_4096, 256, 256);
  window_internal window_buf1022_buf1022d[1];
  window_datatype * buf1022_ptr = (window_datatype * )buf1022;
  window_datatype * buf1022d_ptr = (window_datatype * )buf1022d;
  window_init(window_buf1022_buf1022d, 1, buf1022, LOCK_12_5_2_4096, buf1022d, LOCK_12_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_4_bounds = sync_buffer[1];

  while (proc_12_4_bounds)
  {

    // Kernel call : i592:mm_kernel0
    window_acquire(window_buf1020_buf1020d,LOCK_12_5_0_0,LOCK_12_5_1_4096,buf1020_ptr,buf1020d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1021_buf1021d,LOCK_12_4_2_4096,LOCK_12_4_3_4096,buf1021_ptr,buf1021d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1022_buf1022d,LOCK_12_5_2_4096,LOCK_12_5_3_0,buf1022_ptr,buf1022d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1020_buf1020d),get_input_window_float(window_buf1021_buf1021d),get_output_window_float(window_buf1022_buf1022d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1020_buf1020d,LOCK_12_5_0_0,LOCK_12_5_1_4096,buf1020_ptr,buf1020d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1021_buf1021d,LOCK_12_4_2_4096,LOCK_12_4_3_4096,buf1021_ptr,buf1021d_ptr,0,index, REL_WRITE);
    window_release(window_buf1022_buf1022d,LOCK_12_5_2_4096,LOCK_12_5_3_0,buf1022_ptr,buf1022d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_4_bounds > 0)
      --proc_12_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}