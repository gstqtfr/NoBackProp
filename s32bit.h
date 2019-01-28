#ifndef S32BIT_H
#define S32BIT_H

//This is from: https://steve.hollasch.net/cgindex/coding/ieeefloat.html

/*

Floating Point Components
Sign	Exponent	Fraction
Single Precision	1 [31]	8 [30–23]	23 [22–00]
Double Precision	1 [63]	11 [62–52]	52 [51–00]
Laid out as bits, floating point numbers look like this:

Single: SEEEEEEE EFFFFFFF FFFFFFFF FFFFFFFF
Double: SEEEEEEE EEEEFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF

 */

struct _s32bits {
    unsigned int s22 : 1;
    unsigned int s21 : 1;
    unsigned int s20 : 1;
    unsigned int s19 : 1;
    unsigned int s18 : 1;
    unsigned int s17 : 1;
    unsigned int s16 : 1;
    unsigned int s15 : 1;
    unsigned int s14 : 1;
    unsigned int s13 : 1;  
    unsigned int s12 : 1;
    unsigned int s11 : 1;
    unsigned int s10 : 1;
    unsigned int s9 : 1;
    unsigned int s8 : 1;
    unsigned int s7 : 1;
    unsigned int s6 : 1;
    unsigned int s5 : 1;
    unsigned int s4 : 1;
    unsigned int s3 : 1;
    unsigned int s2 : 1;
    unsigned int s1 : 1;
    unsigned int s0 : 1;
    unsigned int e7 : 1;
    unsigned int e6 : 1;
    unsigned int e5 : 1;
    unsigned int e4 : 1;
    unsigned int e3 : 1;
    unsigned int e2 : 1;
    unsigned int e1 : 1;
    unsigned int e0 : 1;
    unsigned int s : 1;
};


union u32bits {
    _s32bits bits;
    float f;
};


// JKK: do we make size a member or friend function?
std::ostream & operator<<(std::ostream &, u32bits &);


#endif
