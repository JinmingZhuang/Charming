// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/45_2/src/45_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_2_6_4096 22
#define LOCK_44_2_7_4096 23
#define LOCK_45_1_6_0 6
#define LOCK_45_1_7_4096 7
#define LOCK_45_1_4_4096 4
#define LOCK_45_1_5_4096 5
#define LOCK_45_2_4_0 52
#define LOCK_45_2_5_4096 53

// Declare shared memory buffers
v4float buf521[256];
v4float buf521d[256];
v4float buf522[256];
v4float buf522d[256];
v4float buf523[256];
v4float buf523d[256];
v4float buf524[256];
v4float buf524d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf522_buf522d[1];
  window_datatype * buf522_ptr = (window_datatype * )buf522;
  window_datatype * buf522d_ptr = (window_datatype * )buf522d;
  window_init(window_buf522_buf522d, 1, buf522, LOCK_44_2_6_4096, buf522d, LOCK_44_2_7_4096, 256, 256);
  window_internal window_buf523_buf523d[1];
  window_datatype * buf523_ptr = (window_datatype * )buf523;
  window_datatype * buf523d_ptr = (window_datatype * )buf523d;
  window_init(window_buf523_buf523d, 1, buf523, LOCK_45_1_6_0, buf523d, LOCK_45_1_7_4096, 256, 256);
  window_internal window_buf521_buf521d[1];
  window_datatype * buf521_ptr = (window_datatype * )buf521;
  window_datatype * buf521d_ptr = (window_datatype * )buf521d;
  window_init(window_buf521_buf521d, 1, buf521, LOCK_45_1_4_4096, buf521d, LOCK_45_1_5_4096, 256, 256);
  window_internal window_buf524_buf524d[1];
  window_datatype * buf524_ptr = (window_datatype * )buf524;
  window_datatype * buf524d_ptr = (window_datatype * )buf524d;
  window_init(window_buf524_buf524d, 1, buf524, LOCK_45_2_4_0, buf524d, LOCK_45_2_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_45_2_bounds = sync_buffer[1];

  while (proc_45_2_bounds)
  {

    // Kernel call : i342:mm_kernel1
    window_acquire(window_buf522_buf522d,LOCK_44_2_6_4096,LOCK_44_2_7_4096,buf522_ptr,buf522d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf523_buf523d,LOCK_45_1_6_0,LOCK_45_1_7_4096,buf523_ptr,buf523d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf521_buf521d,LOCK_45_1_4_4096,LOCK_45_1_5_4096,buf521_ptr,buf521d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf524_buf524d,LOCK_45_2_4_0,LOCK_45_2_5_4096,buf524_ptr,buf524d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf522_buf522d),get_input_window_float(window_buf523_buf523d),get_input_window_float(window_buf521_buf521d),get_output_window_float(window_buf524_buf524d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf522_buf522d,LOCK_44_2_6_4096,LOCK_44_2_7_4096,buf522_ptr,buf522d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf523_buf523d,LOCK_45_1_6_0,LOCK_45_1_7_4096,buf523_ptr,buf523d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf521_buf521d,LOCK_45_1_4_4096,LOCK_45_1_5_4096,buf521_ptr,buf521d_ptr,0,index, REL_WRITE);
    window_release(window_buf524_buf524d,LOCK_45_2_4_0,LOCK_45_2_5_4096,buf524_ptr,buf524d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_45_2_bounds > 0)
      --proc_45_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}