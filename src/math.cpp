#include"math.h"


int2::int2(int x, int y)
    :
        x(x)
        ,y(y)
{
}


int2 int2::operator*(int scalar) const
{
    return int2(
        x*scalar,
        y*scalar);
}


int2 int2::operator/(int scalar) const
{
    return int2(
        x/scalar,
        y/scalar);
}

float2::float2(float x, float y)
    :
        x(x)
        ,y(y)
{
}

float2 float2::operator*(const float scalar) const
{
    return float2(
        x*scalar,
        y*scalar);
}


float2 float2::operator/(const float scalar) const
{
    return float2(
        x/scalar,
        y/scalar);
}


float2& float2::operator=(float2& pairxy)
{
    x = pairxy.x;
    y = pairxy.y;
    return *this;
}
Location topLeft(Location l, int2 Radius)
{
    return Location(
            l.x-Radius.x
            ,
            l.y+Radius.y
            , l.ox, l.oy
            );
}
Location topRight(Location l, int2 Radius)
{
    return Location(
            l.x+Radius.x
            ,
            l.y+Radius.y
            , l.ox, l.oy
            );
}
Location botLeft(Location l, int2 Radius)
{
    return Location(
            l.x-Radius.x
            ,
            l.y-Radius.y
            , l.ox, l.oy
            );
}
Location botRight(Location l, int2 Radius)
{
    return Location(
            l.x+Radius.x
            ,
            l.y-Radius.y
            , l.ox, l.oy
            );
}


Location topLeft(Location l, float2 Radius)
{
    return Location(
            l.x-Radius.x
            ,
            l.y+Radius.y
            , l.ox, l.oy
            );
}
Location topRight(Location l, float2 Radius)
{
    return Location(
            l.x+Radius.x
            ,
            l.y+Radius.y
            , l.ox, l.oy
            );
}
Location botLeft(Location l, float2 Radius)
{
    return Location(
            l.x-Radius.x
            ,
            l.y-Radius.y
            , l.ox, l.oy
            );
}
Location botRight(Location l, float2 Radius)
{
    return Location(
            l.x+Radius.x
            ,
            l.y-Radius.y
            , l.ox, l.oy
            );
}

