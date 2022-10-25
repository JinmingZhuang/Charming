// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/10_0/src/10_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_10_0_0_0 48
#define LOCK_10_0_1_0 49
#define LOCK_10_1_0_4096 32
#define LOCK_10_1_1_0 33
#define LOCK_10_1_2_0 34
#define LOCK_10_1_3_4096 35

// Declare shared memory buffers
v4float buf96[256];
v4float buf96d[256];
v4float buf97[256];
v4float buf97d[256];
v4float buf98[256];
v4float buf98d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf96_buf96d[1];
  window_datatype * buf96_ptr = (window_datatype * )buf96;
  window_datatype * buf96d_ptr = (window_datatype * )buf96d;
  window_init(window_buf96_buf96d, 1, buf96, LOCK_10_0_0_0, buf96d, LOCK_10_0_1_0, 256, 256);
  window_internal window_buf97_buf97d[1];
  window_datatype * buf97_ptr = (window_datatype * )buf97;
  window_datatype * buf97d_ptr = (window_datatype * )buf97d;
  window_init(window_buf97_buf97d, 1, buf97, LOCK_10_1_0_4096, buf97d, LOCK_10_1_1_0, 256, 256);
  window_internal window_buf98_buf98d[1];
  window_datatype * buf98_ptr = (window_datatype * )buf98;
  window_datatype * buf98d_ptr = (window_datatype * )buf98d;
  window_init(window_buf98_buf98d, 1, buf98, LOCK_10_1_2_0, buf98d, LOCK_10_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_10_0_bounds = sync_buffer[1];

  while (proc_10_0_bounds)
  {

    // Kernel call : i130:mm_kernel0
    window_acquire(window_buf96_buf96d,LOCK_10_0_0_0,LOCK_10_0_1_0,buf96_ptr,buf96d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf97_buf97d,LOCK_10_1_0_4096,LOCK_10_1_1_0,buf97_ptr,buf97d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf98_buf98d,LOCK_10_1_2_0,LOCK_10_1_3_4096,buf98_ptr,buf98d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf96_buf96d),get_input_window_float(window_buf97_buf97d),get_output_window_float(window_buf98_buf98d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf96_buf96d,LOCK_10_0_0_0,LOCK_10_0_1_0,buf96_ptr,buf96d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf97_buf97d,LOCK_10_1_0_4096,LOCK_10_1_1_0,buf97_ptr,buf97d_ptr,0,index, REL_WRITE);
    window_release(window_buf98_buf98d,LOCK_10_1_2_0,LOCK_10_1_3_4096,buf98_ptr,buf98d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_10_0_bounds > 0)
      --proc_10_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}