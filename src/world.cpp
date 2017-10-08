#include"world.h"


World::World()
    :
        aspectRatio(16,9)
        ,zoomScale(1)
        // x+2, y+2 because need additional render buffer column/row for offset
        ,tileVertices(sf::Quads, (aspectRatio.x+1) * (aspectRatio.y+1)*zoomScale*zoomScale * 4)
        ,tileSizeInPixels(16)
        ,botLeftLoc(0,0)
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

VertexArray World::mapDisplay(
        const Location& worldLoc
    )
{
    botLeftLoc = botLeft(worldLoc, (aspectRatio*zoomScale)/2.f);

    if((int)aspectRatio.x%2 == 1)
    {
        botLeftLoc.ox+=127;
    }
    if((int)aspectRatio.y%2 == 1)
    {
        botLeftLoc.oy-=127;
    }

    //botLeftLoc.x = worldLoc.x - (aspectRatio.x*zoomScale)/2;
    //botLeftLoc.y = worldLoc.y - (aspectRatio.y*zoomScale)/2;
    //botLeftLoc.ox = worldLoc.ox;
    //botLeftLoc.oy = worldLoc.oy;
    printf("%i, %i, %i, %i\n", botLeftLoc.x, botLeftLoc.y, botLeftLoc.ox, botLeftLoc.oy);

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
            //printf("tilemap[%i][%i]",botLeftLoc.y+j, botLeftLoc.x+i);

            //printf(" is in\n");
            quad[0].position = Vector2f(
                    i * tileSizeInPixels - ((float)botLeftLoc.ox/255)*tileSizeInPixels
                    ,
                    j * tileSizeInPixels - ((float)botLeftLoc.oy/255)*tileSizeInPixels
                    );
            quad[1].position = Vector2f(
                    (i+1) * tileSizeInPixels - ((float)botLeftLoc.ox/255)*tileSizeInPixels-1
                    ,
                    j * tileSizeInPixels - ((float)botLeftLoc.oy/255)*tileSizeInPixels
                    );
            quad[2].position = Vector2f(
                    (i+1) * tileSizeInPixels - ((float)botLeftLoc.ox/255)*tileSizeInPixels-1
                    ,
                    (j+1) * tileSizeInPixels - ((float)botLeftLoc.oy/255)*tileSizeInPixels-1
                    );
            quad[3].position = Vector2f(
                    i * tileSizeInPixels - ((float)botLeftLoc.ox/255)*tileSizeInPixels
                    ,
                    (j+1) * tileSizeInPixels - ((float)botLeftLoc.oy/255)*tileSizeInPixels-1
                    );
#ifdef maptiles
#endif
            switch (at(botLeftLoc.x+i, botLeftLoc.y+j)) {
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

//
int World::at(int x, int y)
{
    if(x < tileMap[0].size() && x >= 0
      && tileMap.size() - 1 - y < tileMap.size() && tileMap.size() - 1 - y >= 0)
    {
        return tileMap[tileMap.size() - 1 - y][x];
    }

    return -1;

}

float2 World:: meter2Pixel_Relative(const Location& worldLoc)
{
    // printf("(float)(%i - %i)*%i - (float)((%d / 256)*%d) = %f\n",
    //         worldLoc.x , botLeftLoc.x        , tileSizeInPixels ,          worldLoc.ox+1         ,tileSizeInPixels,
    //         (float)(worldLoc.x-botLeftLoc.x) * tileSizeInPixels + ((float)(worldLoc.ox+1/256))*tileSizeInPixels);
    // printf("(float)(%i - %i)*%i - (float)((%d / 256)*%d) = %f\n",
    //         worldLoc.y , botLeftLoc.y        , tileSizeInPixels ,          worldLoc.oy+1         ,tileSizeInPixels,
    //         (float)(worldLoc.y-botLeftLoc.y) * tileSizeInPixels + ((float)(worldLoc.oy+1/256))*tileSizeInPixels);
    //printf("(float)(%i - %i) - ((float))%f * %i = %f\n",
                            //worldLoc.x,botLeftLoc.x  ,  (float)worldLoc.ox/255.0f ,tileSizeInPixels,
                    //(float)(worldLoc.x-botLeftLoc.x) - ((float)worldLoc.ox/255.0f)*tileSizeInPixels);
//
    float2 screenPos(
            (float)(worldLoc.x-botLeftLoc.x) / tileSizeInPixels - ((float)worldLoc.ox/255)*tileSizeInPixels
            ,
            (float)(worldLoc.y-botLeftLoc.y) / tileSizeInPixels - ((float)worldLoc.oy/255)*tileSizeInPixels
        );
}
