// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/26_1/src/26_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_26_0_2_4096 2
#define LOCK_26_0_3_4096 3
#define LOCK_27_1_0_4096 48
#define LOCK_27_1_1_0 49
#define LOCK_26_1_2_4096 18
#define LOCK_26_1_3_0 19
#define LOCK_26_1_4_0 20
#define LOCK_26_1_5_4096 21

// Declare shared memory buffers
v4float buf290[256];
v4float buf290d[256];
v4float buf291[256];
v4float buf291d[256];
v4float buf292[256];
v4float buf292d[256];
v4float buf293[256];
v4float buf293d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf291_buf291d[1];
  window_datatype * buf291_ptr = (window_datatype * )buf291;
  window_datatype * buf291d_ptr = (window_datatype * )buf291d;
  window_init(window_buf291_buf291d, 1, buf291, LOCK_26_0_2_4096, buf291d, LOCK_26_0_3_4096, 256, 256);
  window_internal window_buf292_buf292d[1];
  window_datatype * buf292_ptr = (window_datatype * )buf292;
  window_datatype * buf292d_ptr = (window_datatype * )buf292d;
  window_init(window_buf292_buf292d, 1, buf292, LOCK_27_1_0_4096, buf292d, LOCK_27_1_1_0, 256, 256);
  window_internal window_buf290_buf290d[1];
  window_datatype * buf290_ptr = (window_datatype * )buf290;
  window_datatype * buf290d_ptr = (window_datatype * )buf290d;
  window_init(window_buf290_buf290d, 1, buf290, LOCK_26_1_2_4096, buf290d, LOCK_26_1_3_0, 256, 256);
  window_internal window_buf293_buf293d[1];
  window_datatype * buf293_ptr = (window_datatype * )buf293;
  window_datatype * buf293d_ptr = (window_datatype * )buf293d;
  window_init(window_buf293_buf293d, 1, buf293, LOCK_26_1_4_0, buf293d, LOCK_26_1_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_26_1_bounds = sync_buffer[1];

  while (proc_26_1_bounds)
  {

    // Kernel call : i227:mm_kernel1
    window_acquire(window_buf291_buf291d,LOCK_26_0_2_4096,LOCK_26_0_3_4096,buf291_ptr,buf291d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf292_buf292d,LOCK_27_1_0_4096,LOCK_27_1_1_0,buf292_ptr,buf292d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf290_buf290d,LOCK_26_1_2_4096,LOCK_26_1_3_0,buf290_ptr,buf290d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf293_buf293d,LOCK_26_1_4_0,LOCK_26_1_5_4096,buf293_ptr,buf293d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf291_buf291d),get_input_window_float(window_buf292_buf292d),get_input_window_float(window_buf290_buf290d),get_output_window_float(window_buf293_buf293d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf291_buf291d,LOCK_26_0_2_4096,LOCK_26_0_3_4096,buf291_ptr,buf291d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf292_buf292d,LOCK_27_1_0_4096,LOCK_27_1_1_0,buf292_ptr,buf292d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf290_buf290d,LOCK_26_1_2_4096,LOCK_26_1_3_0,buf290_ptr,buf290d_ptr,0,index, REL_WRITE);
    window_release(window_buf293_buf293d,LOCK_26_1_4_0,LOCK_26_1_5_4096,buf293_ptr,buf293d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_26_1_bounds > 0)
      --proc_26_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}