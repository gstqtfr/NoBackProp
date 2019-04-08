/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "clone_and_mutate.h"

#include <iostream>
#include <random>
#include "s32bit.h"
#include "germinal_centre.h"

const bool verbose = true;

int germinal_centre::get_hotspot() const {
    return i_dist->get();
}

