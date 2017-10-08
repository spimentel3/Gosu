#include"world.h"

/* static */ World *World::m_instance = 0;


/* static */ World * World::instance()
{
    if (m_instance == 0){
        m_instance = new World();
        m_instance->loadMap(0);
    }
    return m_instance;
}

World::World()
    :
        aspectRatio(16,9)
        ,scale(1)
{
}


int2 World:: meter2Pixel_Relative(const int2& worldLoc, const int2& tileOffs)
{
    int2 screenPos(
            numB
            ,
        )
}

