#include"game.h"

using std::cout;
using std::endl;
using sf::Clock;

Game::Game()
    :
        window(VideoMode(1920, 1080), "super fun game wow")
        ,world(World::instance())

{
    run();
}

void Game::run()
{
    Clock clock;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        float delta = clock.restart().asSeconds();
        sf::Event event;
        if(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        else if (event.type == sf::Event::Resized)
        {
            //window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
        {
            window.close();
        }
        window.display();
    }
}

int main()
{
    Game gosu;
}
