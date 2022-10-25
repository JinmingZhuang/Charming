// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/17_5/src/17_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_17_4_2_4096 2
#define LOCK_17_4_3_4096 3
#define LOCK_17_6_0_0 32
#define LOCK_17_6_1_0 33
#define LOCK_17_5_2_0 18
#define LOCK_17_5_3_4096 19
#define LOCK_17_5_4_4096 20
#define LOCK_17_5_5_0 21

// Declare shared memory buffers
v4float buf962[256];
v4float buf962d[256];
v4float buf963[256];
v4float buf963d[256];
v4float buf964[256];
v4float buf964d[256];
v4float buf965[256];
v4float buf965d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf963_buf963d[1];
  window_datatype * buf963_ptr = (window_datatype * )buf963;
  window_datatype * buf963d_ptr = (window_datatype * )buf963d;
  window_init(window_buf963_buf963d, 1, buf963, LOCK_17_4_2_4096, buf963d, LOCK_17_4_3_4096, 256, 256);
  window_internal window_buf964_buf964d[1];
  window_datatype * buf964_ptr = (window_datatype * )buf964;
  window_datatype * buf964d_ptr = (window_datatype * )buf964d;
  window_init(window_buf964_buf964d, 1, buf964, LOCK_17_6_0_0, buf964d, LOCK_17_6_1_0, 256, 256);
  window_internal window_buf962_buf962d[1];
  window_datatype * buf962_ptr = (window_datatype * )buf962;
  window_datatype * buf962d_ptr = (window_datatype * )buf962d;
  window_init(window_buf962_buf962d, 1, buf962, LOCK_17_5_2_0, buf962d, LOCK_17_5_3_4096, 256, 256);
  window_internal window_buf965_buf965d[1];
  window_datatype * buf965_ptr = (window_datatype * )buf965;
  window_datatype * buf965d_ptr = (window_datatype * )buf965d;
  window_init(window_buf965_buf965d, 1, buf965, LOCK_17_5_4_4096, buf965d, LOCK_17_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_17_5_bounds = sync_buffer[1];

  while (proc_17_5_bounds)
  {

    // Kernel call : i563:mm_kernel1
    window_acquire(window_buf963_buf963d,LOCK_17_4_2_4096,LOCK_17_4_3_4096,buf963_ptr,buf963d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf964_buf964d,LOCK_17_6_0_0,LOCK_17_6_1_0,buf964_ptr,buf964d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf962_buf962d,LOCK_17_5_2_0,LOCK_17_5_3_4096,buf962_ptr,buf962d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf965_buf965d,LOCK_17_5_4_4096,LOCK_17_5_5_0,buf965_ptr,buf965d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf963_buf963d),get_input_window_float(window_buf964_buf964d),get_input_window_float(window_buf962_buf962d),get_output_window_float(window_buf965_buf965d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf963_buf963d,LOCK_17_4_2_4096,LOCK_17_4_3_4096,buf963_ptr,buf963d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf964_buf964d,LOCK_17_6_0_0,LOCK_17_6_1_0,buf964_ptr,buf964d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf962_buf962d,LOCK_17_5_2_0,LOCK_17_5_3_4096,buf962_ptr,buf962d_ptr,0,index, REL_WRITE);
    window_release(window_buf965_buf965d,LOCK_17_5_4_4096,LOCK_17_5_5_0,buf965_ptr,buf965d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_17_5_bounds > 0)
      --proc_17_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}