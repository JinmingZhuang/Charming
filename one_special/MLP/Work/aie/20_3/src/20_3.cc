// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_3/src/20_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_4_0_0 32
#define LOCK_20_4_1_0 33
#define LOCK_20_2_2_4096 2
#define LOCK_20_2_3_4096 3
#define LOCK_20_3_2_4096 18
#define LOCK_20_3_3_4096 19
#define LOCK_20_3_4_0 20
#define LOCK_20_3_5_0 21

// Declare shared memory buffers
v4float buf224[256];
v4float buf224d[256];
v4float buf225[256];
v4float buf225d[256];
v4float buf226[256];
v4float buf226d[256];
v4float buf227[256];
v4float buf227d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf225_buf225d[1];
  window_datatype * buf225_ptr = (window_datatype * )buf225;
  window_datatype * buf225d_ptr = (window_datatype * )buf225d;
  window_init(window_buf225_buf225d, 1, buf225, LOCK_20_4_0_0, buf225d, LOCK_20_4_1_0, 256, 256);
  window_internal window_buf226_buf226d[1];
  window_datatype * buf226_ptr = (window_datatype * )buf226;
  window_datatype * buf226d_ptr = (window_datatype * )buf226d;
  window_init(window_buf226_buf226d, 1, buf226, LOCK_20_2_2_4096, buf226d, LOCK_20_2_3_4096, 256, 256);
  window_internal window_buf224_buf224d[1];
  window_datatype * buf224_ptr = (window_datatype * )buf224;
  window_datatype * buf224d_ptr = (window_datatype * )buf224d;
  window_init(window_buf224_buf224d, 1, buf224, LOCK_20_3_2_4096, buf224d, LOCK_20_3_3_4096, 256, 256);
  window_internal window_buf227_buf227d[1];
  window_datatype * buf227_ptr = (window_datatype * )buf227;
  window_datatype * buf227d_ptr = (window_datatype * )buf227d;
  window_init(window_buf227_buf227d, 1, buf227, LOCK_20_3_4_0, buf227d, LOCK_20_3_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_3_bounds = sync_buffer[1];

  while (proc_20_3_bounds)
  {

    // Kernel call : i193:mm_kernel1
    window_acquire(window_buf225_buf225d,LOCK_20_4_0_0,LOCK_20_4_1_0,buf225_ptr,buf225d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf226_buf226d,LOCK_20_2_2_4096,LOCK_20_2_3_4096,buf226_ptr,buf226d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf224_buf224d,LOCK_20_3_2_4096,LOCK_20_3_3_4096,buf224_ptr,buf224d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf227_buf227d,LOCK_20_3_4_0,LOCK_20_3_5_0,buf227_ptr,buf227d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf225_buf225d),get_input_window_float(window_buf226_buf226d),get_input_window_float(window_buf224_buf224d),get_output_window_float(window_buf227_buf227d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf225_buf225d,LOCK_20_4_0_0,LOCK_20_4_1_0,buf225_ptr,buf225d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf226_buf226d,LOCK_20_2_2_4096,LOCK_20_2_3_4096,buf226_ptr,buf226d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf224_buf224d,LOCK_20_3_2_4096,LOCK_20_3_3_4096,buf224_ptr,buf224d_ptr,0,index, REL_WRITE);
    window_release(window_buf227_buf227d,LOCK_20_3_4_0,LOCK_20_3_5_0,buf227_ptr,buf227d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_3_bounds > 0)
      --proc_20_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}