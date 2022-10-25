// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_6/src/49_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_6_0_4096 48
#define LOCK_49_6_1_0 49
#define LOCK_49_6_2_0 50
#define LOCK_49_6_3_4096 51
#define LOCK_49_5_6_0 6
#define LOCK_49_5_7_0 7
#define LOCK_49_6_4_4096 52
#define LOCK_49_6_5_0 53

// Declare shared memory buffers
v4float buf581[256];
v4float buf581d[256];
v4float buf582[256];
v4float buf582d[256];
v4float buf583[256];
v4float buf583d[256];
v4float buf584[256];
v4float buf584d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf582_buf582d[1];
  window_datatype * buf582_ptr = (window_datatype * )buf582;
  window_datatype * buf582d_ptr = (window_datatype * )buf582d;
  window_init(window_buf582_buf582d, 1, buf582, LOCK_49_6_0_4096, buf582d, LOCK_49_6_1_0, 256, 256);
  window_internal window_buf583_buf583d[1];
  window_datatype * buf583_ptr = (window_datatype * )buf583;
  window_datatype * buf583d_ptr = (window_datatype * )buf583d;
  window_init(window_buf583_buf583d, 1, buf583, LOCK_49_6_2_0, buf583d, LOCK_49_6_3_4096, 256, 256);
  window_internal window_buf581_buf581d[1];
  window_datatype * buf581_ptr = (window_datatype * )buf581;
  window_datatype * buf581d_ptr = (window_datatype * )buf581d;
  window_init(window_buf581_buf581d, 1, buf581, LOCK_49_5_6_0, buf581d, LOCK_49_5_7_0, 256, 256);
  window_internal window_buf584_buf584d[1];
  window_datatype * buf584_ptr = (window_datatype * )buf584;
  window_datatype * buf584d_ptr = (window_datatype * )buf584d;
  window_init(window_buf584_buf584d, 1, buf584, LOCK_49_6_4_4096, buf584d, LOCK_49_6_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_6_bounds = sync_buffer[1];

  while (proc_49_6_bounds)
  {

    // Kernel call : i372:mm_kernel1
    window_acquire(window_buf582_buf582d,LOCK_49_6_0_4096,LOCK_49_6_1_0,buf582_ptr,buf582d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf583_buf583d,LOCK_49_6_2_0,LOCK_49_6_3_4096,buf583_ptr,buf583d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf581_buf581d,LOCK_49_5_6_0,LOCK_49_5_7_0,buf581_ptr,buf581d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf584_buf584d,LOCK_49_6_4_4096,LOCK_49_6_5_0,buf584_ptr,buf584d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf582_buf582d),get_input_window_float(window_buf583_buf583d),get_input_window_float(window_buf581_buf581d),get_output_window_float(window_buf584_buf584d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf582_buf582d,LOCK_49_6_0_4096,LOCK_49_6_1_0,buf582_ptr,buf582d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf583_buf583d,LOCK_49_6_2_0,LOCK_49_6_3_4096,buf583_ptr,buf583d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf581_buf581d,LOCK_49_5_6_0,LOCK_49_5_7_0,buf581_ptr,buf581d_ptr,0,index, REL_WRITE);
    window_release(window_buf584_buf584d,LOCK_49_6_4_4096,LOCK_49_6_5_0,buf584_ptr,buf584d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_6_bounds > 0)
      --proc_49_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}