#include <stdlib.h>
#include <stdint.h>
#include "memory.h"
#include "fetch.h"

uint32_t fetch(uint64_t addr) {
    uint32_t inst = read_vmemory_word(addr);
    return inst;
}