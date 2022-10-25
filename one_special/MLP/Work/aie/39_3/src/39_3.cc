// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_3/src/39_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_4_0_0 32
#define LOCK_39_4_1_0 33
#define LOCK_39_3_2_4096 18
#define LOCK_39_3_3_4096 19
#define LOCK_39_3_0_0 16
#define LOCK_39_3_1_0 17
#define LOCK_39_3_4_0 20
#define LOCK_39_3_5_4096 21

// Declare shared memory buffers
v4float buf452[256];
v4float buf452d[256];
v4float buf453[256];
v4float buf453d[256];
v4float buf454[256];
v4float buf454d[256];
v4float buf455[256];
v4float buf455d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf453_buf453d[1];
  window_datatype * buf453_ptr = (window_datatype * )buf453;
  window_datatype * buf453d_ptr = (window_datatype * )buf453d;
  window_init(window_buf453_buf453d, 1, buf453, LOCK_39_4_0_0, buf453d, LOCK_39_4_1_0, 256, 256);
  window_internal window_buf454_buf454d[1];
  window_datatype * buf454_ptr = (window_datatype * )buf454;
  window_datatype * buf454d_ptr = (window_datatype * )buf454d;
  window_init(window_buf454_buf454d, 1, buf454, LOCK_39_3_2_4096, buf454d, LOCK_39_3_3_4096, 256, 256);
  window_internal window_buf452_buf452d[1];
  window_datatype * buf452_ptr = (window_datatype * )buf452;
  window_datatype * buf452d_ptr = (window_datatype * )buf452d;
  window_init(window_buf452_buf452d, 1, buf452, LOCK_39_3_0_0, buf452d, LOCK_39_3_1_0, 256, 256);
  window_internal window_buf455_buf455d[1];
  window_datatype * buf455_ptr = (window_datatype * )buf455;
  window_datatype * buf455d_ptr = (window_datatype * )buf455d;
  window_init(window_buf455_buf455d, 1, buf455, LOCK_39_3_4_0, buf455d, LOCK_39_3_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_3_bounds = sync_buffer[1];

  while (proc_39_3_bounds)
  {

    // Kernel call : i307:mm_kernel1
    window_acquire(window_buf453_buf453d,LOCK_39_4_0_0,LOCK_39_4_1_0,buf453_ptr,buf453d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf454_buf454d,LOCK_39_3_2_4096,LOCK_39_3_3_4096,buf454_ptr,buf454d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf452_buf452d,LOCK_39_3_0_0,LOCK_39_3_1_0,buf452_ptr,buf452d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf455_buf455d,LOCK_39_3_4_0,LOCK_39_3_5_4096,buf455_ptr,buf455d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf453_buf453d),get_input_window_float(window_buf454_buf454d),get_input_window_float(window_buf452_buf452d),get_output_window_float(window_buf455_buf455d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf453_buf453d,LOCK_39_4_0_0,LOCK_39_4_1_0,buf453_ptr,buf453d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf454_buf454d,LOCK_39_3_2_4096,LOCK_39_3_3_4096,buf454_ptr,buf454d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf452_buf452d,LOCK_39_3_0_0,LOCK_39_3_1_0,buf452_ptr,buf452d_ptr,0,index, REL_WRITE);
    window_release(window_buf455_buf455d,LOCK_39_3_4_0,LOCK_39_3_5_4096,buf455_ptr,buf455d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_3_bounds > 0)
      --proc_39_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}