// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_4/src/23_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_5_0_4096 32
#define LOCK_23_5_1_0 33
#define LOCK_23_3_2_4096 2
#define LOCK_23_3_3_4096 3
#define LOCK_23_5_2_4096 34
#define LOCK_23_5_3_4096 35

// Declare shared memory buffers
v4float buf888[256];
v4float buf888d[256];
v4float buf889[256];
v4float buf889d[256];
v4float buf890[256];
v4float buf890d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf888_buf888d[1];
  window_datatype * buf888_ptr = (window_datatype * )buf888;
  window_datatype * buf888d_ptr = (window_datatype * )buf888d;
  window_init(window_buf888_buf888d, 1, buf888, LOCK_23_5_0_4096, buf888d, LOCK_23_5_1_0, 256, 256);
  window_internal window_buf889_buf889d[1];
  window_datatype * buf889_ptr = (window_datatype * )buf889;
  window_datatype * buf889d_ptr = (window_datatype * )buf889d;
  window_init(window_buf889_buf889d, 1, buf889, LOCK_23_3_2_4096, buf889d, LOCK_23_3_3_4096, 256, 256);
  window_internal window_buf890_buf890d[1];
  window_datatype * buf890_ptr = (window_datatype * )buf890;
  window_datatype * buf890d_ptr = (window_datatype * )buf890d;
  window_init(window_buf890_buf890d, 1, buf890, LOCK_23_5_2_4096, buf890d, LOCK_23_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_4_bounds = sync_buffer[1];

  while (proc_23_4_bounds)
  {

    // Kernel call : i526:mm_kernel0
    window_acquire(window_buf888_buf888d,LOCK_23_5_0_4096,LOCK_23_5_1_0,buf888_ptr,buf888d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf889_buf889d,LOCK_23_3_2_4096,LOCK_23_3_3_4096,buf889_ptr,buf889d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf890_buf890d,LOCK_23_5_2_4096,LOCK_23_5_3_4096,buf890_ptr,buf890d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf888_buf888d),get_input_window_float(window_buf889_buf889d),get_output_window_float(window_buf890_buf890d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf888_buf888d,LOCK_23_5_0_4096,LOCK_23_5_1_0,buf888_ptr,buf888d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf889_buf889d,LOCK_23_3_2_4096,LOCK_23_3_3_4096,buf889_ptr,buf889d_ptr,0,index, REL_WRITE);
    window_release(window_buf890_buf890d,LOCK_23_5_2_4096,LOCK_23_5_3_4096,buf890_ptr,buf890d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_4_bounds > 0)
      --proc_23_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}