#ifndef WORLD_H
#define WORLD_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include<iostream>
#include<cmath>
#include<assert.h>

#include"location.h"
#include"math.h"

using std::vector;
using sf::VertexArray;
using sf::Vector2f;


class World
{
    private:
        World();
        World(const World &);
        const World &operator=(const World &);

        static World *m_instance;

        float2 aspectRatio;
        float zoomScale;

        vector<vector<int>> tileMap;
        VertexArray tileVertices;
        int tileSizeInPixels;

        Location topLeftLoc;

    public:
        static World *instance();

        void setTileSizeInPixels(int pixSize);
        VertexArray& mapDisplay(const Location& worldLoc);
        void loadMap(int overLvl, int mapID, int curLvl);

        int at(int x, int y);

        // This function translates "meter coords" into the pixel coordinates they should take on the screen.
        float2 meterLoc2PixelPos(const Location& coord);
        Vector2f meterLoc2PixelPosV2f(const Location& coord);

        float2 meterRad2PixelRad(const int2& radius);
        // This function converts measurements from meters to pixels (used for radius conversions, etc)
        //Vector2f meter2PixelRad(const Vector2f& coord);
};
#endif
