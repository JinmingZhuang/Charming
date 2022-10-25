// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_3/src/45_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_45_3_0_0 16
#define LOCK_45_3_1_0 17
#define LOCK_45_4_0_0 32
#define LOCK_45_4_1_0 33
#define LOCK_45_2_4_0 4
#define LOCK_45_2_5_4096 5
#define LOCK_45_2_6_0 6
#define LOCK_45_2_7_4096 7

// Declare shared memory buffers
v4float buf524[256];
v4float buf524d[256];
v4float buf525[256];
v4float buf525d[256];
v4float buf526[256];
v4float buf526d[256];
v4float buf527[256];
v4float buf527d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf525_buf525d[1];
  window_datatype * buf525_ptr = (window_datatype * )buf525;
  window_datatype * buf525d_ptr = (window_datatype * )buf525d;
  window_init(window_buf525_buf525d, 1, buf525, LOCK_45_3_0_0, buf525d, LOCK_45_3_1_0, 256, 256);
  window_internal window_buf526_buf526d[1];
  window_datatype * buf526_ptr = (window_datatype * )buf526;
  window_datatype * buf526d_ptr = (window_datatype * )buf526d;
  window_init(window_buf526_buf526d, 1, buf526, LOCK_45_4_0_0, buf526d, LOCK_45_4_1_0, 256, 256);
  window_internal window_buf524_buf524d[1];
  window_datatype * buf524_ptr = (window_datatype * )buf524;
  window_datatype * buf524d_ptr = (window_datatype * )buf524d;
  window_init(window_buf524_buf524d, 1, buf524, LOCK_45_2_4_0, buf524d, LOCK_45_2_5_4096, 256, 256);
  window_internal window_buf527_buf527d[1];
  window_datatype * buf527_ptr = (window_datatype * )buf527;
  window_datatype * buf527d_ptr = (window_datatype * )buf527d;
  window_init(window_buf527_buf527d, 1, buf527, LOCK_45_2_6_0, buf527d, LOCK_45_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_3_bounds = sync_buffer[1];

  while (proc_45_3_bounds)
  {

    // Kernel call : i343:mm_kernel1
    window_acquire(window_buf525_buf525d,LOCK_45_3_0_0,LOCK_45_3_1_0,buf525_ptr,buf525d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf526_buf526d,LOCK_45_4_0_0,LOCK_45_4_1_0,buf526_ptr,buf526d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf524_buf524d,LOCK_45_2_4_0,LOCK_45_2_5_4096,buf524_ptr,buf524d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf527_buf527d,LOCK_45_2_6_0,LOCK_45_2_7_4096,buf527_ptr,buf527d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf525_buf525d),get_input_window_float(window_buf526_buf526d),get_input_window_float(window_buf524_buf524d),get_output_window_float(window_buf527_buf527d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf525_buf525d,LOCK_45_3_0_0,LOCK_45_3_1_0,buf525_ptr,buf525d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf526_buf526d,LOCK_45_4_0_0,LOCK_45_4_1_0,buf526_ptr,buf526d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf524_buf524d,LOCK_45_2_4_0,LOCK_45_2_5_4096,buf524_ptr,buf524d_ptr,0,index, REL_WRITE);
    window_release(window_buf527_buf527d,LOCK_45_2_6_0,LOCK_45_2_7_4096,buf527_ptr,buf527d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_3_bounds > 0)
      --proc_45_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}