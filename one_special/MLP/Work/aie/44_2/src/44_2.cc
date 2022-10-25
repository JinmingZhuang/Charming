// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/44_2/src/44_2.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_44_2_0_4096 48
#define LOCK_44_2_1_4096 49
#define LOCK_43_2_2_4096 18
#define LOCK_43_2_3_4096 19
#define LOCK_44_1_6_4096 6
#define LOCK_44_1_7_4096 7
#define LOCK_44_2_2_0 50
#define LOCK_44_2_3_0 51

// Declare shared memory buffers
v4float buf509[256];
v4float buf509d[256];
v4float buf510[256];
v4float buf510d[256];
v4float buf511[256];
v4float buf511d[256];
v4float buf512[256];
v4float buf512d[256];

// Declare Kernel functions and initializers
void mm_kernel1(input_window<float> *,input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf510_buf510d[1];
  window_datatype * buf510_ptr = (window_datatype * )buf510;
  window_datatype * buf510d_ptr = (window_datatype * )buf510d;
  window_init(window_buf510_buf510d, 1, buf510, LOCK_44_2_0_4096, buf510d, LOCK_44_2_1_4096, 256, 256);
  window_internal window_buf511_buf511d[1];
  window_datatype * buf511_ptr = (window_datatype * )buf511;
  window_datatype * buf511d_ptr = (window_datatype * )buf511d;
  window_init(window_buf511_buf511d, 1, buf511, LOCK_43_2_2_4096, buf511d, LOCK_43_2_3_4096, 256, 256);
  window_internal window_buf509_buf509d[1];
  window_datatype * buf509_ptr = (window_datatype * )buf509;
  window_datatype * buf509d_ptr = (window_datatype * )buf509d;
  window_init(window_buf509_buf509d, 1, buf509, LOCK_44_1_6_4096, buf509d, LOCK_44_1_7_4096, 256, 256);
  window_internal window_buf512_buf512d[1];
  window_datatype * buf512_ptr = (window_datatype * )buf512;
  window_datatype * buf512d_ptr = (window_datatype * )buf512d;
  window_init(window_buf512_buf512d, 1, buf512, LOCK_44_2_2_0, buf512d, LOCK_44_2_3_0, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_44_2_bounds = sync_buffer[1];

  while (proc_44_2_bounds)
  {

    // Kernel call : i336:mm_kernel1
    window_acquire(window_buf510_buf510d,LOCK_44_2_0_4096,LOCK_44_2_1_4096,buf510_ptr,buf510d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf511_buf511d,LOCK_43_2_2_4096,LOCK_43_2_3_4096,buf511_ptr,buf511d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf509_buf509d,LOCK_44_1_6_4096,LOCK_44_1_7_4096,buf509_ptr,buf509d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf512_buf512d,LOCK_44_2_2_0,LOCK_44_2_3_0,buf512_ptr,buf512d_ptr,0,index , ACQ_WRITE);
    mm_kernel1(get_input_window_float(window_buf510_buf510d),get_input_window_float(window_buf511_buf511d),get_input_window_float(window_buf509_buf509d),get_output_window_float(window_buf512_buf512d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf510_buf510d,LOCK_44_2_0_4096,LOCK_44_2_1_4096,buf510_ptr,buf510d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf511_buf511d,LOCK_43_2_2_4096,LOCK_43_2_3_4096,buf511_ptr,buf511d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf509_buf509d,LOCK_44_1_6_4096,LOCK_44_1_7_4096,buf509_ptr,buf509d_ptr,0,index, REL_WRITE);
    window_release(window_buf512_buf512d,LOCK_44_2_2_0,LOCK_44_2_3_0,buf512_ptr,buf512d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_44_2_bounds > 0)
      --proc_44_2_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}