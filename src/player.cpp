#include"player.h"

Player::Player(int x, int y, int offsx, int offsy)
    :
        Entity(x, y, offsx, offsy)
{
    velocity.x = 0;
    velocity.y = 0;
    accel.x = 10;
    accel.y = 10;
}

void Player::getState(const float& delta, int2& forceDirections)
{
    float2 forceApplied(0,0);
    forceApplied.x = forceDirections.x;
    forceApplied.y = forceDirections.y;

    if( forceDirections.x !=0 && forceDirections.y !=0 )
        forceApplied *= 0.70710678118f; // Diagonal unit vector
    forceApplied *= 200.f; // Movement speed
    forceApplied += -velocity*20.f; // Friction
    //forceApplied.y -= gravity;

    velocity += forceApplied*delta;

    Location newLocation = worldLoc + forceApplied*(float)pow(delta, 2)*.5f + velocity*delta;
}

void Player::updateState()
{
}

void Player::render()
{
}

