#include <cstdint>
#include <cstdio>

#if defined(_WIN64) || defined(_WIN32)
#define WIN32_PLATFORM
#endif

#ifdef WIN32_PLATFORM
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

    //enum address_t {
    //    adr_8bits,
    //    adr_16bits,
    //    adr_32bits,
    //    adr_64bits,
    //};

    enum MEM_UNIT_T { //Size bytes
        ONE = 1,
        KB = 1024,
        MB = 1048576,
        GB = 1073741824,
    };

    typedef uint32_t address_t;


    static void error_func(const int &val, const char *str) {
        printf("[ERROR_%03d] %s!\n", val, str);
    }

    static size_t get_size_ram_sytem(){
#ifdef WIN32_PLATFORM
        typedef BOOL(WINAPI *PGMSE)(LPMEMORYSTATUSEX);
        PGMSE pGMSE = (PGMSE)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), TEXT("GlobalMemoryStatusEx"));
        if (pGMSE != 0)
        {
            MEMORYSTATUSEX mi;
            memset(&mi, 0, sizeof(MEMORYSTATUSEX));
            mi.dwLength = sizeof(MEMORYSTATUSEX);
            return  pGMSE(&mi) == TRUE ? static_cast<size_t>(mi.ullTotalPhys) : 0;
        } else {
            MEMORYSTATUS mi;
            memset(&mi, 0, sizeof(MEMORYSTATUS));
            mi.dwLength = sizeof(MEMORYSTATUS);
            GlobalMemoryStatus(&mi);
            return static_cast<size_t>(mi.dwTotalPhys);
        }
    }
#elif _UNIX

#endif
}