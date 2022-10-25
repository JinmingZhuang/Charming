// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_0/src/33_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_0_0_0 48
#define LOCK_33_0_1_0 49
#define LOCK_32_0_2_4096 18
#define LOCK_32_0_3_4096 19
#define LOCK_33_1_0_0 32
#define LOCK_33_1_1_4096 33

// Declare shared memory buffers
v4float buf372[256];
v4float buf372d[256];
v4float buf373[256];
v4float buf373d[256];
v4float buf374[256];
v4float buf374d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf372_buf372d[1];
  window_datatype * buf372_ptr = (window_datatype * )buf372;
  window_datatype * buf372d_ptr = (window_datatype * )buf372d;
  window_init(window_buf372_buf372d, 1, buf372, LOCK_33_0_0_0, buf372d, LOCK_33_0_1_0, 256, 256);
  window_internal window_buf373_buf373d[1];
  window_datatype * buf373_ptr = (window_datatype * )buf373;
  window_datatype * buf373d_ptr = (window_datatype * )buf373d;
  window_init(window_buf373_buf373d, 1, buf373, LOCK_32_0_2_4096, buf373d, LOCK_32_0_3_4096, 256, 256);
  window_internal window_buf374_buf374d[1];
  window_datatype * buf374_ptr = (window_datatype * )buf374;
  window_datatype * buf374d_ptr = (window_datatype * )buf374d;
  window_init(window_buf374_buf374d, 1, buf374, LOCK_33_1_0_0, buf374d, LOCK_33_1_1_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_0_bounds = sync_buffer[1];

  while (proc_33_0_bounds)
  {

    // Kernel call : i268:mm_kernel0
    window_acquire(window_buf372_buf372d,LOCK_33_0_0_0,LOCK_33_0_1_0,buf372_ptr,buf372d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf373_buf373d,LOCK_32_0_2_4096,LOCK_32_0_3_4096,buf373_ptr,buf373d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf374_buf374d,LOCK_33_1_0_0,LOCK_33_1_1_4096,buf374_ptr,buf374d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf372_buf372d),get_input_window_float(window_buf373_buf373d),get_output_window_float(window_buf374_buf374d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf372_buf372d,LOCK_33_0_0_0,LOCK_33_0_1_0,buf372_ptr,buf372d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf373_buf373d,LOCK_32_0_2_4096,LOCK_32_0_3_4096,buf373_ptr,buf373d_ptr,0,index, REL_WRITE);
    window_release(window_buf374_buf374d,LOCK_33_1_0_0,LOCK_33_1_1_4096,buf374_ptr,buf374d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_0_bounds > 0)
      --proc_33_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}