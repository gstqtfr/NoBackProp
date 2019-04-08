/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "s32bit.h"
#include "addressable_float.h"

_addressable_float::~_addressable_float() { }

std::ostream & operator<<(std::ostream & os, const _addressable_float & af) 
{

  os << std::setw(10);
  //os << af.getf() << std::endl;
  // JKK: need to output the bits here too ...
  // JKK: ... also need to sort out the "size" issue ...
  for (auto i = 0; i < af.size(); i++)
    {
      os << af.get(i);
    }
  return os;
}