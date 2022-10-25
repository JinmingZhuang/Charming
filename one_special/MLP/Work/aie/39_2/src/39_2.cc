// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/39_2/src/39_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_39_2_2_4096 50
#define LOCK_39_2_3_4096 51
#define LOCK_39_1_6_0 6
#define LOCK_39_1_7_4096 7
#define LOCK_39_1_4_4096 4
#define LOCK_39_1_5_4096 5
#define LOCK_39_3_0_0 32
#define LOCK_39_3_1_0 33

// Declare shared memory buffers
v4float buf449[256];
v4float buf449d[256];
v4float buf450[256];
v4float buf450d[256];
v4float buf451[256];
v4float buf451d[256];
v4float buf452[256];
v4float buf452d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf450_buf450d[1];
  window_datatype * buf450_ptr = (window_datatype * )buf450;
  window_datatype * buf450d_ptr = (window_datatype * )buf450d;
  window_init(window_buf450_buf450d, 1, buf450, LOCK_39_2_2_4096, buf450d, LOCK_39_2_3_4096, 256, 256);
  window_internal window_buf451_buf451d[1];
  window_datatype * buf451_ptr = (window_datatype * )buf451;
  window_datatype * buf451d_ptr = (window_datatype * )buf451d;
  window_init(window_buf451_buf451d, 1, buf451, LOCK_39_1_6_0, buf451d, LOCK_39_1_7_4096, 256, 256);
  window_internal window_buf449_buf449d[1];
  window_datatype * buf449_ptr = (window_datatype * )buf449;
  window_datatype * buf449d_ptr = (window_datatype * )buf449d;
  window_init(window_buf449_buf449d, 1, buf449, LOCK_39_1_4_4096, buf449d, LOCK_39_1_5_4096, 256, 256);
  window_internal window_buf452_buf452d[1];
  window_datatype * buf452_ptr = (window_datatype * )buf452;
  window_datatype * buf452d_ptr = (window_datatype * )buf452d;
  window_init(window_buf452_buf452d, 1, buf452, LOCK_39_3_0_0, buf452d, LOCK_39_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_39_2_bounds = sync_buffer[1];

  while (proc_39_2_bounds)
  {

    // Kernel call : i306:mm_kernel1
    window_acquire(window_buf450_buf450d,LOCK_39_2_2_4096,LOCK_39_2_3_4096,buf450_ptr,buf450d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf451_buf451d,LOCK_39_1_6_0,LOCK_39_1_7_4096,buf451_ptr,buf451d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf449_buf449d,LOCK_39_1_4_4096,LOCK_39_1_5_4096,buf449_ptr,buf449d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf452_buf452d,LOCK_39_3_0_0,LOCK_39_3_1_0,buf452_ptr,buf452d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf450_buf450d),get_input_window_float(window_buf451_buf451d),get_input_window_float(window_buf449_buf449d),get_output_window_float(window_buf452_buf452d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf450_buf450d,LOCK_39_2_2_4096,LOCK_39_2_3_4096,buf450_ptr,buf450d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf451_buf451d,LOCK_39_1_6_0,LOCK_39_1_7_4096,buf451_ptr,buf451d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf449_buf449d,LOCK_39_1_4_4096,LOCK_39_1_5_4096,buf449_ptr,buf449d_ptr,0,index, REL_WRITE);
    window_release(window_buf452_buf452d,LOCK_39_3_0_0,LOCK_39_3_1_0,buf452_ptr,buf452d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_39_2_bounds > 0)
      --proc_39_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}