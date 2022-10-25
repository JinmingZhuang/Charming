// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_2/src/8_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_2_0_0 48
#define LOCK_8_2_1_0 49
#define LOCK_7_2_2_4096 18
#define LOCK_7_2_3_4096 19
#define LOCK_8_1_6_0 6
#define LOCK_8_1_7_4096 7
#define LOCK_8_2_2_4096 50
#define LOCK_8_2_3_4096 51

// Declare shared memory buffers
v4float buf77[256];
v4float buf77d[256];
v4float buf78[256];
v4float buf78d[256];
v4float buf79[256];
v4float buf79d[256];
v4float buf80[256];
v4float buf80d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf78_buf78d[1];
  window_datatype * buf78_ptr = (window_datatype * )buf78;
  window_datatype * buf78d_ptr = (window_datatype * )buf78d;
  window_init(window_buf78_buf78d, 1, buf78, LOCK_8_2_0_0, buf78d, LOCK_8_2_1_0, 256, 256);
  window_internal window_buf79_buf79d[1];
  window_datatype * buf79_ptr = (window_datatype * )buf79;
  window_datatype * buf79d_ptr = (window_datatype * )buf79d;
  window_init(window_buf79_buf79d, 1, buf79, LOCK_7_2_2_4096, buf79d, LOCK_7_2_3_4096, 256, 256);
  window_internal window_buf77_buf77d[1];
  window_datatype * buf77_ptr = (window_datatype * )buf77;
  window_datatype * buf77d_ptr = (window_datatype * )buf77d;
  window_init(window_buf77_buf77d, 1, buf77, LOCK_8_1_6_0, buf77d, LOCK_8_1_7_4096, 256, 256);
  window_internal window_buf80_buf80d[1];
  window_datatype * buf80_ptr = (window_datatype * )buf80;
  window_datatype * buf80d_ptr = (window_datatype * )buf80d;
  window_init(window_buf80_buf80d, 1, buf80, LOCK_8_2_2_4096, buf80d, LOCK_8_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_2_bounds = sync_buffer[1];

  while (proc_8_2_bounds)
  {

    // Kernel call : i120:mm_kernel1
    window_acquire(window_buf78_buf78d,LOCK_8_2_0_0,LOCK_8_2_1_0,buf78_ptr,buf78d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf79_buf79d,LOCK_7_2_2_4096,LOCK_7_2_3_4096,buf79_ptr,buf79d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf77_buf77d,LOCK_8_1_6_0,LOCK_8_1_7_4096,buf77_ptr,buf77d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf80_buf80d,LOCK_8_2_2_4096,LOCK_8_2_3_4096,buf80_ptr,buf80d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf78_buf78d),get_input_window_float(window_buf79_buf79d),get_input_window_float(window_buf77_buf77d),get_output_window_float(window_buf80_buf80d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf78_buf78d,LOCK_8_2_0_0,LOCK_8_2_1_0,buf78_ptr,buf78d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf79_buf79d,LOCK_7_2_2_4096,LOCK_7_2_3_4096,buf79_ptr,buf79d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf77_buf77d,LOCK_8_1_6_0,LOCK_8_1_7_4096,buf77_ptr,buf77d_ptr,0,index, REL_WRITE);
    window_release(window_buf80_buf80d,LOCK_8_2_2_4096,LOCK_8_2_3_4096,buf80_ptr,buf80d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_2_bounds > 0)
      --proc_8_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}