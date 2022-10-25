// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_1/src/42_1.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_0_2_4096 2
#define LOCK_42_0_3_4096 3
#define LOCK_42_1_4_0 20
#define LOCK_42_1_5_0 21
#define LOCK_42_1_2_4096 18
#define LOCK_42_1_3_4096 19
#define LOCK_42_1_6_4096 22
#define LOCK_42_1_7_4096 23

// Declare shared memory buffers
v4float buf482[256];
v4float buf482d[256];
v4float buf483[256];
v4float buf483d[256];
v4float buf484[256];
v4float buf484d[256];
v4float buf485[256];
v4float buf485d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf483_buf483d[1];
  window_datatype * buf483_ptr = (window_datatype * )buf483;
  window_datatype * buf483d_ptr = (window_datatype * )buf483d;
  window_init(window_buf483_buf483d, 1, buf483, LOCK_42_0_2_4096, buf483d, LOCK_42_0_3_4096, 256, 256);
  window_internal window_buf484_buf484d[1];
  window_datatype * buf484_ptr = (window_datatype * )buf484;
  window_datatype * buf484d_ptr = (window_datatype * )buf484d;
  window_init(window_buf484_buf484d, 1, buf484, LOCK_42_1_4_0, buf484d, LOCK_42_1_5_0, 256, 256);
  window_internal window_buf482_buf482d[1];
  window_datatype * buf482_ptr = (window_datatype * )buf482;
  window_datatype * buf482d_ptr = (window_datatype * )buf482d;
  window_init(window_buf482_buf482d, 1, buf482, LOCK_42_1_2_4096, buf482d, LOCK_42_1_3_4096, 256, 256);
  window_internal window_buf485_buf485d[1];
  window_datatype * buf485_ptr = (window_datatype * )buf485;
  window_datatype * buf485d_ptr = (window_datatype * )buf485d;
  window_init(window_buf485_buf485d, 1, buf485, LOCK_42_1_6_4096, buf485d, LOCK_42_1_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_1_bounds = sync_buffer[1];

  while (proc_42_1_bounds)
  {

    // Kernel call : i323:mm_kernel1
    window_acquire(window_buf483_buf483d,LOCK_42_0_2_4096,LOCK_42_0_3_4096,buf483_ptr,buf483d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf484_buf484d,LOCK_42_1_4_0,LOCK_42_1_5_0,buf484_ptr,buf484d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf482_buf482d,LOCK_42_1_2_4096,LOCK_42_1_3_4096,buf482_ptr,buf482d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf485_buf485d,LOCK_42_1_6_4096,LOCK_42_1_7_4096,buf485_ptr,buf485d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf483_buf483d),get_input_window_float(window_buf484_buf484d),get_input_window_float(window_buf482_buf482d),get_output_window_float(window_buf485_buf485d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf483_buf483d,LOCK_42_0_2_4096,LOCK_42_0_3_4096,buf483_ptr,buf483d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf484_buf484d,LOCK_42_1_4_0,LOCK_42_1_5_0,buf484_ptr,buf484d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf482_buf482d,LOCK_42_1_2_4096,LOCK_42_1_3_4096,buf482_ptr,buf482d_ptr,0,index, REL_WRITE);
    window_release(window_buf485_buf485d,LOCK_42_1_6_4096,LOCK_42_1_7_4096,buf485_ptr,buf485d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_1_bounds > 0)
      --proc_42_1_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}