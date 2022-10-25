// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_5/src/25_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_6_0_0 32
#define LOCK_25_6_1_0 33
#define LOCK_25_6_2_4096 34
#define LOCK_25_6_3_4096 35
#define LOCK_25_5_2_0 18
#define LOCK_25_5_3_4096 19
#define LOCK_25_5_4_0 20
#define LOCK_25_5_5_4096 21

// Declare shared memory buffers
v4float buf866[256];
v4float buf866d[256];
v4float buf867[256];
v4float buf867d[256];
v4float buf868[256];
v4float buf868d[256];
v4float buf869[256];
v4float buf869d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf867_buf867d[1];
  window_datatype * buf867_ptr = (window_datatype * )buf867;
  window_datatype * buf867d_ptr = (window_datatype * )buf867d;
  window_init(window_buf867_buf867d, 1, buf867, LOCK_25_6_0_0, buf867d, LOCK_25_6_1_0, 256, 256);
  window_internal window_buf868_buf868d[1];
  window_datatype * buf868_ptr = (window_datatype * )buf868;
  window_datatype * buf868d_ptr = (window_datatype * )buf868d;
  window_init(window_buf868_buf868d, 1, buf868, LOCK_25_6_2_4096, buf868d, LOCK_25_6_3_4096, 256, 256);
  window_internal window_buf866_buf866d[1];
  window_datatype * buf866_ptr = (window_datatype * )buf866;
  window_datatype * buf866d_ptr = (window_datatype * )buf866d;
  window_init(window_buf866_buf866d, 1, buf866, LOCK_25_5_2_0, buf866d, LOCK_25_5_3_4096, 256, 256);
  window_internal window_buf869_buf869d[1];
  window_datatype * buf869_ptr = (window_datatype * )buf869;
  window_datatype * buf869d_ptr = (window_datatype * )buf869d;
  window_init(window_buf869_buf869d, 1, buf869, LOCK_25_5_4_0, buf869d, LOCK_25_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_5_bounds = sync_buffer[1];

  while (proc_25_5_bounds)
  {

    // Kernel call : i515:mm_kernel1
    window_acquire(window_buf867_buf867d,LOCK_25_6_0_0,LOCK_25_6_1_0,buf867_ptr,buf867d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf868_buf868d,LOCK_25_6_2_4096,LOCK_25_6_3_4096,buf868_ptr,buf868d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf866_buf866d,LOCK_25_5_2_0,LOCK_25_5_3_4096,buf866_ptr,buf866d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf869_buf869d,LOCK_25_5_4_0,LOCK_25_5_5_4096,buf869_ptr,buf869d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf867_buf867d),get_input_window_float(window_buf868_buf868d),get_input_window_float(window_buf866_buf866d),get_output_window_float(window_buf869_buf869d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf867_buf867d,LOCK_25_6_0_0,LOCK_25_6_1_0,buf867_ptr,buf867d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf868_buf868d,LOCK_25_6_2_4096,LOCK_25_6_3_4096,buf868_ptr,buf868d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf866_buf866d,LOCK_25_5_2_0,LOCK_25_5_3_4096,buf866_ptr,buf866d_ptr,0,index, REL_WRITE);
    window_release(window_buf869_buf869d,LOCK_25_5_4_0,LOCK_25_5_5_4096,buf869_ptr,buf869d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_5_bounds > 0)
      --proc_25_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}