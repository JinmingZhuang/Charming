// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_1/src/14_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_0_2_4096 2
#define LOCK_14_0_3_4096 3
#define LOCK_14_1_4_0 20
#define LOCK_14_1_5_0 21
#define LOCK_14_1_2_4096 18
#define LOCK_14_1_3_4096 19
#define LOCK_14_1_6_4096 22
#define LOCK_14_1_7_4096 23

// Declare shared memory buffers
v4float buf146[256];
v4float buf146d[256];
v4float buf147[256];
v4float buf147d[256];
v4float buf148[256];
v4float buf148d[256];
v4float buf149[256];
v4float buf149d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf147_buf147d[1];
  window_datatype * buf147_ptr = (window_datatype * )buf147;
  window_datatype * buf147d_ptr = (window_datatype * )buf147d;
  window_init(window_buf147_buf147d, 1, buf147, LOCK_14_0_2_4096, buf147d, LOCK_14_0_3_4096, 256, 256);
  window_internal window_buf148_buf148d[1];
  window_datatype * buf148_ptr = (window_datatype * )buf148;
  window_datatype * buf148d_ptr = (window_datatype * )buf148d;
  window_init(window_buf148_buf148d, 1, buf148, LOCK_14_1_4_0, buf148d, LOCK_14_1_5_0, 256, 256);
  window_internal window_buf146_buf146d[1];
  window_datatype * buf146_ptr = (window_datatype * )buf146;
  window_datatype * buf146d_ptr = (window_datatype * )buf146d;
  window_init(window_buf146_buf146d, 1, buf146, LOCK_14_1_2_4096, buf146d, LOCK_14_1_3_4096, 256, 256);
  window_internal window_buf149_buf149d[1];
  window_datatype * buf149_ptr = (window_datatype * )buf149;
  window_datatype * buf149d_ptr = (window_datatype * )buf149d;
  window_init(window_buf149_buf149d, 1, buf149, LOCK_14_1_6_4096, buf149d, LOCK_14_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_1_bounds = sync_buffer[1];

  while (proc_14_1_bounds)
  {

    // Kernel call : i155:mm_kernel1
    window_acquire(window_buf147_buf147d,LOCK_14_0_2_4096,LOCK_14_0_3_4096,buf147_ptr,buf147d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf148_buf148d,LOCK_14_1_4_0,LOCK_14_1_5_0,buf148_ptr,buf148d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf146_buf146d,LOCK_14_1_2_4096,LOCK_14_1_3_4096,buf146_ptr,buf146d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf149_buf149d,LOCK_14_1_6_4096,LOCK_14_1_7_4096,buf149_ptr,buf149d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf147_buf147d),get_input_window_float(window_buf148_buf148d),get_input_window_float(window_buf146_buf146d),get_output_window_float(window_buf149_buf149d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf147_buf147d,LOCK_14_0_2_4096,LOCK_14_0_3_4096,buf147_ptr,buf147d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf148_buf148d,LOCK_14_1_4_0,LOCK_14_1_5_0,buf148_ptr,buf148d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf146_buf146d,LOCK_14_1_2_4096,LOCK_14_1_3_4096,buf146_ptr,buf146d_ptr,0,index, REL_WRITE);
    window_release(window_buf149_buf149d,LOCK_14_1_6_4096,LOCK_14_1_7_4096,buf149_ptr,buf149d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_1_bounds > 0)
      --proc_14_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}