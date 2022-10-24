#include "config_softmax.hpp"
#include <math.h>
#include <stdio.h>
#include <cstdint>
#include <hls_stream.h>
/**
 * @brief baseline project, without any optimizaiton
 * 
 */

typedef hls::stream<ap_uint<512>> axis_stream_512;


extern "C" {



void gen_read_addr(axis_stream_512& read_addr_stream, uint32_t row_size, uint32_t col_chunk){
  for(uint32_t cck = 0; cck < col_chunk; ++cck){
    gen_read_addr_i:
    for(uint32_t i = 0; i < row_size / T_SIZE; i += ROTATE){
      gen_read_addr_j:
      for(uint32_t j = 0; j < COL_SIZE; ++j){
        gen_read_addr_k:
        for(uint32_t k = 0; k < ROTATE; ++k){ // II = 1, Depth = 1
#pragma HLS pipeline II = 1
            uint32_t addr = i + j * row_size/T_SIZE + k + cck * COL_SIZE * row_size / T_SIZE;
            read_addr_stream.write(addr);
          
        }
      }
    }
  }
}

void gen_write_addr(axis_stream_512 &write_addr_stream, uint32_t row_size, uint32_t col_chunk){
  for(uint32_t cck = 0; cck < col_chunk; ++cck){
    gen_write_addr_i:
    for(uint32_t i = 0; i < row_size / T_SIZE; i += ROTATE){
      gen_write_addr_j:
      for(uint32_t j = 0; j < COL_SIZE; ++j){
        gen_write_addr_k:
        for(uint32_t k = 0; k < ROTATE; ++k){ // II = 1, Depth = 1
#pragma HLS pipeline II = 1
            uint32_t addr=i + j * row_size/T_SIZE + k + cck * COL_SIZE * row_size / T_SIZE;
            write_addr_stream.write(addr);
        }
      }
    }
  }
}

void load_ddr(data_t *src, axis_stream_512 & read_addr_stream, axis_stream_512& val_stream, uint32_t row_size, uint32_t col_chunk){

  uint32_t addr_count = 0;
    load_ddr:
    for(uint32_t i = 0; i < col_chunk * row_size * COL_SIZE/ T_SIZE; ++i){ // II = 1, Depth = 2
#pragma HLS pipeline II = 1

        uint32_t addr = read_addr_stream.read();
		    data_t tmp = src[addr];
        val_stream.write(tmp);
       
    }

}

void write_ddr(data_t *dst, axis_stream_512& write_addr_stream, axis_stream_512 & res_stream, uint32_t row_size, uint32_t col_chunk){

  uint32_t addr_count = 0;
    write_ddr:
    for(uint32_t i = 0; i  < col_chunk * row_size * COL_SIZE/ T_SIZE; ++i){ // II = 1, Depth = 2
#pragma HLS pipeline II = 1
      uint32_t addr = write_addr_stream.read();
      data_t tmp = res_stream.read();
	  dst[addr] = tmp;

    }

}


void load_and_sum(const bool enable, axis_stream_512& val_stream, data_t buf_val[ROTATE][COL_SIZE], data_t buf_sum[ROTATE]){

  if(!enable) return;
  data_t sum0[ROTATE];
  load_and_sum_i:
  for(uint32_t i = 0; i < COL_SIZE; ++i){
    load_and_sum_j:
    for(uint32_t j = 0; j < ROTATE; ++j){ // II = 1, Depth = 23
#pragma HLS pipeline II = 1
      data_t tmp = val_stream.read();
      load_and_sum_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
       #pragma HLS unroll
        fp_int val, s;
        val.raw = tmp((k + 1) * 32 - 1, k * 32);
        val.val = exp(val.val);
        s.raw = i == 0 ? 0 : sum0[j]((k + 1) * 32 - 1, k * 32);
        s.val += val.val;
        buf_val[j][i]((k + 1) * 32 - 1, k * 32) = val.raw;
        sum0[j]((k + 1) * 32 - 1, k * 32) = s.raw;
      }
    }
  }
  
  store_sum_j:
  for(uint32_t j = 0; j < ROTATE; ++j){ // II = 1, Depth = 2
#pragma HLS pipeline II = 1
    store_sum_k:
      buf_sum[j] = sum0[j];
  }
}

void divide(const bool enable, data_t buf_val[ROTATE][COL_SIZE], data_t buf_sum[ROTATE], data_t buf_res[ROTATE][COL_SIZE]){
  if(!enable) return;
  divide_col:
  for(uint32_t col = 0; col < COL_SIZE; ++col){
    divide_rotate:
    for(uint32_t rotate = 0; rotate < ROTATE; ++rotate){ // II = 9
#pragma HLS pipeline II = 1
      divide_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
#pragma HLS unroll
		fp_int v1, v2, v3;
		v1.raw = buf_val[rotate][col]((k + 1) * 32 - 1, k * 32);
		v2.raw = buf_sum[rotate]((k + 1) * 32 - 1, k * 32);
		v3.val = v1.val / v2.val;
		// printf("v1:%f , v2:%f, v3:%f\r\n", v1.val, v2.val, v3.val);
		buf_res[rotate][col]((k + 1) * 32 - 1, k * 32) = v3.raw;
        // buf_res[k][rotate][col] = buf_val[k][rotate][col] / buf_sum[rotate][k];
      
      }
    }
  }

  divide_zero:
  for(uint32_t rotate = 0; rotate < ROTATE; ++rotate){
#pragma HLS pipeline II = 1
     buf_sum[rotate] = 0;
  }

}

