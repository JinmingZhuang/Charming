// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/38_6/src/38_6.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_38_5_4_0 4
#define LOCK_38_5_5_4096 5
#define LOCK_37_6_0_0 16
#define LOCK_37_6_1_0 17
#define LOCK_38_5_2_0 2
#define LOCK_38_5_3_0 3
#define LOCK_38_6_2_4096 50
#define LOCK_38_6_3_4096 51

// Declare shared memory buffers
v4float buf713[256];
v4float buf713d[256];
v4float buf714[256];
v4float buf714d[256];
v4float buf715[256];
v4float buf715d[256];
v4float buf716[256];
v4float buf716d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf714_buf714d[1];
  window_datatype * buf714_ptr = (window_datatype * )buf714;
  window_datatype * buf714d_ptr = (window_datatype * )buf714d;
  window_init(window_buf714_buf714d, 1, buf714, LOCK_38_5_4_0, buf714d, LOCK_38_5_5_4096, 256, 256);
  window_internal window_buf715_buf715d[1];
  window_datatype * buf715_ptr = (window_datatype * )buf715;
  window_datatype * buf715d_ptr = (window_datatype * )buf715d;
  window_init(window_buf715_buf715d, 1, buf715, LOCK_37_6_0_0, buf715d, LOCK_37_6_1_0, 256, 256);
  window_internal window_buf713_buf713d[1];
  window_datatype * buf713_ptr = (window_datatype * )buf713;
  window_datatype * buf713d_ptr = (window_datatype * )buf713d;
  window_init(window_buf713_buf713d, 1, buf713, LOCK_38_5_2_0, buf713d, LOCK_38_5_3_0, 256, 256);
  window_internal window_buf716_buf716d[1];
  window_datatype * buf716_ptr = (window_datatype * )buf716;
  window_datatype * buf716d_ptr = (window_datatype * )buf716d;
  window_init(window_buf716_buf716d, 1, buf716, LOCK_38_6_2_4096, buf716d, LOCK_38_6_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_38_6_bounds = sync_buffer[1];

  while (proc_38_6_bounds)
  {

    // Kernel call : i438:mm_kernel1
    window_acquire(window_buf714_buf714d,LOCK_38_5_4_0,LOCK_38_5_5_4096,buf714_ptr,buf714d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf715_buf715d,LOCK_37_6_0_0,LOCK_37_6_1_0,buf715_ptr,buf715d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf713_buf713d,LOCK_38_5_2_0,LOCK_38_5_3_0,buf713_ptr,buf713d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf716_buf716d,LOCK_38_6_2_4096,LOCK_38_6_3_4096,buf716_ptr,buf716d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf714_buf714d),get_input_window_float(window_buf715_buf715d),get_input_window_float(window_buf713_buf713d),get_output_window_float(window_buf716_buf716d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf714_buf714d,LOCK_38_5_4_0,LOCK_38_5_5_4096,buf714_ptr,buf714d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf715_buf715d,LOCK_37_6_0_0,LOCK_37_6_1_0,buf715_ptr,buf715d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf713_buf713d,LOCK_38_5_2_0,LOCK_38_5_3_0,buf713_ptr,buf713d_ptr,0,index, REL_WRITE);
    window_release(window_buf716_buf716d,LOCK_38_6_2_4096,LOCK_38_6_3_4096,buf716_ptr,buf716d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_38_6_bounds > 0)
      --proc_38_6_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}