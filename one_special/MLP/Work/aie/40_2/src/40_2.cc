// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_2/src/40_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_2_0_4096 48
#define LOCK_40_2_1_0 49
#define LOCK_40_3_0_0 32
#define LOCK_40_3_1_0 33
#define LOCK_40_1_6_0 6
#define LOCK_40_1_7_0 7
#define LOCK_40_2_2_0 50
#define LOCK_40_2_3_4096 51

// Declare shared memory buffers
v4float buf461[256];
v4float buf461d[256];
v4float buf462[256];
v4float buf462d[256];
v4float buf463[256];
v4float buf463d[256];
v4float buf464[256];
v4float buf464d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf462_buf462d[1];
  window_datatype * buf462_ptr = (window_datatype * )buf462;
  window_datatype * buf462d_ptr = (window_datatype * )buf462d;
  window_init(window_buf462_buf462d, 1, buf462, LOCK_40_2_0_4096, buf462d, LOCK_40_2_1_0, 256, 256);
  window_internal window_buf463_buf463d[1];
  window_datatype * buf463_ptr = (window_datatype * )buf463;
  window_datatype * buf463d_ptr = (window_datatype * )buf463d;
  window_init(window_buf463_buf463d, 1, buf463, LOCK_40_3_0_0, buf463d, LOCK_40_3_1_0, 256, 256);
  window_internal window_buf461_buf461d[1];
  window_datatype * buf461_ptr = (window_datatype * )buf461;
  window_datatype * buf461d_ptr = (window_datatype * )buf461d;
  window_init(window_buf461_buf461d, 1, buf461, LOCK_40_1_6_0, buf461d, LOCK_40_1_7_0, 256, 256);
  window_internal window_buf464_buf464d[1];
  window_datatype * buf464_ptr = (window_datatype * )buf464;
  window_datatype * buf464d_ptr = (window_datatype * )buf464d;
  window_init(window_buf464_buf464d, 1, buf464, LOCK_40_2_2_0, buf464d, LOCK_40_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_2_bounds = sync_buffer[1];

  while (proc_40_2_bounds)
  {

    // Kernel call : i312:mm_kernel1
    window_acquire(window_buf462_buf462d,LOCK_40_2_0_4096,LOCK_40_2_1_0,buf462_ptr,buf462d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf463_buf463d,LOCK_40_3_0_0,LOCK_40_3_1_0,buf463_ptr,buf463d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf461_buf461d,LOCK_40_1_6_0,LOCK_40_1_7_0,buf461_ptr,buf461d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf464_buf464d,LOCK_40_2_2_0,LOCK_40_2_3_4096,buf464_ptr,buf464d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf462_buf462d),get_input_window_float(window_buf463_buf463d),get_input_window_float(window_buf461_buf461d),get_output_window_float(window_buf464_buf464d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf462_buf462d,LOCK_40_2_0_4096,LOCK_40_2_1_0,buf462_ptr,buf462d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf463_buf463d,LOCK_40_3_0_0,LOCK_40_3_1_0,buf463_ptr,buf463d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf461_buf461d,LOCK_40_1_6_0,LOCK_40_1_7_0,buf461_ptr,buf461d_ptr,0,index, REL_WRITE);
    window_release(window_buf464_buf464d,LOCK_40_2_2_0,LOCK_40_2_3_4096,buf464_ptr,buf464d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_2_bounds > 0)
      --proc_40_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}