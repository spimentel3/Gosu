#include"world.h"


World::World()
    :
        aspectRatio(16,9)
        ,zoomScale(1)
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


// NOTE Sets resolution of the tiles, both x and y
void World::setTileSizeInPixels(int pixSize)
{
    tileSizeInPixels = pixSize;
}

// NOTE Hard coded for now.
// Use params when we actually start having multiple maps
void World::loadMap(int overLvl, int mapID, int curLvl)
{
    // NOTE tileMaps ALWAYS need to be rectangular ->(y[0].size == y[1...n].size)
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

VertexArray& World::mapDisplay(
        const Location& worldLoc
    )
{
    topLeftLoc = topLeft(worldLoc, (aspectRatio*zoomScale)/2.f);

    if((int)aspectRatio.x%2 == 1)
    {
        topLeftLoc.ox+=127;
    }
    if((int)aspectRatio.y%2 == 1)
    {
        topLeftLoc.oy-=127;
    }

    // NOTE For optimization:
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

            //printf(" is in\n");
            quad[0].position = Vector2f(
                    i * tileSizeInPixels - ((float)topLeftLoc.ox/255)*tileSizeInPixels
                    ,
                    j * tileSizeInPixels - ((float)topLeftLoc.oy/255)*tileSizeInPixels
                    );
            quad[1].position = Vector2f(
                    (i+1) * tileSizeInPixels - ((float)topLeftLoc.ox/255)*tileSizeInPixels-1
                    ,
                    j * tileSizeInPixels - ((float)topLeftLoc.oy/255)*tileSizeInPixels
                    );
            quad[2].position = Vector2f(
                    (i+1) * tileSizeInPixels - ((float)topLeftLoc.ox/255)*tileSizeInPixels-1
                    ,
                    (j+1) * tileSizeInPixels - ((float)topLeftLoc.oy/255)*tileSizeInPixels-1
                    );
            quad[3].position = Vector2f(
                    i * tileSizeInPixels - ((float)topLeftLoc.ox/255)*tileSizeInPixels
                    ,
                    (j+1) * tileSizeInPixels - ((float)topLeftLoc.oy/255)*tileSizeInPixels-1
                    );
#ifdef maptiles
#endif
            switch (at(topLeftLoc.x+i, topLeftLoc.y-j)) {
                case 1:
                {
                    quad[0].color = sf::Color(199,100,0);
                    quad[1].color = sf::Color(199,100,0);
                    quad[2].color = sf::Color(199,100,0);
                    quad[3].color = sf::Color(199,100,0);
                    break;
                }
                case 0:
                {
                    quad[0].color = sf::Color(0,255,0);
                    quad[1].color = sf::Color(0,255,0);
                    quad[2].color = sf::Color(0,255,0);
                    quad[3].color = sf::Color(0,255,0);
                    break;
                }
                case -1:
                {
                    quad[0].color = sf::Color(100,100,100);
                    quad[1].color = sf::Color(100,100,100);
                    quad[2].color = sf::Color(100,100,100);
                    quad[3].color = sf::Color(100,100,100);
                    break;
                }
                default:
                    assert(false);
            }
        }
    }

    return tileVertices;
}

int World::at(int x, int y)
{
    if(x < tileMap[0].size() && x >= 0
      && tileMap.size() - y < tileMap.size() && tileMap.size() - y >= 0)
    {
        return tileMap[tileMap.size() - y][x];
    }
    return -1;

}

float2 World:: meterLoc2PixelPos(const Location& worldLoc)
{
    /*
    printf("(float)(%i - %i)*tileSize - ((float))%f * %i = %f\n",
            worldLoc.x
            ,topLeftLoc.x
            ,(float)worldLoc.ox/255
            ,((int)aspectRatio.x%2)? (float)(worldLoc.ox+127)/255 : ((float)worldLoc.ox/255)
            ,tileSizeInPixels
            ,
            (float)(worldLoc.x+topLeftLoc.x)
            * tileSizeInPixels
            - ((int)aspectRatio.x%2)? (float)(worldLoc.ox+127)/255 : ((float)worldLoc.ox/255)
            * tileSizeInPixels);
    */
    return float2(
            (float)(worldLoc.x-topLeftLoc.x)
            * tileSizeInPixels
            - (((int)aspectRatio.x%2)? (float)(worldLoc.ox+127)/255 : ((float)worldLoc.ox/255))
            * tileSizeInPixels
            ,
            (float)(worldLoc.y+topLeftLoc.y)
            * tileSizeInPixels
            + (((int)aspectRatio.y%2)? (float)(worldLoc.oy+127)/255 : ((float)worldLoc.oy/255))
            * tileSizeInPixels
        );
}

Vector2f World:: meterLoc2PixelPosV2f(const Location& worldLoc)
{
    printf("(float)(%i - %i)*tileSize - ((float))%f * %i = %f   ----   ",
            worldLoc.x
            ,topLeftLoc.x
            ,(((int)aspectRatio.x%2)? (float)(worldLoc.ox+127)/255 : ((float)worldLoc.ox/255))
            ,tileSizeInPixels
            ,
            (float)(worldLoc.x-topLeftLoc.x)
            * tileSizeInPixels
            - (((int)aspectRatio.x%2)? (float)(worldLoc.ox+127)/255 : ((float)worldLoc.ox/255))
            * tileSizeInPixels);

    printf("(float)(%i + %i)*tileSize + ((float))%f * %i = %f\n",
            worldLoc.y
            ,topLeftLoc.y
            ,(((int)aspectRatio.y%2)? (float)(worldLoc.oy+127)/255 : ((float)worldLoc.oy/255))
            ,tileSizeInPixels
            ,
            (float)(worldLoc.y+topLeftLoc.y)
            * tileSizeInPixels
            + (((int)aspectRatio.y%2)? (float)(worldLoc.oy+127)/255 : ((float)worldLoc.oy/255))
            * tileSizeInPixels);
    return Vector2f(
            (float)(worldLoc.x-topLeftLoc.x)
            * tileSizeInPixels
            - (((int)aspectRatio.x%2)? (float)(worldLoc.ox+127)/255 : ((float)worldLoc.ox/255))
            * tileSizeInPixels
            ,
            (float)(worldLoc.y+topLeftLoc.y)
            * tileSizeInPixels
            + (((int)aspectRatio.y%2)? (float)(worldLoc.oy+127)/255 : ((float)worldLoc.oy/255))
            * tileSizeInPixels
        );
}

float2 World::meterRad2PixelRad(const int2& radius)
{
    return float2(
            ((float)radius.x /255)*tileSizeInPixels
            ,
            ((float)radius.y /255)*tileSizeInPixels
        );
}

