#ifndef _INSTRUCTIONS_H_
#define _INSTRUCTIONS_H_

#include "rv64_opcodes.h"

/* DEFINES */

/* STRUCTURES */

typedef struct instruction_type {
    uint32_t full_inst;
    sane_mnemonics_t mnemonic;
    uint64_t addr;

    uint8_t rd; 
    uint8_t rs1;
    uint8_t rs2;

    uint64_t rd_result;
    uint64_t rs1_value;
    uint64_t rs2_value;
    uint64_t imm;
} instruction_t;

/* FUNCTION DEFINITIONS */

// Helper functions for each encountered instruction type
void lui(instruction_t*);
void auipc(instruction_t*);
void jal(instruction_t*);
void jalr(instruction_t*);
void beq(instruction_t*);
void bne(instruction_t*);
void bltu(instruction_t*);
void bgeu(instruction_t*);
void lw(instruction_t*);
void lbu(instruction_t*);
void lhu(instruction_t*);
void sw(instruction_t*);
void addi(instruction_t*);
void xori(instruction_t*);
void andi(instruction_t*);
void slli(instruction_t*);
void srli(instruction_t*);
void add(instruction_t*);
void sub(instruction_t*);
void ld(instruction_t*);
void sd(instruction_t*);
void addiw(instruction_t*);
void slliw(instruction_t*);
void addw(instruction_t*);
void mul(instruction_t*);
void divu(instruction_t*);


#endif