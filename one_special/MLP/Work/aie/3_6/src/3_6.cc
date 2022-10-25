// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_6/src/3_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_7_0_4096 32
#define LOCK_3_7_1_4096 33
#define LOCK_3_6_2_4096 50
#define LOCK_3_6_3_4096 51
#define LOCK_3_5_6_0 6
#define LOCK_3_5_7_0 7
#define LOCK_3_7_2_4096 34
#define LOCK_3_7_3_4096 35

// Declare shared memory buffers
v4float buf1133[256];
v4float buf1133d[256];
v4float buf1134[256];
v4float buf1134d[256];
v4float buf1135[256];
v4float buf1135d[256];
v4float buf1136[256];
v4float buf1136d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1134_buf1134d[1];
  window_datatype * buf1134_ptr = (window_datatype * )buf1134;
  window_datatype * buf1134d_ptr = (window_datatype * )buf1134d;
  window_init(window_buf1134_buf1134d, 1, buf1134, LOCK_3_7_0_4096, buf1134d, LOCK_3_7_1_4096, 256, 256);
  window_internal window_buf1135_buf1135d[1];
  window_datatype * buf1135_ptr = (window_datatype * )buf1135;
  window_datatype * buf1135d_ptr = (window_datatype * )buf1135d;
  window_init(window_buf1135_buf1135d, 1, buf1135, LOCK_3_6_2_4096, buf1135d, LOCK_3_6_3_4096, 256, 256);
  window_internal window_buf1133_buf1133d[1];
  window_datatype * buf1133_ptr = (window_datatype * )buf1133;
  window_datatype * buf1133d_ptr = (window_datatype * )buf1133d;
  window_init(window_buf1133_buf1133d, 1, buf1133, LOCK_3_5_6_0, buf1133d, LOCK_3_5_7_0, 256, 256);
  window_internal window_buf1136_buf1136d[1];
  window_datatype * buf1136_ptr = (window_datatype * )buf1136;
  window_datatype * buf1136d_ptr = (window_datatype * )buf1136d;
  window_init(window_buf1136_buf1136d, 1, buf1136, LOCK_3_7_2_4096, buf1136d, LOCK_3_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_6_bounds = sync_buffer[1];

  while (proc_3_6_bounds)
  {

    // Kernel call : i648:mm_kernel1
    window_acquire(window_buf1134_buf1134d,LOCK_3_7_0_4096,LOCK_3_7_1_4096,buf1134_ptr,buf1134d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1135_buf1135d,LOCK_3_6_2_4096,LOCK_3_6_3_4096,buf1135_ptr,buf1135d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1133_buf1133d,LOCK_3_5_6_0,LOCK_3_5_7_0,buf1133_ptr,buf1133d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1136_buf1136d,LOCK_3_7_2_4096,LOCK_3_7_3_4096,buf1136_ptr,buf1136d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1134_buf1134d),get_input_window_float(window_buf1135_buf1135d),get_input_window_float(window_buf1133_buf1133d),get_output_window_float(window_buf1136_buf1136d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1134_buf1134d,LOCK_3_7_0_4096,LOCK_3_7_1_4096,buf1134_ptr,buf1134d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1135_buf1135d,LOCK_3_6_2_4096,LOCK_3_6_3_4096,buf1135_ptr,buf1135d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1133_buf1133d,LOCK_3_5_6_0,LOCK_3_5_7_0,buf1133_ptr,buf1133d_ptr,0,index, REL_WRITE);
    window_release(window_buf1136_buf1136d,LOCK_3_7_2_4096,LOCK_3_7_3_4096,buf1136_ptr,buf1136d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_6_bounds > 0)
      --proc_3_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}