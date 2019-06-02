#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define MAXADDR 	1 << 24 	// 0xffffff highest addressable
								// memory region (16 MB)
#define RAM_SIZE 	1 << 17 	// 128k of RAM
#define PAGE 		256			// 256 byte pages
#define BANK 		1 << 16 	// 64k sized banks
#define WORD		2			// 2 Bytes
#define BITS		16			// Number of Bits in word
#define READ(a, b)		true

// Integer types
typedef uint_least32_t u32;
typedef struct {char data[3];} u24;
typedef uint_least16_t u16;
typedef  int_least16_t s16;
typedef uint_least8_t   u8;
typedef  int_least8_t   s8;

u8 		get_bits	(void* data, u8 nbits, u8 bitno);
void 	assign_bits	(void* data, u8 nbits, u8 bitno, u8 val);


u8 RAM[RAM_SIZE];

void mem_read(u16 addr, void * buf, u8 nbytes);
void mem_write(u16 addr, void * buf, u8 nbytes);

#endif