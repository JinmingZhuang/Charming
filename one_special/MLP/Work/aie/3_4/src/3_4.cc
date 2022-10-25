// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/3_4/src/3_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_3_4_2_4096 50
#define LOCK_3_4_3_4096 51
#define LOCK_3_5_0_4096 32
#define LOCK_3_5_1_4096 33
#define LOCK_3_5_2_4096 34
#define LOCK_3_5_3_4096 35

// Declare shared memory buffers
v4float buf1128[256];
v4float buf1128d[256];
v4float buf1129[256];
v4float buf1129d[256];
v4float buf1130[256];
v4float buf1130d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1128_buf1128d[1];
  window_datatype * buf1128_ptr = (window_datatype * )buf1128;
  window_datatype * buf1128d_ptr = (window_datatype * )buf1128d;
  window_init(window_buf1128_buf1128d, 1, buf1128, LOCK_3_4_2_4096, buf1128d, LOCK_3_4_3_4096, 256, 256);
  window_internal window_buf1129_buf1129d[1];
  window_datatype * buf1129_ptr = (window_datatype * )buf1129;
  window_datatype * buf1129d_ptr = (window_datatype * )buf1129d;
  window_init(window_buf1129_buf1129d, 1, buf1129, LOCK_3_5_0_4096, buf1129d, LOCK_3_5_1_4096, 256, 256);
  window_internal window_buf1130_buf1130d[1];
  window_datatype * buf1130_ptr = (window_datatype * )buf1130;
  window_datatype * buf1130d_ptr = (window_datatype * )buf1130d;
  window_init(window_buf1130_buf1130d, 1, buf1130, LOCK_3_5_2_4096, buf1130d, LOCK_3_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_3_4_bounds = sync_buffer[1];

  while (proc_3_4_bounds)
  {

    // Kernel call : i646:mm_kernel0
    window_acquire(window_buf1128_buf1128d,LOCK_3_4_2_4096,LOCK_3_4_3_4096,buf1128_ptr,buf1128d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1129_buf1129d,LOCK_3_5_0_4096,LOCK_3_5_1_4096,buf1129_ptr,buf1129d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1130_buf1130d,LOCK_3_5_2_4096,LOCK_3_5_3_4096,buf1130_ptr,buf1130d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf1128_buf1128d),get_input_window_float(window_buf1129_buf1129d),get_output_window_float(window_buf1130_buf1130d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1128_buf1128d,LOCK_3_4_2_4096,LOCK_3_4_3_4096,buf1128_ptr,buf1128d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1129_buf1129d,LOCK_3_5_0_4096,LOCK_3_5_1_4096,buf1129_ptr,buf1129d_ptr,0,index, REL_WRITE);
    window_release(window_buf1130_buf1130d,LOCK_3_5_2_4096,LOCK_3_5_3_4096,buf1130_ptr,buf1130d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_3_4_bounds > 0)
      --proc_3_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}