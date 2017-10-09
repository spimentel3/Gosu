#include"location.h"

Location::Location(int x, int y, int offsx, int offsy)
    :
        x(x)
        ,y(y)
        ,ox(offsx)
        ,oy(offsy)
{
}

Location Location::operator-(const float2 xypair) const
{
    return Location(
            x-xypair.x,
            y-xypair.y);
}


Location Location::operator+(const float2 xypair) const
{
    return Location(
            x+xypair.x,
            y+xypair.y);
}
/*
Location operator-(const Location& l, const int2& xypair)
{
    return Location(
        l.x-xypair.x,
        l.y-xypair.y
        );
}*/
