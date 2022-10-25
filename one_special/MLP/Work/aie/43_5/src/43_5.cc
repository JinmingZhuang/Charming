// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_5/src/43_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_6_0_0 32
#define LOCK_43_6_1_0 33
#define LOCK_44_5_6_4096 54
#define LOCK_44_5_7_0 55
#define LOCK_43_5_2_4096 18
#define LOCK_43_5_3_4096 19
#define LOCK_43_5_4_0 20
#define LOCK_43_5_5_0 21

// Declare shared memory buffers
v4float buf650[256];
v4float buf650d[256];
v4float buf651[256];
v4float buf651d[256];
v4float buf652[256];
v4float buf652d[256];
v4float buf653[256];
v4float buf653d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf651_buf651d[1];
  window_datatype * buf651_ptr = (window_datatype * )buf651;
  window_datatype * buf651d_ptr = (window_datatype * )buf651d;
  window_init(window_buf651_buf651d, 1, buf651, LOCK_43_6_0_0, buf651d, LOCK_43_6_1_0, 256, 256);
  window_internal window_buf652_buf652d[1];
  window_datatype * buf652_ptr = (window_datatype * )buf652;
  window_datatype * buf652d_ptr = (window_datatype * )buf652d;
  window_init(window_buf652_buf652d, 1, buf652, LOCK_44_5_6_4096, buf652d, LOCK_44_5_7_0, 256, 256);
  window_internal window_buf650_buf650d[1];
  window_datatype * buf650_ptr = (window_datatype * )buf650;
  window_datatype * buf650d_ptr = (window_datatype * )buf650d;
  window_init(window_buf650_buf650d, 1, buf650, LOCK_43_5_2_4096, buf650d, LOCK_43_5_3_4096, 256, 256);
  window_internal window_buf653_buf653d[1];
  window_datatype * buf653_ptr = (window_datatype * )buf653;
  window_datatype * buf653d_ptr = (window_datatype * )buf653d;
  window_init(window_buf653_buf653d, 1, buf653, LOCK_43_5_4_0, buf653d, LOCK_43_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_5_bounds = sync_buffer[1];

  while (proc_43_5_bounds)
  {

    // Kernel call : i407:mm_kernel1
    window_acquire(window_buf651_buf651d,LOCK_43_6_0_0,LOCK_43_6_1_0,buf651_ptr,buf651d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf652_buf652d,LOCK_44_5_6_4096,LOCK_44_5_7_0,buf652_ptr,buf652d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf650_buf650d,LOCK_43_5_2_4096,LOCK_43_5_3_4096,buf650_ptr,buf650d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf653_buf653d,LOCK_43_5_4_0,LOCK_43_5_5_0,buf653_ptr,buf653d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf651_buf651d),get_input_window_float(window_buf652_buf652d),get_input_window_float(window_buf650_buf650d),get_output_window_float(window_buf653_buf653d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf651_buf651d,LOCK_43_6_0_0,LOCK_43_6_1_0,buf651_ptr,buf651d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf652_buf652d,LOCK_44_5_6_4096,LOCK_44_5_7_0,buf652_ptr,buf652d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf650_buf650d,LOCK_43_5_2_4096,LOCK_43_5_3_4096,buf650_ptr,buf650d_ptr,0,index, REL_WRITE);
    window_release(window_buf653_buf653d,LOCK_43_5_4_0,LOCK_43_5_5_0,buf653_ptr,buf653d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_5_bounds > 0)
      --proc_43_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}