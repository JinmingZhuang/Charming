// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_7/src/45_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_45_6_0_0 0
#define LOCK_45_6_1_0 1
#define LOCK_45_6_2_4096 2
#define LOCK_45_6_3_4096 3
#define LOCK_45_7_2_4096 18
#define LOCK_45_7_3_4096 19
#define LOCK_45_7_4_4096 20
#define LOCK_45_7_5_4096 21

// Declare shared memory buffers
v4float buf632[256];
v4float buf632d[256];
v4float buf633[256];
v4float buf633d[256];
v4float buf634[256];
v4float buf634d[256];
v4float buf635[256];
v4float buf635d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf633_buf633d[1];
  window_datatype * buf633_ptr = (window_datatype * )buf633;
  window_datatype * buf633d_ptr = (window_datatype * )buf633d;
  window_init(window_buf633_buf633d, 1, buf633, LOCK_45_6_0_0, buf633d, LOCK_45_6_1_0, 256, 256);
  window_internal window_buf634_buf634d[1];
  window_datatype * buf634_ptr = (window_datatype * )buf634;
  window_datatype * buf634d_ptr = (window_datatype * )buf634d;
  window_init(window_buf634_buf634d, 1, buf634, LOCK_45_6_2_4096, buf634d, LOCK_45_6_3_4096, 256, 256);
  window_internal window_buf632_buf632d[1];
  window_datatype * buf632_ptr = (window_datatype * )buf632;
  window_datatype * buf632d_ptr = (window_datatype * )buf632d;
  window_init(window_buf632_buf632d, 1, buf632, LOCK_45_7_2_4096, buf632d, LOCK_45_7_3_4096, 256, 256);
  window_internal window_buf635_buf635d[1];
  window_datatype * buf635_ptr = (window_datatype * )buf635;
  window_datatype * buf635d_ptr = (window_datatype * )buf635d;
  window_init(window_buf635_buf635d, 1, buf635, LOCK_45_7_4_4096, buf635d, LOCK_45_7_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_7_bounds = sync_buffer[1];

  while (proc_45_7_bounds)
  {

    // Kernel call : i397:mm_kernel1
    window_acquire(window_buf633_buf633d,LOCK_45_6_0_0,LOCK_45_6_1_0,buf633_ptr,buf633d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf634_buf634d,LOCK_45_6_2_4096,LOCK_45_6_3_4096,buf634_ptr,buf634d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf632_buf632d,LOCK_45_7_2_4096,LOCK_45_7_3_4096,buf632_ptr,buf632d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf635_buf635d,LOCK_45_7_4_4096,LOCK_45_7_5_4096,buf635_ptr,buf635d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf633_buf633d),get_input_window_float(window_buf634_buf634d),get_input_window_float(window_buf632_buf632d),get_output_window_float(window_buf635_buf635d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf633_buf633d,LOCK_45_6_0_0,LOCK_45_6_1_0,buf633_ptr,buf633d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf634_buf634d,LOCK_45_6_2_4096,LOCK_45_6_3_4096,buf634_ptr,buf634d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf632_buf632d,LOCK_45_7_2_4096,LOCK_45_7_3_4096,buf632_ptr,buf632d_ptr,0,index, REL_WRITE);
    window_release(window_buf635_buf635d,LOCK_45_7_4_4096,LOCK_45_7_5_4096,buf635_ptr,buf635d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_7_bounds > 0)
      --proc_45_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}