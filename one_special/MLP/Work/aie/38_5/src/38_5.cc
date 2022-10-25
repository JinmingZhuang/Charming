// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_5/src/38_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_4_2_4096 2
#define LOCK_38_4_3_4096 3
#define LOCK_39_5_6_4096 54
#define LOCK_39_5_7_4096 55
#define LOCK_38_5_0_4096 16
#define LOCK_38_5_1_0 17
#define LOCK_38_5_2_0 18
#define LOCK_38_5_3_0 19

// Declare shared memory buffers
v4float buf710[256];
v4float buf710d[256];
v4float buf711[256];
v4float buf711d[256];
v4float buf712[256];
v4float buf712d[256];
v4float buf713[256];
v4float buf713d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf711_buf711d[1];
  window_datatype * buf711_ptr = (window_datatype * )buf711;
  window_datatype * buf711d_ptr = (window_datatype * )buf711d;
  window_init(window_buf711_buf711d, 1, buf711, LOCK_38_4_2_4096, buf711d, LOCK_38_4_3_4096, 256, 256);
  window_internal window_buf712_buf712d[1];
  window_datatype * buf712_ptr = (window_datatype * )buf712;
  window_datatype * buf712d_ptr = (window_datatype * )buf712d;
  window_init(window_buf712_buf712d, 1, buf712, LOCK_39_5_6_4096, buf712d, LOCK_39_5_7_4096, 256, 256);
  window_internal window_buf710_buf710d[1];
  window_datatype * buf710_ptr = (window_datatype * )buf710;
  window_datatype * buf710d_ptr = (window_datatype * )buf710d;
  window_init(window_buf710_buf710d, 1, buf710, LOCK_38_5_0_4096, buf710d, LOCK_38_5_1_0, 256, 256);
  window_internal window_buf713_buf713d[1];
  window_datatype * buf713_ptr = (window_datatype * )buf713;
  window_datatype * buf713d_ptr = (window_datatype * )buf713d;
  window_init(window_buf713_buf713d, 1, buf713, LOCK_38_5_2_0, buf713d, LOCK_38_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_5_bounds = sync_buffer[1];

  while (proc_38_5_bounds)
  {

    // Kernel call : i437:mm_kernel1
    window_acquire(window_buf711_buf711d,LOCK_38_4_2_4096,LOCK_38_4_3_4096,buf711_ptr,buf711d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf712_buf712d,LOCK_39_5_6_4096,LOCK_39_5_7_4096,buf712_ptr,buf712d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf710_buf710d,LOCK_38_5_0_4096,LOCK_38_5_1_0,buf710_ptr,buf710d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf713_buf713d,LOCK_38_5_2_0,LOCK_38_5_3_0,buf713_ptr,buf713d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf711_buf711d),get_input_window_float(window_buf712_buf712d),get_input_window_float(window_buf710_buf710d),get_output_window_float(window_buf713_buf713d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf711_buf711d,LOCK_38_4_2_4096,LOCK_38_4_3_4096,buf711_ptr,buf711d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf712_buf712d,LOCK_39_5_6_4096,LOCK_39_5_7_4096,buf712_ptr,buf712d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf710_buf710d,LOCK_38_5_0_4096,LOCK_38_5_1_0,buf710_ptr,buf710d_ptr,0,index, REL_WRITE);
    window_release(window_buf713_buf713d,LOCK_38_5_2_0,LOCK_38_5_3_0,buf713_ptr,buf713d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_5_bounds > 0)
      --proc_38_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}