// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_7/src/44_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_7_2_4096 18
#define LOCK_44_7_3_4096 19
#define LOCK_45_7_6_0 54
#define LOCK_45_7_7_0 55
#define LOCK_44_6_4_4096 4
#define LOCK_44_6_5_4096 5
#define LOCK_44_6_6_4096 6
#define LOCK_44_6_7_4096 7

// Declare shared memory buffers
v4float buf644[256];
v4float buf644d[256];
v4float buf645[256];
v4float buf645d[256];
v4float buf646[256];
v4float buf646d[256];
v4float buf647[256];
v4float buf647d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf645_buf645d[1];
  window_datatype * buf645_ptr = (window_datatype * )buf645;
  window_datatype * buf645d_ptr = (window_datatype * )buf645d;
  window_init(window_buf645_buf645d, 1, buf645, LOCK_44_7_2_4096, buf645d, LOCK_44_7_3_4096, 256, 256);
  window_internal window_buf646_buf646d[1];
  window_datatype * buf646_ptr = (window_datatype * )buf646;
  window_datatype * buf646d_ptr = (window_datatype * )buf646d;
  window_init(window_buf646_buf646d, 1, buf646, LOCK_45_7_6_0, buf646d, LOCK_45_7_7_0, 256, 256);
  window_internal window_buf644_buf644d[1];
  window_datatype * buf644_ptr = (window_datatype * )buf644;
  window_datatype * buf644d_ptr = (window_datatype * )buf644d;
  window_init(window_buf644_buf644d, 1, buf644, LOCK_44_6_4_4096, buf644d, LOCK_44_6_5_4096, 256, 256);
  window_internal window_buf647_buf647d[1];
  window_datatype * buf647_ptr = (window_datatype * )buf647;
  window_datatype * buf647d_ptr = (window_datatype * )buf647d;
  window_init(window_buf647_buf647d, 1, buf647, LOCK_44_6_6_4096, buf647d, LOCK_44_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_7_bounds = sync_buffer[1];

  while (proc_44_7_bounds)
  {

    // Kernel call : i403:mm_kernel1
    window_acquire(window_buf645_buf645d,LOCK_44_7_2_4096,LOCK_44_7_3_4096,buf645_ptr,buf645d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf646_buf646d,LOCK_45_7_6_0,LOCK_45_7_7_0,buf646_ptr,buf646d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf644_buf644d,LOCK_44_6_4_4096,LOCK_44_6_5_4096,buf644_ptr,buf644d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf647_buf647d,LOCK_44_6_6_4096,LOCK_44_6_7_4096,buf647_ptr,buf647d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf645_buf645d),get_input_window_float(window_buf646_buf646d),get_input_window_float(window_buf644_buf644d),get_output_window_float(window_buf647_buf647d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf645_buf645d,LOCK_44_7_2_4096,LOCK_44_7_3_4096,buf645_ptr,buf645d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf646_buf646d,LOCK_45_7_6_0,LOCK_45_7_7_0,buf646_ptr,buf646d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf644_buf644d,LOCK_44_6_4_4096,LOCK_44_6_5_4096,buf644_ptr,buf644d_ptr,0,index, REL_WRITE);
    window_release(window_buf647_buf647d,LOCK_44_6_6_4096,LOCK_44_6_7_4096,buf647_ptr,buf647d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_7_bounds > 0)
      --proc_44_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}