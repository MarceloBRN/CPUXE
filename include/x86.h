#ifndef CPUXE_X86_H
#define CPUXE_X86_H


#include <cstdint>
#include <string>
#include "internal.h"


#pragma once

namespace cpuxe {

	typedef BYTE Reg8;

	struct Reg16 {

		void operator=(WORD value) {
			word = value;
		}

		WORD operator++() {
			word++;
		}

		union {
			WORD word;

			struct
			{
				Reg8 low;
				Reg8 high;
			};
		};
	};

	union Reg32 {

		DWORD dword;

		void operator=(DWORD value) {
			dword = value;
		}

		DWORD operator++() {
			dword++;
		}

		struct
		{
			Reg16 low;
			Reg16 X;
		};

	};

	union Reg64 {

		QWORD qword;

		void operator=(QWORD value) {
			qword = value;
		}

		QWORD operator++() {
			qword++;
		}

		struct
		{
			Reg32 low;
			Reg32 X;
		};

	};

	union RFLAGS_Reg {

		QWORD data;

		void operator=(QWORD value) {
			data = value;
		}

		struct
		{
			QWORD CF : 1; //Carry flag
			QWORD reserved1 : 1; //Reserved
			QWORD PF : 1; //Parity flag
			QWORD reserved3 : 1;
			QWORD AF : 1; //Adjust flag
			QWORD reserved5 : 1;
			QWORD ZF : 1; //Zero flag
			QWORD SF : 1; //Sign flag
			QWORD TF : 1; //Trap flag
			QWORD IF : 1; //Interrupt enable flag
			QWORD DF : 1; //Direction flag
			QWORD OF : 1; //Overflow flag
			QWORD IPL : 1; //Input privilege level
			QWORD OPL : 1; //Output privilege level
			QWORD NT : 1; //Nested task flag
			QWORD reserved15 : 1;
			QWORD RF : 1; //Resume flag
			QWORD VM : 1; //Virtual 8086 mode flag
			QWORD AC : 1; //Alignment check
			QWORD VIF : 1; //Virtual interrupt flag
			QWORD VIP : 1; //Virtual interrupt pending
			QWORD ID : 1; //Able to use CPUID instruction
			QWORD reservedN : 42;
		};

	};

	union MXCSR_Reg {

		DWORD data;

		void operator=(DWORD value) {
			data = value;
		}

		struct
		{
			DWORD IOF : 1; //Invalid Operation Flag
			DWORD DF : 1; //Denormal Flag
			DWORD DZF : 1; //Divide-by-Zero Flag
			DWORD OF : 1; //Overflow Flag
			DWORD UF : 1; //Underflow Flag
			DWORD PF : 1; //Precision Flag
			DWORD DAZ : 1; //Denormals Are Zeros
			DWORD IOM : 1; //Invalid Operation Mask
			DWORD DOM : 1; //Denormal Operation Mask
			DWORD DZM : 1; //Divide-by-Zero Mask
			DWORD OM : 1; //Overflow Mask
			DWORD UM : 1; //Underflow Mask
			DWORD PM : 1; //Precision Mask
			DWORD RC : 2; //Rounding Control
			DWORD NT : 1; //Flush to Zero
			DWORD reserved : 16; //
		};

	};

	typedef QWORD MMX_Reg;

	union FPUX80_Reg {

		struct
		{
			BYTE sign : 1;
			BYTE exp : 7;
		};

		union {

			MMX_Reg mmx;

			struct
			{
				DWORD fraction1 : 32;
				DWORD fraction2 : 32;
			};
		};

		void reset() {
			sign = 0;
			exp = 0;
			mmx = 0;
		}
	};

	union XMM {

		struct
		{
			QWORD x1;
			QWORD x2;
		};

	};

	union YMM {

		struct
		{
			QWORD y1;
			QWORD y2;
			XMM y3;
		};

	};

	union ZMM_Reg {

		struct
		{
			QWORD z1;
			QWORD z2;
			QWORD z3;
			QWORD z4;
			YMM z5;
		};

	};

