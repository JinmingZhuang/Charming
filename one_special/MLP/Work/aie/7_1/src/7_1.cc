// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/7_1/src/7_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_7_0_2_4096 2
#define LOCK_7_0_3_4096 3
#define LOCK_7_2_0_0 32
#define LOCK_7_2_1_0 33
#define LOCK_7_1_4_0 20
#define LOCK_7_1_5_0 21
#define LOCK_7_1_6_0 22
#define LOCK_7_1_7_4096 23

// Declare shared memory buffers
v4float buf62[256];
v4float buf62d[256];
v4float buf63[256];
v4float buf63d[256];
v4float buf64[256];
v4float buf64d[256];
v4float buf65[256];
v4float buf65d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf63_buf63d[1];
  window_datatype * buf63_ptr = (window_datatype * )buf63;
  window_datatype * buf63d_ptr = (window_datatype * )buf63d;
  window_init(window_buf63_buf63d, 1, buf63, LOCK_7_0_2_4096, buf63d, LOCK_7_0_3_4096, 256, 256);
  window_internal window_buf64_buf64d[1];
  window_datatype * buf64_ptr = (window_datatype * )buf64;
  window_datatype * buf64d_ptr = (window_datatype * )buf64d;
  window_init(window_buf64_buf64d, 1, buf64, LOCK_7_2_0_0, buf64d, LOCK_7_2_1_0, 256, 256);
  window_internal window_buf62_buf62d[1];
  window_datatype * buf62_ptr = (window_datatype * )buf62;
  window_datatype * buf62d_ptr = (window_datatype * )buf62d;
  window_init(window_buf62_buf62d, 1, buf62, LOCK_7_1_4_0, buf62d, LOCK_7_1_5_0, 256, 256);
  window_internal window_buf65_buf65d[1];
  window_datatype * buf65_ptr = (window_datatype * )buf65;
  window_datatype * buf65d_ptr = (window_datatype * )buf65d;
  window_init(window_buf65_buf65d, 1, buf65, LOCK_7_1_6_0, buf65d, LOCK_7_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_7_1_bounds = sync_buffer[1];

  while (proc_7_1_bounds)
  {

    // Kernel call : i113:mm_kernel1
    window_acquire(window_buf63_buf63d,LOCK_7_0_2_4096,LOCK_7_0_3_4096,buf63_ptr,buf63d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf64_buf64d,LOCK_7_2_0_0,LOCK_7_2_1_0,buf64_ptr,buf64d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf62_buf62d,LOCK_7_1_4_0,LOCK_7_1_5_0,buf62_ptr,buf62d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf65_buf65d,LOCK_7_1_6_0,LOCK_7_1_7_4096,buf65_ptr,buf65d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf63_buf63d),get_input_window_float(window_buf64_buf64d),get_input_window_float(window_buf62_buf62d),get_output_window_float(window_buf65_buf65d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf63_buf63d,LOCK_7_0_2_4096,LOCK_7_0_3_4096,buf63_ptr,buf63d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf64_buf64d,LOCK_7_2_0_0,LOCK_7_2_1_0,buf64_ptr,buf64d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf62_buf62d,LOCK_7_1_4_0,LOCK_7_1_5_0,buf62_ptr,buf62d_ptr,0,index, REL_WRITE);
    window_release(window_buf65_buf65d,LOCK_7_1_6_0,LOCK_7_1_7_4096,buf65_ptr,buf65d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_7_1_bounds > 0)
      --proc_7_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}