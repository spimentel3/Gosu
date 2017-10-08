#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include"math.h"
#include"world.h"
#include"entity.h"

using sf::RenderWindow;
using sf::VideoMode;

class Game
{
    private:
        RenderWindow window;
        World* world;
    //functions:
        void run();
    public:
        Game();
};

#endif
