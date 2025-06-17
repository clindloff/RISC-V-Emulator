#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "memory.h"
#include "instructions.h"
#include "util.h"
#include "decode.h"

/* GLOBAL VARIABLES */
extern uint64_t PC;

instruction_t* decode(uint32_t inst_encoding) {
    instruction_t* inst = (instruction_t*) malloc(sizeof(instruction_t));
    inst->full_inst = inst_encoding; 
    inst->addr = PC;
    int opcode = extract(inst_encoding, 6, 0);
    int funct2 = extract(inst_encoding, 26, 25);
    int funct3 = extract(inst_encoding, 14, 12);
    int funct5 = extract(inst_encoding, 31, 27);
    int funct6 = extract(inst_encoding, 31, 26);
    int funct7 = extract(inst_encoding, 31, 25);
    int funct12 = extract(inst_encoding, 31, 20);

    switch(opcode) {
        case RV64_OP_LOAD:
        inst->imm = sext(extract(inst->full_inst, 31, 20), 12);
        inst->rs1 = extract(inst->full_inst, 19, 15);
        inst->rs1_value = read_register_int(inst->rs1).intdouble;
        inst->rd = extract(inst->full_inst, 11, 7);
            switch(funct3) {
                case RV64_FUNCT3_LB:
                    assert(0 && RV64_FUNCT3_LB);
                    break;
                case RV64_FUNCT3_LH:
                    assert(0 && RV64_FUNCT3_LH);
                    break;
                case RV64_FUNCT3_LW:
                    inst->mnemonic = inst_lw;
                    break;
                case RV64_FUNCT3_LBU:
                    inst->mnemonic = inst_lbu;
                    break;
                case RV64_FUNCT3_LHU:
                    inst->mnemonic = inst_lhu;
                    break;
                case RV64_FUNCT3_LWU:
                    assert(0&& RV64_FUNCT3_LWU);
                    break;
                case RV64_FUNCT3_LD:
                    inst->mnemonic = inst_ld;
                    break;
            }
            break;
        case RV64_OP_LOAD_FP:
            switch(funct3) {
                case RV64_FUNCT3_FLW:
                    assert(0 && RV64_FUNCT3_FLW);
                    break;
                case RV64_FUNCT3_FLD:
                    assert(0 && RV64_FUNCT3_FLD);
                    break;
                // case RV64_FUNCT3_FLQ:
                //     assert(0 && RV64_FUNCT3_FLQ);
                //     break;
            }
            break;
        case RV64_OP_MISC_MEM:
            switch(funct3) {
                case RV64_FUNCT3_FENCE:
                    assert(0 && RV64_FUNCT3_FENCE);
                    break;
                case RV64_FUNCT3_FENCEI:
                    assert(0 && RV64_FUNCT3_FENCEI);
                    break;
            }
            break;
        case RV64_OP_OP_IMM:
            switch(funct3) {
                case RV64_FUNCT3_ADDI:
                    inst->mnemonic = inst_addi;
                    inst->imm = sext(extract(inst->full_inst, 31, 20), 12);
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rd = extract(inst->full_inst, 11, 7);
                    break;
                case RV64_FUNCT3_SLTI:
                    assert(0 && RV64_FUNCT3_SLTI);
                    break;
                case RV64_FUNCT3_SLTIU:
                    assert(0 && RV64_FUNCT3_SLTIU);
                    break;
                case RV64_FUNCT3_XORI:
                    inst->mnemonic = inst_xori;
                    inst->imm = sext(extract(inst->full_inst, 31, 20), 12);
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rd = extract(inst->full_inst, 11, 7);
                    break;
                case RV64_FUNCT3_ORI:
                    assert(0 && RV64_FUNCT3_ORI);
                    break;
                case RV64_FUNCT3_ANDI:
                    inst->mnemonic = inst_andi;
                    inst->imm = sext(extract(inst->full_inst, 31, 20), 12);
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rd = extract(inst->full_inst, 11, 7);
                    break;
                case RV64_FUNCT3_SLLI:
                    inst->mnemonic = inst_slli;
                    inst->imm = extract(inst->full_inst, 24, 20);
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rd = extract(inst->full_inst, 11, 7);
                    break;
                case RV64_FUNCT3_SRLI:
                    switch(funct6) {
                        case RV64_SHIFT_IMM_SRLI:
                            inst->mnemonic = inst_srli;
                            inst->imm = extract(inst->full_inst, 24, 20);
                            inst->rs1 = extract(inst->full_inst, 19, 15);
                            inst->rs1_value = read_register_int(inst->rs1).intdouble;
                            inst->rd = extract(inst->full_inst, 11, 7);
                            break;
                        case RV64_SHIFT_IMM_SRAI:
                            assert(0 && RV64_SHIFT_IMM_SRAI);
                            break;
                    }
                    break;
            }
            break;
        case RV64_OP_AUIPC:
            inst->mnemonic = inst_auipc;
            inst->rd = extract(inst->full_inst, 11, 7);
            inst->imm = sext(extract(inst->full_inst, 31, 12), 20);   
            break;
        case RV64_OP_OP_IMM32:
            switch(funct3) {
                case RV64_FUNCT3_ADDIW:
                    inst->mnemonic = inst_addiw;
                    inst->imm = sext(extract(inst->full_inst, 31, 20), 12);
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = sext(read_register_int(inst->rs1).intword, 32);
                    inst->rd = extract(inst->full_inst, 11, 7);
                    break;
                case RV64_FUNCT3_SLLIW:
                    inst->mnemonic = inst_slliw;
                    inst->imm = extract(inst->full_inst, 24, 20);
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = read_register_int(inst->rs1).intword;
                    inst->rd = extract(inst->full_inst, 11, 7);
                    break;
                case RV64_FUNCT3_SRLIW:
                    switch(funct7) {
                        case RV64_FUNCT7_SRLIW:
                            assert(0 && RV64_FUNCT7_SRLIW);
                            break;
                        case RV64_FUNCT7_SRAIW:
                            assert(0 && RV64_FUNCT3_SRAIW);
                            break;
                    }
                    break;
            }
            break;
        case RV64_OP_STORE:
            uint64_t bit11to5 = extract(inst->full_inst, 31, 25) << 5;
            uint64_t bit4to0 = extract(inst->full_inst, 11, 7);
            inst->imm = sext(bit11to5 | bit4to0, 12);
            inst->rs1 = extract(inst->full_inst, 19, 15);
            inst->rs2 = extract(inst->full_inst, 24, 20);
            switch(funct3) {
                case RV64_FUNCT3_SB:
                    assert(0 && RV64_FUNCT3_SB);
                    break;
                case RV64_FUNCT3_SH:
                    assert(0 && RV64_FUNCT3_SH);
                    break;
                case RV64_FUNCT3_SW:
                    inst->mnemonic = inst_sw;
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rs2_value = read_register_int(inst->rs2).intword;
                    break;
                case RV64_FUNCT3_SD:
                    inst->mnemonic = inst_sd;
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rs2_value = read_register_int(inst->rs2).intdouble;
                    break;
            }
            break;
        case RV64_OP_STORE_FP:
            switch(funct3) {
                case RV64_FUNCT3_FSW:
                    assert(0 && RV64_FUNCT3_FSW);
                    break;
                case RV64_FUNCT3_FLD:
                    assert(0 && RV64_FUNCT3_FSD);
                    break;
                // case RV64_FUNCT3_FSQ:
                //     assert(0 && RV64_FUNCT3_FSQ);
                //     break;
            }
            break;
        case RV64_OP_AMO:
            switch(funct3) {
                case RV64_FUNCT3_LRW: // this covers a bunch of them, not just lrw
                    switch(funct5) {
                        case RV64_FUNCT5_LRW:
                            assert(0 && RV64_FUNCT5_LRW);
                            break;
                        case RV64_FUNCT5_SCW:
                            assert(0 && RV64_FUNCT5_SCW);
                            break;
                        case RV64_FUNCT5_AMOSWAPW:
                            assert(0 && RV64_FUNCT5_AMOSWAPW);
                            break;
                        case RV64_FUNCT5_AMOADDW:
                            assert(0 && RV64_FUNCT5_AMOADDW);
                            break;
                        case RV64_FUNCT5_AMOXORW:
                            assert(0 && RV64_FUNCT5_AMOXORW);
                            break;
                        case RV64_FUNCT5_AMOANDW:
                            assert(0 && RV64_FUNCT5_AMOANDW);
                            break;
                        case RV64_FUNCT5_AMOORW:
                            assert(0 && RV64_FUNCT5_AMOORW);
                            break;
                        case RV64_FUNCT5_AMOMINW:
                            assert(0 && RV64_FUNCT5_AMOMINW);
                            break;
                        case RV64_FUNCT5_AMOMAXW:
                            assert(0 && RV64_FUNCT5_AMOMAXW);
                            break;
                        case RV64_FUNCT5_AMOMINUW:
                            assert(0 && RV64_FUNCT5_AMOMINUW);
                            break;
                        case RV64_FUNCT5_AMOMAXUW:
                            assert(0 && RV64_FUNCT5_AMOMAXUW);
                            break;
                    }
                    break;
                case RV64_FUNCT3_LRD: // this covers a bunch of them, not just lrd again
                    switch(funct5) {
                        case RV64_FUNCT5_LRD:
                            assert(0 && RV64_FUNCT5_LRD);
                            break;
                        case RV64_FUNCT5_SCD:
                            assert(0 && RV64_FUNCT5_SCD);
                            break;
                        case RV64_FUNCT5_AMOSWAPD:
                            assert(0 && RV64_FUNCT5_AMOSWAPD);
                            break;
                        case RV64_FUNCT5_AMOADDD:
                            assert(0 && RV64_FUNCT5_AMOADDD);
                            break;
                        case RV64_FUNCT5_AMOXORD:
                            assert(0 && RV64_FUNCT5_AMOXORD);
                            break;
                        case RV64_FUNCT5_AMOANDD:
                            assert(0 && RV64_FUNCT5_AMOANDD);
                            break;
                        case RV64_FUNCT5_AMOORD:
                            assert(0 && RV64_FUNCT5_AMOORD);
                            break;
                        case RV64_FUNCT5_AMOMIND:
                            assert(0 && RV64_FUNCT5_AMOMIND);
                            break;
                        case RV64_FUNCT5_AMOMAXD:
                            assert(0 && RV64_FUNCT5_AMOMAXD);
                            break;
                        case RV64_FUNCT5_AMOMINUD:
                            assert(0 && RV64_FUNCT5_AMOMINUD);
                            break;
                        case RV64_FUNCT5_AMOMAXUD:
                            assert(0 && RV64_FUNCT5_AMOMAXUD);
                            break;
                    }
                    break;
            }
            break;
        case RV64_OP_OP:
            switch(funct3) {
                case RV64_FUNCT3_ADD: // this covers: add, sub, mul
                    inst->rs2 = extract(inst->full_inst, 24, 20);
                    inst->rs2_value = read_register_int(inst->rs2).intdouble;
                    inst->rs1 = extract(inst->full_inst, 19, 15);
                    inst->rs1_value = read_register_int(inst->rs1).intdouble;
                    inst->rd = extract(inst->full_inst, 11, 7);
                    switch(funct7) {
                        case RV64_FUNCT7_ADD:
                            inst->mnemonic = inst_add;
                            break;
                        case RV64_FUNCT7_SUB:
                            inst->mnemonic = inst_sub;
                            break;
                        case RV64_FUNCT7_MUL:
                            inst->mnemonic = inst_mul;
                            break;
                    }
                    break;
                case RV64_FUNCT3_SLL: // this covers: sll, mulh
                    switch(funct7) {
                        case RV64_FUNCT7_SLL:
                            assert(0 && RV64_FUNCT7_SLL);
                            break;
                        case RV64_FUNCT7_MULH:
                            assert(0 && RV64_FUNCT7_MULH);
                            break;
                    }
                    break;
                case RV64_FUNCT3_SLT: // this covers: slt, mulhsu
                    switch(funct7) {
                        case RV64_FUNCT7_SLT:
                            assert(0 && RV64_FUNCT7_SLT);
                            break;
                        case RV64_FUNCT7_MULHSU:
                            assert(0 && RV64_FUNCT7_MULHSU);
                            break;
                    }
                    break;
                case RV64_FUNCT3_SLTU: // this covers: sltu, mulhu
                    switch(funct7) {
                        case RV64_FUNCT7_SLTU:
                            assert(0 && RV64_FUNCT7_SLTU);
                            break;
                        case RV64_FUNCT7_MULHU:
                            assert(0 && RV64_FUNCT7_MULHU);
                            break;
                    }
                    break;
                case RV64_FUNCT3_XOR: // this covers: xor, div
                    switch(funct7) {
                        case RV64_FUNCT7_XOR:
                            assert(0 && RV64_FUNCT7_XOR);
                            break;
                        case RV64_FUNCT7_DIV:
                            assert(0 && RV64_FUNCT7_DIV);
                            break;
                    }
                    break;
                case RV64_FUNCT3_SRL: // this covers: srl, sra, divu
                    switch(funct7) {
                        case RV64_FUNCT7_SRL:
                            assert(0 && RV64_FUNCT7_SRL);
                            break;
                        case RV64_FUNCT7_SRA:
                            assert(0 && RV64_FUNCT7_SRA);
                            break;
                        case RV64_FUNCT7_DIVU:
                            inst->mnemonic = inst_divu;
                            inst->rs2 = extract(inst->full_inst, 24, 20);
                            inst->rs2_value = read_register_int(inst->rs2).intdouble;
                            inst->rs1 = extract(inst->full_inst, 19, 15);
                            inst->rs1_value = read_register_int(inst->rs1).intdouble;
                            inst->rd = extract(inst->full_inst, 11, 7);
                            break;                        
                    }
                    break;
                case RV64_FUNCT3_OR: // this covers: or, rem
                    switch(funct7) {
                        case RV64_FUNCT7_OR:
                            assert(0 && RV64_FUNCT7_OR);
                            break;
                        case RV64_FUNCT7_REM:
                            assert(0 && RV64_FUNCT7_REM);
                            break;
                    }
                    break;
                case RV64_FUNCT3_AND: // this covers: and, remu
                    switch(funct7) {
                        case RV64_FUNCT7_AND:
                            assert(0 && RV64_FUNCT7_AND);
                            break;
                        case RV64_FUNCT7_REMU:
                            assert(0 && RV64_FUNCT7_REMU);
                            break;
                    }
                    break;
            }
            break;
        case RV64_OP_LUI:
            inst->mnemonic = inst_lui;
            inst->imm = extract(inst->full_inst, 31, 12);
            inst->rd = extract(inst->full_inst, 11, 7);
            break;
        case RV64_OP_OP32:
            switch(funct3) {
                case RV64_FUNCT3_ADDW: // this covers: addw, subw, mulw
                    switch(funct7) {
                        case RV64_FUNCT7_ADDW:
                            inst->mnemonic = inst_addw;
                            inst->rs2 = extract(inst->full_inst, 24, 20);
                            inst->rs2_value = read_register_int(inst->rs2).intword;
                            inst->rs1 = extract(inst->full_inst, 19, 15);
                            inst->rs1_value = read_register_int(inst->rs1).intword;
                            inst->rd = extract(inst->full_inst, 11, 7);
                            break;
                        case RV64_FUNCT7_SUBW:
                            assert(0 && RV64_FUNCT7_SUBW);
                            break;
                        case RV64_FUNCT7_MULW:
                            assert(0 && RV64_FUNCT7_MULW);
                            break;
                    }
                    break;
                case RV64_FUNCT3_SLLW:
                    assert(0 && RV64_FUNCT3_SLLW);
                    break;
                case RV64_FUNCT3_DIVW:
                    assert(0 && RV64_FUNCT3_DIVW);
                    break;
                case RV64_FUNCT3_SRLW: // this covers: srlw, sraw, divuw
                    switch(funct7) {
                        case RV64_FUNCT7_SRLW:
                            assert(0 && RV64_FUNCT7_SRLW);
                            break;
                        case RV64_FUNCT7_SRAW:
                            assert(0 && RV64_FUNCT7_SRAW);
                            break;
                        case RV64_FUNCT7_DIVUW:
                            assert(0 && RV64_FUNCT7_DIVUW);
                            break;
                    }
                    break;
                case RV64_FUNCT3_REMW:
                    assert(0 && RV64_FUNCT3_REMW);
                    break;
                case RV64_FUNCT3_REMUW:
                    assert(0 && RV64_FUNCT7_REMUW);
                    break;
            }
            break;
        case RV64_OP_MADD:
            switch(funct2) {
                case RV64_FUNCT2_FMADDS:
                    assert(0 && RV64_FUNCT2_FMADDS);
                    break;
                case RV64_FUNCT2_FMADDD:
                    assert(0 && RV64_FUNCT2_FMADDD);
                    break;
                // case RV64_FUNCT2_FMADDQ:
                //     assert(0 && RV64_FUNCT2_FMADDQ);
                //     break;
            }
            break;
        case RV64_OP_MSUB:
            switch(funct2) {
                case RV64_FUNCT2_FMSUBS:
                    assert(0 && RV64_FUNCT2_FMSUBS);
                    break;
                case RV64_FUNCT2_FMSUBD:
                    assert(0 && RV64_FUNCT2_FMSUBD);
                    break;
                // case RV64_FUNCT2_FMSUBQ:
                //     assert(0 && RV64_FUNCT2_FMSUBQ);
                //     break;
            }
            break;
        case RV64_OP_NMSUB:
            switch(funct2) {
                case RV64_FUNCT2_FNMSUBS:
                    assert(0 && RV64_FUNCT2_FNMSUBS);
                    break;
                case RV64_FUNCT2_FNMSUBD:
                    assert(0 && RV64_FUNCT2_FNMSUBD);
                    break;
                // case RV64_FUNCT2_FNMSUBQ:
                //     assert(0 && RV64_FUNCT2_FNMSUBQ);
                //     break;
            }
            break;
        case RV64_OP_NMADD:
            switch(funct2) {
                case RV64_FUNCT2_FNMADDS:
                    assert(0 && RV64_FUNCT2_FNMADDS);
                    break;
                case RV64_FUNCT2_FNMADDD:
                    assert(0 && RV64_FUNCT2_FNMADDD);
                    break;
                // case RV64_FUNCT2_FNMADDQ:
                //     assert(0 && RV64_FUNCT2_FNMADDQ);
                //     break;
            }
            break;
        case RV64_OP_FP:
            /* Bunch of instructions... I'll do it later */
            assert(0 && RV64_OP_FP);
            break;
        case RV64_OP_BRANCH:
            inst->imm = sext((extract(inst->full_inst, 31, 31) << 12) | // bit 12
                             (extract(inst->full_inst, 7, 7) << 11)   | // bit 11
                             (extract(inst->full_inst, 30, 25) << 5)  | // bit 10-5
                             (extract(inst->full_inst, 11, 8) << 1),    // bit 4-0 
                                                                   13); // 13 bit value                    
            inst->rs2 = extract(inst->full_inst, 24, 20);
            inst->rs2_value = read_register_int(inst->rs2).intdouble;
            inst->rs1 = extract(inst->full_inst, 19, 15);
            inst->rs1_value = read_register_int(inst->rs1).intdouble;
            switch(funct3) {
                case RV64_FUNCT3_BEQ:
                    inst->mnemonic = inst_beq;
                    break;
                case RV64_FUNCT3_BNE:
                    inst->mnemonic = inst_bne;
                    break;
                case RV64_FUNCT3_BLT:
                    assert(0 && RV64_FUNCT3_BLT);
                    break;
                case RV64_FUNCT3_BGE:
                    assert(0 && RV64_FUNCT3_BGE);
                    break;
                case RV64_FUNCT3_BLTU:
                    inst->mnemonic = inst_bne;
                    break;
                case RV64_FUNCT3_BGEU:
                    inst->mnemonic = inst_bgeu;
                    break;
            }
            break;
        case RV64_OP_JALR:
            inst->mnemonic = inst_jalr;
            inst->imm = extract(inst->full_inst, 31, 20);
            inst->rs1 = extract(inst->full_inst, 19, 15);
            inst->rs1_value = read_register_int(inst->rs1).intdouble;
            inst->rd = extract(inst->full_inst, 11, 7);
            break;
        case RV64_OP_JAL:
            inst->mnemonic = inst_jal;
            inst->rd = extract(inst->full_inst, 11, 7);
            uint64_t imm = extract(inst->full_inst, 31, 12);   
            uint64_t bit20 =     (imm & 0x80000) >> 0;  // 1000 0000 0000 0000 0000 -> 1000 0000 0000 0000 0000
            uint64_t bit10to1 =  (imm & 0x7fe00) >> 9;  // 0111 1111 1110 0000 0000 -> 0000 0000 0011 1111 1111
            uint64_t bit11 =     (imm & 0x00100) << 2;  // 0000 0000 0001 0000 0000 -> 0000 0000 0100 0000 0000
            uint64_t bit19to12 = (imm & 0x000ff) << 11; // 0000 0000 0000 1111 1111 -> 0111 1111 1000 0000 0000            
            imm = (bit20 | bit10to1 | bit11 | bit19to12) << 1;
            inst->imm = sext(imm, 21);
            break;
        case RV64_OP_SYSTEM:
            switch(funct3) {
                case RV64_FUNCT3_ECALL: // this covers: ecall, ebreak
                    switch(funct12) {
                        case RV64_FUNCT12_ECALL:
                            inst->mnemonic = inst_ecall;
                            break;
                        case RV64_FUNCT12_EBREAK:
                            assert(0 && RV64_FUNCT12_EBREAK);
                    }
                    break;
                case RV64_FUNCT3_CSRRW:
                    assert(0 && RV64_FUNCT3_CSRRW);
                    break;
                case RV64_FUNCT3_CSRRS:
                    assert(0 && RV64_FUNCT3_CSRRS);
                    break;
                case RV64_FUNCT3_CSRRC:
                    assert(0 && RV64_FUNCT3_CSRRC);
                    break;
                case RV64_FUNCT3_CSRRWI:
                    assert(0 && RV64_FUNCT3_CSRRWI);
                    break;
                case RV64_FUNCT3_CSRRSI:
                    assert(0 && RV64_FUNCT3_CSRRSI);
                    break;
                case RV64_FUNCT3_CSRRCI:
                    assert(0 && RV64_FUNCT3_CSRRCI);
                    break;
            }
            break;
        default:
            printf("PANIC THIS WAS NOT SUPPOSED TO HAPPEN! AHHHHHHH!!!!\n");

    }

    return inst;
}
