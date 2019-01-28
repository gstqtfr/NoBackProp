/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <random>
#include "s32bit.h"
#include "germinal_centre.h"


// fucking 'orrible ... but this is how it's done, apparently ...
std::random_device rd;
std::mt19937 gen(rd());

// _addressable_fields? or u32bits?

_addressable_float germinal_centre::somatic_hypermutation(const _addressable_float & af) {

    auto hotspot = distr(gen);
    std::cout << hotspot << std::endl;
    
    return af;
}




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
        
        distr = std::uniform_int_distribution<>(0,sz-1);
        
    }
