/*Copyright [2022] <Michael Chagnon>*/
#include "FibLFSR.h"
#include <iostream>
#include <string>

FibLFSR::FibLFSR(std::string input) {
seed = input;
}

std::ostream & operator << (std::ostream &out, const FibLFSR &c) {
    out << c.seed;
return out;
}

int FibLFSR::step() {
int bit = 0;

    if (seed[0] == '1') {
        tap15 = 1;
    } else if (seed[0] == '0') {
        tap15 = 0;
    }

    if (seed[2] == '1') {
        tap13 = 1;
    } else if (seed[2] == '0') {
        tap13 = 0;
    }

    if (seed[3] == '1') {
        tap12 = 1;
    } else if (seed[3] == '0') {
        tap12 = 0;
    }

    if (seed[5] == '1') {
        tap10 = 1;
    } else if (seed[5] == '0') {
        tap10 = 0;
    }


    if ((tap15 - tap13) != 0) {
        bit = 1;
    } else {
        bit = 0;
    }
    if ((bit - tap12) != 0) {
        bit = 1;
    } else {
        bit = 0;
    }

    if ((bit - tap10) != 0) {
        bit = 1;
    } else {
        bit = 0;
    }

    seed.erase(seed.begin());
    seed.push_back(bit + 48);

return bit;
}

int FibLFSR::generate(int k) {
int var = 0;

    for (int i = 0; i < k; i++) {
        var = (var * 2) + step();
    }
return var;
}
