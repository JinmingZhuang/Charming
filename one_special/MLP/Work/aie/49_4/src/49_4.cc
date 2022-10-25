// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_4/src/49_4.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_5_0_4096 32
#define LOCK_49_5_1_0 33
#define LOCK_49_4_0_0 48
#define LOCK_49_4_1_0 49
#define LOCK_49_5_2_4096 34
#define LOCK_49_5_3_4096 35

// Declare shared memory buffers
v4float buf576[256];
v4float buf576d[256];
v4float buf577[256];
v4float buf577d[256];
v4float buf578[256];
v4float buf578d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf576_buf576d[1];
  window_datatype * buf576_ptr = (window_datatype * )buf576;
  window_datatype * buf576d_ptr = (window_datatype * )buf576d;
  window_init(window_buf576_buf576d, 1, buf576, LOCK_49_5_0_4096, buf576d, LOCK_49_5_1_0, 256, 256);
  window_internal window_buf577_buf577d[1];
  window_datatype * buf577_ptr = (window_datatype * )buf577;
  window_datatype * buf577d_ptr = (window_datatype * )buf577d;
  window_init(window_buf577_buf577d, 1, buf577, LOCK_49_4_0_0, buf577d, LOCK_49_4_1_0, 256, 256);
  window_internal window_buf578_buf578d[1];
  window_datatype * buf578_ptr = (window_datatype * )buf578;
  window_datatype * buf578d_ptr = (window_datatype * )buf578d;
  window_init(window_buf578_buf578d, 1, buf578, LOCK_49_5_2_4096, buf578d, LOCK_49_5_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_4_bounds = sync_buffer[1];

  while (proc_49_4_bounds)
  {

    // Kernel call : i370:mm_kernel0
    window_acquire(window_buf576_buf576d,LOCK_49_5_0_4096,LOCK_49_5_1_0,buf576_ptr,buf576d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf577_buf577d,LOCK_49_4_0_0,LOCK_49_4_1_0,buf577_ptr,buf577d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf578_buf578d,LOCK_49_5_2_4096,LOCK_49_5_3_4096,buf578_ptr,buf578d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf576_buf576d),get_input_window_float(window_buf577_buf577d),get_output_window_float(window_buf578_buf578d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf576_buf576d,LOCK_49_5_0_4096,LOCK_49_5_1_0,buf576_ptr,buf576d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf577_buf577d,LOCK_49_4_0_0,LOCK_49_4_1_0,buf577_ptr,buf577d_ptr,0,index, REL_WRITE);
    window_release(window_buf578_buf578d,LOCK_49_5_2_4096,LOCK_49_5_3_4096,buf578_ptr,buf578d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_4_bounds > 0)
      --proc_49_4_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}