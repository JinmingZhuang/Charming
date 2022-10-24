#ifndef CONFIG_LAYERNORM_HPP
#define CONFIG_LAYERNORM_HPP

#include <ap_int.h>
#include <stdint.h>


#define DATA_TYPE float
#define DATA_BIT (sizeof(DATA_TYPE) * 8)

#define COL_SIZE 1024
#define BITWIDTH  512
#define DATAWIDTH 32
const int T_SIZE=(BITWIDTH / DATAWIDTH) ;
const int COL_DT = COL_SIZE/ T_SIZE;


#define ROTATE    8 

#define data_t ap_int<BITWIDTH>

#define KRNL_REP 1

union fp_int{
    unsigned int raw;
    float val;
};

#endif
