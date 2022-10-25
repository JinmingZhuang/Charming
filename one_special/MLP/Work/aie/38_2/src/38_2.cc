// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_2/src/38_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_2_0_0 48
#define LOCK_38_2_1_0 49
#define LOCK_38_1_6_0 6
#define LOCK_38_1_7_4096 7
#define LOCK_38_1_4_4096 4
#define LOCK_38_1_5_4096 5
#define LOCK_38_3_0_0 32
#define LOCK_38_3_1_0 33

// Declare shared memory buffers
v4float buf437[256];
v4float buf437d[256];
v4float buf438[256];
v4float buf438d[256];
v4float buf439[256];
v4float buf439d[256];
v4float buf440[256];
v4float buf440d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf438_buf438d[1];
  window_datatype * buf438_ptr = (window_datatype * )buf438;
  window_datatype * buf438d_ptr = (window_datatype * )buf438d;
  window_init(window_buf438_buf438d, 1, buf438, LOCK_38_2_0_0, buf438d, LOCK_38_2_1_0, 256, 256);
  window_internal window_buf439_buf439d[1];
  window_datatype * buf439_ptr = (window_datatype * )buf439;
  window_datatype * buf439d_ptr = (window_datatype * )buf439d;
  window_init(window_buf439_buf439d, 1, buf439, LOCK_38_1_6_0, buf439d, LOCK_38_1_7_4096, 256, 256);
  window_internal window_buf437_buf437d[1];
  window_datatype * buf437_ptr = (window_datatype * )buf437;
  window_datatype * buf437d_ptr = (window_datatype * )buf437d;
  window_init(window_buf437_buf437d, 1, buf437, LOCK_38_1_4_4096, buf437d, LOCK_38_1_5_4096, 256, 256);
  window_internal window_buf440_buf440d[1];
  window_datatype * buf440_ptr = (window_datatype * )buf440;
  window_datatype * buf440d_ptr = (window_datatype * )buf440d;
  window_init(window_buf440_buf440d, 1, buf440, LOCK_38_3_0_0, buf440d, LOCK_38_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_2_bounds = sync_buffer[1];

  while (proc_38_2_bounds)
  {

    // Kernel call : i300:mm_kernel1
    window_acquire(window_buf438_buf438d,LOCK_38_2_0_0,LOCK_38_2_1_0,buf438_ptr,buf438d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf439_buf439d,LOCK_38_1_6_0,LOCK_38_1_7_4096,buf439_ptr,buf439d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf437_buf437d,LOCK_38_1_4_4096,LOCK_38_1_5_4096,buf437_ptr,buf437d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf440_buf440d,LOCK_38_3_0_0,LOCK_38_3_1_0,buf440_ptr,buf440d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf438_buf438d),get_input_window_float(window_buf439_buf439d),get_input_window_float(window_buf437_buf437d),get_output_window_float(window_buf440_buf440d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf438_buf438d,LOCK_38_2_0_0,LOCK_38_2_1_0,buf438_ptr,buf438d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf439_buf439d,LOCK_38_1_6_0,LOCK_38_1_7_4096,buf439_ptr,buf439d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf437_buf437d,LOCK_38_1_4_4096,LOCK_38_1_5_4096,buf437_ptr,buf437d_ptr,0,index, REL_WRITE);
    window_release(window_buf440_buf440d,LOCK_38_3_0_0,LOCK_38_3_1_0,buf440_ptr,buf440d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_2_bounds > 0)
      --proc_38_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}