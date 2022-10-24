#ifndef CONFIG_SOFTMAX_HPP
#define CONFIG_SOFTMAX_HPP

#include <ap_int.h>
#include <stdint.h>


#define DATA_TYPE float
#define DATA_BIT (sizeof(DATA_TYPE) * 8)

#define COL_SIZE 512
#define ROW_SIZE (16*8*16)
#define BITWIDTH  512
#define DATAWIDTH 32


#define ROTATE    8 

#define data_t ap_int<BITWIDTH>

#define KRNL_REP 1

const int T_SIZE =(BITWIDTH / DATAWIDTH) ;
const int COL_DT = COL_SIZE/ T_SIZE;

union fp_int{
    unsigned int raw;
    float val;
};

#endif
