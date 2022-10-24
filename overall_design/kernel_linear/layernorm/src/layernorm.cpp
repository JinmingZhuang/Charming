#include "config_layernorm.hpp"
#include <math.h>
#include <stdio.h>
#include <hls_stream.h>
/**
 * @brief baseline project, without any optimizaiton
 * 
 */
typedef hls::stream<ap_uint<512>> axis_stream_512;


extern "C" {
// union fp_int {
//   float val;
//   unsigned int raw;
// };

void gen_read_addr(axis_stream_512 &read_addr_stream, uint32_t row_size, uint32_t col_chunk){
  gen_read_addr_cck:
  for(uint32_t cck = 0; cck < col_chunk; ++cck){
    gen_read_addr_i:
    for(uint32_t i = 0; i < row_size / T_SIZE; i += ROTATE){
      gen_read_addr_j:
      for(uint32_t j = 0; j < COL_SIZE; ++j){
        gen_read_addr_k:
        for(uint32_t k = 0; k < ROTATE; ++k){ // II = 1, Depth = 1
#pragma HLS pipeline II = 1
            uint32_t addr = j * row_size/ T_SIZE + k + i + cck * (COL_SIZE * row_size / T_SIZE);
            read_addr_stream.write(addr);
        }
      }
    }
  }
}

void gen_write_addr(axis_stream_512& write_addr_stream, uint32_t row_size, uint32_t col_chunk){
  gen_read_addr_cck:
  for(uint32_t cck = 0; cck < col_chunk; ++cck){
    gen_write_addr_i:
    for(uint32_t i = 0; i < row_size / T_SIZE; i += ROTATE){
      gen_write_addr_j:
      for(uint32_t j = 0; j < COL_SIZE; ++j){
        gen_write_addr_k:
        for(uint32_t k = 0; k < ROTATE; ++k){ // II = 1, Depth = 1
#pragma HLS pipeline II = 1
            uint32_t addr = i + j * row_size/ T_SIZE + k + cck * (COL_SIZE * row_size / T_SIZE);
            write_addr_stream.write(addr);
		}
	  }
	}
  }
}


void load_ddr(data_t *src, axis_stream_512& read_addr_stream, axis_stream_512& val_stream, uint32_t row_size, uint32_t col_chunk){
    load_ddr:
    for(uint32_t i = 0; i < col_chunk * row_size * COL_DT; ++i){ // II = 1, Depth = 2
#pragma HLS pipeline II = 1
        uint32_t addr = read_addr_stream.read();
        data_t tmp = src[addr];
		    val_stream.write(tmp);
    }
}

void write_ddr(data_t *dst, axis_stream_512& write_addr_stream, axis_stream_512& res_stream, uint32_t row_size, uint32_t col_chunk){
    write_ddr:
    for(uint32_t i = 0; i < col_chunk * row_size * COL_DT; ++i){ // II = 1, Depth = 2
#pragma HLS pipeline II = 1
      uint32_t addr = write_addr_stream.read();
        data_t tmp = res_stream.read();
		dst[addr] = tmp;
        
    }
}


void load_and_avg(const bool enable, axis_stream_512& val_stream, data_t buf_val[ROTATE][COL_SIZE], data_t buf_avg[ROTATE]){

  if(!enable) return;
  data_t avg[ROTATE];
  
  load_and_sum_i:
  for(uint32_t i = 0; i < COL_SIZE; ++i){
    load_and_sum_j:
    for(uint32_t j = 0; j < ROTATE; ++j){ // II = 1, Depth = 9
#pragma HLS pipeline II = 1
#pragma HLS DEPENDENCE variable=avg type=inter direction=RAW false
      data_t tmp = val_stream.read();
      load_and_sum_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
       #pragma HLS unroll
        fp_int val, s;
        val.raw = tmp((k + 1) * 32 - 1, k * 32);
        s.raw = i == 0 ? 0 : avg[j]((k + 1) * 32 - 1, k * 32);
        s.val += val.val;
        buf_val[j][i]((k + 1) * 32 - 1, k * 32) = val.raw;
        avg[j]((k + 1) * 32 - 1, k * 32) = s.raw;
      }
    }
  }
  store_avg_j:
  for(uint32_t j = 0; j < ROTATE; ++j){ // II = 1, Depth = 7
#pragma HLS pipeline II = 1
      data_t tmp;
      store_avg_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
#pragma HLS unroll
        fp_int s;
        s.raw = avg[j]((k + 1) * 32 - 1, k * 32);
		    s.val = s.val / COL_SIZE;
        tmp((k + 1) * 32 - 1, k * 32) = s.raw;
      }
      buf_avg[j] = tmp;
    }
}

