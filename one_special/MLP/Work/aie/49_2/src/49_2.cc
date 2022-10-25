// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/49_2/src/49_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_49_2_0_0 48
#define LOCK_49_2_1_0 49
#define LOCK_49_2_2_4096 50
#define LOCK_49_2_3_4096 51
#define LOCK_49_1_6_4096 6
#define LOCK_49_1_7_4096 7
#define LOCK_49_3_0_0 32
#define LOCK_49_3_1_0 33

// Declare shared memory buffers
v4float buf569[256];
v4float buf569d[256];
v4float buf570[256];
v4float buf570d[256];
v4float buf571[256];
v4float buf571d[256];
v4float buf572[256];
v4float buf572d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf570_buf570d[1];
  window_datatype * buf570_ptr = (window_datatype * )buf570;
  window_datatype * buf570d_ptr = (window_datatype * )buf570d;
  window_init(window_buf570_buf570d, 1, buf570, LOCK_49_2_0_0, buf570d, LOCK_49_2_1_0, 256, 256);
  window_internal window_buf571_buf571d[1];
  window_datatype * buf571_ptr = (window_datatype * )buf571;
  window_datatype * buf571d_ptr = (window_datatype * )buf571d;
  window_init(window_buf571_buf571d, 1, buf571, LOCK_49_2_2_4096, buf571d, LOCK_49_2_3_4096, 256, 256);
  window_internal window_buf569_buf569d[1];
  window_datatype * buf569_ptr = (window_datatype * )buf569;
  window_datatype * buf569d_ptr = (window_datatype * )buf569d;
  window_init(window_buf569_buf569d, 1, buf569, LOCK_49_1_6_4096, buf569d, LOCK_49_1_7_4096, 256, 256);
  window_internal window_buf572_buf572d[1];
  window_datatype * buf572_ptr = (window_datatype * )buf572;
  window_datatype * buf572d_ptr = (window_datatype * )buf572d;
  window_init(window_buf572_buf572d, 1, buf572, LOCK_49_3_0_0, buf572d, LOCK_49_3_1_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_49_2_bounds = sync_buffer[1];

  while (proc_49_2_bounds)
  {

    // Kernel call : i366:mm_kernel1
    window_acquire(window_buf570_buf570d,LOCK_49_2_0_0,LOCK_49_2_1_0,buf570_ptr,buf570d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf571_buf571d,LOCK_49_2_2_4096,LOCK_49_2_3_4096,buf571_ptr,buf571d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf569_buf569d,LOCK_49_1_6_4096,LOCK_49_1_7_4096,buf569_ptr,buf569d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf572_buf572d,LOCK_49_3_0_0,LOCK_49_3_1_0,buf572_ptr,buf572d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf570_buf570d),get_input_window_float(window_buf571_buf571d),get_input_window_float(window_buf569_buf569d),get_output_window_float(window_buf572_buf572d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf570_buf570d,LOCK_49_2_0_0,LOCK_49_2_1_0,buf570_ptr,buf570d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf571_buf571d,LOCK_49_2_2_4096,LOCK_49_2_3_4096,buf571_ptr,buf571d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf569_buf569d,LOCK_49_1_6_4096,LOCK_49_1_7_4096,buf569_ptr,buf569d_ptr,0,index, REL_WRITE);
    window_release(window_buf572_buf572d,LOCK_49_3_0_0,LOCK_49_3_1_0,buf572_ptr,buf572d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_49_2_bounds > 0)
      --proc_49_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}