#ifndef MATH_H
#define MATH_H

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

#endif
