/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   random_float.h
 * Author: johnny
 *
 * Created on 31 January 2019, 14:22
 */

#ifndef RANDOM_FLOAT_H
#define RANDOM_FLOAT_H

#include <random>

class random_float {
public:
    random_float(float low, float high): dist{low, high} {}
    float get() { return dist(re); }
private:
    std::random_device r;
    std::default_random_engine re{r()};
    std::uniform_real_distribution<> dist;
};

#endif /* RANDOM_FLOAT_H */

