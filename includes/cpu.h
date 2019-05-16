#ifndef CPU_H
#define CPU_H

#include "includes/mem.h"

typedef struct CPU {
	u16 A;  // Accumulator (Math) register
	u16 X;  // X and Y 
	u16 Y;  //		 are Indexing Registers
	u8  DB; // Data Bank holds the bank for memory transfers
	u16 DP;  // Direct page register, used for direct addressing modes
	u8  PB; // Program Bank holds memory bank address of instruction
	u16 PC; // Program Counter
	u16 SP; // Stack Pointer
	union {
		struct {
			u8 C: 1; // Carry Flag
			u8 Z: 1; // Zero  Flag
			u8 I: 1; // IRQ disable
			u8 D: 1; // Decimal
			u8 X: 1; // Index Register Size (0 = 16-bit, 1 =8-bit)
			u8 M: 1; // Accumulator Register Size (0 = 16-bit, 1 =8-bit)
			u8 N: 1; // Overflow Flag
			u8 O: 1; // Negative Flag
		};
		u8 raw;
	} P;  // Processor Status register
} CPU;

#endif