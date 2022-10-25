// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_4/src/20_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_3_6_4096 6
#define LOCK_20_3_7_0 7
#define LOCK_20_4_2_4096 50
#define LOCK_20_4_3_4096 51
#define LOCK_20_5_0_0 32
#define LOCK_20_5_1_0 33

// Declare shared memory buffers
v4float buf924[256];
v4float buf924d[256];
v4float buf925[256];
v4float buf925d[256];
v4float buf926[256];
v4float buf926d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf924_buf924d[1];
  window_datatype * buf924_ptr = (window_datatype * )buf924;
  window_datatype * buf924d_ptr = (window_datatype * )buf924d;
  window_init(window_buf924_buf924d, 1, buf924, LOCK_20_3_6_4096, buf924d, LOCK_20_3_7_0, 256, 256);
  window_internal window_buf925_buf925d[1];
  window_datatype * buf925_ptr = (window_datatype * )buf925;
  window_datatype * buf925d_ptr = (window_datatype * )buf925d;
  window_init(window_buf925_buf925d, 1, buf925, LOCK_20_4_2_4096, buf925d, LOCK_20_4_3_4096, 256, 256);
  window_internal window_buf926_buf926d[1];
  window_datatype * buf926_ptr = (window_datatype * )buf926;
  window_datatype * buf926d_ptr = (window_datatype * )buf926d;
  window_init(window_buf926_buf926d, 1, buf926, LOCK_20_5_0_0, buf926d, LOCK_20_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_4_bounds = sync_buffer[1];

  while (proc_20_4_bounds)
  {

    // Kernel call : i544:mm_kernel0
    window_acquire(window_buf924_buf924d,LOCK_20_3_6_4096,LOCK_20_3_7_0,buf924_ptr,buf924d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf925_buf925d,LOCK_20_4_2_4096,LOCK_20_4_3_4096,buf925_ptr,buf925d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf926_buf926d,LOCK_20_5_0_0,LOCK_20_5_1_0,buf926_ptr,buf926d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf924_buf924d),get_input_window_float(window_buf925_buf925d),get_output_window_float(window_buf926_buf926d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf924_buf924d,LOCK_20_3_6_4096,LOCK_20_3_7_0,buf924_ptr,buf924d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf925_buf925d,LOCK_20_4_2_4096,LOCK_20_4_3_4096,buf925_ptr,buf925d_ptr,0,index, REL_WRITE);
    window_release(window_buf926_buf926d,LOCK_20_5_0_0,LOCK_20_5_1_0,buf926_ptr,buf926d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_4_bounds > 0)
      --proc_20_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}