// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_4/src/46_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_5_0_0 32
#define LOCK_46_5_1_0 33
#define LOCK_46_5_2_4096 34
#define LOCK_46_5_3_0 35
#define LOCK_46_5_4_4096 36
#define LOCK_46_5_5_0 37

// Declare shared memory buffers
v4float buf612[256];
v4float buf612d[256];
v4float buf613[256];
v4float buf613d[256];
v4float buf614[256];
v4float buf614d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf612_buf612d[1];
  window_datatype * buf612_ptr = (window_datatype * )buf612;
  window_datatype * buf612d_ptr = (window_datatype * )buf612d;
  window_init(window_buf612_buf612d, 1, buf612, LOCK_46_5_0_0, buf612d, LOCK_46_5_1_0, 256, 256);
  window_internal window_buf613_buf613d[1];
  window_datatype * buf613_ptr = (window_datatype * )buf613;
  window_datatype * buf613d_ptr = (window_datatype * )buf613d;
  window_init(window_buf613_buf613d, 1, buf613, LOCK_46_5_2_4096, buf613d, LOCK_46_5_3_0, 256, 256);
  window_internal window_buf614_buf614d[1];
  window_datatype * buf614_ptr = (window_datatype * )buf614;
  window_datatype * buf614d_ptr = (window_datatype * )buf614d;
  window_init(window_buf614_buf614d, 1, buf614, LOCK_46_5_4_4096, buf614d, LOCK_46_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_4_bounds = sync_buffer[1];

  while (proc_46_4_bounds)
  {

    // Kernel call : i388:mm_kernel0
    window_acquire(window_buf612_buf612d,LOCK_46_5_0_0,LOCK_46_5_1_0,buf612_ptr,buf612d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf613_buf613d,LOCK_46_5_2_4096,LOCK_46_5_3_0,buf613_ptr,buf613d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf614_buf614d,LOCK_46_5_4_4096,LOCK_46_5_5_0,buf614_ptr,buf614d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf612_buf612d),get_input_window_float(window_buf613_buf613d),get_output_window_float(window_buf614_buf614d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf612_buf612d,LOCK_46_5_0_0,LOCK_46_5_1_0,buf612_ptr,buf612d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf613_buf613d,LOCK_46_5_2_4096,LOCK_46_5_3_0,buf613_ptr,buf613d_ptr,0,index, REL_WRITE);
    window_release(window_buf614_buf614d,LOCK_46_5_4_4096,LOCK_46_5_5_0,buf614_ptr,buf614d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_4_bounds > 0)
      --proc_46_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}