// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_1/src/24_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_2_0_0 32
#define LOCK_24_2_1_4096 33
#define LOCK_24_1_2_4096 18
#define LOCK_24_1_3_0 19
#define LOCK_24_1_0_0 16
#define LOCK_24_1_1_4096 17
#define LOCK_24_1_4_0 20
#define LOCK_24_1_5_4096 21

// Declare shared memory buffers
v4float buf266[256];
v4float buf266d[256];
v4float buf267[256];
v4float buf267d[256];
v4float buf268[256];
v4float buf268d[256];
v4float buf269[256];
v4float buf269d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf267_buf267d[1];
  window_datatype * buf267_ptr = (window_datatype * )buf267;
  window_datatype * buf267d_ptr = (window_datatype * )buf267d;
  window_init(window_buf267_buf267d, 1, buf267, LOCK_24_2_0_0, buf267d, LOCK_24_2_1_4096, 256, 256);
  window_internal window_buf268_buf268d[1];
  window_datatype * buf268_ptr = (window_datatype * )buf268;
  window_datatype * buf268d_ptr = (window_datatype * )buf268d;
  window_init(window_buf268_buf268d, 1, buf268, LOCK_24_1_2_4096, buf268d, LOCK_24_1_3_0, 256, 256);
  window_internal window_buf266_buf266d[1];
  window_datatype * buf266_ptr = (window_datatype * )buf266;
  window_datatype * buf266d_ptr = (window_datatype * )buf266d;
  window_init(window_buf266_buf266d, 1, buf266, LOCK_24_1_0_0, buf266d, LOCK_24_1_1_4096, 256, 256);
  window_internal window_buf269_buf269d[1];
  window_datatype * buf269_ptr = (window_datatype * )buf269;
  window_datatype * buf269d_ptr = (window_datatype * )buf269d;
  window_init(window_buf269_buf269d, 1, buf269, LOCK_24_1_4_0, buf269d, LOCK_24_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_1_bounds = sync_buffer[1];

  while (proc_24_1_bounds)
  {

    // Kernel call : i215:mm_kernel1
    window_acquire(window_buf267_buf267d,LOCK_24_2_0_0,LOCK_24_2_1_4096,buf267_ptr,buf267d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf268_buf268d,LOCK_24_1_2_4096,LOCK_24_1_3_0,buf268_ptr,buf268d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf266_buf266d,LOCK_24_1_0_0,LOCK_24_1_1_4096,buf266_ptr,buf266d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf269_buf269d,LOCK_24_1_4_0,LOCK_24_1_5_4096,buf269_ptr,buf269d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf267_buf267d),get_input_window_float(window_buf268_buf268d),get_input_window_float(window_buf266_buf266d),get_output_window_float(window_buf269_buf269d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf267_buf267d,LOCK_24_2_0_0,LOCK_24_2_1_4096,buf267_ptr,buf267d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf268_buf268d,LOCK_24_1_2_4096,LOCK_24_1_3_0,buf268_ptr,buf268d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf266_buf266d,LOCK_24_1_0_0,LOCK_24_1_1_4096,buf266_ptr,buf266d_ptr,0,index, REL_WRITE);
    window_release(window_buf269_buf269d,LOCK_24_1_4_0,LOCK_24_1_5_4096,buf269_ptr,buf269d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_1_bounds > 0)
      --proc_24_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}