/*Copyright [2022] <Michael Chagnon>*/
#pragma once
#ifndef FIBLFSR_H_
#define FIBLFSR_H_
#include <iostream>
#include <string>

class FibLFSR{
 public:
    explicit FibLFSR(std::string seed);  // constructor to create LFSR
     // with the given initial seed
    int step();  // simulate one step and return the new bit as 0 or 1
    int generate(int k);  // simulate k steps and return k-bit integer
    friend std::ostream& operator << (std::ostream &out, const FibLFSR &c);

 private:
    std::string seed;
    int tap10;
    int tap12;
    int tap13;
    int tap15;
};

#endif
