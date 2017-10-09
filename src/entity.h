#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Window.hpp>

#include"world.h"

using sf::RenderWindow;

class Entity
{
    private:
    protected:
        Location worldLoc;

        float2 velocity;
        float2 accel;

        VertexArray body;
        int2 radius;

        // Everyone has their own
    public:
        Entity(int x, int y, int offsx, int offsy, int2 r=127);

        const Location& getLocation() const;

        virtual void broadcastState();
        virtual void update(const float& delta,int2& forcesApplied); //Everyone uses
        virtual void render(RenderWindow& window); 
};
#endif
