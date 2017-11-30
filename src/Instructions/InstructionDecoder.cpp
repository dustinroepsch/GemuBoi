#include "InstructionDecoder.hpp"

#include <iostream>
#include <iomanip>

InstructionDecoder::InstructionDecoder(std::ifstream jsonFile)
{
    jsonFile >> opcodeTable;
    usePrefixOperator = false;
}

void InstructionDecoder::mapInstructions()
{
    //nop
    unprefixedOpcodes[0x00] = [](Registers &registers, Memory &memory) {
        registers.incPC(1);
        return 4;
    };
}

void InstructionDecoder::printUnimplError(uint8_t opcode, bool usePrefixOperator)
{
    std::cout << "UnImpl Instruction!" << std::endl;
    std::stringstream hexOP;
    hexOP << "0x" << std::hex << opcode;
    if (usePrefixOperator)
    {
        std::cout << opcodeTable["prefixed"][hexOP.str()];
    }
    else
    {
        std::cout << opcodeTable["unprefixed"][hexOP.str()];
    }
}

std::function<int(Registers &, Memory &)> InstructionDecoder::getInstruction(const Registers &registers, const Memory &memory, uint8_t opcode)
{
    if (usePrefixOperator)
    {
        uint8_t actualOpcode = memory.readByte((uint16_t)registers.getPC() + 1);

        if (prefixedOpcodes[actualOpcode])
        {
            return prefixedOpcodes[actualOpcode];
        }
        else
        {
            printUnimplError(opcode, usePrefixOperator);
            return unprefixedOpcodes[0x00];
        }
    }
    else
    {
        if (unprefixedOpcodes[opcode])
        {
            return unprefixedOpcodes[opcode];
        }
        else
        {
            printUnimplError(opcode, usePrefixOperator);
            return unprefixedOpcodes[0x00];
        }
    }
}
