// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/25_6/src/25_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_25_5_6_0 6
#define LOCK_25_5_7_4096 7
#define LOCK_25_7_0_4096 32
#define LOCK_25_7_1_0 33
#define LOCK_25_5_4_0 4
#define LOCK_25_5_5_4096 5
#define LOCK_25_7_2_4096 34
#define LOCK_25_7_3_4096 35

// Declare shared memory buffers
v4float buf869[256];
v4float buf869d[256];
v4float buf870[256];
v4float buf870d[256];
v4float buf871[256];
v4float buf871d[256];
v4float buf872[256];
v4float buf872d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf870_buf870d[1];
  window_datatype * buf870_ptr = (window_datatype * )buf870;
  window_datatype * buf870d_ptr = (window_datatype * )buf870d;
  window_init(window_buf870_buf870d, 1, buf870, LOCK_25_5_6_0, buf870d, LOCK_25_5_7_4096, 256, 256);
  window_internal window_buf871_buf871d[1];
  window_datatype * buf871_ptr = (window_datatype * )buf871;
  window_datatype * buf871d_ptr = (window_datatype * )buf871d;
  window_init(window_buf871_buf871d, 1, buf871, LOCK_25_7_0_4096, buf871d, LOCK_25_7_1_0, 256, 256);
  window_internal window_buf869_buf869d[1];
  window_datatype * buf869_ptr = (window_datatype * )buf869;
  window_datatype * buf869d_ptr = (window_datatype * )buf869d;
  window_init(window_buf869_buf869d, 1, buf869, LOCK_25_5_4_0, buf869d, LOCK_25_5_5_4096, 256, 256);
  window_internal window_buf872_buf872d[1];
  window_datatype * buf872_ptr = (window_datatype * )buf872;
  window_datatype * buf872d_ptr = (window_datatype * )buf872d;
  window_init(window_buf872_buf872d, 1, buf872, LOCK_25_7_2_4096, buf872d, LOCK_25_7_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_25_6_bounds = sync_buffer[1];

  while (proc_25_6_bounds)
  {

    // Kernel call : i516:mm_kernel1
    window_acquire(window_buf870_buf870d,LOCK_25_5_6_0,LOCK_25_5_7_4096,buf870_ptr,buf870d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf871_buf871d,LOCK_25_7_0_4096,LOCK_25_7_1_0,buf871_ptr,buf871d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf869_buf869d,LOCK_25_5_4_0,LOCK_25_5_5_4096,buf869_ptr,buf869d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf872_buf872d,LOCK_25_7_2_4096,LOCK_25_7_3_4096,buf872_ptr,buf872d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf870_buf870d),get_input_window_float(window_buf871_buf871d),get_input_window_float(window_buf869_buf869d),get_output_window_float(window_buf872_buf872d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf870_buf870d,LOCK_25_5_6_0,LOCK_25_5_7_4096,buf870_ptr,buf870d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf871_buf871d,LOCK_25_7_0_4096,LOCK_25_7_1_0,buf871_ptr,buf871d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf869_buf869d,LOCK_25_5_4_0,LOCK_25_5_5_4096,buf869_ptr,buf869d_ptr,0,index, REL_WRITE);
    window_release(window_buf872_buf872d,LOCK_25_7_2_4096,LOCK_25_7_3_4096,buf872_ptr,buf872d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_25_6_bounds > 0)
      --proc_25_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}