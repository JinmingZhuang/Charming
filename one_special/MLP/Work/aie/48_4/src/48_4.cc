// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/48_4/src/48_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_48_4_0_4096 48
#define LOCK_48_4_1_4096 49
#define LOCK_48_4_2_0 50
#define LOCK_48_4_3_0 51
#define LOCK_48_5_0_0 32
#define LOCK_48_5_1_0 33

// Declare shared memory buffers
v4float buf588[256];
v4float buf588d[256];
v4float buf589[256];
v4float buf589d[256];
v4float buf590[256];
v4float buf590d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf588_buf588d[1];
  window_datatype * buf588_ptr = (window_datatype * )buf588;
  window_datatype * buf588d_ptr = (window_datatype * )buf588d;
  window_init(window_buf588_buf588d, 1, buf588, LOCK_48_4_0_4096, buf588d, LOCK_48_4_1_4096, 256, 256);
  window_internal window_buf589_buf589d[1];
  window_datatype * buf589_ptr = (window_datatype * )buf589;
  window_datatype * buf589d_ptr = (window_datatype * )buf589d;
  window_init(window_buf589_buf589d, 1, buf589, LOCK_48_4_2_0, buf589d, LOCK_48_4_3_0, 256, 256);
  window_internal window_buf590_buf590d[1];
  window_datatype * buf590_ptr = (window_datatype * )buf590;
  window_datatype * buf590d_ptr = (window_datatype * )buf590d;
  window_init(window_buf590_buf590d, 1, buf590, LOCK_48_5_0_0, buf590d, LOCK_48_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_48_4_bounds = sync_buffer[1];

  while (proc_48_4_bounds)
  {

    // Kernel call : i376:mm_kernel0
    window_acquire(window_buf588_buf588d,LOCK_48_4_0_4096,LOCK_48_4_1_4096,buf588_ptr,buf588d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf589_buf589d,LOCK_48_4_2_0,LOCK_48_4_3_0,buf589_ptr,buf589d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf590_buf590d,LOCK_48_5_0_0,LOCK_48_5_1_0,buf590_ptr,buf590d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf588_buf588d),get_input_window_float(window_buf589_buf589d),get_output_window_float(window_buf590_buf590d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf588_buf588d,LOCK_48_4_0_4096,LOCK_48_4_1_4096,buf588_ptr,buf588d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf589_buf589d,LOCK_48_4_2_0,LOCK_48_4_3_0,buf589_ptr,buf589d_ptr,0,index, REL_WRITE);
    window_release(window_buf590_buf590d,LOCK_48_5_0_0,LOCK_48_5_1_0,buf590_ptr,buf590d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_48_4_bounds > 0)
      --proc_48_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}