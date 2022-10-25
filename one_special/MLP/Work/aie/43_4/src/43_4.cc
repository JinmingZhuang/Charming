// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_4/src/43_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_4_2_4096 50
#define LOCK_43_4_3_4096 51
#define LOCK_43_5_0_4096 32
#define LOCK_43_5_1_4096 33
#define LOCK_43_5_2_4096 34
#define LOCK_43_5_3_4096 35

// Declare shared memory buffers
v4float buf648[256];
v4float buf648d[256];
v4float buf649[256];
v4float buf649d[256];
v4float buf650[256];
v4float buf650d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf648_buf648d[1];
  window_datatype * buf648_ptr = (window_datatype * )buf648;
  window_datatype * buf648d_ptr = (window_datatype * )buf648d;
  window_init(window_buf648_buf648d, 1, buf648, LOCK_43_4_2_4096, buf648d, LOCK_43_4_3_4096, 256, 256);
  window_internal window_buf649_buf649d[1];
  window_datatype * buf649_ptr = (window_datatype * )buf649;
  window_datatype * buf649d_ptr = (window_datatype * )buf649d;
  window_init(window_buf649_buf649d, 1, buf649, LOCK_43_5_0_4096, buf649d, LOCK_43_5_1_4096, 256, 256);
  window_internal window_buf650_buf650d[1];
  window_datatype * buf650_ptr = (window_datatype * )buf650;
  window_datatype * buf650d_ptr = (window_datatype * )buf650d;
  window_init(window_buf650_buf650d, 1, buf650, LOCK_43_5_2_4096, buf650d, LOCK_43_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_4_bounds = sync_buffer[1];

  while (proc_43_4_bounds)
  {

    // Kernel call : i406:mm_kernel0
    window_acquire(window_buf648_buf648d,LOCK_43_4_2_4096,LOCK_43_4_3_4096,buf648_ptr,buf648d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf649_buf649d,LOCK_43_5_0_4096,LOCK_43_5_1_4096,buf649_ptr,buf649d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf650_buf650d,LOCK_43_5_2_4096,LOCK_43_5_3_4096,buf650_ptr,buf650d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf648_buf648d),get_input_window_float(window_buf649_buf649d),get_output_window_float(window_buf650_buf650d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf648_buf648d,LOCK_43_4_2_4096,LOCK_43_4_3_4096,buf648_ptr,buf648d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf649_buf649d,LOCK_43_5_0_4096,LOCK_43_5_1_4096,buf649_ptr,buf649d_ptr,0,index, REL_WRITE);
    window_release(window_buf650_buf650d,LOCK_43_5_2_4096,LOCK_43_5_3_4096,buf650_ptr,buf650d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_4_bounds > 0)
      --proc_43_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}