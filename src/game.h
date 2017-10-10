#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<unistd.h>

#include"math.h"
#include"world.h"
#include"entity.h"
#include"player.h"
#include"eventhandler.h"

using sf::RenderWindow;
using sf::VideoMode;

class Game
{
    private:
        RenderWindow window;
        World* world;
        Player player;
    //functions:
        void run();
    public:
        Game();
};

#endif
