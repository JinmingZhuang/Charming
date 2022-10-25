// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/13_5/src/13_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_5_6_4096 54
#define LOCK_14_5_7_4096 55
#define LOCK_13_6_0_0 32
#define LOCK_13_6_1_4096 33
#define LOCK_13_5_0_0 16
#define LOCK_13_5_1_4096 17
#define LOCK_13_5_2_0 18
#define LOCK_13_5_3_0 19

// Declare shared memory buffers
v4float buf1010[256];
v4float buf1010d[256];
v4float buf1011[256];
v4float buf1011d[256];
v4float buf1012[256];
v4float buf1012d[256];
v4float buf1013[256];
v4float buf1013d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1011_buf1011d[1];
  window_datatype * buf1011_ptr = (window_datatype * )buf1011;
  window_datatype * buf1011d_ptr = (window_datatype * )buf1011d;
  window_init(window_buf1011_buf1011d, 1, buf1011, LOCK_14_5_6_4096, buf1011d, LOCK_14_5_7_4096, 256, 256);
  window_internal window_buf1012_buf1012d[1];
  window_datatype * buf1012_ptr = (window_datatype * )buf1012;
  window_datatype * buf1012d_ptr = (window_datatype * )buf1012d;
  window_init(window_buf1012_buf1012d, 1, buf1012, LOCK_13_6_0_0, buf1012d, LOCK_13_6_1_4096, 256, 256);
  window_internal window_buf1010_buf1010d[1];
  window_datatype * buf1010_ptr = (window_datatype * )buf1010;
  window_datatype * buf1010d_ptr = (window_datatype * )buf1010d;
  window_init(window_buf1010_buf1010d, 1, buf1010, LOCK_13_5_0_0, buf1010d, LOCK_13_5_1_4096, 256, 256);
  window_internal window_buf1013_buf1013d[1];
  window_datatype * buf1013_ptr = (window_datatype * )buf1013;
  window_datatype * buf1013d_ptr = (window_datatype * )buf1013d;
  window_init(window_buf1013_buf1013d, 1, buf1013, LOCK_13_5_2_0, buf1013d, LOCK_13_5_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_13_5_bounds = sync_buffer[1];

  while (proc_13_5_bounds)
  {

    // Kernel call : i587:mm_kernel1
    window_acquire(window_buf1011_buf1011d,LOCK_14_5_6_4096,LOCK_14_5_7_4096,buf1011_ptr,buf1011d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1012_buf1012d,LOCK_13_6_0_0,LOCK_13_6_1_4096,buf1012_ptr,buf1012d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1010_buf1010d,LOCK_13_5_0_0,LOCK_13_5_1_4096,buf1010_ptr,buf1010d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1013_buf1013d,LOCK_13_5_2_0,LOCK_13_5_3_0,buf1013_ptr,buf1013d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1011_buf1011d),get_input_window_float(window_buf1012_buf1012d),get_input_window_float(window_buf1010_buf1010d),get_output_window_float(window_buf1013_buf1013d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1011_buf1011d,LOCK_14_5_6_4096,LOCK_14_5_7_4096,buf1011_ptr,buf1011d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1012_buf1012d,LOCK_13_6_0_0,LOCK_13_6_1_4096,buf1012_ptr,buf1012d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1010_buf1010d,LOCK_13_5_0_0,LOCK_13_5_1_4096,buf1010_ptr,buf1010d_ptr,0,index, REL_WRITE);
    window_release(window_buf1013_buf1013d,LOCK_13_5_2_0,LOCK_13_5_3_0,buf1013_ptr,buf1013d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_13_5_bounds > 0)
      --proc_13_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}