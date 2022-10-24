#ifndef CONFIG_TRANS1_HPP
#define CONFIG_TRANS1_HPP

#include <ap_int.h>
#include <stdint.h>


#define DATA_TYPE float
#define DATA_BIT (sizeof(DATA_TYPE) * 8)


#define COL_SIZE 512
#define ROW_SIZE (16*8*512)
#define BITWIDTH  512
#define DATAWIDTH 32

#define SUB_W 64
#define SUB_H 512

#define data_t ap_int<BITWIDTH>

const int T_SIZE = (BITWIDTH / DATAWIDTH) ;

union fp_int{
    unsigned int raw;
    float val;
};

#endif
