// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_5/src/3_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_6_0_0 32
#define LOCK_3_6_1_0 33
#define LOCK_3_5_4_0 20
#define LOCK_3_5_5_0 21
#define LOCK_3_5_2_4096 18
#define LOCK_3_5_3_4096 19
#define LOCK_3_5_6_0 22
#define LOCK_3_5_7_0 23

// Declare shared memory buffers
v4float buf1130[256];
v4float buf1130d[256];
v4float buf1131[256];
v4float buf1131d[256];
v4float buf1132[256];
v4float buf1132d[256];
v4float buf1133[256];
v4float buf1133d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1131_buf1131d[1];
  window_datatype * buf1131_ptr = (window_datatype * )buf1131;
  window_datatype * buf1131d_ptr = (window_datatype * )buf1131d;
  window_init(window_buf1131_buf1131d, 1, buf1131, LOCK_3_6_0_0, buf1131d, LOCK_3_6_1_0, 256, 256);
  window_internal window_buf1132_buf1132d[1];
  window_datatype * buf1132_ptr = (window_datatype * )buf1132;
  window_datatype * buf1132d_ptr = (window_datatype * )buf1132d;
  window_init(window_buf1132_buf1132d, 1, buf1132, LOCK_3_5_4_0, buf1132d, LOCK_3_5_5_0, 256, 256);
  window_internal window_buf1130_buf1130d[1];
  window_datatype * buf1130_ptr = (window_datatype * )buf1130;
  window_datatype * buf1130d_ptr = (window_datatype * )buf1130d;
  window_init(window_buf1130_buf1130d, 1, buf1130, LOCK_3_5_2_4096, buf1130d, LOCK_3_5_3_4096, 256, 256);
  window_internal window_buf1133_buf1133d[1];
  window_datatype * buf1133_ptr = (window_datatype * )buf1133;
  window_datatype * buf1133d_ptr = (window_datatype * )buf1133d;
  window_init(window_buf1133_buf1133d, 1, buf1133, LOCK_3_5_6_0, buf1133d, LOCK_3_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_5_bounds = sync_buffer[1];

  while (proc_3_5_bounds)
  {

    // Kernel call : i647:mm_kernel1
    window_acquire(window_buf1131_buf1131d,LOCK_3_6_0_0,LOCK_3_6_1_0,buf1131_ptr,buf1131d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1132_buf1132d,LOCK_3_5_4_0,LOCK_3_5_5_0,buf1132_ptr,buf1132d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1130_buf1130d,LOCK_3_5_2_4096,LOCK_3_5_3_4096,buf1130_ptr,buf1130d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1133_buf1133d,LOCK_3_5_6_0,LOCK_3_5_7_0,buf1133_ptr,buf1133d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1131_buf1131d),get_input_window_float(window_buf1132_buf1132d),get_input_window_float(window_buf1130_buf1130d),get_output_window_float(window_buf1133_buf1133d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1131_buf1131d,LOCK_3_6_0_0,LOCK_3_6_1_0,buf1131_ptr,buf1131d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1132_buf1132d,LOCK_3_5_4_0,LOCK_3_5_5_0,buf1132_ptr,buf1132d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1130_buf1130d,LOCK_3_5_2_4096,LOCK_3_5_3_4096,buf1130_ptr,buf1130d_ptr,0,index, REL_WRITE);
    window_release(window_buf1133_buf1133d,LOCK_3_5_6_0,LOCK_3_5_7_0,buf1133_ptr,buf1133d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_5_bounds > 0)
      --proc_3_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}