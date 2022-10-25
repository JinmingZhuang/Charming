// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_2/src/26_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_26_2_0_0 48
#define LOCK_26_2_1_4096 49
#define LOCK_26_1_6_4096 6
#define LOCK_26_1_7_0 7
#define LOCK_26_1_4_0 4
#define LOCK_26_1_5_4096 5
#define LOCK_26_2_2_4096 50
#define LOCK_26_2_3_4096 51

// Declare shared memory buffers
v4float buf293[256];
v4float buf293d[256];
v4float buf294[256];
v4float buf294d[256];
v4float buf295[256];
v4float buf295d[256];
v4float buf296[256];
v4float buf296d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf294_buf294d[1];
  window_datatype * buf294_ptr = (window_datatype * )buf294;
  window_datatype * buf294d_ptr = (window_datatype * )buf294d;
  window_init(window_buf294_buf294d, 1, buf294, LOCK_26_2_0_0, buf294d, LOCK_26_2_1_4096, 256, 256);
  window_internal window_buf295_buf295d[1];
  window_datatype * buf295_ptr = (window_datatype * )buf295;
  window_datatype * buf295d_ptr = (window_datatype * )buf295d;
  window_init(window_buf295_buf295d, 1, buf295, LOCK_26_1_6_4096, buf295d, LOCK_26_1_7_0, 256, 256);
  window_internal window_buf293_buf293d[1];
  window_datatype * buf293_ptr = (window_datatype * )buf293;
  window_datatype * buf293d_ptr = (window_datatype * )buf293d;
  window_init(window_buf293_buf293d, 1, buf293, LOCK_26_1_4_0, buf293d, LOCK_26_1_5_4096, 256, 256);
  window_internal window_buf296_buf296d[1];
  window_datatype * buf296_ptr = (window_datatype * )buf296;
  window_datatype * buf296d_ptr = (window_datatype * )buf296d;
  window_init(window_buf296_buf296d, 1, buf296, LOCK_26_2_2_4096, buf296d, LOCK_26_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_2_bounds = sync_buffer[1];

  while (proc_26_2_bounds)
  {

    // Kernel call : i228:mm_kernel1
    window_acquire(window_buf294_buf294d,LOCK_26_2_0_0,LOCK_26_2_1_4096,buf294_ptr,buf294d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf295_buf295d,LOCK_26_1_6_4096,LOCK_26_1_7_0,buf295_ptr,buf295d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf293_buf293d,LOCK_26_1_4_0,LOCK_26_1_5_4096,buf293_ptr,buf293d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf296_buf296d,LOCK_26_2_2_4096,LOCK_26_2_3_4096,buf296_ptr,buf296d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf294_buf294d),get_input_window_float(window_buf295_buf295d),get_input_window_float(window_buf293_buf293d),get_output_window_float(window_buf296_buf296d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf294_buf294d,LOCK_26_2_0_0,LOCK_26_2_1_4096,buf294_ptr,buf294d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf295_buf295d,LOCK_26_1_6_4096,LOCK_26_1_7_0,buf295_ptr,buf295d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf293_buf293d,LOCK_26_1_4_0,LOCK_26_1_5_4096,buf293_ptr,buf293d_ptr,0,index, REL_WRITE);
    window_release(window_buf296_buf296d,LOCK_26_2_2_4096,LOCK_26_2_3_4096,buf296_ptr,buf296d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_2_bounds > 0)
      --proc_26_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}