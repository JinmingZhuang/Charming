// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/34_5/src/34_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_34_5_4_4096 20
#define LOCK_34_5_5_0 21
#define LOCK_35_5_6_4096 54
#define LOCK_35_5_7_4096 55
#define LOCK_34_5_2_4096 18
#define LOCK_34_5_3_4096 19
#define LOCK_34_5_6_0 22
#define LOCK_34_5_7_0 23

// Declare shared memory buffers
v4float buf758[256];
v4float buf758d[256];
v4float buf759[256];
v4float buf759d[256];
v4float buf760[256];
v4float buf760d[256];
v4float buf761[256];
v4float buf761d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf759_buf759d[1];
  window_datatype * buf759_ptr = (window_datatype * )buf759;
  window_datatype * buf759d_ptr = (window_datatype * )buf759d;
  window_init(window_buf759_buf759d, 1, buf759, LOCK_34_5_4_4096, buf759d, LOCK_34_5_5_0, 256, 256);
  window_internal window_buf760_buf760d[1];
  window_datatype * buf760_ptr = (window_datatype * )buf760;
  window_datatype * buf760d_ptr = (window_datatype * )buf760d;
  window_init(window_buf760_buf760d, 1, buf760, LOCK_35_5_6_4096, buf760d, LOCK_35_5_7_4096, 256, 256);
  window_internal window_buf758_buf758d[1];
  window_datatype * buf758_ptr = (window_datatype * )buf758;
  window_datatype * buf758d_ptr = (window_datatype * )buf758d;
  window_init(window_buf758_buf758d, 1, buf758, LOCK_34_5_2_4096, buf758d, LOCK_34_5_3_4096, 256, 256);
  window_internal window_buf761_buf761d[1];
  window_datatype * buf761_ptr = (window_datatype * )buf761;
  window_datatype * buf761d_ptr = (window_datatype * )buf761d;
  window_init(window_buf761_buf761d, 1, buf761, LOCK_34_5_6_0, buf761d, LOCK_34_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_34_5_bounds = sync_buffer[1];

  while (proc_34_5_bounds)
  {

    // Kernel call : i461:mm_kernel1
    window_acquire(window_buf759_buf759d,LOCK_34_5_4_4096,LOCK_34_5_5_0,buf759_ptr,buf759d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf760_buf760d,LOCK_35_5_6_4096,LOCK_35_5_7_4096,buf760_ptr,buf760d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf758_buf758d,LOCK_34_5_2_4096,LOCK_34_5_3_4096,buf758_ptr,buf758d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf761_buf761d,LOCK_34_5_6_0,LOCK_34_5_7_0,buf761_ptr,buf761d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf759_buf759d),get_input_window_float(window_buf760_buf760d),get_input_window_float(window_buf758_buf758d),get_output_window_float(window_buf761_buf761d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf759_buf759d,LOCK_34_5_4_4096,LOCK_34_5_5_0,buf759_ptr,buf759d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf760_buf760d,LOCK_35_5_6_4096,LOCK_35_5_7_4096,buf760_ptr,buf760d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf758_buf758d,LOCK_34_5_2_4096,LOCK_34_5_3_4096,buf758_ptr,buf758d_ptr,0,index, REL_WRITE);
    window_release(window_buf761_buf761d,LOCK_34_5_6_0,LOCK_34_5_7_0,buf761_ptr,buf761d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_34_5_bounds > 0)
      --proc_34_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}