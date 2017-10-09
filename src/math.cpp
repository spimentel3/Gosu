#include"math.h"


int2::int2(int x, int y)
    :
        x(x)
        ,y(y)
{
}

int2::int2(int a)
    :
        x(a)
        ,y(a)
{
}

int2& int2::operator=(int a)
{
    x=a;
    y=a;
    return *this;
}

int2 int2::operator*(int scalar) const
{
    return int2(
        x*scalar,
        y*scalar);
}

int2 int2::operator-() const
{
    return int2(
        -x,
        -y);
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

float2 float2::operator+(const float2 xypair) const
{
    return float2(
        x+xypair.x,
        y+xypair.y);
}
float2 float2::operator-() const
{
    return float2(
        -x,
        -y);
}

float2 float2::operator/(const float scalar) const
{
    return float2(
        x/scalar,
        y/scalar);
}


float2& float2::operator=(const float2& pairxy)
{
    x = pairxy.x;
    y = pairxy.y;
    return *this;
}

float2& float2::operator*=(const float scalar)
{
    
    x *= scalar;
    y *= scalar;
    return *this;
}

float2& float2::operator+=(const float2& xypair)
{
    x += xypair.x;
    y += xypair.y;
    return *this;
}

float2& float2::operator+=(const float scalar)
{
    
    x += scalar;
    y += scalar;
    return *this;
}

float2& float2::operator*=(const float2& xypair)
{
    
    x *= xypair.x;
    y *= xypair.y;
    return *this;
}

int ceil(float a)
{
    int b=0;
    if( a > 0)
        b= a-(int)a>.001?(int)a+1:(int)a;
    else
        b= a-(int)a>-.001?(int)a+1:(int)a;
    printf("%f - %i > .001? == %i\n", a, (int)a, b);
    return b;
}


int floor(float a)
{
    return (int)a;
}

// int2 Location functions

Location topLeft(Location l, int2 Radius)
{
    return Location(
        l.ox - Radius.x < 0? l.x-ceil((float)(l.ox - Radius.x)/255): l.x
        ,
        l.oy + Radius.y > 255? l.y+floor((float)(l.oy + Radius.y)/255): l.y
        , 
        l.ox - Radius.x < 0? -(l.ox - Radius.x): l.ox - Radius.x
        , 
        l.oy - Radius.y > 255? (l.oy + Radius.y)%255: l.oy + Radius.y
    );
}
Location topRight(Location l, int2 Radius)
{
    return Location(
        l.ox + Radius.x > 255? l.x+floor((float)(l.ox + Radius.x)/255): l.x
        ,
        l.oy + Radius.y > 255? l.y+floor((float)(l.oy + Radius.y)/255): l.y
        , 
        l.ox - Radius.x > 255? (l.ox + Radius.x)%255: l.ox + Radius.x
        , 
        l.oy - Radius.y > 255? (l.oy + Radius.y)%255: l.oy + Radius.y
    );
}
Location botLeft(Location l, int2 Radius)
{ //        l.x-ceil((float)(l.ox - Radius.x)/255)
    printf("botLeft\n");
    printf("%i -ceil((float)(%i   - %i      )/255) = %i \n", l.x, l.ox, Radius.x,l.x-ceil((float)(l.ox - Radius.x)/255) ); 
    printf("l.y - ceil == %i - %i\n", l.x,ceil(((float)(l.ox - Radius.x)/255)));
    printf("-(%i - %i)\n", l.ox, Radius.x);
    return Location(
        l.ox - Radius.x < 0? l.x-ceil((float)(l.ox - Radius.x)/255): l.x
        ,
        l.oy - Radius.y < 0? l.y-ceil((float)(l.oy - Radius.y)/255): l.y
        , 
        l.ox - Radius.x < 0? -(l.ox - Radius.x): l.ox - Radius.x
        , 
        l.oy - Radius.y < 0? -(l.oy - Radius.y): l.oy - Radius.y
    );
}
Location botRight(Location l, int2 Radius)
{
    printf("botRight\n");
    printf("%i +floor((float)(%i   + %i      )/255) = %i \n", l.x, l.ox, Radius.x,l.x+floor((float)(l.ox + Radius.x)/255)); 
    printf("%i + %i\n", l.ox, Radius.x);
    return Location(
        l.ox + Radius.x > 255? l.x+floor((float)(l.ox + Radius.x)/255): l.x
        ,
        l.oy - Radius.y < 0? l.y-ceil((float)(l.oy - Radius.y)/255): l.y
        , 
        (l.ox + Radius.x)%255
        , 
        l.oy - Radius.y < 0? -(l.oy - Radius.y): l.oy - Radius.y
    );
}

// Float2 location functions

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

