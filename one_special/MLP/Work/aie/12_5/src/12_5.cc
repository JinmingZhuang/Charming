// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_5/src/12_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_13_5_6_4096 54
#define LOCK_13_5_7_4096 55
#define LOCK_12_6_0_0 32
#define LOCK_12_6_1_0 33
#define LOCK_12_5_2_4096 18
#define LOCK_12_5_3_0 19
#define LOCK_12_5_4_0 20
#define LOCK_12_5_5_4096 21

// Declare shared memory buffers
v4float buf1022[256];
v4float buf1022d[256];
v4float buf1023[256];
v4float buf1023d[256];
v4float buf1024[256];
v4float buf1024d[256];
v4float buf1025[256];
v4float buf1025d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1023_buf1023d[1];
  window_datatype * buf1023_ptr = (window_datatype * )buf1023;
  window_datatype * buf1023d_ptr = (window_datatype * )buf1023d;
  window_init(window_buf1023_buf1023d, 1, buf1023, LOCK_13_5_6_4096, buf1023d, LOCK_13_5_7_4096, 256, 256);
  window_internal window_buf1024_buf1024d[1];
  window_datatype * buf1024_ptr = (window_datatype * )buf1024;
  window_datatype * buf1024d_ptr = (window_datatype * )buf1024d;
  window_init(window_buf1024_buf1024d, 1, buf1024, LOCK_12_6_0_0, buf1024d, LOCK_12_6_1_0, 256, 256);
  window_internal window_buf1022_buf1022d[1];
  window_datatype * buf1022_ptr = (window_datatype * )buf1022;
  window_datatype * buf1022d_ptr = (window_datatype * )buf1022d;
  window_init(window_buf1022_buf1022d, 1, buf1022, LOCK_12_5_2_4096, buf1022d, LOCK_12_5_3_0, 256, 256);
  window_internal window_buf1025_buf1025d[1];
  window_datatype * buf1025_ptr = (window_datatype * )buf1025;
  window_datatype * buf1025d_ptr = (window_datatype * )buf1025d;
  window_init(window_buf1025_buf1025d, 1, buf1025, LOCK_12_5_4_0, buf1025d, LOCK_12_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_5_bounds = sync_buffer[1];

  while (proc_12_5_bounds)
  {

    // Kernel call : i593:mm_kernel1
    window_acquire(window_buf1023_buf1023d,LOCK_13_5_6_4096,LOCK_13_5_7_4096,buf1023_ptr,buf1023d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1024_buf1024d,LOCK_12_6_0_0,LOCK_12_6_1_0,buf1024_ptr,buf1024d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1022_buf1022d,LOCK_12_5_2_4096,LOCK_12_5_3_0,buf1022_ptr,buf1022d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1025_buf1025d,LOCK_12_5_4_0,LOCK_12_5_5_4096,buf1025_ptr,buf1025d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1023_buf1023d),get_input_window_float(window_buf1024_buf1024d),get_input_window_float(window_buf1022_buf1022d),get_output_window_float(window_buf1025_buf1025d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1023_buf1023d,LOCK_13_5_6_4096,LOCK_13_5_7_4096,buf1023_ptr,buf1023d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1024_buf1024d,LOCK_12_6_0_0,LOCK_12_6_1_0,buf1024_ptr,buf1024d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1022_buf1022d,LOCK_12_5_2_4096,LOCK_12_5_3_0,buf1022_ptr,buf1022d_ptr,0,index, REL_WRITE);
    window_release(window_buf1025_buf1025d,LOCK_12_5_4_0,LOCK_12_5_5_4096,buf1025_ptr,buf1025d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_5_bounds > 0)
      --proc_12_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}