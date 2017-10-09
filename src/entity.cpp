#include"entity.h"

Entity::Entity(int x, int y, int offsx, int offsy)
    :
        worldLoc(x, y, offsx, offsy)
        ,velocity(0,0)
        ,accel(0,0)
        ,body(sf::Quads, 4)
{
}

void Entity::update(const float& delta, int2& forcesApplied)
{
    getState(delta, forcesApplied);
    updateState();
    render();
}


void Entity::getState(const float& delta, int2& forcesApplied)
{
}

void Entity::updateState()
{
}

void Entity::render()
{
}

