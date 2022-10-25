// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_6/src/14_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_6_0_4096 48
#define LOCK_14_6_1_4096 49
#define LOCK_14_6_2_0 50
#define LOCK_14_6_3_0 51
#define LOCK_14_5_4_0 4
#define LOCK_14_5_5_4096 5
#define LOCK_14_6_4_0 52
#define LOCK_14_6_5_4096 53

// Declare shared memory buffers
v4float buf1001[256];
v4float buf1001d[256];
v4float buf1002[256];
v4float buf1002d[256];
v4float buf1003[256];
v4float buf1003d[256];
v4float buf1004[256];
v4float buf1004d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1002_buf1002d[1];
  window_datatype * buf1002_ptr = (window_datatype * )buf1002;
  window_datatype * buf1002d_ptr = (window_datatype * )buf1002d;
  window_init(window_buf1002_buf1002d, 1, buf1002, LOCK_14_6_0_4096, buf1002d, LOCK_14_6_1_4096, 256, 256);
  window_internal window_buf1003_buf1003d[1];
  window_datatype * buf1003_ptr = (window_datatype * )buf1003;
  window_datatype * buf1003d_ptr = (window_datatype * )buf1003d;
  window_init(window_buf1003_buf1003d, 1, buf1003, LOCK_14_6_2_0, buf1003d, LOCK_14_6_3_0, 256, 256);
  window_internal window_buf1001_buf1001d[1];
  window_datatype * buf1001_ptr = (window_datatype * )buf1001;
  window_datatype * buf1001d_ptr = (window_datatype * )buf1001d;
  window_init(window_buf1001_buf1001d, 1, buf1001, LOCK_14_5_4_0, buf1001d, LOCK_14_5_5_4096, 256, 256);
  window_internal window_buf1004_buf1004d[1];
  window_datatype * buf1004_ptr = (window_datatype * )buf1004;
  window_datatype * buf1004d_ptr = (window_datatype * )buf1004d;
  window_init(window_buf1004_buf1004d, 1, buf1004, LOCK_14_6_4_0, buf1004d, LOCK_14_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_6_bounds = sync_buffer[1];

  while (proc_14_6_bounds)
  {

    // Kernel call : i582:mm_kernel1
    window_acquire(window_buf1002_buf1002d,LOCK_14_6_0_4096,LOCK_14_6_1_4096,buf1002_ptr,buf1002d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1003_buf1003d,LOCK_14_6_2_0,LOCK_14_6_3_0,buf1003_ptr,buf1003d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1001_buf1001d,LOCK_14_5_4_0,LOCK_14_5_5_4096,buf1001_ptr,buf1001d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1004_buf1004d,LOCK_14_6_4_0,LOCK_14_6_5_4096,buf1004_ptr,buf1004d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1002_buf1002d),get_input_window_float(window_buf1003_buf1003d),get_input_window_float(window_buf1001_buf1001d),get_output_window_float(window_buf1004_buf1004d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1002_buf1002d,LOCK_14_6_0_4096,LOCK_14_6_1_4096,buf1002_ptr,buf1002d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1003_buf1003d,LOCK_14_6_2_0,LOCK_14_6_3_0,buf1003_ptr,buf1003d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1001_buf1001d,LOCK_14_5_4_0,LOCK_14_5_5_4096,buf1001_ptr,buf1001d_ptr,0,index, REL_WRITE);
    window_release(window_buf1004_buf1004d,LOCK_14_6_4_0,LOCK_14_6_5_4096,buf1004_ptr,buf1004d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_6_bounds > 0)
      --proc_14_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}