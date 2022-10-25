// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/5_7/src/5_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_5_6_2_4096 2
#define LOCK_5_6_3_4096 3
#define LOCK_5_6_4_0 4
#define LOCK_5_6_5_4096 5
#define LOCK_5_6_0_0 0
#define LOCK_5_6_1_0 1
#define LOCK_5_6_6_4096 6
#define LOCK_5_6_7_0 7

// Declare shared memory buffers
v4float buf1112[256];
v4float buf1112d[256];
v4float buf1113[256];
v4float buf1113d[256];
v4float buf1114[256];
v4float buf1114d[256];
v4float buf1115[256];
v4float buf1115d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1113_buf1113d[1];
  window_datatype * buf1113_ptr = (window_datatype * )buf1113;
  window_datatype * buf1113d_ptr = (window_datatype * )buf1113d;
  window_init(window_buf1113_buf1113d, 1, buf1113, LOCK_5_6_2_4096, buf1113d, LOCK_5_6_3_4096, 256, 256);
  window_internal window_buf1114_buf1114d[1];
  window_datatype * buf1114_ptr = (window_datatype * )buf1114;
  window_datatype * buf1114d_ptr = (window_datatype * )buf1114d;
  window_init(window_buf1114_buf1114d, 1, buf1114, LOCK_5_6_4_0, buf1114d, LOCK_5_6_5_4096, 256, 256);
  window_internal window_buf1112_buf1112d[1];
  window_datatype * buf1112_ptr = (window_datatype * )buf1112;
  window_datatype * buf1112d_ptr = (window_datatype * )buf1112d;
  window_init(window_buf1112_buf1112d, 1, buf1112, LOCK_5_6_0_0, buf1112d, LOCK_5_6_1_0, 256, 256);
  window_internal window_buf1115_buf1115d[1];
  window_datatype * buf1115_ptr = (window_datatype * )buf1115;
  window_datatype * buf1115d_ptr = (window_datatype * )buf1115d;
  window_init(window_buf1115_buf1115d, 1, buf1115, LOCK_5_6_6_4096, buf1115d, LOCK_5_6_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_5_7_bounds = sync_buffer[1];

  while (proc_5_7_bounds)
  {

    // Kernel call : i637:mm_kernel1
    window_acquire(window_buf1113_buf1113d,LOCK_5_6_2_4096,LOCK_5_6_3_4096,buf1113_ptr,buf1113d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1114_buf1114d,LOCK_5_6_4_0,LOCK_5_6_5_4096,buf1114_ptr,buf1114d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1112_buf1112d,LOCK_5_6_0_0,LOCK_5_6_1_0,buf1112_ptr,buf1112d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1115_buf1115d,LOCK_5_6_6_4096,LOCK_5_6_7_0,buf1115_ptr,buf1115d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1113_buf1113d),get_input_window_float(window_buf1114_buf1114d),get_input_window_float(window_buf1112_buf1112d),get_output_window_float(window_buf1115_buf1115d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1113_buf1113d,LOCK_5_6_2_4096,LOCK_5_6_3_4096,buf1113_ptr,buf1113d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1114_buf1114d,LOCK_5_6_4_0,LOCK_5_6_5_4096,buf1114_ptr,buf1114d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1112_buf1112d,LOCK_5_6_0_0,LOCK_5_6_1_0,buf1112_ptr,buf1112d_ptr,0,index, REL_WRITE);
    window_release(window_buf1115_buf1115d,LOCK_5_6_6_4096,LOCK_5_6_7_0,buf1115_ptr,buf1115d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_5_7_bounds > 0)
      --proc_5_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}