// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_6/src/20_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_6_0_0 48
#define LOCK_20_6_1_0 49
#define LOCK_19_6_0_0 16
#define LOCK_19_6_1_0 17
#define LOCK_20_5_6_4096 6
#define LOCK_20_5_7_4096 7
#define LOCK_20_7_0_0 32
#define LOCK_20_7_1_0 33

// Declare shared memory buffers
v4float buf929[256];
v4float buf929d[256];
v4float buf930[256];
v4float buf930d[256];
v4float buf931[256];
v4float buf931d[256];
v4float buf932[256];
v4float buf932d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf930_buf930d[1];
  window_datatype * buf930_ptr = (window_datatype * )buf930;
  window_datatype * buf930d_ptr = (window_datatype * )buf930d;
  window_init(window_buf930_buf930d, 1, buf930, LOCK_20_6_0_0, buf930d, LOCK_20_6_1_0, 256, 256);
  window_internal window_buf931_buf931d[1];
  window_datatype * buf931_ptr = (window_datatype * )buf931;
  window_datatype * buf931d_ptr = (window_datatype * )buf931d;
  window_init(window_buf931_buf931d, 1, buf931, LOCK_19_6_0_0, buf931d, LOCK_19_6_1_0, 256, 256);
  window_internal window_buf929_buf929d[1];
  window_datatype * buf929_ptr = (window_datatype * )buf929;
  window_datatype * buf929d_ptr = (window_datatype * )buf929d;
  window_init(window_buf929_buf929d, 1, buf929, LOCK_20_5_6_4096, buf929d, LOCK_20_5_7_4096, 256, 256);
  window_internal window_buf932_buf932d[1];
  window_datatype * buf932_ptr = (window_datatype * )buf932;
  window_datatype * buf932d_ptr = (window_datatype * )buf932d;
  window_init(window_buf932_buf932d, 1, buf932, LOCK_20_7_0_0, buf932d, LOCK_20_7_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_6_bounds = sync_buffer[1];

  while (proc_20_6_bounds)
  {

    // Kernel call : i546:mm_kernel1
    window_acquire(window_buf930_buf930d,LOCK_20_6_0_0,LOCK_20_6_1_0,buf930_ptr,buf930d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf931_buf931d,LOCK_19_6_0_0,LOCK_19_6_1_0,buf931_ptr,buf931d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf929_buf929d,LOCK_20_5_6_4096,LOCK_20_5_7_4096,buf929_ptr,buf929d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf932_buf932d,LOCK_20_7_0_0,LOCK_20_7_1_0,buf932_ptr,buf932d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf930_buf930d),get_input_window_float(window_buf931_buf931d),get_input_window_float(window_buf929_buf929d),get_output_window_float(window_buf932_buf932d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf930_buf930d,LOCK_20_6_0_0,LOCK_20_6_1_0,buf930_ptr,buf930d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf931_buf931d,LOCK_19_6_0_0,LOCK_19_6_1_0,buf931_ptr,buf931d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf929_buf929d,LOCK_20_5_6_4096,LOCK_20_5_7_4096,buf929_ptr,buf929d_ptr,0,index, REL_WRITE);
    window_release(window_buf932_buf932d,LOCK_20_7_0_0,LOCK_20_7_1_0,buf932_ptr,buf932d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_6_bounds > 0)
      --proc_20_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}