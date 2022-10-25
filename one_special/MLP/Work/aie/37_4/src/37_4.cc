// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_4/src/37_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_5_0_4096 32
#define LOCK_37_5_1_0 33
#define LOCK_37_4_2_4096 50
#define LOCK_37_4_3_4096 51
#define LOCK_37_5_2_4096 34
#define LOCK_37_5_3_4096 35

// Declare shared memory buffers
v4float buf720[256];
v4float buf720d[256];
v4float buf721[256];
v4float buf721d[256];
v4float buf722[256];
v4float buf722d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf720_buf720d[1];
  window_datatype * buf720_ptr = (window_datatype * )buf720;
  window_datatype * buf720d_ptr = (window_datatype * )buf720d;
  window_init(window_buf720_buf720d, 1, buf720, LOCK_37_5_0_4096, buf720d, LOCK_37_5_1_0, 256, 256);
  window_internal window_buf721_buf721d[1];
  window_datatype * buf721_ptr = (window_datatype * )buf721;
  window_datatype * buf721d_ptr = (window_datatype * )buf721d;
  window_init(window_buf721_buf721d, 1, buf721, LOCK_37_4_2_4096, buf721d, LOCK_37_4_3_4096, 256, 256);
  window_internal window_buf722_buf722d[1];
  window_datatype * buf722_ptr = (window_datatype * )buf722;
  window_datatype * buf722d_ptr = (window_datatype * )buf722d;
  window_init(window_buf722_buf722d, 1, buf722, LOCK_37_5_2_4096, buf722d, LOCK_37_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_4_bounds = sync_buffer[1];

  while (proc_37_4_bounds)
  {

    // Kernel call : i442:mm_kernel0
    window_acquire(window_buf720_buf720d,LOCK_37_5_0_4096,LOCK_37_5_1_0,buf720_ptr,buf720d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf721_buf721d,LOCK_37_4_2_4096,LOCK_37_4_3_4096,buf721_ptr,buf721d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf722_buf722d,LOCK_37_5_2_4096,LOCK_37_5_3_4096,buf722_ptr,buf722d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf720_buf720d),get_input_window_float(window_buf721_buf721d),get_output_window_float(window_buf722_buf722d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf720_buf720d,LOCK_37_5_0_4096,LOCK_37_5_1_0,buf720_ptr,buf720d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf721_buf721d,LOCK_37_4_2_4096,LOCK_37_4_3_4096,buf721_ptr,buf721d_ptr,0,index, REL_WRITE);
    window_release(window_buf722_buf722d,LOCK_37_5_2_4096,LOCK_37_5_3_4096,buf722_ptr,buf722d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_4_bounds > 0)
      --proc_37_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}