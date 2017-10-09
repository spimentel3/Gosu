#ifndef PLAYER_H
#define PLAYER_H

#include"entity.h"

class Player: public Entity
{
    private:
    protected:
    public:
        Player(int x, int y, int offsx, int offsy);

        void broadcastState();
        void update(const float& delta, int2& forceDirections);
        void render(RenderWindow& window);
};

#endif
