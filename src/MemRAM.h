#include <cstdint>
#include "internal.h"

#pragma once

//typedef uint_least8_t BYTE;

namespace cpuxe{

class RAM
{
public:
	RAM(const size_t &lenght, const address_t& address_bits, const MEM_UNIT_T& type = MEM_UNIT_T::ONE);
	virtual ~RAM();
    size_t read(const size_t &addr);
	void write(const size_t &addr, const cpuxe::BYTE &data);

    void info();
    void info(const size_t &pos);
    void info(const size_t &begin, const size_t &end);

	
private:
    cpuxe::BYTE *memory;
    size_t size;
    size_t address_bits;
};

}

