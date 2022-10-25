// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_7/src/26_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_7_0_0 48
#define LOCK_27_7_1_0 49
#define LOCK_27_7_2_4096 50
#define LOCK_27_7_3_4096 51
#define LOCK_26_6_4_4096 4
#define LOCK_26_6_5_4096 5
#define LOCK_26_6_6_0 6
#define LOCK_26_6_7_4096 7

// Declare shared memory buffers
v4float buf860[256];
v4float buf860d[256];
v4float buf861[256];
v4float buf861d[256];
v4float buf862[256];
v4float buf862d[256];
v4float buf863[256];
v4float buf863d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf861_buf861d[1];
  window_datatype * buf861_ptr = (window_datatype * )buf861;
  window_datatype * buf861d_ptr = (window_datatype * )buf861d;
  window_init(window_buf861_buf861d, 1, buf861, LOCK_27_7_0_0, buf861d, LOCK_27_7_1_0, 256, 256);
  window_internal window_buf862_buf862d[1];
  window_datatype * buf862_ptr = (window_datatype * )buf862;
  window_datatype * buf862d_ptr = (window_datatype * )buf862d;
  window_init(window_buf862_buf862d, 1, buf862, LOCK_27_7_2_4096, buf862d, LOCK_27_7_3_4096, 256, 256);
  window_internal window_buf860_buf860d[1];
  window_datatype * buf860_ptr = (window_datatype * )buf860;
  window_datatype * buf860d_ptr = (window_datatype * )buf860d;
  window_init(window_buf860_buf860d, 1, buf860, LOCK_26_6_4_4096, buf860d, LOCK_26_6_5_4096, 256, 256);
  window_internal window_buf863_buf863d[1];
  window_datatype * buf863_ptr = (window_datatype * )buf863;
  window_datatype * buf863d_ptr = (window_datatype * )buf863d;
  window_init(window_buf863_buf863d, 1, buf863, LOCK_26_6_6_0, buf863d, LOCK_26_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_7_bounds = sync_buffer[1];

  while (proc_26_7_bounds)
  {

    // Kernel call : i511:mm_kernel1
    window_acquire(window_buf861_buf861d,LOCK_27_7_0_0,LOCK_27_7_1_0,buf861_ptr,buf861d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf862_buf862d,LOCK_27_7_2_4096,LOCK_27_7_3_4096,buf862_ptr,buf862d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf860_buf860d,LOCK_26_6_4_4096,LOCK_26_6_5_4096,buf860_ptr,buf860d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf863_buf863d,LOCK_26_6_6_0,LOCK_26_6_7_4096,buf863_ptr,buf863d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf861_buf861d),get_input_window_float(window_buf862_buf862d),get_input_window_float(window_buf860_buf860d),get_output_window_float(window_buf863_buf863d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf861_buf861d,LOCK_27_7_0_0,LOCK_27_7_1_0,buf861_ptr,buf861d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf862_buf862d,LOCK_27_7_2_4096,LOCK_27_7_3_4096,buf862_ptr,buf862d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf860_buf860d,LOCK_26_6_4_4096,LOCK_26_6_5_4096,buf860_ptr,buf860d_ptr,0,index, REL_WRITE);
    window_release(window_buf863_buf863d,LOCK_26_6_6_0,LOCK_26_6_7_4096,buf863_ptr,buf863d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_7_bounds > 0)
      --proc_26_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}