// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_1/src/33_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_1_2_0 18
#define LOCK_33_1_3_4096 19
#define LOCK_33_0_2_4096 2
#define LOCK_33_0_3_4096 3
#define LOCK_33_1_0_0 16
#define LOCK_33_1_1_4096 17
#define LOCK_33_1_4_0 20
#define LOCK_33_1_5_4096 21

// Declare shared memory buffers
v4float buf374[256];
v4float buf374d[256];
v4float buf375[256];
v4float buf375d[256];
v4float buf376[256];
v4float buf376d[256];
v4float buf377[256];
v4float buf377d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf375_buf375d[1];
  window_datatype * buf375_ptr = (window_datatype * )buf375;
  window_datatype * buf375d_ptr = (window_datatype * )buf375d;
  window_init(window_buf375_buf375d, 1, buf375, LOCK_33_1_2_0, buf375d, LOCK_33_1_3_4096, 256, 256);
  window_internal window_buf376_buf376d[1];
  window_datatype * buf376_ptr = (window_datatype * )buf376;
  window_datatype * buf376d_ptr = (window_datatype * )buf376d;
  window_init(window_buf376_buf376d, 1, buf376, LOCK_33_0_2_4096, buf376d, LOCK_33_0_3_4096, 256, 256);
  window_internal window_buf374_buf374d[1];
  window_datatype * buf374_ptr = (window_datatype * )buf374;
  window_datatype * buf374d_ptr = (window_datatype * )buf374d;
  window_init(window_buf374_buf374d, 1, buf374, LOCK_33_1_0_0, buf374d, LOCK_33_1_1_4096, 256, 256);
  window_internal window_buf377_buf377d[1];
  window_datatype * buf377_ptr = (window_datatype * )buf377;
  window_datatype * buf377d_ptr = (window_datatype * )buf377d;
  window_init(window_buf377_buf377d, 1, buf377, LOCK_33_1_4_0, buf377d, LOCK_33_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_1_bounds = sync_buffer[1];

  while (proc_33_1_bounds)
  {

    // Kernel call : i269:mm_kernel1
    window_acquire(window_buf375_buf375d,LOCK_33_1_2_0,LOCK_33_1_3_4096,buf375_ptr,buf375d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf376_buf376d,LOCK_33_0_2_4096,LOCK_33_0_3_4096,buf376_ptr,buf376d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf374_buf374d,LOCK_33_1_0_0,LOCK_33_1_1_4096,buf374_ptr,buf374d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf377_buf377d,LOCK_33_1_4_0,LOCK_33_1_5_4096,buf377_ptr,buf377d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf375_buf375d),get_input_window_float(window_buf376_buf376d),get_input_window_float(window_buf374_buf374d),get_output_window_float(window_buf377_buf377d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf375_buf375d,LOCK_33_1_2_0,LOCK_33_1_3_4096,buf375_ptr,buf375d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf376_buf376d,LOCK_33_0_2_4096,LOCK_33_0_3_4096,buf376_ptr,buf376d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf374_buf374d,LOCK_33_1_0_0,LOCK_33_1_1_4096,buf374_ptr,buf374d_ptr,0,index, REL_WRITE);
    window_release(window_buf377_buf377d,LOCK_33_1_4_0,LOCK_33_1_5_4096,buf377_ptr,buf377d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_1_bounds > 0)
      --proc_33_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}