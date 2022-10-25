// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/19_5/src/19_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_19_4_2_4096 2
#define LOCK_19_4_3_4096 3
#define LOCK_19_6_2_4096 34
#define LOCK_19_6_3_4096 35
#define LOCK_19_5_2_0 18
#define LOCK_19_5_3_0 19
#define LOCK_19_5_4_0 20
#define LOCK_19_5_5_4096 21

// Declare shared memory buffers
v4float buf938[256];
v4float buf938d[256];
v4float buf939[256];
v4float buf939d[256];
v4float buf940[256];
v4float buf940d[256];
v4float buf941[256];
v4float buf941d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf939_buf939d[1];
  window_datatype * buf939_ptr = (window_datatype * )buf939;
  window_datatype * buf939d_ptr = (window_datatype * )buf939d;
  window_init(window_buf939_buf939d, 1, buf939, LOCK_19_4_2_4096, buf939d, LOCK_19_4_3_4096, 256, 256);
  window_internal window_buf940_buf940d[1];
  window_datatype * buf940_ptr = (window_datatype * )buf940;
  window_datatype * buf940d_ptr = (window_datatype * )buf940d;
  window_init(window_buf940_buf940d, 1, buf940, LOCK_19_6_2_4096, buf940d, LOCK_19_6_3_4096, 256, 256);
  window_internal window_buf938_buf938d[1];
  window_datatype * buf938_ptr = (window_datatype * )buf938;
  window_datatype * buf938d_ptr = (window_datatype * )buf938d;
  window_init(window_buf938_buf938d, 1, buf938, LOCK_19_5_2_0, buf938d, LOCK_19_5_3_0, 256, 256);
  window_internal window_buf941_buf941d[1];
  window_datatype * buf941_ptr = (window_datatype * )buf941;
  window_datatype * buf941d_ptr = (window_datatype * )buf941d;
  window_init(window_buf941_buf941d, 1, buf941, LOCK_19_5_4_0, buf941d, LOCK_19_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_19_5_bounds = sync_buffer[1];

  while (proc_19_5_bounds)
  {

    // Kernel call : i551:mm_kernel1
    window_acquire(window_buf939_buf939d,LOCK_19_4_2_4096,LOCK_19_4_3_4096,buf939_ptr,buf939d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf940_buf940d,LOCK_19_6_2_4096,LOCK_19_6_3_4096,buf940_ptr,buf940d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf938_buf938d,LOCK_19_5_2_0,LOCK_19_5_3_0,buf938_ptr,buf938d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf941_buf941d,LOCK_19_5_4_0,LOCK_19_5_5_4096,buf941_ptr,buf941d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf939_buf939d),get_input_window_float(window_buf940_buf940d),get_input_window_float(window_buf938_buf938d),get_output_window_float(window_buf941_buf941d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf939_buf939d,LOCK_19_4_2_4096,LOCK_19_4_3_4096,buf939_ptr,buf939d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf940_buf940d,LOCK_19_6_2_4096,LOCK_19_6_3_4096,buf940_ptr,buf940d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf938_buf938d,LOCK_19_5_2_0,LOCK_19_5_3_0,buf938_ptr,buf938d_ptr,0,index, REL_WRITE);
    window_release(window_buf941_buf941d,LOCK_19_5_4_0,LOCK_19_5_5_4096,buf941_ptr,buf941d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_19_5_bounds > 0)
      --proc_19_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}