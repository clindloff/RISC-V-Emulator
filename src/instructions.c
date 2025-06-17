#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "util.h"
#include "instructions.h"

/* GLOBAL VARIABLES */
extern uint64_t PC;

void lui(instruction_t* inst) {
    inst->rd_result = inst->imm << 12;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void auipc(instruction_t* inst) {
    inst->rd_result = PC + (inst->imm << 12);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void jal(instruction_t* inst) {
    write_register_int(inst->rd, (register_data_t) (PC+4));
    PC += inst->imm;
}

void jalr(instruction_t* inst) {
    inst->rd_result = PC + 4;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC = inst->imm + inst->rs1_value;
}

void beq(instruction_t* inst) {
    if(inst->rs1_value == inst->rs2_value) {
        PC = PC + inst->imm;
    } else {
        PC += 4;
    }
}

void bne(instruction_t* inst) {
    if(inst->rs1_value != inst->rs2_value) {
        PC = PC + inst->imm;
    } else {
        PC += 4;
    }
} 

void bltu(instruction_t* inst) {
    if(inst->rs1_value < inst->rs2_value) {
        PC = PC + inst->imm;
    } else {
        PC += 4;
    }
}

void bgeu(instruction_t* inst) {
    if(inst->rs1_value >= inst->rs2_value) {
        PC = PC + inst->imm;
    } else {
        PC += 4;
    }
}

void lw(instruction_t* inst) {
    uint64_t addr = inst->imm + inst->rs1_value;
    inst->rd_result = sext(read_vmemory_word(addr), 32);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void lbu(instruction_t* inst) {
    uint64_t addr = inst->imm + inst->rs1_value;
    inst->rd_result = read_vmemory_byte(addr);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void lhu(instruction_t* inst) {
    uint64_t addr = inst->imm + inst->rs1_value;
    inst->rd_result = read_vmemory_halfword(addr);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void sw(instruction_t* inst) {
    uint64_t addr = inst->imm + inst->rs1_value;
    write_vmemory_word(addr, inst->rs2_value);
    PC += 4;
}

void addi(instruction_t* inst) {
    inst->rd_result = inst->rs1_value + inst->imm;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void xori(instruction_t* inst) {
    inst->rd_result = inst->imm ^ inst->rs1_value;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void andi(instruction_t* inst) {
    inst->rd_result = inst->imm & inst->rs1_value;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void slli(instruction_t* inst) {
    inst->rd_result = inst->rs1_value << inst->imm;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void srli(instruction_t* inst) {
    inst->rd_result = inst->rs1_value >> inst->imm;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void add(instruction_t* inst) {
    inst->rd_result = inst->rs1_value + inst->rs2_value;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void sub(instruction_t* inst) {
    inst->rd_result = inst->rs1_value - inst->rs2_value;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void ld(instruction_t* inst) {
    uint64_t addr = inst->imm + inst->rs1_value;
    inst->rd_result = read_vmemory_doubleword(addr);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void sd(instruction_t* inst) {
    uint64_t addr = inst->imm + inst->rs1_value;
    write_vmemory_doubleword(addr, inst->rs2_value);
    PC += 4;
}

void addiw(instruction_t* inst) {
    inst->rd_result = sext((uint32_t) inst->rs1_value + (uint32_t) inst->imm, 32);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void slliw(instruction_t* inst) {
    inst->rd_result = (uint32_t) (inst->rs1_value << inst->imm);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void addw(instruction_t* inst) {
    inst->rd_result = sext(inst->rs1_value + inst->rs2_value, 32);
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void mul(instruction_t* inst) {
    inst->rd_result = inst->rs1_value * inst->rs2_value;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

void divu(instruction_t* inst) {
    inst->rd_result = inst->rs1_value / inst->rs2_value;
    write_register_int(inst->rd, (register_data_t) inst->rd_result);
    PC += 4;
}

