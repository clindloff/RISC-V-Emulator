#ifndef _MEMORY_H_
#define _MEMORY_H_

/* DEFINES */

/* STRUCTURES */

/* 
 * Union for register data values
 */
typedef union register_data_type {
    uint32_t intword;
    uint64_t intdouble;
    float fpsingle;
    double fpdouble;
} register_data_t;

/* FUNCTION DEFINITIONS */

/*
 * Functions to utilize the register files
 * One for integers and another for float,
 * and another to initilize register zero
 */
void register_init();
register_data_t read_register_int(uint32_t);
void write_register_int(uint32_t, register_data_t);
register_data_t read_register_float(uint32_t);
void write_register_float(uint32_t, register_data_t);

/*
 * Functions to read and write from memory in
 * various sizes
 */
uint8_t     read_vmemory_byte(uint64_t);
void        write_vmemory_byte(uint64_t, uint8_t);
uint16_t    read_vmemory_halfword(uint64_t);
void        write_vmemory_halfword(uint64_t, uint16_t);
uint32_t    read_vmemory_word(uint64_t);
void        write_vmemory_word(uint64_t, uint32_t);
uint64_t    read_vmemory_doubleword(uint64_t);
void        write_vmemory_doubleword(uint64_t, uint64_t);

void        read_vmemory_pages(uint64_t, uint8_t* , size_t);
void        write_vmemory_pages(uint64_t, uint8_t*, size_t);

void print_pages(uint64_t, size_t);

void print_string(uint64_t);


#endif