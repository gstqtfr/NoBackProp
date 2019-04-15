/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test_clone_and_mutate.cpp
 * Author: johnny
 *
 * Created on 15 April 2019, 14:42
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
#include "clone_and_mutate.h"


/*
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
    std::cout << "built    an _addressable_float from a float" << std:: endl;
    std::cout << af1 << std::endl;
    
    const int N=50;
    
    clone_and_mutate cam1(N, af1, 0, 20, 0.25);
    
    
    
    return 0;
}

