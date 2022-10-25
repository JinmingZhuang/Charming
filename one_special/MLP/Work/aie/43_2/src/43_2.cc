// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_2/src/43_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_2_0_0 48
#define LOCK_43_2_1_0 49
#define LOCK_43_1_6_4096 6
#define LOCK_43_1_7_0 7
#define LOCK_43_1_4_4096 4
#define LOCK_43_1_5_0 5
#define LOCK_43_3_0_0 32
#define LOCK_43_3_1_0 33

// Declare shared memory buffers
v4float buf497[256];
v4float buf497d[256];
v4float buf498[256];
v4float buf498d[256];
v4float buf499[256];
v4float buf499d[256];
v4float buf500[256];
v4float buf500d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf498_buf498d[1];
  window_datatype * buf498_ptr = (window_datatype * )buf498;
  window_datatype * buf498d_ptr = (window_datatype * )buf498d;
  window_init(window_buf498_buf498d, 1, buf498, LOCK_43_2_0_0, buf498d, LOCK_43_2_1_0, 256, 256);
  window_internal window_buf499_buf499d[1];
  window_datatype * buf499_ptr = (window_datatype * )buf499;
  window_datatype * buf499d_ptr = (window_datatype * )buf499d;
  window_init(window_buf499_buf499d, 1, buf499, LOCK_43_1_6_4096, buf499d, LOCK_43_1_7_0, 256, 256);
  window_internal window_buf497_buf497d[1];
  window_datatype * buf497_ptr = (window_datatype * )buf497;
  window_datatype * buf497d_ptr = (window_datatype * )buf497d;
  window_init(window_buf497_buf497d, 1, buf497, LOCK_43_1_4_4096, buf497d, LOCK_43_1_5_0, 256, 256);
  window_internal window_buf500_buf500d[1];
  window_datatype * buf500_ptr = (window_datatype * )buf500;
  window_datatype * buf500d_ptr = (window_datatype * )buf500d;
  window_init(window_buf500_buf500d, 1, buf500, LOCK_43_3_0_0, buf500d, LOCK_43_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_2_bounds = sync_buffer[1];

  while (proc_43_2_bounds)
  {

    // Kernel call : i330:mm_kernel1
    window_acquire(window_buf498_buf498d,LOCK_43_2_0_0,LOCK_43_2_1_0,buf498_ptr,buf498d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf499_buf499d,LOCK_43_1_6_4096,LOCK_43_1_7_0,buf499_ptr,buf499d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf497_buf497d,LOCK_43_1_4_4096,LOCK_43_1_5_0,buf497_ptr,buf497d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf500_buf500d,LOCK_43_3_0_0,LOCK_43_3_1_0,buf500_ptr,buf500d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf498_buf498d),get_input_window_float(window_buf499_buf499d),get_input_window_float(window_buf497_buf497d),get_output_window_float(window_buf500_buf500d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf498_buf498d,LOCK_43_2_0_0,LOCK_43_2_1_0,buf498_ptr,buf498d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf499_buf499d,LOCK_43_1_6_4096,LOCK_43_1_7_0,buf499_ptr,buf499d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf497_buf497d,LOCK_43_1_4_4096,LOCK_43_1_5_0,buf497_ptr,buf497d_ptr,0,index, REL_WRITE);
    window_release(window_buf500_buf500d,LOCK_43_3_0_0,LOCK_43_3_1_0,buf500_ptr,buf500d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_2_bounds > 0)
      --proc_43_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}