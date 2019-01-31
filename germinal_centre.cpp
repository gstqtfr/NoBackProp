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
//std::random_device rd;
//std::mt19937 e2(rd);

const bool verbose = true;
// _addressable_fields? or u32bits?

int germinal_centre::get_hotspot() {
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
        int min, 
        int max) {

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
