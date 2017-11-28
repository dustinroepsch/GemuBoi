#pragma once

#include <cstdint>

/*
* Little endian most significant bit of a word
*/
uint8_t msb(uint16_t word) {
    return 0x00FF & word;
}

/*
* Little endian least significan bit of a wor
*/
uint8_t lsb(uint16_t word) {
    //little endian so lsb is 1st byte
    return word >> 8;
}
/*
* Little endian word from lsb and msb
*/
uint16_t makeWord(uint16_t lsb, uint16_t msb) {
    //little endian;
    return (lsb << 8) ^ msb;
}