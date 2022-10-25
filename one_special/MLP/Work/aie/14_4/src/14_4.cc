// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/14_4/src/14_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_14_3_6_4096 6
#define LOCK_14_3_7_4096 7
#define LOCK_14_4_0_0 48
#define LOCK_14_4_1_0 49
#define LOCK_14_5_0_0 32
#define LOCK_14_5_1_0 33

// Declare shared memory buffers
v4float buf996[256];
v4float buf996d[256];
v4float buf997[256];
v4float buf997d[256];
v4float buf998[256];
v4float buf998d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf996_buf996d[1];
  window_datatype * buf996_ptr = (window_datatype * )buf996;
  window_datatype * buf996d_ptr = (window_datatype * )buf996d;
  window_init(window_buf996_buf996d, 1, buf996, LOCK_14_3_6_4096, buf996d, LOCK_14_3_7_4096, 256, 256);
  window_internal window_buf997_buf997d[1];
  window_datatype * buf997_ptr = (window_datatype * )buf997;
  window_datatype * buf997d_ptr = (window_datatype * )buf997d;
  window_init(window_buf997_buf997d, 1, buf997, LOCK_14_4_0_0, buf997d, LOCK_14_4_1_0, 256, 256);
  window_internal window_buf998_buf998d[1];
  window_datatype * buf998_ptr = (window_datatype * )buf998;
  window_datatype * buf998d_ptr = (window_datatype * )buf998d;
  window_init(window_buf998_buf998d, 1, buf998, LOCK_14_5_0_0, buf998d, LOCK_14_5_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_14_4_bounds = sync_buffer[1];

  while (proc_14_4_bounds)
  {

    // Kernel call : i580:mm_kernel0
    window_acquire(window_buf996_buf996d,LOCK_14_3_6_4096,LOCK_14_3_7_4096,buf996_ptr,buf996d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf997_buf997d,LOCK_14_4_0_0,LOCK_14_4_1_0,buf997_ptr,buf997d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf998_buf998d,LOCK_14_5_0_0,LOCK_14_5_1_0,buf998_ptr,buf998d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf996_buf996d),get_input_window_float(window_buf997_buf997d),get_output_window_float(window_buf998_buf998d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf996_buf996d,LOCK_14_3_6_4096,LOCK_14_3_7_4096,buf996_ptr,buf996d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf997_buf997d,LOCK_14_4_0_0,LOCK_14_4_1_0,buf997_ptr,buf997d_ptr,0,index, REL_WRITE);
    window_release(window_buf998_buf998d,LOCK_14_5_0_0,LOCK_14_5_1_0,buf998_ptr,buf998d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_14_4_bounds > 0)
      --proc_14_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}