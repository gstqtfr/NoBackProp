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

// JKK: question here is, do we use the gradual decay
// JKK: hack here? seems like the most obvious, & useful,
// JKK: but not as general, so use exp_dist()

int germinal_centre::get_random_length() const {
    return i_dist->get();
}

void germinal_centre::mutate_clone_pool() {

    // JKK: dah, fuck. forgot i was dealing with a unique_ptr here ...

    // JKK: from 
    // https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
    
    // You need to move the unique_ptr:
    // vec.push_back(std::move(ptr2x));
    
    

    /*
    for (int i=0; i < size(); i++) {
        _addressable_float antibody = *gc.at(i);
        std::cout << "mutate_clone_pool(): got " << antibody << std::endl;
        auto mutant = somatic_hypermutation(antibody);
        // now replace the antibody in the clonal pool
        gc.at(i) = antibody;
    }
     */



    // JKK: then, somewhere here, we need to get the fitness (?!...)
    // JKK: actually, no, the complementarity is det'd outside this
    // JKK: class. so we just present the clonal pool, then clone the
    // JKK: best matching antibody ... job done!
}

// JKK: make this inline? private? (i.e. just get hotspot)

_addressable_float germinal_centre::somatic_hypermutation(const _addressable_float & af) {

    auto hotspot = i_dist->get();
    std::cout << "som_hype: hotspot: " << hotspot << std::endl;

    auto _length = get_random_length();
    std::cout << "som_hype: (int) _length: " << _length << std::endl;

    auto length = exp_dist(_length);
    std::cout << "som_hype: (float) length: " << _length << std::endl;

    // JKK: er ... add code ... good code. that works.

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

germinal_centre::germinal_centre(const germinal_centre & other) :
min(other.min), max(other.max), lambda(other.lambda), af(other.af) {
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
    // also, creates a clonal pool
    for (int i = 0; i < other.af.size(); i++) {
        gc.push_back(std::make_unique<_addressable_float>(af));
        std::cout << "copy ctor: " << af << std::endl;
    }
}

// copy assignment operator
// slightly diff. logic to the copy ctor

germinal_centre & germinal_centre::operator=(const germinal_centre & other) {
    if (this != &other) { // self-assignment check expected
        // need to delete our unique_pointers
        while (!gc.empty()) {
            gc.pop_back();
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

// move assignment operator ...
// this is (relatively) new, refer to e.g. 
// https://smartbear.com/blog/develop/c11-tutorial-introducing-the-move-constructor-and/

germinal_centre & germinal_centre::operator=(const germinal_centre && other) {

    if (this != &other) { // self-assignment check expected
        while (!gc.empty()) {
            gc.pop_back();
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
            std::cout << "op=  ctor(&&): " << af << std::endl;
        }
    }
    return *this;
}

germinal_centre::germinal_centre(const germinal_centre && other) :
lambda(other.lambda), min(other.min), max(other.max), af(other.af) {

    // then copy the RHS data ...
    i_dist = std::unique_ptr<random_integer>(new random_integer(min, max));
    // this has the side effect of creating a clonal pool
    for (int i = 0; i < other.af.size(); i++) {
        gc.push_back(std::make_unique<_addressable_float>(af));
        std::cout << "move ctor: " << af << std::endl;
    }
}
