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


