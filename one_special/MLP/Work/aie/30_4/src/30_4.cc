// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_4/src/30_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_30_5_0_4096 32
#define LOCK_30_5_1_4096 33
#define LOCK_30_5_2_0 34
#define LOCK_30_5_3_0 35
#define LOCK_30_5_4_0 36
#define LOCK_30_5_5_0 37

// Declare shared memory buffers
v4float buf804[256];
v4float buf804d[256];
v4float buf805[256];
v4float buf805d[256];
v4float buf806[256];
v4float buf806d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf804_buf804d[1];
  window_datatype * buf804_ptr = (window_datatype * )buf804;
  window_datatype * buf804d_ptr = (window_datatype * )buf804d;
  window_init(window_buf804_buf804d, 1, buf804, LOCK_30_5_0_4096, buf804d, LOCK_30_5_1_4096, 256, 256);
  window_internal window_buf805_buf805d[1];
  window_datatype * buf805_ptr = (window_datatype * )buf805;
  window_datatype * buf805d_ptr = (window_datatype * )buf805d;
  window_init(window_buf805_buf805d, 1, buf805, LOCK_30_5_2_0, buf805d, LOCK_30_5_3_0, 256, 256);
  window_internal window_buf806_buf806d[1];
  window_datatype * buf806_ptr = (window_datatype * )buf806;
  window_datatype * buf806d_ptr = (window_datatype * )buf806d;
  window_init(window_buf806_buf806d, 1, buf806, LOCK_30_5_4_0, buf806d, LOCK_30_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_4_bounds = sync_buffer[1];

  while (proc_30_4_bounds)
  {

    // Kernel call : i484:mm_kernel0
    window_acquire(window_buf804_buf804d,LOCK_30_5_0_4096,LOCK_30_5_1_4096,buf804_ptr,buf804d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf805_buf805d,LOCK_30_5_2_0,LOCK_30_5_3_0,buf805_ptr,buf805d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf806_buf806d,LOCK_30_5_4_0,LOCK_30_5_5_0,buf806_ptr,buf806d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf804_buf804d),get_input_window_float(window_buf805_buf805d),get_output_window_float(window_buf806_buf806d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf804_buf804d,LOCK_30_5_0_4096,LOCK_30_5_1_4096,buf804_ptr,buf804d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf805_buf805d,LOCK_30_5_2_0,LOCK_30_5_3_0,buf805_ptr,buf805d_ptr,0,index, REL_WRITE);
    window_release(window_buf806_buf806d,LOCK_30_5_4_0,LOCK_30_5_5_0,buf806_ptr,buf806d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_4_bounds > 0)
      --proc_30_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}