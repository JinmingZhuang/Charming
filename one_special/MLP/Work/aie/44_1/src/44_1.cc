// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_1/src/44_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_0_2_4096 2
#define LOCK_44_0_3_4096 3
#define LOCK_45_1_0_0 48
#define LOCK_45_1_1_0 49
#define LOCK_44_1_4_4096 20
#define LOCK_44_1_5_4096 21
#define LOCK_44_1_6_4096 22
#define LOCK_44_1_7_4096 23

// Declare shared memory buffers
v4float buf506[256];
v4float buf506d[256];
v4float buf507[256];
v4float buf507d[256];
v4float buf508[256];
v4float buf508d[256];
v4float buf509[256];
v4float buf509d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf507_buf507d[1];
  window_datatype * buf507_ptr = (window_datatype * )buf507;
  window_datatype * buf507d_ptr = (window_datatype * )buf507d;
  window_init(window_buf507_buf507d, 1, buf507, LOCK_44_0_2_4096, buf507d, LOCK_44_0_3_4096, 256, 256);
  window_internal window_buf508_buf508d[1];
  window_datatype * buf508_ptr = (window_datatype * )buf508;
  window_datatype * buf508d_ptr = (window_datatype * )buf508d;
  window_init(window_buf508_buf508d, 1, buf508, LOCK_45_1_0_0, buf508d, LOCK_45_1_1_0, 256, 256);
  window_internal window_buf506_buf506d[1];
  window_datatype * buf506_ptr = (window_datatype * )buf506;
  window_datatype * buf506d_ptr = (window_datatype * )buf506d;
  window_init(window_buf506_buf506d, 1, buf506, LOCK_44_1_4_4096, buf506d, LOCK_44_1_5_4096, 256, 256);
  window_internal window_buf509_buf509d[1];
  window_datatype * buf509_ptr = (window_datatype * )buf509;
  window_datatype * buf509d_ptr = (window_datatype * )buf509d;
  window_init(window_buf509_buf509d, 1, buf509, LOCK_44_1_6_4096, buf509d, LOCK_44_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_1_bounds = sync_buffer[1];

  while (proc_44_1_bounds)
  {

    // Kernel call : i335:mm_kernel1
    window_acquire(window_buf507_buf507d,LOCK_44_0_2_4096,LOCK_44_0_3_4096,buf507_ptr,buf507d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf508_buf508d,LOCK_45_1_0_0,LOCK_45_1_1_0,buf508_ptr,buf508d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf506_buf506d,LOCK_44_1_4_4096,LOCK_44_1_5_4096,buf506_ptr,buf506d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf509_buf509d,LOCK_44_1_6_4096,LOCK_44_1_7_4096,buf509_ptr,buf509d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf507_buf507d),get_input_window_float(window_buf508_buf508d),get_input_window_float(window_buf506_buf506d),get_output_window_float(window_buf509_buf509d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf507_buf507d,LOCK_44_0_2_4096,LOCK_44_0_3_4096,buf507_ptr,buf507d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf508_buf508d,LOCK_45_1_0_0,LOCK_45_1_1_0,buf508_ptr,buf508d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf506_buf506d,LOCK_44_1_4_4096,LOCK_44_1_5_4096,buf506_ptr,buf506d_ptr,0,index, REL_WRITE);
    window_release(window_buf509_buf509d,LOCK_44_1_6_4096,LOCK_44_1_7_4096,buf509_ptr,buf509d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_1_bounds > 0)
      --proc_44_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}