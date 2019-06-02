#ifndef CPU_H
#define CPU_H

#include "mem.h"

typedef union {
		struct {
			u8 H, L;
		};
		u16 W;
} reg16;

typedef union {
	struct {
		u8 bank;
		u16 val;
	};
	u32 W: 24;
} br;

struct CPU {
	reg16 A;  // Accumulator (Math) register
	reg16 X;  // X and Y 
	reg16 Y;  //		 are Indexing Registers
	br  DPB;  // (DPB.bank) Data Bank holds the bank for memory transfers
			  // (DPB.val)  Direct page register, used for direct addressing modes
	br  PCB;  // (PCB.bank) Program Bank holds memory bank address of instruction
			  // (PCB.val)  Program Counter
	reg16 SP; // Stack Pointer
	union {
		struct {
			u8 C: 1; // Carry Flag
			u8 Z: 1; // Zero  Flag
			u8 I: 1; // IRQ disable
			u8 D: 1; // Decimal
			u8 X: 1; // Index Register Size (0 = 16-bit, 1 =8-bit)
			u8 M: 1; // Accumulator Register Size (0 = 16-bit, 1 =8-bit)
			u8 V: 1; // Overflow Flag
			u8 N: 1; // Negative Flag
		};
		u8 raw;
	} P;  // Processor Status register
};

struct CPU cpu;

u32 get_operands(int opcode);

#endif