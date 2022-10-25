// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_2/src/19_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_19_1_6_4096 6
#define LOCK_19_1_7_4096 7
#define LOCK_19_3_2_4096 34
#define LOCK_19_3_3_4096 35
#define LOCK_19_1_4_0 4
#define LOCK_19_1_5_0 5
#define LOCK_19_2_0_0 48
#define LOCK_19_2_1_0 49

// Declare shared memory buffers
v4float buf209[256];
v4float buf209d[256];
v4float buf210[256];
v4float buf210d[256];
v4float buf211[256];
v4float buf211d[256];
v4float buf212[256];
v4float buf212d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf210_buf210d[1];
  window_datatype * buf210_ptr = (window_datatype * )buf210;
  window_datatype * buf210d_ptr = (window_datatype * )buf210d;
  window_init(window_buf210_buf210d, 1, buf210, LOCK_19_1_6_4096, buf210d, LOCK_19_1_7_4096, 256, 256);
  window_internal window_buf211_buf211d[1];
  window_datatype * buf211_ptr = (window_datatype * )buf211;
  window_datatype * buf211d_ptr = (window_datatype * )buf211d;
  window_init(window_buf211_buf211d, 1, buf211, LOCK_19_3_2_4096, buf211d, LOCK_19_3_3_4096, 256, 256);
  window_internal window_buf209_buf209d[1];
  window_datatype * buf209_ptr = (window_datatype * )buf209;
  window_datatype * buf209d_ptr = (window_datatype * )buf209d;
  window_init(window_buf209_buf209d, 1, buf209, LOCK_19_1_4_0, buf209d, LOCK_19_1_5_0, 256, 256);
  window_internal window_buf212_buf212d[1];
  window_datatype * buf212_ptr = (window_datatype * )buf212;
  window_datatype * buf212d_ptr = (window_datatype * )buf212d;
  window_init(window_buf212_buf212d, 1, buf212, LOCK_19_2_0_0, buf212d, LOCK_19_2_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_2_bounds = sync_buffer[1];

  while (proc_19_2_bounds)
  {

    // Kernel call : i186:mm_kernel1
    window_acquire(window_buf210_buf210d,LOCK_19_1_6_4096,LOCK_19_1_7_4096,buf210_ptr,buf210d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf211_buf211d,LOCK_19_3_2_4096,LOCK_19_3_3_4096,buf211_ptr,buf211d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf209_buf209d,LOCK_19_1_4_0,LOCK_19_1_5_0,buf209_ptr,buf209d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf212_buf212d,LOCK_19_2_0_0,LOCK_19_2_1_0,buf212_ptr,buf212d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf210_buf210d),get_input_window_float(window_buf211_buf211d),get_input_window_float(window_buf209_buf209d),get_output_window_float(window_buf212_buf212d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf210_buf210d,LOCK_19_1_6_4096,LOCK_19_1_7_4096,buf210_ptr,buf210d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf211_buf211d,LOCK_19_3_2_4096,LOCK_19_3_3_4096,buf211_ptr,buf211d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf209_buf209d,LOCK_19_1_4_0,LOCK_19_1_5_0,buf209_ptr,buf209d_ptr,0,index, REL_WRITE);
    window_release(window_buf212_buf212d,LOCK_19_2_0_0,LOCK_19_2_1_0,buf212_ptr,buf212d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_2_bounds > 0)
      --proc_19_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}