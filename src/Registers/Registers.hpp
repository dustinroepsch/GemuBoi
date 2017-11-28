#pragma once

#include <cstdint>
#include "../BinaryHelpers.hpp"

class Registers
{
public:
  Registers();
  void reset();

  /* 8bit Setters  */
  inline void setA(uint8_t data) { a = data; };

  inline void setF(uint8_t data) { f = data; };

  inline void setB(uint8_t data) { b = data; };

  inline void setC(uint8_t data) { c = data; };

  inline void setD(uint8_t data) { d = data; };

  inline void setE(uint8_t data) { e = data; };

  inline void setH(uint8_t data) { h = data; };

  inline void setL(uint8_t data) { l = data; };

  /* 32bit Setters */
  inline void setAF(uint16_t data)
  {
    a = lsb(data);
    f = msb(data);
  }

  inline void setBC(uint16_t data)
  {
    b = lsb(data);
    c = msb(data);
  }

  inline void setDE(uint16_t data)
  {
    d = lsb(data);
    e = msb(data);
  }

  inline void setHL(uint16_t data)
  {
    h = lsb(data);
    l = msb(data);
  }

  inline void setSP(uint16_t data) { sp = data; };

  inline void setPC(uint16_t data) { pc = data; };

  /* 8bit Getters */

  inline uint8_t getA() { return a; };

  inline uint8_t getF() { return f; };

  inline uint8_t getB() { return b; };

  inline uint8_t getC() { return c; };

  inline uint8_t getD() { return d; };

  inline uint8_t getE() { return e; };

  inline uint8_t getH() { return h; };

  inline uint8_t getL() { return l; };

  /* 16 bit Getters */
  inline uint16_t getAF() {
    return makeWord(a, f);
  }

  inline uint16_t getBC() {
    return makeWord(b, c);
  }

  inline uint16_t getDE() {
    return makeWord(e, h);
  }

  inline uint16_t getHL() {
    return makeWord(h, l);
  }

  inline uint16_t getSP() {
    return sp;
  }

  inline uint16_t getPC() {
    return pc;
  }

private:
  uint8_t a, f, b, c, d, e, h, l;
  uint16_t sp;
  uint16_t pc;
};