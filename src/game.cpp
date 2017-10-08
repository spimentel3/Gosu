#include"game.h"

using std::cout;
using std::endl;
using sf::Clock;

Game::Game()
    :
        window(VideoMode(1600, 900), "super fun game wow")
        ,world(World::instance())

{
    world->setTileSizeInPixels(window.getSize().x/16);
    window.setFramerateLimit(144);
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
        window.clear(sf::Color::Black);
        Location worldLocation(7,4,255,127);
        window.draw(world->mapDisplay(worldLocation));
        window.display();
    }
}

int main()
{
    Game gosu;
}