	typedef WORD Segment_Reg;
	typedef size_t IP_reg;
	typedef QWORD Control_reg;
	typedef QWORD Debug_reg;
	typedef WORD Status_reg;
	typedef WORD Tag_reg;

	class Processorx64
	{
	public:
		Processorx64(ARCH arch = ARCH::pe_i386, TARGET target = TARGET::x86_32);
		virtual ~Processorx64();

		/*General-Purpose Registers*/
		Reg64 RAX_T;
		Reg64 RBX_T;
		Reg64 RCX_T;
		Reg64 RDX_T;
		Reg64 RBP_T;
		Reg64 RSI_T;
		Reg64 RDI_T;
		Reg64 RSP_T;
		Reg64 R8_T;
		Reg64 R9_T;
		Reg64 R10_T;
		Reg64 R11_T;
		Reg64 R12_T;
		Reg64 R13_T;
		Reg64 R14_T;
		Reg64 R15_T;

		/*Segment Registers*/
		Segment_Reg CS;
		Segment_Reg DS;
		Segment_Reg SS;
		Segment_Reg ES;
		Segment_Reg FS;
		Segment_Reg GS;

		/*RFLAGS register*/
		RFLAGS_Reg RFLAGS_T;

		/*instruction pointer register*/
		Reg64 RIP_T;

		/*FPU register*/
		FPUX80_Reg ST0_T;
		FPUX80_Reg ST1_T;
		FPUX80_Reg ST2_T;
		FPUX80_Reg ST3_T;
		FPUX80_Reg ST4_T;
		FPUX80_Reg ST5_T;
		FPUX80_Reg ST6_T;
		FPUX80_Reg ST7_T;

		Status_reg SR_T; //Status Register
		Tag_reg TR_T; //Tag Register

		/*Control register*/
		Control_reg CR0_T;
		Control_reg CR1_T;
		Control_reg CR2_T;
		Control_reg CR3_T;
		Control_reg CR4_T;
		Control_reg CR5_T;
		Control_reg CR6_T;
		Control_reg CR7_T;
		Control_reg CR8_T;

		/*Debug register*/
		Debug_reg DR0_T;
		Debug_reg DR1_T;
		Debug_reg DR2_T;
		Debug_reg DR3_T;
		Debug_reg DR4_T;
		Debug_reg DR5_T;
		Debug_reg DR6_T;
		Debug_reg DR7_T;

		/*ZMM register*/
		ZMM_Reg ZMM0_T;
		ZMM_Reg ZMM1_T;
		ZMM_Reg ZMM2_T;
		ZMM_Reg ZMM3_T;
		ZMM_Reg ZMM4_T;
		ZMM_Reg ZMM5_T;
		ZMM_Reg ZMM6_T;
		ZMM_Reg ZMM7_T;
		ZMM_Reg ZMM8_T;
		ZMM_Reg ZMM9_T;
		ZMM_Reg ZMM10_T;
		ZMM_Reg ZMM11_T;
		ZMM_Reg ZMM12_T;
		ZMM_Reg ZMM13_T;
		ZMM_Reg ZMM14_T;
		ZMM_Reg ZMM15_T;
		ZMM_Reg ZMM16_T;
		ZMM_Reg ZMM17_T;
		ZMM_Reg ZMM18_T;
		ZMM_Reg ZMM19_T;
		ZMM_Reg ZMM20_T;
		ZMM_Reg ZMM21_T;
		ZMM_Reg ZMM22_T;
		ZMM_Reg ZMM23_T;
		ZMM_Reg ZMM24_T;
		ZMM_Reg ZMM25_T;
		ZMM_Reg ZMM26_T;
		ZMM_Reg ZMM27_T;
		ZMM_Reg ZMM28_T;
		ZMM_Reg ZMM29_T;
		ZMM_Reg ZMM30_T;
		ZMM_Reg ZMM31_T;

		MXCSR_Reg MXCSR_T; //MXCSR Register

		void Reset();
		void PrintStatus();

	private:
#ifdef _WINDOWS_
		HANDLE hConsole;
#endif // _WINDOWS_
		ARCH arch;
		TARGET target;

