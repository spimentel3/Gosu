#include"world.h"

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
/*
Location operator-(const Location& l, const int2& xypair)
{
    return Location(
        l.x-xypair.x,
        l.y-xypair.y
        );
}*/

World::World()
    :
        aspectRatio(16,9)
        ,zoomScale(2)
        // x+2, y+2 because need additional render buffer column/row for offset 
        ,tileVertices(sf::Quads, (aspectRatio.x+1) * (aspectRatio.y+1)*zoomScale*zoomScale * 4)
        ,tileSizeInPixels(16)
        ,topLeftLoc(0,0)
{
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


// Sets resolution of the tiles, both x and y
void World::setTileSizeInPixels(int pixSize)
{
    tileSizeInPixels = pixSize;
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
    topLeftLoc = worldLoc - (aspectRatio*zoomScale)/2.f;
    //topLeftLoc.x = worldLoc.x - (aspectRatio.x*zoomScale)/2;
    //topLeftLoc.y = worldLoc.y - (aspectRatio.y*zoomScale)/2;
    //topLeftLoc.ox = worldLoc.ox;
    //topLeftLoc.oy = worldLoc.oy;
    printf("%i, %i, %i, %i\n", topLeftLoc.x, topLeftLoc.y, topLeftLoc.ox, topLeftLoc.oy);

    // For optimization:
        // We can duplicate textures instead of reapply to vertices
    int height = aspectRatio.y*zoomScale+1;
    int width = aspectRatio.x*zoomScale+1;
    for(int j=0; j<height; j++) // maybe 2
    {
        //printf("\n%i: ",j);
        for(int i=0; i<width; i++) // maybe 2
        {
            //printf("%i ", i);
            sf::Vertex* quad = &tileVertices[((i) + (j)*width)*4];
            //Inside
            //printf("tilemap[%i][%i]",topLeftLoc.y+j, topLeftLoc.x+i);
            if(topLeftLoc.x+i < tileMap[0].size() && topLeftLoc.x+i >= 0
                && topLeftLoc.y+j < tileMap.size() && topLeftLoc.y+j >= 0)
            {
                //printf(" is in\n");
                quad[0].position = Vector2f(
                        i * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels
                        ,
                        j * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels
                        );
                quad[1].position = Vector2f(
                        (i+1) * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels-1
                        ,
                        j * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels
                        );
                quad[2].position = Vector2f(
                        (i+1) * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels-1
                        ,
                        (j+1) * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels-1
                        );
                quad[3].position = Vector2f(
                        i * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels
                        ,
                        (j+1) * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels-1
                        );
#ifdef maptiles
#endif
                if(tileMap[topLeftLoc.y+j][topLeftLoc.x+i] == 0)
                {
                    quad[0].color = sf::Color(0,255,0);
                    quad[1].color = sf::Color(0,255,0);
                    quad[2].color = sf::Color(0,255,0);
                    quad[3].color = sf::Color(0,255,0);
                }
                if(tileMap[topLeftLoc.y+j][topLeftLoc.x+i] == 1)
                {
                    quad[0].color = sf::Color(199,100,0);
                    quad[1].color = sf::Color(199,100,0);
                    quad[2].color = sf::Color(199,100,0);
                    quad[3].color = sf::Color(199,100,0);
                }
            }
            else // We are outside of our tileMap
            {
                //printf(" isn't in\n");
                quad[0].position = Vector2f(
                        i * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels
                        ,
                        j * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels
                        );
                quad[1].position = Vector2f(
                        (i+1) * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels-1
                        ,
                        j * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels
                        );
                quad[2].position = Vector2f(
                        (i+1) * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels-1
                        ,
                        (j+1) * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels-1
                        );
                quad[3].position = Vector2f(
                        i * tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels
                        ,
                        (j+1) * tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels-1
                        );
                quad[0].color = sf::Color(100,100,100);
                quad[1].color = sf::Color(100,100,100);
                quad[2].color = sf::Color(100,100,100);
                quad[3].color = sf::Color(100,100,100);
            }
        }
    }

    return tileVertices;
}

float2 World:: meter2Pixel_Relative(const Location& worldLoc)
{
    printf("%f/%i - %f = %f\n",
            (float)(worldLoc.x-topLeftLoc.x) , tileSizeInPixels , ((float)worldLoc.ox/256)*tileSizeInPixels,
            (float)(worldLoc.x-topLeftLoc.x) / tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels);
    float2 screenPos(
            (float)(worldLoc.x-topLeftLoc.x) / tileSizeInPixels - ((float)worldLoc.ox/256)*tileSizeInPixels
            ,
            (float)(worldLoc.y-topLeftLoc.y) / tileSizeInPixels - ((float)worldLoc.oy/256)*tileSizeInPixels
        );
}
