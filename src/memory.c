#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "util.h"
#include "memory.h"

/* GLOBAL VARIABLES*/

uint64_t PC; // Program counter

register_data_t register_int[32];   // Integer register file
register_data_t register_float[32]; // Float register file

unsigned char***** vmemory = NULL; // Main memory

void register_init() {
    register_int[0] = (register_data_t)(uint64_t) 0;
}

register_data_t read_register_int(uint32_t index) {
    return register_int[index];
}

void write_register_int(uint32_t index, register_data_t data) {
    if(index != 0)
        register_int[index] = data;
}

register_data_t read_register_float(uint32_t index) {
    return register_float[index];
}

void write_register_float(uint32_t index, register_data_t data) {
        register_float[index] = data;
}

uint8_t read_vmemory_byte(uint64_t addr) {
    uint64_t L1 = extract(addr, 47, 40);
    uint64_t L2 = extract(addr, 39, 32);
    uint64_t L3 = extract(addr, 31, 24);
    uint64_t L4 = extract(addr, 23, 12);
    uint64_t L5 = extract(addr, 11,  0);

    if(vmemory ==  NULL) {
        vmemory = (uint8_t*****) malloc((1 << 8) * sizeof(uint8_t****));
        for(int i = 0; i < (1 << 8); i++) {
            vmemory[i] = NULL;  
        }
    }

    if(vmemory[L1] ==  NULL) {
        vmemory[L1] = (uint8_t****) malloc((1 << 8) * sizeof(uint8_t***));
        for(int i = 0; i < (1 << 8); i++) {
            vmemory[L1][i] = NULL;
        }
    }

    if(vmemory[L1][L2] ==  NULL) {
        vmemory[L1][L2] = (uint8_t***) malloc((1 << 8) * sizeof(uint8_t**));
        for(int i = 0; i < (1 << 8); i++) {
            vmemory[L1][L2][i] = NULL;
        }
    }

    if(vmemory[L1][L2][L3] ==  NULL) {
        vmemory[L1][L2][L3] = (uint8_t**) malloc((1 << 12) * sizeof(uint8_t*));
        for(int i = 0; i < (1 << 12); i++) {
            vmemory[L1][L2][L3][i] = NULL;
        }
    }

    if(vmemory[L1][L2][L3][L4] ==  NULL) {
        vmemory[L1][L2][L3][L4] = (uint8_t*) malloc((1 << 12) * sizeof(uint8_t));
        for(int i = 0; i < (1 << 12); i++) {
           vmemory[L1][L2][L3][L4][i] = '\0';
        }
    }

    return vmemory[L1][L2][L3][L4][L5];
}

void write_vmemory_byte(uint64_t addr, uint8_t data) {
    uint64_t L1 = extract(addr, 47, 40);
    uint64_t L2 = extract(addr, 39, 32);
    uint64_t L3 = extract(addr, 31, 24);
    uint64_t L4 = extract(addr, 23, 12);
    uint64_t L5 = extract(addr, 11,  0);


    if(vmemory ==  NULL) {
        vmemory = (uint8_t*****) malloc((1 << 8) * sizeof(uint8_t****));
        for(int i = 0; i < (1 << 8); i++) {
            vmemory[i] = NULL;
        }
    }

    if(vmemory[L1] ==  NULL) {
        vmemory[L1] = (uint8_t****) malloc((1 << 8) * sizeof(uint8_t***));
        for(int i = 0; i < (1 << 8); i++) {
            vmemory[L1][i] = NULL;
        }
    }

    if(vmemory[L1][L2] ==  NULL) {
        vmemory[L1][L2] = (uint8_t***) malloc((1 << 8) * sizeof(uint8_t**));
        for(int i = 0; i < (1 << 8); i++) {
            vmemory[L1][L2][i] = NULL;
        }
    }

    if(vmemory[L1][L2][L3] ==  NULL) {
        vmemory[L1][L2][L3] = (uint8_t**) malloc((1 << 12) * sizeof(uint8_t*));
        for(int i = 0; i < (1 << 12); i++) {
            vmemory[L1][L2][L3][i] = NULL;
        }
    }

    if(vmemory[L1][L2][L3][L4] ==  NULL) {
        vmemory[L1][L2][L3][L4] = (uint8_t*) malloc((1 << 12) * sizeof(uint8_t));
        for(int i = 0; i < (1 << 12); i++) {
           vmemory[L1][L2][L3][L4][i] = '\0';
        }
    }

    vmemory[L1][L2][L3][L4][L5] = data;
}

uint16_t read_vmemory_halfword(uint64_t addr) {
    if(addr % 2 != 0) {
        printf("ERROR: Read halfword address not aligned: 0x%012lx\n", addr);
        exit(EXIT_FAILURE);
    }

    uint16_t byte0 = read_vmemory_byte(addr);
    uint16_t byte1 = read_vmemory_byte(addr+1);

    uint16_t data = (byte1<<8) | byte0;

    return data;
}

