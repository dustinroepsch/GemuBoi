#pragma once

#include <cstdint>

class Memory
{
    Memory() {};
  public:
    uint8_t readByte(uint16_t addr) const;
};