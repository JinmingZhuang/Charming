// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/35_5/src/35_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_35_4_2_4096 2
#define LOCK_35_4_3_4096 3
#define LOCK_35_5_2_4096 18
#define LOCK_35_5_3_4096 19
#define LOCK_35_5_0_0 16
#define LOCK_35_5_1_0 17
#define LOCK_35_5_4_0 20
#define LOCK_35_5_5_0 21

// Declare shared memory buffers
v4float buf746[256];
v4float buf746d[256];
v4float buf747[256];
v4float buf747d[256];
v4float buf748[256];
v4float buf748d[256];
v4float buf749[256];
v4float buf749d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf747_buf747d[1];
  window_datatype * buf747_ptr = (window_datatype * )buf747;
  window_datatype * buf747d_ptr = (window_datatype * )buf747d;
  window_init(window_buf747_buf747d, 1, buf747, LOCK_35_4_2_4096, buf747d, LOCK_35_4_3_4096, 256, 256);
  window_internal window_buf748_buf748d[1];
  window_datatype * buf748_ptr = (window_datatype * )buf748;
  window_datatype * buf748d_ptr = (window_datatype * )buf748d;
  window_init(window_buf748_buf748d, 1, buf748, LOCK_35_5_2_4096, buf748d, LOCK_35_5_3_4096, 256, 256);
  window_internal window_buf746_buf746d[1];
  window_datatype * buf746_ptr = (window_datatype * )buf746;
  window_datatype * buf746d_ptr = (window_datatype * )buf746d;
  window_init(window_buf746_buf746d, 1, buf746, LOCK_35_5_0_0, buf746d, LOCK_35_5_1_0, 256, 256);
  window_internal window_buf749_buf749d[1];
  window_datatype * buf749_ptr = (window_datatype * )buf749;
  window_datatype * buf749d_ptr = (window_datatype * )buf749d;
  window_init(window_buf749_buf749d, 1, buf749, LOCK_35_5_4_0, buf749d, LOCK_35_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_35_5_bounds = sync_buffer[1];

  while (proc_35_5_bounds)
  {

    // Kernel call : i455:mm_kernel1
    window_acquire(window_buf747_buf747d,LOCK_35_4_2_4096,LOCK_35_4_3_4096,buf747_ptr,buf747d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf748_buf748d,LOCK_35_5_2_4096,LOCK_35_5_3_4096,buf748_ptr,buf748d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf746_buf746d,LOCK_35_5_0_0,LOCK_35_5_1_0,buf746_ptr,buf746d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf749_buf749d,LOCK_35_5_4_0,LOCK_35_5_5_0,buf749_ptr,buf749d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf747_buf747d),get_input_window_float(window_buf748_buf748d),get_input_window_float(window_buf746_buf746d),get_output_window_float(window_buf749_buf749d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf747_buf747d,LOCK_35_4_2_4096,LOCK_35_4_3_4096,buf747_ptr,buf747d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf748_buf748d,LOCK_35_5_2_4096,LOCK_35_5_3_4096,buf748_ptr,buf748d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf746_buf746d,LOCK_35_5_0_0,LOCK_35_5_1_0,buf746_ptr,buf746d_ptr,0,index, REL_WRITE);
    window_release(window_buf749_buf749d,LOCK_35_5_4_0,LOCK_35_5_5_0,buf749_ptr,buf749d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_35_5_bounds > 0)
      --proc_35_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}