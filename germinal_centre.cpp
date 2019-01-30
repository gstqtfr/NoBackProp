/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <random>
#include "s32bit.h"
#include "germinal_centre.h"


// JKK: fucking 'orrible ... but this is how it's done, apparently ...
// JKK: need to find a way of doing this properly ...
std::random_device rd;
std::mt19937 e2(rd);

const bool verbose=true;
// _addressable_fields? or u32bits?

const unsigned short germinal_centre::get_hotspot() const {
    
    auto hotspot = disti(e2);
    if (verbose)
        std::cout << hotspot << std::endl;
    
    return hotspot;
}

const unsigned short germinal_centre::get_random_length() const {
    

    return 0;
}


// JKK: make this inline? private? (i.e. just get hotspot)

_addressable_float germinal_centre::somatic_hypermutation(const _addressable_float & af) {

    auto hotspot = disti(e2);
    std::cout << hotspot << std::endl;
    
    return af;
}

// : connections_dist(1, operatorsCount)

germinal_centre::germinal_centre(const int sz, const _addressable_float & af) {
        // bit hacky, but this is how we create & initialise 
        // an array (use vector, then make_unique) ...
        for (int i = 0; i < sz; i++) {
            gc.push_back(std::make_unique<_addressable_float>(af));
        }

        // iterate through these guys & initialise with the
        // _addressable_float param
        for (const auto& af : gc) {
            std::wcout << "Original float: " << af->getf() << std::endl;
        }
        
        // we'll need to get the original floats mutated here ...
        
        // JKK: 2DO: need a way of passing these parameters into
        // JKK: 2DO: the constructor & initialising them there ...
        
        disti = std::uniform_int_distribution<>(0,sz-1);
        distr = std::uniform_real_distribution<> distr(-1, 1);
        
        
    }
