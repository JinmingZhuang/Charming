// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/16_7/src/16_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_16_7_2_4096 18
#define LOCK_16_7_3_4096 19
#define LOCK_16_6_4_0 4
#define LOCK_16_6_5_0 5
#define LOCK_16_6_2_4096 2
#define LOCK_16_6_3_4096 3
#define LOCK_16_6_6_4096 6
#define LOCK_16_6_7_4096 7

// Declare shared memory buffers
v4float buf980[256];
v4float buf980d[256];
v4float buf981[256];
v4float buf981d[256];
v4float buf982[256];
v4float buf982d[256];
v4float buf983[256];
v4float buf983d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf981_buf981d[1];
  window_datatype * buf981_ptr = (window_datatype * )buf981;
  window_datatype * buf981d_ptr = (window_datatype * )buf981d;
  window_init(window_buf981_buf981d, 1, buf981, LOCK_16_7_2_4096, buf981d, LOCK_16_7_3_4096, 256, 256);
  window_internal window_buf982_buf982d[1];
  window_datatype * buf982_ptr = (window_datatype * )buf982;
  window_datatype * buf982d_ptr = (window_datatype * )buf982d;
  window_init(window_buf982_buf982d, 1, buf982, LOCK_16_6_4_0, buf982d, LOCK_16_6_5_0, 256, 256);
  window_internal window_buf980_buf980d[1];
  window_datatype * buf980_ptr = (window_datatype * )buf980;
  window_datatype * buf980d_ptr = (window_datatype * )buf980d;
  window_init(window_buf980_buf980d, 1, buf980, LOCK_16_6_2_4096, buf980d, LOCK_16_6_3_4096, 256, 256);
  window_internal window_buf983_buf983d[1];
  window_datatype * buf983_ptr = (window_datatype * )buf983;
  window_datatype * buf983d_ptr = (window_datatype * )buf983d;
  window_init(window_buf983_buf983d, 1, buf983, LOCK_16_6_6_4096, buf983d, LOCK_16_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_16_7_bounds = sync_buffer[1];

  while (proc_16_7_bounds)
  {

    // Kernel call : i571:mm_kernel1
    window_acquire(window_buf981_buf981d,LOCK_16_7_2_4096,LOCK_16_7_3_4096,buf981_ptr,buf981d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf982_buf982d,LOCK_16_6_4_0,LOCK_16_6_5_0,buf982_ptr,buf982d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf980_buf980d,LOCK_16_6_2_4096,LOCK_16_6_3_4096,buf980_ptr,buf980d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf983_buf983d,LOCK_16_6_6_4096,LOCK_16_6_7_4096,buf983_ptr,buf983d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf981_buf981d),get_input_window_float(window_buf982_buf982d),get_input_window_float(window_buf980_buf980d),get_output_window_float(window_buf983_buf983d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf981_buf981d,LOCK_16_7_2_4096,LOCK_16_7_3_4096,buf981_ptr,buf981d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf982_buf982d,LOCK_16_6_4_0,LOCK_16_6_5_0,buf982_ptr,buf982d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf980_buf980d,LOCK_16_6_2_4096,LOCK_16_6_3_4096,buf980_ptr,buf980d_ptr,0,index, REL_WRITE);
    window_release(window_buf983_buf983d,LOCK_16_6_6_4096,LOCK_16_6_7_4096,buf983_ptr,buf983d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_16_7_bounds > 0)
      --proc_16_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}