		void PrintStatusGeneralRegister(std::string name, Reg64 reg);
		void PrintStatusSegmentRegister(std::string name, Segment_Reg reg);
		void PrintStatusFlagRegister(std::string name, QWORD reg);
		void PrintStatusFlag(std::string name, BYTE reg);
		void PrintFPUregister(std::string name, FPUX80_Reg reg);
		void PrintMMXregister(std::string name, MMX_Reg reg);
		BOOL setTextColor(HANDLE h, int foregound, int background);
	};
}


#define RAX processor->RAX_T.qword
#define EAX processor->RAX_T.elow.dword
#define AX processor->RAX_T.elow.low.word
#define AL processor->RAX_T.elow.low.L
#define AH processor->RAX_T.elow.low.H

#define RBX processor->RBX_T.qword
#define EBX processor->RBX_T.elow.dword
#define BX processor->RBX_T.elow.low.word
#define BL processor->RBX_T.elow.low.L
#define BH processor->RBX_T.elow.low.H

#define RCX processor->RCX_T.qword
#define ECX processor->RCX_T.elow.dword
#define CX processor->RCX_T.elow.low.word
#define CL processor->RCX_T.elow.low.L
#define CH processor->RCX_T.elow.low.H

#define RDX processor->RDX_T.qword
#define EDX processor->RDX_T.elow.dword
#define DX processor->RDX_T.elow.low.word
#define DL processor->RDX_T.elow.low.L
#define DH processor->RDX_T.elow.low.H

#define RBP processor->RBP_T.qword
#define EBP processor->RBP_T.elow.dword
#define BP processor->RBP_T.elow.low.word
#define BPL processor->RBP_T.elow.low.L

#define RSI processor->RSI_T.qword
#define ESI processor->RSI_T.elow.dword
#define SI processor->RSI_T.elow.low.word
#define SIL processor->RSI_T.elow.low.L

#define RDI processor->RDI_T.qword
#define EDI processor->RDI_T.elow.dword
#define DI processor->RDI_T.elow.low.word
#define DIL processor->RDI_T.elow.low.L

#define RSP processor->RSP_T.qword
#define ESP processor->RSP_T.elow.dword
#define SP processor->RSP_T.elow.low.word
#define SPL processor->RSP_T.elow.low.L

#define RSP processor->RSP_T.qword
#define ESP processor->RSP_T.elow.dword
#define SP processor->RSP_T.elow.low.word
#define SPL processor->RSP_T.elow.low.L

#define RSP processor->RSP_T.qword
#define ESP processor->RSP_T.elow.dword
#define SP processor->RSP_T.elow.low.word
#define SPL processor->RSP_T.elow.low.L

#define R8 processor->R8_T.qword
#define R8D processor->R8_T.elow.dword
#define R8W processor->R8_T.elow.low.word
#define R8B processor->R8_T.elow.low.L

#define R9 processor->R9_T.qword
#define R9D processor->R9_T.elow.dword
#define R9W processor->R9_T.elow.low.word
#define R9B processor->R9_T.elow.low.L

#define R10 processor->R10_T.qword
#define R10D processor->R10_T.elow.dword
#define R10W processor->R10_T.elow.low.word
#define R10B processor->R10_T.elow.low.L

#define R11 processor->R11_T.qword
#define R11D processor->R11_T.elow.dword
#define R11W processor->R11_T.elow.low.word
#define R11B processor->R11_T.elow.low.L

#define R12 processor->R12_T.qword
#define R12D processor->R12_T.elow.dword
#define R12W processor->R12_T.elow.low.word
#define R12B processor->R12_T.elow.low.L

#define R13 processor->R13_T.qword
#define R13D processor->R13_T.elow.dword
#define R13W processor->R13_T.elow.low.word
#define R13B processor->R13_T.elow.low.L

#define R14 processor->R14_T.qword
#define R14D processor->R14_T.elow.dword
#define R14W processor->R14_T.elow.low.word
#define R14B processor->R14_T.elow.low.L

