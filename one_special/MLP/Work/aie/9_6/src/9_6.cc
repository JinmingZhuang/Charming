// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/9_6/src/9_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_9_7_0_0 32
#define LOCK_9_7_1_0 33
#define LOCK_9_5_6_0 6
#define LOCK_9_5_7_0 7
#define LOCK_9_5_4_0 4
#define LOCK_9_5_5_4096 5
#define LOCK_9_6_2_4096 50
#define LOCK_9_6_3_4096 51

// Declare shared memory buffers
v4float buf1061[256];
v4float buf1061d[256];
v4float buf1062[256];
v4float buf1062d[256];
v4float buf1063[256];
v4float buf1063d[256];
v4float buf1064[256];
v4float buf1064d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1062_buf1062d[1];
  window_datatype * buf1062_ptr = (window_datatype * )buf1062;
  window_datatype * buf1062d_ptr = (window_datatype * )buf1062d;
  window_init(window_buf1062_buf1062d, 1, buf1062, LOCK_9_7_0_0, buf1062d, LOCK_9_7_1_0, 256, 256);
  window_internal window_buf1063_buf1063d[1];
  window_datatype * buf1063_ptr = (window_datatype * )buf1063;
  window_datatype * buf1063d_ptr = (window_datatype * )buf1063d;
  window_init(window_buf1063_buf1063d, 1, buf1063, LOCK_9_5_6_0, buf1063d, LOCK_9_5_7_0, 256, 256);
  window_internal window_buf1061_buf1061d[1];
  window_datatype * buf1061_ptr = (window_datatype * )buf1061;
  window_datatype * buf1061d_ptr = (window_datatype * )buf1061d;
  window_init(window_buf1061_buf1061d, 1, buf1061, LOCK_9_5_4_0, buf1061d, LOCK_9_5_5_4096, 256, 256);
  window_internal window_buf1064_buf1064d[1];
  window_datatype * buf1064_ptr = (window_datatype * )buf1064;
  window_datatype * buf1064d_ptr = (window_datatype * )buf1064d;
  window_init(window_buf1064_buf1064d, 1, buf1064, LOCK_9_6_2_4096, buf1064d, LOCK_9_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_9_6_bounds = sync_buffer[1];

  while (proc_9_6_bounds)
  {

    // Kernel call : i612:mm_kernel1
    window_acquire(window_buf1062_buf1062d,LOCK_9_7_0_0,LOCK_9_7_1_0,buf1062_ptr,buf1062d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1063_buf1063d,LOCK_9_5_6_0,LOCK_9_5_7_0,buf1063_ptr,buf1063d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1061_buf1061d,LOCK_9_5_4_0,LOCK_9_5_5_4096,buf1061_ptr,buf1061d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1064_buf1064d,LOCK_9_6_2_4096,LOCK_9_6_3_4096,buf1064_ptr,buf1064d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1062_buf1062d),get_input_window_float(window_buf1063_buf1063d),get_input_window_float(window_buf1061_buf1061d),get_output_window_float(window_buf1064_buf1064d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1062_buf1062d,LOCK_9_7_0_0,LOCK_9_7_1_0,buf1062_ptr,buf1062d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1063_buf1063d,LOCK_9_5_6_0,LOCK_9_5_7_0,buf1063_ptr,buf1063d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1061_buf1061d,LOCK_9_5_4_0,LOCK_9_5_5_4096,buf1061_ptr,buf1061d_ptr,0,index, REL_WRITE);
    window_release(window_buf1064_buf1064d,LOCK_9_6_2_4096,LOCK_9_6_3_4096,buf1064_ptr,buf1064d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_9_6_bounds > 0)
      --proc_9_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}