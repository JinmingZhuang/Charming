// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/43_1/src/43_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_1_0_0 48
#define LOCK_44_1_1_0 49
#define LOCK_44_1_2_0 50
#define LOCK_44_1_3_0 51
#define LOCK_43_1_2_4096 18
#define LOCK_43_1_3_0 19
#define LOCK_43_1_4_4096 20
#define LOCK_43_1_5_0 21

// Declare shared memory buffers
v4float buf494[256];
v4float buf494d[256];
v4float buf495[256];
v4float buf495d[256];
v4float buf496[256];
v4float buf496d[256];
v4float buf497[256];
v4float buf497d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf495_buf495d[1];
  window_datatype * buf495_ptr = (window_datatype * )buf495;
  window_datatype * buf495d_ptr = (window_datatype * )buf495d;
  window_init(window_buf495_buf495d, 1, buf495, LOCK_44_1_0_0, buf495d, LOCK_44_1_1_0, 256, 256);
  window_internal window_buf496_buf496d[1];
  window_datatype * buf496_ptr = (window_datatype * )buf496;
  window_datatype * buf496d_ptr = (window_datatype * )buf496d;
  window_init(window_buf496_buf496d, 1, buf496, LOCK_44_1_2_0, buf496d, LOCK_44_1_3_0, 256, 256);
  window_internal window_buf494_buf494d[1];
  window_datatype * buf494_ptr = (window_datatype * )buf494;
  window_datatype * buf494d_ptr = (window_datatype * )buf494d;
  window_init(window_buf494_buf494d, 1, buf494, LOCK_43_1_2_4096, buf494d, LOCK_43_1_3_0, 256, 256);
  window_internal window_buf497_buf497d[1];
  window_datatype * buf497_ptr = (window_datatype * )buf497;
  window_datatype * buf497d_ptr = (window_datatype * )buf497d;
  window_init(window_buf497_buf497d, 1, buf497, LOCK_43_1_4_4096, buf497d, LOCK_43_1_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_43_1_bounds = sync_buffer[1];

  while (proc_43_1_bounds)
  {

    // Kernel call : i329:mm_kernel1
    window_acquire(window_buf495_buf495d,LOCK_44_1_0_0,LOCK_44_1_1_0,buf495_ptr,buf495d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf496_buf496d,LOCK_44_1_2_0,LOCK_44_1_3_0,buf496_ptr,buf496d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf494_buf494d,LOCK_43_1_2_4096,LOCK_43_1_3_0,buf494_ptr,buf494d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf497_buf497d,LOCK_43_1_4_4096,LOCK_43_1_5_0,buf497_ptr,buf497d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf495_buf495d),get_input_window_float(window_buf496_buf496d),get_input_window_float(window_buf494_buf494d),get_output_window_float(window_buf497_buf497d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf495_buf495d,LOCK_44_1_0_0,LOCK_44_1_1_0,buf495_ptr,buf495d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf496_buf496d,LOCK_44_1_2_0,LOCK_44_1_3_0,buf496_ptr,buf496d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf494_buf494d,LOCK_43_1_2_4096,LOCK_43_1_3_0,buf494_ptr,buf494d_ptr,0,index, REL_WRITE);
    window_release(window_buf497_buf497d,LOCK_43_1_4_4096,LOCK_43_1_5_0,buf497_ptr,buf497d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_43_1_bounds > 0)
      --proc_43_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}