void buffer2stream(const bool enable, axis_stream_512 &res_stream, data_t buf_res[ROTATE][COL_SIZE]){
  if(!enable) return;
  buffer2stream_col:
  for(uint32_t col = 0; col < COL_SIZE; ++col){
    buffer2stream_rotate:
    for(uint32_t rotate = 0; rotate < ROTATE; ++rotate){ // II = 1, Depth = 4
#pragma HLS pipeline II = 1
//       data_t tmp;
//       buffer2stream_k:
//       for(uint32_t k = 0; k < T_SIZE; ++k){
// #pragma HLS unroll
//         fp_int val;
//         val.val = buf_res[k][rotate][col];
//         tmp((k + 1) * 32 - 1, k * 32) = val.raw;
//       }
      res_stream << buf_res[rotate][col];
    }
  }

}



void compute(axis_stream_512& val_stream, axis_stream_512& res_stream, uint32_t row_size, uint32_t col_chunk){

data_t buf_val_1[ROTATE][COL_SIZE];
data_t buf_val_2[ROTATE][COL_SIZE];
data_t buf_res_1[ROTATE][COL_SIZE];
data_t buf_res_2[ROTATE][COL_SIZE];

data_t buf_sum_1[ROTATE];
data_t buf_sum_2[ROTATE];

#pragma HLS bind_storage variable=buf_val_1 type=RAM_1P impl=BRAM
#pragma HLS bind_storage variable=buf_val_2 type=RAM_1P impl=BRAM
#pragma HLS bind_storage variable=buf_res_1 type=RAM_1P impl=BRAM
#pragma HLS bind_storage variable=buf_res_2 type=RAM_1P impl=BRAM

#pragma HLS bind_storage variable=buf_sum_1 type=RAM_1P impl=LUTRAM
#pragma HLS bind_storage variable=buf_sum_2 type=RAM_1P impl=LUTRAM


  compute:
  for(uint32_t i = 0; i < (col_chunk * row_size/T_SIZE/ROTATE) + 2; ++i){

    if(i % 2 == 0){
      load_and_sum(i < (col_chunk *row_size/T_SIZE/ROTATE), val_stream, buf_val_1, buf_sum_1);
      divide(i > 0 && i < (col_chunk *row_size/T_SIZE/ROTATE) + 1, buf_val_2, buf_sum_2, buf_res_2);
      buffer2stream(i > 1, res_stream, buf_res_1);
    }else{
      load_and_sum(i < (col_chunk *row_size/T_SIZE/ROTATE), val_stream, buf_val_2, buf_sum_2);
      divide(i > 0 && i < (col_chunk *row_size/T_SIZE/ROTATE) + 1, buf_val_1, buf_sum_1, buf_res_1);
      buffer2stream(i > 1, res_stream, buf_res_2);
    }
  
  }


}


/**
 * @brief 
 * 
 * @param mem 
 * @param res 
 */

void softmax(data_t * mem_src, data_t *mem_res, uint32_t row_size, uint32_t col_chunk) {
#pragma HLS INTERFACE m_axi port=mem_src offset=slave bundle=gmem0  max_read_burst_length=16 num_read_outstanding=16
#pragma HLS INTERFACE m_axi port=mem_res offset=slave bundle=gmem1  max_read_burst_length=16 num_read_outstanding=16

#pragma HLS interface s_axilite port=mem_src bundle=control
#pragma HLS interface s_axilite port=mem_res bundle=control
#pragma HLS interface s_axilite port=row_size bundle=control
#pragma HLS interface s_axilite port=col_chunk bundle=control
#pragma HLS interface s_axilite port = return bundle = control

  axis_stream_512 val_stream("val_stream"); // load exp(xi)
  axis_stream_512 res_stream("res_stream"); // res
  axis_stream_512 read_addr_stream("read_addr_stream"); // addrread_write_stream
  axis_stream_512 write_addr_stream("write_addr_stream");
  

#pragma HLS DATAFLOW
	gen_read_addr(read_addr_stream, row_size, col_chunk);
	load_ddr(mem_src, read_addr_stream, val_stream, row_size, col_chunk);
	compute(val_stream, res_stream, row_size, col_chunk);
	gen_write_addr(write_addr_stream, row_size, col_chunk);
	write_ddr(mem_res, write_addr_stream, res_stream, row_size, col_chunk);
    
}

} // extern C
