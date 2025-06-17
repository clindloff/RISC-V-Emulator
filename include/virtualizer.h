#ifndef VIRTUALIZER_H
#define VIRTUALIZER_H

/* DEFINES */

/* STRUCTURES */

/* FUNCTION DEFINITIONS */

uint32_t fetch(uint64_t);
instruction_t* decode();
void execute(instruction_t*);



#endif