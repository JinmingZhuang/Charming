// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_6/src/40_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_7_0_0 32
#define LOCK_40_7_1_4096 33
#define LOCK_40_7_2_4096 34
#define LOCK_40_7_3_4096 35
#define LOCK_40_5_6_4096 6
#define LOCK_40_5_7_4096 7
#define LOCK_40_7_4_0 36
#define LOCK_40_7_5_0 37

// Declare shared memory buffers
v4float buf689[256];
v4float buf689d[256];
v4float buf690[256];
v4float buf690d[256];
v4float buf691[256];
v4float buf691d[256];
v4float buf692[256];
v4float buf692d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf690_buf690d[1];
  window_datatype * buf690_ptr = (window_datatype * )buf690;
  window_datatype * buf690d_ptr = (window_datatype * )buf690d;
  window_init(window_buf690_buf690d, 1, buf690, LOCK_40_7_0_0, buf690d, LOCK_40_7_1_4096, 256, 256);
  window_internal window_buf691_buf691d[1];
  window_datatype * buf691_ptr = (window_datatype * )buf691;
  window_datatype * buf691d_ptr = (window_datatype * )buf691d;
  window_init(window_buf691_buf691d, 1, buf691, LOCK_40_7_2_4096, buf691d, LOCK_40_7_3_4096, 256, 256);
  window_internal window_buf689_buf689d[1];
  window_datatype * buf689_ptr = (window_datatype * )buf689;
  window_datatype * buf689d_ptr = (window_datatype * )buf689d;
  window_init(window_buf689_buf689d, 1, buf689, LOCK_40_5_6_4096, buf689d, LOCK_40_5_7_4096, 256, 256);
  window_internal window_buf692_buf692d[1];
  window_datatype * buf692_ptr = (window_datatype * )buf692;
  window_datatype * buf692d_ptr = (window_datatype * )buf692d;
  window_init(window_buf692_buf692d, 1, buf692, LOCK_40_7_4_0, buf692d, LOCK_40_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_6_bounds = sync_buffer[1];

  while (proc_40_6_bounds)
  {

    // Kernel call : i426:mm_kernel1
    window_acquire(window_buf690_buf690d,LOCK_40_7_0_0,LOCK_40_7_1_4096,buf690_ptr,buf690d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf691_buf691d,LOCK_40_7_2_4096,LOCK_40_7_3_4096,buf691_ptr,buf691d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf689_buf689d,LOCK_40_5_6_4096,LOCK_40_5_7_4096,buf689_ptr,buf689d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf692_buf692d,LOCK_40_7_4_0,LOCK_40_7_5_0,buf692_ptr,buf692d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf690_buf690d),get_input_window_float(window_buf691_buf691d),get_input_window_float(window_buf689_buf689d),get_output_window_float(window_buf692_buf692d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf690_buf690d,LOCK_40_7_0_0,LOCK_40_7_1_4096,buf690_ptr,buf690d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf691_buf691d,LOCK_40_7_2_4096,LOCK_40_7_3_4096,buf691_ptr,buf691d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf689_buf689d,LOCK_40_5_6_4096,LOCK_40_5_7_4096,buf689_ptr,buf689d_ptr,0,index, REL_WRITE);
    window_release(window_buf692_buf692d,LOCK_40_7_4_0,LOCK_40_7_5_0,buf692_ptr,buf692d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_6_bounds > 0)
      --proc_40_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}