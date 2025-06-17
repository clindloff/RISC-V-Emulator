#ifndef _VIRTUALIZER_H_
#define _VIRTUALIZER_H_

/* DEFINES */

/* STRUCTURES */

/* FUNCTION DEFINITIONS */

/*
 * Helper function to extract values from 64 bit numbers
 * i.e. instructions, addresses
 */
uint32_t extract(uint64_t, uint8_t, uint8_t);

/*
 * Helper function to sign extend values to 64 bits from 
 * varying sizes*/
uint64_t sext(uint64_t, ssize_t);

#endif