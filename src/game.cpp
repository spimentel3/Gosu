#include"game.h"

using std::cout;
using std::endl;
using sf::Clock;

Game::Game()
    :
        window(VideoMode(1600, 900), "super fun game wow")
        ,world(World::instance())
        ,player(0,0,0,0)

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
        int2 forces;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            forces.y=1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            forces.x=-1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            forces.y=-1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            forces.x=1;
        }
        window.clear(sf::Color::Black);
        Location worldLocation(0,0,127,0);
        float2 rel = world->meterLoc2PixelPos(worldLocation);
        //printf("%f %f\n", rel.x, rel.y);
        
        player.update(delta, forces);
        window.draw(world->mapDisplay(worldLocation));
        window.display();


        /*

        Do Player input, and get new positon
        window.draw(world->mapDisplay(Player.get_position));Z

        */
    }
}

int main()
{
    Game gosu;
}
