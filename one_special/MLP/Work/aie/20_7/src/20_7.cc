// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/20_7/src/20_7.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_20_7_2_4096 18
#define LOCK_20_7_3_4096 19
#define LOCK_20_6_2_4096 2
#define LOCK_20_6_3_4096 3
#define LOCK_20_7_0_0 16
#define LOCK_20_7_1_0 17
#define LOCK_20_7_4_0 20
#define LOCK_20_7_5_0 21

// Declare shared memory buffers
v4float buf932[256];
v4float buf932d[256];
v4float buf933[256];
v4float buf933d[256];
v4float buf934[256];
v4float buf934d[256];
v4float buf935[256];
v4float buf935d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf933_buf933d[1];
  window_datatype * buf933_ptr = (window_datatype * )buf933;
  window_datatype * buf933d_ptr = (window_datatype * )buf933d;
  window_init(window_buf933_buf933d, 1, buf933, LOCK_20_7_2_4096, buf933d, LOCK_20_7_3_4096, 256, 256);
  window_internal window_buf934_buf934d[1];
  window_datatype * buf934_ptr = (window_datatype * )buf934;
  window_datatype * buf934d_ptr = (window_datatype * )buf934d;
  window_init(window_buf934_buf934d, 1, buf934, LOCK_20_6_2_4096, buf934d, LOCK_20_6_3_4096, 256, 256);
  window_internal window_buf932_buf932d[1];
  window_datatype * buf932_ptr = (window_datatype * )buf932;
  window_datatype * buf932d_ptr = (window_datatype * )buf932d;
  window_init(window_buf932_buf932d, 1, buf932, LOCK_20_7_0_0, buf932d, LOCK_20_7_1_0, 256, 256);
  window_internal window_buf935_buf935d[1];
  window_datatype * buf935_ptr = (window_datatype * )buf935;
  window_datatype * buf935d_ptr = (window_datatype * )buf935d;
  window_init(window_buf935_buf935d, 1, buf935, LOCK_20_7_4_0, buf935d, LOCK_20_7_5_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_20_7_bounds = sync_buffer[1];

  while (proc_20_7_bounds)
  {

    // Kernel call : i547:mm_kernel1
    window_acquire(window_buf933_buf933d,LOCK_20_7_2_4096,LOCK_20_7_3_4096,buf933_ptr,buf933d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf934_buf934d,LOCK_20_6_2_4096,LOCK_20_6_3_4096,buf934_ptr,buf934d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf932_buf932d,LOCK_20_7_0_0,LOCK_20_7_1_0,buf932_ptr,buf932d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf935_buf935d,LOCK_20_7_4_0,LOCK_20_7_5_0,buf935_ptr,buf935d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf933_buf933d),get_input_window_float(window_buf934_buf934d),get_input_window_float(window_buf932_buf932d),get_output_window_float(window_buf935_buf935d));
    // The output port does not connect to an ME compute node, so write pointer need not be advanced
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf933_buf933d,LOCK_20_7_2_4096,LOCK_20_7_3_4096,buf933_ptr,buf933d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf934_buf934d,LOCK_20_6_2_4096,LOCK_20_6_3_4096,buf934_ptr,buf934d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf932_buf932d,LOCK_20_7_0_0,LOCK_20_7_1_0,buf932_ptr,buf932d_ptr,0,index, REL_WRITE);
    window_release(window_buf935_buf935d,LOCK_20_7_4_0,LOCK_20_7_5_0,buf935_ptr,buf935d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_20_7_bounds > 0)
      --proc_20_7_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}