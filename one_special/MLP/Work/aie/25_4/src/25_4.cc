// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_4/src/25_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_3_6_4096 6
#define LOCK_25_3_7_4096 7
#define LOCK_25_5_0_0 32
#define LOCK_25_5_1_4096 33
#define LOCK_25_5_2_0 34
#define LOCK_25_5_3_4096 35

// Declare shared memory buffers
v4float buf864[256];
v4float buf864d[256];
v4float buf865[256];
v4float buf865d[256];
v4float buf866[256];
v4float buf866d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf864_buf864d[1];
  window_datatype * buf864_ptr = (window_datatype * )buf864;
  window_datatype * buf864d_ptr = (window_datatype * )buf864d;
  window_init(window_buf864_buf864d, 1, buf864, LOCK_25_3_6_4096, buf864d, LOCK_25_3_7_4096, 256, 256);
  window_internal window_buf865_buf865d[1];
  window_datatype * buf865_ptr = (window_datatype * )buf865;
  window_datatype * buf865d_ptr = (window_datatype * )buf865d;
  window_init(window_buf865_buf865d, 1, buf865, LOCK_25_5_0_0, buf865d, LOCK_25_5_1_4096, 256, 256);
  window_internal window_buf866_buf866d[1];
  window_datatype * buf866_ptr = (window_datatype * )buf866;
  window_datatype * buf866d_ptr = (window_datatype * )buf866d;
  window_init(window_buf866_buf866d, 1, buf866, LOCK_25_5_2_0, buf866d, LOCK_25_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_4_bounds = sync_buffer[1];

  while (proc_25_4_bounds)
  {

    // Kernel call : i514:mm_kernel0
    window_acquire(window_buf864_buf864d,LOCK_25_3_6_4096,LOCK_25_3_7_4096,buf864_ptr,buf864d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf865_buf865d,LOCK_25_5_0_0,LOCK_25_5_1_4096,buf865_ptr,buf865d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf866_buf866d,LOCK_25_5_2_0,LOCK_25_5_3_4096,buf866_ptr,buf866d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf864_buf864d),get_input_window_float(window_buf865_buf865d),get_output_window_float(window_buf866_buf866d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf864_buf864d,LOCK_25_3_6_4096,LOCK_25_3_7_4096,buf864_ptr,buf864d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf865_buf865d,LOCK_25_5_0_0,LOCK_25_5_1_4096,buf865_ptr,buf865d_ptr,0,index, REL_WRITE);
    window_release(window_buf866_buf866d,LOCK_25_5_2_0,LOCK_25_5_3_4096,buf866_ptr,buf866d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_4_bounds > 0)
      --proc_25_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}