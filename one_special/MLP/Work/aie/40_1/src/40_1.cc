// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_1/src/40_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_40_1_4_0 20
#define LOCK_40_1_5_0 21
#define LOCK_41_1_0_0 48
#define LOCK_41_1_1_0 49
#define LOCK_40_1_2_4096 18
#define LOCK_40_1_3_4096 19
#define LOCK_40_1_6_0 22
#define LOCK_40_1_7_0 23

// Declare shared memory buffers
v4float buf458[256];
v4float buf458d[256];
v4float buf459[256];
v4float buf459d[256];
v4float buf460[256];
v4float buf460d[256];
v4float buf461[256];
v4float buf461d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf459_buf459d[1];
  window_datatype * buf459_ptr = (window_datatype * )buf459;
  window_datatype * buf459d_ptr = (window_datatype * )buf459d;
  window_init(window_buf459_buf459d, 1, buf459, LOCK_40_1_4_0, buf459d, LOCK_40_1_5_0, 256, 256);
  window_internal window_buf460_buf460d[1];
  window_datatype * buf460_ptr = (window_datatype * )buf460;
  window_datatype * buf460d_ptr = (window_datatype * )buf460d;
  window_init(window_buf460_buf460d, 1, buf460, LOCK_41_1_0_0, buf460d, LOCK_41_1_1_0, 256, 256);
  window_internal window_buf458_buf458d[1];
  window_datatype * buf458_ptr = (window_datatype * )buf458;
  window_datatype * buf458d_ptr = (window_datatype * )buf458d;
  window_init(window_buf458_buf458d, 1, buf458, LOCK_40_1_2_4096, buf458d, LOCK_40_1_3_4096, 256, 256);
  window_internal window_buf461_buf461d[1];
  window_datatype * buf461_ptr = (window_datatype * )buf461;
  window_datatype * buf461d_ptr = (window_datatype * )buf461d;
  window_init(window_buf461_buf461d, 1, buf461, LOCK_40_1_6_0, buf461d, LOCK_40_1_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_1_bounds = sync_buffer[1];

  while (proc_40_1_bounds)
  {

    // Kernel call : i311:mm_kernel1
    window_acquire(window_buf459_buf459d,LOCK_40_1_4_0,LOCK_40_1_5_0,buf459_ptr,buf459d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf460_buf460d,LOCK_41_1_0_0,LOCK_41_1_1_0,buf460_ptr,buf460d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf458_buf458d,LOCK_40_1_2_4096,LOCK_40_1_3_4096,buf458_ptr,buf458d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf461_buf461d,LOCK_40_1_6_0,LOCK_40_1_7_0,buf461_ptr,buf461d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf459_buf459d),get_input_window_float(window_buf460_buf460d),get_input_window_float(window_buf458_buf458d),get_output_window_float(window_buf461_buf461d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf459_buf459d,LOCK_40_1_4_0,LOCK_40_1_5_0,buf459_ptr,buf459d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf460_buf460d,LOCK_41_1_0_0,LOCK_41_1_1_0,buf460_ptr,buf460d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf458_buf458d,LOCK_40_1_2_4096,LOCK_40_1_3_4096,buf458_ptr,buf458d_ptr,0,index, REL_WRITE);
    window_release(window_buf461_buf461d,LOCK_40_1_6_0,LOCK_40_1_7_0,buf461_ptr,buf461d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_1_bounds > 0)
      --proc_40_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}