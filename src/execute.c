#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "instructions.h"
#include "syscalls.h"
#include "execute.h"

void execute(instruction_t* inst) {
    switch (inst->mnemonic) {
        /* RV32I */
        case inst_lui:
            lui(inst);
            break;
        case inst_auipc:
            auipc(inst);
            break;
        case inst_jal:
            jal(inst);
            break;
        case inst_jalr:
            jalr(inst);
            break;
        case inst_beq:
            beq(inst);
            break;
        case inst_bne:
            bne(inst);
            break;
        case inst_blt:
            
            break;
        case inst_bge:
            
            break;
        case inst_bltu:
            bltu(inst);
            break;
        case inst_bgeu:
            bgeu(inst);
            break;
        case inst_lb:
            
            break;
        case inst_lh:
            
            break;
        case inst_lw:
            lw(inst);
            break;
        case inst_lbu:
            lbu(inst);
            break;
        case inst_lhu:
            lhu(inst);
            break;
        case inst_sb:
            
            break;
        case inst_sh:
            
            break;
        case inst_sw:
            sw(inst);
            break;
        case inst_addi:
            addi(inst);
            break;
        case inst_slti:
            
            break;
        case inst_sltiu:
            
            break;
        case inst_xori:
            xori(inst);
            break;
        case inst_ori:
            
            break;
        case inst_andi:
            andi(inst);
            break;
        case inst_slli:
            slli(inst);
            break;
        case inst_srli:
            srli(inst);
            break;
        case inst_srai:
            
            break;
        case inst_add:
            add(inst);
            break;
        case inst_sub:
            sub(inst);
            break;
        case inst_sll:
            
            break;
        case inst_slt:
            
            break;
        case inst_sltu:
            
            break;
        case inst_xor:
            
            break;
        case inst_srl:
            
            break;
        case inst_sra:
            
            break;
        case inst_or:
            
            break;
        case inst_and:
            
            break;
        case inst_fence:
            
            break;
        case inst_ecall:
            syscall(read_register_int(17).intdouble);
            break;
        case inst_ebreak:
            
            break;
        /* RV64I */
        case inst_lwu:
            
            break;
        case inst_ld:
            ld(inst);
            break;
        case inst_sd:
            sd(inst);
            break;
        case inst_addiw:
            addiw(inst);
            break;
        case inst_slliw:
            slliw(inst);
            break;
        case inst_srliw:
            
            break;
        case inst_sraiw:
            
            break;
        case inst_addw:
            addw(inst);
            break;
        case inst_subw:
            
            break;
        case inst_sllw:
            
            break;
        case inst_srlw:
            
            break;
        case inst_sraw:
            
            break;
        /* RV64 Zifencei */
        case inst_fencei:
            
            break;
        /* RV64 Zicsr */
        case inst_csrrw:
            
            break;
        case inst_csrrs:
            
            break;
        case inst_csrrc:
            
            break;
        case inst_csrrwi:
            
            break;
        case inst_csrrsi:
            
            break;
        case inst_csrrci:
            
            break;
        /* RV32M */
        case inst_mul:
            mul(inst);
            break;
        case inst_mulh:
            
            break;
        case inst_mulhsu:
            
            break;
        case inst_mulhu:
            
            break;
        case inst_div:
            
            break;
        case inst_divu:
            divu(inst);
            break;
        case inst_rem:
            
            break;
        case inst_remu:
            
            break;
        /* RV64M */
        case inst_mulw:
            
            break;
        case inst_divw:
            
            break;
        case inst_divuw:
            
            break;
        case inst_remw:
            
            break;
        case inst_remuw:
            
            break;
        /* RV32A */
        case inst_lrw:
            
            break;
        case inst_scw:
            
            break;
        case inst_amoswapw:
            
            break;
        case inst_amoaddw:
            
            break;
        case inst_amoxorw:
            
            break;
        case inst_amoandw:
            
            break;
        case inst_amoorw:
            
            break;
        case inst_amominw:
            
            break;
        case inst_amomaxw:
            
            break;
        case inst_amominuw:
            
            break;
        case inst_amomaxuw:
            
            break;
        /* RV64A */
        case inst_lrd:
            
            break;
        case inst_scd:
            
            break;
        case inst_amoswapd:
            
            break;
        case inst_amoaddd:
            
            break;
        case inst_amoxord:
            
            break;
        case inst_amoandd:
            
            break;
        case inst_amoord:
            
            break;
        case inst_amomind:
            
            break;
        case inst_amomaxd:
            
            break;
        case inst_amominud:
            
            break;
        case inst_amomaxud:
            
            break;
        /* RV32F */
        case inst_flw:
            
            break;
        case inst_fsw:
            
            break;
        case inst_fmadds:
            
            break;
        case inst_fmsubs:
            
            break;
        case inst_fnmsubs:
            
            break;
        case inst_fnmadds:
            
            break;
        case inst_fadds:
            
            break;
        case inst_fsubs:
            
            break;
        case inst_fmuls:
            
            break;
        case inst_fdivs:
            
            break;
        case inst_fsqrts:
            
            break;
        case inst_fsgnjs:
            
            break;
        case inst_fsgnjns:
            
            break;
        case inst_fsgnjxs:
            
            break;
        case inst_fmins:
            
            break;
        case inst_fmaxs:
            
            break;
        case inst_fcvtws:
            
            break;
        case inst_fcvtwus:
            
            break;
        case inst_fmvxw:
            
            break;
        case inst_feqs:
            
            break;
        case inst_flts:
            
            break;
        case inst_fles:
            
            break;
        case inst_fclasss:
            
            break;
        case inst_fcvtsw:
            
            break;
        case inst_fcvtswu:
            
            break;
        case inst_fmvwx:
            
            break;
        /* RV64F */
        case inst_fcvtls:
            
            break;
        case inst_fcvtlus:
            
            break;
        case inst_fcvtsl:
            
            break;
        case inst_fcvtslu:
            
            break;
        /* RV32D */
        case inst_fld:
            
            break;
        case inst_fsd:
            
            break;
        case inst_fmaddd:
            
            break;
        case inst_fmsubd:
            
            break;
        case inst_fnmsubd:
            
            break;
        case inst_fnmaddd:
            
            break;
        case inst_faddd:
            
            break;
        case inst_fsubd:
            
            break;
        case inst_fmuld:
            
            break;
        case inst_fdivd:
            
            break;
        case inst_fsqrtd:
            
            break;
        case inst_fsgnjd:
            
            break;
        case inst_fsgnjnd:
            
            break;
        case inst_fsgnjxd:
            
            break;
        case inst_fmind:
            
            break;
        case inst_fmaxd:
            
            break;
        case inst_fcvtsd:
            
            break;
        case inst_fcvtds:
            
            break;
        case inst_feqd:
            
            break;
        case inst_fltd:
            
            break;
        case inst_fled:
            
            break;
        case inst_fclassd:
            
            break;
        case inst_fcvtwd:
            
            break;
        case inst_fcvtwud:
            
            break;
        case inst_fcvtdw:
            
            break;
        case inst_fcvtdwu:
            
            break;
        /* RV64D */
        case inst_fcvtld:
            
            break;
        case inst_fcvtlud:
            
            break;
        case inst_fmvxd:
            
            break;
        case inst_fcvtdl:
            
            break;
        case inst_fcvtdlu:
            
            break;
        case inst_fmvdx:
            
            break;
        default:
            break;
    }

    print_instruction(inst);
}

