// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_6/src/12_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_5_6_4096 6
#define LOCK_12_5_7_0 7
#define LOCK_12_7_0_4096 32
#define LOCK_12_7_1_4096 33
#define LOCK_12_5_4_0 4
#define LOCK_12_5_5_4096 5
#define LOCK_12_7_2_4096 34
#define LOCK_12_7_3_4096 35

// Declare shared memory buffers
v4float buf1025[256];
v4float buf1025d[256];
v4float buf1026[256];
v4float buf1026d[256];
v4float buf1027[256];
v4float buf1027d[256];
v4float buf1028[256];
v4float buf1028d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1026_buf1026d[1];
  window_datatype * buf1026_ptr = (window_datatype * )buf1026;
  window_datatype * buf1026d_ptr = (window_datatype * )buf1026d;
  window_init(window_buf1026_buf1026d, 1, buf1026, LOCK_12_5_6_4096, buf1026d, LOCK_12_5_7_0, 256, 256);
  window_internal window_buf1027_buf1027d[1];
  window_datatype * buf1027_ptr = (window_datatype * )buf1027;
  window_datatype * buf1027d_ptr = (window_datatype * )buf1027d;
  window_init(window_buf1027_buf1027d, 1, buf1027, LOCK_12_7_0_4096, buf1027d, LOCK_12_7_1_4096, 256, 256);
  window_internal window_buf1025_buf1025d[1];
  window_datatype * buf1025_ptr = (window_datatype * )buf1025;
  window_datatype * buf1025d_ptr = (window_datatype * )buf1025d;
  window_init(window_buf1025_buf1025d, 1, buf1025, LOCK_12_5_4_0, buf1025d, LOCK_12_5_5_4096, 256, 256);
  window_internal window_buf1028_buf1028d[1];
  window_datatype * buf1028_ptr = (window_datatype * )buf1028;
  window_datatype * buf1028d_ptr = (window_datatype * )buf1028d;
  window_init(window_buf1028_buf1028d, 1, buf1028, LOCK_12_7_2_4096, buf1028d, LOCK_12_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_6_bounds = sync_buffer[1];

  while (proc_12_6_bounds)
  {

    // Kernel call : i594:mm_kernel1
    window_acquire(window_buf1026_buf1026d,LOCK_12_5_6_4096,LOCK_12_5_7_0,buf1026_ptr,buf1026d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1027_buf1027d,LOCK_12_7_0_4096,LOCK_12_7_1_4096,buf1027_ptr,buf1027d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1025_buf1025d,LOCK_12_5_4_0,LOCK_12_5_5_4096,buf1025_ptr,buf1025d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1028_buf1028d,LOCK_12_7_2_4096,LOCK_12_7_3_4096,buf1028_ptr,buf1028d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1026_buf1026d),get_input_window_float(window_buf1027_buf1027d),get_input_window_float(window_buf1025_buf1025d),get_output_window_float(window_buf1028_buf1028d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1026_buf1026d,LOCK_12_5_6_4096,LOCK_12_5_7_0,buf1026_ptr,buf1026d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1027_buf1027d,LOCK_12_7_0_4096,LOCK_12_7_1_4096,buf1027_ptr,buf1027d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1025_buf1025d,LOCK_12_5_4_0,LOCK_12_5_5_4096,buf1025_ptr,buf1025d_ptr,0,index, REL_WRITE);
    window_release(window_buf1028_buf1028d,LOCK_12_7_2_4096,LOCK_12_7_3_4096,buf1028_ptr,buf1028d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_6_bounds > 0)
      --proc_12_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}