#include <cstdio>

#include "Registers/Registers.hpp"

int main() {
    Registers reg;

    printf("0x%02x\n", reg.getA());
    reg.setA(0x1B);
    printf("0x%02x\n", reg.getA());
    printf("0x%04x\n", reg.getAF());
    reg.setF(0x3A);
    printf("0x%04x\n", reg.getAF());

    reg.setAF(0x1234);
    printf("0x%04x\n", reg.getAF());
    printf("0x%02x\n", reg.getA());
    printf("0x%02x\n", reg.getF());
    
    
    
    
    
    return 0;
}