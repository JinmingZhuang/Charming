// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_3/src/41_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_41_4_0_0 32
#define LOCK_41_4_1_0 33
#define LOCK_41_2_4_0 4
#define LOCK_41_2_5_0 5
#define LOCK_41_2_2_0 2
#define LOCK_41_2_3_4096 3
#define LOCK_41_2_6_4096 6
#define LOCK_41_2_7_4096 7

// Declare shared memory buffers
v4float buf476[256];
v4float buf476d[256];
v4float buf477[256];
v4float buf477d[256];
v4float buf478[256];
v4float buf478d[256];
v4float buf479[256];
v4float buf479d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf477_buf477d[1];
  window_datatype * buf477_ptr = (window_datatype * )buf477;
  window_datatype * buf477d_ptr = (window_datatype * )buf477d;
  window_init(window_buf477_buf477d, 1, buf477, LOCK_41_4_0_0, buf477d, LOCK_41_4_1_0, 256, 256);
  window_internal window_buf478_buf478d[1];
  window_datatype * buf478_ptr = (window_datatype * )buf478;
  window_datatype * buf478d_ptr = (window_datatype * )buf478d;
  window_init(window_buf478_buf478d, 1, buf478, LOCK_41_2_4_0, buf478d, LOCK_41_2_5_0, 256, 256);
  window_internal window_buf476_buf476d[1];
  window_datatype * buf476_ptr = (window_datatype * )buf476;
  window_datatype * buf476d_ptr = (window_datatype * )buf476d;
  window_init(window_buf476_buf476d, 1, buf476, LOCK_41_2_2_0, buf476d, LOCK_41_2_3_4096, 256, 256);
  window_internal window_buf479_buf479d[1];
  window_datatype * buf479_ptr = (window_datatype * )buf479;
  window_datatype * buf479d_ptr = (window_datatype * )buf479d;
  window_init(window_buf479_buf479d, 1, buf479, LOCK_41_2_6_4096, buf479d, LOCK_41_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_3_bounds = sync_buffer[1];

  while (proc_41_3_bounds)
  {

    // Kernel call : i319:mm_kernel1
    window_acquire(window_buf477_buf477d,LOCK_41_4_0_0,LOCK_41_4_1_0,buf477_ptr,buf477d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf478_buf478d,LOCK_41_2_4_0,LOCK_41_2_5_0,buf478_ptr,buf478d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf476_buf476d,LOCK_41_2_2_0,LOCK_41_2_3_4096,buf476_ptr,buf476d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf479_buf479d,LOCK_41_2_6_4096,LOCK_41_2_7_4096,buf479_ptr,buf479d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf477_buf477d),get_input_window_float(window_buf478_buf478d),get_input_window_float(window_buf476_buf476d),get_output_window_float(window_buf479_buf479d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf477_buf477d,LOCK_41_4_0_0,LOCK_41_4_1_0,buf477_ptr,buf477d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf478_buf478d,LOCK_41_2_4_0,LOCK_41_2_5_0,buf478_ptr,buf478d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf476_buf476d,LOCK_41_2_2_0,LOCK_41_2_3_4096,buf476_ptr,buf476d_ptr,0,index, REL_WRITE);
    window_release(window_buf479_buf479d,LOCK_41_2_6_4096,LOCK_41_2_7_4096,buf479_ptr,buf479d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_3_bounds > 0)
      --proc_41_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}