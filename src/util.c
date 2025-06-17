#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "util.h"

uint32_t extract(uint64_t value, uint8_t upper, uint8_t lower) {
    uint32_t length = upper - lower + 1;
    uint64_t val = value;
    val = val >> lower;
    val = val & ((1 << length)-1);
    return val;
}

uint64_t sext(uint64_t val, ssize_t size) {
    uint8_t extbit = size - 1;
    uint64_t mask = 0x1lu << extbit;
    if(mask & val) {
        uint64_t sextmask = 0xffffffffffffffff << size;
        return sextmask | val;
    } else {
        return val;
    }
}