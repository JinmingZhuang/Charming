// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/6_5/src/6_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_6_5_4_0 20
#define LOCK_6_5_5_0 21
#define LOCK_6_6_0_0 32
#define LOCK_6_6_1_0 33
#define LOCK_6_5_2_4096 18
#define LOCK_6_5_3_4096 19
#define LOCK_6_5_6_0 22
#define LOCK_6_5_7_0 23

// Declare shared memory buffers
v4float buf1094[256];
v4float buf1094d[256];
v4float buf1095[256];
v4float buf1095d[256];
v4float buf1096[256];
v4float buf1096d[256];
v4float buf1097[256];
v4float buf1097d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1095_buf1095d[1];
  window_datatype * buf1095_ptr = (window_datatype * )buf1095;
  window_datatype * buf1095d_ptr = (window_datatype * )buf1095d;
  window_init(window_buf1095_buf1095d, 1, buf1095, LOCK_6_5_4_0, buf1095d, LOCK_6_5_5_0, 256, 256);
  window_internal window_buf1096_buf1096d[1];
  window_datatype * buf1096_ptr = (window_datatype * )buf1096;
  window_datatype * buf1096d_ptr = (window_datatype * )buf1096d;
  window_init(window_buf1096_buf1096d, 1, buf1096, LOCK_6_6_0_0, buf1096d, LOCK_6_6_1_0, 256, 256);
  window_internal window_buf1094_buf1094d[1];
  window_datatype * buf1094_ptr = (window_datatype * )buf1094;
  window_datatype * buf1094d_ptr = (window_datatype * )buf1094d;
  window_init(window_buf1094_buf1094d, 1, buf1094, LOCK_6_5_2_4096, buf1094d, LOCK_6_5_3_4096, 256, 256);
  window_internal window_buf1097_buf1097d[1];
  window_datatype * buf1097_ptr = (window_datatype * )buf1097;
  window_datatype * buf1097d_ptr = (window_datatype * )buf1097d;
  window_init(window_buf1097_buf1097d, 1, buf1097, LOCK_6_5_6_0, buf1097d, LOCK_6_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_6_5_bounds = sync_buffer[1];

  while (proc_6_5_bounds)
  {

    // Kernel call : i629:mm_kernel1
    window_acquire(window_buf1095_buf1095d,LOCK_6_5_4_0,LOCK_6_5_5_0,buf1095_ptr,buf1095d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1096_buf1096d,LOCK_6_6_0_0,LOCK_6_6_1_0,buf1096_ptr,buf1096d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1094_buf1094d,LOCK_6_5_2_4096,LOCK_6_5_3_4096,buf1094_ptr,buf1094d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1097_buf1097d,LOCK_6_5_6_0,LOCK_6_5_7_0,buf1097_ptr,buf1097d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1095_buf1095d),get_input_window_float(window_buf1096_buf1096d),get_input_window_float(window_buf1094_buf1094d),get_output_window_float(window_buf1097_buf1097d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1095_buf1095d,LOCK_6_5_4_0,LOCK_6_5_5_0,buf1095_ptr,buf1095d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1096_buf1096d,LOCK_6_6_0_0,LOCK_6_6_1_0,buf1096_ptr,buf1096d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1094_buf1094d,LOCK_6_5_2_4096,LOCK_6_5_3_4096,buf1094_ptr,buf1094d_ptr,0,index, REL_WRITE);
    window_release(window_buf1097_buf1097d,LOCK_6_5_6_0,LOCK_6_5_7_0,buf1097_ptr,buf1097d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_6_5_bounds > 0)
      --proc_6_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}