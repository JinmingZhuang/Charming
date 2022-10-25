// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/8_3/src/8_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_8_2_4_4096 4
#define LOCK_8_2_5_4096 5
#define LOCK_8_4_0_0 32
#define LOCK_8_4_1_0 33
#define LOCK_8_2_2_4096 2
#define LOCK_8_2_3_4096 3
#define LOCK_8_2_6_0 6
#define LOCK_8_2_7_0 7

// Declare shared memory buffers
v4float buf80[256];
v4float buf80d[256];
v4float buf81[256];
v4float buf81d[256];
v4float buf82[256];
v4float buf82d[256];
v4float buf83[256];
v4float buf83d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf81_buf81d[1];
  window_datatype * buf81_ptr = (window_datatype * )buf81;
  window_datatype * buf81d_ptr = (window_datatype * )buf81d;
  window_init(window_buf81_buf81d, 1, buf81, LOCK_8_2_4_4096, buf81d, LOCK_8_2_5_4096, 256, 256);
  window_internal window_buf82_buf82d[1];
  window_datatype * buf82_ptr = (window_datatype * )buf82;
  window_datatype * buf82d_ptr = (window_datatype * )buf82d;
  window_init(window_buf82_buf82d, 1, buf82, LOCK_8_4_0_0, buf82d, LOCK_8_4_1_0, 256, 256);
  window_internal window_buf80_buf80d[1];
  window_datatype * buf80_ptr = (window_datatype * )buf80;
  window_datatype * buf80d_ptr = (window_datatype * )buf80d;
  window_init(window_buf80_buf80d, 1, buf80, LOCK_8_2_2_4096, buf80d, LOCK_8_2_3_4096, 256, 256);
  window_internal window_buf83_buf83d[1];
  window_datatype * buf83_ptr = (window_datatype * )buf83;
  window_datatype * buf83d_ptr = (window_datatype * )buf83d;
  window_init(window_buf83_buf83d, 1, buf83, LOCK_8_2_6_0, buf83d, LOCK_8_2_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_8_3_bounds = sync_buffer[1];

  while (proc_8_3_bounds)
  {

    // Kernel call : i121:mm_kernel1
    window_acquire(window_buf81_buf81d,LOCK_8_2_4_4096,LOCK_8_2_5_4096,buf81_ptr,buf81d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf82_buf82d,LOCK_8_4_0_0,LOCK_8_4_1_0,buf82_ptr,buf82d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf80_buf80d,LOCK_8_2_2_4096,LOCK_8_2_3_4096,buf80_ptr,buf80d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf83_buf83d,LOCK_8_2_6_0,LOCK_8_2_7_0,buf83_ptr,buf83d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf81_buf81d),get_input_window_float(window_buf82_buf82d),get_input_window_float(window_buf80_buf80d),get_output_window_float(window_buf83_buf83d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf81_buf81d,LOCK_8_2_4_4096,LOCK_8_2_5_4096,buf81_ptr,buf81d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf82_buf82d,LOCK_8_4_0_0,LOCK_8_4_1_0,buf82_ptr,buf82d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf80_buf80d,LOCK_8_2_2_4096,LOCK_8_2_3_4096,buf80_ptr,buf80d_ptr,0,index, REL_WRITE);
    window_release(window_buf83_buf83d,LOCK_8_2_6_0,LOCK_8_2_7_0,buf83_ptr,buf83d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_8_3_bounds > 0)
      --proc_8_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}