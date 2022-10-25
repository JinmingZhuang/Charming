// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_4/src/34_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_5_0_4096 32
#define LOCK_34_5_1_0 33
#define LOCK_34_3_6_0 6
#define LOCK_34_3_7_4096 7
#define LOCK_34_5_2_4096 34
#define LOCK_34_5_3_4096 35

// Declare shared memory buffers
v4float buf756[256];
v4float buf756d[256];
v4float buf757[256];
v4float buf757d[256];
v4float buf758[256];
v4float buf758d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf756_buf756d[1];
  window_datatype * buf756_ptr = (window_datatype * )buf756;
  window_datatype * buf756d_ptr = (window_datatype * )buf756d;
  window_init(window_buf756_buf756d, 1, buf756, LOCK_34_5_0_4096, buf756d, LOCK_34_5_1_0, 256, 256);
  window_internal window_buf757_buf757d[1];
  window_datatype * buf757_ptr = (window_datatype * )buf757;
  window_datatype * buf757d_ptr = (window_datatype * )buf757d;
  window_init(window_buf757_buf757d, 1, buf757, LOCK_34_3_6_0, buf757d, LOCK_34_3_7_4096, 256, 256);
  window_internal window_buf758_buf758d[1];
  window_datatype * buf758_ptr = (window_datatype * )buf758;
  window_datatype * buf758d_ptr = (window_datatype * )buf758d;
  window_init(window_buf758_buf758d, 1, buf758, LOCK_34_5_2_4096, buf758d, LOCK_34_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_4_bounds = sync_buffer[1];

  while (proc_34_4_bounds)
  {

    // Kernel call : i460:mm_kernel0
    window_acquire(window_buf756_buf756d,LOCK_34_5_0_4096,LOCK_34_5_1_0,buf756_ptr,buf756d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf757_buf757d,LOCK_34_3_6_0,LOCK_34_3_7_4096,buf757_ptr,buf757d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf758_buf758d,LOCK_34_5_2_4096,LOCK_34_5_3_4096,buf758_ptr,buf758d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf756_buf756d),get_input_window_float(window_buf757_buf757d),get_output_window_float(window_buf758_buf758d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf756_buf756d,LOCK_34_5_0_4096,LOCK_34_5_1_0,buf756_ptr,buf756d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf757_buf757d,LOCK_34_3_6_0,LOCK_34_3_7_4096,buf757_ptr,buf757d_ptr,0,index, REL_WRITE);
    window_release(window_buf758_buf758d,LOCK_34_5_2_4096,LOCK_34_5_3_4096,buf758_ptr,buf758d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_4_bounds > 0)
      --proc_34_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}