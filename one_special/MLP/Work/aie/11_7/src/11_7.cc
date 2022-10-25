// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/11_7/src/11_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_11_7_0_0 16
#define LOCK_11_7_1_0 17
#define LOCK_11_7_2_4096 18
#define LOCK_11_7_3_4096 19
#define LOCK_11_6_4_4096 4
#define LOCK_11_6_5_4096 5
#define LOCK_11_6_6_0 6
#define LOCK_11_6_7_4096 7

// Declare shared memory buffers
v4float buf1040[256];
v4float buf1040d[256];
v4float buf1041[256];
v4float buf1041d[256];
v4float buf1042[256];
v4float buf1042d[256];
v4float buf1043[256];
v4float buf1043d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf1041_buf1041d[1];
  window_datatype * buf1041_ptr = (window_datatype * )buf1041;
  window_datatype * buf1041d_ptr = (window_datatype * )buf1041d;
  window_init(window_buf1041_buf1041d, 1, buf1041, LOCK_11_7_0_0, buf1041d, LOCK_11_7_1_0, 256, 256);
  window_internal window_buf1042_buf1042d[1];
  window_datatype * buf1042_ptr = (window_datatype * )buf1042;
  window_datatype * buf1042d_ptr = (window_datatype * )buf1042d;
  window_init(window_buf1042_buf1042d, 1, buf1042, LOCK_11_7_2_4096, buf1042d, LOCK_11_7_3_4096, 256, 256);
  window_internal window_buf1040_buf1040d[1];
  window_datatype * buf1040_ptr = (window_datatype * )buf1040;
  window_datatype * buf1040d_ptr = (window_datatype * )buf1040d;
  window_init(window_buf1040_buf1040d, 1, buf1040, LOCK_11_6_4_4096, buf1040d, LOCK_11_6_5_4096, 256, 256);
  window_internal window_buf1043_buf1043d[1];
  window_datatype * buf1043_ptr = (window_datatype * )buf1043;
  window_datatype * buf1043d_ptr = (window_datatype * )buf1043d;
  window_init(window_buf1043_buf1043d, 1, buf1043, LOCK_11_6_6_0, buf1043d, LOCK_11_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_11_7_bounds = sync_buffer[1];

  while (proc_11_7_bounds)
  {

    // Kernel call : i601:mm_kernel1
    window_acquire(window_buf1041_buf1041d,LOCK_11_7_0_0,LOCK_11_7_1_0,buf1041_ptr,buf1041d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1042_buf1042d,LOCK_11_7_2_4096,LOCK_11_7_3_4096,buf1042_ptr,buf1042d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1040_buf1040d,LOCK_11_6_4_4096,LOCK_11_6_5_4096,buf1040_ptr,buf1040d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf1043_buf1043d,LOCK_11_6_6_0,LOCK_11_6_7_4096,buf1043_ptr,buf1043d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf1041_buf1041d),get_input_window_float(window_buf1042_buf1042d),get_input_window_float(window_buf1040_buf1040d),get_output_window_float(window_buf1043_buf1043d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1041_buf1041d,LOCK_11_7_0_0,LOCK_11_7_1_0,buf1041_ptr,buf1041d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1042_buf1042d,LOCK_11_7_2_4096,LOCK_11_7_3_4096,buf1042_ptr,buf1042d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf1040_buf1040d,LOCK_11_6_4_4096,LOCK_11_6_5_4096,buf1040_ptr,buf1040d_ptr,0,index, REL_WRITE);
    window_release(window_buf1043_buf1043d,LOCK_11_6_6_0,LOCK_11_6_7_4096,buf1043_ptr,buf1043d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_11_7_bounds > 0)
      --proc_11_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}