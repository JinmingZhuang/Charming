// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_6/src/2_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_2_5_4_4096 4
#define LOCK_2_5_5_4096 5
#define LOCK_1_6_0_0 16
#define LOCK_1_6_1_0 17
#define LOCK_2_5_2_0 2
#define LOCK_2_5_3_0 3
#define LOCK_2_6_0_0 48
#define LOCK_2_6_1_1376 49

// Declare shared memory buffers
v4float buf1145[256];
v4float buf1145d[256];
v4float buf1146[256];
v4float buf1146d[256];
v4float buf1147[256];
v4float buf1147d[256];
v4float buf1148[256];
v4float buf1148d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1146_buf1146d[1];
  window_datatype * buf1146_ptr = (window_datatype * )buf1146;
  window_datatype * buf1146d_ptr = (window_datatype * )buf1146d;
  window_init(window_buf1146_buf1146d, 1, buf1146, LOCK_2_5_4_4096, buf1146d, LOCK_2_5_5_4096, 256, 256);
  window_internal window_buf1147_buf1147d[1];
  window_datatype * buf1147_ptr = (window_datatype * )buf1147;
  window_datatype * buf1147d_ptr = (window_datatype * )buf1147d;
  window_init(window_buf1147_buf1147d, 1, buf1147, LOCK_1_6_0_0, buf1147d, LOCK_1_6_1_0, 256, 256);
  window_internal window_buf1145_buf1145d[1];
  window_datatype * buf1145_ptr = (window_datatype * )buf1145;
  window_datatype * buf1145d_ptr = (window_datatype * )buf1145d;
  window_init(window_buf1145_buf1145d, 1, buf1145, LOCK_2_5_2_0, buf1145d, LOCK_2_5_3_0, 256, 256);
  window_internal window_buf1148_buf1148d[1];
  window_datatype * buf1148_ptr = (window_datatype * )buf1148;
  window_datatype * buf1148d_ptr = (window_datatype * )buf1148d;
  window_init(window_buf1148_buf1148d, 1, buf1148, LOCK_2_6_0_0, buf1148d, LOCK_2_6_1_1376, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_6_bounds = sync_buffer[1];

  while (proc_2_6_bounds)
  {

    // Kernel call : i654:mm_kernel1
    window_acquire(window_buf1146_buf1146d,LOCK_2_5_4_4096,LOCK_2_5_5_4096,buf1146_ptr,buf1146d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1147_buf1147d,LOCK_1_6_0_0,LOCK_1_6_1_0,buf1147_ptr,buf1147d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1145_buf1145d,LOCK_2_5_2_0,LOCK_2_5_3_0,buf1145_ptr,buf1145d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1148_buf1148d,LOCK_2_6_0_0,LOCK_2_6_1_1376,buf1148_ptr,buf1148d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1146_buf1146d),get_input_window_float(window_buf1147_buf1147d),get_input_window_float(window_buf1145_buf1145d),get_output_window_float(window_buf1148_buf1148d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1146_buf1146d,LOCK_2_5_4_4096,LOCK_2_5_5_4096,buf1146_ptr,buf1146d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1147_buf1147d,LOCK_1_6_0_0,LOCK_1_6_1_0,buf1147_ptr,buf1147d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1145_buf1145d,LOCK_2_5_2_0,LOCK_2_5_3_0,buf1145_ptr,buf1145d_ptr,0,index, REL_WRITE);
    window_release(window_buf1148_buf1148d,LOCK_2_6_0_0,LOCK_2_6_1_1376,buf1148_ptr,buf1148d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_6_bounds > 0)
      --proc_2_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}