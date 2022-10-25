// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_2/src/13_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_13_3_2_4096 34
#define LOCK_13_3_3_0 35
#define LOCK_13_1_6_4096 6
#define LOCK_13_1_7_0 7
#define LOCK_13_1_4_4096 4
#define LOCK_13_1_5_4096 5
#define LOCK_13_3_4_4096 36
#define LOCK_13_3_5_4096 37

// Declare shared memory buffers
v4float buf137[256];
v4float buf137d[256];
v4float buf138[256];
v4float buf138d[256];
v4float buf139[256];
v4float buf139d[256];
v4float buf140[256];
v4float buf140d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf138_buf138d[1];
  window_datatype * buf138_ptr = (window_datatype * )buf138;
  window_datatype * buf138d_ptr = (window_datatype * )buf138d;
  window_init(window_buf138_buf138d, 1, buf138, LOCK_13_3_2_4096, buf138d, LOCK_13_3_3_0, 256, 256);
  window_internal window_buf139_buf139d[1];
  window_datatype * buf139_ptr = (window_datatype * )buf139;
  window_datatype * buf139d_ptr = (window_datatype * )buf139d;
  window_init(window_buf139_buf139d, 1, buf139, LOCK_13_1_6_4096, buf139d, LOCK_13_1_7_0, 256, 256);
  window_internal window_buf137_buf137d[1];
  window_datatype * buf137_ptr = (window_datatype * )buf137;
  window_datatype * buf137d_ptr = (window_datatype * )buf137d;
  window_init(window_buf137_buf137d, 1, buf137, LOCK_13_1_4_4096, buf137d, LOCK_13_1_5_4096, 256, 256);
  window_internal window_buf140_buf140d[1];
  window_datatype * buf140_ptr = (window_datatype * )buf140;
  window_datatype * buf140d_ptr = (window_datatype * )buf140d;
  window_init(window_buf140_buf140d, 1, buf140, LOCK_13_3_4_4096, buf140d, LOCK_13_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_2_bounds = sync_buffer[1];

  while (proc_13_2_bounds)
  {

    // Kernel call : i150:mm_kernel1
    window_acquire(window_buf138_buf138d,LOCK_13_3_2_4096,LOCK_13_3_3_0,buf138_ptr,buf138d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf139_buf139d,LOCK_13_1_6_4096,LOCK_13_1_7_0,buf139_ptr,buf139d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf137_buf137d,LOCK_13_1_4_4096,LOCK_13_1_5_4096,buf137_ptr,buf137d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf140_buf140d,LOCK_13_3_4_4096,LOCK_13_3_5_4096,buf140_ptr,buf140d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf138_buf138d),get_input_window_float(window_buf139_buf139d),get_input_window_float(window_buf137_buf137d),get_output_window_float(window_buf140_buf140d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf138_buf138d,LOCK_13_3_2_4096,LOCK_13_3_3_0,buf138_ptr,buf138d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf139_buf139d,LOCK_13_1_6_4096,LOCK_13_1_7_0,buf139_ptr,buf139d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf137_buf137d,LOCK_13_1_4_4096,LOCK_13_1_5_4096,buf137_ptr,buf137d_ptr,0,index, REL_WRITE);
    window_release(window_buf140_buf140d,LOCK_13_3_4_4096,LOCK_13_3_5_4096,buf140_ptr,buf140d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_2_bounds > 0)
      --proc_13_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}