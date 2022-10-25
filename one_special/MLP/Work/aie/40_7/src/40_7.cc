// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/40_7/src/40_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_41_7_2_4096 50
#define LOCK_41_7_3_4096 51
#define LOCK_40_6_2_4096 2
#define LOCK_40_6_3_4096 3
#define LOCK_40_7_4_0 20
#define LOCK_40_7_5_0 21
#define LOCK_40_7_6_0 22
#define LOCK_40_7_7_4096 23

// Declare shared memory buffers
v4float buf692[256];
v4float buf692d[256];
v4float buf693[256];
v4float buf693d[256];
v4float buf694[256];
v4float buf694d[256];
v4float buf695[256];
v4float buf695d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf693_buf693d[1];
  window_datatype * buf693_ptr = (window_datatype * )buf693;
  window_datatype * buf693d_ptr = (window_datatype * )buf693d;
  window_init(window_buf693_buf693d, 1, buf693, LOCK_41_7_2_4096, buf693d, LOCK_41_7_3_4096, 256, 256);
  window_internal window_buf694_buf694d[1];
  window_datatype * buf694_ptr = (window_datatype * )buf694;
  window_datatype * buf694d_ptr = (window_datatype * )buf694d;
  window_init(window_buf694_buf694d, 1, buf694, LOCK_40_6_2_4096, buf694d, LOCK_40_6_3_4096, 256, 256);
  window_internal window_buf692_buf692d[1];
  window_datatype * buf692_ptr = (window_datatype * )buf692;
  window_datatype * buf692d_ptr = (window_datatype * )buf692d;
  window_init(window_buf692_buf692d, 1, buf692, LOCK_40_7_4_0, buf692d, LOCK_40_7_5_0, 256, 256);
  window_internal window_buf695_buf695d[1];
  window_datatype * buf695_ptr = (window_datatype * )buf695;
  window_datatype * buf695d_ptr = (window_datatype * )buf695d;
  window_init(window_buf695_buf695d, 1, buf695, LOCK_40_7_6_0, buf695d, LOCK_40_7_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_40_7_bounds = sync_buffer[1];

  while (proc_40_7_bounds)
  {

    // Kernel call : i427:mm_kernel1
    window_acquire(window_buf693_buf693d,LOCK_41_7_2_4096,LOCK_41_7_3_4096,buf693_ptr,buf693d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf694_buf694d,LOCK_40_6_2_4096,LOCK_40_6_3_4096,buf694_ptr,buf694d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf692_buf692d,LOCK_40_7_4_0,LOCK_40_7_5_0,buf692_ptr,buf692d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf695_buf695d,LOCK_40_7_6_0,LOCK_40_7_7_4096,buf695_ptr,buf695d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf693_buf693d),get_input_window_float(window_buf694_buf694d),get_input_window_float(window_buf692_buf692d),get_output_window_float(window_buf695_buf695d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf693_buf693d,LOCK_41_7_2_4096,LOCK_41_7_3_4096,buf693_ptr,buf693d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf694_buf694d,LOCK_40_6_2_4096,LOCK_40_6_3_4096,buf694_ptr,buf694d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf692_buf692d,LOCK_40_7_4_0,LOCK_40_7_5_0,buf692_ptr,buf692d_ptr,0,index, REL_WRITE);
    window_release(window_buf695_buf695d,LOCK_40_7_6_0,LOCK_40_7_7_4096,buf695_ptr,buf695d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_40_7_bounds > 0)
      --proc_40_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}