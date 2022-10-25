// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/23_2/src/23_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_1_6_0 6
#define LOCK_23_1_7_4096 7
#define LOCK_23_2_2_0 50
#define LOCK_23_2_3_0 51
#define LOCK_23_1_4_4096 4
#define LOCK_23_1_5_4096 5
#define LOCK_23_2_4_0 52
#define LOCK_23_2_5_4096 53

// Declare shared memory buffers
v4float buf257[256];
v4float buf257d[256];
v4float buf258[256];
v4float buf258d[256];
v4float buf259[256];
v4float buf259d[256];
v4float buf260[256];
v4float buf260d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf258_buf258d[1];
  window_datatype * buf258_ptr = (window_datatype * )buf258;
  window_datatype * buf258d_ptr = (window_datatype * )buf258d;
  window_init(window_buf258_buf258d, 1, buf258, LOCK_23_1_6_0, buf258d, LOCK_23_1_7_4096, 256, 256);
  window_internal window_buf259_buf259d[1];
  window_datatype * buf259_ptr = (window_datatype * )buf259;
  window_datatype * buf259d_ptr = (window_datatype * )buf259d;
  window_init(window_buf259_buf259d, 1, buf259, LOCK_23_2_2_0, buf259d, LOCK_23_2_3_0, 256, 256);
  window_internal window_buf257_buf257d[1];
  window_datatype * buf257_ptr = (window_datatype * )buf257;
  window_datatype * buf257d_ptr = (window_datatype * )buf257d;
  window_init(window_buf257_buf257d, 1, buf257, LOCK_23_1_4_4096, buf257d, LOCK_23_1_5_4096, 256, 256);
  window_internal window_buf260_buf260d[1];
  window_datatype * buf260_ptr = (window_datatype * )buf260;
  window_datatype * buf260d_ptr = (window_datatype * )buf260d;
  window_init(window_buf260_buf260d, 1, buf260, LOCK_23_2_4_0, buf260d, LOCK_23_2_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_23_2_bounds = sync_buffer[1];

  while (proc_23_2_bounds)
  {

    // Kernel call : i210:mm_kernel1
    window_acquire(window_buf258_buf258d,LOCK_23_1_6_0,LOCK_23_1_7_4096,buf258_ptr,buf258d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf259_buf259d,LOCK_23_2_2_0,LOCK_23_2_3_0,buf259_ptr,buf259d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf257_buf257d,LOCK_23_1_4_4096,LOCK_23_1_5_4096,buf257_ptr,buf257d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf260_buf260d,LOCK_23_2_4_0,LOCK_23_2_5_4096,buf260_ptr,buf260d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf258_buf258d),get_input_window_float(window_buf259_buf259d),get_input_window_float(window_buf257_buf257d),get_output_window_float(window_buf260_buf260d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf258_buf258d,LOCK_23_1_6_0,LOCK_23_1_7_4096,buf258_ptr,buf258d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf259_buf259d,LOCK_23_2_2_0,LOCK_23_2_3_0,buf259_ptr,buf259d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf257_buf257d,LOCK_23_1_4_4096,LOCK_23_1_5_4096,buf257_ptr,buf257d_ptr,0,index, REL_WRITE);
    window_release(window_buf260_buf260d,LOCK_23_2_4_0,LOCK_23_2_5_4096,buf260_ptr,buf260d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_23_2_bounds > 0)
      --proc_23_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}