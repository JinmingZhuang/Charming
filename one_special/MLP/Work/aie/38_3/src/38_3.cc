// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_3/src/38_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_2_2_4096 2
#define LOCK_38_2_3_4096 3
#define LOCK_38_4_0_0 32
#define LOCK_38_4_1_0 33
#define LOCK_38_3_0_0 16
#define LOCK_38_3_1_0 17
#define LOCK_38_3_2_4096 18
#define LOCK_38_3_3_4096 19

// Declare shared memory buffers
v4float buf440[256];
v4float buf440d[256];
v4float buf441[256];
v4float buf441d[256];
v4float buf442[256];
v4float buf442d[256];
v4float buf443[256];
v4float buf443d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf441_buf441d[1];
  window_datatype * buf441_ptr = (window_datatype * )buf441;
  window_datatype * buf441d_ptr = (window_datatype * )buf441d;
  window_init(window_buf441_buf441d, 1, buf441, LOCK_38_2_2_4096, buf441d, LOCK_38_2_3_4096, 256, 256);
  window_internal window_buf442_buf442d[1];
  window_datatype * buf442_ptr = (window_datatype * )buf442;
  window_datatype * buf442d_ptr = (window_datatype * )buf442d;
  window_init(window_buf442_buf442d, 1, buf442, LOCK_38_4_0_0, buf442d, LOCK_38_4_1_0, 256, 256);
  window_internal window_buf440_buf440d[1];
  window_datatype * buf440_ptr = (window_datatype * )buf440;
  window_datatype * buf440d_ptr = (window_datatype * )buf440d;
  window_init(window_buf440_buf440d, 1, buf440, LOCK_38_3_0_0, buf440d, LOCK_38_3_1_0, 256, 256);
  window_internal window_buf443_buf443d[1];
  window_datatype * buf443_ptr = (window_datatype * )buf443;
  window_datatype * buf443d_ptr = (window_datatype * )buf443d;
  window_init(window_buf443_buf443d, 1, buf443, LOCK_38_3_2_4096, buf443d, LOCK_38_3_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_3_bounds = sync_buffer[1];

  while (proc_38_3_bounds)
  {

    // Kernel call : i301:mm_kernel1
    window_acquire(window_buf441_buf441d,LOCK_38_2_2_4096,LOCK_38_2_3_4096,buf441_ptr,buf441d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf442_buf442d,LOCK_38_4_0_0,LOCK_38_4_1_0,buf442_ptr,buf442d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf440_buf440d,LOCK_38_3_0_0,LOCK_38_3_1_0,buf440_ptr,buf440d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf443_buf443d,LOCK_38_3_2_4096,LOCK_38_3_3_4096,buf443_ptr,buf443d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf441_buf441d),get_input_window_float(window_buf442_buf442d),get_input_window_float(window_buf440_buf440d),get_output_window_float(window_buf443_buf443d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf441_buf441d,LOCK_38_2_2_4096,LOCK_38_2_3_4096,buf441_ptr,buf441d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf442_buf442d,LOCK_38_4_0_0,LOCK_38_4_1_0,buf442_ptr,buf442d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf440_buf440d,LOCK_38_3_0_0,LOCK_38_3_1_0,buf440_ptr,buf440d_ptr,0,index, REL_WRITE);
    window_release(window_buf443_buf443d,LOCK_38_3_2_4096,LOCK_38_3_3_4096,buf443_ptr,buf443d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_3_bounds > 0)
      --proc_38_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}