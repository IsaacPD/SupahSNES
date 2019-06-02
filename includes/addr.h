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

template<bool e=false, bool X=false, bool Y=false>
static inline u32 Direct(u8 nbytes) // DIRECT, DIRECT X/Y
{
	u16 addr = Immediate<>();

	if (X) addr += cpu.X.W;
	if (Y) addr += cpu.Y.W
	if (e) addr = cpu.DPB.val + u8(addr);
	else addr += cpu.DPB.val;
	return READ(addr, nbytes);
}

template<bool e=false, bool X=false, bool Y=false, u8 nbytes=2>
static inline u32 DirectIndirect() // (DIRECT), [DIRECT], (DIRECT, X), (DIRECT), Y, [DIRECT], Y
{
	u32 addr = nbytes == 2 ? (cpu.PCB.bank << BITS) | Direct<e, X>(nbytes) : Direct<e, X>(nbytes);
	if (Y) addr += cpu.Y.w;
	
	return READ(addr, nbytes);
}

template<bool X=false, bool jump=false>
static inline u32 Long(u8 nbytes)
{
	u32 addr = u32(Immediate<u24>());
	if (jump) return addr;
	if (X) addr += cpu.X.W;
	return READ(addr, nbytes);
}

template<typename T>
static inline void Relative() // Only branch statements use rel8/16 so the actual branch is done here
{
	s16 offset = Immediate<T>();
	cpu.PCB.val += offset;
}

static inline u32 Stack()
{
	u16 addr = Immediate<>() + cpu.SP.W;
	return READ(addr, WORD);
}

static inline u32 StackIndirect()
{
	u16 addr = Stack() + cpu.Y.W;
	return READ(addr, WORD);
}

#endif