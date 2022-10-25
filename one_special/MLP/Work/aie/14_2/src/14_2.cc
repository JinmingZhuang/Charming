// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_2/src/14_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_13_2_2_4096 18
#define LOCK_13_2_3_4096 19
#define LOCK_14_3_0_0 32
#define LOCK_14_3_1_0 33
#define LOCK_14_1_6_4096 6
#define LOCK_14_1_7_4096 7
#define LOCK_14_3_2_0 34
#define LOCK_14_3_3_0 35

// Declare shared memory buffers
v4float buf149[256];
v4float buf149d[256];
v4float buf150[256];
v4float buf150d[256];
v4float buf151[256];
v4float buf151d[256];
v4float buf152[256];
v4float buf152d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf150_buf150d[1];
  window_datatype * buf150_ptr = (window_datatype * )buf150;
  window_datatype * buf150d_ptr = (window_datatype * )buf150d;
  window_init(window_buf150_buf150d, 1, buf150, LOCK_13_2_2_4096, buf150d, LOCK_13_2_3_4096, 256, 256);
  window_internal window_buf151_buf151d[1];
  window_datatype * buf151_ptr = (window_datatype * )buf151;
  window_datatype * buf151d_ptr = (window_datatype * )buf151d;
  window_init(window_buf151_buf151d, 1, buf151, LOCK_14_3_0_0, buf151d, LOCK_14_3_1_0, 256, 256);
  window_internal window_buf149_buf149d[1];
  window_datatype * buf149_ptr = (window_datatype * )buf149;
  window_datatype * buf149d_ptr = (window_datatype * )buf149d;
  window_init(window_buf149_buf149d, 1, buf149, LOCK_14_1_6_4096, buf149d, LOCK_14_1_7_4096, 256, 256);
  window_internal window_buf152_buf152d[1];
  window_datatype * buf152_ptr = (window_datatype * )buf152;
  window_datatype * buf152d_ptr = (window_datatype * )buf152d;
  window_init(window_buf152_buf152d, 1, buf152, LOCK_14_3_2_0, buf152d, LOCK_14_3_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_2_bounds = sync_buffer[1];

  while (proc_14_2_bounds)
  {

    // Kernel call : i156:mm_kernel1
    window_acquire(window_buf150_buf150d,LOCK_13_2_2_4096,LOCK_13_2_3_4096,buf150_ptr,buf150d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf151_buf151d,LOCK_14_3_0_0,LOCK_14_3_1_0,buf151_ptr,buf151d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf149_buf149d,LOCK_14_1_6_4096,LOCK_14_1_7_4096,buf149_ptr,buf149d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf152_buf152d,LOCK_14_3_2_0,LOCK_14_3_3_0,buf152_ptr,buf152d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf150_buf150d),get_input_window_float(window_buf151_buf151d),get_input_window_float(window_buf149_buf149d),get_output_window_float(window_buf152_buf152d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf150_buf150d,LOCK_13_2_2_4096,LOCK_13_2_3_4096,buf150_ptr,buf150d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf151_buf151d,LOCK_14_3_0_0,LOCK_14_3_1_0,buf151_ptr,buf151d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf149_buf149d,LOCK_14_1_6_4096,LOCK_14_1_7_4096,buf149_ptr,buf149d_ptr,0,index, REL_WRITE);
    window_release(window_buf152_buf152d,LOCK_14_3_2_0,LOCK_14_3_3_0,buf152_ptr,buf152d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_2_bounds > 0)
      --proc_14_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}