#define R15 processor->R15_T.qword
#define R15D processor->R15_T.elow.dword
#define R15W processor->R15_T.elow.low.word
#define R15B processor->R15_T.elow.low.L

#define RFLAGS processor->RFLAGS_T

#define RIP processor->RIP_T

#define MMX0 processor->ST0_T.mmx;
#define MMX1 processor->ST1_T.mmx;
#define MMX2 processor->ST2_T.mmx;
#define MMX3 processor->ST3_T.mmx;
#define MMX4 processor->ST4_T.mmx;
#define MMX5 processor->ST5_T.mmx;
#define MMX6 processor->ST6_T.mmx;
#define MMX7 processor->ST7_T.mmx;

#define XMM0 processor->ZMM0_T.z5.y3
#define XMM1 processor->ZMM1_T.z5.y3
#define XMM2 processor->ZMM2_T.z5.y3
#define XMM3 processor->ZMM3_T.z5.y3
#define XMM4 processor->ZMM4_T.z5.y3
#define XMM5 processor->ZMM5_T.z5.y3
#define XMM6 processor->ZMM6_T.z5.y3
#define XMM7 processor->ZMM7_T.z5.y3
#define XMM8 processor->ZMM8_T.z5.y3
#define XMM9 processor->ZMM9_T.z5.y3
#define XMM10 processor->ZMM10_T.z5.y3
#define XMM11 processor->ZMM11_T.z5.y3
#define XMM12 processor->ZMM12_T.z5.y3
#define XMM13 processor->ZMM13_T.z5.y3
#define XMM14 processor->ZMM14_T.z5.y3
#define XMM15 processor->ZMM15_T.z5.y3

#define YMM0 processor->ZMM0_T.z5
#define YMM1 processor->ZMM1_T.z5
#define YMM2 processor->ZMM2_T.z5
#define YMM3 processor->ZMM3_T.z5
#define YMM4 processor->ZMM4_T.z5
#define YMM5 processor->ZMM5_T.z5
#define YMM6 processor->ZMM6_T.z5
#define YMM7 processor->ZMM7_T.z5
#define YMM8 processor->ZMM8_T.z5
#define YMM9 processor->ZMM9_T.z5
#define YMM10 processor->ZMM10_T.z5
#define YMM11 processor->ZMM11_T.z5
#define YMM12 processor->ZMM12_T.z5
#define YMM13 processor->ZMM13_T.z5
#define YMM14 processor->ZMM14_T.z5
#define YMM15 processor->ZMM15_T.z5

#define ZMM0 processor->ZMM0_T
#define ZMM1 processor->ZMM1_T
#define ZMM2 processor->ZMM2_T
#define ZMM3 processor->ZMM3_T
#define ZMM4 processor->ZMM4_T
#define ZMM5 processor->ZMM5_T
#define ZMM6 processor->ZMM6_T
#define ZMM7 processor->ZMM7_T
#define ZMM8 processor->ZMM8_T
#define ZMM9 processor->ZMM9_T
#define ZMM10 processor->ZMM10_T
#define ZMM11 processor->ZMM11_T
#define ZMM12 processor->ZMM12_T
#define ZMM13 processor->ZMM13_T
#define ZMM14 processor->ZMM14_T
#define ZMM15 processor->ZMM15_T
#define ZMM16 processor->ZMM16_T
#define ZMM17 processor->ZMM17_T
#define ZMM18 processor->ZMM18_T
#define ZMM19 processor->ZMM19_T
#define ZMM20 processor->ZMM20_T
#define ZMM21 processor->ZMM21_T
#define ZMM22 processor->ZMM22_T
#define ZMM23 processor->ZMM23_T
#define ZMM24 processor->ZMM24_T
#define ZMM25 processor->ZMM25_T
#define ZMM26 processor->ZMM26_T
#define ZMM27 processor->ZMM27_T
#define ZMM28 processor->ZMM28_T
#define ZMM29 processor->ZMM29_T
#define ZMM30 processor->ZMM30_T
#define ZMM31 processor->ZMM31_T

#define MXCSR processor->MXCSR_T

#endif // CPUXE_X86_H