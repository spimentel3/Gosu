#include"entity.h"

Entity::Entity(int x, int y, int offsx, int offsy
        ,int2 r
        )
    :
        worldLoc(x, y, offsx, offsy)
        ,velocity(0,0)
        ,accel(0,0)
        ,body(sf::Quads, 4)
        ,radius(r)
{
}

const Location& Entity::getLocation() const
{
    return worldLoc;
}

void Entity::broadcastState()
{
}

void Entity::update(const float& delta, int2& forcesApplied)
{
}

void Entity::render(RenderWindow& window)
{
}

