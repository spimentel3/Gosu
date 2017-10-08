#ifndef MATH_H
#define MATH_H

#include"location.h"

class Location;

class int2
{
    private:
    public:
        int x;
        int y;

    //functions:
        int2(int x=0, int y=0);
        int2 operator*(int) const;
        int2 operator/(int) const;
};

class float2
{
    private:
    public:
        float x;
        float y;

    //functions:
        float2(float x, float y);
        float2 operator*(float) const;
        float2 operator/(float) const;
        float2& operator=(float2&);
};

Location topLeft(Location, int2 Radius);
Location topRight(Location, int2 Radius);
Location botLeft(Location, int2 Radius);
Location botRight(Location, int2 Radius);

Location topLeft(Location, float2 Radius);
Location topRight(Location, float2 Radius);
Location botLeft(Location, float2 Radius);
Location botRight(Location, float2 Radius);

#endif
