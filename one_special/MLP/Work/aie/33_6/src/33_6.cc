// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_6/src/33_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_7_0_0 32
#define LOCK_33_7_1_4096 33
#define LOCK_32_6_0_0 16
#define LOCK_32_6_1_0 17
#define LOCK_33_5_6_0 6
#define LOCK_33_5_7_0 7
#define LOCK_33_7_2_4096 34
#define LOCK_33_7_3_4096 35

// Declare shared memory buffers
v4float buf773[256];
v4float buf773d[256];
v4float buf774[256];
v4float buf774d[256];
v4float buf775[256];
v4float buf775d[256];
v4float buf776[256];
v4float buf776d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf774_buf774d[1];
  window_datatype * buf774_ptr = (window_datatype * )buf774;
  window_datatype * buf774d_ptr = (window_datatype * )buf774d;
  window_init(window_buf774_buf774d, 1, buf774, LOCK_33_7_0_0, buf774d, LOCK_33_7_1_4096, 256, 256);
  window_internal window_buf775_buf775d[1];
  window_datatype * buf775_ptr = (window_datatype * )buf775;
  window_datatype * buf775d_ptr = (window_datatype * )buf775d;
  window_init(window_buf775_buf775d, 1, buf775, LOCK_32_6_0_0, buf775d, LOCK_32_6_1_0, 256, 256);
  window_internal window_buf773_buf773d[1];
  window_datatype * buf773_ptr = (window_datatype * )buf773;
  window_datatype * buf773d_ptr = (window_datatype * )buf773d;
  window_init(window_buf773_buf773d, 1, buf773, LOCK_33_5_6_0, buf773d, LOCK_33_5_7_0, 256, 256);
  window_internal window_buf776_buf776d[1];
  window_datatype * buf776_ptr = (window_datatype * )buf776;
  window_datatype * buf776d_ptr = (window_datatype * )buf776d;
  window_init(window_buf776_buf776d, 1, buf776, LOCK_33_7_2_4096, buf776d, LOCK_33_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_6_bounds = sync_buffer[1];

  while (proc_33_6_bounds)
  {

    // Kernel call : i468:mm_kernel1
    window_acquire(window_buf774_buf774d,LOCK_33_7_0_0,LOCK_33_7_1_4096,buf774_ptr,buf774d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf775_buf775d,LOCK_32_6_0_0,LOCK_32_6_1_0,buf775_ptr,buf775d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf773_buf773d,LOCK_33_5_6_0,LOCK_33_5_7_0,buf773_ptr,buf773d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf776_buf776d,LOCK_33_7_2_4096,LOCK_33_7_3_4096,buf776_ptr,buf776d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf774_buf774d),get_input_window_float(window_buf775_buf775d),get_input_window_float(window_buf773_buf773d),get_output_window_float(window_buf776_buf776d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf774_buf774d,LOCK_33_7_0_0,LOCK_33_7_1_4096,buf774_ptr,buf774d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf775_buf775d,LOCK_32_6_0_0,LOCK_32_6_1_0,buf775_ptr,buf775d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf773_buf773d,LOCK_33_5_6_0,LOCK_33_5_7_0,buf773_ptr,buf773d_ptr,0,index, REL_WRITE);
    window_release(window_buf776_buf776d,LOCK_33_7_2_4096,LOCK_33_7_3_4096,buf776_ptr,buf776d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_6_bounds > 0)
      --proc_33_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}