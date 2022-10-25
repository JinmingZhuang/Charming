// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_0/src/44_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_0_0_0 48
#define LOCK_44_0_1_0 49
#define LOCK_43_0_2_4096 18
#define LOCK_43_0_3_4096 19
#define LOCK_44_1_4_4096 36
#define LOCK_44_1_5_4096 37

// Declare shared memory buffers
v4float buf504[256];
v4float buf504d[256];
v4float buf505[256];
v4float buf505d[256];
v4float buf506[256];
v4float buf506d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf504_buf504d[1];
  window_datatype * buf504_ptr = (window_datatype * )buf504;
  window_datatype * buf504d_ptr = (window_datatype * )buf504d;
  window_init(window_buf504_buf504d, 1, buf504, LOCK_44_0_0_0, buf504d, LOCK_44_0_1_0, 256, 256);
  window_internal window_buf505_buf505d[1];
  window_datatype * buf505_ptr = (window_datatype * )buf505;
  window_datatype * buf505d_ptr = (window_datatype * )buf505d;
  window_init(window_buf505_buf505d, 1, buf505, LOCK_43_0_2_4096, buf505d, LOCK_43_0_3_4096, 256, 256);
  window_internal window_buf506_buf506d[1];
  window_datatype * buf506_ptr = (window_datatype * )buf506;
  window_datatype * buf506d_ptr = (window_datatype * )buf506d;
  window_init(window_buf506_buf506d, 1, buf506, LOCK_44_1_4_4096, buf506d, LOCK_44_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_0_bounds = sync_buffer[1];

  while (proc_44_0_bounds)
  {

    // Kernel call : i334:mm_kernel0
    window_acquire(window_buf504_buf504d,LOCK_44_0_0_0,LOCK_44_0_1_0,buf504_ptr,buf504d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf505_buf505d,LOCK_43_0_2_4096,LOCK_43_0_3_4096,buf505_ptr,buf505d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf506_buf506d,LOCK_44_1_4_4096,LOCK_44_1_5_4096,buf506_ptr,buf506d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf504_buf504d),get_input_window_float(window_buf505_buf505d),get_output_window_float(window_buf506_buf506d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf504_buf504d,LOCK_44_0_0_0,LOCK_44_0_1_0,buf504_ptr,buf504d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf505_buf505d,LOCK_43_0_2_4096,LOCK_43_0_3_4096,buf505_ptr,buf505d_ptr,0,index, REL_WRITE);
    window_release(window_buf506_buf506d,LOCK_44_1_4_4096,LOCK_44_1_5_4096,buf506_ptr,buf506d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_0_bounds > 0)
      --proc_44_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}