// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_4/src/33_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_3_2_4096 2
#define LOCK_33_3_3_4096 3
#define LOCK_33_5_0_4096 32
#define LOCK_33_5_1_0 33
#define LOCK_33_5_2_4096 34
#define LOCK_33_5_3_4096 35

// Declare shared memory buffers
v4float buf768[256];
v4float buf768d[256];
v4float buf769[256];
v4float buf769d[256];
v4float buf770[256];
v4float buf770d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf768_buf768d[1];
  window_datatype * buf768_ptr = (window_datatype * )buf768;
  window_datatype * buf768d_ptr = (window_datatype * )buf768d;
  window_init(window_buf768_buf768d, 1, buf768, LOCK_33_3_2_4096, buf768d, LOCK_33_3_3_4096, 256, 256);
  window_internal window_buf769_buf769d[1];
  window_datatype * buf769_ptr = (window_datatype * )buf769;
  window_datatype * buf769d_ptr = (window_datatype * )buf769d;
  window_init(window_buf769_buf769d, 1, buf769, LOCK_33_5_0_4096, buf769d, LOCK_33_5_1_0, 256, 256);
  window_internal window_buf770_buf770d[1];
  window_datatype * buf770_ptr = (window_datatype * )buf770;
  window_datatype * buf770d_ptr = (window_datatype * )buf770d;
  window_init(window_buf770_buf770d, 1, buf770, LOCK_33_5_2_4096, buf770d, LOCK_33_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_4_bounds = sync_buffer[1];

  while (proc_33_4_bounds)
  {

    // Kernel call : i466:mm_kernel0
    window_acquire(window_buf768_buf768d,LOCK_33_3_2_4096,LOCK_33_3_3_4096,buf768_ptr,buf768d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf769_buf769d,LOCK_33_5_0_4096,LOCK_33_5_1_0,buf769_ptr,buf769d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf770_buf770d,LOCK_33_5_2_4096,LOCK_33_5_3_4096,buf770_ptr,buf770d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf768_buf768d),get_input_window_float(window_buf769_buf769d),get_output_window_float(window_buf770_buf770d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf768_buf768d,LOCK_33_3_2_4096,LOCK_33_3_3_4096,buf768_ptr,buf768d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf769_buf769d,LOCK_33_5_0_4096,LOCK_33_5_1_0,buf769_ptr,buf769d_ptr,0,index, REL_WRITE);
    window_release(window_buf770_buf770d,LOCK_33_5_2_4096,LOCK_33_5_3_4096,buf770_ptr,buf770d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_4_bounds > 0)
      --proc_33_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}