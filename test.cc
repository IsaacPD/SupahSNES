#include <stdio.h>
#include <stdint.h>

typedef uint_least32_t u32;
typedef uint_least16_t u16;
typedef uint_least8_t   u8;
typedef  int_least8_t   s8;

typedef union {
	struct {
		u8 bank;
		u16 val;
	} __packed;
	u32 W: 24;
} br;

char arr[3];

uint8_t ram[256];

int main(){
	u8 val = 0x04;

	printf("%x\n", val);
	printf("%x\n", val << 16);
	return 0;
}