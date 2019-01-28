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

class germinal_centre {
private:
    
    std::vector<std::unique_ptr<_addressable_float>> gc;
    std::uniform_int_distribution<int> distr; // guaranteed unbiased

public:

    // JKK: might need make_unique_default_init here ...

    germinal_centre(const int sz, const _addressable_float & af); 

    const long unsigned size() const { return gc.size(); }

    _addressable_float somatic_hypermutation(const _addressable_float & u);
};



#endif /* GERMINAL_CENTRE_H */

