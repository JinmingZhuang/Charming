// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_2/src/36_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_3_0_0 32
#define LOCK_36_3_1_0 33
#define LOCK_36_1_6_0 6
#define LOCK_36_1_7_4096 7
#define LOCK_36_1_4_0 4
#define LOCK_36_1_5_4096 5
#define LOCK_36_2_2_4096 50
#define LOCK_36_2_3_4096 51

// Declare shared memory buffers
v4float buf413[256];
v4float buf413d[256];
v4float buf414[256];
v4float buf414d[256];
v4float buf415[256];
v4float buf415d[256];
v4float buf416[256];
v4float buf416d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf414_buf414d[1];
  window_datatype * buf414_ptr = (window_datatype * )buf414;
  window_datatype * buf414d_ptr = (window_datatype * )buf414d;
  window_init(window_buf414_buf414d, 1, buf414, LOCK_36_3_0_0, buf414d, LOCK_36_3_1_0, 256, 256);
  window_internal window_buf415_buf415d[1];
  window_datatype * buf415_ptr = (window_datatype * )buf415;
  window_datatype * buf415d_ptr = (window_datatype * )buf415d;
  window_init(window_buf415_buf415d, 1, buf415, LOCK_36_1_6_0, buf415d, LOCK_36_1_7_4096, 256, 256);
  window_internal window_buf413_buf413d[1];
  window_datatype * buf413_ptr = (window_datatype * )buf413;
  window_datatype * buf413d_ptr = (window_datatype * )buf413d;
  window_init(window_buf413_buf413d, 1, buf413, LOCK_36_1_4_0, buf413d, LOCK_36_1_5_4096, 256, 256);
  window_internal window_buf416_buf416d[1];
  window_datatype * buf416_ptr = (window_datatype * )buf416;
  window_datatype * buf416d_ptr = (window_datatype * )buf416d;
  window_init(window_buf416_buf416d, 1, buf416, LOCK_36_2_2_4096, buf416d, LOCK_36_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_2_bounds = sync_buffer[1];

  while (proc_36_2_bounds)
  {

    // Kernel call : i288:mm_kernel1
    window_acquire(window_buf414_buf414d,LOCK_36_3_0_0,LOCK_36_3_1_0,buf414_ptr,buf414d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf415_buf415d,LOCK_36_1_6_0,LOCK_36_1_7_4096,buf415_ptr,buf415d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf413_buf413d,LOCK_36_1_4_0,LOCK_36_1_5_4096,buf413_ptr,buf413d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf416_buf416d,LOCK_36_2_2_4096,LOCK_36_2_3_4096,buf416_ptr,buf416d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf414_buf414d),get_input_window_float(window_buf415_buf415d),get_input_window_float(window_buf413_buf413d),get_output_window_float(window_buf416_buf416d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf414_buf414d,LOCK_36_3_0_0,LOCK_36_3_1_0,buf414_ptr,buf414d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf415_buf415d,LOCK_36_1_6_0,LOCK_36_1_7_4096,buf415_ptr,buf415d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf413_buf413d,LOCK_36_1_4_0,LOCK_36_1_5_4096,buf413_ptr,buf413d_ptr,0,index, REL_WRITE);
    window_release(window_buf416_buf416d,LOCK_36_2_2_4096,LOCK_36_2_3_4096,buf416_ptr,buf416d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_2_bounds > 0)
      --proc_36_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}