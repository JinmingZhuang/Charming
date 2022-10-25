// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_4/src/44_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_43_4_0_0 16
#define LOCK_43_4_1_0 17
#define LOCK_44_3_2_4096 2
#define LOCK_44_3_3_4096 3
#define LOCK_44_5_0_4096 32
#define LOCK_44_5_1_0 33

// Declare shared memory buffers
v4float buf636[256];
v4float buf636d[256];
v4float buf637[256];
v4float buf637d[256];
v4float buf638[256];
v4float buf638d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf636_buf636d[1];
  window_datatype * buf636_ptr = (window_datatype * )buf636;
  window_datatype * buf636d_ptr = (window_datatype * )buf636d;
  window_init(window_buf636_buf636d, 1, buf636, LOCK_43_4_0_0, buf636d, LOCK_43_4_1_0, 256, 256);
  window_internal window_buf637_buf637d[1];
  window_datatype * buf637_ptr = (window_datatype * )buf637;
  window_datatype * buf637d_ptr = (window_datatype * )buf637d;
  window_init(window_buf637_buf637d, 1, buf637, LOCK_44_3_2_4096, buf637d, LOCK_44_3_3_4096, 256, 256);
  window_internal window_buf638_buf638d[1];
  window_datatype * buf638_ptr = (window_datatype * )buf638;
  window_datatype * buf638d_ptr = (window_datatype * )buf638d;
  window_init(window_buf638_buf638d, 1, buf638, LOCK_44_5_0_4096, buf638d, LOCK_44_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_4_bounds = sync_buffer[1];

  while (proc_44_4_bounds)
  {

    // Kernel call : i400:mm_kernel0
    window_acquire(window_buf636_buf636d,LOCK_43_4_0_0,LOCK_43_4_1_0,buf636_ptr,buf636d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf637_buf637d,LOCK_44_3_2_4096,LOCK_44_3_3_4096,buf637_ptr,buf637d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf638_buf638d,LOCK_44_5_0_4096,LOCK_44_5_1_0,buf638_ptr,buf638d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf636_buf636d),get_input_window_float(window_buf637_buf637d),get_output_window_float(window_buf638_buf638d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf636_buf636d,LOCK_43_4_0_0,LOCK_43_4_1_0,buf636_ptr,buf636d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf637_buf637d,LOCK_44_3_2_4096,LOCK_44_3_3_4096,buf637_ptr,buf637d_ptr,0,index, REL_WRITE);
    window_release(window_buf638_buf638d,LOCK_44_5_0_4096,LOCK_44_5_1_0,buf638_ptr,buf638d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_4_bounds > 0)
      --proc_44_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}