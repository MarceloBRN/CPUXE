#include <cstdint>

#if defined(_WIN64) || defined(_WIN32)
#include <Windows.h>

#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKCYAN 3
#define DARKRED 4
#define DARKMANGENTA 5
#define DARKYELLOW 6
#define GRAY 7
#define DARKGRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

#endif

#pragma once

namespace cpuxe {

	typedef uint64_t QWORD;
	typedef uint32_t DWORD;
	typedef uint16_t WORD;
	typedef uint8_t BYTE;

	enum TARGET {
		x86_32,
		x86_64,
		x86_32_intel,
		x86_64_intel,
		x86_32_nacl,
		x86_64_nacl,
	};

	enum ARCH {
		pe_i386,
		pei_i386,
		elf32_i386,
		elf32_little,
		elf32_big,
		srec,
		symbolsrec,
		verilog,
		tekhex,
		binary,
		ihex
	};

}