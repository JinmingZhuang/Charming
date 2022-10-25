// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/41_6/src/41_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_41_5_6_0 6
#define LOCK_41_5_7_4096 7
#define LOCK_41_6_2_0 50
#define LOCK_41_6_3_4096 51
#define LOCK_41_5_4_0 4
#define LOCK_41_5_5_4096 5
#define LOCK_41_6_4_4096 52
#define LOCK_41_6_5_4096 53

// Declare shared memory buffers
v4float buf677[256];
v4float buf677d[256];
v4float buf678[256];
v4float buf678d[256];
v4float buf679[256];
v4float buf679d[256];
v4float buf680[256];
v4float buf680d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf678_buf678d[1];
  window_datatype * buf678_ptr = (window_datatype * )buf678;
  window_datatype * buf678d_ptr = (window_datatype * )buf678d;
  window_init(window_buf678_buf678d, 1, buf678, LOCK_41_5_6_0, buf678d, LOCK_41_5_7_4096, 256, 256);
  window_internal window_buf679_buf679d[1];
  window_datatype * buf679_ptr = (window_datatype * )buf679;
  window_datatype * buf679d_ptr = (window_datatype * )buf679d;
  window_init(window_buf679_buf679d, 1, buf679, LOCK_41_6_2_0, buf679d, LOCK_41_6_3_4096, 256, 256);
  window_internal window_buf677_buf677d[1];
  window_datatype * buf677_ptr = (window_datatype * )buf677;
  window_datatype * buf677d_ptr = (window_datatype * )buf677d;
  window_init(window_buf677_buf677d, 1, buf677, LOCK_41_5_4_0, buf677d, LOCK_41_5_5_4096, 256, 256);
  window_internal window_buf680_buf680d[1];
  window_datatype * buf680_ptr = (window_datatype * )buf680;
  window_datatype * buf680d_ptr = (window_datatype * )buf680d;
  window_init(window_buf680_buf680d, 1, buf680, LOCK_41_6_4_4096, buf680d, LOCK_41_6_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_41_6_bounds = sync_buffer[1];

  while (proc_41_6_bounds)
  {

    // Kernel call : i420:mm_kernel1
    window_acquire(window_buf678_buf678d,LOCK_41_5_6_0,LOCK_41_5_7_4096,buf678_ptr,buf678d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf679_buf679d,LOCK_41_6_2_0,LOCK_41_6_3_4096,buf679_ptr,buf679d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf677_buf677d,LOCK_41_5_4_0,LOCK_41_5_5_4096,buf677_ptr,buf677d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf680_buf680d,LOCK_41_6_4_4096,LOCK_41_6_5_4096,buf680_ptr,buf680d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf678_buf678d),get_input_window_float(window_buf679_buf679d),get_input_window_float(window_buf677_buf677d),get_output_window_float(window_buf680_buf680d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf678_buf678d,LOCK_41_5_6_0,LOCK_41_5_7_4096,buf678_ptr,buf678d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf679_buf679d,LOCK_41_6_2_0,LOCK_41_6_3_4096,buf679_ptr,buf679d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf677_buf677d,LOCK_41_5_4_0,LOCK_41_5_5_4096,buf677_ptr,buf677d_ptr,0,index, REL_WRITE);
    window_release(window_buf680_buf680d,LOCK_41_6_4_4096,LOCK_41_6_5_4096,buf680_ptr,buf680d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_41_6_bounds > 0)
      --proc_41_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}