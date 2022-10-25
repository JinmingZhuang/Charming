// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_5/src/20_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_5_2_4096 18
#define LOCK_20_5_3_4096 19
#define LOCK_20_5_4_0 20
#define LOCK_20_5_5_0 21
#define LOCK_20_5_0_0 16
#define LOCK_20_5_1_0 17
#define LOCK_20_5_6_4096 22
#define LOCK_20_5_7_4096 23

// Declare shared memory buffers
v4float buf926[256];
v4float buf926d[256];
v4float buf927[256];
v4float buf927d[256];
v4float buf928[256];
v4float buf928d[256];
v4float buf929[256];
v4float buf929d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf927_buf927d[1];
  window_datatype * buf927_ptr = (window_datatype * )buf927;
  window_datatype * buf927d_ptr = (window_datatype * )buf927d;
  window_init(window_buf927_buf927d, 1, buf927, LOCK_20_5_2_4096, buf927d, LOCK_20_5_3_4096, 256, 256);
  window_internal window_buf928_buf928d[1];
  window_datatype * buf928_ptr = (window_datatype * )buf928;
  window_datatype * buf928d_ptr = (window_datatype * )buf928d;
  window_init(window_buf928_buf928d, 1, buf928, LOCK_20_5_4_0, buf928d, LOCK_20_5_5_0, 256, 256);
  window_internal window_buf926_buf926d[1];
  window_datatype * buf926_ptr = (window_datatype * )buf926;
  window_datatype * buf926d_ptr = (window_datatype * )buf926d;
  window_init(window_buf926_buf926d, 1, buf926, LOCK_20_5_0_0, buf926d, LOCK_20_5_1_0, 256, 256);
  window_internal window_buf929_buf929d[1];
  window_datatype * buf929_ptr = (window_datatype * )buf929;
  window_datatype * buf929d_ptr = (window_datatype * )buf929d;
  window_init(window_buf929_buf929d, 1, buf929, LOCK_20_5_6_4096, buf929d, LOCK_20_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_5_bounds = sync_buffer[1];

  while (proc_20_5_bounds)
  {

    // Kernel call : i545:mm_kernel1
    window_acquire(window_buf927_buf927d,LOCK_20_5_2_4096,LOCK_20_5_3_4096,buf927_ptr,buf927d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf928_buf928d,LOCK_20_5_4_0,LOCK_20_5_5_0,buf928_ptr,buf928d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf926_buf926d,LOCK_20_5_0_0,LOCK_20_5_1_0,buf926_ptr,buf926d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf929_buf929d,LOCK_20_5_6_4096,LOCK_20_5_7_4096,buf929_ptr,buf929d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf927_buf927d),get_input_window_float(window_buf928_buf928d),get_input_window_float(window_buf926_buf926d),get_output_window_float(window_buf929_buf929d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf927_buf927d,LOCK_20_5_2_4096,LOCK_20_5_3_4096,buf927_ptr,buf927d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf928_buf928d,LOCK_20_5_4_0,LOCK_20_5_5_0,buf928_ptr,buf928d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf926_buf926d,LOCK_20_5_0_0,LOCK_20_5_1_0,buf926_ptr,buf926d_ptr,0,index, REL_WRITE);
    window_release(window_buf929_buf929d,LOCK_20_5_6_4096,LOCK_20_5_7_4096,buf929_ptr,buf929d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_5_bounds > 0)
      --proc_20_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}