void write_vmemory_halfword(uint64_t addr, uint16_t data) {
    if(addr % 2 != 0) {
        printf("ERROR: Write halfword address not aligned: 0x%012lx\n", addr);
        exit(EXIT_FAILURE);
    }

    uint16_t byte0 =  data & 0x00ff;
    uint16_t byte1 = (data & 0xff00)>>8;

    write_vmemory_byte(addr, byte0);
    write_vmemory_byte(addr+1, byte1);
}

uint32_t read_vmemory_word(uint64_t addr) {
    if(addr % 4 != 0) {
        printf("ERROR: Read word address not aligned: 0x%012lx\n", addr);
        exit(EXIT_FAILURE);
    }

    uint32_t byte0 = read_vmemory_byte(addr);
    uint32_t byte1 = read_vmemory_byte(addr+1);
    uint32_t byte2 = read_vmemory_byte(addr+2);
    uint32_t byte3 = read_vmemory_byte(addr+3);

    uint32_t data = (byte3<<24) | (byte2<<16) | (byte1<<8) | byte0;

    return data;
}

void write_vmemory_word(uint64_t addr, uint32_t data) {
    if(addr % 4 != 0) {
        printf("ERROR: Read word address not aligned: 0x%012lx\n", addr);
        exit(EXIT_FAILURE);
    }

    uint32_t byte0 = (data & 0x000000ff);
    uint32_t byte1 = (data & 0x0000ff00)>>8;
    uint32_t byte2 = (data & 0x00ff0000)>>16;
    uint32_t byte3 = (data & 0xff000000)>>24;

    write_vmemory_byte(addr, byte0);
    write_vmemory_byte(addr+1, byte1);
    write_vmemory_byte(addr+2, byte2);
    write_vmemory_byte(addr+3, byte3);
}

uint64_t read_vmemory_doubleword(uint64_t addr) {
    if(addr % 8 != 0) {
        printf("ERROR: Read doubleword address not aligned: 0x%012lx\n", addr);
        exit(EXIT_FAILURE);
    }

    uint64_t byte0 = read_vmemory_byte(addr);
    uint64_t byte1 = read_vmemory_byte(addr+1);
    uint64_t byte2 = read_vmemory_byte(addr+2);
    uint64_t byte3 = read_vmemory_byte(addr+3);
    uint64_t byte4 = read_vmemory_byte(addr+4);
    uint64_t byte5 = read_vmemory_byte(addr+5);
    uint64_t byte6 = read_vmemory_byte(addr+6);
    uint64_t byte7 = read_vmemory_byte(addr+7);

    uint64_t data = (byte7<<56) | (byte6<<48) | (byte5<<40) | (byte4<<32) | (byte3<<24) | (byte2<<16) | (byte1<<8) | byte0;

    return data;
}

void write_vmemory_doubleword(uint64_t addr, uint64_t data) {
    if(addr % 8 != 0) {
        printf("ERROR: Write doubleword address not aligned: 0x%012lx\n", addr);
        exit(EXIT_FAILURE);
    }

    uint64_t byte0 = (data & 0x00000000000000ff);
    uint64_t byte1 = (data & 0x000000000000ff00)>>8;
    uint64_t byte2 = (data & 0x0000000000ff0000)>>16;
    uint64_t byte3 = (data & 0x00000000ff000000)>>24;
    uint64_t byte4 = (data & 0x000000ff00000000)>>32;
    uint64_t byte5 = (data & 0x0000ff0000000000)>>40;
    uint64_t byte6 = (data & 0x00ff000000000000)>>48;
    uint64_t byte7 = (data & 0xff00000000000000)>>56;

    write_vmemory_byte(addr, byte0);
    write_vmemory_byte(addr+1, byte1);
    write_vmemory_byte(addr+2, byte2);
    write_vmemory_byte(addr+3, byte3);
    write_vmemory_byte(addr+4, byte4);
    write_vmemory_byte(addr+5, byte5);
    write_vmemory_byte(addr+6, byte6);
    write_vmemory_byte(addr+7, byte7);
}

void write_vmemory_pages(uint64_t addr, uint8_t* data, size_t size) {
    for(uint64_t i = 0; i < size; i++) {
        write_vmemory_byte(addr+i, data[i]);
    }
}

void read_vmemory_pages(uint64_t addr, uint8_t* buffer, size_t size) {
    for(uint64_t i = 0; i < size; i++) {
        buffer[i] = read_vmemory_byte(addr+i);
    }
}

void print_pages(uint64_t addr, size_t size) {
    for(uint64_t i = 0; i < size; i++) {
        uint8_t byte = read_vmemory_byte(addr+i);
        printf("%c", byte);
    }
    printf("\n\n");
}

void print_string(uint64_t addr) {
    char c;
    while((c = (char)read_vmemory_byte(addr)) != '\0') {
        printf("%c", c);
        addr++;
    }
}