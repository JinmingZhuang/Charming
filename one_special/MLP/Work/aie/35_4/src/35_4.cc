// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_4/src/35_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_4_2_4096 18
#define LOCK_34_4_3_4096 19
#define LOCK_35_4_0_0 48
#define LOCK_35_4_1_0 49
#define LOCK_35_5_0_0 32
#define LOCK_35_5_1_0 33

// Declare shared memory buffers
v4float buf744[256];
v4float buf744d[256];
v4float buf745[256];
v4float buf745d[256];
v4float buf746[256];
v4float buf746d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf744_buf744d[1];
  window_datatype * buf744_ptr = (window_datatype * )buf744;
  window_datatype * buf744d_ptr = (window_datatype * )buf744d;
  window_init(window_buf744_buf744d, 1, buf744, LOCK_34_4_2_4096, buf744d, LOCK_34_4_3_4096, 256, 256);
  window_internal window_buf745_buf745d[1];
  window_datatype * buf745_ptr = (window_datatype * )buf745;
  window_datatype * buf745d_ptr = (window_datatype * )buf745d;
  window_init(window_buf745_buf745d, 1, buf745, LOCK_35_4_0_0, buf745d, LOCK_35_4_1_0, 256, 256);
  window_internal window_buf746_buf746d[1];
  window_datatype * buf746_ptr = (window_datatype * )buf746;
  window_datatype * buf746d_ptr = (window_datatype * )buf746d;
  window_init(window_buf746_buf746d, 1, buf746, LOCK_35_5_0_0, buf746d, LOCK_35_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_4_bounds = sync_buffer[1];

  while (proc_35_4_bounds)
  {

    // Kernel call : i454:mm_kernel0
    window_acquire(window_buf744_buf744d,LOCK_34_4_2_4096,LOCK_34_4_3_4096,buf744_ptr,buf744d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf745_buf745d,LOCK_35_4_0_0,LOCK_35_4_1_0,buf745_ptr,buf745d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf746_buf746d,LOCK_35_5_0_0,LOCK_35_5_1_0,buf746_ptr,buf746d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf744_buf744d),get_input_window_float(window_buf745_buf745d),get_output_window_float(window_buf746_buf746d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf744_buf744d,LOCK_34_4_2_4096,LOCK_34_4_3_4096,buf744_ptr,buf744d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf745_buf745d,LOCK_35_4_0_0,LOCK_35_4_1_0,buf745_ptr,buf745d_ptr,0,index, REL_WRITE);
    window_release(window_buf746_buf746d,LOCK_35_5_0_0,LOCK_35_5_1_0,buf746_ptr,buf746d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_4_bounds > 0)
      --proc_35_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}