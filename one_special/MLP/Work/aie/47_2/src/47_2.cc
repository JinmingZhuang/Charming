// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/47_2/src/47_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_47_1_4_0 4
#define LOCK_47_1_5_0 5
#define LOCK_47_1_6_4096 6
#define LOCK_47_1_7_4096 7
#define LOCK_47_1_2_4096 2
#define LOCK_47_1_3_0 3
#define LOCK_47_2_2_4096 50
#define LOCK_47_2_3_4096 51

// Declare shared memory buffers
v4float buf545[256];
v4float buf545d[256];
v4float buf546[256];
v4float buf546d[256];
v4float buf547[256];
v4float buf547d[256];
v4float buf548[256];
v4float buf548d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf546_buf546d[1];
  window_datatype * buf546_ptr = (window_datatype * )buf546;
  window_datatype * buf546d_ptr = (window_datatype * )buf546d;
  window_init(window_buf546_buf546d, 1, buf546, LOCK_47_1_4_0, buf546d, LOCK_47_1_5_0, 256, 256);
  window_internal window_buf547_buf547d[1];
  window_datatype * buf547_ptr = (window_datatype * )buf547;
  window_datatype * buf547d_ptr = (window_datatype * )buf547d;
  window_init(window_buf547_buf547d, 1, buf547, LOCK_47_1_6_4096, buf547d, LOCK_47_1_7_4096, 256, 256);
  window_internal window_buf545_buf545d[1];
  window_datatype * buf545_ptr = (window_datatype * )buf545;
  window_datatype * buf545d_ptr = (window_datatype * )buf545d;
  window_init(window_buf545_buf545d, 1, buf545, LOCK_47_1_2_4096, buf545d, LOCK_47_1_3_0, 256, 256);
  window_internal window_buf548_buf548d[1];
  window_datatype * buf548_ptr = (window_datatype * )buf548;
  window_datatype * buf548d_ptr = (window_datatype * )buf548d;
  window_init(window_buf548_buf548d, 1, buf548, LOCK_47_2_2_4096, buf548d, LOCK_47_2_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_47_2_bounds = sync_buffer[1];

  while (proc_47_2_bounds)
  {

    // Kernel call : i354:mm_kernel1
    window_acquire(window_buf546_buf546d,LOCK_47_1_4_0,LOCK_47_1_5_0,buf546_ptr,buf546d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf547_buf547d,LOCK_47_1_6_4096,LOCK_47_1_7_4096,buf547_ptr,buf547d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf545_buf545d,LOCK_47_1_2_4096,LOCK_47_1_3_0,buf545_ptr,buf545d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf548_buf548d,LOCK_47_2_2_4096,LOCK_47_2_3_4096,buf548_ptr,buf548d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf546_buf546d),get_input_window_float(window_buf547_buf547d),get_input_window_float(window_buf545_buf545d),get_output_window_float(window_buf548_buf548d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf546_buf546d,LOCK_47_1_4_0,LOCK_47_1_5_0,buf546_ptr,buf546d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf547_buf547d,LOCK_47_1_6_4096,LOCK_47_1_7_4096,buf547_ptr,buf547d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf545_buf545d,LOCK_47_1_2_4096,LOCK_47_1_3_0,buf545_ptr,buf545d_ptr,0,index, REL_WRITE);
    window_release(window_buf548_buf548d,LOCK_47_2_2_4096,LOCK_47_2_3_4096,buf548_ptr,buf548d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_47_2_bounds > 0)
      --proc_47_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}