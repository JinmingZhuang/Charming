// Automatically generated Processor driver using MathEngine Tool chain
// Processor File : ./Work/aie/42_0/src/42_0.cc
// Runs 1 ME kernel

#include <stdio.h>

#define __AIEARCH__ 1
#undef DEBUG 
#undef DEBUGLOCKS 

#include <adf.h>
// Initialize sync_buffer[1] with compiler option static test-iterations value or -1
volatile static int sync_buffer[8] = {0, -1};
#include <adf/sync/mesync.h>

#define LOCK_42_0_0_0 48
#define LOCK_42_0_1_0 49
#define LOCK_41_0_2_4096 18
#define LOCK_41_0_3_4096 19
#define LOCK_42_1_2_4096 34
#define LOCK_42_1_3_4096 35

// Declare shared memory buffers
v4float buf480[256];
v4float buf480d[256];
v4float buf481[256];
v4float buf481d[256];
v4float buf482[256];
v4float buf482d[256];

// Declare Kernel functions and initializers
void mm_kernel0(input_window<float> *,input_window<float> *,output_window<float> *);

// Declare Kernel objects and external arrays

int main(void) {
  sync_buffer[0] = 0; //reset end signal
  window_internal window_buf480_buf480d[1];
  window_datatype * buf480_ptr = (window_datatype * )buf480;
  window_datatype * buf480d_ptr = (window_datatype * )buf480d;
  window_init(window_buf480_buf480d, 1, buf480, LOCK_42_0_0_0, buf480d, LOCK_42_0_1_0, 256, 256);
  window_internal window_buf481_buf481d[1];
  window_datatype * buf481_ptr = (window_datatype * )buf481;
  window_datatype * buf481d_ptr = (window_datatype * )buf481d;
  window_init(window_buf481_buf481d, 1, buf481, LOCK_41_0_2_4096, buf481d, LOCK_41_0_3_4096, 256, 256);
  window_internal window_buf482_buf482d[1];
  window_datatype * buf482_ptr = (window_datatype * )buf482;
  window_datatype * buf482d_ptr = (window_datatype * )buf482d;
  window_init(window_buf482_buf482d, 1, buf482, LOCK_42_1_2_4096, buf482d, LOCK_42_1_3_4096, 256, 256);
  int32 index = 0;
  while(true)
  {

  int32 proc_42_0_bounds = sync_buffer[1];

  while (proc_42_0_bounds)
  {

    // Kernel call : i322:mm_kernel0
    window_acquire(window_buf480_buf480d,LOCK_42_0_0_0,LOCK_42_0_1_0,buf480_ptr,buf480d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf481_buf481d,LOCK_41_0_2_4096,LOCK_41_0_3_4096,buf481_ptr,buf481d_ptr,0,index, ACQ_READ);
    window_acquire(window_buf482_buf482d,LOCK_42_1_2_4096,LOCK_42_1_3_4096,buf482_ptr,buf482d_ptr,0,index , ACQ_WRITE);
    mm_kernel0(get_input_window_float(window_buf480_buf480d),get_input_window_float(window_buf481_buf481d),get_output_window_float(window_buf482_buf482d));
    // The output port margin is zero, therefore write pointer is in correct position for reading
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf480_buf480d,LOCK_42_0_0_0,LOCK_42_0_1_0,buf480_ptr,buf480d_ptr,0,index, REL_WRITE);
    // The input port margin is zero, therefore there is no copy to be done
    // And now the lock has ended
    window_release(window_buf481_buf481d,LOCK_41_0_2_4096,LOCK_41_0_3_4096,buf481_ptr,buf481d_ptr,0,index, REL_WRITE);
    window_release(window_buf482_buf482d,LOCK_42_1_2_4096,LOCK_42_1_3_4096,buf482_ptr,buf482d_ptr,0,index, REL_READ);
    index = 1 - index;

    chess_memory_fence();

    if(proc_42_0_bounds > 0)
      --proc_42_0_bounds;
  }
  done();
  if (sync_buffer[0] > 0) break;
  }
  return 0;
}