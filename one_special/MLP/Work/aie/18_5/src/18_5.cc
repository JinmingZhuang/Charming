// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/18_5/src/18_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_18_4_2_4096 2
#define LOCK_18_4_3_4096 3
#define LOCK_18_6_2_4096 34
#define LOCK_18_6_3_4096 35
#define LOCK_18_5_2_0 18
#define LOCK_18_5_3_0 19
#define LOCK_18_5_4_4096 20
#define LOCK_18_5_5_4096 21

// Declare shared memory buffers
v4float buf950[256];
v4float buf950d[256];
v4float buf951[256];
v4float buf951d[256];
v4float buf952[256];
v4float buf952d[256];
v4float buf953[256];
v4float buf953d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf951_buf951d[1];
  window_datatype * buf951_ptr = (window_datatype * )buf951;
  window_datatype * buf951d_ptr = (window_datatype * )buf951d;
  window_init(window_buf951_buf951d, 1, buf951, LOCK_18_4_2_4096, buf951d, LOCK_18_4_3_4096, 256, 256);
  window_internal window_buf952_buf952d[1];
  window_datatype * buf952_ptr = (window_datatype * )buf952;
  window_datatype * buf952d_ptr = (window_datatype * )buf952d;
  window_init(window_buf952_buf952d, 1, buf952, LOCK_18_6_2_4096, buf952d, LOCK_18_6_3_4096, 256, 256);
  window_internal window_buf950_buf950d[1];
  window_datatype * buf950_ptr = (window_datatype * )buf950;
  window_datatype * buf950d_ptr = (window_datatype * )buf950d;
  window_init(window_buf950_buf950d, 1, buf950, LOCK_18_5_2_0, buf950d, LOCK_18_5_3_0, 256, 256);
  window_internal window_buf953_buf953d[1];
  window_datatype * buf953_ptr = (window_datatype * )buf953;
  window_datatype * buf953d_ptr = (window_datatype * )buf953d;
  window_init(window_buf953_buf953d, 1, buf953, LOCK_18_5_4_4096, buf953d, LOCK_18_5_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_18_5_bounds = sync_buffer[1];

  while (proc_18_5_bounds)
  {

    // Kernel call : i557:mm_kernel1
    window_acquire(window_buf951_buf951d,LOCK_18_4_2_4096,LOCK_18_4_3_4096,buf951_ptr,buf951d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf952_buf952d,LOCK_18_6_2_4096,LOCK_18_6_3_4096,buf952_ptr,buf952d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf950_buf950d,LOCK_18_5_2_0,LOCK_18_5_3_0,buf950_ptr,buf950d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf953_buf953d,LOCK_18_5_4_4096,LOCK_18_5_5_4096,buf953_ptr,buf953d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf951_buf951d),get_input_window_float(window_buf952_buf952d),get_input_window_float(window_buf950_buf950d),get_output_window_float(window_buf953_buf953d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf951_buf951d,LOCK_18_4_2_4096,LOCK_18_4_3_4096,buf951_ptr,buf951d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf952_buf952d,LOCK_18_6_2_4096,LOCK_18_6_3_4096,buf952_ptr,buf952d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf950_buf950d,LOCK_18_5_2_0,LOCK_18_5_3_0,buf950_ptr,buf950d_ptr,0,index, REL_WRITE);
    window_release(window_buf953_buf953d,LOCK_18_5_4_4096,LOCK_18_5_5_4096,buf953_ptr,buf953d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_18_5_bounds > 0)
      --proc_18_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}