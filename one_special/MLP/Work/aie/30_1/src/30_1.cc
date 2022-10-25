// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/30_1/src/30_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_30_0_2_4096 2
#define LOCK_30_0_3_4096 3
#define LOCK_30_1_4_0 20
#define LOCK_30_1_5_0 21
#define LOCK_30_1_2_4096 18
#define LOCK_30_1_3_4096 19
#define LOCK_30_1_6_4096 22
#define LOCK_30_1_7_4096 23

// Declare shared memory buffers
v4float buf338[256];
v4float buf338d[256];
v4float buf339[256];
v4float buf339d[256];
v4float buf340[256];
v4float buf340d[256];
v4float buf341[256];
v4float buf341d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf339_buf339d[1];
  window_datatype * buf339_ptr = (window_datatype * )buf339;
  window_datatype * buf339d_ptr = (window_datatype * )buf339d;
  window_init(window_buf339_buf339d, 1, buf339, LOCK_30_0_2_4096, buf339d, LOCK_30_0_3_4096, 256, 256);
  window_internal window_buf340_buf340d[1];
  window_datatype * buf340_ptr = (window_datatype * )buf340;
  window_datatype * buf340d_ptr = (window_datatype * )buf340d;
  window_init(window_buf340_buf340d, 1, buf340, LOCK_30_1_4_0, buf340d, LOCK_30_1_5_0, 256, 256);
  window_internal window_buf338_buf338d[1];
  window_datatype * buf338_ptr = (window_datatype * )buf338;
  window_datatype * buf338d_ptr = (window_datatype * )buf338d;
  window_init(window_buf338_buf338d, 1, buf338, LOCK_30_1_2_4096, buf338d, LOCK_30_1_3_4096, 256, 256);
  window_internal window_buf341_buf341d[1];
  window_datatype * buf341_ptr = (window_datatype * )buf341;
  window_datatype * buf341d_ptr = (window_datatype * )buf341d;
  window_init(window_buf341_buf341d, 1, buf341, LOCK_30_1_6_4096, buf341d, LOCK_30_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_30_1_bounds = sync_buffer[1];

  while (proc_30_1_bounds)
  {

    // Kernel call : i251:mm_kernel1
    window_acquire(window_buf339_buf339d,LOCK_30_0_2_4096,LOCK_30_0_3_4096,buf339_ptr,buf339d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf340_buf340d,LOCK_30_1_4_0,LOCK_30_1_5_0,buf340_ptr,buf340d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf338_buf338d,LOCK_30_1_2_4096,LOCK_30_1_3_4096,buf338_ptr,buf338d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf341_buf341d,LOCK_30_1_6_4096,LOCK_30_1_7_4096,buf341_ptr,buf341d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf339_buf339d),get_input_window_float(window_buf340_buf340d),get_input_window_float(window_buf338_buf338d),get_output_window_float(window_buf341_buf341d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf339_buf339d,LOCK_30_0_2_4096,LOCK_30_0_3_4096,buf339_ptr,buf339d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf340_buf340d,LOCK_30_1_4_0,LOCK_30_1_5_0,buf340_ptr,buf340d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf338_buf338d,LOCK_30_1_2_4096,LOCK_30_1_3_4096,buf338_ptr,buf338d_ptr,0,index, REL_WRITE);
    window_release(window_buf341_buf341d,LOCK_30_1_6_4096,LOCK_30_1_7_4096,buf341_ptr,buf341d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_30_1_bounds > 0)
      --proc_30_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}