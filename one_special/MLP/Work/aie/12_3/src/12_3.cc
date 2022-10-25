// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/12_3/src/12_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_12_2_2_4096 2
#define LOCK_12_2_3_4096 3
#define LOCK_13_3_0_0 48
#define LOCK_13_3_1_0 49
#define LOCK_12_3_4_0 20
#define LOCK_12_3_5_0 21
#define LOCK_12_3_6_4096 22
#define LOCK_12_3_7_0 23

// Declare shared memory buffers
v4float buf128[256];
v4float buf128d[256];
v4float buf129[256];
v4float buf129d[256];
v4float buf130[256];
v4float buf130d[256];
v4float buf131[256];
v4float buf131d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf129_buf129d[1];
  window_datatype * buf129_ptr = (window_datatype * )buf129;
  window_datatype * buf129d_ptr = (window_datatype * )buf129d;
  window_init(window_buf129_buf129d, 1, buf129, LOCK_12_2_2_4096, buf129d, LOCK_12_2_3_4096, 256, 256);
  window_internal window_buf130_buf130d[1];
  window_datatype * buf130_ptr = (window_datatype * )buf130;
  window_datatype * buf130d_ptr = (window_datatype * )buf130d;
  window_init(window_buf130_buf130d, 1, buf130, LOCK_13_3_0_0, buf130d, LOCK_13_3_1_0, 256, 256);
  window_internal window_buf128_buf128d[1];
  window_datatype * buf128_ptr = (window_datatype * )buf128;
  window_datatype * buf128d_ptr = (window_datatype * )buf128d;
  window_init(window_buf128_buf128d, 1, buf128, LOCK_12_3_4_0, buf128d, LOCK_12_3_5_0, 256, 256);
  window_internal window_buf131_buf131d[1];
  window_datatype * buf131_ptr = (window_datatype * )buf131;
  window_datatype * buf131d_ptr = (window_datatype * )buf131d;
  window_init(window_buf131_buf131d, 1, buf131, LOCK_12_3_6_4096, buf131d, LOCK_12_3_7_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_12_3_bounds = sync_buffer[1];

  while (proc_12_3_bounds)
  {

    // Kernel call : i145:mm_kernel1
    window_acquire(window_buf129_buf129d,LOCK_12_2_2_4096,LOCK_12_2_3_4096,buf129_ptr,buf129d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf130_buf130d,LOCK_13_3_0_0,LOCK_13_3_1_0,buf130_ptr,buf130d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf128_buf128d,LOCK_12_3_4_0,LOCK_12_3_5_0,buf128_ptr,buf128d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf131_buf131d,LOCK_12_3_6_4096,LOCK_12_3_7_0,buf131_ptr,buf131d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf129_buf129d),get_input_window_float(window_buf130_buf130d),get_input_window_float(window_buf128_buf128d),get_output_window_float(window_buf131_buf131d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf129_buf129d,LOCK_12_2_2_4096,LOCK_12_2_3_4096,buf129_ptr,buf129d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf130_buf130d,LOCK_13_3_0_0,LOCK_13_3_1_0,buf130_ptr,buf130d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf128_buf128d,LOCK_12_3_4_0,LOCK_12_3_5_0,buf128_ptr,buf128d_ptr,0,index, REL_WRITE);
    window_release(window_buf131_buf131d,LOCK_12_3_6_4096,LOCK_12_3_7_0,buf131_ptr,buf131d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_12_3_bounds > 0)
      --proc_12_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}