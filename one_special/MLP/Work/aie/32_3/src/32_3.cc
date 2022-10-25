// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/32_3/src/32_3.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_33_3_0_0 48
#define LOCK_33_3_1_0 49
#define LOCK_32_4_0_0 32
#define LOCK_32_4_1_0 33
#define LOCK_32_2_4_4096 4
#define LOCK_32_2_5_0 5
#define LOCK_32_2_6_4096 6
#define LOCK_32_2_7_4096 7

// Declare shared memory buffers
v4float buf368[256];
v4float buf368d[256];
v4float buf369[256];
v4float buf369d[256];
v4float buf370[256];
v4float buf370d[256];
v4float buf371[256];
v4float buf371d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf369_buf369d[1];
  window_datatype * buf369_ptr = (window_datatype * )buf369;
  window_datatype * buf369d_ptr = (window_datatype * )buf369d;
  window_init(window_buf369_buf369d, 1, buf369, LOCK_33_3_0_0, buf369d, LOCK_33_3_1_0, 256, 256);
  window_internal window_buf370_buf370d[1];
  window_datatype * buf370_ptr = (window_datatype * )buf370;
  window_datatype * buf370d_ptr = (window_datatype * )buf370d;
  window_init(window_buf370_buf370d, 1, buf370, LOCK_32_4_0_0, buf370d, LOCK_32_4_1_0, 256, 256);
  window_internal window_buf368_buf368d[1];
  window_datatype * buf368_ptr = (window_datatype * )buf368;
  window_datatype * buf368d_ptr = (window_datatype * )buf368d;
  window_init(window_buf368_buf368d, 1, buf368, LOCK_32_2_4_4096, buf368d, LOCK_32_2_5_0, 256, 256);
  window_internal window_buf371_buf371d[1];
  window_datatype * buf371_ptr = (window_datatype * )buf371;
  window_datatype * buf371d_ptr = (window_datatype * )buf371d;
  window_init(window_buf371_buf371d, 1, buf371, LOCK_32_2_6_4096, buf371d, LOCK_32_2_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_32_3_bounds = sync_buffer[1];

  while (proc_32_3_bounds)
  {

    // Kernel call : i265:mm_kernel1
    window_acquire(window_buf369_buf369d,LOCK_33_3_0_0,LOCK_33_3_1_0,buf369_ptr,buf369d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf370_buf370d,LOCK_32_4_0_0,LOCK_32_4_1_0,buf370_ptr,buf370d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf368_buf368d,LOCK_32_2_4_4096,LOCK_32_2_5_0,buf368_ptr,buf368d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf371_buf371d,LOCK_32_2_6_4096,LOCK_32_2_7_4096,buf371_ptr,buf371d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf369_buf369d),get_input_window_float(window_buf370_buf370d),get_input_window_float(window_buf368_buf368d),get_output_window_float(window_buf371_buf371d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf369_buf369d,LOCK_33_3_0_0,LOCK_33_3_1_0,buf369_ptr,buf369d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf370_buf370d,LOCK_32_4_0_0,LOCK_32_4_1_0,buf370_ptr,buf370d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf368_buf368d,LOCK_32_2_4_4096,LOCK_32_2_5_0,buf368_ptr,buf368d_ptr,0,index, REL_WRITE);
    window_release(window_buf371_buf371d,LOCK_32_2_6_4096,LOCK_32_2_7_4096,buf371_ptr,buf371d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_32_3_bounds > 0)
      --proc_32_3_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}