#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "loader.h"
#include "memory.h"
#include "instructions.h"
#include "util.h"
#include "virtualizer.h"

extern uint64_t PC;

int main(int argc, char* argv[], char* envp[]) {
    
    if(argc < 2) {
        printf("ERROR: No input file\n");
        return EXIT_FAILURE;
    }

    int result = EXIT_FAILURE;

    result = loader_init(argv[1], envp);
    if(result == EXIT_FAILURE) {
        printf("ERROR: Failed to initiate loader\n");
        return EXIT_FAILURE;
    }

    int halt = 0;
    int inst_count = 1;
    while(!halt) {
        printf("%d", inst_count++);
        uint32_t full_inst = fetch(PC);
        instruction_t* inst = decode(full_inst);
        execute(inst);
    }

    return EXIT_SUCCESS;
}

