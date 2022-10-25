// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_1/src/41_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_1_0_0 48
#define LOCK_42_1_1_0 49
#define LOCK_41_1_4_0 20
#define LOCK_41_1_5_0 21
#define LOCK_41_1_2_4096 18
#define LOCK_41_1_3_4096 19
#define LOCK_41_1_6_4096 22
#define LOCK_41_1_7_4096 23

// Declare shared memory buffers
v4float buf470[256];
v4float buf470d[256];
v4float buf471[256];
v4float buf471d[256];
v4float buf472[256];
v4float buf472d[256];
v4float buf473[256];
v4float buf473d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf471_buf471d[1];
  window_datatype * buf471_ptr = (window_datatype * )buf471;
  window_datatype * buf471d_ptr = (window_datatype * )buf471d;
  window_init(window_buf471_buf471d, 1, buf471, LOCK_42_1_0_0, buf471d, LOCK_42_1_1_0, 256, 256);
  window_internal window_buf472_buf472d[1];
  window_datatype * buf472_ptr = (window_datatype * )buf472;
  window_datatype * buf472d_ptr = (window_datatype * )buf472d;
  window_init(window_buf472_buf472d, 1, buf472, LOCK_41_1_4_0, buf472d, LOCK_41_1_5_0, 256, 256);
  window_internal window_buf470_buf470d[1];
  window_datatype * buf470_ptr = (window_datatype * )buf470;
  window_datatype * buf470d_ptr = (window_datatype * )buf470d;
  window_init(window_buf470_buf470d, 1, buf470, LOCK_41_1_2_4096, buf470d, LOCK_41_1_3_4096, 256, 256);
  window_internal window_buf473_buf473d[1];
  window_datatype * buf473_ptr = (window_datatype * )buf473;
  window_datatype * buf473d_ptr = (window_datatype * )buf473d;
  window_init(window_buf473_buf473d, 1, buf473, LOCK_41_1_6_4096, buf473d, LOCK_41_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_1_bounds = sync_buffer[1];

  while (proc_41_1_bounds)
  {

    // Kernel call : i317:mm_kernel1
    window_acquire(window_buf471_buf471d,LOCK_42_1_0_0,LOCK_42_1_1_0,buf471_ptr,buf471d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf472_buf472d,LOCK_41_1_4_0,LOCK_41_1_5_0,buf472_ptr,buf472d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf470_buf470d,LOCK_41_1_2_4096,LOCK_41_1_3_4096,buf470_ptr,buf470d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf473_buf473d,LOCK_41_1_6_4096,LOCK_41_1_7_4096,buf473_ptr,buf473d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf471_buf471d),get_input_window_float(window_buf472_buf472d),get_input_window_float(window_buf470_buf470d),get_output_window_float(window_buf473_buf473d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf471_buf471d,LOCK_42_1_0_0,LOCK_42_1_1_0,buf471_ptr,buf471d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf472_buf472d,LOCK_41_1_4_0,LOCK_41_1_5_0,buf472_ptr,buf472d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf470_buf470d,LOCK_41_1_2_4096,LOCK_41_1_3_4096,buf470_ptr,buf470d_ptr,0,index, REL_WRITE);
    window_release(window_buf473_buf473d,LOCK_41_1_6_4096,LOCK_41_1_7_4096,buf473_ptr,buf473d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_1_bounds > 0)
      --proc_41_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}