void calcu_var(const bool enable, data_t buf_val[ROTATE][COL_SIZE], data_t buf_avg[ROTATE], data_t buf_std[ROTATE]){
  if(!enable) return;
  data_t var[ROTATE];
  float sub;
  calcu_var_i:
  for(uint32_t i = 0; i < COL_SIZE; ++i){
    calcu_var_j:
    for(uint32_t j = 0; j < ROTATE; ++j){ // II = 1, Depth = 21
#pragma HLS pipeline II = 1
#pragma HLS DEPENDENCE variable=var type=inter direction=RAW false
      calcu_var_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
      #pragma HLS unroll
        fp_int val, s;
        val.raw;
        s.raw = i == 0 ? 0 : var[j]((k + 1) * 32 - 1, k * 32);
		fp_int v1, v2;
		v1.raw = buf_val[j][i]((k + 1) * 32 - 1, k * 32);
		v2.raw = buf_avg[j]((k + 1) * 32 - 1, k * 32);
        sub = v1.val - v2.val;
        s.val += sub * sub;
        var[j]((k + 1) * 32 - 1, k * 32) = s.raw;
      }
    }
  }
  std_j:
    for(uint32_t j = 0; j < ROTATE; ++j){ // II = 1, Depth = 19
#pragma HLS pipeline II = 1
      std_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
#pragma HLS unroll
        fp_int s;
        s.raw = var[j]((k + 1) * 32 - 1, k * 32);
		s.val = sqrt(s.val / COL_SIZE);
		// printf("std1:%f\r\n", s.val);
        buf_std[j]((k + 1) * 32 - 1, k * 32) = s.raw;
      }
    }
}

void norm(const bool enable, data_t buf_val[ROTATE][COL_SIZE], data_t buf_avg[ROTATE], data_t buf_std[ROTATE], data_t buf_res[ROTATE][COL_SIZE]){
  if(!enable) return;
  norm_col:
  for(uint32_t col = 0; col < COL_SIZE; ++col){
    norm_rotate:
    for(uint32_t rotate = 0; rotate < ROTATE; ++rotate){ // II = 1, Depth = 23
#pragma HLS pipeline II = 1
      norm_k:
      for(uint32_t k = 0; k < T_SIZE; ++k){
#pragma HLS unroll
		fp_int v1, v2, v3;
		v1.raw = buf_val[rotate][col]((k + 1) * 32 - 1, k * 32);
		v2.raw = buf_avg[rotate]((k + 1) * 32 - 1, k * 32);
		v3.raw = buf_std[rotate]((k + 1) * 32 - 1, k * 32);
		fp_int v4;
		v4.val = (v1.val - v2.val) / v3.val;
		// printf("v1:%f , v2:%f, v3:%f\r\n", v1.val, v2.val, v3.val);
		buf_res[rotate][col]((k + 1) * 32 - 1, k * 32) = v4.raw;
        // buf_res[rotate][k][col] = (buf_val[rotate][k][col] - buf_avg[rotate][k]) / buf_std[rotate][k];
        
      }
    }
  }
  norm_zero:
  for(uint32_t rotate = 0; rotate < ROTATE; ++rotate){ // II = 1, Depth = 23
#pragma HLS pipeline II = 1
        buf_avg[rotate] = 0;
        buf_std[rotate] = 0;

  }
}

void buffer2stream(const bool enable, axis_stream_512 &res_stream, data_t buf_res[ROTATE][COL_SIZE]){
  if(!enable) return;
  buffer2stream_col:
  for(uint32_t col = 0; col < COL_SIZE; ++col){
    buffer2stream_rotate:
    for(uint32_t rotate = 0; rotate < ROTATE; ++rotate){ // II = 1, Depth = 4
#pragma HLS pipeline II = 1
      res_stream << buf_res[rotate][col];
    }
  }

}



