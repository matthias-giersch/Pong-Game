#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "GameState.h"
#include "Menu.h"
#include "PlayState.h"

class Game
{
public:
    Game();

    enum class State { MAINMENU, PLAY };

    void run();
    bool isRunning() const;
    void changeState(State newState);
    static std::string numberToString(int num);

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time then;
    sf::Time now;
    sf::Time frameDeltaTime;

private:
    bool running{ true };
    std::unique_ptr<GameState> currentState;
};
