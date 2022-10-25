// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/15_5/src/15_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_15_4_2_4096 2
#define LOCK_15_4_3_4096 3
#define LOCK_15_5_2_4096 18
#define LOCK_15_5_3_0 19
#define LOCK_15_5_0_4096 16
#define LOCK_15_5_1_4096 17
#define LOCK_15_5_4_4096 20
#define LOCK_15_5_5_0 21

// Declare shared memory buffers
v4float buf986[256];
v4float buf986d[256];
v4float buf987[256];
v4float buf987d[256];
v4float buf988[256];
v4float buf988d[256];
v4float buf989[256];
v4float buf989d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf987_buf987d[1];
  window_datatype * buf987_ptr = (window_datatype * )buf987;
  window_datatype * buf987d_ptr = (window_datatype * )buf987d;
  window_init(window_buf987_buf987d, 1, buf987, LOCK_15_4_2_4096, buf987d, LOCK_15_4_3_4096, 256, 256);
  window_internal window_buf988_buf988d[1];
  window_datatype * buf988_ptr = (window_datatype * )buf988;
  window_datatype * buf988d_ptr = (window_datatype * )buf988d;
  window_init(window_buf988_buf988d, 1, buf988, LOCK_15_5_2_4096, buf988d, LOCK_15_5_3_0, 256, 256);
  window_internal window_buf986_buf986d[1];
  window_datatype * buf986_ptr = (window_datatype * )buf986;
  window_datatype * buf986d_ptr = (window_datatype * )buf986d;
  window_init(window_buf986_buf986d, 1, buf986, LOCK_15_5_0_4096, buf986d, LOCK_15_5_1_4096, 256, 256);
  window_internal window_buf989_buf989d[1];
  window_datatype * buf989_ptr = (window_datatype * )buf989;
  window_datatype * buf989d_ptr = (window_datatype * )buf989d;
  window_init(window_buf989_buf989d, 1, buf989, LOCK_15_5_4_4096, buf989d, LOCK_15_5_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_15_5_bounds = sync_buffer[1];

  while (proc_15_5_bounds)
  {

    // Kernel call : i575:mm_kernel1
    window_acquire(window_buf987_buf987d,LOCK_15_4_2_4096,LOCK_15_4_3_4096,buf987_ptr,buf987d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf988_buf988d,LOCK_15_5_2_4096,LOCK_15_5_3_0,buf988_ptr,buf988d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf986_buf986d,LOCK_15_5_0_4096,LOCK_15_5_1_4096,buf986_ptr,buf986d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf989_buf989d,LOCK_15_5_4_4096,LOCK_15_5_5_0,buf989_ptr,buf989d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf987_buf987d),get_input_window_float(window_buf988_buf988d),get_input_window_float(window_buf986_buf986d),get_output_window_float(window_buf989_buf989d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf987_buf987d,LOCK_15_4_2_4096,LOCK_15_4_3_4096,buf987_ptr,buf987d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf988_buf988d,LOCK_15_5_2_4096,LOCK_15_5_3_0,buf988_ptr,buf988d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf986_buf986d,LOCK_15_5_0_4096,LOCK_15_5_1_4096,buf986_ptr,buf986d_ptr,0,index, REL_WRITE);
    window_release(window_buf989_buf989d,LOCK_15_5_4_4096,LOCK_15_5_5_0,buf989_ptr,buf989d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_15_5_bounds > 0)
      --proc_15_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}