void print_instruction(instruction_t* inst) {
    switch (inst->mnemonic) {
        /* RV32I */
        case inst_lui:
            printf("\t%lx:\t%.8x\tlui r%d<-[0x%lx], 0x%lx\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm);
            break;
        case inst_auipc:
            printf("\t%lx:\t%.8x\tauipc r%d<-[0x%lx], 0x%lx\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm);    
            break;
        case inst_jal:
            printf("\t%lx:\t%.8x\tjal %lx\n", inst->addr, inst->full_inst, inst->imm + inst->addr);
            break;
        case inst_jalr:
            printf("\t%lx:\t%.8x\tjalr r%d<-[0x%lx], %lx\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm + inst->rs1_value);
            break;
        case inst_beq:
            printf("\t%lx:\t%.8x\tbeq r%d[0x%lx], r%d[0x%lx], %lx\n", inst->addr, inst->full_inst, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value, inst->imm + inst->addr);
            break;
        case inst_bne:
            printf("\t%lx:\t%.8x\tbne r%d[0x%lx], r%d[0x%lx], %lx\n", inst->addr, inst->full_inst, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value, inst->imm + inst->addr);
            break;
        case inst_blt:
            
            break;
        case inst_bge:
            
            break;
        case inst_bltu:
            printf("\t%lx:\t%.8x\tbltu r%d[0x%lx], r%d[0x%lx], %lx\n", inst->addr, inst->full_inst, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value, inst->imm + inst->addr);
            break;
        case inst_bgeu:
            printf("\t%lx:\t%.8x\tbgeu r%d[0x%lx], r%d[0x%lx], %lx\n", inst->addr, inst->full_inst, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value, inst->imm + inst->addr);
            break;
        case inst_lb:
            
            break;
        case inst_lh:
            
            break;
        case inst_lw:
            printf("\t%lx:\t%.8x\tlw r%d<-[%ld], %ld(r%d[0x%lx])\n", 
            inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm, inst->rs1, inst->rs1_value);
            break;
        case inst_lbu:
            printf("\t%lx:\t%.8x\tlbu r%d<-[%ld], %ld(r%d[0x%lx])\n", 
            inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm, inst->rs1, inst->rs1_value);
            break;
        case inst_lhu:
            printf("\t%lx:\t%.8x\tlhu r%d<-[%ld], %ld(r%d[0x%lx])\n", 
            inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm, inst->rs1, inst->rs1_value);
            break;
        case inst_sb:
            
            break;
        case inst_sh:
            
            break;
        case inst_sw:
            printf("\t%lx:\t%.8x\tsw r%d[0x%lx], %ld(r%d[0x%lx])\n", 
            inst->addr, inst->full_inst, inst->rs2, inst->rs2_value, inst->imm, inst->rs1, inst->rs1_value);
            break;
        case inst_addi:
            printf("\t%lx:\t%.8x\taddi r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, (int64_t) inst->imm);
            break;
        case inst_slti:
            
            break;
        case inst_sltiu:
            
            break;
        case inst_xori:
            printf("\t%lx:\t%.8x\txori r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, (int64_t) inst->imm);
            break;
        case inst_ori:
            
            break;
        case inst_andi:
            printf("\t%lx:\t%.8x\tandi r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, (int64_t) inst->imm);
            break;
        case inst_slli:
            printf("\t%lx:\t%.8x\tslli r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, (int64_t) inst->imm);
            break;
        case inst_srli:
            printf("\t%lx:\t%.8x\tsrli r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, (int64_t) inst->imm);
            break;
        case inst_srai:
            
            break;
        case inst_add:
            printf("\t%lx:\t%.8x\tadd r%d<-[0x%lx], r%d[0x%lx], r%d[0x%lx]\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs2, inst->rs2_value, inst->rs1, inst->rs1_value);
            break;
        case inst_sub:
            printf("\t%lx:\t%.8x\tsub r%d<-[0x%lx], r%d[0x%lx], r%d[0x%lx]\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value);
            break;
        case inst_sll:
            
            break;
        case inst_slt:
            
            break;
        case inst_sltu:
            
            break;
        case inst_xor:
            
            break;
        case inst_srl:
            
            break;
        case inst_sra:
            
            break;
        case inst_or:
            
            break;
        case inst_and:
            
            break;
        case inst_fence:
            
            break;
        case inst_ecall:
            printf("\t%lx:\t%.8x\tecall\n", inst->addr, inst->full_inst);
            break;
        case inst_ebreak:
            
            break;
        /* RV64I */
        case inst_lwu:
            
            break;
        case inst_ld:
            printf("\t%lx:\t%.8x\tld r%d<-[%ld], %ld(r%d[0x%lx])\n", 
            inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->imm, inst->rs1, inst->rs1_value);
            break;
        case inst_sd:
            printf("\t%lx:\t%.8x\tsd r%d[0x%lx], %ld(r%d[0x%lx])\n", 
            inst->addr, inst->full_inst, inst->rs2, inst->rs2_value, inst->imm, inst->rs1, inst->rs1_value);
            break;
        case inst_addiw:
            printf("\t%lx:\t%.8x\taddiw r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, inst->imm);
            break;
        case inst_slliw:
            printf("\t%lx:\t%.8x\tslliw r%d<-[0x%lx], r%d[0x%lx], %ld\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, inst->imm);
            break;
        case inst_srliw:
            
            break;
        case inst_sraiw:
            
            break;
        case inst_addw:
            printf("\t%lx:\t%.8x\taddw r%d<-[0x%lx], r%d[0x%lx], r%d[[0x%lx]\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value);
            break;
        case inst_subw:
            
            break;
        case inst_sllw:
            
            break;
        case inst_srlw:
            
            break;
        case inst_sraw:
            
            break;
        /* RV64 Zifencei */
        case inst_fencei:
            
            break;
        /* RV64 Zicsr */
        case inst_csrrw:
            
            break;
        case inst_csrrs:
            
            break;
        case inst_csrrc:
            
            break;
        case inst_csrrwi:
            
            break;
        case inst_csrrsi:
            
            break;
        case inst_csrrci:
            
            break;
        /* RV32M */
        case inst_mul:
            printf("\t%lx:\t%.8x\tmul r%d<-[0x%lx], r%d[0x%lx], r%d[0x%lx]\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs2, inst->rs2_value, inst->rs1, inst->rs1_value);
            break;
        case inst_mulh:
            
            break;
        case inst_mulhsu:
            
            break;
        case inst_mulhu:
            
            break;
        case inst_div:
            
            break;
        case inst_divu:
            printf("\t%lx:\t%.8x\tdivu r%d<-[0x%lx], r%d[0x%lx], r%d[0x%lx]\n", inst->addr, inst->full_inst, inst->rd, inst->rd_result, inst->rs1, inst->rs1_value, inst->rs2, inst->rs2_value);
            break;
        case inst_rem:
            
            break;
        case inst_remu:
            
            break;
        /* RV64M */
        case inst_mulw:
            
            break;
        case inst_divw:
            
            break;
        case inst_divuw:
            
            break;
        case inst_remw:
            
            break;
        case inst_remuw:
            
            break;
        /* RV32A */
        case inst_lrw:
            
            break;
        case inst_scw:
            
            break;
        case inst_amoswapw:
            
            break;
        case inst_amoaddw:
            
            break;
        case inst_amoxorw:
            
            break;
        case inst_amoandw:
            
            break;
        case inst_amoorw:
            
            break;
        case inst_amominw:
            
            break;
        case inst_amomaxw:
            
            break;
        case inst_amominuw:
            
            break;
        case inst_amomaxuw:
            
            break;
        /* RV64A */
        case inst_lrd:
            
            break;
        case inst_scd:
            
            break;
        case inst_amoswapd:
            
            break;
        case inst_amoaddd:
            
            break;
        case inst_amoxord:
            
            break;
        case inst_amoandd:
            
            break;
        case inst_amoord:
            
            break;
        case inst_amomind:
            
            break;
        case inst_amomaxd:
            
            break;
        case inst_amominud:
            
            break;
        case inst_amomaxud:
            
            break;
        /* RV32F */
        case inst_flw:
            
            break;
        case inst_fsw:
            
            break;
        case inst_fmadds:
            
            break;
        case inst_fmsubs:
            
            break;
        case inst_fnmsubs:
            
            break;
        case inst_fnmadds:
            
            break;
        case inst_fadds:
            
            break;
        case inst_fsubs:
            
            break;
        case inst_fmuls:
            
            break;
        case inst_fdivs:
            
            break;
        case inst_fsqrts:
            
            break;
        case inst_fsgnjs:
            
            break;
        case inst_fsgnjns:
            
            break;
        case inst_fsgnjxs:
            
            break;
        case inst_fmins:
            
            break;
        case inst_fmaxs:
            
            break;
        case inst_fcvtws:
            
            break;
        case inst_fcvtwus:
            
            break;
        case inst_fmvxw:
            
            break;
        case inst_feqs:
            
            break;
        case inst_flts:
            
            break;
        case inst_fles:
            
            break;
        case inst_fclasss:
            
            break;
        case inst_fcvtsw:
            
            break;
        case inst_fcvtswu:
            
            break;
        case inst_fmvwx:
            
            break;
        /* RV64F */
        case inst_fcvtls:
            
            break;
        case inst_fcvtlus:
            
            break;
        case inst_fcvtsl:
            
            break;
        case inst_fcvtslu:
            
            break;
        /* RV32D */
        case inst_fld:
            
            break;
        case inst_fsd:
            
            break;
        case inst_fmaddd:
            
            break;
        case inst_fmsubd:
            
            break;
        case inst_fnmsubd:
            
            break;
        case inst_fnmaddd:
            
            break;
        case inst_faddd:
            
            break;
        case inst_fsubd:
            
            break;
        case inst_fmuld:
            
            break;
        case inst_fdivd:
            
            break;
        case inst_fsqrtd:
            
            break;
        case inst_fsgnjd:
            
            break;
        case inst_fsgnjnd:
            
            break;
        case inst_fsgnjxd:
            
            break;
        case inst_fmind:
            
            break;
        case inst_fmaxd:
            
            break;
        case inst_fcvtsd:
            
            break;
        case inst_fcvtds:
            
            break;
        case inst_feqd:
            
            break;
        case inst_fltd:
            
            break;
        case inst_fled:
            
            break;
        case inst_fclassd:
            
            break;
        case inst_fcvtwd:
            
            break;
        case inst_fcvtwud:
            
            break;
        case inst_fcvtdw:
            
            break;
        case inst_fcvtdwu:
            
            break;
        /* RV64D */
        case inst_fcvtld:
            
            break;
        case inst_fcvtlud:
            
            break;
        case inst_fmvxd:
            
            break;
        case inst_fcvtdl:
            
            break;
        case inst_fcvtdlu:
            
            break;
        case inst_fmvdx:
            
            break;
        default:
            printf("ERROR: Instruction mnemonic not found...\n");
            break;
    }
}