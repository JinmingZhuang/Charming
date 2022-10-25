// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_3/src/35_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_3_2_4096 18
#define LOCK_35_3_3_4096 19
#define LOCK_35_2_4_4096 4
#define LOCK_35_2_5_0 5
#define LOCK_35_2_2_4096 2
#define LOCK_35_2_3_4096 3
#define LOCK_35_2_6_0 6
#define LOCK_35_2_7_0 7

// Declare shared memory buffers
v4float buf404[256];
v4float buf404d[256];
v4float buf405[256];
v4float buf405d[256];
v4float buf406[256];
v4float buf406d[256];
v4float buf407[256];
v4float buf407d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf405_buf405d[1];
  window_datatype * buf405_ptr = (window_datatype * )buf405;
  window_datatype * buf405d_ptr = (window_datatype * )buf405d;
  window_init(window_buf405_buf405d, 1, buf405, LOCK_35_3_2_4096, buf405d, LOCK_35_3_3_4096, 256, 256);
  window_internal window_buf406_buf406d[1];
  window_datatype * buf406_ptr = (window_datatype * )buf406;
  window_datatype * buf406d_ptr = (window_datatype * )buf406d;
  window_init(window_buf406_buf406d, 1, buf406, LOCK_35_2_4_4096, buf406d, LOCK_35_2_5_0, 256, 256);
  window_internal window_buf404_buf404d[1];
  window_datatype * buf404_ptr = (window_datatype * )buf404;
  window_datatype * buf404d_ptr = (window_datatype * )buf404d;
  window_init(window_buf404_buf404d, 1, buf404, LOCK_35_2_2_4096, buf404d, LOCK_35_2_3_4096, 256, 256);
  window_internal window_buf407_buf407d[1];
  window_datatype * buf407_ptr = (window_datatype * )buf407;
  window_datatype * buf407d_ptr = (window_datatype * )buf407d;
  window_init(window_buf407_buf407d, 1, buf407, LOCK_35_2_6_0, buf407d, LOCK_35_2_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_3_bounds = sync_buffer[1];

  while (proc_35_3_bounds)
  {

    // Kernel call : i283:mm_kernel1
    window_acquire(window_buf405_buf405d,LOCK_35_3_2_4096,LOCK_35_3_3_4096,buf405_ptr,buf405d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf406_buf406d,LOCK_35_2_4_4096,LOCK_35_2_5_0,buf406_ptr,buf406d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf404_buf404d,LOCK_35_2_2_4096,LOCK_35_2_3_4096,buf404_ptr,buf404d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf407_buf407d,LOCK_35_2_6_0,LOCK_35_2_7_0,buf407_ptr,buf407d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf405_buf405d),get_input_window_float(window_buf406_buf406d),get_input_window_float(window_buf404_buf404d),get_output_window_float(window_buf407_buf407d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf405_buf405d,LOCK_35_3_2_4096,LOCK_35_3_3_4096,buf405_ptr,buf405d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf406_buf406d,LOCK_35_2_4_4096,LOCK_35_2_5_0,buf406_ptr,buf406d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf404_buf404d,LOCK_35_2_2_4096,LOCK_35_2_3_4096,buf404_ptr,buf404d_ptr,0,index, REL_WRITE);
    window_release(window_buf407_buf407d,LOCK_35_2_6_0,LOCK_35_2_7_0,buf407_ptr,buf407d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_3_bounds > 0)
      --proc_35_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}