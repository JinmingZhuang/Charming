// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_7/src/3_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_7_4_0 20
#define LOCK_3_7_5_0 21
#define LOCK_4_7_6_4096 54
#define LOCK_4_7_7_0 55
#define LOCK_3_7_2_4096 18
#define LOCK_3_7_3_4096 19
#define LOCK_3_7_6_0 22
#define LOCK_3_7_7_0 23

// Declare shared memory buffers
v4float buf1136[256];
v4float buf1136d[256];
v4float buf1137[256];
v4float buf1137d[256];
v4float buf1138[256];
v4float buf1138d[256];
v4float buf1139[256];
v4float buf1139d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1137_buf1137d[1];
  window_datatype * buf1137_ptr = (window_datatype * )buf1137;
  window_datatype * buf1137d_ptr = (window_datatype * )buf1137d;
  window_init(window_buf1137_buf1137d, 1, buf1137, LOCK_3_7_4_0, buf1137d, LOCK_3_7_5_0, 256, 256);
  window_internal window_buf1138_buf1138d[1];
  window_datatype * buf1138_ptr = (window_datatype * )buf1138;
  window_datatype * buf1138d_ptr = (window_datatype * )buf1138d;
  window_init(window_buf1138_buf1138d, 1, buf1138, LOCK_4_7_6_4096, buf1138d, LOCK_4_7_7_0, 256, 256);
  window_internal window_buf1136_buf1136d[1];
  window_datatype * buf1136_ptr = (window_datatype * )buf1136;
  window_datatype * buf1136d_ptr = (window_datatype * )buf1136d;
  window_init(window_buf1136_buf1136d, 1, buf1136, LOCK_3_7_2_4096, buf1136d, LOCK_3_7_3_4096, 256, 256);
  window_internal window_buf1139_buf1139d[1];
  window_datatype * buf1139_ptr = (window_datatype * )buf1139;
  window_datatype * buf1139d_ptr = (window_datatype * )buf1139d;
  window_init(window_buf1139_buf1139d, 1, buf1139, LOCK_3_7_6_0, buf1139d, LOCK_3_7_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_7_bounds = sync_buffer[1];

  while (proc_3_7_bounds)
  {

    // Kernel call : i649:mm_kernel1
    window_acquire(window_buf1137_buf1137d,LOCK_3_7_4_0,LOCK_3_7_5_0,buf1137_ptr,buf1137d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1138_buf1138d,LOCK_4_7_6_4096,LOCK_4_7_7_0,buf1138_ptr,buf1138d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1136_buf1136d,LOCK_3_7_2_4096,LOCK_3_7_3_4096,buf1136_ptr,buf1136d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1139_buf1139d,LOCK_3_7_6_0,LOCK_3_7_7_0,buf1139_ptr,buf1139d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1137_buf1137d),get_input_window_float(window_buf1138_buf1138d),get_input_window_float(window_buf1136_buf1136d),get_output_window_float(window_buf1139_buf1139d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1137_buf1137d,LOCK_3_7_4_0,LOCK_3_7_5_0,buf1137_ptr,buf1137d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1138_buf1138d,LOCK_4_7_6_4096,LOCK_4_7_7_0,buf1138_ptr,buf1138d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1136_buf1136d,LOCK_3_7_2_4096,LOCK_3_7_3_4096,buf1136_ptr,buf1136d_ptr,0,index, REL_WRITE);
    window_release(window_buf1139_buf1139d,LOCK_3_7_6_0,LOCK_3_7_7_0,buf1139_ptr,buf1139d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_7_bounds > 0)
      --proc_3_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}