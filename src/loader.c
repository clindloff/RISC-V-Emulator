#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include "memory.h"
#include "loader.h"

/* GLOBAL VARIABLES */
int fd_elf;
Elf64_Ehdr* header;
extern uint64_t PC;

int loader_init(char* filename, char** envp) {
    int result = -1;

    int fd_input = open(filename, O_RDONLY);
    if(fd_elf == -1) {
        perror("Error opening input text: ");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int bytes = read(fd_input, &buffer, 1024);
    if(bytes == -1) {
        perror("Error reading input text: ");
        return EXIT_FAILURE;
    }

    int argc = 0;
    char** argv;
    char* token;
    char* delim = " \n";

    char str[bytes];
    strcpy(str, buffer);
    token = strtok(str, delim);
    while(token != NULL) {
        argc++;
        token = strtok(NULL, delim);
    }

    argv = (char**) malloc(argc * sizeof(char*));
    strcpy(str, buffer);
    token = strtok(str, delim);
    for(int i = 0; token != NULL; i++) {
        argv[i] = (char*) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(argv[i], token);

        token = strtok(NULL, delim);
    }

    /* Print out argc and argv read from input file */    
    // printf("argc: %d\n", argc);
    // for(int i =  0; i < argc; i++) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    result = open_elf(argv[0]);
    if(result == EXIT_FAILURE) {
        printf("Aw man this shit blows...\n");
        return EXIT_FAILURE;
    }

    result = read_ph();
    if(result == EXIT_FAILURE) {
        printf("shucks...\n");
        return EXIT_FAILURE;
    }

    result = stack_init(argc, argv, envp);
    if(result == EXIT_FAILURE) {
        printf("the stack fell apart...\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int open_elf(char* filename) {
    header = (Elf64_Ehdr*) malloc(sizeof(Elf64_Ehdr));

    fd_elf = open(filename, O_RDONLY);
    if(fd_elf == -1) {
        perror("Error opening ELF File: ");
        return EXIT_FAILURE;
    }

    int bytes = read(fd_elf, header, sizeof(Elf64_Ehdr));
    if(bytes == -1) {
        perror("Error reading ELF Header: ");
        return EXIT_FAILURE;
    }

    if(header->e_ident[EI_MAG0] != ELFMAG0 ||
       header->e_ident[EI_MAG1] != ELFMAG1 ||
       header->e_ident[EI_MAG2] != ELFMAG2 || 
       header->e_ident[EI_MAG3] != ELFMAG3 ) {
        printf("Not an ELF file\n");
        return EXIT_FAILURE;
    }

    if(header->e_ident[EI_DATA] != ELFDATA2LSB) {
        printf("ELF file not little-endian\n");
        return EXIT_FAILURE;
    }

    if(header->e_type != ET_EXEC) {
        printf("ELF file is not an executable\n");
        return EXIT_FAILURE;
    }

    if(header->e_machine != EM_RISCV) {
        printf("ELF file is not RISC-V architecture\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int read_ph() {
    
    int32_t result = lseek(fd_elf, header->e_phoff, SEEK_SET);
    if(result == -1) {
        printf("lseek failed somehow\n");
        return -1;
    }

    Elf64_Phdr* pheaders = malloc(header->e_phentsize * header->e_phnum);
    if(pheaders == NULL) {
        printf("malloc failed somehow\n");
        return -1;
    }
    int64_t bytes = read(fd_elf, pheaders, header->e_phentsize * header->e_phnum);
    if(bytes == -1) {
        printf("Read failed somehow\n");
        return -1;
    }

    // printf("PT_LOAD: 0x%x\n", PT_LOAD);
    // printf("PT_NOTE: 0x%x\n", PT_NOTE);
    // printf("PT_TLS: 0x%x\n", PT_TLS);
    // printf("PT_GNU_STACK: 0x%x\n", PT_GNU_STACK);
    // printf("PT_GNU_RELRO: 0x%x\n", PT_GNU_RELRO);
    // printf("PT_RISCV_ATTRIBUTES: 0x%x\n\n", PT_RISCV_ATTRIBUTES);

    for(int i = 0; i < header->e_phnum; i++) {

        if(pheaders[i].p_type != PT_LOAD &&
           pheaders[i].p_type != PT_TLS) {
            continue;
        }

        // printf("type:   0x%.16x\n", pheaders[i].p_type);
        // printf("offset: 0x%.16lx\n", pheaders[i].p_offset);
        // printf("filesz: 0x%.16lx\n", pheaders[i].p_filesz);
        // printf("memsz:  0x%.16lx\n", pheaders[i].p_memsz);
        // printf("vadder: 0x%.16lx\n\n", pheaders[i].p_vaddr);

        result = lseek(fd_elf, pheaders[i].p_offset, SEEK_SET);
        if(result == -1) {
            printf("lseek failed somehow\n");
            return -1;
        }

        uint8_t* data = malloc(pheaders[i].p_memsz);
        if(data == NULL) {
            printf("oops\n");
            return -1;
        }
        
        int32_t bytes = read(fd_elf, data, pheaders[i].p_filesz);
        if(bytes == -1) {
            printf("Read failed somehow\n");
            return -1;
        }

        write_vmemory_pages(pheaders[i].p_vaddr, data, bytes);

        if(pheaders[i].p_type == PT_TLS) {
            register_data_t tp;
            tp.intdouble = pheaders[i].p_vaddr;
            write_register_int(4, tp);
        }

        // for(int j = 0; j < 100; j++) {
        //     printf("%c", data[j]);
        // }
        // print_pages(pheaders[i].p_vaddr, 100);

        free(data);
        data = NULL;
    }

    free(pheaders);
    pheaders = NULL;

    return EXIT_SUCCESS;
}

int stack_init(int argc, char *argv[], char *envp[]) {
    uint64_t stack_upper_addr = 0x7fffffffffff + 1;
    
    int envp_count = 0;
    int envp_bytes = 0;
    for(int i = 0; envp[i] != NULL; i++) {
        envp_count++;
        envp_bytes += strlen(envp[i]) + 1;
        //printf("envp[%d]: %ld : %s\n", i, strlen(envp[i]), envp[i]);
        //printf("%s\n", envp[i]);
    }
    while(envp_bytes % 8 != 0) {
        envp_bytes++;
    }

    int argv_bytes = 0;
    for(int i = 0; i < argc; i++) {
        argv_bytes += strlen(argv[i]) + 1;
        //printf("%s\n", argv[i]);
    }
    while(argv_bytes % 8 != 0) {
        argv_bytes++;
    }


    int total_bytes =   envp_bytes          +   // envp
                        argv_bytes          +   // argv
                        (envp_count+1) * 8  +   // envp addresses
                        (argc+1) * 8        +   // argv addresses
                        8                   +   // argc
                        32;                     // Auxillary vector
    
    int pages_needed = 1;
    while(total_bytes > pages_needed*PAGE_SIZE) {
        pages_needed++;
    }

    uint64_t stack_addr = stack_upper_addr - (PAGE_SIZE * pages_needed);

    /* Print byte count information for testing */
    // printf("envp_bytes:   %d\n", envp_bytes);
    // printf("argv_bytes:   %d\n", argv_bytes);
    // printf("envp_count:   %d\n", envp_count);
    // printf("argc:         %d\n", argc);
    // printf("total_bytes:  %d\n", total_bytes);
    // printf("pages_needed: %d\n", pages_needed);
    // printf("stack_addr:   %lx\n\n", stack_addr);


    uint64_t argc_addr = stack_addr;

    uint64_t argv_addr_addr[argc+1];
    argv_addr_addr[0] = stack_addr+8;
    for(int i = 1; i < argc+1; i++) {
        argv_addr_addr[i] = argv_addr_addr[i-1] + 8;
    }

    uint64_t envp_addr_addr[envp_count+1];
    envp_addr_addr[0] = argv_addr_addr[argc] + 8;
    for(int i = 1; i < envp_count+1; i++) {
        envp_addr_addr[i] = envp_addr_addr[i-1] + 8;
    }

    uint64_t null_vector_addr = envp_addr_addr[envp_count] + 8;

    uint64_t argv_addr[argc];
    argv_addr[0] = null_vector_addr + 32;
    for(int i = 1; i < argc; i++) {
        argv_addr[i] = argv_addr[i-1] + strlen(argv[i-1]) + 1;
    }

    uint64_t envp_addr[envp_count];
    envp_addr[0] = argv_addr[0] + argv_bytes;
    for(int i = 1; i < envp_count; i++) {
        envp_addr[i] = envp_addr[i-1] + strlen(envp[i-1]) + 1;
    }
    
    /* Print calculated addresses for stack stuck for testing */
    // printf("argc_addr:\t\t0x%.12lx\n", argc_addr);
    // for(int i = 0; i < argc+1; i++) {
    //     printf("argv_addr_addr[%d]:\t0x%.12lx\n", i, argv_addr_addr[i]);
    // }
    // for(int i = 0; i < envp_count+1; i++) {
    //     printf("envp_addr_addr[%d]:\t0x%.12lx\n", i, envp_addr_addr[i]);
    // }
    // printf("null_vector_addr:\t0x%.12lx\n", null_vector_addr);
    // for(int i = 0; i < argc; i++) {
    //     printf("argv_addr[%d]:\t\t0x%.12lx\n", i, argv_addr[i]);
    // }
    // for(int i = 0; i < envp_count; i++) {
    //     printf("envp_addr[%d]:\t\t0x%.12lx\n", i, envp_addr[i]);
    // }
    // printf("\n");

    /* arc */
    write_vmemory_doubleword(argc_addr, argc);

    /* argv addresses */
    for(int i = 0; i < argc; i++) {
        write_vmemory_doubleword(argv_addr_addr[i], argv_addr[i]);
    }
    write_vmemory_doubleword(argv_addr_addr[argc], 0);

    /* envp addresses */
    for(int i = 0; i < envp_count; i++) {
        write_vmemory_doubleword(envp_addr_addr[i], envp_addr[i]);
    }
    write_vmemory_doubleword(envp_addr_addr[envp_count], 0);

    /* null vector */
    for(int i = 0; i < 4; i++) {
        write_vmemory_doubleword(null_vector_addr + i*8, 0);
    }

    /* argv */
    for(int i = 0; i < argc; i++) {
        write_vmemory_pages(argv_addr[i], (uint8_t*) argv[i], strlen(argv[i])+1);
    }

    /* envp */
    for(int i = 0; i < envp_count; i++) {
        write_vmemory_pages(envp_addr[i], (uint8_t*) envp[i], strlen(envp[i])+1);
    }

    register_init();
    write_register_int(2, (register_data_t) stack_addr);
    write_register_int(10, (register_data_t) (uint64_t) argc);
    write_register_int(11, (register_data_t) argv_addr[0]);
    write_register_int(12,(register_data_t) envp_addr[0]);

    PC = header->e_entry;

    /* print stack for testing */
    // uint64_t cur_addr = stack_addr;
    // uint64_t tmp;
    // printf("Name\t\tAddress Stored\tData\n");
    // printf("argc:\t\t  %12ld\n", read_vmemory_doubleword(cur_addr));
    // cur_addr += 8;
    // for(int i = 0; i <= argc; i++) {
    //     printf("argv[%d]:\t0x%.12lx\t", i, (tmp = read_vmemory_doubleword(cur_addr)));
    //     print_string(tmp);
    //     printf("\n");
    //     cur_addr += 8;
    // }
    // for(int i = 0; i <= envp_count; i++) {
    //     printf("envp[%d]:\t0x%.12lx\t", i, (tmp = read_vmemory_doubleword(cur_addr)));
    //     print_string(tmp);
    //     printf("\n");
    //     cur_addr += 8;
    // }
    // for(int i = 0; i < 4; i++) {
    //     printf("null[%d]:\t0x%.12lx\n", i, read_vmemory_doubleword(cur_addr));
    //     cur_addr += 8;
    // }

    return EXIT_SUCCESS;
}
