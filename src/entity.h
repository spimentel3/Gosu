#ifndef ENTITY_H
#define ENTITY_H

#include"world.h"

class Entity
{
    friend class Player;
    private:
        Location worldLoc;

        float2 velocity;
        float2 accel;

        VertexArray body;

        // Everyone has their own
        virtual void getState(const float& delta, int2& forcesApplied);
        virtual void updateState();
        virtual void render(); 
    public:
        Entity(int x, int y, int offsx, int offsy);

        virtual void update(const float& delta,int2& forcesApplied); //Everyone uses
        VertexArray& getBody();
};
#endif
