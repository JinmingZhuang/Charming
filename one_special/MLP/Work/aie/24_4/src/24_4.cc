// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_4/src/24_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_23_4_0_4096 16
#define LOCK_23_4_1_4096 17
#define LOCK_23_4_2_0 18
#define LOCK_23_4_3_0 19
#define LOCK_24_5_0_0 32
#define LOCK_24_5_1_0 33

// Declare shared memory buffers
v4float buf876[256];
v4float buf876d[256];
v4float buf877[256];
v4float buf877d[256];
v4float buf878[256];
v4float buf878d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf876_buf876d[1];
  window_datatype * buf876_ptr = (window_datatype * )buf876;
  window_datatype * buf876d_ptr = (window_datatype * )buf876d;
  window_init(window_buf876_buf876d, 1, buf876, LOCK_23_4_0_4096, buf876d, LOCK_23_4_1_4096, 256, 256);
  window_internal window_buf877_buf877d[1];
  window_datatype * buf877_ptr = (window_datatype * )buf877;
  window_datatype * buf877d_ptr = (window_datatype * )buf877d;
  window_init(window_buf877_buf877d, 1, buf877, LOCK_23_4_2_0, buf877d, LOCK_23_4_3_0, 256, 256);
  window_internal window_buf878_buf878d[1];
  window_datatype * buf878_ptr = (window_datatype * )buf878;
  window_datatype * buf878d_ptr = (window_datatype * )buf878d;
  window_init(window_buf878_buf878d, 1, buf878, LOCK_24_5_0_0, buf878d, LOCK_24_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_4_bounds = sync_buffer[1];

  while (proc_24_4_bounds)
  {

    // Kernel call : i520:mm_kernel0
    window_acquire(window_buf876_buf876d,LOCK_23_4_0_4096,LOCK_23_4_1_4096,buf876_ptr,buf876d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf877_buf877d,LOCK_23_4_2_0,LOCK_23_4_3_0,buf877_ptr,buf877d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf878_buf878d,LOCK_24_5_0_0,LOCK_24_5_1_0,buf878_ptr,buf878d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf876_buf876d),get_input_window_float(window_buf877_buf877d),get_output_window_float(window_buf878_buf878d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf876_buf876d,LOCK_23_4_0_4096,LOCK_23_4_1_4096,buf876_ptr,buf876d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf877_buf877d,LOCK_23_4_2_0,LOCK_23_4_3_0,buf877_ptr,buf877d_ptr,0,index, REL_WRITE);
    window_release(window_buf878_buf878d,LOCK_24_5_0_0,LOCK_24_5_1_0,buf878_ptr,buf878d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_4_bounds > 0)
      --proc_24_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}