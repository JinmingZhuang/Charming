// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_2/src/15_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_2_0_0 48
#define LOCK_15_2_1_0 49
#define LOCK_15_2_2_4096 50
#define LOCK_15_2_3_4096 51
#define LOCK_15_1_6_4096 6
#define LOCK_15_1_7_4096 7
#define LOCK_15_3_0_0 32
#define LOCK_15_3_1_0 33

// Declare shared memory buffers
v4float buf161[256];
v4float buf161d[256];
v4float buf162[256];
v4float buf162d[256];
v4float buf163[256];
v4float buf163d[256];
v4float buf164[256];
v4float buf164d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf162_buf162d[1];
  window_datatype * buf162_ptr = (window_datatype * )buf162;
  window_datatype * buf162d_ptr = (window_datatype * )buf162d;
  window_init(window_buf162_buf162d, 1, buf162, LOCK_15_2_0_0, buf162d, LOCK_15_2_1_0, 256, 256);
  window_internal window_buf163_buf163d[1];
  window_datatype * buf163_ptr = (window_datatype * )buf163;
  window_datatype * buf163d_ptr = (window_datatype * )buf163d;
  window_init(window_buf163_buf163d, 1, buf163, LOCK_15_2_2_4096, buf163d, LOCK_15_2_3_4096, 256, 256);
  window_internal window_buf161_buf161d[1];
  window_datatype * buf161_ptr = (window_datatype * )buf161;
  window_datatype * buf161d_ptr = (window_datatype * )buf161d;
  window_init(window_buf161_buf161d, 1, buf161, LOCK_15_1_6_4096, buf161d, LOCK_15_1_7_4096, 256, 256);
  window_internal window_buf164_buf164d[1];
  window_datatype * buf164_ptr = (window_datatype * )buf164;
  window_datatype * buf164d_ptr = (window_datatype * )buf164d;
  window_init(window_buf164_buf164d, 1, buf164, LOCK_15_3_0_0, buf164d, LOCK_15_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_2_bounds = sync_buffer[1];

  while (proc_15_2_bounds)
  {

    // Kernel call : i162:mm_kernel1
    window_acquire(window_buf162_buf162d,LOCK_15_2_0_0,LOCK_15_2_1_0,buf162_ptr,buf162d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf163_buf163d,LOCK_15_2_2_4096,LOCK_15_2_3_4096,buf163_ptr,buf163d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf161_buf161d,LOCK_15_1_6_4096,LOCK_15_1_7_4096,buf161_ptr,buf161d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf164_buf164d,LOCK_15_3_0_0,LOCK_15_3_1_0,buf164_ptr,buf164d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf162_buf162d),get_input_window_float(window_buf163_buf163d),get_input_window_float(window_buf161_buf161d),get_output_window_float(window_buf164_buf164d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf162_buf162d,LOCK_15_2_0_0,LOCK_15_2_1_0,buf162_ptr,buf162d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf163_buf163d,LOCK_15_2_2_4096,LOCK_15_2_3_4096,buf163_ptr,buf163d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf161_buf161d,LOCK_15_1_6_4096,LOCK_15_1_7_4096,buf161_ptr,buf161d_ptr,0,index, REL_WRITE);
    window_release(window_buf164_buf164d,LOCK_15_3_0_0,LOCK_15_3_1_0,buf164_ptr,buf164d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_2_bounds > 0)
      --proc_15_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}