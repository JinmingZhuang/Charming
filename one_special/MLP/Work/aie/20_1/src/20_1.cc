// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_1/src/20_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_0_2_4096 2
#define LOCK_20_0_3_4096 3
#define LOCK_20_1_4_0 20
#define LOCK_20_1_5_0 21
#define LOCK_20_1_2_4096 18
#define LOCK_20_1_3_4096 19
#define LOCK_20_1_6_4096 22
#define LOCK_20_1_7_4096 23

// Declare shared memory buffers
v4float buf218[256];
v4float buf218d[256];
v4float buf219[256];
v4float buf219d[256];
v4float buf220[256];
v4float buf220d[256];
v4float buf221[256];
v4float buf221d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf219_buf219d[1];
  window_datatype * buf219_ptr = (window_datatype * )buf219;
  window_datatype * buf219d_ptr = (window_datatype * )buf219d;
  window_init(window_buf219_buf219d, 1, buf219, LOCK_20_0_2_4096, buf219d, LOCK_20_0_3_4096, 256, 256);
  window_internal window_buf220_buf220d[1];
  window_datatype * buf220_ptr = (window_datatype * )buf220;
  window_datatype * buf220d_ptr = (window_datatype * )buf220d;
  window_init(window_buf220_buf220d, 1, buf220, LOCK_20_1_4_0, buf220d, LOCK_20_1_5_0, 256, 256);
  window_internal window_buf218_buf218d[1];
  window_datatype * buf218_ptr = (window_datatype * )buf218;
  window_datatype * buf218d_ptr = (window_datatype * )buf218d;
  window_init(window_buf218_buf218d, 1, buf218, LOCK_20_1_2_4096, buf218d, LOCK_20_1_3_4096, 256, 256);
  window_internal window_buf221_buf221d[1];
  window_datatype * buf221_ptr = (window_datatype * )buf221;
  window_datatype * buf221d_ptr = (window_datatype * )buf221d;
  window_init(window_buf221_buf221d, 1, buf221, LOCK_20_1_6_4096, buf221d, LOCK_20_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_1_bounds = sync_buffer[1];

  while (proc_20_1_bounds)
  {

    // Kernel call : i191:mm_kernel1
    window_acquire(window_buf219_buf219d,LOCK_20_0_2_4096,LOCK_20_0_3_4096,buf219_ptr,buf219d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf220_buf220d,LOCK_20_1_4_0,LOCK_20_1_5_0,buf220_ptr,buf220d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf218_buf218d,LOCK_20_1_2_4096,LOCK_20_1_3_4096,buf218_ptr,buf218d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf221_buf221d,LOCK_20_1_6_4096,LOCK_20_1_7_4096,buf221_ptr,buf221d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf219_buf219d),get_input_window_float(window_buf220_buf220d),get_input_window_float(window_buf218_buf218d),get_output_window_float(window_buf221_buf221d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf219_buf219d,LOCK_20_0_2_4096,LOCK_20_0_3_4096,buf219_ptr,buf219d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf220_buf220d,LOCK_20_1_4_0,LOCK_20_1_5_0,buf220_ptr,buf220d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf218_buf218d,LOCK_20_1_2_4096,LOCK_20_1_3_4096,buf218_ptr,buf218d_ptr,0,index, REL_WRITE);
    window_release(window_buf221_buf221d,LOCK_20_1_6_4096,LOCK_20_1_7_4096,buf221_ptr,buf221d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_1_bounds > 0)
      --proc_20_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}