void compute(axis_stream_512& val_stream, axis_stream_512& res_stream, uint32_t row_size, uint32_t col_chunk){

data_t buf_val_1[ROTATE][COL_SIZE];
data_t buf_val_2[ROTATE][COL_SIZE];
data_t buf_val_3[ROTATE][COL_SIZE];

data_t buf_res_1[ROTATE][COL_SIZE];
data_t buf_res_2[ROTATE][COL_SIZE];
data_t buf_res_3[ROTATE][COL_SIZE];

data_t buf_avg_1[ROTATE];
data_t buf_avg_2[ROTATE];
data_t buf_avg_3[ROTATE];

data_t buf_std_1[ROTATE];
data_t buf_std_2[ROTATE];
data_t buf_std_3[ROTATE];


#pragma HLS bind_storage variable=buf_val_1 type=RAM_1P impl=URAM
#pragma HLS bind_storage variable=buf_val_2 type=RAM_1P impl=URAM
#pragma HLS bind_storage variable=buf_val_3 type=RAM_1P impl=URAM

#pragma HLS bind_storage variable=buf_res_1 type=RAM_1P impl=URAM
#pragma HLS bind_storage variable=buf_res_2 type=RAM_1P impl=URAM
#pragma HLS bind_storage variable=buf_res_3 type=RAM_1P impl=URAM

#pragma HLS bind_storage variable=buf_avg_1 type=RAM_1P impl=LUTRAM
#pragma HLS bind_storage variable=buf_avg_2 type=RAM_1P impl=LUTRAM
#pragma HLS bind_storage variable=buf_avg_3 type=RAM_1P impl=LUTRAM

#pragma HLS bind_storage variable=buf_std_1 type=RAM_1P impl=LUTRAM
#pragma HLS bind_storage variable=buf_std_2 type=RAM_1P impl=LUTRAM
#pragma HLS bind_storage variable=buf_std_3 type=RAM_1P impl=LUTRAM


  compute:
  for(uint32_t i = 0; i < (col_chunk * row_size/T_SIZE/ROTATE) + 3; ++i){
	printf("run:%d\r\n", i);
    switch(i % 3){
      case 0:
        load_and_avg(i < (col_chunk * row_size/T_SIZE/ROTATE), val_stream, buf_val_1, buf_avg_1);
        calcu_var(i > 0 && i < (col_chunk * row_size/T_SIZE/ROTATE) + 1, buf_val_3, buf_avg_3, buf_std_3);
        norm(i > 1 && i < (col_chunk * row_size/T_SIZE/ROTATE) + 2, buf_val_2, buf_avg_2, buf_std_2, buf_res_2);
        buffer2stream(i > 2, res_stream, buf_res_1);
        break;
      case 1:
        load_and_avg(i < (col_chunk * row_size/T_SIZE/ROTATE), val_stream, buf_val_2, buf_avg_2);
        calcu_var(i > 0 && i < (col_chunk * row_size/T_SIZE/ROTATE) + 1, buf_val_1, buf_avg_1, buf_std_1);
        norm(i > 1 && i < (col_chunk * row_size/T_SIZE/ROTATE) + 2, buf_val_3, buf_avg_3, buf_std_3, buf_res_3);
        buffer2stream(i > 2, res_stream, buf_res_2);
        break;
      case 2:
        load_and_avg(i < (col_chunk * row_size/T_SIZE/ROTATE), val_stream, buf_val_3, buf_avg_3);
        calcu_var(i > 0 && i < (col_chunk * row_size/T_SIZE/ROTATE) + 1, buf_val_2, buf_avg_2, buf_std_2);
        norm(i > 1 && i < (col_chunk * row_size/T_SIZE/ROTATE) + 2, buf_val_1, buf_avg_1, buf_std_1, buf_res_1);
        buffer2stream(i > 2, res_stream, buf_res_3);
        break;
    }
  }


}

/**
 * @brief 
 * 
 * @param mem 
 * @param res 
 */
void layernorm(data_t * mem_src, data_t * mem_res, uint32_t row_size, uint32_t col_chunk) {
#pragma HLS INTERFACE m_axi port=mem_src offset=slave bundle=gmem0  max_read_burst_length=16 num_read_outstanding=16
#pragma HLS INTERFACE m_axi port=mem_res offset=slave bundle=gmem0  max_read_burst_length=16 num_read_outstanding=16

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
