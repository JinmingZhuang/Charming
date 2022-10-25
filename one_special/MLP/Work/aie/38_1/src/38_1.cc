// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_1/src/38_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_0_2_4096 2
#define LOCK_38_0_3_4096 3
#define LOCK_38_1_2_4096 18
#define LOCK_38_1_3_0 19
#define LOCK_38_1_0_0 16
#define LOCK_38_1_1_0 17
#define LOCK_38_1_4_4096 20
#define LOCK_38_1_5_4096 21

// Declare shared memory buffers
v4float buf434[256];
v4float buf434d[256];
v4float buf435[256];
v4float buf435d[256];
v4float buf436[256];
v4float buf436d[256];
v4float buf437[256];
v4float buf437d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf435_buf435d[1];
  window_datatype * buf435_ptr = (window_datatype * )buf435;
  window_datatype * buf435d_ptr = (window_datatype * )buf435d;
  window_init(window_buf435_buf435d, 1, buf435, LOCK_38_0_2_4096, buf435d, LOCK_38_0_3_4096, 256, 256);
  window_internal window_buf436_buf436d[1];
  window_datatype * buf436_ptr = (window_datatype * )buf436;
  window_datatype * buf436d_ptr = (window_datatype * )buf436d;
  window_init(window_buf436_buf436d, 1, buf436, LOCK_38_1_2_4096, buf436d, LOCK_38_1_3_0, 256, 256);
  window_internal window_buf434_buf434d[1];
  window_datatype * buf434_ptr = (window_datatype * )buf434;
  window_datatype * buf434d_ptr = (window_datatype * )buf434d;
  window_init(window_buf434_buf434d, 1, buf434, LOCK_38_1_0_0, buf434d, LOCK_38_1_1_0, 256, 256);
  window_internal window_buf437_buf437d[1];
  window_datatype * buf437_ptr = (window_datatype * )buf437;
  window_datatype * buf437d_ptr = (window_datatype * )buf437d;
  window_init(window_buf437_buf437d, 1, buf437, LOCK_38_1_4_4096, buf437d, LOCK_38_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_1_bounds = sync_buffer[1];

  while (proc_38_1_bounds)
  {

    // Kernel call : i299:mm_kernel1
    window_acquire(window_buf435_buf435d,LOCK_38_0_2_4096,LOCK_38_0_3_4096,buf435_ptr,buf435d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf436_buf436d,LOCK_38_1_2_4096,LOCK_38_1_3_0,buf436_ptr,buf436d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf434_buf434d,LOCK_38_1_0_0,LOCK_38_1_1_0,buf434_ptr,buf434d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf437_buf437d,LOCK_38_1_4_4096,LOCK_38_1_5_4096,buf437_ptr,buf437d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf435_buf435d),get_input_window_float(window_buf436_buf436d),get_input_window_float(window_buf434_buf434d),get_output_window_float(window_buf437_buf437d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf435_buf435d,LOCK_38_0_2_4096,LOCK_38_0_3_4096,buf435_ptr,buf435d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf436_buf436d,LOCK_38_1_2_4096,LOCK_38_1_3_0,buf436_ptr,buf436d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf434_buf434d,LOCK_38_1_0_0,LOCK_38_1_1_0,buf434_ptr,buf434d_ptr,0,index, REL_WRITE);
    window_release(window_buf437_buf437d,LOCK_38_1_4_4096,LOCK_38_1_5_4096,buf437_ptr,buf437d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_1_bounds > 0)
      --proc_38_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}