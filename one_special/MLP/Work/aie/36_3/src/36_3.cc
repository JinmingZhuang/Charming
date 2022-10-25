// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/36_3/src/36_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_36_2_4_0 4
#define LOCK_36_2_5_0 5
#define LOCK_36_4_0_0 32
#define LOCK_36_4_1_0 33
#define LOCK_36_2_2_4096 2
#define LOCK_36_2_3_4096 3
#define LOCK_36_2_6_4096 6
#define LOCK_36_2_7_4096 7

// Declare shared memory buffers
v4float buf416[256];
v4float buf416d[256];
v4float buf417[256];
v4float buf417d[256];
v4float buf418[256];
v4float buf418d[256];
v4float buf419[256];
v4float buf419d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf417_buf417d[1];
  window_datatype * buf417_ptr = (window_datatype * )buf417;
  window_datatype * buf417d_ptr = (window_datatype * )buf417d;
  window_init(window_buf417_buf417d, 1, buf417, LOCK_36_2_4_0, buf417d, LOCK_36_2_5_0, 256, 256);
  window_internal window_buf418_buf418d[1];
  window_datatype * buf418_ptr = (window_datatype * )buf418;
  window_datatype * buf418d_ptr = (window_datatype * )buf418d;
  window_init(window_buf418_buf418d, 1, buf418, LOCK_36_4_0_0, buf418d, LOCK_36_4_1_0, 256, 256);
  window_internal window_buf416_buf416d[1];
  window_datatype * buf416_ptr = (window_datatype * )buf416;
  window_datatype * buf416d_ptr = (window_datatype * )buf416d;
  window_init(window_buf416_buf416d, 1, buf416, LOCK_36_2_2_4096, buf416d, LOCK_36_2_3_4096, 256, 256);
  window_internal window_buf419_buf419d[1];
  window_datatype * buf419_ptr = (window_datatype * )buf419;
  window_datatype * buf419d_ptr = (window_datatype * )buf419d;
  window_init(window_buf419_buf419d, 1, buf419, LOCK_36_2_6_4096, buf419d, LOCK_36_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_36_3_bounds = sync_buffer[1];

  while (proc_36_3_bounds)
  {

    // Kernel call : i289:mm_kernel1
    window_acquire(window_buf417_buf417d,LOCK_36_2_4_0,LOCK_36_2_5_0,buf417_ptr,buf417d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf418_buf418d,LOCK_36_4_0_0,LOCK_36_4_1_0,buf418_ptr,buf418d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf416_buf416d,LOCK_36_2_2_4096,LOCK_36_2_3_4096,buf416_ptr,buf416d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf419_buf419d,LOCK_36_2_6_4096,LOCK_36_2_7_4096,buf419_ptr,buf419d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf417_buf417d),get_input_window_float(window_buf418_buf418d),get_input_window_float(window_buf416_buf416d),get_output_window_float(window_buf419_buf419d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf417_buf417d,LOCK_36_2_4_0,LOCK_36_2_5_0,buf417_ptr,buf417d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf418_buf418d,LOCK_36_4_0_0,LOCK_36_4_1_0,buf418_ptr,buf418d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf416_buf416d,LOCK_36_2_2_4096,LOCK_36_2_3_4096,buf416_ptr,buf416d_ptr,0,index, REL_WRITE);
    window_release(window_buf419_buf419d,LOCK_36_2_6_4096,LOCK_36_2_7_4096,buf419_ptr,buf419d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_36_3_bounds > 0)
      --proc_36_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}