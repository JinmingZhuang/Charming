// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_5/src/40_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_5_4_0 20
#define LOCK_40_5_5_0 21
#define LOCK_40_6_0_0 32
#define LOCK_40_6_1_0 33
#define LOCK_40_5_2_0 18
#define LOCK_40_5_3_4096 19
#define LOCK_40_5_6_4096 22
#define LOCK_40_5_7_4096 23

// Declare shared memory buffers
v4float buf686[256];
v4float buf686d[256];
v4float buf687[256];
v4float buf687d[256];
v4float buf688[256];
v4float buf688d[256];
v4float buf689[256];
v4float buf689d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf687_buf687d[1];
  window_datatype * buf687_ptr = (window_datatype * )buf687;
  window_datatype * buf687d_ptr = (window_datatype * )buf687d;
  window_init(window_buf687_buf687d, 1, buf687, LOCK_40_5_4_0, buf687d, LOCK_40_5_5_0, 256, 256);
  window_internal window_buf688_buf688d[1];
  window_datatype * buf688_ptr = (window_datatype * )buf688;
  window_datatype * buf688d_ptr = (window_datatype * )buf688d;
  window_init(window_buf688_buf688d, 1, buf688, LOCK_40_6_0_0, buf688d, LOCK_40_6_1_0, 256, 256);
  window_internal window_buf686_buf686d[1];
  window_datatype * buf686_ptr = (window_datatype * )buf686;
  window_datatype * buf686d_ptr = (window_datatype * )buf686d;
  window_init(window_buf686_buf686d, 1, buf686, LOCK_40_5_2_0, buf686d, LOCK_40_5_3_4096, 256, 256);
  window_internal window_buf689_buf689d[1];
  window_datatype * buf689_ptr = (window_datatype * )buf689;
  window_datatype * buf689d_ptr = (window_datatype * )buf689d;
  window_init(window_buf689_buf689d, 1, buf689, LOCK_40_5_6_4096, buf689d, LOCK_40_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_5_bounds = sync_buffer[1];

  while (proc_40_5_bounds)
  {

    // Kernel call : i425:mm_kernel1
    window_acquire(window_buf687_buf687d,LOCK_40_5_4_0,LOCK_40_5_5_0,buf687_ptr,buf687d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf688_buf688d,LOCK_40_6_0_0,LOCK_40_6_1_0,buf688_ptr,buf688d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf686_buf686d,LOCK_40_5_2_0,LOCK_40_5_3_4096,buf686_ptr,buf686d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf689_buf689d,LOCK_40_5_6_4096,LOCK_40_5_7_4096,buf689_ptr,buf689d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf687_buf687d),get_input_window_float(window_buf688_buf688d),get_input_window_float(window_buf686_buf686d),get_output_window_float(window_buf689_buf689d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf687_buf687d,LOCK_40_5_4_0,LOCK_40_5_5_0,buf687_ptr,buf687d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf688_buf688d,LOCK_40_6_0_0,LOCK_40_6_1_0,buf688_ptr,buf688d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf686_buf686d,LOCK_40_5_2_0,LOCK_40_5_3_4096,buf686_ptr,buf686d_ptr,0,index, REL_WRITE);
    window_release(window_buf689_buf689d,LOCK_40_5_6_4096,LOCK_40_5_7_4096,buf689_ptr,buf689d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_5_bounds > 0)
      --proc_40_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}