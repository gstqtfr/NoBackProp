/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clone_and_mutate.h
 * Author: johnny
 *
 * Created on 08 April 2019, 20:08
 */

#ifndef CLONE_AND_MUTATE_H
#define CLONE_AND_MUTATE_H

#include <memory>
#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include "addressable_float.h"
#include "random_integer.h"

class clone_and_mutate {
private:
    _addressable_float af;
    std::unique_ptr<random_integer> i_dist;
    std::unique_ptr<random_integer> i_binary;
    std::list<_addressable_float> clonal_pool;
    int min;
    int max;
    float lambda;
    
    float exp_dist(float x) const {
        return (lambda * exp(-lambda * x));
    }

public:

    clone_and_mutate() { }

    clone_and_mutate(const int,
            const _addressable_float &,
            const int,
            const int,
            const float);

    clone_and_mutate(const clone_and_mutate &);

    clone_and_mutate(const clone_and_mutate &&);

    clone_and_mutate & operator=(const clone_and_mutate &);

    clone_and_mutate & operator=(const clone_and_mutate &&);

    ~clone_and_mutate();

    const int unsigned inline size() const {
        return clonal_pool.size();
    }

    void mutate_clone_pool();

    _addressable_float & somatic_hypermutation(const _addressable_float &);

    const int get_hotspot() const;

    const int get_random_length() const;


};

#endif /* CLONE_AND_MUTATE_H */