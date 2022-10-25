// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_7/src/41_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_7_2_4096 50
#define LOCK_42_7_3_4096 51
#define LOCK_41_7_0_0 16
#define LOCK_41_7_1_0 17
#define LOCK_41_6_4_4096 4
#define LOCK_41_6_5_4096 5
#define LOCK_41_6_6_4096 6
#define LOCK_41_6_7_0 7

// Declare shared memory buffers
v4float buf680[256];
v4float buf680d[256];
v4float buf681[256];
v4float buf681d[256];
v4float buf682[256];
v4float buf682d[256];
v4float buf683[256];
v4float buf683d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf681_buf681d[1];
  window_datatype * buf681_ptr = (window_datatype * )buf681;
  window_datatype * buf681d_ptr = (window_datatype * )buf681d;
  window_init(window_buf681_buf681d, 1, buf681, LOCK_42_7_2_4096, buf681d, LOCK_42_7_3_4096, 256, 256);
  window_internal window_buf682_buf682d[1];
  window_datatype * buf682_ptr = (window_datatype * )buf682;
  window_datatype * buf682d_ptr = (window_datatype * )buf682d;
  window_init(window_buf682_buf682d, 1, buf682, LOCK_41_7_0_0, buf682d, LOCK_41_7_1_0, 256, 256);
  window_internal window_buf680_buf680d[1];
  window_datatype * buf680_ptr = (window_datatype * )buf680;
  window_datatype * buf680d_ptr = (window_datatype * )buf680d;
  window_init(window_buf680_buf680d, 1, buf680, LOCK_41_6_4_4096, buf680d, LOCK_41_6_5_4096, 256, 256);
  window_internal window_buf683_buf683d[1];
  window_datatype * buf683_ptr = (window_datatype * )buf683;
  window_datatype * buf683d_ptr = (window_datatype * )buf683d;
  window_init(window_buf683_buf683d, 1, buf683, LOCK_41_6_6_4096, buf683d, LOCK_41_6_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_7_bounds = sync_buffer[1];

  while (proc_41_7_bounds)
  {

    // Kernel call : i421:mm_kernel1
    window_acquire(window_buf681_buf681d,LOCK_42_7_2_4096,LOCK_42_7_3_4096,buf681_ptr,buf681d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf682_buf682d,LOCK_41_7_0_0,LOCK_41_7_1_0,buf682_ptr,buf682d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf680_buf680d,LOCK_41_6_4_4096,LOCK_41_6_5_4096,buf680_ptr,buf680d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf683_buf683d,LOCK_41_6_6_4096,LOCK_41_6_7_0,buf683_ptr,buf683d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf681_buf681d),get_input_window_float(window_buf682_buf682d),get_input_window_float(window_buf680_buf680d),get_output_window_float(window_buf683_buf683d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf681_buf681d,LOCK_42_7_2_4096,LOCK_42_7_3_4096,buf681_ptr,buf681d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf682_buf682d,LOCK_41_7_0_0,LOCK_41_7_1_0,buf682_ptr,buf682d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf680_buf680d,LOCK_41_6_4_4096,LOCK_41_6_5_4096,buf680_ptr,buf680d_ptr,0,index, REL_WRITE);
    window_release(window_buf683_buf683d,LOCK_41_6_6_4096,LOCK_41_6_7_0,buf683_ptr,buf683d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_7_bounds > 0)
      --proc_41_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}