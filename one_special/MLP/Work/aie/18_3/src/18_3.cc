// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_3/src/18_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_2_2_4096 2
#define LOCK_18_2_3_4096 3
#define LOCK_19_3_0_0 48
#define LOCK_19_3_1_0 49
#define LOCK_18_3_4_0 20
#define LOCK_18_3_5_4096 21
#define LOCK_18_3_6_0 22
#define LOCK_18_3_7_4096 23

// Declare shared memory buffers
v4float buf200[256];
v4float buf200d[256];
v4float buf201[256];
v4float buf201d[256];
v4float buf202[256];
v4float buf202d[256];
v4float buf203[256];
v4float buf203d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf201_buf201d[1];
  window_datatype * buf201_ptr = (window_datatype * )buf201;
  window_datatype * buf201d_ptr = (window_datatype * )buf201d;
  window_init(window_buf201_buf201d, 1, buf201, LOCK_18_2_2_4096, buf201d, LOCK_18_2_3_4096, 256, 256);
  window_internal window_buf202_buf202d[1];
  window_datatype * buf202_ptr = (window_datatype * )buf202;
  window_datatype * buf202d_ptr = (window_datatype * )buf202d;
  window_init(window_buf202_buf202d, 1, buf202, LOCK_19_3_0_0, buf202d, LOCK_19_3_1_0, 256, 256);
  window_internal window_buf200_buf200d[1];
  window_datatype * buf200_ptr = (window_datatype * )buf200;
  window_datatype * buf200d_ptr = (window_datatype * )buf200d;
  window_init(window_buf200_buf200d, 1, buf200, LOCK_18_3_4_0, buf200d, LOCK_18_3_5_4096, 256, 256);
  window_internal window_buf203_buf203d[1];
  window_datatype * buf203_ptr = (window_datatype * )buf203;
  window_datatype * buf203d_ptr = (window_datatype * )buf203d;
  window_init(window_buf203_buf203d, 1, buf203, LOCK_18_3_6_0, buf203d, LOCK_18_3_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_3_bounds = sync_buffer[1];

  while (proc_18_3_bounds)
  {

    // Kernel call : i181:mm_kernel1
    window_acquire(window_buf201_buf201d,LOCK_18_2_2_4096,LOCK_18_2_3_4096,buf201_ptr,buf201d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf202_buf202d,LOCK_19_3_0_0,LOCK_19_3_1_0,buf202_ptr,buf202d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf200_buf200d,LOCK_18_3_4_0,LOCK_18_3_5_4096,buf200_ptr,buf200d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf203_buf203d,LOCK_18_3_6_0,LOCK_18_3_7_4096,buf203_ptr,buf203d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf201_buf201d),get_input_window_float(window_buf202_buf202d),get_input_window_float(window_buf200_buf200d),get_output_window_float(window_buf203_buf203d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf201_buf201d,LOCK_18_2_2_4096,LOCK_18_2_3_4096,buf201_ptr,buf201d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf202_buf202d,LOCK_19_3_0_0,LOCK_19_3_1_0,buf202_ptr,buf202d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf200_buf200d,LOCK_18_3_4_0,LOCK_18_3_5_4096,buf200_ptr,buf200d_ptr,0,index, REL_WRITE);
    window_release(window_buf203_buf203d,LOCK_18_3_6_0,LOCK_18_3_7_4096,buf203_ptr,buf203d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_3_bounds > 0)
      --proc_18_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}