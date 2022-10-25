// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/27_2/src/27_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_27_2_2_0 50
#define LOCK_27_2_3_0 51
#define LOCK_26_2_6_0 22
#define LOCK_26_2_7_0 23
#define LOCK_27_1_6_0 6
#define LOCK_27_1_7_4096 7
#define LOCK_27_2_4_4096 52
#define LOCK_27_2_5_4096 53

// Declare shared memory buffers
v4float buf305[256];
v4float buf305d[256];
v4float buf306[256];
v4float buf306d[256];
v4float buf307[256];
v4float buf307d[256];
v4float buf308[256];
v4float buf308d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf306_buf306d[1];
  window_datatype * buf306_ptr = (window_datatype * )buf306;
  window_datatype * buf306d_ptr = (window_datatype * )buf306d;
  window_init(window_buf306_buf306d, 1, buf306, LOCK_27_2_2_0, buf306d, LOCK_27_2_3_0, 256, 256);
  window_internal window_buf307_buf307d[1];
  window_datatype * buf307_ptr = (window_datatype * )buf307;
  window_datatype * buf307d_ptr = (window_datatype * )buf307d;
  window_init(window_buf307_buf307d, 1, buf307, LOCK_26_2_6_0, buf307d, LOCK_26_2_7_0, 256, 256);
  window_internal window_buf305_buf305d[1];
  window_datatype * buf305_ptr = (window_datatype * )buf305;
  window_datatype * buf305d_ptr = (window_datatype * )buf305d;
  window_init(window_buf305_buf305d, 1, buf305, LOCK_27_1_6_0, buf305d, LOCK_27_1_7_4096, 256, 256);
  window_internal window_buf308_buf308d[1];
  window_datatype * buf308_ptr = (window_datatype * )buf308;
  window_datatype * buf308d_ptr = (window_datatype * )buf308d;
  window_init(window_buf308_buf308d, 1, buf308, LOCK_27_2_4_4096, buf308d, LOCK_27_2_5_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_27_2_bounds = sync_buffer[1];

  while (proc_27_2_bounds)
  {

    // Kernel call : i234:mm_kernel1
    window_acquire(window_buf306_buf306d,LOCK_27_2_2_0,LOCK_27_2_3_0,buf306_ptr,buf306d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf307_buf307d,LOCK_26_2_6_0,LOCK_26_2_7_0,buf307_ptr,buf307d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf305_buf305d,LOCK_27_1_6_0,LOCK_27_1_7_4096,buf305_ptr,buf305d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf308_buf308d,LOCK_27_2_4_4096,LOCK_27_2_5_4096,buf308_ptr,buf308d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf306_buf306d),get_input_window_float(window_buf307_buf307d),get_input_window_float(window_buf305_buf305d),get_output_window_float(window_buf308_buf308d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf306_buf306d,LOCK_27_2_2_0,LOCK_27_2_3_0,buf306_ptr,buf306d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf307_buf307d,LOCK_26_2_6_0,LOCK_26_2_7_0,buf307_ptr,buf307d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf305_buf305d,LOCK_27_1_6_0,LOCK_27_1_7_4096,buf305_ptr,buf305d_ptr,0,index, REL_WRITE);
    window_release(window_buf308_buf308d,LOCK_27_2_4_4096,LOCK_27_2_5_4096,buf308_ptr,buf308d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_27_2_bounds > 0)
      --proc_27_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}