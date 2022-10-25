// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_1/src/35_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_1_4_0 20
#define LOCK_35_1_5_0 21
#define LOCK_36_1_0_0 48
#define LOCK_36_1_1_4096 49
#define LOCK_35_1_2_4096 18
#define LOCK_35_1_3_4096 19
#define LOCK_35_1_6_4096 22
#define LOCK_35_1_7_4096 23

// Declare shared memory buffers
v4float buf398[256];
v4float buf398d[256];
v4float buf399[256];
v4float buf399d[256];
v4float buf400[256];
v4float buf400d[256];
v4float buf401[256];
v4float buf401d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf399_buf399d[1];
  window_datatype * buf399_ptr = (window_datatype * )buf399;
  window_datatype * buf399d_ptr = (window_datatype * )buf399d;
  window_init(window_buf399_buf399d, 1, buf399, LOCK_35_1_4_0, buf399d, LOCK_35_1_5_0, 256, 256);
  window_internal window_buf400_buf400d[1];
  window_datatype * buf400_ptr = (window_datatype * )buf400;
  window_datatype * buf400d_ptr = (window_datatype * )buf400d;
  window_init(window_buf400_buf400d, 1, buf400, LOCK_36_1_0_0, buf400d, LOCK_36_1_1_4096, 256, 256);
  window_internal window_buf398_buf398d[1];
  window_datatype * buf398_ptr = (window_datatype * )buf398;
  window_datatype * buf398d_ptr = (window_datatype * )buf398d;
  window_init(window_buf398_buf398d, 1, buf398, LOCK_35_1_2_4096, buf398d, LOCK_35_1_3_4096, 256, 256);
  window_internal window_buf401_buf401d[1];
  window_datatype * buf401_ptr = (window_datatype * )buf401;
  window_datatype * buf401d_ptr = (window_datatype * )buf401d;
  window_init(window_buf401_buf401d, 1, buf401, LOCK_35_1_6_4096, buf401d, LOCK_35_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_1_bounds = sync_buffer[1];

  while (proc_35_1_bounds)
  {

    // Kernel call : i281:mm_kernel1
    window_acquire(window_buf399_buf399d,LOCK_35_1_4_0,LOCK_35_1_5_0,buf399_ptr,buf399d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf400_buf400d,LOCK_36_1_0_0,LOCK_36_1_1_4096,buf400_ptr,buf400d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf398_buf398d,LOCK_35_1_2_4096,LOCK_35_1_3_4096,buf398_ptr,buf398d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf401_buf401d,LOCK_35_1_6_4096,LOCK_35_1_7_4096,buf401_ptr,buf401d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf399_buf399d),get_input_window_float(window_buf400_buf400d),get_input_window_float(window_buf398_buf398d),get_output_window_float(window_buf401_buf401d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf399_buf399d,LOCK_35_1_4_0,LOCK_35_1_5_0,buf399_ptr,buf399d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf400_buf400d,LOCK_36_1_0_0,LOCK_36_1_1_4096,buf400_ptr,buf400d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf398_buf398d,LOCK_35_1_2_4096,LOCK_35_1_3_4096,buf398_ptr,buf398d_ptr,0,index, REL_WRITE);
    window_release(window_buf401_buf401d,LOCK_35_1_6_4096,LOCK_35_1_7_4096,buf401_ptr,buf401d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_1_bounds > 0)
      --proc_35_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}