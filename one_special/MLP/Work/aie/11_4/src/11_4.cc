// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_4/src/11_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_4_0_0 48
#define LOCK_11_4_1_0 49
#define LOCK_11_4_2_4096 50
#define LOCK_11_4_3_4096 51
#define LOCK_11_5_0_0 32
#define LOCK_11_5_1_4096 33

// Declare shared memory buffers
v4float buf1032[256];
v4float buf1032d[256];
v4float buf1033[256];
v4float buf1033d[256];
v4float buf1034[256];
v4float buf1034d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1032_buf1032d[1];
  window_datatype * buf1032_ptr = (window_datatype * )buf1032;
  window_datatype * buf1032d_ptr = (window_datatype * )buf1032d;
  window_init(window_buf1032_buf1032d, 1, buf1032, LOCK_11_4_0_0, buf1032d, LOCK_11_4_1_0, 256, 256);
  window_internal window_buf1033_buf1033d[1];
  window_datatype * buf1033_ptr = (window_datatype * )buf1033;
  window_datatype * buf1033d_ptr = (window_datatype * )buf1033d;
  window_init(window_buf1033_buf1033d, 1, buf1033, LOCK_11_4_2_4096, buf1033d, LOCK_11_4_3_4096, 256, 256);
  window_internal window_buf1034_buf1034d[1];
  window_datatype * buf1034_ptr = (window_datatype * )buf1034;
  window_datatype * buf1034d_ptr = (window_datatype * )buf1034d;
  window_init(window_buf1034_buf1034d, 1, buf1034, LOCK_11_5_0_0, buf1034d, LOCK_11_5_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_4_bounds = sync_buffer[1];

  while (proc_11_4_bounds)
  {

    // Kernel call : i598:mm_kernel0
    window_acquire(window_buf1032_buf1032d,LOCK_11_4_0_0,LOCK_11_4_1_0,buf1032_ptr,buf1032d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1033_buf1033d,LOCK_11_4_2_4096,LOCK_11_4_3_4096,buf1033_ptr,buf1033d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1034_buf1034d,LOCK_11_5_0_0,LOCK_11_5_1_4096,buf1034_ptr,buf1034d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1032_buf1032d),get_input_window_float(window_buf1033_buf1033d),get_output_window_float(window_buf1034_buf1034d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1032_buf1032d,LOCK_11_4_0_0,LOCK_11_4_1_0,buf1032_ptr,buf1032d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1033_buf1033d,LOCK_11_4_2_4096,LOCK_11_4_3_4096,buf1033_ptr,buf1033d_ptr,0,index, REL_WRITE);
    window_release(window_buf1034_buf1034d,LOCK_11_5_0_0,LOCK_11_5_1_4096,buf1034_ptr,buf1034d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_4_bounds > 0)
      --proc_11_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}