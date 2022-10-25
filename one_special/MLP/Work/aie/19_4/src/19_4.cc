// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_4/src/19_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_19_5_0_0 32
#define LOCK_19_5_1_4096 33
#define LOCK_19_4_0_0 48
#define LOCK_19_4_1_0 49
#define LOCK_19_5_2_0 34
#define LOCK_19_5_3_0 35

// Declare shared memory buffers
v4float buf936[256];
v4float buf936d[256];
v4float buf937[256];
v4float buf937d[256];
v4float buf938[256];
v4float buf938d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf936_buf936d[1];
  window_datatype * buf936_ptr = (window_datatype * )buf936;
  window_datatype * buf936d_ptr = (window_datatype * )buf936d;
  window_init(window_buf936_buf936d, 1, buf936, LOCK_19_5_0_0, buf936d, LOCK_19_5_1_4096, 256, 256);
  window_internal window_buf937_buf937d[1];
  window_datatype * buf937_ptr = (window_datatype * )buf937;
  window_datatype * buf937d_ptr = (window_datatype * )buf937d;
  window_init(window_buf937_buf937d, 1, buf937, LOCK_19_4_0_0, buf937d, LOCK_19_4_1_0, 256, 256);
  window_internal window_buf938_buf938d[1];
  window_datatype * buf938_ptr = (window_datatype * )buf938;
  window_datatype * buf938d_ptr = (window_datatype * )buf938d;
  window_init(window_buf938_buf938d, 1, buf938, LOCK_19_5_2_0, buf938d, LOCK_19_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_4_bounds = sync_buffer[1];

  while (proc_19_4_bounds)
  {

    // Kernel call : i550:mm_kernel0
    window_acquire(window_buf936_buf936d,LOCK_19_5_0_0,LOCK_19_5_1_4096,buf936_ptr,buf936d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf937_buf937d,LOCK_19_4_0_0,LOCK_19_4_1_0,buf937_ptr,buf937d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf938_buf938d,LOCK_19_5_2_0,LOCK_19_5_3_0,buf938_ptr,buf938d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf936_buf936d),get_input_window_float(window_buf937_buf937d),get_output_window_float(window_buf938_buf938d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf936_buf936d,LOCK_19_5_0_0,LOCK_19_5_1_4096,buf936_ptr,buf936d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf937_buf937d,LOCK_19_4_0_0,LOCK_19_4_1_0,buf937_ptr,buf937d_ptr,0,index, REL_WRITE);
    window_release(window_buf938_buf938d,LOCK_19_5_2_0,LOCK_19_5_3_0,buf938_ptr,buf938d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_4_bounds > 0)
      --proc_19_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}