// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_0/src/18_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_1_0_4096 32
#define LOCK_18_1_1_4096 33
#define LOCK_18_1_2_0 34
#define LOCK_18_1_3_4096 35
#define LOCK_18_1_4_0 36
#define LOCK_18_1_5_0 37

// Declare shared memory buffers
v4float buf192[256];
v4float buf192d[256];
v4float buf193[256];
v4float buf193d[256];
v4float buf194[256];
v4float buf194d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf192_buf192d[1];
  window_datatype * buf192_ptr = (window_datatype * )buf192;
  window_datatype * buf192d_ptr = (window_datatype * )buf192d;
  window_init(window_buf192_buf192d, 1, buf192, LOCK_18_1_0_4096, buf192d, LOCK_18_1_1_4096, 256, 256);
  window_internal window_buf193_buf193d[1];
  window_datatype * buf193_ptr = (window_datatype * )buf193;
  window_datatype * buf193d_ptr = (window_datatype * )buf193d;
  window_init(window_buf193_buf193d, 1, buf193, LOCK_18_1_2_0, buf193d, LOCK_18_1_3_4096, 256, 256);
  window_internal window_buf194_buf194d[1];
  window_datatype * buf194_ptr = (window_datatype * )buf194;
  window_datatype * buf194d_ptr = (window_datatype * )buf194d;
  window_init(window_buf194_buf194d, 1, buf194, LOCK_18_1_4_0, buf194d, LOCK_18_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_0_bounds = sync_buffer[1];

  while (proc_18_0_bounds)
  {

    // Kernel call : i178:mm_kernel0
    window_acquire(window_buf192_buf192d,LOCK_18_1_0_4096,LOCK_18_1_1_4096,buf192_ptr,buf192d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf193_buf193d,LOCK_18_1_2_0,LOCK_18_1_3_4096,buf193_ptr,buf193d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf194_buf194d,LOCK_18_1_4_0,LOCK_18_1_5_0,buf194_ptr,buf194d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf192_buf192d),get_input_window_float(window_buf193_buf193d),get_output_window_float(window_buf194_buf194d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf192_buf192d,LOCK_18_1_0_4096,LOCK_18_1_1_4096,buf192_ptr,buf192d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf193_buf193d,LOCK_18_1_2_0,LOCK_18_1_3_4096,buf193_ptr,buf193d_ptr,0,index, REL_WRITE);
    window_release(window_buf194_buf194d,LOCK_18_1_4_0,LOCK_18_1_5_0,buf194_ptr,buf194d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_0_bounds > 0)
      --proc_18_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}