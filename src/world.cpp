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

World::World()
    :
        aspectRatio(16,9)
        ,zoomScale(1)
        // x+2, y+2 because need additional render buffer column/row for offset 
        ,tileVertices(sf::Quads, (aspectRatio.x+2) * (aspectRatio.y+2) * 4)
        ,tileSizeInPixels(16)
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
    Location topLeftLoc(
        worldLoc.x - (aspectRatio.x*zoomScale)/2
        ,
        worldLoc.y + (aspectRatio.y*zoomScale)/2
        );
    // For optimization:
        // We can duplicate textures instead of reapply to vertices
    int height = aspectRatio.y*zoomScale+1;
    int width = aspectRatio.x*zoomScale+1;
    for(int j=0; j<height; j++) // maybe 2
    {
        for(int i=0; i<width; i++) // maybe 2
        {
            sf::Vertex* quad = &tileVertices[(i + j*width)*4];
            //Inside
            if(topLeftLoc.x+i < tileMap[0].size() && topLeftLoc.x+i > 0
                && topLeftLoc.y+j < tileMap.size() && topLeftLoc.y+j > 0)
            {
                quad[0].position = Vector2f(
                        i * tileSizeInPixels - (float)worldLoc.ox/256
                        ,
                        j * tileSizeInPixels - (float)worldLoc.oy/256
                        );
                quad[1].position = Vector2f(
                        (i+1) * tileSizeInPixels - (float)worldLoc.ox/256-1
                        ,
                        j * tileSizeInPixels - (float)worldLoc.oy/256
                        );
                quad[2].position = Vector2f(
                        (i+1) * tileSizeInPixels - (float)worldLoc.ox/256-1
                        ,
                        (j+1) * tileSizeInPixels - (float)worldLoc.oy/256-1
                        );
                quad[3].position = Vector2f(
                        i * tileSizeInPixels - (float)worldLoc.ox/256
                        ,
                        (j+1) * tileSizeInPixels - (float)worldLoc.oy/256-1
                        );
#ifdef maptiles
    printf("%i,%i is at pos <%f,%f> because tileSize is %i\n",i,j,
                        i * tileSizeInPixels - (float)worldLoc.ox/256
                        ,
                        (j+1) * tileSizeInPixels - (float)worldLoc.oy/256-1
                        , tileSizeInPixels
                    );
#endif
                if(tileMap[j][i] == 0)
                {
                    quad[0].color = sf::Color(0,255,0);
                    quad[1].color = sf::Color(0,255,0);
                    quad[2].color = sf::Color(0,255,0);
                    quad[3].color = sf::Color(0,255,0);
                }
                if(tileMap[j][i] == 1)
                {
                    quad[0].color = sf::Color(199,199,0);
                    quad[1].color = sf::Color(199,199,0);
                    quad[2].color = sf::Color(199,199,0);
                    quad[3].color = sf::Color(199,199,0);
                }
            }
            else // We are outside of our tileMap
            {
            }
        }
    }

    return tileVertices;
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
