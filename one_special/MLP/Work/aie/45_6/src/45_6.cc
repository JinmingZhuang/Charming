// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_6/src/45_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_6_0_0 16
#define LOCK_44_6_1_0 17
#define LOCK_45_7_0_0 32
#define LOCK_45_7_1_0 33
#define LOCK_45_5_6_4096 6
#define LOCK_45_5_7_4096 7
#define LOCK_45_7_2_4096 34
#define LOCK_45_7_3_4096 35

// Declare shared memory buffers
v4float buf629[256];
v4float buf629d[256];
v4float buf630[256];
v4float buf630d[256];
v4float buf631[256];
v4float buf631d[256];
v4float buf632[256];
v4float buf632d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf630_buf630d[1];
  window_datatype * buf630_ptr = (window_datatype * )buf630;
  window_datatype * buf630d_ptr = (window_datatype * )buf630d;
  window_init(window_buf630_buf630d, 1, buf630, LOCK_44_6_0_0, buf630d, LOCK_44_6_1_0, 256, 256);
  window_internal window_buf631_buf631d[1];
  window_datatype * buf631_ptr = (window_datatype * )buf631;
  window_datatype * buf631d_ptr = (window_datatype * )buf631d;
  window_init(window_buf631_buf631d, 1, buf631, LOCK_45_7_0_0, buf631d, LOCK_45_7_1_0, 256, 256);
  window_internal window_buf629_buf629d[1];
  window_datatype * buf629_ptr = (window_datatype * )buf629;
  window_datatype * buf629d_ptr = (window_datatype * )buf629d;
  window_init(window_buf629_buf629d, 1, buf629, LOCK_45_5_6_4096, buf629d, LOCK_45_5_7_4096, 256, 256);
  window_internal window_buf632_buf632d[1];
  window_datatype * buf632_ptr = (window_datatype * )buf632;
  window_datatype * buf632d_ptr = (window_datatype * )buf632d;
  window_init(window_buf632_buf632d, 1, buf632, LOCK_45_7_2_4096, buf632d, LOCK_45_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_6_bounds = sync_buffer[1];

  while (proc_45_6_bounds)
  {

    // Kernel call : i396:mm_kernel1
    window_acquire(window_buf630_buf630d,LOCK_44_6_0_0,LOCK_44_6_1_0,buf630_ptr,buf630d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf631_buf631d,LOCK_45_7_0_0,LOCK_45_7_1_0,buf631_ptr,buf631d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf629_buf629d,LOCK_45_5_6_4096,LOCK_45_5_7_4096,buf629_ptr,buf629d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf632_buf632d,LOCK_45_7_2_4096,LOCK_45_7_3_4096,buf632_ptr,buf632d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf630_buf630d),get_input_window_float(window_buf631_buf631d),get_input_window_float(window_buf629_buf629d),get_output_window_float(window_buf632_buf632d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf630_buf630d,LOCK_44_6_0_0,LOCK_44_6_1_0,buf630_ptr,buf630d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf631_buf631d,LOCK_45_7_0_0,LOCK_45_7_1_0,buf631_ptr,buf631d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf629_buf629d,LOCK_45_5_6_4096,LOCK_45_5_7_4096,buf629_ptr,buf629d_ptr,0,index, REL_WRITE);
    window_release(window_buf632_buf632d,LOCK_45_7_2_4096,LOCK_45_7_3_4096,buf632_ptr,buf632d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_6_bounds > 0)
      --proc_45_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}