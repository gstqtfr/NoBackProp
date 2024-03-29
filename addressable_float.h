/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   addressable_float.h
 * Author: johnny
 *
 * Created on 21 January 2019, 12:47
 */

#ifndef ADDRESSABLE_FLOAT_H
#define ADDRESSABLE_FLOAT_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "s32bit.h"

class _addressable_float {
private:
    u32bits _u;

    bool inside_range(unsigned pos, unsigned val) const {
        if ((pos < 0) || (pos > size() - 1)) {
            return false;
        }

        if ((val != 0) && (val != 1)) {
            return false;
        }

        return true;
    }

public:

    // a default constructor: X()
    _addressable_float() {
        std::cout << "_addressable_float::default ctor" << std::endl;
        _u.f = 0.0;
    }

    //the slightly odd destructor thing - declare here &
    // define in the .cpp file (?!)
    ~_addressable_float();
    
    // exp. ctor for tyoe float
    explicit _addressable_float(float f) {
        std::cout << "_addressable_float::explicit float ctor" << std::endl;
        _u.f = f;
    }

    // exp. ctor for type u32bits
    explicit _addressable_float(u32bits uf) {
        std::cout << "_addressable_float::explicit u32bits ctor" << std::endl;
        _u = uf;
    }

    // JKK: since this is a union, we don't have to
    // JKK: worry about init'g the bit field

    // a copy constructor: X(const X&)
    _addressable_float(const _addressable_float & af) {
         std::cout << " _addressable_float(const _addressable_float) ctor" << std::endl;
        _u.f = af._u.f;
    }

    // a copy assignment: operator=(const X&)
    _addressable_float operator=(const _addressable_float & af) {
        std::cout << "_addressable_float operator=(const _addressable_float & af) ctor" << std::endl;
        _u.f = af._u.f;
        return *this;
    }
    
    // a move constructor: X(X&&)
    _addressable_float(_addressable_float&& af) {
       std::cout << " _addressable_float(const _addressable_float&& ) (rvalue) ctor" << std::endl; 
       _u.f = af._u.f;
    }
    
    // a move assignment: operator=(X&&)
    _addressable_float & operator=(_addressable_float&& other) {
        std::cout << "operator=(_addressable_float&& other (rvalue)" << std::endl;
        _u.f = other._u.f;
        return *this;
    }
    
    int size() const {
        return 32;
    }

    float getf() const {
        return _u.f;
    }

    unsigned get(unsigned pos) const {
        unsigned val = 0;
        if (!inside_range(pos, val)) {
            std::string err_msg = "received position argument "
                    + std::to_string(pos)
                    + ", which is out of range";
            throw std::invalid_argument(err_msg);
        }
        switch (pos) {
            case 31:
                val = _u.bits.s;
                break;
            case 30:
                val = _u.bits.e0;
                break;
            case 29:
                val = _u.bits.e1;
                break;
            case 28:
                val = _u.bits.e2;
                break;
            case 27:
                val = _u.bits.e3;
                break;
            case 26:
                val = _u.bits.e4;
                break;
            case 25:
                val = _u.bits.e5;
                break;
            case 24:
                val = _u.bits.e6;
                break;
            case 23:
                val = _u.bits.e7;
                break;
            case 22:
                val = _u.bits.s0;
                break;
            case 21:
                val = _u.bits.s1;
                break;
            case 20:
                val = _u.bits.s2;
                break;
            case 19:
                val = _u.bits.s3;
                break;
            case 18:
                val = _u.bits.s4;
                break;
            case 17:
                val = _u.bits.s5;
                break;
            case 16:
                val = _u.bits.s6;
                break;
            case 15:
                val = _u.bits.s7;
                break;
            case 14:
                val = _u.bits.s8;
                break;
            case 13:
                val = _u.bits.s9;
                break;
            case 12:
                val = _u.bits.s10;
                break;
            case 11:
                val = _u.bits.s11;
                break;
            case 10:
                val = _u.bits.s12;
                break;
            case 9:
                val = _u.bits.s13;
                break;
            case 8:
                val = _u.bits.s14;
                break;
            case 7:
                val = _u.bits.s15;
                break;
            case 6:
                val = _u.bits.s16;
                break;
            case 5:
                val = _u.bits.s17;
                break;
            case 4:
                val = _u.bits.s18;
                break;
            case 3:
                val = _u.bits.s19;
                break;
            case 2:
                val = _u.bits.s20;
                break;
            case 1:
                val = _u.bits.s21;
                break;
            case 0:
                val = _u.bits.s22;
                break;

        }
        return val;

    }

    // TODO: JKK: needs a template? i.e. for int, short, etc. ...

    unsigned set(unsigned pos, unsigned val) {
        // JKK: exception? error message? eh? dunno ...
        // JKK: exception. if this occurs, there's some major
        // JKK: major issue with the code - really shouldn't happen ...

        if (!inside_range(pos, val)) {
            throw "Parameter out of range";
        }

        switch (pos) {
            case 31:
                _u.bits.s = val;
                break;
            case 30:
                _u.bits.e0 = val;
                break;
            case 29:
                _u.bits.e1 = val;
                break;
            case 28:
                _u.bits.e2 = val;
                break;
            case 27:
                _u.bits.e3 = val;
                break;
            case 26:
                _u.bits.e4 = val;
                break;
            case 25:
                _u.bits.e5 = val;
                break;
            case 24:
                _u.bits.e6 = val;
                break;
            case 23:
                _u.bits.e7 = val;
                break;
            case 22:
                _u.bits.s0 = val;
                break;
            case 21:
                _u.bits.s1 = val;
                break;
            case 20:
                _u.bits.s2 = val;
                break;
            case 19:
                _u.bits.s3 = val;
                break;
            case 18:
                _u.bits.s4 = val;
                break;
            case 17:
                _u.bits.s5 = val;
                break;
            case 16:
                _u.bits.s6 = val;
                break;
            case 15:
                _u.bits.s7 = val;
                break;
            case 14:
                _u.bits.s8 = val;
                break;
            case 13:
                _u.bits.s9 = val;
                break;
            case 12:
                _u.bits.s10 = val;
                break;
            case 11:
                _u.bits.s11 = val;
                break;
            case 10:
                _u.bits.s12 = val;
                break;
            case 9:
                _u.bits.s13 = val;
                break;
            case 8:
                _u.bits.s14 = val;
                break;
            case 7:
                _u.bits.s15 = val;
                break;
            case 6:
                _u.bits.s16 = val;
                break;
            case 5:
                _u.bits.s17 = val;
                break;
            case 4:
                _u.bits.s18 = val;
                break;
            case 3:
                _u.bits.s19 = val;
                break;
            case 2:
                _u.bits.s20 = val;
                break;
            case 1:
                _u.bits.s21 = val;
                break;
            case 0:
                _u.bits.s22 = val;
                break;

        }

        return pos;
    }

    std::unique_ptr<_addressable_float> _addressable_float_factory(const _addressable_float & __af) const {
        return std::make_unique<_addressable_float>(__af);
    }
   
    _addressable_float _addressable_float_reference_factory(const _addressable_float & __af) const {
        _addressable_float _af = __af;
        return _af;
    }
    
    friend std::ostream & operator<<(std::ostream &, const _addressable_float &);
};

#endif /* ADDRESSABLE_FLOAT_H */

