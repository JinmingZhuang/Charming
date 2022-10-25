// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_1/src/34_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_2_0_0 32
#define LOCK_34_2_1_0 33
#define LOCK_35_1_0_0 48
#define LOCK_35_1_1_0 49
#define LOCK_34_1_2_0 18
#define LOCK_34_1_3_0 19
#define LOCK_34_1_4_0 20
#define LOCK_34_1_5_0 21

// Declare shared memory buffers
v4float buf386[256];
v4float buf386d[256];
v4float buf387[256];
v4float buf387d[256];
v4float buf388[256];
v4float buf388d[256];
v4float buf389[256];
v4float buf389d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf387_buf387d[1];
  window_datatype * buf387_ptr = (window_datatype * )buf387;
  window_datatype * buf387d_ptr = (window_datatype * )buf387d;
  window_init(window_buf387_buf387d, 1, buf387, LOCK_34_2_0_0, buf387d, LOCK_34_2_1_0, 256, 256);
  window_internal window_buf388_buf388d[1];
  window_datatype * buf388_ptr = (window_datatype * )buf388;
  window_datatype * buf388d_ptr = (window_datatype * )buf388d;
  window_init(window_buf388_buf388d, 1, buf388, LOCK_35_1_0_0, buf388d, LOCK_35_1_1_0, 256, 256);
  window_internal window_buf386_buf386d[1];
  window_datatype * buf386_ptr = (window_datatype * )buf386;
  window_datatype * buf386d_ptr = (window_datatype * )buf386d;
  window_init(window_buf386_buf386d, 1, buf386, LOCK_34_1_2_0, buf386d, LOCK_34_1_3_0, 256, 256);
  window_internal window_buf389_buf389d[1];
  window_datatype * buf389_ptr = (window_datatype * )buf389;
  window_datatype * buf389d_ptr = (window_datatype * )buf389d;
  window_init(window_buf389_buf389d, 1, buf389, LOCK_34_1_4_0, buf389d, LOCK_34_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_1_bounds = sync_buffer[1];

  while (proc_34_1_bounds)
  {

    // Kernel call : i275:mm_kernel1
    window_acquire(window_buf387_buf387d,LOCK_34_2_0_0,LOCK_34_2_1_0,buf387_ptr,buf387d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf388_buf388d,LOCK_35_1_0_0,LOCK_35_1_1_0,buf388_ptr,buf388d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf386_buf386d,LOCK_34_1_2_0,LOCK_34_1_3_0,buf386_ptr,buf386d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf389_buf389d,LOCK_34_1_4_0,LOCK_34_1_5_0,buf389_ptr,buf389d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf387_buf387d),get_input_window_float(window_buf388_buf388d),get_input_window_float(window_buf386_buf386d),get_output_window_float(window_buf389_buf389d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf387_buf387d,LOCK_34_2_0_0,LOCK_34_2_1_0,buf387_ptr,buf387d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf388_buf388d,LOCK_35_1_0_0,LOCK_35_1_1_0,buf388_ptr,buf388d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf386_buf386d,LOCK_34_1_2_0,LOCK_34_1_3_0,buf386_ptr,buf386d_ptr,0,index, REL_WRITE);
    window_release(window_buf389_buf389d,LOCK_34_1_4_0,LOCK_34_1_5_0,buf389_ptr,buf389d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_1_bounds > 0)
      --proc_34_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}