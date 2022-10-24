#include "config_trans1.hpp"
#include <math.h>
#include <stdio.h>
#include <hls_stream.h>
/**
 * @brief baseline project, without any optimizaiton
 * 
 */
typedef hls::stream<uint32_t> axis_stream_addr;
typedef hls::stream<ap_uint<512>> axis_stream_512;


extern "C" {
void gen_load_addr(axis_stream_addr & load_addr, const uint32_t bh, const uint32_t bw){
  for(uint32_t h = 0; h < bh; ++h){
    for(uint32_t w = 0; w < bw; ++w){
      for(uint32_t sw = 0; sw < SUB_W; ++sw){
        for(uint32_t sh = 0; sh < SUB_H / T_SIZE; ++sh){
    #pragma HLS pipeline II = 1
          uint32_t addr=(w * SUB_W + sw) * (bh * SUB_H) / T_SIZE + h * SUB_H / T_SIZE + sh;
          load_addr.write(addr);
        }
      }
    }
  }
}


void gen_write_addr(axis_stream_addr & write_addr, const uint32_t ah, const uint32_t aw){ // sub_h & sub_w are the same to the previous one
    for(uint32_t h = 0; h < ah; ++h){
      for(uint32_t w = 0; w < aw; ++w){
        for(uint32_t sw = 0; sw < SUB_H; ++sw){
          for(uint32_t sh = 0; sh < SUB_W / T_SIZE; ++sh){
      #pragma HLS pipeline II = 1
            uint32_t addr=(w * SUB_H + sw) * (ah * SUB_W) / T_SIZE + h * SUB_W / T_SIZE + sh;
            write_addr.write(addr);
          }
        }
      }
    }
}

void load_data(data_t* mem_in, axis_stream_addr & load_addr, axis_stream_512 & data_stream_in, uint32_t bh, uint32_t bw){
    for(uint32_t i = 0; i < SUB_H * SUB_W / (BITWIDTH/DATAWIDTH) * bh * bw; ++i){
      uint32_t addr = load_addr.read();
      data_t tmp = mem_in[addr];
      data_stream_in.write(tmp);
    }
}

void write_data(data_t * mem_out, axis_stream_addr & write_addr, axis_stream_512 & data_stream_out, uint32_t ah, uint32_t aw){
    for(uint32_t i = 0; i < SUB_H * SUB_W / (BITWIDTH/DATAWIDTH) * ah * aw; ++i){
      uint32_t addr = write_addr.read();
      data_t tmp = data_stream_out.read();
      mem_out[addr] = tmp;
    }
}

void stream2buffer(const bool enable, axis_stream_512 & data_stream_in, float buf_val[SUB_W][SUB_H]){
    if(!enable) return;
    for(uint32_t sw = 0; sw < SUB_W; ++sw){
    for(uint32_t sh = 0; sh < SUB_H / T_SIZE; ++sh){
#pragma HLS pipeline II = 1
      data_t tmp = data_stream_in.read();
      for(uint32_t k = 0; k < T_SIZE; ++k){
#pragma HLS unroll
        buf_val[sw][sh * T_SIZE + k] = tmp((k + 1) * 32 - 1, k * 32);
      }
    }
  }
}

void buffer2stream(const bool enable, axis_stream_512 & data_stream_out, float buf_val[SUB_W][SUB_H]){
    if(!enable) return;
    for(uint32_t sw = 0; sw < SUB_H; ++sw){
      for(uint32_t sh = 0; sh < SUB_W / T_SIZE; ++sh){
  #pragma HLS pipeline II = 1
        data_t tmp;
        for(uint32_t k = 0; k < T_SIZE; ++k){
  #pragma HLS unroll
          tmp((k + 1) * 32 - 1, k * 32) = buf_val[sh * T_SIZE + k][sw];
        } 
        data_stream_out.write(tmp);
      }
    }
}

void reorder(axis_stream_512 & data_stream_in, axis_stream_512 & data_stream_out, uint32_t bh, uint32_t bw, uint32_t ah, uint32_t aw){
    float buf_src_1[SUB_W][SUB_H];
    float buf_src_2[SUB_W][SUB_H];

    #pragma HLS bind_storage variable=buf_src_1 type=RAM_1P impl=LUTRAM
    #pragma HLS bind_storage variable=buf_src_2 type=RAM_1P impl=LUTRAM

    #pragma HLS array_partition variable = buf_src_1 dim = 1 factor = 16 cyclic
    #pragma HLS array_partition variable = buf_src_1 dim = 2 factor = 16 cyclic

    #pragma HLS array_partition variable = buf_src_2 dim = 1 factor = 16 cyclic
    #pragma HLS array_partition variable = buf_src_2 dim = 2 factor = 16 cyclic

    uint64_t total_size = (bh * bw);

    for(uint64_t i = 0; i < total_size + 1; i++){
        if(i % 2 == 0){
            stream2buffer(i < total_size, data_stream_in, buf_src_1);
            buffer2stream(i > 0, data_stream_out, buf_src_2);
        }else{
            stream2buffer(i < total_size, data_stream_in, buf_src_2);
            buffer2stream(i > 0, data_stream_out, buf_src_1);
        }
    }
    printf("reoder finish \r\n");
}


void transpose1(data_t * mem_in, data_t * mem_out, uint32_t bh, uint32_t bw, uint32_t ah, uint32_t aw) {
#pragma HLS interface m_axi port = mem_in offset = slave bundle = gmem0 max_read_burst_length=32 num_read_outstanding=16
#pragma HLS interface m_axi port = mem_out offset = slave bundle = gmem1 max_write_burst_length=16 num_write_outstanding=16

#pragma HLS interface s_axilite port = mem_in bundle = control
#pragma HLS interface s_axilite port = mem_out bundle = control

#pragma HLS interface s_axilite port = bw bundle = control
#pragma HLS interface s_axilite port = bh bundle = control
#pragma HLS interface s_axilite port = aw bundle = control
#pragma HLS interface s_axilite port = ah bundle = control
#pragma HLS interface s_axilite port = return bundle = control

    axis_stream_addr load_addr("load_addr");
    axis_stream_addr write_addr("write_addr");
    axis_stream_512 trans_data_in("trans_data_in");
    axis_stream_512 trans_data_out("trans_data_out");
  
  #pragma HLS DATAFLOW
    gen_load_addr(load_addr, bh, bw); // uint32_t h_bef, uint32_t w_bef, uint32_t sub_h, uint32_t sub_w, uint32_t chunk
    load_data(mem_in, load_addr, trans_data_in, bh, bw);
    reorder(trans_data_in,trans_data_out, bh, bw, ah, aw);
    gen_write_addr(write_addr, ah, aw); // uint32_t h_bef, uint32_t w_bef, uint32_t sub_h, uint32_t sub_w
    write_data(mem_out, write_addr, trans_data_out, ah, aw); // (tapa::async_mmap<Elem>& mem_out, tapa::istream<uint64_t> & write_addr, tapa::istream<Elem> & data_stream_out, uint32_t h_bef, uint32_t w_bef, uint32_t sub_h, uint32_t sub_w)
    
}

} // extern C
