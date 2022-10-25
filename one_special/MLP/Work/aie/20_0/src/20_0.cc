// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_0/src/20_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_19_0_2_4096 18
#define LOCK_19_0_3_4096 19
#define LOCK_20_0_0_0 48
#define LOCK_20_0_1_0 49
#define LOCK_20_1_2_4096 34
#define LOCK_20_1_3_4096 35

// Declare shared memory buffers
v4float buf216[256];
v4float buf216d[256];
v4float buf217[256];
v4float buf217d[256];
v4float buf218[256];
v4float buf218d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf216_buf216d[1];
  window_datatype * buf216_ptr = (window_datatype * )buf216;
  window_datatype * buf216d_ptr = (window_datatype * )buf216d;
  window_init(window_buf216_buf216d, 1, buf216, LOCK_19_0_2_4096, buf216d, LOCK_19_0_3_4096, 256, 256);
  window_internal window_buf217_buf217d[1];
  window_datatype * buf217_ptr = (window_datatype * )buf217;
  window_datatype * buf217d_ptr = (window_datatype * )buf217d;
  window_init(window_buf217_buf217d, 1, buf217, LOCK_20_0_0_0, buf217d, LOCK_20_0_1_0, 256, 256);
  window_internal window_buf218_buf218d[1];
  window_datatype * buf218_ptr = (window_datatype * )buf218;
  window_datatype * buf218d_ptr = (window_datatype * )buf218d;
  window_init(window_buf218_buf218d, 1, buf218, LOCK_20_1_2_4096, buf218d, LOCK_20_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_0_bounds = sync_buffer[1];

  while (proc_20_0_bounds)
  {

    // Kernel call : i190:mm_kernel0
    window_acquire(window_buf216_buf216d,LOCK_19_0_2_4096,LOCK_19_0_3_4096,buf216_ptr,buf216d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf217_buf217d,LOCK_20_0_0_0,LOCK_20_0_1_0,buf217_ptr,buf217d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf218_buf218d,LOCK_20_1_2_4096,LOCK_20_1_3_4096,buf218_ptr,buf218d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf216_buf216d),get_input_window_float(window_buf217_buf217d),get_output_window_float(window_buf218_buf218d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf216_buf216d,LOCK_19_0_2_4096,LOCK_19_0_3_4096,buf216_ptr,buf216d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf217_buf217d,LOCK_20_0_0_0,LOCK_20_0_1_0,buf217_ptr,buf217d_ptr,0,index, REL_WRITE);
    window_release(window_buf218_buf218d,LOCK_20_1_2_4096,LOCK_20_1_3_4096,buf218_ptr,buf218d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_0_bounds > 0)
      --proc_20_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}