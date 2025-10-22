#include "../hdrs/Game.h"
#include <sstream>

Game::Game()
{
    window.create(sf::VideoMode(1280, 720), "Pong Game");
    running = true;
    changeState(State::MAINMENU);
}

void Game::run()
{
    while (window.isOpen())
    {
        now = clock.getElapsedTime();
        frameDeltaTime = now - then;
        then = now;

        if (currentState)
        {
            currentState -> handleEvents(*this);

            window.clear(sf::Color(3, 44, 96));

            currentState -> update(*this);
            currentState -> draw(*this);

            window.display();
        }
    }
}

bool Game::isRunning() const
{
    return running;
}

void Game::changeState(State newState)
{
    switch (newState)
    {
    case State::MAINMENU:
        currentState = std::make_unique<Menu>();
        break;
    case State::PLAY:
        currentState = std::make_unique<PlayState>();
        break;
    }
}

std::string Game::numberToString(int num)
{
    std::ostringstream ss;
    ss << num;
    return ss.str();
}
