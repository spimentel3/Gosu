#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<vector>
#include<iostream>
#include<cmath>
#include <assert.h>


class World
{       
    private:
        World();
        World(const World &);
        const World &operator=(const World &);

        static World *m_instance;

        int2 aspectRatio;
        int zoomScale;

    public:
        static World *instance();

        // This function translates "meter coords" into the pixel coordinates they should take on the screen.
        Vector2f meter2Pixel_Relative(const Vector2f& coord);
        // This function converts measurements from meters to pixels (used for radius conversions, etc)
        Vector2f meter2Pixel(const Vector2f& coord);
};
#endif
