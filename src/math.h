#ifndef MATH_H
#define MATH_H

#include"location.h"
#include<iostream>

class Location;

class int2
{
    private:
    public:
        int x;
        int y;

    //functions:
        int2(int x, int y);
        int2(int a=0);
        int2& operator=(int);
        int2 operator*(int) const;
        int2 operator-() const;     // Unary minus
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
        float2 operator+(const float2) const;
        float2 operator-() const;       // Unary minus
        float2 operator/(float) const;
        float2& operator=(const float2&);
        float2& operator*=(const float2&);
        float2& operator+=(const float2&);
        float2& operator+=(const float);
        float2& operator*=(const float);
};

int ceil(float a);
int floor(float a);

Location topLeft(Location, int2 Radius);
Location topRight(Location, int2 Radius);
Location botLeft(Location, int2 Radius);
Location botRight(Location, int2 Radius);

Location topLeft(Location, float2 Radius);
Location topRight(Location, float2 Radius);
Location botLeft(Location, float2 Radius);
Location botRight(Location, float2 Radius);

#endif
