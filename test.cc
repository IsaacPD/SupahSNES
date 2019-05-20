#include <stdio.h>
#include <stdint.h>

uint8_t ram[256];

int main(){
	ram[12] = 0xE5;
	ram[13] = 0xA4;

	uint8_t * t0 = &ram[12];
	uint16_t * t1 = (uint16_t *) t0;

	printf("%x %x\n", *t1, *t0);
	return 0;
}