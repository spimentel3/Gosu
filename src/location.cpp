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
    float new_ox = (ox + fraction(xypair.x)*255);
    float new_oy = (oy + fraction(xypair.y)*255);
    int new_x = x+(int)xypair.x;
    int new_y = y+(int)xypair.y;

    if(new_ox < 0){
        new_ox += 255;
        new_x--;
    }
    else if(new_ox > 255){
        new_x++;
    }
    if(new_oy < 0){
        new_oy += 255;
        new_y--;
    }
    else if(new_oy > 255){
        new_y++;
    }
    return Location(
            new_x
            , new_y
            , (int)new_ox % 255
            , (int)new_oy % 255
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
