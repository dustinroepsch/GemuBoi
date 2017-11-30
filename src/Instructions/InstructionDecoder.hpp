#pragma once

#include <fstream>
#include <functional>

#include "../json.hpp"
#include "../Registers/Registers.hpp"
#include "../Memory/Memory.hpp"

using json = nlohmann::json;

class InstructionDecoder
{
  public:
    InstructionDecoder(std::ifstream jsonFile);

    //instructions are functions that take the registers and memory, and return the number
    //of clock cycles it takes to execute that instruction
    std::function<int(Registers &, Memory &)> getInstruction(const Registers &registers, const Memory &memory, uint8_t opcode);

  private:
    void mapInstructions();
    void printUnimplError(uint8_t opcode, bool usePrefixOperator);

    bool usePrefixOperator;

    json opcodeTable;
    std::array<std::function<int(Registers &, Memory &)>, 255> unprefixedOpcodes;
    std::array<std::function<int(Registers &, Memory &)>, 255> prefixedOpcodes;
};