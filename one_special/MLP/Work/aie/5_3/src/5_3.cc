// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_3/src/5_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_3_4_0 20
#define LOCK_5_3_5_0 21
#define LOCK_5_2_2_4096 2
#define LOCK_5_2_3_4096 3
#define LOCK_5_3_2_4096 18
#define LOCK_5_3_3_4096 19
#define LOCK_5_3_6_0 22
#define LOCK_5_3_7_0 23

// Declare shared memory buffers
v4float buf44[256];
v4float buf44d[256];
v4float buf45[256];
v4float buf45d[256];
v4float buf46[256];
v4float buf46d[256];
v4float buf47[256];
v4float buf47d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf45_buf45d[1];
  window_datatype * buf45_ptr = (window_datatype * )buf45;
  window_datatype * buf45d_ptr = (window_datatype * )buf45d;
  window_init(window_buf45_buf45d, 1, buf45, LOCK_5_3_4_0, buf45d, LOCK_5_3_5_0, 256, 256);
  window_internal window_buf46_buf46d[1];
  window_datatype * buf46_ptr = (window_datatype * )buf46;
  window_datatype * buf46d_ptr = (window_datatype * )buf46d;
  window_init(window_buf46_buf46d, 1, buf46, LOCK_5_2_2_4096, buf46d, LOCK_5_2_3_4096, 256, 256);
  window_internal window_buf44_buf44d[1];
  window_datatype * buf44_ptr = (window_datatype * )buf44;
  window_datatype * buf44d_ptr = (window_datatype * )buf44d;
  window_init(window_buf44_buf44d, 1, buf44, LOCK_5_3_2_4096, buf44d, LOCK_5_3_3_4096, 256, 256);
  window_internal window_buf47_buf47d[1];
  window_datatype * buf47_ptr = (window_datatype * )buf47;
  window_datatype * buf47d_ptr = (window_datatype * )buf47d;
  window_init(window_buf47_buf47d, 1, buf47, LOCK_5_3_6_0, buf47d, LOCK_5_3_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_3_bounds = sync_buffer[1];

  while (proc_5_3_bounds)
  {

    // Kernel call : i103:mm_kernel1
    window_acquire(window_buf45_buf45d,LOCK_5_3_4_0,LOCK_5_3_5_0,buf45_ptr,buf45d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf46_buf46d,LOCK_5_2_2_4096,LOCK_5_2_3_4096,buf46_ptr,buf46d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf44_buf44d,LOCK_5_3_2_4096,LOCK_5_3_3_4096,buf44_ptr,buf44d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf47_buf47d,LOCK_5_3_6_0,LOCK_5_3_7_0,buf47_ptr,buf47d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf45_buf45d),get_input_window_float(window_buf46_buf46d),get_input_window_float(window_buf44_buf44d),get_output_window_float(window_buf47_buf47d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf45_buf45d,LOCK_5_3_4_0,LOCK_5_3_5_0,buf45_ptr,buf45d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf46_buf46d,LOCK_5_2_2_4096,LOCK_5_2_3_4096,buf46_ptr,buf46d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf44_buf44d,LOCK_5_3_2_4096,LOCK_5_3_3_4096,buf44_ptr,buf44d_ptr,0,index, REL_WRITE);
    window_release(window_buf47_buf47d,LOCK_5_3_6_0,LOCK_5_3_7_0,buf47_ptr,buf47d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_3_bounds > 0)
      --proc_5_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}