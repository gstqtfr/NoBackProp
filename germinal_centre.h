/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   germinal_centre.h
 * Author: johnny
 *
 * Created on 23 January 2019, 09:41
 */

#ifndef GERMINAL_CENTRE_H
#define GERMINAL_CENTRE_H

// in which we define The Flip out of a germinal centre

// a GC has to 
// a) accept an _addressable_float
// b) clone it
// c) hypermutate it
// d) apply the objective function
// e) return the most successful clone

// we also need to replace it in the antibody population, but
// this is a task for another object, i think ...

#include <memory>
#include <iostream>
#include <vector>
#include "addressable_float.h"
#include "random_integer.h"

class germinal_centre {
private:
    _addressable_float af;
    std::unique_ptr<random_integer> i_dist;
    std::vector<std::unique_ptr<_addressable_float>> gc;
    int min;
    int max;

    float lambda;
    // JKK: RESTORE TO PRIVATE once tested
    //const unsigned short inline get_hotspot() const; 
    //const unsigned short inline get_random_length() const


public:
    
    germinal_centre() { }
    
    germinal_centre(const int sz,
            const _addressable_float & _af, 
            int, 
            int, 
            float);
    
    germinal_centre(const germinal_centre &);
    
    ~germinal_centre() { 
        // do nothing, let the system worry about the 
        // unique_pointers ...
    }
    
    const int unsigned inline size() const {
        return af.size();
    }
    _addressable_float somatic_hypermutation(const _addressable_float & u);
    // JKK: RESTORE TO PRIVATE once tested
    int get_hotspot() const;
    int get_random_length() const;
    float exp_dist(float x) {
       return (lambda * exp(-lambda * x));
    }
};



#endif /* GERMINAL_CENTRE_H */

