#ifndef ENTITY_H
#define ENTITY_H

#include"world.h"

class Entity
{
    friend class Player;
    private:
        Location worldLoc;

        //float2 velocity;
        //float2 accel;
    public:
        Entity(int x, int y, int offsx, int offsy);
        ~Entity();
};
#endif
