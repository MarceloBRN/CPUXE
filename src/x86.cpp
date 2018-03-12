#include <iostream>
#include <iomanip>
#include <bitset>
#include "x86.h"

namespace cpuxe {

    cpuxe::CPUXE_X86_64::CPUXE_X86_64(ARCH arch, TARGET target)
    {
        this->arch = arch;
        this->target = target;
#ifdef _WINDOWS_
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _WINDOWS_
    }

    cpuxe::CPUXE_X86_64::~CPUXE_X86_64()
    {
    }

    void cpuxe::CPUXE_X86_64::set_rax(const QWORD & value)
    {
        RAX_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rbx(const QWORD & value)
    {
        RBX_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rcx(const QWORD & value)
    {
        RCX_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rdx(const QWORD & value)
    {
        RDX_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rbp(const QWORD & value)
    {
        RBP_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rsi(const QWORD & value)
    {
        RSI_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rdi(const QWORD & value)
    {
        RDI_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_rsp(const QWORD & value)
    {
    }

    void cpuxe::CPUXE_X86_64::set_r8(const QWORD & value)
    {
        R8_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r9(const QWORD & value)
    {
        R9_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r10(const QWORD & value)
    {
        R10_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r11(const QWORD & value)
    {
        R11_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r12(const QWORD & value)
    {
        R12_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r13(const QWORD & value)
    {
        R13_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r14(const QWORD & value)
    {
        R14_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_r15(const QWORD & value)
    {
        R15_T = value;
    }

    void cpuxe::CPUXE_X86_64::set_eax(const DWORD & value)
    {
        RAX_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_ebx(const DWORD & value)
    {
        RBX_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_ecx(const DWORD & value)
    {
        RCX_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_edx(const DWORD & value)
    {
        RDX_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_ebp(const DWORD & value)
    {
        RBP_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_esi(const DWORD & value)
    {
        RSI_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_edi(const DWORD & value)
    {
        RDI_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_esp(const DWORD & value)
    {
        RSP_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r8d(const DWORD & value)
    {
        R8_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r9d(const DWORD & value)
    {
        R9_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r10d(const DWORD & value)
    {
        R10_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r11d(const DWORD & value)
    {
        R11_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r12d(const DWORD & value)
    {
        R12_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r13d(const DWORD & value)
    {
        R13_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r14d(const DWORD & value)
    {
        R14_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r15d(const DWORD & value)
    {
        R15_T.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_ax(const WORD & value)
    {
        RAX_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_bx(const WORD & value)
    {
        RBX_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_cx(const WORD & value)
    {
        RCX_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_dx(const WORD & value)
    {
        RDX_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_bp(const WORD & value)
    {
        RBP_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_si(const WORD & value)
    {
        RSI_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_di(const WORD & value)
    {
        RDI_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_sp(const WORD & value)
    {
        RSP_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r8w(const WORD & value)
    {
        R8_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r9w(const WORD & value)
    {
        R9_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r10w(const WORD & value)
    {
        R10_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r11w(const WORD & value)
    {
        R11_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r12w(const WORD & value)
    {
        R12_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r13w(const WORD & value)
    {
        R13_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r14w(const WORD & value)
    {
        R14_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r15w(const WORD & value)
    {
        R15_T.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_al(const BYTE & value)
    {
        RAX_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_bl(const BYTE & value)
    {
        RBX_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_cl(const BYTE & value)
    {
        RCX_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_dl(const BYTE & value)
    {
        RDX_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_ah(const BYTE & value)
    {
        RAX_T.low.low.high = value;
    }

    void cpuxe::CPUXE_X86_64::set_bh(const BYTE & value)
    {
        RBX_T.low.low.high = value;
    }

    void cpuxe::CPUXE_X86_64::set_ch(const BYTE & value)
    {
        RCX_T.low.low.high = value;
    }

    void cpuxe::CPUXE_X86_64::set_dh(const BYTE & value)
    {
        RDX_T.low.low.high = value;
    }

    void cpuxe::CPUXE_X86_64::set_bpl(const BYTE & value)
    {
        RBP_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_sil(const BYTE & value)
    {
        RSI_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_dil(const BYTE & value)
    {
        RDI_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_spl(const BYTE & value)
    {
        RSP_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r8b(const BYTE & value)
    {
        R8_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r9b(const BYTE & value)
    {
        R9_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r10b(const BYTE & value)
    {
        R10_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r11b(const BYTE & value)
    {
        R11_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r12b(const BYTE & value)
    {
        R12_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r13b(const BYTE & value)
    {
        R13_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r14b(const BYTE & value)
    {
        R14_T.low.low.low = value;
    }

    void cpuxe::CPUXE_X86_64::set_r15b(const BYTE & value)
    {
        R15_T.low.low.low = value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rax() const
    {
        return RAX_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rbx() const
    {
        return RBX_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rcx() const
    {
        return RCX_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rdx() const
    {
        return RDX_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rbp() const
    {
        return RBP_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rsi() const
    {
        return RSI_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rdi() const
    {
        return RDI_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::rsp() const
    {
        return RSP_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r8() const
    {
        return R8_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r9() const
    {
        return R9_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r10() const
    {
        return R10_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r11() const
    {
        return R11_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r12() const
    {
        return R12_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r13() const
    {
        return R13_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r14() const
    {
        return R14_T.value;
    }

    const QWORD &cpuxe::CPUXE_X86_64::r15() const
    {
        return R15_T.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::eax() const
    {
        return RAX_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::ebx() const
    {
        return RBX_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::ecx() const
    {
        return RCX_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::edx() const
    {
        return RDX_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::ebp() const
    {
        return RBP_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::esi() const
    {
        return RSI_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::edi() const
    {
        return RDI_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::esp() const
    {
        return RSP_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r8d() const
    {
        return R8_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r9d() const
    {
        return R9_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r10d() const
    {
        return R10_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r11d() const
    {
        return R11_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r12d() const
    {
        return R12_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r13d() const
    {
        return R13_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r14d() const
    {
        return R14_T.low.value;
    }

    const DWORD &cpuxe::CPUXE_X86_64::r15d() const
    {
        return R15_T.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::ax() const
    {
        return RAX_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::bx() const
    {
        return RBX_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::cx() const
    {
        return RCX_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::dx() const
    {
        return RDX_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::bp() const
    {
        return RBP_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::si() const
    {
        return RSI_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::di() const
    {
        return RDI_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::sp() const
    {
        return RSP_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r8w() const
    {
        return R8_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r9w() const
    {
        return R9_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r10w() const
    {
        return R10_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r11w() const
    {
        return R11_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r12w() const
    {
        return R12_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r13w() const
    {
        return R13_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r14w() const
    {
        return R14_T.low.low.value;
    }

    const WORD &cpuxe::CPUXE_X86_64::r15w() const
    {
        return R15_T.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::al() const
    {
        return RAX_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::bl() const
    {
        return RBX_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::cl() const
    {
        return RCX_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::dl() const
    {
        return RDX_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::ah() const
    {
        return RAX_T.low.low.high.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::bh() const
    {
        return RBX_T.low.low.high.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::ch() const
    {
        return RCX_T.low.low.high.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::dh() const
    {
        return RDX_T.low.low.high.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::bpl() const
    {
        return RBP_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::sil() const
    {
        return RSI_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::dil() const
    {
        return RDI_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::spl() const
    {
        return RSP_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r8b() const
    {
        return R8_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r9b() const
    {
        return R9_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r10b() const
    {
        return R10_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r11b() const
    {
        return R11_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r12b() const
    {
        return R12_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r13b() const
    {
        return R13_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r14b() const
    {
        return R14_T.low.low.low.value;
    }

    const BYTE &cpuxe::CPUXE_X86_64::r15b() const
    {
        return R15_T.low.low.low.value;
    }

    void cpuxe::CPUXE_X86_64::Reset()
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

    void CPUXE_X86_64::PrintStatus()
    {
#ifdef _WINDOWS_
        setTextColor(hConsole, WHITE, DARKMANGENTA);
#endif // _WINDOWS_
        std::cout << "GENERAL REGISTERS" << std::endl;

        PrintStatusGeneralRegister("RAX", RAX_T);
        PrintStatusGeneralRegister("RBX", RBX_T);
        PrintStatusGeneralRegister("RCX", RCX_T);
        PrintStatusGeneralRegister("RDX", RDX_T);
        PrintStatusGeneralRegister("RBP", RBP_T);
        PrintStatusGeneralRegister("RSI", RSI_T);
        PrintStatusGeneralRegister("RDI", RDI_T);
        PrintStatusGeneralRegister("RSP", RSP_T);
        PrintStatusGeneralRegister("R8 ", R8_T);
        PrintStatusGeneralRegister("R9 ", R9_T);
        PrintStatusGeneralRegister("R10", R10_T);
        PrintStatusGeneralRegister("R11", R11_T);
        PrintStatusGeneralRegister("R12", R12_T);
        PrintStatusGeneralRegister("R13", R13_T);
        PrintStatusGeneralRegister("R14", R14_T);
        PrintStatusGeneralRegister("R15", R15_T);

#ifdef _WINDOWS_
        setTextColor(hConsole, GRAY, BLACK);
#endif // _WINDOWS_
        std::cout << std::endl;
    }

    void cpuxe::CPUXE_X86_64::PrintStatusGeneralRegister(std::string name, Reg64_X86 reg)
    {
#ifdef _WINDOWS_
        setTextColor(hConsole, GREEN, BLACK);
#endif // _WINDOWS_
        std::cout << name << ": ";
#ifdef _WINDOWS_
        setTextColor(hConsole, GRAY, BLACK);
#endif // _WINDOWS_
        printf("0x%016I64X ", reg.value);
#ifdef _WINDOWS_
        setTextColor(hConsole, CYAN, BLACK);
#endif // _WINDOWS_
        printf("d:(%020llu) ", reg.value);
#ifdef _WINDOWS_
        setTextColor(hConsole, YELLOW, BLACK);
#endif // _WINDOWS_
        std::cout << "b:( ";
        //std::cout << std::bitset<64>(RAX) << " ";
        std::cout << std::bitset<4>((reg.value & 0xF000000000000000) >> 60) << " ";
        std::cout << std::bitset<4>((reg.value & 0x0F00000000000000) >> 56) << " ";
        std::cout << std::bitset<4>((reg.value & 0x00F0000000000000) >> 52) << " ";
        std::cout << std::bitset<4>((reg.value & 0x000F000000000000) >> 48) << " ";
        std::cout << std::bitset<4>((reg.value & 0x0000F00000000000) >> 44) << " ";
        std::cout << std::bitset<4>((reg.value & 0x00000F0000000000) >> 40) << " ";
        std::cout << std::bitset<4>((reg.value & 0x000000F000000000) >> 36) << " ";
        std::cout << std::bitset<4>((reg.value & 0x0000000F00000000) >> 32) << " | ";
        std::cout << std::bitset<4>((reg.value & 0x00000000F0000000) >> 28) << " ";
        std::cout << std::bitset<4>((reg.value & 0x000000000F000000) >> 24) << " ";
        std::cout << std::bitset<4>((reg.value & 0x0000000000F00000) >> 20) << " ";
        std::cout << std::bitset<4>((reg.value & 0x00000000000F0000) >> 16) << " | ";
        std::cout << std::bitset<4>((reg.value & 0x000000000000F000) >> 12) << " ";
        std::cout << std::bitset<4>((reg.value & 0x0000000000000F00) >> 8) << " | ";
        std::cout << std::bitset<4>((reg.value & 0x00000000000000F0) >> 4) << " ";
        std::cout << std::bitset<4>((reg.value & 0x000000000000000F)) << " ";
        std::cout << ")\n";
    }

    BOOL cpuxe::CPUXE_X86_64::setTextColor(HANDLE h, int foregound, int background)
    {
        WORD color = foregound | (background << 4);
        return SetConsoleTextAttribute(h, color);
    }


}