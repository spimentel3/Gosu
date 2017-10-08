#include"world.h"

Location::Location(int x, int y, int offsx, int offsy)
    :
        x(x)
        ,y(y)
        ,ox(offsx)
        ,oy(offsy)
{
}

Location& Location::operator-(int2& xypair)
{
    x-=xypair.x;
    y-=xypair.y;
    return *this;
}


/* static */ World *World::m_instance = 0;


/* static */ World * World::instance()
{
    if (m_instance == 0){
        m_instance = new World();
        m_instance->loadMap(0,0,0);
    }
    return m_instance;
}

World::World()
    :
        aspectRatio(16,9)
        ,zoomScale(1)
{
}

// Hard coded for now.
// Use params when we actually start having multiple maps
void World::loadMap(int overLvl, int mapID, int curLvl)
{
    // tileMaps ALWAYS need to be rectangular ->(y[0].size == y[1...n].size)
    tileMap = {
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
       ,{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
       ,{ 1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 }
       ,{ 1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1 }
       ,{ 1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 }
       ,{ 1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1 }
       ,{ 1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1 }
       ,{ 1,1,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,1 }
       ,{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
       ,{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
       ,{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
       ,{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
    };
}

VertexArray World::mapDisplay(
        const Location& worldLoc
    )
{
    Location topLeftLoc(
            worldLoc.x - (aspectRatio.x*zoomScale)/2
            ,
            worldLoc.y + (aspectRatio.x*zoomScale)/2
            );
    for(unsigned int j=0; j<aspectRatio.y*zoomScale+1; j++) // maybe 2
    {
        for(unsigned int i=0; i<aspectRatio.x*zoomScale+1; i++) // maybe 2
        {
            if(worldLoc.x+i > tileMap[0].size() || worldLoc.x+i < 0)
            {
            }
            if(worldLoc.y+j > tileMap.size() || worldLoc.y+j < 0)
            {
            }
        }
    }
}

/*

Location World:: meter2Pixel_Relative(const Location& worldLoc)
{
    Location screenPos(
            0
            ,
            0
        )
}
*/
