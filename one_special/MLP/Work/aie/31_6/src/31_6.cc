// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/31_6/src/31_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_5_6_4096 6
#define LOCK_31_5_7_4096 7
#define LOCK_31_7_0_4096 32
#define LOCK_31_7_1_4096 33
#define LOCK_31_5_4_0 4
#define LOCK_31_5_5_0 5
#define LOCK_31_7_2_4096 34
#define LOCK_31_7_3_4096 35

// Declare shared memory buffers
v4float buf797[256];
v4float buf797d[256];
v4float buf798[256];
v4float buf798d[256];
v4float buf799[256];
v4float buf799d[256];
v4float buf800[256];
v4float buf800d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf798_buf798d[1];
  window_datatype * buf798_ptr = (window_datatype * )buf798;
  window_datatype * buf798d_ptr = (window_datatype * )buf798d;
  window_init(window_buf798_buf798d, 1, buf798, LOCK_31_5_6_4096, buf798d, LOCK_31_5_7_4096, 256, 256);
  window_internal window_buf799_buf799d[1];
  window_datatype * buf799_ptr = (window_datatype * )buf799;
  window_datatype * buf799d_ptr = (window_datatype * )buf799d;
  window_init(window_buf799_buf799d, 1, buf799, LOCK_31_7_0_4096, buf799d, LOCK_31_7_1_4096, 256, 256);
  window_internal window_buf797_buf797d[1];
  window_datatype * buf797_ptr = (window_datatype * )buf797;
  window_datatype * buf797d_ptr = (window_datatype * )buf797d;
  window_init(window_buf797_buf797d, 1, buf797, LOCK_31_5_4_0, buf797d, LOCK_31_5_5_0, 256, 256);
  window_internal window_buf800_buf800d[1];
  window_datatype * buf800_ptr = (window_datatype * )buf800;
  window_datatype * buf800d_ptr = (window_datatype * )buf800d;
  window_init(window_buf800_buf800d, 1, buf800, LOCK_31_7_2_4096, buf800d, LOCK_31_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_31_6_bounds = sync_buffer[1];

  while (proc_31_6_bounds)
  {

    // Kernel call : i480:mm_kernel1
    window_acquire(window_buf798_buf798d,LOCK_31_5_6_4096,LOCK_31_5_7_4096,buf798_ptr,buf798d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf799_buf799d,LOCK_31_7_0_4096,LOCK_31_7_1_4096,buf799_ptr,buf799d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf797_buf797d,LOCK_31_5_4_0,LOCK_31_5_5_0,buf797_ptr,buf797d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf800_buf800d,LOCK_31_7_2_4096,LOCK_31_7_3_4096,buf800_ptr,buf800d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf798_buf798d),get_input_window_float(window_buf799_buf799d),get_input_window_float(window_buf797_buf797d),get_output_window_float(window_buf800_buf800d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf798_buf798d,LOCK_31_5_6_4096,LOCK_31_5_7_4096,buf798_ptr,buf798d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf799_buf799d,LOCK_31_7_0_4096,LOCK_31_7_1_4096,buf799_ptr,buf799d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf797_buf797d,LOCK_31_5_4_0,LOCK_31_5_5_0,buf797_ptr,buf797d_ptr,0,index, REL_WRITE);
    window_release(window_buf800_buf800d,LOCK_31_7_2_4096,LOCK_31_7_3_4096,buf800_ptr,buf800d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_31_6_bounds > 0)
      --proc_31_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}