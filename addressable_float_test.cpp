/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   addressable_float_test.cpp
 * Author: johnny
 *
 * Created on 18 February 2019, 17:02
 */

#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <stdexcept>
#include "addressable_float.h"

/*
 * 
 * compile short cut:
 * 
 * g++ -std=c++17 -o addressable_float_test addressable_float.cpp addressable_float_test.cpp
 * 
 */
int main(int argc, char** argv) {

    std::cout << "building an _addressable_float" << std:: endl;
    
    /*
     * we'll have to do all the random number generator stuff here ...
     */
    
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> r_dist(-1, 1);
    // ... yuk ...
    std::uniform_int_distribution<> i_dist(0, 32);
    
    float f=r_dist(e2);
    u32bits u32;
    u32.f=f;
    
    _addressable_float af1(f);
    std::cout << "built    an _addressable_float using float ctor" << std:: endl;
    std::cout << af1 << std::endl;
    
    _addressable_float af2(u32);
    std::cout << "built    an _addressable_float using u32 ctor" << std:: endl;
    std::cout << af2 << std::endl;
    
    _addressable_float af3(af1);
    std::cout << "built    an _addressable_float using copy ctor" << std:: endl;
    std::cout << af3 << std::endl;
    
    _addressable_float af4 = af3;
    std::cout << "built    an _addressable_float using  copy assignment op=" << std:: endl;
    std::cout << af4 << std::endl;
    
    
    if (true) {
        _addressable_float af5 = af3;
        std::cout << "built    an _addressable_float using  copy assignment op=" << std:: endl;
        std::cout << af5 << std::endl;
        std::cout << "testing  the destructor ..." << std:: endl;
    }
    
    // so, if this thing hasn't thrown an exception, we *should* be good ...
    // so far so good ...
    
    _addressable_float af5 = _addressable_float();
    std::cout << "built    an _addressable_float using  rvalue move ctor" << std:: endl;
    std::cout << af5 << std::endl;
    
    _addressable_float af6;
    af6 = std::move(af3);
    std::cout << "built    an _addressable_float using operator=(_addressable_float&& other" << std::endl; 
    std::cout << af6 << std::endl;
     
    return 0;
}

