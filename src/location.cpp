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
            y-xypair.y
            ,ox+(xypair.x-(int)xypair.x)*255
            ,oy+(xypair.y-(int)xypair.y)*255
            );
    assert(false && "Idk if this should be used");
}


Location Location::operator+(const float2 xypair) const
{
    printf("xypair = %f, %f\n", xypair.x, xypair.y);
    return Location(
            x+xypair.x + (int)((ox+fraction(xypair.x)*255)/255)
            ,y+xypair.y + (int)((oy+fraction(xypair.y)*255)/255)
            ,(int)(ox+fraction(xypair.x)*255) % 255
            ,(int)(oy+fraction(xypair.y)*255) % 255
            );
}
/*
Location operator-(const Location& l, const int2& xypair)
{
    return Location(
        l.x-xypair.x,
        l.y-xypair.y
        );
}*/

void Location::print(string name)
{
    printf("%s: %i<%i>, %i<%i>\n", name.c_str(), x, ox, y, oy);
}
