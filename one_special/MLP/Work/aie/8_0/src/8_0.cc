// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_0/src/8_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_1_0_4096 32
#define LOCK_8_1_1_0 33
#define LOCK_8_1_2_0 34
#define LOCK_8_1_3_0 35
#define LOCK_8_1_4_4096 36
#define LOCK_8_1_5_4096 37

// Declare shared memory buffers
v4float buf72[256];
v4float buf72d[256];
v4float buf73[256];
v4float buf73d[256];
v4float buf74[256];
v4float buf74d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf72_buf72d[1];
  window_datatype * buf72_ptr = (window_datatype * )buf72;
  window_datatype * buf72d_ptr = (window_datatype * )buf72d;
  window_init(window_buf72_buf72d, 1, buf72, LOCK_8_1_0_4096, buf72d, LOCK_8_1_1_0, 256, 256);
  window_internal window_buf73_buf73d[1];
  window_datatype * buf73_ptr = (window_datatype * )buf73;
  window_datatype * buf73d_ptr = (window_datatype * )buf73d;
  window_init(window_buf73_buf73d, 1, buf73, LOCK_8_1_2_0, buf73d, LOCK_8_1_3_0, 256, 256);
  window_internal window_buf74_buf74d[1];
  window_datatype * buf74_ptr = (window_datatype * )buf74;
  window_datatype * buf74d_ptr = (window_datatype * )buf74d;
  window_init(window_buf74_buf74d, 1, buf74, LOCK_8_1_4_4096, buf74d, LOCK_8_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_0_bounds = sync_buffer[1];

  while (proc_8_0_bounds)
  {

    // Kernel call : i118:mm_kernel0
    window_acquire(window_buf72_buf72d,LOCK_8_1_0_4096,LOCK_8_1_1_0,buf72_ptr,buf72d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf73_buf73d,LOCK_8_1_2_0,LOCK_8_1_3_0,buf73_ptr,buf73d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf74_buf74d,LOCK_8_1_4_4096,LOCK_8_1_5_4096,buf74_ptr,buf74d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf72_buf72d),get_input_window_float(window_buf73_buf73d),get_output_window_float(window_buf74_buf74d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf72_buf72d,LOCK_8_1_0_4096,LOCK_8_1_1_0,buf72_ptr,buf72d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf73_buf73d,LOCK_8_1_2_0,LOCK_8_1_3_0,buf73_ptr,buf73d_ptr,0,index, REL_WRITE);
    window_release(window_buf74_buf74d,LOCK_8_1_4_4096,LOCK_8_1_5_4096,buf74_ptr,buf74d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_0_bounds > 0)
      --proc_8_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}