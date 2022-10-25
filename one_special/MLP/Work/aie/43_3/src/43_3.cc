// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_3/src/43_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_3_2_4096 18
#define LOCK_43_3_3_4096 19
#define LOCK_43_3_4_0 20
#define LOCK_43_3_5_0 21
#define LOCK_43_3_0_0 16
#define LOCK_43_3_1_0 17
#define LOCK_43_3_6_4096 22
#define LOCK_43_3_7_4096 23

// Declare shared memory buffers
v4float buf500[256];
v4float buf500d[256];
v4float buf501[256];
v4float buf501d[256];
v4float buf502[256];
v4float buf502d[256];
v4float buf503[256];
v4float buf503d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf501_buf501d[1];
  window_datatype * buf501_ptr = (window_datatype * )buf501;
  window_datatype * buf501d_ptr = (window_datatype * )buf501d;
  window_init(window_buf501_buf501d, 1, buf501, LOCK_43_3_2_4096, buf501d, LOCK_43_3_3_4096, 256, 256);
  window_internal window_buf502_buf502d[1];
  window_datatype * buf502_ptr = (window_datatype * )buf502;
  window_datatype * buf502d_ptr = (window_datatype * )buf502d;
  window_init(window_buf502_buf502d, 1, buf502, LOCK_43_3_4_0, buf502d, LOCK_43_3_5_0, 256, 256);
  window_internal window_buf500_buf500d[1];
  window_datatype * buf500_ptr = (window_datatype * )buf500;
  window_datatype * buf500d_ptr = (window_datatype * )buf500d;
  window_init(window_buf500_buf500d, 1, buf500, LOCK_43_3_0_0, buf500d, LOCK_43_3_1_0, 256, 256);
  window_internal window_buf503_buf503d[1];
  window_datatype * buf503_ptr = (window_datatype * )buf503;
  window_datatype * buf503d_ptr = (window_datatype * )buf503d;
  window_init(window_buf503_buf503d, 1, buf503, LOCK_43_3_6_4096, buf503d, LOCK_43_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_3_bounds = sync_buffer[1];

  while (proc_43_3_bounds)
  {

    // Kernel call : i331:mm_kernel1
    window_acquire(window_buf501_buf501d,LOCK_43_3_2_4096,LOCK_43_3_3_4096,buf501_ptr,buf501d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf502_buf502d,LOCK_43_3_4_0,LOCK_43_3_5_0,buf502_ptr,buf502d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf500_buf500d,LOCK_43_3_0_0,LOCK_43_3_1_0,buf500_ptr,buf500d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf503_buf503d,LOCK_43_3_6_4096,LOCK_43_3_7_4096,buf503_ptr,buf503d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf501_buf501d),get_input_window_float(window_buf502_buf502d),get_input_window_float(window_buf500_buf500d),get_output_window_float(window_buf503_buf503d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf501_buf501d,LOCK_43_3_2_4096,LOCK_43_3_3_4096,buf501_ptr,buf501d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf502_buf502d,LOCK_43_3_4_0,LOCK_43_3_5_0,buf502_ptr,buf502d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf500_buf500d,LOCK_43_3_0_0,LOCK_43_3_1_0,buf500_ptr,buf500d_ptr,0,index, REL_WRITE);
    window_release(window_buf503_buf503d,LOCK_43_3_6_4096,LOCK_43_3_7_4096,buf503_ptr,buf503d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_3_bounds > 0)
      --proc_43_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}