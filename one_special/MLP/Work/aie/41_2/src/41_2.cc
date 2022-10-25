// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_2/src/41_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_41_2_0_4096 48
#define LOCK_41_2_1_0 49
#define LOCK_41_3_0_0 32
#define LOCK_41_3_1_0 33
#define LOCK_41_1_6_4096 6
#define LOCK_41_1_7_4096 7
#define LOCK_41_2_2_0 50
#define LOCK_41_2_3_4096 51

// Declare shared memory buffers
v4float buf473[256];
v4float buf473d[256];
v4float buf474[256];
v4float buf474d[256];
v4float buf475[256];
v4float buf475d[256];
v4float buf476[256];
v4float buf476d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf474_buf474d[1];
  window_datatype * buf474_ptr = (window_datatype * )buf474;
  window_datatype * buf474d_ptr = (window_datatype * )buf474d;
  window_init(window_buf474_buf474d, 1, buf474, LOCK_41_2_0_4096, buf474d, LOCK_41_2_1_0, 256, 256);
  window_internal window_buf475_buf475d[1];
  window_datatype * buf475_ptr = (window_datatype * )buf475;
  window_datatype * buf475d_ptr = (window_datatype * )buf475d;
  window_init(window_buf475_buf475d, 1, buf475, LOCK_41_3_0_0, buf475d, LOCK_41_3_1_0, 256, 256);
  window_internal window_buf473_buf473d[1];
  window_datatype * buf473_ptr = (window_datatype * )buf473;
  window_datatype * buf473d_ptr = (window_datatype * )buf473d;
  window_init(window_buf473_buf473d, 1, buf473, LOCK_41_1_6_4096, buf473d, LOCK_41_1_7_4096, 256, 256);
  window_internal window_buf476_buf476d[1];
  window_datatype * buf476_ptr = (window_datatype * )buf476;
  window_datatype * buf476d_ptr = (window_datatype * )buf476d;
  window_init(window_buf476_buf476d, 1, buf476, LOCK_41_2_2_0, buf476d, LOCK_41_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_2_bounds = sync_buffer[1];

  while (proc_41_2_bounds)
  {

    // Kernel call : i318:mm_kernel1
    window_acquire(window_buf474_buf474d,LOCK_41_2_0_4096,LOCK_41_2_1_0,buf474_ptr,buf474d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf475_buf475d,LOCK_41_3_0_0,LOCK_41_3_1_0,buf475_ptr,buf475d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf473_buf473d,LOCK_41_1_6_4096,LOCK_41_1_7_4096,buf473_ptr,buf473d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf476_buf476d,LOCK_41_2_2_0,LOCK_41_2_3_4096,buf476_ptr,buf476d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf474_buf474d),get_input_window_float(window_buf475_buf475d),get_input_window_float(window_buf473_buf473d),get_output_window_float(window_buf476_buf476d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf474_buf474d,LOCK_41_2_0_4096,LOCK_41_2_1_0,buf474_ptr,buf474d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf475_buf475d,LOCK_41_3_0_0,LOCK_41_3_1_0,buf475_ptr,buf475d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf473_buf473d,LOCK_41_1_6_4096,LOCK_41_1_7_4096,buf473_ptr,buf473d_ptr,0,index, REL_WRITE);
    window_release(window_buf476_buf476d,LOCK_41_2_2_0,LOCK_41_2_3_4096,buf476_ptr,buf476d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_2_bounds > 0)
      --proc_41_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}