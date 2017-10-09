#include"player.h"

Player::Player(int x, int y, int offsx, int offsy)
:
    Entity(x, y, offsx, offsy, 126)
{
    velocity.x = 0;
    velocity.y = 0;
    accel.x = 10;
    accel.y = 10;
}

void Player::broadcastState()
{
}

void Player::update(const float& delta, int2& forceDirections)
{
    float2 forceApplied(forceDirections.x,forceDirections.y);

    if( forceDirections.x !=0 && forceDirections.y !=0 )
        forceApplied *= 0.70710678118f; // Diagonal unit vector
    forceApplied *= 200.f; // Movement speed
    forceApplied += -velocity*20.f; // Friction

    velocity += forceApplied*delta;

    Location newLocation = worldLoc + forceApplied*(float)pow(delta, 2)*.5f + velocity*delta;

    // Do Checks

    worldLoc = newLocation;
}


void Player::render(RenderWindow& window)
{
    /*
    printf("\n");
    Location bl= botLeft(worldLoc, radius);
    printf("My location is %i %i. Radius is %i  My botLeft is %i<%i>,%i<%i>\n", worldLoc.x, worldLoc.y, radius.x,
            bl.x,bl.ox, bl.y,bl.oy);

    World::instance()->meterLoc2PixelPosV2f(bl);

    Location br= botRight(worldLoc, radius);
    printf("My location is %i %i. Radius is %i  My botLeft is %i<%i>,%i<%i>\n", worldLoc.x, worldLoc.y, radius.x,
            br.x,br.ox, br.y,br.oy);
    World::instance()->meterLoc2PixelPosV2f(br);

    printf("\n");
    */

  //body[0].position = World::instance()->meterLoc2PixelPosV2f(botLeft(worldLoc, radius));
  //body[1].position = World::instance()->meterLoc2PixelPosV2f(topLeft(worldLoc, radius));
  //body[2].position = World::instance()->meterLoc2PixelPosV2f(topRight(worldLoc, radius));
  //body[3].position = World::instance()->meterLoc2PixelPosV2f(botRight(worldLoc, radius));

    
    float2 screenPos = World::instance()->meterLoc2PixelPos(worldLoc);
    float2 screenRad = World::instance()->meterRad2PixelRad(radius);
    body[0].position = Vector2f( screenPos.x - screenRad.x, screenPos.y-screenRad.y);
    body[1].position = Vector2f( screenPos.x - screenRad.x, screenPos.y+screenRad.y);
    body[2].position = Vector2f( screenPos.x + screenRad.x, screenPos.y+screenRad.y);
    body[3].position = Vector2f( screenPos.x + screenRad.x, screenPos.y-screenRad.y);
    for(int i=0; i<4; i++)
        printf("%i %i\n", body[i].position.x,body[i].position.y);

    body[0].color = sf::Color(255,0,0);
    body[1].color = sf::Color(255,0,0);
    body[2].color = sf::Color(255,0,0);
    body[3].color = sf::Color(255,0,0);

    window.draw(body);
}

