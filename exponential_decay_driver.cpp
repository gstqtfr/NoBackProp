/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exponential_decay_driver.cpp
 * Author: johnny
 *
 * Created on 31 January 2019, 19:16
 */

#include <cmath>
#include <iostream>
#include "germinal_centre.h"
#include "random_integer.h"
#include "random_float.h"
#include "addressable_float.h"

const double N = 32.0;

float exp_dist(float x, float lambda) {
    return (lambda * exp(-lambda * x));
}

/*
 * 
 */
int main(int argc, char** argv) {

    for (double lambda = 1/N; lambda <= 0.5; lambda += 1/N) {
        std::cout << lambda << " " << std::endl;
        for (int i = 0; i < N; i++) {
            double x = double(i);
            std::cout << x << " " << lambda << " " 
                    << exp_dist(x, lambda) << std::endl;
        }
        std::cout << std::endl;
    }
    
    const int max=31;
    const int N=50;
    random_integer i_dist(0,max);  
    random_float r_dist(-10,10);
    float f=r_dist.get();
    u32bits u32;
    u32.f=f;
    
    _addressable_float af1(f);
    std::cout << "built    an _addressable_float from a float" << std:: endl;
    std::cout << af1 << std::endl;

    float _lambda=0.25;
    germinal_centre gc1(N, af1, 0, 31, _lambda);
    
    // let's instantiate a germinal centre, start mucking about with it
    // then we can sort the implementation of hotspot & length ...

    for (int i=0; i <N; i++) {
        // this is what we get from the gc ATM ...
        std::cout << gc1.get_hotspot() << std::endl;
        // ... & we want to bias it ...
        
    }

    return 0;
}
