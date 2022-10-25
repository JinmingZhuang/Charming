// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_2/src/32_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_31_2_4_4096 20
#define LOCK_31_2_5_0 21
#define LOCK_31_2_6_4096 22
#define LOCK_31_2_7_4096 23
#define LOCK_32_1_6_0 6
#define LOCK_32_1_7_4096 7
#define LOCK_32_2_4_4096 52
#define LOCK_32_2_5_0 53

// Declare shared memory buffers
v4float buf365[256];
v4float buf365d[256];
v4float buf366[256];
v4float buf366d[256];
v4float buf367[256];
v4float buf367d[256];
v4float buf368[256];
v4float buf368d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf366_buf366d[1];
  window_datatype * buf366_ptr = (window_datatype * )buf366;
  window_datatype * buf366d_ptr = (window_datatype * )buf366d;
  window_init(window_buf366_buf366d, 1, buf366, LOCK_31_2_4_4096, buf366d, LOCK_31_2_5_0, 256, 256);
  window_internal window_buf367_buf367d[1];
  window_datatype * buf367_ptr = (window_datatype * )buf367;
  window_datatype * buf367d_ptr = (window_datatype * )buf367d;
  window_init(window_buf367_buf367d, 1, buf367, LOCK_31_2_6_4096, buf367d, LOCK_31_2_7_4096, 256, 256);
  window_internal window_buf365_buf365d[1];
  window_datatype * buf365_ptr = (window_datatype * )buf365;
  window_datatype * buf365d_ptr = (window_datatype * )buf365d;
  window_init(window_buf365_buf365d, 1, buf365, LOCK_32_1_6_0, buf365d, LOCK_32_1_7_4096, 256, 256);
  window_internal window_buf368_buf368d[1];
  window_datatype * buf368_ptr = (window_datatype * )buf368;
  window_datatype * buf368d_ptr = (window_datatype * )buf368d;
  window_init(window_buf368_buf368d, 1, buf368, LOCK_32_2_4_4096, buf368d, LOCK_32_2_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_2_bounds = sync_buffer[1];

  while (proc_32_2_bounds)
  {

    // Kernel call : i264:mm_kernel1
    window_acquire(window_buf366_buf366d,LOCK_31_2_4_4096,LOCK_31_2_5_0,buf366_ptr,buf366d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf367_buf367d,LOCK_31_2_6_4096,LOCK_31_2_7_4096,buf367_ptr,buf367d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf365_buf365d,LOCK_32_1_6_0,LOCK_32_1_7_4096,buf365_ptr,buf365d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf368_buf368d,LOCK_32_2_4_4096,LOCK_32_2_5_0,buf368_ptr,buf368d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf366_buf366d),get_input_window_float(window_buf367_buf367d),get_input_window_float(window_buf365_buf365d),get_output_window_float(window_buf368_buf368d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf366_buf366d,LOCK_31_2_4_4096,LOCK_31_2_5_0,buf366_ptr,buf366d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf367_buf367d,LOCK_31_2_6_4096,LOCK_31_2_7_4096,buf367_ptr,buf367d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf365_buf365d,LOCK_32_1_6_0,LOCK_32_1_7_4096,buf365_ptr,buf365d_ptr,0,index, REL_WRITE);
    window_release(window_buf368_buf368d,LOCK_32_2_4_4096,LOCK_32_2_5_0,buf368_ptr,buf368d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_2_bounds > 0)
      --proc_32_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}