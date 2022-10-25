// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_6/src/43_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_7_0_0 32
#define LOCK_43_7_1_0 33
#define LOCK_43_5_6_0 6
#define LOCK_43_5_7_0 7
#define LOCK_43_5_4_0 4
#define LOCK_43_5_5_0 5
#define LOCK_43_6_2_4096 50
#define LOCK_43_6_3_4096 51

// Declare shared memory buffers
v4float buf653[256];
v4float buf653d[256];
v4float buf654[256];
v4float buf654d[256];
v4float buf655[256];
v4float buf655d[256];
v4float buf656[256];
v4float buf656d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf654_buf654d[1];
  window_datatype * buf654_ptr = (window_datatype * )buf654;
  window_datatype * buf654d_ptr = (window_datatype * )buf654d;
  window_init(window_buf654_buf654d, 1, buf654, LOCK_43_7_0_0, buf654d, LOCK_43_7_1_0, 256, 256);
  window_internal window_buf655_buf655d[1];
  window_datatype * buf655_ptr = (window_datatype * )buf655;
  window_datatype * buf655d_ptr = (window_datatype * )buf655d;
  window_init(window_buf655_buf655d, 1, buf655, LOCK_43_5_6_0, buf655d, LOCK_43_5_7_0, 256, 256);
  window_internal window_buf653_buf653d[1];
  window_datatype * buf653_ptr = (window_datatype * )buf653;
  window_datatype * buf653d_ptr = (window_datatype * )buf653d;
  window_init(window_buf653_buf653d, 1, buf653, LOCK_43_5_4_0, buf653d, LOCK_43_5_5_0, 256, 256);
  window_internal window_buf656_buf656d[1];
  window_datatype * buf656_ptr = (window_datatype * )buf656;
  window_datatype * buf656d_ptr = (window_datatype * )buf656d;
  window_init(window_buf656_buf656d, 1, buf656, LOCK_43_6_2_4096, buf656d, LOCK_43_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_6_bounds = sync_buffer[1];

  while (proc_43_6_bounds)
  {

    // Kernel call : i408:mm_kernel1
    window_acquire(window_buf654_buf654d,LOCK_43_7_0_0,LOCK_43_7_1_0,buf654_ptr,buf654d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf655_buf655d,LOCK_43_5_6_0,LOCK_43_5_7_0,buf655_ptr,buf655d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf653_buf653d,LOCK_43_5_4_0,LOCK_43_5_5_0,buf653_ptr,buf653d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf656_buf656d,LOCK_43_6_2_4096,LOCK_43_6_3_4096,buf656_ptr,buf656d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf654_buf654d),get_input_window_float(window_buf655_buf655d),get_input_window_float(window_buf653_buf653d),get_output_window_float(window_buf656_buf656d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf654_buf654d,LOCK_43_7_0_0,LOCK_43_7_1_0,buf654_ptr,buf654d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf655_buf655d,LOCK_43_5_6_0,LOCK_43_5_7_0,buf655_ptr,buf655d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf653_buf653d,LOCK_43_5_4_0,LOCK_43_5_5_0,buf653_ptr,buf653d_ptr,0,index, REL_WRITE);
    window_release(window_buf656_buf656d,LOCK_43_6_2_4096,LOCK_43_6_3_4096,buf656_ptr,buf656d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_6_bounds > 0)
      --proc_43_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}