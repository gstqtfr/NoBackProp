/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "clone_and_mutate.h"

#include <iostream>
#include <random>
#include "s32bit.h"
#include "germinal_centre.h"

const bool verbose = true;

int clone_and_mutate::get_hotspot() const {
    return i_dist->get();
}

int clone_and_mutate::get_random_length() const {
    return i_dist->get();
}

// param-heavy ctor 
clone_and_mutate::clone_and_mutate(const int _sz,
        const _addressable_float & _af,
        const int _min,
        const int _max,
        const float _lambda):
af(_af), min(_min), max(_min), lambda(_lambda) {

    // JKK: we use the _sz param. to initialise the
    // JKK: list ...

    // JKK: also, we need to get the random number 
    // JKK: generators constructed here ...

    // gives us our hotspot (length, too? maybe ...)
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max)); 
    // 1? 0? i_binary decides, so you don't have to!
    i_binary = std::unique_ptr<random_integer>(new random_integer(0, 1));
    
    // create the clonal pool
    for (int i = 0; i < _sz; i++) {
        clonal_pool.push_back(af._addressable_float_reference_factory(af));
    }
}

// copy ctor
clone_and_mutate::clone_and_mutate(const clone_and_mutate & other):
    min(other.min), max(other.max), lambda(other.lambda), af(other.af) {
    
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
    i_binary = std::unique_ptr<random_integer>(new random_integer(0, 1));
    
    // also, creates a clonal pool
    for (int i = 0; i < other.size(); i++) {
        clonal_pool.push_back(af._addressable_float_reference_factory(af));
    }
}

// assignment op=
clone_and_mutate & clone_and_mutate::operator=(const clone_and_mutate & other) {
    if (this != &other) { // self-assignment check expected
        while (!clonal_pool.empty()) {
            clonal_pool.pop_back();
        }
        // then copy the RHS data ...
        lambda = other.lambda;
        min = other.min;
        max = other.max;
        af = other.af;
        i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
        // JKK: *think* this is okay ... but test it to destruction, just
        // JKK: in case ...
        i_binary = std::unique_ptr<random_integer>(new random_integer(0, 1));
        
        for (int i = 0; i < other.size(); i++) {
            clonal_pool.push_back(af._addressable_float_reference_factory(af));
            // std::cout << "op=  ctor: " << af << std::endl;
        }
    }
    return *this;
}

clone_and_mutate & clone_and_mutate::operator=(const clone_and_mutate && other) {
    
    if (this != &other) { // self-assignment check expected
        while (!clonal_pool.empty()) {
            clonal_pool.pop_back();
        }
        // then copy the RHS data ...
        lambda = other.lambda;
        min = other.min;
        max = other.max;
        af = other.af;
        i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
        i_binary = std::unique_ptr<random_integer>(new random_integer(0, 1));
        
        for (int i = 0; i < other.size(); i++) {
            clonal_pool.push_back(af._addressable_float_reference_factory(af));
        }
    }
    return *this;
}


clone_and_mutate::clone_and_mutate(const clone_and_mutate && other):
    lambda(other.lambda), min(other.min), max(other.max), af(other.af) {
    
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
    i_binary = std::unique_ptr<random_integer>(new random_integer(0, 1));
    
    for (int i = 0; i < other.size(); i++) {
        clonal_pool.push_back(af._addressable_float_reference_factory(af)); 
    }
    
    return *this;
}

clone_and_mutate()::~clone_and_mutate() { }


