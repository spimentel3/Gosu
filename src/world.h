#ifndef WORLD_H
#define WORLD_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include<iostream>
#include<cmath>
#include<assert.h>

#include"math.h"

using std::vector;
using sf::VertexArray;

class Location
{
    private:
    public:
        // Center of any body
        int /*worldLoc*/x;
        int /*worldLoc*/y;

        int /*tileOffs*/ox;
        int /*tileOffs*/oy;


    //functions:
        Location(int x, int y, int offsx=0, int offsy=0);
        Location& operator-(int2& xypair);
};

class World
{       
    private:
        World();
        World(const World &);
        const World &operator=(const World &);

        static World *m_instance;

        int2 aspectRatio;
        int zoomScale;

        vector<vector<int>> tileMap;

    public:
        static World *instance();

        VertexArray mapDisplay(const Location& worldLoc);
        void loadMap(int overLvl, int mapID, int curLvl);

        // This function translates "meter coords" into the pixel coordinates they should take on the screen.
        //Vector2f meter2Pixel_Relative(const Vector2f& coord);
        // This function converts measurements from meters to pixels (used for radius conversions, etc)
        //Vector2f meter2Pixel(const Vector2f& coord);
};
#endif
