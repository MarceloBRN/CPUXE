#ifndef CPUXE_X86_H
#define CPUXE_X86_H


#include <cstdint>
#include <string>
#include "internal.h"


#pragma once

namespace cpuxe {

    struct Reg8 {
        void operator=(BYTE data) {
            value = data;
        }

        WORD operator++() {
            value++;
        }

        BYTE value;
    };

    struct Reg16 {
        void operator=(WORD data) {
            value = data;
        }

        WORD operator++() {
            value++;
        }

        union {
            WORD value;

            struct
            {
                Reg8 low;
                Reg8 high;
            };
        };
    };

    struct Reg32 {

        void operator=(DWORD data) {
            value = data;
        }

        DWORD operator++() {
            value++;
        }

        union {
            DWORD value;

            struct
            {
                Reg16 low;
                Reg16 X;
            };
        };

        

    };

    struct Reg64 {

        void operator=(QWORD data) {
            value = data;
        }

        QWORD operator++() {
            value++;
        }

        union
        {
            QWORD value;

            struct
            {
                Reg32 low;
                Reg32 X;
            };
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

    class CPUXE_X86
    {
    public:
        CPUXE_X86(ARCH arch = ARCH::pe_i386, TARGET target = TARGET::x86_64);
        virtual ~CPUXE_X86();

        void set_rax(const QWORD &value);
        void set_rbx(const QWORD &value);
        void set_rcx(const QWORD &value);
        void set_rdx(const QWORD &value);
        void set_rbp(const QWORD &value);
        void set_rsi(const QWORD &value);
        void set_rdi(const QWORD &value);
        void set_rsp(const QWORD &value);
        void set_r8(const QWORD &value);
        void set_r9(const QWORD &value);
        void set_r10(const QWORD &value);
        void set_r11(const QWORD &value);
        void set_r12(const QWORD &value);
        void set_r13(const QWORD &value);
        void set_r14(const QWORD &value);
        void set_r15(const QWORD &value);

        void set_eax(const DWORD &value);
        void set_ebx(const DWORD &value);
        void set_ecx(const DWORD &value);
        void set_edx(const DWORD &value);
        void set_ebp(const DWORD &value);
        void set_esi(const DWORD &value);
        void set_edi(const DWORD &value);
        void set_esp(const DWORD &value);
        void set_r8d(const DWORD &value);
        void set_r9d(const DWORD &value);
        void set_r10d(const DWORD &value);
        void set_r11d(const DWORD &value);
        void set_r12d(const DWORD &value);
        void set_r13d(const DWORD &value);
        void set_r14d(const DWORD &value);
        void set_r15d(const DWORD &value);

        void set_ax(const WORD &value);
        void set_bx(const WORD &value);
        void set_cx(const WORD &value);
        void set_dx(const WORD &value);
        void set_bp(const WORD &value);
        void set_si(const WORD &value);
        void set_di(const WORD &value);
        void set_sp(const WORD &value);
        void set_r8w(const WORD &value);
        void set_r9w(const WORD &value);
        void set_r10w(const WORD &value);
        void set_r11w(const WORD &value);
        void set_r12w(const WORD &value);
        void set_r13w(const WORD &value);
        void set_r14w(const WORD &value);
        void set_r15w(const WORD &value);

        void set_al(const BYTE &value);
        void set_bl(const BYTE &value);
        void set_cl(const BYTE &value);
        void set_dl(const BYTE &value);
        void set_ah(const BYTE &value);
        void set_bh(const BYTE &value);
        void set_ch(const BYTE &value);
        void set_dh(const BYTE &value);
        void set_bpl(const BYTE &value);
        void set_sil(const BYTE &value);
        void set_dil(const BYTE &value);
        void set_spl(const BYTE &value);
        void set_r8b(const BYTE &value);
        void set_r9b(const BYTE &value);
        void set_r10b(const BYTE &value);
        void set_r11b(const BYTE &value);
        void set_r12b(const BYTE &value);
        void set_r13b(const BYTE &value);
        void set_r14b(const BYTE &value);
        void set_r15b(const BYTE &value);

        const QWORD &rax() const;
        const QWORD &rbx() const;
        const QWORD &rcx() const;
        const QWORD &rdx() const;
        const QWORD &rbp() const;
        const QWORD &rsi() const;
        const QWORD &rdi() const;
        const QWORD &rsp() const;
        const QWORD &r8() const;
        const QWORD &r9() const;
        const QWORD &r10() const;
        const QWORD &r11() const;
        const QWORD &r12() const;
        const QWORD &r13() const;
        const QWORD &r14() const;
        const QWORD &r15() const;

        const DWORD &eax() const;
        const DWORD &ebx() const;
        const DWORD &ecx() const;
        const DWORD &edx() const;
        const DWORD &ebp() const;
        const DWORD &esi() const;
        const DWORD &edi() const;
        const DWORD &esp() const;
        const DWORD &r8d() const;
        const DWORD &r9d() const;
        const DWORD &r10d() const;
        const DWORD &r11d() const;
        const DWORD &r12d() const;
        const DWORD &r13d() const;
        const DWORD &r14d() const;
        const DWORD &r15d() const;

        const WORD &ax() const;
        const WORD &bx() const;
        const WORD &cx() const;
        const WORD &dx() const;
        const WORD &bp() const;
        const WORD &si() const;
        const WORD &di() const;
        const WORD &sp() const;
        const WORD &r8w() const;
        const WORD &r9w() const;
        const WORD &r10w() const;
        const WORD &r11w() const;
        const WORD &r12w() const;
        const WORD &r13w() const;
        const WORD &r14w() const;
        const WORD &r15w() const;

        const BYTE &al() const;
        const BYTE &bl() const;
        const BYTE &cl() const;
        const BYTE &dl() const;
        const BYTE &ah() const;
        const BYTE &bh() const;
        const BYTE &ch() const;
        const BYTE &dh() const;
        const BYTE &bpl() const;
        const BYTE &sil() const;
        const BYTE &dil() const;
        const BYTE &spl() const;
        const BYTE &r8b() const;
        const BYTE &r9b() const;
        const BYTE &r10b() const;
        const BYTE &r11b() const;
        const BYTE &r12b() const;
        const BYTE &r13b() const;
        const BYTE &r14b() const;
        const BYTE &r15b() const;

        void Reset();
        void PrintStatus();

    private:
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

#endif // CPUXE_X86_H