#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define MAXADDR 1 << 24 	// 0xffffff highest addressable
							// memory region (16 MB)
#define RAM_SIZE 1 << 17 	// 128k of RAM
#define PAGE 256
#define BANK 1 << 16 		// 64k sized banks

// Integer types
typedef uint_least32_t u32;
typedef uint_least16_t u16;
typedef uint_least8_t   u8;
typedef  int_least8_t   s8;

u8 		get_bits	(void* data, u8 nbits, u8 bitno);
void 	assign_bits	(void* data, u8 nbits, u8 bitno, u8 val);


u8 RAM[RAM_SIZE];

#endif