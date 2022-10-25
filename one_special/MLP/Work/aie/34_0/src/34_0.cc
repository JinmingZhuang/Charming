// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_0/src/34_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_1_0_4096 32
#define LOCK_34_1_1_4096 33
#define LOCK_34_0_0_0 48
#define LOCK_34_0_1_0 49
#define LOCK_34_1_2_0 34
#define LOCK_34_1_3_0 35

// Declare shared memory buffers
v4float buf384[256];
v4float buf384d[256];
v4float buf385[256];
v4float buf385d[256];
v4float buf386[256];
v4float buf386d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf384_buf384d[1];
  window_datatype * buf384_ptr = (window_datatype * )buf384;
  window_datatype * buf384d_ptr = (window_datatype * )buf384d;
  window_init(window_buf384_buf384d, 1, buf384, LOCK_34_1_0_4096, buf384d, LOCK_34_1_1_4096, 256, 256);
  window_internal window_buf385_buf385d[1];
  window_datatype * buf385_ptr = (window_datatype * )buf385;
  window_datatype * buf385d_ptr = (window_datatype * )buf385d;
  window_init(window_buf385_buf385d, 1, buf385, LOCK_34_0_0_0, buf385d, LOCK_34_0_1_0, 256, 256);
  window_internal window_buf386_buf386d[1];
  window_datatype * buf386_ptr = (window_datatype * )buf386;
  window_datatype * buf386d_ptr = (window_datatype * )buf386d;
  window_init(window_buf386_buf386d, 1, buf386, LOCK_34_1_2_0, buf386d, LOCK_34_1_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_0_bounds = sync_buffer[1];

  while (proc_34_0_bounds)
  {

    // Kernel call : i274:mm_kernel0
    window_acquire(window_buf384_buf384d,LOCK_34_1_0_4096,LOCK_34_1_1_4096,buf384_ptr,buf384d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf385_buf385d,LOCK_34_0_0_0,LOCK_34_0_1_0,buf385_ptr,buf385d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf386_buf386d,LOCK_34_1_2_0,LOCK_34_1_3_0,buf386_ptr,buf386d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf384_buf384d),get_input_window_float(window_buf385_buf385d),get_output_window_float(window_buf386_buf386d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf384_buf384d,LOCK_34_1_0_4096,LOCK_34_1_1_4096,buf384_ptr,buf384d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf385_buf385d,LOCK_34_0_0_0,LOCK_34_0_1_0,buf385_ptr,buf385d_ptr,0,index, REL_WRITE);
    window_release(window_buf386_buf386d,LOCK_34_1_2_0,LOCK_34_1_3_0,buf386_ptr,buf386d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_0_bounds > 0)
      --proc_34_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}