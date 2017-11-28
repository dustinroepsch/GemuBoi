#include "Registers.hpp"

Registers::Registers() {
    reset();
}

void Registers::reset() {
    a = f = b = c = d = e = h = l = 0;
    sp = 0;
    pc = 0x100; //cartridge starts here
}
