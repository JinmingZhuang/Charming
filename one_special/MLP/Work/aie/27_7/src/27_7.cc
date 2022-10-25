// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_7/src/27_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_6_2_4096 2
#define LOCK_27_6_3_4096 3
#define LOCK_27_6_4_0 4
#define LOCK_27_6_5_0 5
#define LOCK_27_6_0_0 0
#define LOCK_27_6_1_0 1
#define LOCK_27_6_6_4096 6
#define LOCK_27_6_7_4096 7

// Declare shared memory buffers
v4float buf848[256];
v4float buf848d[256];
v4float buf849[256];
v4float buf849d[256];
v4float buf850[256];
v4float buf850d[256];
v4float buf851[256];
v4float buf851d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf849_buf849d[1];
  window_datatype * buf849_ptr = (window_datatype * )buf849;
  window_datatype * buf849d_ptr = (window_datatype * )buf849d;
  window_init(window_buf849_buf849d, 1, buf849, LOCK_27_6_2_4096, buf849d, LOCK_27_6_3_4096, 256, 256);
  window_internal window_buf850_buf850d[1];
  window_datatype * buf850_ptr = (window_datatype * )buf850;
  window_datatype * buf850d_ptr = (window_datatype * )buf850d;
  window_init(window_buf850_buf850d, 1, buf850, LOCK_27_6_4_0, buf850d, LOCK_27_6_5_0, 256, 256);
  window_internal window_buf848_buf848d[1];
  window_datatype * buf848_ptr = (window_datatype * )buf848;
  window_datatype * buf848d_ptr = (window_datatype * )buf848d;
  window_init(window_buf848_buf848d, 1, buf848, LOCK_27_6_0_0, buf848d, LOCK_27_6_1_0, 256, 256);
  window_internal window_buf851_buf851d[1];
  window_datatype * buf851_ptr = (window_datatype * )buf851;
  window_datatype * buf851d_ptr = (window_datatype * )buf851d;
  window_init(window_buf851_buf851d, 1, buf851, LOCK_27_6_6_4096, buf851d, LOCK_27_6_7_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_7_bounds = sync_buffer[1];

  while (proc_27_7_bounds)
  {

    // Kernel call : i505:mm_kernel1
    window_acquire(window_buf849_buf849d,LOCK_27_6_2_4096,LOCK_27_6_3_4096,buf849_ptr,buf849d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf850_buf850d,LOCK_27_6_4_0,LOCK_27_6_5_0,buf850_ptr,buf850d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf848_buf848d,LOCK_27_6_0_0,LOCK_27_6_1_0,buf848_ptr,buf848d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf851_buf851d,LOCK_27_6_6_4096,LOCK_27_6_7_4096,buf851_ptr,buf851d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf849_buf849d),get_input_window_float(window_buf850_buf850d),get_input_window_float(window_buf848_buf848d),get_output_window_float(window_buf851_buf851d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf849_buf849d,LOCK_27_6_2_4096,LOCK_27_6_3_4096,buf849_ptr,buf849d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf850_buf850d,LOCK_27_6_4_0,LOCK_27_6_5_0,buf850_ptr,buf850d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf848_buf848d,LOCK_27_6_0_0,LOCK_27_6_1_0,buf848_ptr,buf848d_ptr,0,index, REL_WRITE);
    window_release(window_buf851_buf851d,LOCK_27_6_6_4096,LOCK_27_6_7_4096,buf851_ptr,buf851d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_7_bounds > 0)
      --proc_27_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}