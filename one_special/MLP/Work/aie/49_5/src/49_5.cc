// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_5/src/49_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_4_2_4096 2
#define LOCK_49_4_3_4096 3
#define LOCK_49_5_4_4096 20
#define LOCK_49_5_5_0 21
#define LOCK_49_5_2_4096 18
#define LOCK_49_5_3_4096 19
#define LOCK_49_5_6_0 22
#define LOCK_49_5_7_0 23

// Declare shared memory buffers
v4float buf578[256];
v4float buf578d[256];
v4float buf579[256];
v4float buf579d[256];
v4float buf580[256];
v4float buf580d[256];
v4float buf581[256];
v4float buf581d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf579_buf579d[1];
  window_datatype * buf579_ptr = (window_datatype * )buf579;
  window_datatype * buf579d_ptr = (window_datatype * )buf579d;
  window_init(window_buf579_buf579d, 1, buf579, LOCK_49_4_2_4096, buf579d, LOCK_49_4_3_4096, 256, 256);
  window_internal window_buf580_buf580d[1];
  window_datatype * buf580_ptr = (window_datatype * )buf580;
  window_datatype * buf580d_ptr = (window_datatype * )buf580d;
  window_init(window_buf580_buf580d, 1, buf580, LOCK_49_5_4_4096, buf580d, LOCK_49_5_5_0, 256, 256);
  window_internal window_buf578_buf578d[1];
  window_datatype * buf578_ptr = (window_datatype * )buf578;
  window_datatype * buf578d_ptr = (window_datatype * )buf578d;
  window_init(window_buf578_buf578d, 1, buf578, LOCK_49_5_2_4096, buf578d, LOCK_49_5_3_4096, 256, 256);
  window_internal window_buf581_buf581d[1];
  window_datatype * buf581_ptr = (window_datatype * )buf581;
  window_datatype * buf581d_ptr = (window_datatype * )buf581d;
  window_init(window_buf581_buf581d, 1, buf581, LOCK_49_5_6_0, buf581d, LOCK_49_5_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_5_bounds = sync_buffer[1];

  while (proc_49_5_bounds)
  {

    // Kernel call : i371:mm_kernel1
    window_acquire(window_buf579_buf579d,LOCK_49_4_2_4096,LOCK_49_4_3_4096,buf579_ptr,buf579d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf580_buf580d,LOCK_49_5_4_4096,LOCK_49_5_5_0,buf580_ptr,buf580d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf578_buf578d,LOCK_49_5_2_4096,LOCK_49_5_3_4096,buf578_ptr,buf578d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf581_buf581d,LOCK_49_5_6_0,LOCK_49_5_7_0,buf581_ptr,buf581d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf579_buf579d),get_input_window_float(window_buf580_buf580d),get_input_window_float(window_buf578_buf578d),get_output_window_float(window_buf581_buf581d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf579_buf579d,LOCK_49_4_2_4096,LOCK_49_4_3_4096,buf579_ptr,buf579d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf580_buf580d,LOCK_49_5_4_4096,LOCK_49_5_5_0,buf580_ptr,buf580d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf578_buf578d,LOCK_49_5_2_4096,LOCK_49_5_3_4096,buf578_ptr,buf578d_ptr,0,index, REL_WRITE);
    window_release(window_buf581_buf581d,LOCK_49_5_6_0,LOCK_49_5_7_0,buf581_ptr,buf581d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_5_bounds > 0)
      --proc_49_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}