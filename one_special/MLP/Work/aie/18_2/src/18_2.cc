// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_2/src/18_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_3_0_4096 32
#define LOCK_18_3_1_4096 33
#define LOCK_18_3_2_0 34
#define LOCK_18_3_3_0 35
#define LOCK_18_1_6_4096 6
#define LOCK_18_1_7_0 7
#define LOCK_18_3_4_0 36
#define LOCK_18_3_5_4096 37

// Declare shared memory buffers
v4float buf197[256];
v4float buf197d[256];
v4float buf198[256];
v4float buf198d[256];
v4float buf199[256];
v4float buf199d[256];
v4float buf200[256];
v4float buf200d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf198_buf198d[1];
  window_datatype * buf198_ptr = (window_datatype * )buf198;
  window_datatype * buf198d_ptr = (window_datatype * )buf198d;
  window_init(window_buf198_buf198d, 1, buf198, LOCK_18_3_0_4096, buf198d, LOCK_18_3_1_4096, 256, 256);
  window_internal window_buf199_buf199d[1];
  window_datatype * buf199_ptr = (window_datatype * )buf199;
  window_datatype * buf199d_ptr = (window_datatype * )buf199d;
  window_init(window_buf199_buf199d, 1, buf199, LOCK_18_3_2_0, buf199d, LOCK_18_3_3_0, 256, 256);
  window_internal window_buf197_buf197d[1];
  window_datatype * buf197_ptr = (window_datatype * )buf197;
  window_datatype * buf197d_ptr = (window_datatype * )buf197d;
  window_init(window_buf197_buf197d, 1, buf197, LOCK_18_1_6_4096, buf197d, LOCK_18_1_7_0, 256, 256);
  window_internal window_buf200_buf200d[1];
  window_datatype * buf200_ptr = (window_datatype * )buf200;
  window_datatype * buf200d_ptr = (window_datatype * )buf200d;
  window_init(window_buf200_buf200d, 1, buf200, LOCK_18_3_4_0, buf200d, LOCK_18_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_2_bounds = sync_buffer[1];

  while (proc_18_2_bounds)
  {

    // Kernel call : i180:mm_kernel1
    window_acquire(window_buf198_buf198d,LOCK_18_3_0_4096,LOCK_18_3_1_4096,buf198_ptr,buf198d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf199_buf199d,LOCK_18_3_2_0,LOCK_18_3_3_0,buf199_ptr,buf199d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf197_buf197d,LOCK_18_1_6_4096,LOCK_18_1_7_0,buf197_ptr,buf197d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf200_buf200d,LOCK_18_3_4_0,LOCK_18_3_5_4096,buf200_ptr,buf200d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf198_buf198d),get_input_window_float(window_buf199_buf199d),get_input_window_float(window_buf197_buf197d),get_output_window_float(window_buf200_buf200d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf198_buf198d,LOCK_18_3_0_4096,LOCK_18_3_1_4096,buf198_ptr,buf198d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf199_buf199d,LOCK_18_3_2_0,LOCK_18_3_3_0,buf199_ptr,buf199d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf197_buf197d,LOCK_18_1_6_4096,LOCK_18_1_7_0,buf197_ptr,buf197d_ptr,0,index, REL_WRITE);
    window_release(window_buf200_buf200d,LOCK_18_3_4_0,LOCK_18_3_5_4096,buf200_ptr,buf200d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_2_bounds > 0)
      --proc_18_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}