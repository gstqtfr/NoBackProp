/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test_32bit.cpp
 * Author: johnny
 *
 * Created on 23 January 2019, 14:59
 */


#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <stdexcept>
#include "s32bit.h"
#include "addressable_float.h"
#include "germinal_centre.h"

/*
 * 
 * Guess what this function is ...
 *  
 */
int main(int argc, char** argv) {

    std::cout << "building an _addressable_float" << std:: endl;
    
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(-1, 1);
  
    
    //short float sf=0;
    
    // so let's get this tested ...
    
    float f=dist(e2);
    u32bits u32;
    u32.f=f;
    
    _addressable_float af1(f);
    std::cout << "built    an _addressable_float from a float" << std:: endl;
    std::cout << af1 << std::endl;
    
    
    _addressable_float af2(u32);
    std::cout << "built    an _addressable_float from a u32bits union" << std:: endl;
    std::cout << af2 << std::endl;
    
    // JKK: cool. what do i prod with a stick next?
    // JKK: could do bit addressing, e.g. flip the sign bit ...
 
    const short sign_bit=af1.size()-1;
    std::cout << "sign bit: " << af1.get(sign_bit) << std::endl;
    std::cout << "float: " << af1.getf() << std::endl;
    af1.set(sign_bit, ! af1.get(sign_bit));
    std::cout << "sign bit NOW: " << af1.get(sign_bit) << std::endl;
    std::cout << "float NOW: " << af1.getf() << std::endl;
    
    
    // let's give this a whole bunch of random integers & see if 
    // the exception-throwing mechanism works okay ...
    
    std::cout << std::endl << "trying a deliberately fukd index" 
            << std::endl;
    
    try {
        af2.get(301);
    } catch ( const std::invalid_argument& e) {
        std::cout << "received exception: " << e.what() << std::endl;
    }
    
    // JKK: right, looking pretty good. now the germinal centres ...
    // JKK: back again, couple of days later ... let's get going ...
    
    const int N=20;
    germinal_centre gc1(N, af1);
    
    std::cout << "germinal centre::size == " << gc1.size()
            << std::endl;
    
    
    
    
    return 0;
}

