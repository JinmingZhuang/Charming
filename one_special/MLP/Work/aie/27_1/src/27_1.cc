// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_1/src/27_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_0_2_4096 2
#define LOCK_27_0_3_4096 3
#define LOCK_27_2_0_0 32
#define LOCK_27_2_1_0 33
#define LOCK_27_1_4_0 20
#define LOCK_27_1_5_4096 21
#define LOCK_27_1_6_0 22
#define LOCK_27_1_7_4096 23

// Declare shared memory buffers
v4float buf302[256];
v4float buf302d[256];
v4float buf303[256];
v4float buf303d[256];
v4float buf304[256];
v4float buf304d[256];
v4float buf305[256];
v4float buf305d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf303_buf303d[1];
  window_datatype * buf303_ptr = (window_datatype * )buf303;
  window_datatype * buf303d_ptr = (window_datatype * )buf303d;
  window_init(window_buf303_buf303d, 1, buf303, LOCK_27_0_2_4096, buf303d, LOCK_27_0_3_4096, 256, 256);
  window_internal window_buf304_buf304d[1];
  window_datatype * buf304_ptr = (window_datatype * )buf304;
  window_datatype * buf304d_ptr = (window_datatype * )buf304d;
  window_init(window_buf304_buf304d, 1, buf304, LOCK_27_2_0_0, buf304d, LOCK_27_2_1_0, 256, 256);
  window_internal window_buf302_buf302d[1];
  window_datatype * buf302_ptr = (window_datatype * )buf302;
  window_datatype * buf302d_ptr = (window_datatype * )buf302d;
  window_init(window_buf302_buf302d, 1, buf302, LOCK_27_1_4_0, buf302d, LOCK_27_1_5_4096, 256, 256);
  window_internal window_buf305_buf305d[1];
  window_datatype * buf305_ptr = (window_datatype * )buf305;
  window_datatype * buf305d_ptr = (window_datatype * )buf305d;
  window_init(window_buf305_buf305d, 1, buf305, LOCK_27_1_6_0, buf305d, LOCK_27_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_1_bounds = sync_buffer[1];

  while (proc_27_1_bounds)
  {

    // Kernel call : i233:mm_kernel1
    window_acquire(window_buf303_buf303d,LOCK_27_0_2_4096,LOCK_27_0_3_4096,buf303_ptr,buf303d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf304_buf304d,LOCK_27_2_0_0,LOCK_27_2_1_0,buf304_ptr,buf304d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf302_buf302d,LOCK_27_1_4_0,LOCK_27_1_5_4096,buf302_ptr,buf302d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf305_buf305d,LOCK_27_1_6_0,LOCK_27_1_7_4096,buf305_ptr,buf305d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf303_buf303d),get_input_window_float(window_buf304_buf304d),get_input_window_float(window_buf302_buf302d),get_output_window_float(window_buf305_buf305d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf303_buf303d,LOCK_27_0_2_4096,LOCK_27_0_3_4096,buf303_ptr,buf303d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf304_buf304d,LOCK_27_2_0_0,LOCK_27_2_1_0,buf304_ptr,buf304d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf302_buf302d,LOCK_27_1_4_0,LOCK_27_1_5_4096,buf302_ptr,buf302d_ptr,0,index, REL_WRITE);
    window_release(window_buf305_buf305d,LOCK_27_1_6_0,LOCK_27_1_7_4096,buf305_ptr,buf305d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_1_bounds > 0)
      --proc_27_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}