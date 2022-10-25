// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/46_5/src/46_5.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_46_4_0_4096 0
#define LOCK_46_4_1_4096 1
#define LOCK_46_4_2_0 2
#define LOCK_46_4_3_0 3
#define LOCK_46_5_4_4096 20
#define LOCK_46_5_5_0 21
#define LOCK_46_5_6_4096 22
#define LOCK_46_5_7_4096 23

// Declare shared memory buffers
v4float buf614[256];
v4float buf614d[256];
v4float buf615[256];
v4float buf615d[256];
v4float buf616[256];
v4float buf616d[256];
v4float buf617[256];
v4float buf617d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf615_buf615d[1];
  window_datatype * buf615_ptr = (window_datatype * )buf615;
  window_datatype * buf615d_ptr = (window_datatype * )buf615d;
  window_init(window_buf615_buf615d, 1, buf615, LOCK_46_4_0_4096, buf615d, LOCK_46_4_1_4096, 256, 256);
  window_internal window_buf616_buf616d[1];
  window_datatype * buf616_ptr = (window_datatype * )buf616;
  window_datatype * buf616d_ptr = (window_datatype * )buf616d;
  window_init(window_buf616_buf616d, 1, buf616, LOCK_46_4_2_0, buf616d, LOCK_46_4_3_0, 256, 256);
  window_internal window_buf614_buf614d[1];
  window_datatype * buf614_ptr = (window_datatype * )buf614;
  window_datatype * buf614d_ptr = (window_datatype * )buf614d;
  window_init(window_buf614_buf614d, 1, buf614, LOCK_46_5_4_4096, buf614d, LOCK_46_5_5_0, 256, 256);
  window_internal window_buf617_buf617d[1];
  window_datatype * buf617_ptr = (window_datatype * )buf617;
  window_datatype * buf617d_ptr = (window_datatype * )buf617d;
  window_init(window_buf617_buf617d, 1, buf617, LOCK_46_5_6_4096, buf617d, LOCK_46_5_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_46_5_bounds = sync_buffer[1];

  while (proc_46_5_bounds)
  {

    // Kernel call : i389:mm_kernel1
    window_acquire(window_buf615_buf615d,LOCK_46_4_0_4096,LOCK_46_4_1_4096,buf615_ptr,buf615d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf616_buf616d,LOCK_46_4_2_0,LOCK_46_4_3_0,buf616_ptr,buf616d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf614_buf614d,LOCK_46_5_4_4096,LOCK_46_5_5_0,buf614_ptr,buf614d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf617_buf617d,LOCK_46_5_6_4096,LOCK_46_5_7_4096,buf617_ptr,buf617d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf615_buf615d),get_input_window_float(window_buf616_buf616d),get_input_window_float(window_buf614_buf614d),get_output_window_float(window_buf617_buf617d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf615_buf615d,LOCK_46_4_0_4096,LOCK_46_4_1_4096,buf615_ptr,buf615d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf616_buf616d,LOCK_46_4_2_0,LOCK_46_4_3_0,buf616_ptr,buf616d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf614_buf614d,LOCK_46_5_4_4096,LOCK_46_5_5_0,buf614_ptr,buf614d_ptr,0,index, REL_WRITE);
    window_release(window_buf617_buf617d,LOCK_46_5_6_4096,LOCK_46_5_7_4096,buf617_ptr,buf617d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_46_5_bounds > 0)
      --proc_46_5_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}