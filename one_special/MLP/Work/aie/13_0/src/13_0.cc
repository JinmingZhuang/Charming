// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_0/src/13_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_0_2_4096 18
#define LOCK_12_0_3_4096 19
#define LOCK_13_1_0_0 32
#define LOCK_13_1_1_0 33
#define LOCK_13_1_2_0 34
#define LOCK_13_1_3_4096 35

// Declare shared memory buffers
v4float buf132[256];
v4float buf132d[256];
v4float buf133[256];
v4float buf133d[256];
v4float buf134[256];
v4float buf134d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf132_buf132d[1];
  window_datatype * buf132_ptr = (window_datatype * )buf132;
  window_datatype * buf132d_ptr = (window_datatype * )buf132d;
  window_init(window_buf132_buf132d, 1, buf132, LOCK_12_0_2_4096, buf132d, LOCK_12_0_3_4096, 256, 256);
  window_internal window_buf133_buf133d[1];
  window_datatype * buf133_ptr = (window_datatype * )buf133;
  window_datatype * buf133d_ptr = (window_datatype * )buf133d;
  window_init(window_buf133_buf133d, 1, buf133, LOCK_13_1_0_0, buf133d, LOCK_13_1_1_0, 256, 256);
  window_internal window_buf134_buf134d[1];
  window_datatype * buf134_ptr = (window_datatype * )buf134;
  window_datatype * buf134d_ptr = (window_datatype * )buf134d;
  window_init(window_buf134_buf134d, 1, buf134, LOCK_13_1_2_0, buf134d, LOCK_13_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_0_bounds = sync_buffer[1];

  while (proc_13_0_bounds)
  {

    // Kernel call : i148:mm_kernel0
    window_acquire(window_buf132_buf132d,LOCK_12_0_2_4096,LOCK_12_0_3_4096,buf132_ptr,buf132d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf133_buf133d,LOCK_13_1_0_0,LOCK_13_1_1_0,buf133_ptr,buf133d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf134_buf134d,LOCK_13_1_2_0,LOCK_13_1_3_4096,buf134_ptr,buf134d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf132_buf132d),get_input_window_float(window_buf133_buf133d),get_output_window_float(window_buf134_buf134d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf132_buf132d,LOCK_12_0_2_4096,LOCK_12_0_3_4096,buf132_ptr,buf132d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf133_buf133d,LOCK_13_1_0_0,LOCK_13_1_1_0,buf133_ptr,buf133d_ptr,0,index, REL_WRITE);
    window_release(window_buf134_buf134d,LOCK_13_1_2_0,LOCK_13_1_3_4096,buf134_ptr,buf134d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_0_bounds > 0)
      --proc_13_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}