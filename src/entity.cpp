#include"entity.h"

Entity::Entity(int x, int y, int offsx, int offsy)
    :
        worldLoc(x, y, offsx, offsy)
        ,velocity(0,0)
        ,accel(0,0)
        ,body(sf::Quads, 4)
{
}

void Entity::update(int2& forcesApplied)
{
    getState(forcesApplied);
    updateState();
    render();
}


void Entity::getState(int2& forcesApplied)
{
}

void Entity::updateState()
{
}

void Entity::render()
{
}

