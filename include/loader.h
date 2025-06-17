#ifndef _LOADER_H_
#define _LOADER_H_

/* DEFINES */
#define PAGE_SIZE 4096

/* STRUCTURES */

/* FUNCTION DEFINITIONS */

int loader_init(char*, char**);
int open_elf(char*);
int read_ph();
int stack_init(int argc, char *argv[], char *envp[]);


#endif