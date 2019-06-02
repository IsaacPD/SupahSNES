#pragma once

#include "mem.h"

#define OP(NAME) void NAME(u8 code);

OP(ADC)
OP(SBC)
OP(CMP)
OP(CPX)
OP(CPY)
OP(DEC)
OP(DEX)
OP(DEY)
OP(INC)
OP(INX)
OP(INY)
OP(AND)
OP(EOR)
OP(ORA)
OP(BIT)
OP(TRB)
OP(TSB)
OP(ASL)
OP(LSR)
OP(ROL)
OP(ROR)
OP(BCC)
OP(BCS)
OP(BEQ)
OP(BMI)
OP(BNE)
OP(BPL)
OP(BRA)
OP(BVC)
OP(BVS)
OP(BRL)
OP(JMP)
OP(JSL)
OP(JSR)
OP(RTL)
OP(RTS)
OP(BRK)
OP(COP)
OP(RTI)
OP(CLC)
OP(CLD)
OP(CLI)
OP(CLV)
OP(SEC)
OP(SED)
OP(SEI)
OP(REP)
OP(SEP)
OP(LDA)
OP(LDX)
OP(LDY)
OP(STA)
OP(STX)
OP(STY)
OP(STZ)
OP(MVN)
OP(MVP)
OP(NOP)
OP(WDM)
OP(PEA)
OP(PEI)
OP(PER)
OP(PHA)
OP(PHX)
OP(PHY)
OP(PLA)
OP(PLX)
OP(PLY)
OP(PHB)
OP(PHD)
OP(PHK)
OP(PHP)
OP(PLB)
OP(PLD)
OP(PLP)
OP(STP)
OP(WAI)
OP(TAX)
OP(TAY)
OP(TSX)
OP(TXA)
OP(TXS)
OP(TXY)
OP(TYA)
OP(TYX)
OP(TCD)
OP(TCS)
OP(TDC)
OP(TSC)
OP(XBA)
OP(XCE)