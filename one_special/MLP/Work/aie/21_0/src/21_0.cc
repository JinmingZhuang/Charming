// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/21_0/src/21_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_21_1_0_4096 32
#define LOCK_21_1_1_0 33
#define LOCK_21_1_2_0 34
#define LOCK_21_1_3_4096 35
#define LOCK_21_1_4_4096 36
#define LOCK_21_1_5_0 37

// Declare shared memory buffers
v4float buf228[256];
v4float buf228d[256];
v4float buf229[256];
v4float buf229d[256];
v4float buf230[256];
v4float buf230d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf228_buf228d[1];
  window_datatype * buf228_ptr = (window_datatype * )buf228;
  window_datatype * buf228d_ptr = (window_datatype * )buf228d;
  window_init(window_buf228_buf228d, 1, buf228, LOCK_21_1_0_4096, buf228d, LOCK_21_1_1_0, 256, 256);
  window_internal window_buf229_buf229d[1];
  window_datatype * buf229_ptr = (window_datatype * )buf229;
  window_datatype * buf229d_ptr = (window_datatype * )buf229d;
  window_init(window_buf229_buf229d, 1, buf229, LOCK_21_1_2_0, buf229d, LOCK_21_1_3_4096, 256, 256);
  window_internal window_buf230_buf230d[1];
  window_datatype * buf230_ptr = (window_datatype * )buf230;
  window_datatype * buf230d_ptr = (window_datatype * )buf230d;
  window_init(window_buf230_buf230d, 1, buf230, LOCK_21_1_4_4096, buf230d, LOCK_21_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_21_0_bounds = sync_buffer[1];

  while (proc_21_0_bounds)
  {

    // Kernel call : i196:mm_kernel0
    window_acquire(window_buf228_buf228d,LOCK_21_1_0_4096,LOCK_21_1_1_0,buf228_ptr,buf228d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf229_buf229d,LOCK_21_1_2_0,LOCK_21_1_3_4096,buf229_ptr,buf229d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf230_buf230d,LOCK_21_1_4_4096,LOCK_21_1_5_0,buf230_ptr,buf230d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf228_buf228d),get_input_window_float(window_buf229_buf229d),get_output_window_float(window_buf230_buf230d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf228_buf228d,LOCK_21_1_0_4096,LOCK_21_1_1_0,buf228_ptr,buf228d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf229_buf229d,LOCK_21_1_2_0,LOCK_21_1_3_4096,buf229_ptr,buf229d_ptr,0,index, REL_WRITE);
    window_release(window_buf230_buf230d,LOCK_21_1_4_4096,LOCK_21_1_5_0,buf230_ptr,buf230d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_21_0_bounds > 0)
      --proc_21_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}