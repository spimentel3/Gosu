#ifndef PLAYER_H
#define PLAYER_H

#include"entity.h"
#include"math.h"

class Player: public Entity
{
    private:
    //functions
        virtual void getState(const float& delta, int2& forceDirections);
        virtual void updateState();
        virtual void render();
    public:
        Player(int x, int y, int offsx, int offsy);
};

#endif
