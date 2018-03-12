#include "internal.h"

#pragma once

namespace cpuxe {
    
    struct Reg8_Z80 {
        void operator=(BYTE data) {
            value = data;
        }

        WORD operator++() {
            value++;
        }

        BYTE value;
    };

    struct Reg16_Z80 {
        void operator=(WORD data) {
            value = data;
        }

        WORD operator++() {
            value++;
        }

        WORD value;
    };


    class CPUXE_Z80
    {
    public:

        CPUXE_Z80();
        virtual ~CPUXE_Z80();

    private:

        
    };
}