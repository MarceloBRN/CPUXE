#include <iostream>
#include <iomanip>
#include <bitset>
#include "x86.h"


cpuxe::Processorx64::Processorx64(ARCH arch, TARGET target)
{
	this->arch = arch;
	this->target = target;
#ifdef _WINDOWS_
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _WINDOWS_
}

cpuxe::Processorx64::~Processorx64()
{
}

void cpuxe::Processorx64::Reset()
{
	RAX_T = 0x0000000000000000;
	RBX_T = 0x0000000000000000;
	RCX_T = 0x0000000000000000;
	RDX_T = 0x0000000000000000;
	RBP_T = 0x0000000000000000;
	RSI_T = 0x0000000000000000;
	RDI_T = 0x0000000000000000;
	RSP_T = 0x0000000000000000;
	R8_T = 0x0000000000000000;
	R9_T = 0x0000000000000000;
	R10_T = 0x0000000000000000;
	R11_T = 0x0000000000000000;
	R12_T = 0x0000000000000000;
	R13_T = 0x0000000000000000;
	R14_T = 0x0000000000000000;
	R15_T = 0x0000000000000000;

	CS = 0x00000000;
	DS = 0x00000000;
	SS = 0x00000000;
	ES = 0x00000000;
	FS = 0x00000000;
	GS = 0x00000000;

	RFLAGS_T = 0x0000000000000000;

	RIP_T = 0x0000000000000000;

	ST0_T.reset();
	ST1_T.reset();
	ST2_T.reset();
	ST3_T.reset();
	ST4_T.reset();
	ST5_T.reset();
	ST6_T.reset();
	ST7_T.reset();
}

void cpuxe::Processorx64::PrintStatusGeneralRegister(std::string name, Reg64 reg)
{
#ifdef _WINDOWS_
	setTextColor(hConsole, GREEN, BLACK);
#endif // _WINDOWS_
	std::cout << name << ": ";
#ifdef _WINDOWS_
	setTextColor(hConsole, GRAY, BLACK);
#endif // _WINDOWS_
	printf("0x%016I64X ", reg.qword);
#ifdef _WINDOWS_
	setTextColor(hConsole, CYAN, BLACK);
#endif // _WINDOWS_
	printf("d:(%020zu) ", reg.qword);
#ifdef _WINDOWS_
	setTextColor(hConsole, YELLOW, BLACK);
#endif // _WINDOWS_
	std::cout << "b:( ";
	//std::cout << std::bitset<64>(RAX.qword) << " ";
	std::cout << std::bitset<4>((reg.qword & 0xF000000000000000) >> 60) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x0F00000000000000) >> 56) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x00F0000000000000) >> 52) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x000F000000000000) >> 48) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x0000F00000000000) >> 44) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x00000F0000000000) >> 40) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x000000F000000000) >> 36) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x0000000F00000000) >> 32) << " | ";
	std::cout << std::bitset<4>((reg.qword & 0x00000000F0000000) >> 28) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x000000000F000000) >> 24) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x0000000000F00000) >> 20) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x00000000000F0000) >> 16) << " | ";
	std::cout << std::bitset<4>((reg.qword & 0x000000000000F000) >> 12) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x0000000000000F00) >> 8) << " | ";
	std::cout << std::bitset<4>((reg.qword & 0x00000000000000F0) >> 4) << " ";
	std::cout << std::bitset<4>((reg.qword & 0x000000000000000F)) << " ";
	std::cout << ")\n";
}

BOOL cpuxe::Processorx64::setTextColor(HANDLE h, int foregound, int background)
{
	WORD color = foregound | (background << 4);
	return SetConsoleTextAttribute(h, color);
}
