#include "mnemonics.h"
#include "cpu.h"

void ADC(u8 code) 
{
	u16 operand = get_operands(code);

	if (cpu.P.M)
		cpu.A.L += operand + cpu.P.C;
	else
		cpu.A.W += operand + cpu.P.C;
}

void SBC(u8 code)
{
	u16 operand = get_operands(code);

	if (cpu.P.M)
		cpu.A.L = cpu.A.L - operand - 1 + cpu.P.C;
	else
		cpu.A.W = cpu.A.W - operand - 1 + cpu.P.C;
}

void AND(u8 code)
{
	u16 operand = get_operands(code);

	if (cpu.P.M)
		cpu.A.L &= operand;
	else
		cpu.A.W &= operand;
}

void ASL(u8 code)
{
	switch (code) 
	{
		case 0x0A:
			break;
	}
}