// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_2/src/34_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_3_0_4096 32
#define LOCK_34_3_1_4096 33
#define LOCK_34_1_6_4096 6
#define LOCK_34_1_7_4096 7
#define LOCK_34_1_4_0 4
#define LOCK_34_1_5_0 5
#define LOCK_34_3_2_0 34
#define LOCK_34_3_3_4096 35

// Declare shared memory buffers
v4float buf389[256];
v4float buf389d[256];
v4float buf390[256];
v4float buf390d[256];
v4float buf391[256];
v4float buf391d[256];
v4float buf392[256];
v4float buf392d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf390_buf390d[1];
  window_datatype * buf390_ptr = (window_datatype * )buf390;
  window_datatype * buf390d_ptr = (window_datatype * )buf390d;
  window_init(window_buf390_buf390d, 1, buf390, LOCK_34_3_0_4096, buf390d, LOCK_34_3_1_4096, 256, 256);
  window_internal window_buf391_buf391d[1];
  window_datatype * buf391_ptr = (window_datatype * )buf391;
  window_datatype * buf391d_ptr = (window_datatype * )buf391d;
  window_init(window_buf391_buf391d, 1, buf391, LOCK_34_1_6_4096, buf391d, LOCK_34_1_7_4096, 256, 256);
  window_internal window_buf389_buf389d[1];
  window_datatype * buf389_ptr = (window_datatype * )buf389;
  window_datatype * buf389d_ptr = (window_datatype * )buf389d;
  window_init(window_buf389_buf389d, 1, buf389, LOCK_34_1_4_0, buf389d, LOCK_34_1_5_0, 256, 256);
  window_internal window_buf392_buf392d[1];
  window_datatype * buf392_ptr = (window_datatype * )buf392;
  window_datatype * buf392d_ptr = (window_datatype * )buf392d;
  window_init(window_buf392_buf392d, 1, buf392, LOCK_34_3_2_0, buf392d, LOCK_34_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_2_bounds = sync_buffer[1];

  while (proc_34_2_bounds)
  {

    // Kernel call : i276:mm_kernel1
    window_acquire(window_buf390_buf390d,LOCK_34_3_0_4096,LOCK_34_3_1_4096,buf390_ptr,buf390d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf391_buf391d,LOCK_34_1_6_4096,LOCK_34_1_7_4096,buf391_ptr,buf391d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf389_buf389d,LOCK_34_1_4_0,LOCK_34_1_5_0,buf389_ptr,buf389d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf392_buf392d,LOCK_34_3_2_0,LOCK_34_3_3_4096,buf392_ptr,buf392d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf390_buf390d),get_input_window_float(window_buf391_buf391d),get_input_window_float(window_buf389_buf389d),get_output_window_float(window_buf392_buf392d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf390_buf390d,LOCK_34_3_0_4096,LOCK_34_3_1_4096,buf390_ptr,buf390d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf391_buf391d,LOCK_34_1_6_4096,LOCK_34_1_7_4096,buf391_ptr,buf391d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf389_buf389d,LOCK_34_1_4_0,LOCK_34_1_5_0,buf389_ptr,buf389d_ptr,0,index, REL_WRITE);
    window_release(window_buf392_buf392d,LOCK_34_3_2_0,LOCK_34_3_3_4096,buf392_ptr,buf392d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_2_bounds > 0)
      --proc_34_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}