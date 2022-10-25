// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_0/src/45_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_45_0_0_0 48
#define LOCK_45_0_1_0 49
#define LOCK_45_0_2_4096 50
#define LOCK_45_0_3_4096 51
#define LOCK_45_1_2_0 34
#define LOCK_45_1_3_4096 35

// Declare shared memory buffers
v4float buf516[256];
v4float buf516d[256];
v4float buf517[256];
v4float buf517d[256];
v4float buf518[256];
v4float buf518d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf516_buf516d[1];
  window_datatype * buf516_ptr = (window_datatype * )buf516;
  window_datatype * buf516d_ptr = (window_datatype * )buf516d;
  window_init(window_buf516_buf516d, 1, buf516, LOCK_45_0_0_0, buf516d, LOCK_45_0_1_0, 256, 256);
  window_internal window_buf517_buf517d[1];
  window_datatype * buf517_ptr = (window_datatype * )buf517;
  window_datatype * buf517d_ptr = (window_datatype * )buf517d;
  window_init(window_buf517_buf517d, 1, buf517, LOCK_45_0_2_4096, buf517d, LOCK_45_0_3_4096, 256, 256);
  window_internal window_buf518_buf518d[1];
  window_datatype * buf518_ptr = (window_datatype * )buf518;
  window_datatype * buf518d_ptr = (window_datatype * )buf518d;
  window_init(window_buf518_buf518d, 1, buf518, LOCK_45_1_2_0, buf518d, LOCK_45_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_0_bounds = sync_buffer[1];

  while (proc_45_0_bounds)
  {

    // Kernel call : i340:mm_kernel0
    window_acquire(window_buf516_buf516d,LOCK_45_0_0_0,LOCK_45_0_1_0,buf516_ptr,buf516d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf517_buf517d,LOCK_45_0_2_4096,LOCK_45_0_3_4096,buf517_ptr,buf517d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf518_buf518d,LOCK_45_1_2_0,LOCK_45_1_3_4096,buf518_ptr,buf518d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf516_buf516d),get_input_window_float(window_buf517_buf517d),get_output_window_float(window_buf518_buf518d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf516_buf516d,LOCK_45_0_0_0,LOCK_45_0_1_0,buf516_ptr,buf516d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf517_buf517d,LOCK_45_0_2_4096,LOCK_45_0_3_4096,buf517_ptr,buf517d_ptr,0,index, REL_WRITE);
    window_release(window_buf518_buf518d,LOCK_45_1_2_0,LOCK_45_1_3_4096,buf518_ptr,buf518d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_0_bounds > 0)
      --proc_45_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}