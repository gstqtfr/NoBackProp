#include <iostream>
#include <iomanip>
#include "s32bit.h"


const int u32_size = 32;

std::ostream & operator<<(std::ostream & os, u32bits & u32) 
{

  os << std::setw(10);
  os << u32.f << std::endl;
  // JKK: need to output the bits here too ...
  // JKK: ... also need to sort out the "size" issue ...
  
  return os;
}

