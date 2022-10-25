// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/24_0/src/24_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_24_0_0_0 48
#define LOCK_24_0_1_0 49
#define LOCK_24_0_2_4096 50
#define LOCK_24_0_3_4096 51
#define LOCK_24_1_0_0 32
#define LOCK_24_1_1_4096 33

// Declare shared memory buffers
v4float buf264[256];
v4float buf264d[256];
v4float buf265[256];
v4float buf265d[256];
v4float buf266[256];
v4float buf266d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf264_buf264d[1];
  window_datatype * buf264_ptr = (window_datatype * )buf264;
  window_datatype * buf264d_ptr = (window_datatype * )buf264d;
  window_init(window_buf264_buf264d, 1, buf264, LOCK_24_0_0_0, buf264d, LOCK_24_0_1_0, 256, 256);
  window_internal window_buf265_buf265d[1];
  window_datatype * buf265_ptr = (window_datatype * )buf265;
  window_datatype * buf265d_ptr = (window_datatype * )buf265d;
  window_init(window_buf265_buf265d, 1, buf265, LOCK_24_0_2_4096, buf265d, LOCK_24_0_3_4096, 256, 256);
  window_internal window_buf266_buf266d[1];
  window_datatype * buf266_ptr = (window_datatype * )buf266;
  window_datatype * buf266d_ptr = (window_datatype * )buf266d;
  window_init(window_buf266_buf266d, 1, buf266, LOCK_24_1_0_0, buf266d, LOCK_24_1_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_24_0_bounds = sync_buffer[1];

  while (proc_24_0_bounds)
  {

    // Kernel call : i214:mm_kernel0
    window_acquire(window_buf264_buf264d,LOCK_24_0_0_0,LOCK_24_0_1_0,buf264_ptr,buf264d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf265_buf265d,LOCK_24_0_2_4096,LOCK_24_0_3_4096,buf265_ptr,buf265d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf266_buf266d,LOCK_24_1_0_0,LOCK_24_1_1_4096,buf266_ptr,buf266d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf264_buf264d),get_input_window_float(window_buf265_buf265d),get_output_window_float(window_buf266_buf266d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf264_buf264d,LOCK_24_0_0_0,LOCK_24_0_1_0,buf264_ptr,buf264d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf265_buf265d,LOCK_24_0_2_4096,LOCK_24_0_3_4096,buf265_ptr,buf265d_ptr,0,index, REL_WRITE);
    window_release(window_buf266_buf266d,LOCK_24_1_0_0,LOCK_24_1_1_4096,buf266_ptr,buf266d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_24_0_bounds > 0)
      --proc_24_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}