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
        float _lambda): min(_min), max(_max), lambda(_lambda) {

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

germinal_centre::germinal_centre(const germinal_centre & _gc) {
    
    
    /*
    // so, we need to copy across all the stuff from _gc
    // hopefully, without fucking the whole thing in half
    // Q: what happens if it's already initialised?
    // ... by which i mean *this ...
    // A: hang on, by default, this is a *constructor*, so by 
    //    the semantics of ctors, it shouldn't be already 
    //    constructed ...
    // so let's press on ...
    
    lambda=_gc.lambda;
    min=_gc.min;
    max=_gc.max;
    af = _gc.af;
    
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));

    // bit hacky, but this is how we create & initialise 
    // an array (use vector, then make_unique) ...
    for (int i = 0; i < _gc.af.size(); i++) {
        gc.push_back(af);
        std::cout << af << std::endl;
    }

    
    */
}