#ifndef LOCATION_H
#define LOCATION_H

#include"math.h"
#include<assert.h>
#include<iostream>

using std::string;
using std::endl;
using std::cout;

class float2;

class Location
{
    private:
    public:
        // Center of any body
        int /*worldLoc*/x;
        int /*worldLoc*/y;

        int /*tileOffs*/ox;
        int /*tileOffs*/oy;


    //functions:
        Location(int x, int y, int offsx=0, int offsy=0);
        Location operator-(float2 xypair) const;
        Location operator+(float2 xypair) const;
        void print(string name="");
};

//Location operator-(const Location& l, const int2& xypair);
#endif
