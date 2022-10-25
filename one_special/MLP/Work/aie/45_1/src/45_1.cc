// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_1/src/45_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_45_2_0_0 32
#define LOCK_45_2_1_4096 33
#define LOCK_45_2_2_4096 34
#define LOCK_45_2_3_0 35
#define LOCK_45_1_2_0 18
#define LOCK_45_1_3_4096 19
#define LOCK_45_1_4_4096 20
#define LOCK_45_1_5_4096 21

// Declare shared memory buffers
v4float buf518[256];
v4float buf518d[256];
v4float buf519[256];
v4float buf519d[256];
v4float buf520[256];
v4float buf520d[256];
v4float buf521[256];
v4float buf521d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf519_buf519d[1];
  window_datatype * buf519_ptr = (window_datatype * )buf519;
  window_datatype * buf519d_ptr = (window_datatype * )buf519d;
  window_init(window_buf519_buf519d, 1, buf519, LOCK_45_2_0_0, buf519d, LOCK_45_2_1_4096, 256, 256);
  window_internal window_buf520_buf520d[1];
  window_datatype * buf520_ptr = (window_datatype * )buf520;
  window_datatype * buf520d_ptr = (window_datatype * )buf520d;
  window_init(window_buf520_buf520d, 1, buf520, LOCK_45_2_2_4096, buf520d, LOCK_45_2_3_0, 256, 256);
  window_internal window_buf518_buf518d[1];
  window_datatype * buf518_ptr = (window_datatype * )buf518;
  window_datatype * buf518d_ptr = (window_datatype * )buf518d;
  window_init(window_buf518_buf518d, 1, buf518, LOCK_45_1_2_0, buf518d, LOCK_45_1_3_4096, 256, 256);
  window_internal window_buf521_buf521d[1];
  window_datatype * buf521_ptr = (window_datatype * )buf521;
  window_datatype * buf521d_ptr = (window_datatype * )buf521d;
  window_init(window_buf521_buf521d, 1, buf521, LOCK_45_1_4_4096, buf521d, LOCK_45_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_1_bounds = sync_buffer[1];

  while (proc_45_1_bounds)
  {

    // Kernel call : i341:mm_kernel1
    window_acquire(window_buf519_buf519d,LOCK_45_2_0_0,LOCK_45_2_1_4096,buf519_ptr,buf519d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf520_buf520d,LOCK_45_2_2_4096,LOCK_45_2_3_0,buf520_ptr,buf520d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf518_buf518d,LOCK_45_1_2_0,LOCK_45_1_3_4096,buf518_ptr,buf518d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf521_buf521d,LOCK_45_1_4_4096,LOCK_45_1_5_4096,buf521_ptr,buf521d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf519_buf519d),get_input_window_float(window_buf520_buf520d),get_input_window_float(window_buf518_buf518d),get_output_window_float(window_buf521_buf521d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf519_buf519d,LOCK_45_2_0_0,LOCK_45_2_1_4096,buf519_ptr,buf519d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf520_buf520d,LOCK_45_2_2_4096,LOCK_45_2_3_0,buf520_ptr,buf520d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf518_buf518d,LOCK_45_1_2_0,LOCK_45_1_3_4096,buf518_ptr,buf518d_ptr,0,index, REL_WRITE);
    window_release(window_buf521_buf521d,LOCK_45_1_4_4096,LOCK_45_1_5_4096,buf521_ptr,buf521d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_1_bounds > 0)
      --proc_45_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}