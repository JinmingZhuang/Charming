// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_6/src/34_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_7_0_0 32
#define LOCK_34_7_1_0 33
#define LOCK_34_6_0_4096 48
#define LOCK_34_6_1_0 49
#define LOCK_34_5_6_0 6
#define LOCK_34_5_7_0 7
#define LOCK_34_6_2_4096 50
#define LOCK_34_6_3_4096 51

// Declare shared memory buffers
v4float buf761[256];
v4float buf761d[256];
v4float buf762[256];
v4float buf762d[256];
v4float buf763[256];
v4float buf763d[256];
v4float buf764[256];
v4float buf764d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf762_buf762d[1];
  window_datatype * buf762_ptr = (window_datatype * )buf762;
  window_datatype * buf762d_ptr = (window_datatype * )buf762d;
  window_init(window_buf762_buf762d, 1, buf762, LOCK_34_7_0_0, buf762d, LOCK_34_7_1_0, 256, 256);
  window_internal window_buf763_buf763d[1];
  window_datatype * buf763_ptr = (window_datatype * )buf763;
  window_datatype * buf763d_ptr = (window_datatype * )buf763d;
  window_init(window_buf763_buf763d, 1, buf763, LOCK_34_6_0_4096, buf763d, LOCK_34_6_1_0, 256, 256);
  window_internal window_buf761_buf761d[1];
  window_datatype * buf761_ptr = (window_datatype * )buf761;
  window_datatype * buf761d_ptr = (window_datatype * )buf761d;
  window_init(window_buf761_buf761d, 1, buf761, LOCK_34_5_6_0, buf761d, LOCK_34_5_7_0, 256, 256);
  window_internal window_buf764_buf764d[1];
  window_datatype * buf764_ptr = (window_datatype * )buf764;
  window_datatype * buf764d_ptr = (window_datatype * )buf764d;
  window_init(window_buf764_buf764d, 1, buf764, LOCK_34_6_2_4096, buf764d, LOCK_34_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_6_bounds = sync_buffer[1];

  while (proc_34_6_bounds)
  {

    // Kernel call : i462:mm_kernel1
    window_acquire(window_buf762_buf762d,LOCK_34_7_0_0,LOCK_34_7_1_0,buf762_ptr,buf762d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf763_buf763d,LOCK_34_6_0_4096,LOCK_34_6_1_0,buf763_ptr,buf763d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf761_buf761d,LOCK_34_5_6_0,LOCK_34_5_7_0,buf761_ptr,buf761d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf764_buf764d,LOCK_34_6_2_4096,LOCK_34_6_3_4096,buf764_ptr,buf764d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf762_buf762d),get_input_window_float(window_buf763_buf763d),get_input_window_float(window_buf761_buf761d),get_output_window_float(window_buf764_buf764d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf762_buf762d,LOCK_34_7_0_0,LOCK_34_7_1_0,buf762_ptr,buf762d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf763_buf763d,LOCK_34_6_0_4096,LOCK_34_6_1_0,buf763_ptr,buf763d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf761_buf761d,LOCK_34_5_6_0,LOCK_34_5_7_0,buf761_ptr,buf761d_ptr,0,index, REL_WRITE);
    window_release(window_buf764_buf764d,LOCK_34_6_2_4096,LOCK_34_6_3_4096,buf764_ptr,buf764d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_6_bounds > 0)
      --proc_34_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}