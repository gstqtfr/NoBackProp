/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   random_integer.h
 * Author: johnny
 *
 * Created on 30 January 2019, 15:10
 */

#ifndef RANDOM_INTEGER_H
#define RANDOM_INTEGER_H

#include <random>

class random_integer {
public:
    random_integer(int low, int high): dist{low, high} {}
    int operator()() { return dist(re); }
    int get() { return dist(re); }
private:
    std::random_device r;
    std::default_random_engine re{r()};
    std::uniform_int_distribution<> dist;
};

#endif /* RANDOM_INTEGER_H */

