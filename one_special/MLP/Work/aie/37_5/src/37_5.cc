// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/37_5/src/37_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_37_5_4_4096 20
#define LOCK_37_5_5_0 21
#define LOCK_38_5_6_4096 54
#define LOCK_38_5_7_4096 55
#define LOCK_37_5_2_4096 18
#define LOCK_37_5_3_4096 19
#define LOCK_37_5_6_0 22
#define LOCK_37_5_7_0 23

// Declare shared memory buffers
v4float buf722[256];
v4float buf722d[256];
v4float buf723[256];
v4float buf723d[256];
v4float buf724[256];
v4float buf724d[256];
v4float buf725[256];
v4float buf725d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf723_buf723d[1];
  window_datatype * buf723_ptr = (window_datatype * )buf723;
  window_datatype * buf723d_ptr = (window_datatype * )buf723d;
  window_init(window_buf723_buf723d, 1, buf723, LOCK_37_5_4_4096, buf723d, LOCK_37_5_5_0, 256, 256);
  window_internal window_buf724_buf724d[1];
  window_datatype * buf724_ptr = (window_datatype * )buf724;
  window_datatype * buf724d_ptr = (window_datatype * )buf724d;
  window_init(window_buf724_buf724d, 1, buf724, LOCK_38_5_6_4096, buf724d, LOCK_38_5_7_4096, 256, 256);
  window_internal window_buf722_buf722d[1];
  window_datatype * buf722_ptr = (window_datatype * )buf722;
  window_datatype * buf722d_ptr = (window_datatype * )buf722d;
  window_init(window_buf722_buf722d, 1, buf722, LOCK_37_5_2_4096, buf722d, LOCK_37_5_3_4096, 256, 256);
  window_internal window_buf725_buf725d[1];
  window_datatype * buf725_ptr = (window_datatype * )buf725;
  window_datatype * buf725d_ptr = (window_datatype * )buf725d;
  window_init(window_buf725_buf725d, 1, buf725, LOCK_37_5_6_0, buf725d, LOCK_37_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_37_5_bounds = sync_buffer[1];

  while (proc_37_5_bounds)
  {

    // Kernel call : i443:mm_kernel1
    window_acquire(window_buf723_buf723d,LOCK_37_5_4_4096,LOCK_37_5_5_0,buf723_ptr,buf723d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf724_buf724d,LOCK_38_5_6_4096,LOCK_38_5_7_4096,buf724_ptr,buf724d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf722_buf722d,LOCK_37_5_2_4096,LOCK_37_5_3_4096,buf722_ptr,buf722d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf725_buf725d,LOCK_37_5_6_0,LOCK_37_5_7_0,buf725_ptr,buf725d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf723_buf723d),get_input_window_float(window_buf724_buf724d),get_input_window_float(window_buf722_buf722d),get_output_window_float(window_buf725_buf725d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf723_buf723d,LOCK_37_5_4_4096,LOCK_37_5_5_0,buf723_ptr,buf723d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf724_buf724d,LOCK_38_5_6_4096,LOCK_38_5_7_4096,buf724_ptr,buf724d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf722_buf722d,LOCK_37_5_2_4096,LOCK_37_5_3_4096,buf722_ptr,buf722d_ptr,0,index, REL_WRITE);
    window_release(window_buf725_buf725d,LOCK_37_5_6_0,LOCK_37_5_7_0,buf725_ptr,buf725d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_37_5_bounds > 0)
      --proc_37_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}