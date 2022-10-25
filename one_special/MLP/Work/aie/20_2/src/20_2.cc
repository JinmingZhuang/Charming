// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_2/src/20_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_19_2_6_4096 22
#define LOCK_19_2_7_4096 23
#define LOCK_20_2_0_0 48
#define LOCK_20_2_1_0 49
#define LOCK_20_1_6_4096 6
#define LOCK_20_1_7_4096 7
#define LOCK_20_3_2_4096 34
#define LOCK_20_3_3_4096 35

// Declare shared memory buffers
v4float buf221[256];
v4float buf221d[256];
v4float buf222[256];
v4float buf222d[256];
v4float buf223[256];
v4float buf223d[256];
v4float buf224[256];
v4float buf224d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf222_buf222d[1];
  window_datatype * buf222_ptr = (window_datatype * )buf222;
  window_datatype * buf222d_ptr = (window_datatype * )buf222d;
  window_init(window_buf222_buf222d, 1, buf222, LOCK_19_2_6_4096, buf222d, LOCK_19_2_7_4096, 256, 256);
  window_internal window_buf223_buf223d[1];
  window_datatype * buf223_ptr = (window_datatype * )buf223;
  window_datatype * buf223d_ptr = (window_datatype * )buf223d;
  window_init(window_buf223_buf223d, 1, buf223, LOCK_20_2_0_0, buf223d, LOCK_20_2_1_0, 256, 256);
  window_internal window_buf221_buf221d[1];
  window_datatype * buf221_ptr = (window_datatype * )buf221;
  window_datatype * buf221d_ptr = (window_datatype * )buf221d;
  window_init(window_buf221_buf221d, 1, buf221, LOCK_20_1_6_4096, buf221d, LOCK_20_1_7_4096, 256, 256);
  window_internal window_buf224_buf224d[1];
  window_datatype * buf224_ptr = (window_datatype * )buf224;
  window_datatype * buf224d_ptr = (window_datatype * )buf224d;
  window_init(window_buf224_buf224d, 1, buf224, LOCK_20_3_2_4096, buf224d, LOCK_20_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_2_bounds = sync_buffer[1];

  while (proc_20_2_bounds)
  {

    // Kernel call : i192:mm_kernel1
    window_acquire(window_buf222_buf222d,LOCK_19_2_6_4096,LOCK_19_2_7_4096,buf222_ptr,buf222d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf223_buf223d,LOCK_20_2_0_0,LOCK_20_2_1_0,buf223_ptr,buf223d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf221_buf221d,LOCK_20_1_6_4096,LOCK_20_1_7_4096,buf221_ptr,buf221d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf224_buf224d,LOCK_20_3_2_4096,LOCK_20_3_3_4096,buf224_ptr,buf224d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf222_buf222d),get_input_window_float(window_buf223_buf223d),get_input_window_float(window_buf221_buf221d),get_output_window_float(window_buf224_buf224d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf222_buf222d,LOCK_19_2_6_4096,LOCK_19_2_7_4096,buf222_ptr,buf222d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf223_buf223d,LOCK_20_2_0_0,LOCK_20_2_1_0,buf223_ptr,buf223d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf221_buf221d,LOCK_20_1_6_4096,LOCK_20_1_7_4096,buf221_ptr,buf221d_ptr,0,index, REL_WRITE);
    window_release(window_buf224_buf224d,LOCK_20_3_2_4096,LOCK_20_3_3_4096,buf224_ptr,buf224d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_2_bounds > 0)
      --proc_20_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}