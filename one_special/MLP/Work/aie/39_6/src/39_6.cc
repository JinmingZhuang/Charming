// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_6/src/39_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_6_0_0 16
#define LOCK_38_6_1_0 17
#define LOCK_39_6_2_4096 50
#define LOCK_39_6_3_4096 51
#define LOCK_39_5_4_0 4
#define LOCK_39_5_5_0 5
#define LOCK_39_7_0_0 32
#define LOCK_39_7_1_0 33

// Declare shared memory buffers
v4float buf701[256];
v4float buf701d[256];
v4float buf702[256];
v4float buf702d[256];
v4float buf703[256];
v4float buf703d[256];
v4float buf704[256];
v4float buf704d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf702_buf702d[1];
  window_datatype * buf702_ptr = (window_datatype * )buf702;
  window_datatype * buf702d_ptr = (window_datatype * )buf702d;
  window_init(window_buf702_buf702d, 1, buf702, LOCK_38_6_0_0, buf702d, LOCK_38_6_1_0, 256, 256);
  window_internal window_buf703_buf703d[1];
  window_datatype * buf703_ptr = (window_datatype * )buf703;
  window_datatype * buf703d_ptr = (window_datatype * )buf703d;
  window_init(window_buf703_buf703d, 1, buf703, LOCK_39_6_2_4096, buf703d, LOCK_39_6_3_4096, 256, 256);
  window_internal window_buf701_buf701d[1];
  window_datatype * buf701_ptr = (window_datatype * )buf701;
  window_datatype * buf701d_ptr = (window_datatype * )buf701d;
  window_init(window_buf701_buf701d, 1, buf701, LOCK_39_5_4_0, buf701d, LOCK_39_5_5_0, 256, 256);
  window_internal window_buf704_buf704d[1];
  window_datatype * buf704_ptr = (window_datatype * )buf704;
  window_datatype * buf704d_ptr = (window_datatype * )buf704d;
  window_init(window_buf704_buf704d, 1, buf704, LOCK_39_7_0_0, buf704d, LOCK_39_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_6_bounds = sync_buffer[1];

  while (proc_39_6_bounds)
  {

    // Kernel call : i432:mm_kernel1
    window_acquire(window_buf702_buf702d,LOCK_38_6_0_0,LOCK_38_6_1_0,buf702_ptr,buf702d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf703_buf703d,LOCK_39_6_2_4096,LOCK_39_6_3_4096,buf703_ptr,buf703d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf701_buf701d,LOCK_39_5_4_0,LOCK_39_5_5_0,buf701_ptr,buf701d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf704_buf704d,LOCK_39_7_0_0,LOCK_39_7_1_0,buf704_ptr,buf704d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf702_buf702d),get_input_window_float(window_buf703_buf703d),get_input_window_float(window_buf701_buf701d),get_output_window_float(window_buf704_buf704d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf702_buf702d,LOCK_38_6_0_0,LOCK_38_6_1_0,buf702_ptr,buf702d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf703_buf703d,LOCK_39_6_2_4096,LOCK_39_6_3_4096,buf703_ptr,buf703d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf701_buf701d,LOCK_39_5_4_0,LOCK_39_5_5_0,buf701_ptr,buf701d_ptr,0,index, REL_WRITE);
    window_release(window_buf704_buf704d,LOCK_39_7_0_0,LOCK_39_7_1_0,buf704_ptr,buf704d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_6_bounds > 0)
      --proc_39_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}