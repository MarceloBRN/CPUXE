#include <iostream>
#include "MemRAM.h"

namespace cpuxe {

    cpuxe::RAM::RAM(const size_t &lenght, const address_t& address_bits, const MEM_UNIT_T& type)
    {
        if (address_bits % 8 != 0) {
            error_func(1, "Bad Unit Memory Allocation. It isn't multiple of 8");
        }

        size_t mem_size = lenght * static_cast<size_t>(type);

        //if (type == MEM_UNIT_T::ONE) {

        //}

        this->memory = new cpuxe::BYTE[mem_size];
        if (this->memory == nullptr) {
            error_func(2, "Error of Memory Allocation");
        }
        else {
            this->size = mem_size;
            this->address_bits = address_bits;

            for (size_t i = 0; i < mem_size; i++) {
                memory[i] = 0x0;
            }

        }

        

    }

    cpuxe::RAM::~RAM() {
        delete[] memory;
    }

    size_t cpuxe::RAM::read(const size_t &addr) {
        return memory[addr];
    }

    void cpuxe::RAM::write(const size_t &addr, const cpuxe::BYTE &data) {
        memory[addr] = data;
    }

    void cpuxe::RAM::info()
    {
        std::cout << "RAM SIZE: " << size << "(" << address_bits << " bits)" << std::endl;
        if (address_bits == 64) {
            printf("    Address         : Value(hex) Value(dec)\n");
            for (size_t i = 0; i < size; i++) {
                printf("    %016zX: %02X         %u\n", i, memory[i], memory[i]);
            }
        }
        else if (address_bits == 32){
            printf("    Address : Value(hex) Value(dec)\n");
            for (size_t i = 0; i < size; i++) {
                printf("    %08zX: %02X         %u\n", i, memory[i], memory[i]);
            }
        }
        else if (address_bits == 16) {
            printf("    Address : Value(hex) Value(dec)\n");
            for (size_t i = 0; i < size; i++) {
                printf("    %04zX    : %02X         %u\n", i, memory[i], memory[i]);
            }
        }
        else if (address_bits == 8) {
            printf("    Address : Value(hex) Value(dec)\n");
            for (size_t i = 0; i < size; i++) {
                printf("    %02zX      : %02X         %u\n", i, memory[i], memory[i]);
            }
        }
        
    }

    void RAM::info(const size_t & pos)
    {
        if (pos > size) {
            error_func(3, "Error of Invalid Memory Position Access");
        }
        else {
            std::cout << "RAM SIZE: " << size << " (" << address_bits << " bits)" << std::endl;
            if (address_bits == 64) {
                printf("    Address         : Value(hex) Value(dec)\n");
                printf("    %016zX: %02X         %u\n", pos, memory[pos], memory[pos]);
            }
            else if (address_bits == 32) {
                printf("    Address : Value(hex) Value(dec)\n");
                printf("    %08zX: %02X         %u\n", pos, memory[pos], memory[pos]);
            }
            else if (address_bits == 16) {
                printf("    Address : Value(hex) Value(dec)\n");
                printf("    %04zX    : %02X         %u\n", pos, memory[pos], memory[pos]);
            }
            else if (address_bits == 8) {
                printf("    Address : Value(hex) Value(dec)\n");
                printf("    %02zX      : %02X         %u\n", pos, memory[pos], memory[pos]);
            }
        }

        
    }

    void RAM::info(const size_t & begin, const size_t & end)
    {
        if (end > size) {
            error_func(3, "Error of Invalid Memory Position Access");
        }


        if (begin > end) {
            error_func(4, "Error of Invalid Memory Range");
        }
        else {
            //size_t end_m = size;
            //if (end_m < end) {
            //    end_m = end;
            //    std::cout << "Warning of Invalid Memory Ending!!!" << std::endl;
            //}
            std::cout << "RAM SIZE: " << size << " (" << address_bits << " bits address)" << std::endl;
            if (address_bits == 64) {
                printf("    Address         : Value(hex) Value(dec)\n");
                for (size_t i = begin; i <= end; i++) {
                    printf("    %016zX: %02X         %u\n", i, memory[i], memory[i]);
                }
            }
            else if (address_bits == 32) {
                printf("    Address : Value(hex) Value(dec)\n");
                for (size_t i = begin; i <= end; i++) {
                    printf("    %08zX: %02X         %u\n", i, memory[i], memory[i]);
                }
            }
            else if (address_bits == 16) {
                printf("    Address : Value(hex) Value(dec)\n");
                for (size_t i = begin; i <= end; i++) {
                    printf("    %04zX    : %02X         %u\n", i, memory[i], memory[i]);
                }
            }
            else if (address_bits == 8) {
                printf("    Address : Value(hex) Value(dec)\n");
                for (size_t i = begin; i <= end; i++) {
                    printf("    %02zX      : %02X         %u\n", i, memory[i], memory[i]);
                }
            }
        }
    }
}