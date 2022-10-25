// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_3/src/24_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_2_4_0 4
#define LOCK_24_2_5_0 5
#define LOCK_24_4_0_0 32
#define LOCK_24_4_1_0 33
#define LOCK_24_2_2_0 2
#define LOCK_24_2_3_4096 3
#define LOCK_24_2_6_4096 6
#define LOCK_24_2_7_4096 7

// Declare shared memory buffers
v4float buf272[256];
v4float buf272d[256];
v4float buf273[256];
v4float buf273d[256];
v4float buf274[256];
v4float buf274d[256];
v4float buf275[256];
v4float buf275d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf273_buf273d[1];
  window_datatype * buf273_ptr = (window_datatype * )buf273;
  window_datatype * buf273d_ptr = (window_datatype * )buf273d;
  window_init(window_buf273_buf273d, 1, buf273, LOCK_24_2_4_0, buf273d, LOCK_24_2_5_0, 256, 256);
  window_internal window_buf274_buf274d[1];
  window_datatype * buf274_ptr = (window_datatype * )buf274;
  window_datatype * buf274d_ptr = (window_datatype * )buf274d;
  window_init(window_buf274_buf274d, 1, buf274, LOCK_24_4_0_0, buf274d, LOCK_24_4_1_0, 256, 256);
  window_internal window_buf272_buf272d[1];
  window_datatype * buf272_ptr = (window_datatype * )buf272;
  window_datatype * buf272d_ptr = (window_datatype * )buf272d;
  window_init(window_buf272_buf272d, 1, buf272, LOCK_24_2_2_0, buf272d, LOCK_24_2_3_4096, 256, 256);
  window_internal window_buf275_buf275d[1];
  window_datatype * buf275_ptr = (window_datatype * )buf275;
  window_datatype * buf275d_ptr = (window_datatype * )buf275d;
  window_init(window_buf275_buf275d, 1, buf275, LOCK_24_2_6_4096, buf275d, LOCK_24_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_3_bounds = sync_buffer[1];

  while (proc_24_3_bounds)
  {

    // Kernel call : i217:mm_kernel1
    window_acquire(window_buf273_buf273d,LOCK_24_2_4_0,LOCK_24_2_5_0,buf273_ptr,buf273d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf274_buf274d,LOCK_24_4_0_0,LOCK_24_4_1_0,buf274_ptr,buf274d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf272_buf272d,LOCK_24_2_2_0,LOCK_24_2_3_4096,buf272_ptr,buf272d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf275_buf275d,LOCK_24_2_6_4096,LOCK_24_2_7_4096,buf275_ptr,buf275d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf273_buf273d),get_input_window_float(window_buf274_buf274d),get_input_window_float(window_buf272_buf272d),get_output_window_float(window_buf275_buf275d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf273_buf273d,LOCK_24_2_4_0,LOCK_24_2_5_0,buf273_ptr,buf273d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf274_buf274d,LOCK_24_4_0_0,LOCK_24_4_1_0,buf274_ptr,buf274d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf272_buf272d,LOCK_24_2_2_0,LOCK_24_2_3_4096,buf272_ptr,buf272d_ptr,0,index, REL_WRITE);
    window_release(window_buf275_buf275d,LOCK_24_2_6_4096,LOCK_24_2_7_4096,buf275_ptr,buf275d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_3_bounds > 0)
      --proc_24_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}