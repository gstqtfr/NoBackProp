/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <random>
#include "s32bit.h"
#include "germinal_centre.h"

const bool verbose = true;

int germinal_centre::get_hotspot() const {
    return i_dist->get();
}

int germinal_centre::get_random_length() const {
    return i_dist->get();
}

// JKK: make this inline? private? (i.e. just get hotspot)

_addressable_float germinal_centre::somatic_hypermutation(const _addressable_float & af) {

    auto hotspot = i_dist->get();
    std::cout << hotspot << std::endl;

    return af;
}

// : connections_dist(1, operatorsCount)

germinal_centre::germinal_centre(const int sz,
        const _addressable_float & _af,
        int _min,
        int _max,
        float _lambda) : min(_min), max(_max), lambda(_lambda) {

    af = _af;
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));

    // bit hacky, but this is how we create & initialise 
    // an array (use vector, then make_unique) ...
    for (int i = 0; i < sz; i++) {
        gc.push_back(af._addressable_float_factory(af));
    }

    // iterate through these guys & initialise with the
    // _addressable_float param
    for (const auto& af : gc) {
        std::wcout << "Original float: " << af->getf() << std::endl;
    }

    // we'll need to get the original floats mutated here ...

    // JKK: 2DO: need a way of passing these parameters into
    // JKK: 2DO: the constructor & initialising them there ...
}

// JKK: hang on a tick - what about random number gens?

germinal_centre::germinal_centre(const germinal_centre & other): 
    min(other.min), max(other.max), lambda(other.lambda), af(other.af) {
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
    // also, creates a clonal pool
    for (int i = 0; i < other.af.size(); i++) {
        gc.push_back(std::make_unique<_addressable_float>(af));
        std::cout << "copy ctor: " << af << std::endl;
    }
}

// copy assignment operator
germinal_centre & germinal_centre::operator=(const germinal_centre & other) {
    if (this != &other) { // self-assignment check expected
        if (other.size() != size()) {
            // need to delete our unique_pointers
            while (!gc.empty()) {
                gc.pop_back();
            }
        }
        // then copy the RHS data ...
        lambda = other.lambda;
        min = other.min;
        max = other.max;
        af = other.af;
        i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
        // this has the side effect of creating a clonal pool
        for (int i = 0; i < other.af.size(); i++) {
            gc.push_back(std::make_unique<_addressable_float>(af));
            std::cout << "op=  ctor: " << af << std::endl;
        }
    }
    return *this;
}
