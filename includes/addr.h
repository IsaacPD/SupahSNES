#ifndef ADDR_H_
#define ADDR_H_

#include "mem.h"
#include "cpu.h"

template<typename T=u8>
static inline T Immediate()
{
	T val = READ(cpu.PCB.W, sizeof(T));
	cpu.PCB.val += sizeof(T);
	return val;
}

template<bool jump=false>
static inline u32 Absolute(u8 nbytes, u16 offset=0) // ABSOLUTE, ABSOLUTE X/Y
{
	u32 addr = Immediate<u16>();
	if (jump)
		return addr | (cpu.PCB.bank << BITS);
	return READ((addr | (cpu.DPB.bank << BITS)) + offset, nbytes);
}

template<bool X=false>
static inline u32 AbsoluteIndirect(u8 nbytes) // (ABSOLUTE), [ABSOLUTE], (ABSOLUTE, X)
{
	u32 addr = Immediate<u16>();
	if (X) addr = (addr | (cpu.PCB.bank << BITS)) + cpu.X.W;
	addr = READ(addr, nbytes);
	return nbytes == 2 ? addr | (cpu.PCB.bank << BITS) : addr;
}

template<bool e=false>
static inline u32 Direct(u8 nbytes, u16 offset=0) // DIRECT, DIRECT X/Y
{
	u16 addr = Immediate<>();

	if (e) addr = cpu.DPB.val + u8(addr + offset);
	else addr += cpu.DPB.val + offset;
	return READ(addr, nbytes);
}

template<bool e=false>
static inline u32 DirectIndirect(u8 nbytes, u16 offset=0) // (DIRECT), [DIRECT]
{
	u16 addr = Immediate<>();

	if (e) addr = cpu.DPB.val + u8(addr + offset);
	else addr += cpu.DPB.val + offset;
	return READ(addr, nbytes);
}

#endif