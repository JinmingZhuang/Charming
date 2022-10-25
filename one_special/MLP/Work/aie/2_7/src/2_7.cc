// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/2_7/src/2_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_2_7_0_4096 16
#define LOCK_2_7_1_0 17
#define LOCK_2_7_2_0 18
#define LOCK_2_7_3_4096 19
#define LOCK_2_6_0_0 0
#define LOCK_2_6_1_1376 1
#define LOCK_2_6_2_0 2
#define LOCK_2_6_3_0 3

// Declare shared memory buffers
v4float buf1148[256];
v4float buf1148d[256];
v4float buf1149[256];
v4float buf1149d[256];
v4float buf1150[256];
v4float buf1150d[256];
v4float buf1151[256];
v4float buf1151d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1149_buf1149d[1];
  window_datatype * buf1149_ptr = (window_datatype * )buf1149;
  window_datatype * buf1149d_ptr = (window_datatype * )buf1149d;
  window_init(window_buf1149_buf1149d, 1, buf1149, LOCK_2_7_0_4096, buf1149d, LOCK_2_7_1_0, 256, 256);
  window_internal window_buf1150_buf1150d[1];
  window_datatype * buf1150_ptr = (window_datatype * )buf1150;
  window_datatype * buf1150d_ptr = (window_datatype * )buf1150d;
  window_init(window_buf1150_buf1150d, 1, buf1150, LOCK_2_7_2_0, buf1150d, LOCK_2_7_3_4096, 256, 256);
  window_internal window_buf1148_buf1148d[1];
  window_datatype * buf1148_ptr = (window_datatype * )buf1148;
  window_datatype * buf1148d_ptr = (window_datatype * )buf1148d;
  window_init(window_buf1148_buf1148d, 1, buf1148, LOCK_2_6_0_0, buf1148d, LOCK_2_6_1_1376, 256, 256);
  window_internal window_buf1151_buf1151d[1];
  window_datatype * buf1151_ptr = (window_datatype * )buf1151;
  window_datatype * buf1151d_ptr = (window_datatype * )buf1151d;
  window_init(window_buf1151_buf1151d, 1, buf1151, LOCK_2_6_2_0, buf1151d, LOCK_2_6_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_2_7_bounds = sync_buffer[1];

  while (proc_2_7_bounds)
  {

    // Kernel call : i655:mm_kernel1
    window_acquire(window_buf1149_buf1149d,LOCK_2_7_0_4096,LOCK_2_7_1_0,buf1149_ptr,buf1149d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1150_buf1150d,LOCK_2_7_2_0,LOCK_2_7_3_4096,buf1150_ptr,buf1150d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1148_buf1148d,LOCK_2_6_0_0,LOCK_2_6_1_1376,buf1148_ptr,buf1148d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1151_buf1151d,LOCK_2_6_2_0,LOCK_2_6_3_0,buf1151_ptr,buf1151d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1149_buf1149d),get_input_window_float(window_buf1150_buf1150d),get_input_window_float(window_buf1148_buf1148d),get_output_window_float(window_buf1151_buf1151d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1149_buf1149d,LOCK_2_7_0_4096,LOCK_2_7_1_0,buf1149_ptr,buf1149d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1150_buf1150d,LOCK_2_7_2_0,LOCK_2_7_3_4096,buf1150_ptr,buf1150d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1148_buf1148d,LOCK_2_6_0_0,LOCK_2_6_1_1376,buf1148_ptr,buf1148d_ptr,0,index, REL_WRITE);
    window_release(window_buf1151_buf1151d,LOCK_2_6_2_0,LOCK_2_6_3_0,buf1151_ptr,buf1151d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_2_7_bounds > 0)
      --proc_2_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}