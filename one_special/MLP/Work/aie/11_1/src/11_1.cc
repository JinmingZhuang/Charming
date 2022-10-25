// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_1/src/11_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_0_2_4096 2
#define LOCK_11_0_3_4096 3
#define LOCK_11_1_4_4096 20
#define LOCK_11_1_5_0 21
#define LOCK_11_1_2_4096 18
#define LOCK_11_1_3_4096 19
#define LOCK_11_1_6_0 22
#define LOCK_11_1_7_0 23

// Declare shared memory buffers
v4float buf110[256];
v4float buf110d[256];
v4float buf111[256];
v4float buf111d[256];
v4float buf112[256];
v4float buf112d[256];
v4float buf113[256];
v4float buf113d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf111_buf111d[1];
  window_datatype * buf111_ptr = (window_datatype * )buf111;
  window_datatype * buf111d_ptr = (window_datatype * )buf111d;
  window_init(window_buf111_buf111d, 1, buf111, LOCK_11_0_2_4096, buf111d, LOCK_11_0_3_4096, 256, 256);
  window_internal window_buf112_buf112d[1];
  window_datatype * buf112_ptr = (window_datatype * )buf112;
  window_datatype * buf112d_ptr = (window_datatype * )buf112d;
  window_init(window_buf112_buf112d, 1, buf112, LOCK_11_1_4_4096, buf112d, LOCK_11_1_5_0, 256, 256);
  window_internal window_buf110_buf110d[1];
  window_datatype * buf110_ptr = (window_datatype * )buf110;
  window_datatype * buf110d_ptr = (window_datatype * )buf110d;
  window_init(window_buf110_buf110d, 1, buf110, LOCK_11_1_2_4096, buf110d, LOCK_11_1_3_4096, 256, 256);
  window_internal window_buf113_buf113d[1];
  window_datatype * buf113_ptr = (window_datatype * )buf113;
  window_datatype * buf113d_ptr = (window_datatype * )buf113d;
  window_init(window_buf113_buf113d, 1, buf113, LOCK_11_1_6_0, buf113d, LOCK_11_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_1_bounds = sync_buffer[1];

  while (proc_11_1_bounds)
  {

    // Kernel call : i137:mm_kernel1
    window_acquire(window_buf111_buf111d,LOCK_11_0_2_4096,LOCK_11_0_3_4096,buf111_ptr,buf111d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf112_buf112d,LOCK_11_1_4_4096,LOCK_11_1_5_0,buf112_ptr,buf112d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf110_buf110d,LOCK_11_1_2_4096,LOCK_11_1_3_4096,buf110_ptr,buf110d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf113_buf113d,LOCK_11_1_6_0,LOCK_11_1_7_0,buf113_ptr,buf113d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf111_buf111d),get_input_window_float(window_buf112_buf112d),get_input_window_float(window_buf110_buf110d),get_output_window_float(window_buf113_buf113d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf111_buf111d,LOCK_11_0_2_4096,LOCK_11_0_3_4096,buf111_ptr,buf111d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf112_buf112d,LOCK_11_1_4_4096,LOCK_11_1_5_0,buf112_ptr,buf112d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf110_buf110d,LOCK_11_1_2_4096,LOCK_11_1_3_4096,buf110_ptr,buf110d_ptr,0,index, REL_WRITE);
    window_release(window_buf113_buf113d,LOCK_11_1_6_0,LOCK_11_1_7_0,buf113_ptr,buf113d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_1_bounds > 0)
      --proc_11_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}