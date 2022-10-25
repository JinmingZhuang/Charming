// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_6/src/5_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_4_6_0_0 16
#define LOCK_4_6_1_0 17
#define LOCK_5_5_6_4096 6
#define LOCK_5_5_7_0 7
#define LOCK_5_5_4_0 4
#define LOCK_5_5_5_0 5
#define LOCK_5_6_0_0 48
#define LOCK_5_6_1_0 49

// Declare shared memory buffers
v4float buf1109[256];
v4float buf1109d[256];
v4float buf1110[256];
v4float buf1110d[256];
v4float buf1111[256];
v4float buf1111d[256];
v4float buf1112[256];
v4float buf1112d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1110_buf1110d[1];
  window_datatype * buf1110_ptr = (window_datatype * )buf1110;
  window_datatype * buf1110d_ptr = (window_datatype * )buf1110d;
  window_init(window_buf1110_buf1110d, 1, buf1110, LOCK_4_6_0_0, buf1110d, LOCK_4_6_1_0, 256, 256);
  window_internal window_buf1111_buf1111d[1];
  window_datatype * buf1111_ptr = (window_datatype * )buf1111;
  window_datatype * buf1111d_ptr = (window_datatype * )buf1111d;
  window_init(window_buf1111_buf1111d, 1, buf1111, LOCK_5_5_6_4096, buf1111d, LOCK_5_5_7_0, 256, 256);
  window_internal window_buf1109_buf1109d[1];
  window_datatype * buf1109_ptr = (window_datatype * )buf1109;
  window_datatype * buf1109d_ptr = (window_datatype * )buf1109d;
  window_init(window_buf1109_buf1109d, 1, buf1109, LOCK_5_5_4_0, buf1109d, LOCK_5_5_5_0, 256, 256);
  window_internal window_buf1112_buf1112d[1];
  window_datatype * buf1112_ptr = (window_datatype * )buf1112;
  window_datatype * buf1112d_ptr = (window_datatype * )buf1112d;
  window_init(window_buf1112_buf1112d, 1, buf1112, LOCK_5_6_0_0, buf1112d, LOCK_5_6_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_6_bounds = sync_buffer[1];

  while (proc_5_6_bounds)
  {

    // Kernel call : i636:mm_kernel1
    window_acquire(window_buf1110_buf1110d,LOCK_4_6_0_0,LOCK_4_6_1_0,buf1110_ptr,buf1110d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1111_buf1111d,LOCK_5_5_6_4096,LOCK_5_5_7_0,buf1111_ptr,buf1111d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1109_buf1109d,LOCK_5_5_4_0,LOCK_5_5_5_0,buf1109_ptr,buf1109d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1112_buf1112d,LOCK_5_6_0_0,LOCK_5_6_1_0,buf1112_ptr,buf1112d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1110_buf1110d),get_input_window_float(window_buf1111_buf1111d),get_input_window_float(window_buf1109_buf1109d),get_output_window_float(window_buf1112_buf1112d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1110_buf1110d,LOCK_4_6_0_0,LOCK_4_6_1_0,buf1110_ptr,buf1110d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1111_buf1111d,LOCK_5_5_6_4096,LOCK_5_5_7_0,buf1111_ptr,buf1111d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1109_buf1109d,LOCK_5_5_4_0,LOCK_5_5_5_0,buf1109_ptr,buf1109d_ptr,0,index, REL_WRITE);
    window_release(window_buf1112_buf1112d,LOCK_5_6_0_0,LOCK_5_6_1_0,buf1112_ptr,buf1112d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_6_bounds > 0)
      --proc_5_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}