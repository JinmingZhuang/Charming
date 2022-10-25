// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_3/src/44_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_4_0_0 32
#define LOCK_44_4_1_0 33
#define LOCK_44_3_0_0 16
#define LOCK_44_3_1_0 17
#define LOCK_44_2_2_0 2
#define LOCK_44_2_3_0 3
#define LOCK_44_2_4_0 4
#define LOCK_44_2_5_0 5

// Declare shared memory buffers
v4float buf512[256];
v4float buf512d[256];
v4float buf513[256];
v4float buf513d[256];
v4float buf514[256];
v4float buf514d[256];
v4float buf515[256];
v4float buf515d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf513_buf513d[1];
  window_datatype * buf513_ptr = (window_datatype * )buf513;
  window_datatype * buf513d_ptr = (window_datatype * )buf513d;
  window_init(window_buf513_buf513d, 1, buf513, LOCK_44_4_0_0, buf513d, LOCK_44_4_1_0, 256, 256);
  window_internal window_buf514_buf514d[1];
  window_datatype * buf514_ptr = (window_datatype * )buf514;
  window_datatype * buf514d_ptr = (window_datatype * )buf514d;
  window_init(window_buf514_buf514d, 1, buf514, LOCK_44_3_0_0, buf514d, LOCK_44_3_1_0, 256, 256);
  window_internal window_buf512_buf512d[1];
  window_datatype * buf512_ptr = (window_datatype * )buf512;
  window_datatype * buf512d_ptr = (window_datatype * )buf512d;
  window_init(window_buf512_buf512d, 1, buf512, LOCK_44_2_2_0, buf512d, LOCK_44_2_3_0, 256, 256);
  window_internal window_buf515_buf515d[1];
  window_datatype * buf515_ptr = (window_datatype * )buf515;
  window_datatype * buf515d_ptr = (window_datatype * )buf515d;
  window_init(window_buf515_buf515d, 1, buf515, LOCK_44_2_4_0, buf515d, LOCK_44_2_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_3_bounds = sync_buffer[1];

  while (proc_44_3_bounds)
  {

    // Kernel call : i337:mm_kernel1
    window_acquire(window_buf513_buf513d,LOCK_44_4_0_0,LOCK_44_4_1_0,buf513_ptr,buf513d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf514_buf514d,LOCK_44_3_0_0,LOCK_44_3_1_0,buf514_ptr,buf514d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf512_buf512d,LOCK_44_2_2_0,LOCK_44_2_3_0,buf512_ptr,buf512d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf515_buf515d,LOCK_44_2_4_0,LOCK_44_2_5_0,buf515_ptr,buf515d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf513_buf513d),get_input_window_float(window_buf514_buf514d),get_input_window_float(window_buf512_buf512d),get_output_window_float(window_buf515_buf515d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf513_buf513d,LOCK_44_4_0_0,LOCK_44_4_1_0,buf513_ptr,buf513d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf514_buf514d,LOCK_44_3_0_0,LOCK_44_3_1_0,buf514_ptr,buf514d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf512_buf512d,LOCK_44_2_2_0,LOCK_44_2_3_0,buf512_ptr,buf512d_ptr,0,index, REL_WRITE);
    window_release(window_buf515_buf515d,LOCK_44_2_4_0,LOCK_44_2_5_0,buf515_ptr,buf515d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_3_bounds > 0)
      --proc_44_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}