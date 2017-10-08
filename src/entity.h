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

        virtual void getState(int2& forcesApplied);
        virtual void updateState();
        virtual void render();
    public:
        Entity(int x, int y, int offsx, int offsy);
        ~Entity();

        void update(int2& forcesApplied);
        VertexArray& getBody();
};
#endif
