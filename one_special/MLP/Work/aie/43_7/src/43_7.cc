// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_7/src/43_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_6_4_0 4
#define LOCK_43_6_5_0 5
#define LOCK_43_7_2_4096 18
#define LOCK_43_7_3_4096 19
#define LOCK_43_6_2_4096 2
#define LOCK_43_6_3_4096 3
#define LOCK_43_6_6_4096 6
#define LOCK_43_6_7_4096 7

// Declare shared memory buffers
v4float buf656[256];
v4float buf656d[256];
v4float buf657[256];
v4float buf657d[256];
v4float buf658[256];
v4float buf658d[256];
v4float buf659[256];
v4float buf659d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf657_buf657d[1];
  window_datatype * buf657_ptr = (window_datatype * )buf657;
  window_datatype * buf657d_ptr = (window_datatype * )buf657d;
  window_init(window_buf657_buf657d, 1, buf657, LOCK_43_6_4_0, buf657d, LOCK_43_6_5_0, 256, 256);
  window_internal window_buf658_buf658d[1];
  window_datatype * buf658_ptr = (window_datatype * )buf658;
  window_datatype * buf658d_ptr = (window_datatype * )buf658d;
  window_init(window_buf658_buf658d, 1, buf658, LOCK_43_7_2_4096, buf658d, LOCK_43_7_3_4096, 256, 256);
  window_internal window_buf656_buf656d[1];
  window_datatype * buf656_ptr = (window_datatype * )buf656;
  window_datatype * buf656d_ptr = (window_datatype * )buf656d;
  window_init(window_buf656_buf656d, 1, buf656, LOCK_43_6_2_4096, buf656d, LOCK_43_6_3_4096, 256, 256);
  window_internal window_buf659_buf659d[1];
  window_datatype * buf659_ptr = (window_datatype * )buf659;
  window_datatype * buf659d_ptr = (window_datatype * )buf659d;
  window_init(window_buf659_buf659d, 1, buf659, LOCK_43_6_6_4096, buf659d, LOCK_43_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_7_bounds = sync_buffer[1];

  while (proc_43_7_bounds)
  {

    // Kernel call : i409:mm_kernel1
    window_acquire(window_buf657_buf657d,LOCK_43_6_4_0,LOCK_43_6_5_0,buf657_ptr,buf657d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf658_buf658d,LOCK_43_7_2_4096,LOCK_43_7_3_4096,buf658_ptr,buf658d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf656_buf656d,LOCK_43_6_2_4096,LOCK_43_6_3_4096,buf656_ptr,buf656d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf659_buf659d,LOCK_43_6_6_4096,LOCK_43_6_7_4096,buf659_ptr,buf659d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf657_buf657d),get_input_window_float(window_buf658_buf658d),get_input_window_float(window_buf656_buf656d),get_output_window_float(window_buf659_buf659d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf657_buf657d,LOCK_43_6_4_0,LOCK_43_6_5_0,buf657_ptr,buf657d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf658_buf658d,LOCK_43_7_2_4096,LOCK_43_7_3_4096,buf658_ptr,buf658d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf656_buf656d,LOCK_43_6_2_4096,LOCK_43_6_3_4096,buf656_ptr,buf656d_ptr,0,index, REL_WRITE);
    window_release(window_buf659_buf659d,LOCK_43_6_6_4096,LOCK_43_6_7_4096,buf659_ptr,buf659d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_7_bounds > 0)
      --proc_43_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}