// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_0/src/47_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_0_2_4096 18
#define LOCK_46_0_3_4096 19
#define LOCK_47_0_0_0 48
#define LOCK_47_0_1_0 49
#define LOCK_47_1_0_4096 32
#define LOCK_47_1_1_0 33

// Declare shared memory buffers
v4float buf540[256];
v4float buf540d[256];
v4float buf541[256];
v4float buf541d[256];
v4float buf542[256];
v4float buf542d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf540_buf540d[1];
  window_datatype * buf540_ptr = (window_datatype * )buf540;
  window_datatype * buf540d_ptr = (window_datatype * )buf540d;
  window_init(window_buf540_buf540d, 1, buf540, LOCK_46_0_2_4096, buf540d, LOCK_46_0_3_4096, 256, 256);
  window_internal window_buf541_buf541d[1];
  window_datatype * buf541_ptr = (window_datatype * )buf541;
  window_datatype * buf541d_ptr = (window_datatype * )buf541d;
  window_init(window_buf541_buf541d, 1, buf541, LOCK_47_0_0_0, buf541d, LOCK_47_0_1_0, 256, 256);
  window_internal window_buf542_buf542d[1];
  window_datatype * buf542_ptr = (window_datatype * )buf542;
  window_datatype * buf542d_ptr = (window_datatype * )buf542d;
  window_init(window_buf542_buf542d, 1, buf542, LOCK_47_1_0_4096, buf542d, LOCK_47_1_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_0_bounds = sync_buffer[1];

  while (proc_47_0_bounds)
  {

    // Kernel call : i352:mm_kernel0
    window_acquire(window_buf540_buf540d,LOCK_46_0_2_4096,LOCK_46_0_3_4096,buf540_ptr,buf540d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf541_buf541d,LOCK_47_0_0_0,LOCK_47_0_1_0,buf541_ptr,buf541d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf542_buf542d,LOCK_47_1_0_4096,LOCK_47_1_1_0,buf542_ptr,buf542d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf540_buf540d),get_input_window_float(window_buf541_buf541d),get_output_window_float(window_buf542_buf542d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf540_buf540d,LOCK_46_0_2_4096,LOCK_46_0_3_4096,buf540_ptr,buf540d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf541_buf541d,LOCK_47_0_0_0,LOCK_47_0_1_0,buf541_ptr,buf541d_ptr,0,index, REL_WRITE);
    window_release(window_buf542_buf542d,LOCK_47_1_0_4096,LOCK_47_1_1_0,buf542_ptr,buf542d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_0_bounds > 0)
      --proc_47_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}