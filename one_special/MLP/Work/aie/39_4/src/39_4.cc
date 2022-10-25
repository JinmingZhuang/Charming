// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_4/src/39_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_3_6_4096 6
#define LOCK_39_3_7_0 7
#define LOCK_39_4_2_4096 50
#define LOCK_39_4_3_4096 51
#define LOCK_39_5_0_0 32
#define LOCK_39_5_1_0 33

// Declare shared memory buffers
v4float buf696[256];
v4float buf696d[256];
v4float buf697[256];
v4float buf697d[256];
v4float buf698[256];
v4float buf698d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf696_buf696d[1];
  window_datatype * buf696_ptr = (window_datatype * )buf696;
  window_datatype * buf696d_ptr = (window_datatype * )buf696d;
  window_init(window_buf696_buf696d, 1, buf696, LOCK_39_3_6_4096, buf696d, LOCK_39_3_7_0, 256, 256);
  window_internal window_buf697_buf697d[1];
  window_datatype * buf697_ptr = (window_datatype * )buf697;
  window_datatype * buf697d_ptr = (window_datatype * )buf697d;
  window_init(window_buf697_buf697d, 1, buf697, LOCK_39_4_2_4096, buf697d, LOCK_39_4_3_4096, 256, 256);
  window_internal window_buf698_buf698d[1];
  window_datatype * buf698_ptr = (window_datatype * )buf698;
  window_datatype * buf698d_ptr = (window_datatype * )buf698d;
  window_init(window_buf698_buf698d, 1, buf698, LOCK_39_5_0_0, buf698d, LOCK_39_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_4_bounds = sync_buffer[1];

  while (proc_39_4_bounds)
  {

    // Kernel call : i430:mm_kernel0
    window_acquire(window_buf696_buf696d,LOCK_39_3_6_4096,LOCK_39_3_7_0,buf696_ptr,buf696d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf697_buf697d,LOCK_39_4_2_4096,LOCK_39_4_3_4096,buf697_ptr,buf697d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf698_buf698d,LOCK_39_5_0_0,LOCK_39_5_1_0,buf698_ptr,buf698d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf696_buf696d),get_input_window_float(window_buf697_buf697d),get_output_window_float(window_buf698_buf698d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf696_buf696d,LOCK_39_3_6_4096,LOCK_39_3_7_0,buf696_ptr,buf696d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf697_buf697d,LOCK_39_4_2_4096,LOCK_39_4_3_4096,buf697_ptr,buf697d_ptr,0,index, REL_WRITE);
    window_release(window_buf698_buf698d,LOCK_39_5_0_0,LOCK_39_5_1_0,buf698_ptr,buf698d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_4_bounds > 0)
      --proc_39_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}