/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   random_integer_test.cpp
 * Author: johnny
 *
 * Created on 30 January 2019, 15:18
 */

//#include <cstdlib>
#include <iostream>
#include <vector>
#include "random_integer.h"

/*
 * 
 */
int main(int argc, char** argv) {

    const int max=31;
    random_integer i_dist(0,max);
    
    std::vector<int> histogram(max+1);
    for (int i=0; i< 10000; i++) 
        ++histogram[i_dist()];
    
    for (int i = 0; i!=histogram.size(); ++i) {
        std::cout << i << '\t';
        for (int j = 0; j != histogram[i]; ++j) 
            std::cout << '*';
        std::cout << std::endl;
    }
    
    return 0;
}

