// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/33_5/src/33_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_5_4_4096 20
#define LOCK_33_5_5_0 21
#define LOCK_33_4_2_4096 2
#define LOCK_33_4_3_4096 3
#define LOCK_33_5_2_4096 18
#define LOCK_33_5_3_4096 19
#define LOCK_33_5_6_0 22
#define LOCK_33_5_7_0 23

// Declare shared memory buffers
v4float buf770[256];
v4float buf770d[256];
v4float buf771[256];
v4float buf771d[256];
v4float buf772[256];
v4float buf772d[256];
v4float buf773[256];
v4float buf773d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf771_buf771d[1];
  window_datatype * buf771_ptr = (window_datatype * )buf771;
  window_datatype * buf771d_ptr = (window_datatype * )buf771d;
  window_init(window_buf771_buf771d, 1, buf771, LOCK_33_5_4_4096, buf771d, LOCK_33_5_5_0, 256, 256);
  window_internal window_buf772_buf772d[1];
  window_datatype * buf772_ptr = (window_datatype * )buf772;
  window_datatype * buf772d_ptr = (window_datatype * )buf772d;
  window_init(window_buf772_buf772d, 1, buf772, LOCK_33_4_2_4096, buf772d, LOCK_33_4_3_4096, 256, 256);
  window_internal window_buf770_buf770d[1];
  window_datatype * buf770_ptr = (window_datatype * )buf770;
  window_datatype * buf770d_ptr = (window_datatype * )buf770d;
  window_init(window_buf770_buf770d, 1, buf770, LOCK_33_5_2_4096, buf770d, LOCK_33_5_3_4096, 256, 256);
  window_internal window_buf773_buf773d[1];
  window_datatype * buf773_ptr = (window_datatype * )buf773;
  window_datatype * buf773d_ptr = (window_datatype * )buf773d;
  window_init(window_buf773_buf773d, 1, buf773, LOCK_33_5_6_0, buf773d, LOCK_33_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_33_5_bounds = sync_buffer[1];

  while (proc_33_5_bounds)
  {

    // Kernel call : i467:mm_kernel1
    window_acquire(window_buf771_buf771d,LOCK_33_5_4_4096,LOCK_33_5_5_0,buf771_ptr,buf771d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf772_buf772d,LOCK_33_4_2_4096,LOCK_33_4_3_4096,buf772_ptr,buf772d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf770_buf770d,LOCK_33_5_2_4096,LOCK_33_5_3_4096,buf770_ptr,buf770d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf773_buf773d,LOCK_33_5_6_0,LOCK_33_5_7_0,buf773_ptr,buf773d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf771_buf771d),get_input_window_float(window_buf772_buf772d),get_input_window_float(window_buf770_buf770d),get_output_window_float(window_buf773_buf773d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf771_buf771d,LOCK_33_5_4_4096,LOCK_33_5_5_0,buf771_ptr,buf771d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf772_buf772d,LOCK_33_4_2_4096,LOCK_33_4_3_4096,buf772_ptr,buf772d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf770_buf770d,LOCK_33_5_2_4096,LOCK_33_5_3_4096,buf770_ptr,buf770d_ptr,0,index, REL_WRITE);
    window_release(window_buf773_buf773d,LOCK_33_5_6_0,LOCK_33_5_7_0,buf773_ptr,buf773d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_33_5_bounds > 0)
      --proc_33_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}