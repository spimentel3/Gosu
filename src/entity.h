#ifndef ENTITY_H
#define ENTITY_H

#include"world.h"

class Entity
{
    private:
        Location worldLoc;
    public:
        Entity(int x, int y, int offsx, int offsy);
        ~Entity();
};
#endif
